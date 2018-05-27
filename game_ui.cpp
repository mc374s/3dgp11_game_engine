#include "game.h"
#include "sprite_data.h"
#include "obj2d.h"
#include "numbers.h"

#include "game_ui.h"

////////////////////////////////////////////////////////
// クラス: GameUI 関数

GameUI::GameUI()
{
	clear();
}

void GameUI::memberCopy(const GameUI& a_inputObj)
{
	OBJ2D::memberCopy(a_inputObj);
	m_isVisible = a_inputObj.m_isVisible;
	m_isVisibleAlways = a_inputObj.m_isVisibleAlways;

}

GameUI::GameUI(const GameUI& a_inputObj) :OBJ2DEX(a_inputObj)
{
	memberCopy(a_inputObj);
}

GameUI::~GameUI()
{
	clear();
}

const GameUI& GameUI::operator=(const GameUI& a_right)
{
	memberCopy(a_right);
	return *this;
}

void GameUI::init()
{
	m_isInit = true;
	m_isVisible = true;
	m_isVisibleAlways = true;
	m_custom.scaleMode = SCALE_MODE::CENTER;
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
	for (auto &pObj : m_ppGameUI)
	{
		if (pObj)
		{
			delete pObj;
			pObj = nullptr;
		}
	}

	for (auto &pObj : m_ppNumbers)
	{
		if (pObj)
		{
			delete pObj;
			pObj = nullptr;
}
	}
}

void GameUIManager::init()
{
	/////////////////////////////////////////////////////////////////////////////////
	// Initialize m_ppGameUI
	for (auto &pObj : m_ppGameUI)
	{
		if (pObj)
		{
			pObj->clear();
			pObj->init();
		}
		if (!pObj)
		{
			pObj = new GameUI();
			pObj->init();
		}
	}
	// UI for Ink Gage
	m_ppGameUI[GAGE_FRAME]->m_pSprData = &e_sprGageDivision;
	m_ppGameUI[GAGE_FRAME]->m_isVisibleAlways = false;
	m_ppGameUI[GAGE_FRAME]->m_isVisible = false;
	m_ppGameUI[GAGE_FRAME]->m_pos = { SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2,0 };
	m_ppGameUI[GAGE_FRAME]->m_size = { e_sprGageDivision.width,e_sprGageDivision.height,0 };
	//m_ppGameUI[GAGE_FRAME]->m_custom.scaleX = m_ppGameUI[GAGE_FRAME]->m_size.x / m_ppGameUI[GAGE_FRAME]->m_pSprData->width;
	//m_ppGameUI[GAGE_FRAME]->m_custom.scaleY = m_ppGameUI[GAGE_FRAME]->m_size.y / m_ppGameUI[GAGE_FRAME]->m_pSprData->height;

	m_ppGameUI[GAGE_LEFT]->m_pSprData = &e_sprGage;
	m_ppGameUI[GAGE_LEFT]->m_isVisibleAlways = false;
	m_ppGameUI[GAGE_LEFT]->m_isVisible = false;
	m_ppGameUI[GAGE_LEFT]->m_custom.rgba = 0x0000FFFF;
	m_ppGameUI[GAGE_LEFT]->m_alpha = 180;
	m_ppGameUI[GAGE_LEFT]->m_pos = { (SCREEN_WIDTH - m_ppGameUI[GAGE_LEFT]->m_pSprData->width) / 2,SCREEN_HEIGHT / 2,1 };
	m_ppGameUI[GAGE_LEFT]->m_size = { e_sprGageDivision.width,e_sprGageDivision.height,0 };
	m_ppGameUI[GAGE_LEFT]->m_custom.scaleMode = SCALE_MODE::RIGHTCENTER;

	*m_ppGameUI[GAGE_RIGHT] = *m_ppGameUI[GAGE_LEFT];

	m_ppGameUI[GAGE_RIGHT]->m_custom.rgba = 0xDD0000FF;
	m_ppGameUI[GAGE_RIGHT]->m_pos = { (SCREEN_WIDTH + m_ppGameUI[GAGE_LEFT]->m_pSprData->width) / 2,SCREEN_HEIGHT / 2,1 };
	m_ppGameUI[GAGE_RIGHT]->m_custom.scaleMode = SCALE_MODE::LEFTCENTER;

	// UI for transcription work
	m_ppGameUI[PLAYER_LEFT]->m_pSprData = &e_sprLargePlayer;
	m_ppGameUI[PLAYER_LEFT]->m_isVisibleAlways = false;
	m_ppGameUI[PLAYER_LEFT]->m_isVisible = false;
	m_ppGameUI[PLAYER_LEFT]->m_pos = { SCREEN_WIDTH / 2 - 300,SCREEN_HEIGHT / 2,1 };
	m_ppGameUI[PLAYER_LEFT]->m_size = { m_ppGameUI[PLAYER_LEFT]->m_pSprData->width,m_ppGameUI[PLAYER_LEFT]->m_pSprData->height,0 };
	m_ppGameUI[PLAYER_LEFT]->m_custom.scaleMode = SCALE_MODE::CENTER;
	m_ppGameUI[PLAYER_LEFT]->m_custom.scaleX = m_ppGameUI[PLAYER_LEFT]->m_custom.scaleY = 2.0f;

	*m_ppGameUI[PLAYER_RIGHT] = *m_ppGameUI[PLAYER_LEFT];
	m_ppGameUI[PLAYER_RIGHT]->m_pos = { SCREEN_WIDTH / 2 + 300,SCREEN_HEIGHT / 2,1 };
	m_ppGameUI[PLAYER_RIGHT]->m_size= { m_ppGameUI[PLAYER_RIGHT]->m_pSprData->width,m_ppGameUI[PLAYER_RIGHT]->m_pSprData->height,0 };
	m_ppGameUI[PLAYER_LEFT]->m_custom.reflectX = true;

	m_ppGameUI[PLAYER_CONCENTRATION]->m_pSprData = &e_sprLargePlayer;
	m_ppGameUI[PLAYER_CONCENTRATION]->m_pos = { SCREEN_WIDTH - 100,40,0 };
	m_ppGameUI[PLAYER_CONCENTRATION]->m_custom.scaleMode = SCALE_MODE::CENTER;
	m_ppGameUI[PLAYER_CONCENTRATION]->m_custom.scaleX = m_ppGameUI[PLAYER_CONCENTRATION]->m_custom.scaleY = 0.2;

	// UI for life
	for (int i = STAMP; i < STAMP_MAX; i++) {
		m_ppGameUI[i]->m_pSprData = &e_sprLifeStamp;
		m_ppGameUI[i]->m_pos.x = 45 * (i - STAMP) + 30;
		m_ppGameUI[i]->m_pos.y = 30;
	}

	// UI for Pause
	m_ppGameUI[PAUSE_PANEL]->m_pSprData = &e_sprPausePanel;
	m_ppGameUI[PAUSE_PANEL]->m_pos = { SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 };
	m_ppGameUI[PAUSE_PANEL]->m_isVisibleAlways = false;
	m_ppGameUI[PAUSE_PANEL]->m_isVisible = false;

	*m_ppGameUI[PAUSE_SELECTED] = *m_ppGameUI[PAUSE_PANEL];
	m_ppGameUI[PAUSE_SELECTED]->m_pSprData = &e_sprPauseSelected;
	m_ppGameUI[PAUSE_SELECTED]->m_initPos.y = m_ppGameUI[PAUSE_SELECTED]->m_pos.y += 30;
	


	////////////////////////////////////////////////////////////////////////////////
	// Initialize m_ppNumbers
	for (auto &pObj : m_ppNumbers)
	{
		if (pObj)
		{
			pObj->clear();
}
		if (!pObj)
		{
			pObj = new Numbers();
		}
	}
	m_ppNumbers[CURRENT_CONCENTRATION]->m_pos = { SCREEN_WIDTH - 30,80,0 };

	m_ppNumbers[LEFT_CONCENTRATION]->m_isVisibleAlways = false;
	m_ppNumbers[LEFT_CONCENTRATION]->m_pos = { SCREEN_WIDTH / 2 - 300,360,0 };
	m_ppNumbers[RIGHT_CONCENTRATION]->m_isVisibleAlways = false;
	m_ppNumbers[RIGHT_CONCENTRATION]->m_pos = { SCREEN_WIDTH / 2 + 300,360,0 };



}

void GameUIManager::update()
{

}

void GameUIManager::draw()
{
	for (auto &pObj : m_ppGameUI)
	{
		if (pObj && pObj->m_pSprData && pObj->m_isVisible)
		{
			pObj->draw();
			if (!pObj->m_isVisibleAlways)
			{
				pObj->m_isVisible = false;
			}
		}
	}

	for (auto &pObj : m_ppNumbers)
	{
		if (pObj && pObj->m_isVisible)
		{
			pObj->draw();
			if (!pObj->m_isVisibleAlways)
			{
				pObj->m_isVisible = false;
			}
		}
	}


}

void GameUIManager::showInkTransferGage(int a_playerConcentration, int a_transferConcentration, bool a_isOnLeftPage, bool a_isTranscriptAble)
{
	if (m_ppGameUI[GAGE_FRAME])
	{

		m_ppGameUI[GAGE_FRAME]->m_isVisible = false;
		m_ppGameUI[GAGE_LEFT]->m_isVisible = true;
		m_ppGameUI[GAGE_RIGHT]->m_isVisible = true;
		m_ppGameUI[PLAYER_LEFT]->m_isVisible = true;
		m_ppGameUI[PLAYER_RIGHT]->m_isVisible = true;

		m_ppNumbers[LEFT_CONCENTRATION]->m_isVisible = true;
		m_ppNumbers[RIGHT_CONCENTRATION]->m_isVisible = true;

		m_ppGameUI[PLAYER_CONCENTRATION]->m_isVisible = false;
		m_ppNumbers[CURRENT_CONCENTRATION]->m_isVisible = false;

		m_ppGameUI[GAGE_LEFT]->m_custom.rgba = m_ppGameUI[GAGE_RIGHT]->m_custom.rgba = 0x6F6060FF;
		m_ppGameUI[PLAYER_LEFT]->m_custom.rgba = 0xFFFFFFFF;
		m_ppGameUI[PLAYER_RIGHT]->m_custom.rgba = 0xFFFFFFFF;
		m_ppNumbers[LEFT_CONCENTRATION]->m_custom.rgba = 0xFFFFFFFF;
		m_ppNumbers[RIGHT_CONCENTRATION]->m_custom.rgba = 0xFFFFFFFF;

		if (!a_isOnLeftPage)
		{
			m_ppGameUI[GAGE_LEFT]->m_custom.scaleX = a_playerConcentration / (float)P_CONCENTRATION_MAX_NUM;
			//m_ppGameUI[GAGE_LEFT]->m_custom.rgba = 0x0404B4FF;
			m_ppGameUI[GAGE_LEFT]->m_alpha = 255 * a_playerConcentration / (float)P_CONCENTRATION_MAX_NUM+40;
			m_ppGameUI[GAGE_RIGHT]->m_custom.scaleX = a_transferConcentration / (float)P_CONCENTRATION_MAX_NUM;
			//m_ppGameUI[GAGE_RIGHT]->m_custom.rgba = 0xB18904FF;
			m_ppGameUI[GAGE_RIGHT]->m_alpha = 255 * a_transferConcentration / (float)P_CONCENTRATION_MAX_NUM+40;

			//m_ppGameUI[PLAYER_LEFT]->m_custom.rgba = 0x0404B4FF;
			m_ppGameUI[PLAYER_LEFT]->m_alpha = 255 * a_playerConcentration / (float)P_CONCENTRATION_MAX_NUM + 40;
			//m_ppGameUI[PLAYER_RIGHT]->m_custom.rgba = 0xB18904FF;
			m_ppGameUI[PLAYER_RIGHT]->m_alpha = 255 * a_transferConcentration / (float)P_CONCENTRATION_MAX_NUM + 40;

			m_ppNumbers[LEFT_CONCENTRATION]->setValue(a_playerConcentration);
			m_ppNumbers[RIGHT_CONCENTRATION]->setValue(a_transferConcentration); 
			m_ppNumbers[LEFT_CONCENTRATION]->m_custom.rgba = 0x00FFFFF;

		} else
		{
			m_ppGameUI[GAGE_RIGHT]->m_custom.scaleX = a_playerConcentration / (float)P_CONCENTRATION_MAX_NUM;
			//m_ppGameUI[GAGE_RIGHT]->m_custom.rgba = 0x0404B4FF;
			m_ppGameUI[GAGE_RIGHT]->m_alpha = 255 * a_playerConcentration / (float)P_CONCENTRATION_MAX_NUM+40;
			m_ppGameUI[GAGE_LEFT]->m_custom.scaleX = a_transferConcentration / (float)P_CONCENTRATION_MAX_NUM;
			//m_ppGameUI[GAGE_LEFT]->m_custom.rgba = 0xB18904FF;
			m_ppGameUI[GAGE_LEFT]->m_alpha = 255 * a_transferConcentration / (float)P_CONCENTRATION_MAX_NUM+40;

			//m_ppGameUI[PLAYER_RIGHT]->m_custom.rgba = 0x0404B4FF;
			m_ppGameUI[PLAYER_RIGHT]->m_alpha = 255 * a_playerConcentration / (float)P_CONCENTRATION_MAX_NUM + 40;
			//m_ppGameUI[PLAYER_LEFT]->m_custom.rgba = 0xB18904FF;
			m_ppGameUI[PLAYER_LEFT]->m_alpha = 255 * a_transferConcentration / (float)P_CONCENTRATION_MAX_NUM + 40;

			m_ppNumbers[RIGHT_CONCENTRATION]->setValue(a_playerConcentration);
			m_ppNumbers[LEFT_CONCENTRATION]->setValue(a_transferConcentration);
			m_ppNumbers[RIGHT_CONCENTRATION]->m_custom.rgba = 0x00FFFFFF;
		}
		if (!a_isTranscriptAble)
		{
			m_ppGameUI[GAGE_LEFT]->m_custom.rgba = 0xFF0000FF;
			m_ppGameUI[GAGE_RIGHT]->m_custom.rgba = 0xFF0000FF;


			m_ppGameUI[PLAYER_LEFT]->m_custom.rgba = 0xFF0000FF;
			m_ppGameUI[PLAYER_RIGHT]->m_custom.rgba = 0xFF0000FF;
		}

	}
}

void GameUIManager::showPlayerConcentration(int a_playerConcentration, Vector3 a_pos)
{
	m_ppGameUI[PLAYER_CONCENTRATION]->m_isVisible = true;
	m_ppGameUI[PLAYER_CONCENTRATION]->m_alpha = 255 * a_playerConcentration / (float)P_CONCENTRATION_MAX_NUM + 40;
	m_ppNumbers[CURRENT_CONCENTRATION]->m_isVisible = true;
	m_ppNumbers[CURRENT_CONCENTRATION]->setValue(a_playerConcentration, Vector3(0.35, 0.35, 0));
}

void GameUIManager::showPlayerLife(int a_playerLife)
{
	--a_playerLife;
	for (int i = STAMP; i < STAMP_MAX; i++) {
		if (i - STAMP < a_playerLife)
		{
			m_ppGameUI[i]->m_isVisible = true;
		}
		else
		{
			m_ppGameUI[i]->m_isVisible = false;
		}
	}
}

void GameUIManager::showPausePanel(int a_slelectedNO)
{
	if (m_ppGameUI[PAUSE_PANEL])
	{
		m_ppGameUI[PAUSE_PANEL]->m_isVisible = true;
		m_ppGameUI[PAUSE_SELECTED]->m_isVisible = true;

		m_ppGameUI[PAUSE_SELECTED]->m_pos.y = m_ppGameUI[PAUSE_SELECTED]->m_initPos.y + a_slelectedNO * 86;
	}
}
