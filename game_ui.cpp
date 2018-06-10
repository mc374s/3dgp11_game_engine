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
	animation();
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
	m_ppGameUI[A_LEFT_DIVISION]->m_pSprData = &e_sprGageDivisionAllocation;
	m_ppGameUI[A_LEFT_DIVISION]->m_isVisibleAlways = false;
	m_ppGameUI[A_LEFT_DIVISION]->m_isVisible = false;
	m_ppGameUI[A_LEFT_DIVISION]->m_pos = { SCREEN_WIDTH / 2 - m_ppGameUI[A_LEFT_DIVISION]->m_pSprData->width / 2 - 100,SCREEN_HEIGHT / 2 - 220,0 };
	m_ppGameUI[A_LEFT_DIVISION]->m_size = { e_sprGageDivisionAllocation.width,e_sprGageDivisionAllocation.height,0 };

	*m_ppGameUI[A_RIGHT_DIVISION] = *m_ppGameUI[A_LEFT_DIVISION];
	m_ppGameUI[A_RIGHT_DIVISION]->m_pos.x = SCREEN_WIDTH / 2 + m_ppGameUI[A_RIGHT_DIVISION]->m_pSprData->width / 2 + 100;

	m_ppGameUI[A_LEFT_GAGE]->m_pSprData = &e_sprGageAllocation;
	m_ppGameUI[A_LEFT_GAGE]->m_isVisibleAlways = false;
	m_ppGameUI[A_LEFT_GAGE]->m_isVisible = false;
	m_ppGameUI[A_LEFT_GAGE]->m_custom.rgba = 0x735E60FF;
	//m_ppGameUI[A_LEFT_GAGE]->m_alpha = 200;
	m_ppGameUI[A_LEFT_GAGE]->m_pos.x = m_ppGameUI[A_LEFT_DIVISION]->m_pos.x;
	m_ppGameUI[A_LEFT_GAGE]->m_pos.y = m_ppGameUI[A_LEFT_DIVISION]->m_pos.y;
	m_ppGameUI[A_LEFT_GAGE]->m_size = { e_sprGageDivisionAllocation.width,e_sprGageDivisionAllocation.height,0 };
	m_ppGameUI[A_LEFT_GAGE]->m_custom.scaleMode = SCALE_MODE::RIGHTCENTER;

	*m_ppGameUI[A_RIGHT_GAGE] = *m_ppGameUI[A_LEFT_GAGE];

	//m_ppGameUI[A_RIGHT_GAGE]->m_custom.rgba = 0xDD0000FF;
	m_ppGameUI[A_RIGHT_GAGE]->m_pos.x = m_ppGameUI[A_RIGHT_DIVISION]->m_pos.x;
	m_ppGameUI[A_RIGHT_GAGE]->m_pos.y = m_ppGameUI[A_RIGHT_DIVISION]->m_pos.y;
	m_ppGameUI[A_RIGHT_GAGE]->m_custom.scaleMode = SCALE_MODE::LEFTCENTER;

	*m_ppGameUI[A_LEFT_GAGE_UNDER] = *m_ppGameUI[A_LEFT_GAGE];
	*m_ppGameUI[A_RIGHT_GAGE_UNDER] = *m_ppGameUI[A_RIGHT_GAGE];
	m_ppGameUI[A_LEFT_GAGE_UNDER]->m_pSprData = &sprGageAllocationUnder;
	m_ppGameUI[A_LEFT_GAGE_UNDER]->m_custom.rgba = 0xFFFFFFFF;
	m_ppGameUI[A_LEFT_GAGE_UNDER]->m_alpha = 160;
	m_ppGameUI[A_RIGHT_GAGE_UNDER]->m_pSprData = &sprGageAllocationUnder;
	m_ppGameUI[A_RIGHT_GAGE_UNDER]->m_custom.rgba = 0xFFFFFFFF;
	m_ppGameUI[A_RIGHT_GAGE_UNDER]->m_alpha = 160;

	// UI for transcription work
	m_ppGameUI[A_LEFT_PLAYER]->m_pSprData = &e_sprLargePlayer;
	m_ppGameUI[A_LEFT_PLAYER]->m_isVisibleAlways = false;
	m_ppGameUI[A_LEFT_PLAYER]->m_isVisible = false;
	m_ppGameUI[A_LEFT_PLAYER]->m_pos = { SCREEN_WIDTH / 2 - 300,SCREEN_HEIGHT / 2,1 };
	m_ppGameUI[A_LEFT_PLAYER]->m_size = { m_ppGameUI[A_LEFT_PLAYER]->m_pSprData->width,m_ppGameUI[A_LEFT_PLAYER]->m_pSprData->height,0 };
	m_ppGameUI[A_LEFT_PLAYER]->m_custom.scaleMode = SCALE_MODE::CENTER;
	m_ppGameUI[A_LEFT_PLAYER]->m_custom.scaleX = m_ppGameUI[A_LEFT_PLAYER]->m_custom.scaleY = 2.0f;

	*m_ppGameUI[A_RIGHT_PLAYER] = *m_ppGameUI[A_LEFT_PLAYER];
	m_ppGameUI[A_RIGHT_PLAYER]->m_pos = { SCREEN_WIDTH / 2 + 300,SCREEN_HEIGHT / 2,1 };
	m_ppGameUI[A_RIGHT_PLAYER]->m_size= { m_ppGameUI[A_RIGHT_PLAYER]->m_pSprData->width,m_ppGameUI[A_RIGHT_PLAYER]->m_pSprData->height,0 };
	m_ppGameUI[A_LEFT_PLAYER]->m_custom.reflectX = true;

	// UI for Player Concentration Gage
	m_ppGameUI[C_GAGE_ANIME]->m_isVisibleAlways = false;
	m_ppGameUI[C_GAGE_ANIME]->m_isVisible = false;
	m_ppGameUI[C_GAGE_ANIME]->m_custom.scaleMode = SCALE_MODE::CENTER;
	*m_ppGameUI[C_GAGE] = *m_ppGameUI[C_PLAYER_FACE] = *m_ppGameUI[C_DIVISION] = *m_ppGameUI[C_GAGE_ANIME];

	m_ppGameUI[C_DIVISION]->m_pSprData = &e_sprGageDivision;
	m_ppGameUI[C_DIVISION]->m_pos = m_ppGameUI[C_DIVISION]->m_initPos = { 0,0,0 };
	
	m_ppGameUI[C_GAGE]->m_pSprData = &e_sprGage;
	m_ppGameUI[C_GAGE]->m_custom.scaleMode = SCALE_MODE::LEFTCENTER;
	m_ppGameUI[C_GAGE]->m_custom.rgba = 0x000000FF;
	//m_ppGameUI[C_GAGE]->m_alpha = 200;
	m_ppGameUI[C_GAGE]->m_pos.x = m_ppGameUI[C_DIVISION]->m_pos.x + 93;
	m_ppGameUI[C_GAGE]->m_pos.y = m_ppGameUI[C_DIVISION]->m_pos.y + 35;
	m_ppGameUI[C_GAGE]->m_initPos = m_ppGameUI[C_GAGE]->m_pos;

	*m_ppGameUI[C_GAGE_UNDER] = *m_ppGameUI[C_GAGE];
	m_ppGameUI[C_GAGE_UNDER]->m_pSprData = &e_sprGageUnder;
	m_ppGameUI[C_GAGE_UNDER]->m_custom.rgba = 0xF2CE6CFF;
	m_ppGameUI[C_GAGE_UNDER]->m_alpha = 200;

	m_ppGameUI[C_GAGE_ANIME]->m_pAnimeData = e_pAnimeGage;
	m_ppGameUI[C_GAGE_ANIME]->m_custom.rgba = m_ppGameUI[C_GAGE]->m_custom.rgba;
	m_ppGameUI[C_GAGE_ANIME]->m_alpha = m_ppGameUI[C_GAGE]->m_alpha;
	m_ppGameUI[C_GAGE_ANIME]->m_pos.x = m_ppGameUI[C_GAGE]->m_pos.x + m_ppGameUI[C_GAGE]->m_custom.scaleX*m_ppGameUI[C_GAGE]->m_pSprData->width;
	m_ppGameUI[C_GAGE_ANIME]->m_pos.y = m_ppGameUI[C_GAGE]->m_pos.y;
	m_ppGameUI[C_GAGE_ANIME]->m_initPos = m_ppGameUI[C_GAGE_ANIME]->m_pos;

	m_ppGameUI[C_PLAYER_FACE]->m_pSprData = &e_pSprPlayerFace[1];
	m_ppGameUI[C_PLAYER_FACE]->m_pos.x = m_ppGameUI[C_DIVISION]->m_pos.x - 8;
	m_ppGameUI[C_PLAYER_FACE]->m_pos.y = m_ppGameUI[C_DIVISION]->m_pos.y - 4;
	m_ppGameUI[C_PLAYER_FACE]->m_initPos = m_ppGameUI[C_PLAYER_FACE]->m_pos;

	// UI for life
	for (int i = STAMP; i < STAMP_MAX; i++) {
		m_ppGameUI[i]->m_pSprData = &e_sprLifeStamp;
		m_ppGameUI[i]->m_isVisibleAlways = false;
		m_ppGameUI[i]->m_isVisible = false;
		m_ppGameUI[i]->m_pos.x = 45 * (i - STAMP) + m_ppGameUI[C_DIVISION]->m_pos.x + 140;
		m_ppGameUI[i]->m_pos.y = m_ppGameUI[C_DIVISION]->m_pos.y + 80;
	}

	// UI for Pause
	m_ppGameUI[PAUSE_PANEL]->m_pSprData = &e_sprPausePanel;
	m_ppGameUI[PAUSE_PANEL]->m_pos = { SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2 };
	m_ppGameUI[PAUSE_PANEL]->m_isVisibleAlways = false;
	m_ppGameUI[PAUSE_PANEL]->m_isVisible = false;

	*m_ppGameUI[PAUSE_SELECTED] = *m_ppGameUI[PAUSE_PANEL];
	m_ppGameUI[PAUSE_SELECTED]->m_pSprData = &e_sprPauseSelected;
	m_ppGameUI[PAUSE_SELECTED]->m_initPos.y = m_ppGameUI[PAUSE_SELECTED]->m_pos.y += 30;

	// UI for HELP
	m_ppGameUI[HELP]->m_pSprData = &e_sprHelp;
	m_ppGameUI[HELP]->m_isVisibleAlways = false;
	m_ppGameUI[HELP]->m_isVisible = false;
	m_ppGameUI[HELP]->m_pos = { SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2,0.0f };
	m_ppGameUI[HELP_BUTTON]->m_isVisibleAlways = false;
	m_ppGameUI[HELP_BUTTON]->m_isVisible = false;
	m_ppGameUI[HELP_BUTTON]->m_pSprData = &e_sprHelpButton;
	m_ppGameUI[HELP_BUTTON]->m_initPos = m_ppGameUI[HELP_BUTTON]->m_pos = { 10.0f,SCREEN_HEIGHT - m_ppGameUI[HELP_BUTTON]->m_pSprData->height - 5.0f,0.0f };
	//m_ppGameUI[HELP_BUTTON]->m_alpha = 200;

	// UI X button
	m_ppGameUI[X_BUTTON]->m_isVisibleAlways = false;
	m_ppGameUI[X_BUTTON]->m_isVisible = false;
	m_ppGameUI[X_BUTTON]->m_pSprData = &e_sprXButton;
	m_ppGameUI[X_BUTTON]->m_initPos = m_ppGameUI[X_BUTTON]->m_pos = { SCREEN_WIDTH / 2,SCREEN_HEIGHT - 100,0.0f };
	m_ppGameUI[X_BUTTON]->m_alpha = 255;


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

	m_ppNumbers[LEFT_CONCENTRATION]->m_isVisibleAlways = false;
	m_ppNumbers[LEFT_CONCENTRATION]->m_pos = { SCREEN_WIDTH / 2 - 300,360,0 };
	m_ppNumbers[RIGHT_CONCENTRATION]->m_isVisibleAlways = false;
	m_ppNumbers[RIGHT_CONCENTRATION]->m_pos = { SCREEN_WIDTH / 2 + 300,360,0 };



}

void GameUIManager::update()
{
	/*for (auto &pObj : m_ppGameUI)
	{
		if (pObj)
		{
			pObj->update();
		}
	}*/
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

void GameUIManager::showInkTransferGage(float a_playerConcentration, float a_transferConcentration, bool a_isOnLeftPage, bool a_isTranscriptAble)
{
	if (m_ppGameUI[A_LEFT_DIVISION])
	{

		m_ppGameUI[A_LEFT_DIVISION]->m_isVisible = true;
		m_ppGameUI[A_RIGHT_DIVISION]->m_isVisible = true;
		m_ppGameUI[A_LEFT_GAGE_UNDER]->m_isVisible = true;
		m_ppGameUI[A_RIGHT_GAGE_UNDER]->m_isVisible = true;
		m_ppGameUI[A_LEFT_GAGE]->m_isVisible = true;
		m_ppGameUI[A_RIGHT_GAGE]->m_isVisible = true;
		m_ppGameUI[A_LEFT_PLAYER]->m_isVisible = true;
		m_ppGameUI[A_RIGHT_PLAYER]->m_isVisible = true;

		//m_ppNumbers[LEFT_CONCENTRATION]->m_isVisible = true;
		//m_ppNumbers[RIGHT_CONCENTRATION]->m_isVisible = true;


		m_ppGameUI[A_LEFT_GAGE]->m_custom.rgba = m_ppGameUI[A_RIGHT_GAGE]->m_custom.rgba = 0x6F6060FF;
		m_ppGameUI[A_LEFT_PLAYER]->m_custom.rgba = 0xFFFFFFFF;
		m_ppGameUI[A_RIGHT_PLAYER]->m_custom.rgba = 0xFFFFFFFF;
		m_ppNumbers[LEFT_CONCENTRATION]->m_custom.rgba = 0xFFFFFFFF;
		m_ppNumbers[RIGHT_CONCENTRATION]->m_custom.rgba = 0xFFFFFFFF;

		m_ppGameUI[C_DIVISION]->m_isVisible = m_ppGameUI[C_GAGE]->m_isVisible = m_ppGameUI[C_GAGE_ANIME]->m_isVisible = m_ppGameUI[C_PLAYER_FACE]->m_isVisible= m_ppGameUI[C_GAGE_UNDER]->m_isVisible = false;


		if (fabsf(a_transferConcentration - 0.0f) < FLT_EPSILON)
		{
			a_isOnLeftPage = !a_isOnLeftPage;
		}
		if (!a_isOnLeftPage)
		{
			m_ppGameUI[A_LEFT_GAGE]->m_custom.scaleX = a_playerConcentration / (float)P_CONCENTRATION_MAX;
			//m_ppGameUI[A_LEFT]_GAGE->m_custom.rgba = 0x0404B4FF;
			m_ppGameUI[A_RIGHT_GAGE]->m_custom.scaleX = a_transferConcentration / (float)P_CONCENTRATION_MAX;
			//m_ppGameUI[A_RIGHT_GAGE]->m_custom.rgba = 0xB18904FF;

			m_ppGameUI[A_LEFT_PLAYER]->m_custom.rgba = 0xFFFFFFFF;
			m_ppGameUI[A_LEFT_PLAYER]->m_alpha = 255 * a_playerConcentration / (float)P_CONCENTRATION_MAX;
			m_ppGameUI[A_RIGHT_PLAYER]->m_custom.rgba = 0xFFFFFFFF;
			m_ppGameUI[A_RIGHT_PLAYER]->m_alpha = 255 * a_transferConcentration / (float)P_CONCENTRATION_MAX;

			m_ppNumbers[LEFT_CONCENTRATION]->setValue(a_playerConcentration);
			m_ppNumbers[RIGHT_CONCENTRATION]->setValue(a_transferConcentration); 
			m_ppNumbers[LEFT_CONCENTRATION]->m_custom.rgba = 0x00FFFFF;

		} else
		{
			m_ppGameUI[A_RIGHT_GAGE]->m_custom.scaleX = a_playerConcentration / (float)P_CONCENTRATION_MAX;
			//m_ppGameUI[A_RIGHT_GAGE]->m_custom.rgba = 0x0404B4FF;
			m_ppGameUI[A_LEFT_GAGE]->m_custom.scaleX = a_transferConcentration / (float)P_CONCENTRATION_MAX;
			//m_ppGameUI[A_LEFT_GAGE]->m_custom.rgba = 0xB18904FF;

			m_ppGameUI[A_RIGHT_PLAYER]->m_custom.rgba = 0xFFFFFFFF;
			m_ppGameUI[A_RIGHT_PLAYER]->m_alpha = 255 * a_playerConcentration / (float)P_CONCENTRATION_MAX;
			m_ppGameUI[A_LEFT_PLAYER]->m_custom.rgba = 0xFFFFFFFF;
			m_ppGameUI[A_LEFT_PLAYER]->m_alpha = 255 * a_transferConcentration / (float)P_CONCENTRATION_MAX;

			m_ppNumbers[RIGHT_CONCENTRATION]->setValue(a_playerConcentration);
			m_ppNumbers[LEFT_CONCENTRATION]->setValue(a_transferConcentration);
			m_ppNumbers[RIGHT_CONCENTRATION]->m_custom.rgba = 0x00FFFFFF;
		}
		if (!a_isTranscriptAble)
		{
			m_ppGameUI[A_LEFT_GAGE]->m_custom.rgba = 0xFF0000FF;
			m_ppGameUI[A_RIGHT_GAGE]->m_custom.rgba = 0xFF0000FF;


			m_ppGameUI[A_LEFT_PLAYER]->m_custom.rgba = 0xFF0000FF;
			m_ppGameUI[A_RIGHT_PLAYER]->m_custom.rgba = 0xFF0000FF;

			m_ppNumbers[LEFT_CONCENTRATION]->m_custom.rgba = 0xFF0000FF;
			m_ppNumbers[RIGHT_CONCENTRATION]->m_custom.rgba = 0xFF0000FF;
		}

	}
}

void GameUIManager::showPlayerConcentration(float a_playerConcentration, int a_playerLife, bool a_isDamaged, Vector3 a_pos)
{
	m_ppGameUI[C_DIVISION]->m_isVisible = m_ppGameUI[C_GAGE]->m_isVisible = m_ppGameUI[C_GAGE_ANIME]->m_isVisible = m_ppGameUI[C_PLAYER_FACE]->m_isVisible /*= m_ppGameUI[C_GAGE_UNDER]->m_isVisible*/ = true;

	m_ppGameUI[C_GAGE]->m_custom.scaleX = a_playerConcentration / (float)P_CONCENTRATION_MAX;
	if (a_isDamaged)
	{
		m_ppGameUI[C_GAGE]->m_custom.rgba = 0xFF3F5FFF;
		m_ppGameUI[C_PLAYER_FACE]->m_pSprData = &e_pSprPlayerFace[0];
	}
	else
	{
		m_ppGameUI[C_GAGE]->m_custom.rgba = 0x735E60FF;
		m_ppGameUI[C_PLAYER_FACE]->m_pSprData = &e_pSprPlayerFace[1];
	}

	m_ppGameUI[C_GAGE_ANIME]->m_pos.x = m_ppGameUI[C_GAGE]->m_pos.x + m_ppGameUI[C_GAGE]->m_custom.scaleX*m_ppGameUI[C_GAGE]->m_pSprData->width;
	m_ppGameUI[C_GAGE_ANIME]->m_custom.rgba = m_ppGameUI[C_GAGE]->m_custom.rgba;
	m_ppGameUI[C_GAGE_ANIME]->animation();
	//m_ppGameUI[C_PLAYER_FACE]->m_alpha = 255 * a_playerConcentration / (float)P_CONCENTRATION_MAX;


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

void GameUIManager::showHelpButton()
{
	m_ppGameUI[HELP]->m_isVisible = false;
	m_ppGameUI[HELP_BUTTON]->m_isVisible = true;
	if (KEY_BOARD.Q || GAME_PAD.IsLeftShoulderPressed()) {
		m_ppGameUI[HELP]->m_isVisible = true;
		m_ppGameUI[HELP_BUTTON]->m_isVisible = false;
	}
}

void GameUIManager::showXButton()
{
	static float scaleSpeed = 0.008f;
	m_ppGameUI[X_BUTTON]->m_isVisible = true;
	m_ppGameUI[X_BUTTON]->m_custom.scaleX += scaleSpeed;
	if (m_ppGameUI[X_BUTTON]->m_custom.scaleX > 1.5f) {
		m_ppGameUI[X_BUTTON]->m_custom.scaleX = 1.5f;
		scaleSpeed = -scaleSpeed;
	}
	if (m_ppGameUI[X_BUTTON]->m_custom.scaleX < 1.0f) {
		m_ppGameUI[X_BUTTON]->m_custom.scaleX = 1.0f;
		scaleSpeed = -scaleSpeed;
	}
	m_ppGameUI[X_BUTTON]->m_custom.scaleY = m_ppGameUI[X_BUTTON]->m_custom.scaleX;
}
