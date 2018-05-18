#include "game.h"
#include "obj2d.h"

#include "sprite_data.h"

/////////////////////////////////////////////////////////////////
// Class OBJ2D Function
void OBJ2D::clear() 
{
	m_pSprData = nullptr;
	m_pos = Vector3(0, 0, 0);
	m_speed = m_speedAcc = m_speedMax = m_size = Vector3(0, 0, 0);
	m_timer = 0;
	m_state = 0;
	m_alpha = 255;
	m_concentration = 0;
	m_isInit = false;

	m_isOnLeftPage = true;

	m_type = 0;
}

void OBJ2D::draw() 
{
	if (m_pSprData)
	{
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
		/*if (a_ppBegin[i])
		{
			delete a_ppBegin[i];
			a_ppBegin[i] = new OBJ2D;
		}*/
		return i;
	}
	return -1;
}

///////////////////////////////////////////////////////////////
// Class OBJ2DEX Function
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
	if (m_pSprData)
	{
		m_custom.rgba = m_custom.rgba >> 8 << 8 | m_alpha;
		m_pSprData->draw(m_pos, &m_custom);
	}
}
/////////////////////////////////////////////////////////////////
// Class ObjManager Function
ObjManager::~ObjManager() 
{
	for (int i = 0; i < OBJ_MAX_NUM; i++)
	{
		if (m_ppObj[i] && m_ppObj[i]->m_pSprData && m_ppObj[i]->m_isInit)
		{
			delete m_ppObj[i];
		}
	}
	ZeroMemory(m_ppObj, sizeof(m_ppObj));
	//delete[] m_pObj;

	m_blurAreaList.clear();
	m_newblurAreaList.clear();
	m_transcriptionList.clear();
};

void ObjManager::init() {
	for (int i = 0; i < OBJ_MAX_NUM; i++)
	{
		if (!m_ppObj[i])
		{
			//m_ppObj[i] = new OBJ2D;
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

void ObjManager::updata(bool a_isLeftPage) {


	for (int i = 0; i < OBJ_MAX_NUM; i++)
	{
		if (m_ppObj[i] && m_ppObj[i]->m_isOnLeftPage == a_isLeftPage)
		{
			m_ppObj[i]->update();
		}
	}

	// 描画順番を並び替え　pos.z : 小さい順から描画していく 
	OBJ2D* temp = nullptr;
	for (int i = 1; i < OBJ_MAX_NUM; i++)
	{
		if (m_ppObj[i - 1] && m_ppObj[i] && m_ppObj[i - 1]->m_pos.z > m_ppObj[i]->m_pos.z)
		{
			int j = i;
			do
			{
				temp = m_ppObj[j - 1];
				m_ppObj[j - 1] = m_ppObj[j];
				m_ppObj[j] = temp;
				j--;
			} while (j > 0 && m_ppObj[j - 1]->m_pos.z < m_ppObj[j]->m_pos.z);
		}
	}
}

void ObjManager::draw(bool a_isLeftPage)
{

	char buf[256];
	for (auto it : m_transcriptionList) {
		if (it.m_isOnLeftPage == a_isLeftPage)
		{
			it.draw();
			sprintf_s(buf, "%d", it.m_concentration);
			drawString(it.m_pos.x, it.m_pos.y - it.m_size.y - 40, buf, 0x00000060, STR_CENTER, 32, 20, -20);
		}
	}
	for (auto it : m_blurAreaList) {
		if (it.m_isOnLeftPage == a_isLeftPage)
		{
			it.draw();
		}
	}
	int num = 0;
	for (int i = 0; i < OBJ_MAX_NUM; i++)
	{
		if (m_ppObj[i] && m_ppObj[i]->m_isInit && m_ppObj[i]->m_isOnLeftPage == a_isLeftPage)
		{
			m_ppObj[i]->draw();
			num++;
		}
	}

#ifdef DEBUG

	sprintf_s(buf, "Obj Num: %d\nBlurObjNum: %d", num, m_blurAreaList.size());
	drawString(0, PAGE_HEIGHT - 60, buf, 0x000000FF, STR_LEFT);

#endif // DEBUG

}
//////////////////////////////////////////////////////////////////