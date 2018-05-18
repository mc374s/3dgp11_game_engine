#include "game.h"
#include "sprite_data.h"
#include "obj2d.h"

#include "game_ui.h"


////////////////////////////////////////////////////////
// クラス: GameUI 関数
GameUI::GameUI()
{
	m_isVisible = true;
}

void GameUI::init()
{

}

GameUI::~GameUI()
{
	OBJ2DEX::clear();
	//m_pfMove = nullptr;
}

void GameUI::update()
{

}

void GameUI::draw()
{
	OBJ2DEX::draw();
}

////////////////////////////////////////////////////////


////////////////////////////////////////////////////////
// クラス: GameUIManager 関数
GameUIManager::GameUIManager()
{

}

GameUIManager::~GameUIManager()
{
	for (int i = 0; i < UI_OBJ_MAX_NUM; i++)
	{
		if (m_ppGameUI[i])
		{
			delete m_ppGameUI[i];
			m_ppGameUI[i] = nullptr;
		}
	}
}

void GameUIManager::init()
{
	for (int i = 0; i < UI_OBJ_MAX_NUM; i++)
	{
		if(m_ppGameUI[i])
		{
			delete m_ppGameUI[i];
			m_ppGameUI[i] = nullptr;
		}
		if (!m_ppGameUI[i])
		{
			m_ppGameUI[i] = new GameUI();
		}

		m_ppGameUI[i]->m_custom.scaleMode = SCALE_MODE::CENTER;
	}
	m_ppGameUI[GAGE_FRAME]->m_pSprData = &e_sprGageDivision; 
	m_ppGameUI[GAGE_FRAME]->m_isVisible = false;
	m_ppGameUI[GAGE_FRAME]->m_pos = { SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2,0 };
	m_ppGameUI[GAGE_FRAME]->m_size = { e_sprGageDivision.width,e_sprGageDivision.height,0 };
	//m_ppGameUI[GAGE_FRAME]->m_custom.scaleX = m_ppGameUI[GAGE_FRAME]->m_size.x / m_ppGameUI[GAGE_FRAME]->m_pSprData->width;
	//m_ppGameUI[GAGE_FRAME]->m_custom.scaleY = m_ppGameUI[GAGE_FRAME]->m_size.y / m_ppGameUI[GAGE_FRAME]->m_pSprData->height;

	m_ppGameUI[GAGE_LEFT]->m_pSprData = &e_sprGage;
	m_ppGameUI[GAGE_LEFT]->m_isVisible = false;
	m_ppGameUI[GAGE_LEFT]->m_custom.rgba = 0x0000FFFF;
	m_ppGameUI[GAGE_LEFT]->m_alpha = 180;
	m_ppGameUI[GAGE_LEFT]->m_pos = { (SCREEN_WIDTH - e_sprGage.width) / 2,SCREEN_HEIGHT / 2,1 };
	m_ppGameUI[GAGE_LEFT]->m_size = { e_sprGageDivision.width,e_sprGageDivision.height,0 };
	m_ppGameUI[GAGE_LEFT]->m_custom.scaleMode = SCALE_MODE::RIGHTCENTER;

	m_ppGameUI[GAGE_RIGHT]->m_pSprData = &e_sprGage;
	m_ppGameUI[GAGE_RIGHT]->m_isVisible = false;
	m_ppGameUI[GAGE_RIGHT]->m_custom.rgba = 0xDD0000FF;
	m_ppGameUI[GAGE_RIGHT]->m_alpha = 180;
	m_ppGameUI[GAGE_RIGHT]->m_pos = { (SCREEN_WIDTH + e_sprGage.width) / 2,SCREEN_HEIGHT / 2,1 };
	m_ppGameUI[GAGE_RIGHT]->m_size = { e_sprGageDivision.width,e_sprGageDivision.height,0 };
	m_ppGameUI[GAGE_RIGHT]->m_custom.scaleMode = SCALE_MODE::LEFTCENTER;
	//m_ppGameUI[GAGE]->m_custom.scaleX = m_ppGameUI[GAGE]->m_size.x / m_ppGameUI[GAGE]->m_pSprData->width;
	//m_ppGameUI[GAGE]->m_custom.scaleY = m_ppGameUI[GAGE]->m_size.y / m_ppGameUI[GAGE]->m_pSprData->height;
	

}

void GameUIManager::update()
{
}

void GameUIManager::draw()
{
	for (int i = 0; i < UI_OBJ_MAX_NUM; i++)
	{
		if (m_ppGameUI[i] && m_ppGameUI[i]->m_pSprData && m_ppGameUI[i]->m_isVisible)
		{
			m_ppGameUI[i]->draw();
			if (i == GAGE_FRAME || i == GAGE_LEFT || i == GAGE_RIGHT)
			{
				m_ppGameUI[i]->m_isVisible = false;
			}

		}
	}
}

void GameUIManager::setInkGage(int a_playerConcentration, int a_transferConcentration, bool a_isOnLeftPage, bool a_isTranscriptAble)
{
	if (m_ppGameUI[GAGE_FRAME])
	{

		m_ppGameUI[GAGE_FRAME]->m_isVisible = true;
		m_ppGameUI[GAGE_LEFT]->m_isVisible = true;
		m_ppGameUI[GAGE_RIGHT]->m_isVisible = true;
		if (!a_isOnLeftPage)
		{
			m_ppGameUI[GAGE_LEFT]->m_custom.scaleX = a_playerConcentration / (float)P_CONCENTRATION_MAX_NUM;
			m_ppGameUI[GAGE_LEFT]->m_custom.rgba = 0x0404B4FF;
			m_ppGameUI[GAGE_LEFT]->m_alpha = 255 * a_playerConcentration / (float)P_CONCENTRATION_MAX_NUM+40;
			m_ppGameUI[GAGE_RIGHT]->m_custom.scaleX = a_transferConcentration / (float)P_CONCENTRATION_MAX_NUM;
			m_ppGameUI[GAGE_RIGHT]->m_custom.rgba = 0xB18904FF;
			m_ppGameUI[GAGE_RIGHT]->m_alpha = 255 * a_transferConcentration / (float)P_CONCENTRATION_MAX_NUM+40;
		} else
		{
			m_ppGameUI[GAGE_RIGHT]->m_custom.scaleX = a_playerConcentration / (float)P_CONCENTRATION_MAX_NUM;
			m_ppGameUI[GAGE_RIGHT]->m_custom.rgba = 0x0404B4FF;
			m_ppGameUI[GAGE_RIGHT]->m_alpha = 255 * a_playerConcentration / (float)P_CONCENTRATION_MAX_NUM+40;
			m_ppGameUI[GAGE_LEFT]->m_custom.scaleX = a_transferConcentration / (float)P_CONCENTRATION_MAX_NUM;
			m_ppGameUI[GAGE_LEFT]->m_custom.rgba = 0xB18904FF;
			m_ppGameUI[GAGE_LEFT]->m_alpha = 255 * a_transferConcentration / (float)P_CONCENTRATION_MAX_NUM+40;
		}
		if (!a_isTranscriptAble)
		{
			m_ppGameUI[GAGE_LEFT]->m_custom.rgba = 0xFF0000FF;
			m_ppGameUI[GAGE_RIGHT]->m_custom.rgba = 0xFF0000FF;
		}

	}
}