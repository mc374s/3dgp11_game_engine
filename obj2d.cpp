#include "Game.h"

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
	if (m_pAnimeData &&( m_pAnimeData!=e_pAnimePlayerJump && m_pAnimeData != e_pAnimePlayerStandby && m_pAnimeData != e_pAnimePlayerRun))
	{
		MessageBox(0, L"Alert", 0, MB_OK);
	}
}

void OBJ2DEX::draw() 
{
	if (m_pSprData)
	{
		m_custom.rgba = m_custom.rgba << 8 >> 8 | m_alpha << 24;
		m_pSprData->draw(m_pos, &m_custom);
	}
}

void ObjManager::init() {
	for (int i = 0; i < OBJ_MAX_NUM; i++)
	{
		if (!m_pObj[i])
		{
			m_pObj[i] = new OBJ2D;
		}
	}
	//ZeroMemory(pObj, sizeof(pObj));
}

void ObjManager::updata(bool a_isLeftPage) {


	for (int i = 0; i < OBJ_MAX_NUM; i++)
	{
		if (m_pObj[i] && m_pObj[i]->m_isOnLeftPage == a_isLeftPage)
		{
			m_pObj[i]->update();
		}
	}

	// •`‰æ‡”Ô‚ğ•À‚Ñ‘Ö‚¦@pos.z : ¬‚³‚¢‡‚©‚ç•`‰æ‚µ‚Ä‚¢‚­ 
	OBJ2D* temp = nullptr;
	for (int i = 1; i < OBJ_MAX_NUM; i++)
	{
		if (m_pObj[i - 1]->m_pos.z > m_pObj[i]->m_pos.z)
		{
			int j = i;
			do
			{
				temp = m_pObj[j - 1];
				m_pObj[j - 1] = m_pObj[j];
				m_pObj[j] = temp;
				j--;
			} while (j > 0 && m_pObj[j - 1]->m_pos.z < m_pObj[j]->m_pos.z);
		}
	}
}

void ObjManager::draw(bool a_isLeftPage)
{
	int num = 0;
	for (int i = 0; i < OBJ_MAX_NUM; i++)
	{
		if (m_pObj[i] && m_pObj[i]->m_isInit && m_pObj[i]->m_isOnLeftPage == a_isLeftPage)
		{
			m_pObj[i]->draw();
			num++;
		}
	}
#ifdef DEBUG

	char buf[256];
	sprintf_s(buf, "Obj Num: %d\n", num);
	drawString(0, PAGE_HEIGHT - 60, buf, 0x000000FF, STR_LEFT);

#endif // DEBUG


}