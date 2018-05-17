#include "game.h"
#include "obj2d.h"

/////////////////////////////////////////////////////////////////
// Class OBJ2D Function
void OBJ2D::clear() 
{
	m_pSprData = nullptr;
	m_pos = Vector3(0, 0, 0);
	m_speed = m_size = Vector3(0, 0, 0);
	m_timer = 0;
	m_state = 0;
	m_alpha = 255;
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
		if (a_ppBegin[i])
		{
			delete a_ppBegin[i];
			a_ppBegin[i] = new OBJ2D;
		}
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
		if (m_ppObj[i])
		{
			delete m_ppObj[i];
		}
	}
	ZeroMemory(m_ppObj, sizeof(m_ppObj));
	//delete[] m_pObj;
};

void ObjManager::init() {
	for (int i = 0; i < OBJ_MAX_NUM; i++)
	{
		if (!m_ppObj[i])
		{
			m_ppObj[i] = new OBJ2D;
		}
	}
	//ZeroMemory(pObj, sizeof(pObj));
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
		if (m_ppObj[i - 1]->m_pos.z > m_ppObj[i]->m_pos.z)
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

	char buf[256];
	sprintf_s(buf, "Obj Num: %d\n", num);
	drawString(0, PAGE_HEIGHT - 60, buf, 0x000000FF, STR_LEFT);

#endif // DEBUG

}
//////////////////////////////////////////////////////////////////