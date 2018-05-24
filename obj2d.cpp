#include "game.h"
#include "obj2d.h"

#include "sprite_data.h"

/////////////////////////////////////////////////////////////////
// Class OBJ2D Function
OBJ2D::OBJ2D() 
{
	clear();
}

void OBJ2D::memberCopy(const OBJ2D& a_inputObj)
{
	m_pos = a_inputObj.m_pos;
	m_initPos = a_inputObj.m_initPos;
	m_speed = a_inputObj.m_speed;
	m_speedAcc = a_inputObj.m_speedAcc;
	m_speedMax = a_inputObj.m_speedMax;

	m_size = a_inputObj.m_size;

	m_custom = a_inputObj.m_custom;

	m_timer = a_inputObj.m_timer;
	m_step = a_inputObj.m_step;
	m_alpha = a_inputObj.m_alpha;
	m_type = a_inputObj.m_type;
	m_concentration = a_inputObj.m_concentration;

	m_isInit = a_inputObj.m_isInit;
	m_liveInPagination = a_inputObj.m_liveInPagination;

	m_pSprData = a_inputObj.m_pSprData;
}

OBJ2D::OBJ2D(const OBJ2D& a_inputObj)
{
	memberCopy(a_inputObj);
}

OBJ2D::~OBJ2D() 
{
	clear();
}

const OBJ2D& OBJ2D::operator=(const OBJ2D& a_right)
{
	memberCopy(a_right);
	return *this;
}


void OBJ2D::clear() 
{
	m_pSprData = nullptr;
	m_pos = m_initPos = Vector3(0, 0, 0);
	m_speed = m_speedAcc = m_speedMax = m_size = Vector3(0, 0, 0);
	m_timer = 0;
	m_step = 0;
	m_alpha = 255;
	m_concentration = 0;
	m_isInit = false;

	m_liveInPagination = 1;

	m_type = 0;
}

void OBJ2D::draw() 
{
	if (m_pSprData)
	{
		if (m_alpha > 255) {
			m_alpha = 255;
		}
		if (m_alpha < 0) {
			m_alpha = 0;
		}
		m_custom.rgba = m_custom.rgba >> 8 << 8 | m_alpha;
		m_pSprData->draw(m_pos.x, m_pos.y, &m_custom);
	}
}

int OBJ2D::searchSet(OBJ2D** a_ppBegin, int a_max) 
{
	for (int i = 0; i < a_max; i++)
	{
		if (a_ppBegin[i] && a_ppBegin[i]->m_isInit) {
			continue;
		}
		return i;
	}
	return -1;
}

///////////////////////////////////////////////////////////////
// Class OBJ2DEX Function

OBJ2DEX::OBJ2DEX()
{
	clear();
}

void OBJ2DEX::memberCopy(const OBJ2DEX& a_inputObj)
{
	OBJ2D::memberCopy(a_inputObj);
	m_aframe = a_inputObj.m_aframe;
	m_animeNO = a_inputObj.m_animeNO;
	m_pAnimeData = a_inputObj.m_pAnimeData;
}

OBJ2DEX::OBJ2DEX(const OBJ2DEX& a_inputObj):OBJ2D(a_inputObj)
{
	memberCopy(a_inputObj);
}

OBJ2DEX::~OBJ2DEX()
{
	clear();
}

const OBJ2DEX& OBJ2DEX::operator=(const OBJ2DEX& a_right)
{
	memberCopy(a_right);
	return *this;
}

void OBJ2DEX::clear() 
{
	OBJ2D::clear();
	m_aframe = 0;
	m_animeNO = 0;
	m_pAnimeData = nullptr;
}

void OBJ2DEX::animation() 
{
	if (m_pAnimeData)
	{
		m_aframe++;
		if (m_aframe > (m_pAnimeData[m_animeNO]).frameNum)
		{
			m_aframe = 0;
			m_animeNO++;
			if ((m_pAnimeData[m_animeNO]).texNum < 0)
			{
				m_animeNO = 0;
			}
		}
		m_pSprData = &(m_pAnimeData[m_animeNO]);
	}
}

void OBJ2DEX::draw() 
{
	OBJ2D::draw();
	/*if (m_pSprData)
	{
		if (m_alpha > 255) {
			m_alpha = 255;
		}
		if (m_alpha < 0) {
			m_alpha = 0;
		}
		m_custom.rgba = m_custom.rgba >> 8 << 8 | m_alpha;
		m_pSprData->draw(m_pos, &m_custom);
	}*/
}

/////////////////////////////////////////////////////////////////
// Class ObjManager Function
ObjManager::~ObjManager() 
{
	ZeroMemory(m_ppObjs, sizeof(m_ppObjs));

	m_blurAreaList.clear();
	m_newblurAreaList.clear();
	m_transcriptionList.clear();

};

void ObjManager::init() {

	for (auto &it:m_ppObjs){
		if (it){
			it->clear();
		}
	}

	//ZeroMemory(pObj, sizeof(pObj));

	m_hitObj.m_pSprData = &e_sprHitObj;
	//m_hitObj.m_size = { m_hitObj.m_pSprData->width,m_hitObj.m_pSprData->height,0 };
	m_hitObj.m_size = { 10,10,0 };
	m_hitObj.m_custom.rgba = 0x000000FF;
	m_hitObj.m_alpha = 10;

	m_blurAreaList.clear();
	m_newblurAreaList.clear();
	m_transcriptionList.clear();

}

void ObjManager::update(int a_liveInPagination) {


	for (auto &it : m_ppObjs)
	{
		if (it && it->m_liveInPagination == a_liveInPagination)
		{
			it->update();
		}
	}

	// 描画順番を並び替え　pos.z : 小さい順から描画していく 
	OBJ2D* temp = nullptr;
	for (int i = 1; i < OBJ_MAX_NUM; i++)
	{
		if (m_ppObjs[i - 1] && m_ppObjs[i] && (m_ppObjs[i - 1]->m_liveInPagination == m_ppObjs[i]->m_liveInPagination))
		{
			if (m_ppObjs[i - 1]->m_pos.z > m_ppObjs[i]->m_pos.z)
			{
				int j = i;
				do
				{
					temp = m_ppObjs[j - 1];
					m_ppObjs[j - 1] = m_ppObjs[j];
					m_ppObjs[j] = temp;
					j--;
				} while (j > 0 && m_ppObjs[j - 1]->m_pos.z < m_ppObjs[j]->m_pos.z);
			}
		}
	}

}

void ObjManager::draw(int a_liveInPagination)
{

	char pConcentration[8];
	for (auto &it : m_transcriptionList) {
		if (it.m_liveInPagination == a_liveInPagination)
		{
			it.draw();
			sprintf_s(pConcentration, "%d", it.m_concentration);
			drawString(it.m_pos.x, it.m_pos.y - it.m_size.y - 40, pConcentration, 0x00000060, STR_CENTER, 32, 20, -20);
		}
	}
	for (auto &it : m_blurAreaList) {
		if (it.m_liveInPagination == a_liveInPagination)
		{
			it.draw();
		}
	}
	int num = 0;
	for (auto &it : m_ppObjs)
	{
		if (it && it->m_isInit && it->m_liveInPagination == a_liveInPagination)
		{
			it->draw();
			num++;
		}
	}

#ifdef DEBUG

	char buf[256];
	sprintf_s(buf, "Obj Num: %d\nBlurObjNum: %d", num, m_blurAreaList.size());
	drawString(0, PAGE_HEIGHT - 60, buf, 0x000000FF, STR_LEFT);

#endif // DEBUG

}
//////////////////////////////////////////////////////////////////