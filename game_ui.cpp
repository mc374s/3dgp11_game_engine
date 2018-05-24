#include "game.h"
#include "sprite_data.h"
#include "obj2d.h"

#include "game_ui.h"
#include "player.h"

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
}

void GameUIManager::init()
{
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
	m_ppGameUI[GAGE_LEFT]->m_pos = { (SCREEN_WIDTH - m_ppGameUI[GAGE_LEFT]->m_pSprData->width) / 2,SCREEN_HEIGHT / 2,1 };
	m_ppGameUI[GAGE_LEFT]->m_size = { e_sprGageDivision.width,e_sprGageDivision.height,0 };
	m_ppGameUI[GAGE_LEFT]->m_custom.scaleMode = SCALE_MODE::RIGHTCENTER;

	*m_ppGameUI[GAGE_RIGHT] = *m_ppGameUI[GAGE_LEFT];

	m_ppGameUI[GAGE_RIGHT]->m_custom.rgba = 0xDD0000FF;
	m_ppGameUI[GAGE_RIGHT]->m_pos = { (SCREEN_WIDTH + m_ppGameUI[GAGE_LEFT]->m_pSprData->width) / 2,SCREEN_HEIGHT / 2,1 };
	m_ppGameUI[GAGE_RIGHT]->m_custom.scaleMode = SCALE_MODE::LEFTCENTER;

	m_ppGameUI[PLAYER_LEFT]->m_pSprData = &e_sprLargePlayer;
	m_ppGameUI[PLAYER_LEFT]->m_isVisible = false;
	m_ppGameUI[PLAYER_LEFT]->m_pos = { SCREEN_WIDTH / 2 - 300,SCREEN_HEIGHT / 2,1 };
	m_ppGameUI[PLAYER_LEFT]->m_size = { m_ppGameUI[PLAYER_LEFT]->m_pSprData->width,m_ppGameUI[PLAYER_LEFT]->m_pSprData->height,0 };
	m_ppGameUI[PLAYER_LEFT]->m_custom.scaleMode = SCALE_MODE::CENTER;
	m_ppGameUI[PLAYER_LEFT]->m_custom.scaleX = m_ppGameUI[PLAYER_LEFT]->m_custom.scaleY = 2.0f;

	*m_ppGameUI[PLAYER_RIGHT] = *m_ppGameUI[PLAYER_LEFT];
	m_ppGameUI[PLAYER_RIGHT]->m_pos = { SCREEN_WIDTH / 2 + 300,SCREEN_HEIGHT / 2,1 };
	m_ppGameUI[PLAYER_RIGHT]->m_size= { m_ppGameUI[PLAYER_RIGHT]->m_pSprData->width,m_ppGameUI[PLAYER_RIGHT]->m_pSprData->height,0 };
	m_ppGameUI[PLAYER_LEFT]->m_custom.reflectX = true;


	m_life = pPlayerManager->m_pPlayer->getLife();
	for (int i = 0; i < m_life - 1; i++) {
		m_life_stamp[i].m_pSprData = &e_sprLifeStamp;
		m_life_stamp[i].m_pos.y = 30;
	}
	pPlayerManager->m_pPlayer->
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
			if (i >= GAGE_FRAME && i <= PLAYER_RIGHT)
			{
				m_ppGameUI[i]->m_isVisible = false;
			}

		}
	}

	//プレイヤーのライフ数取得してはんこUI表示
	m_life = pPlayerManager->m_pPlayer->getLife();
	for (int i = 0; i < m_life - 1; i++) {
		m_life_stamp[i].m_pos.x = 45 * i + 30;
		m_life_stamp[i].draw();
	}
}

void GameUIManager::setInkGage(int a_playerConcentration, int a_transferConcentration, bool a_isOnLeftPage, bool a_isTranscriptAble)
{
	if (m_ppGameUI[GAGE_FRAME])
	{

		m_ppGameUI[GAGE_FRAME]->m_isVisible = true;
		m_ppGameUI[GAGE_LEFT]->m_isVisible = true;
		m_ppGameUI[GAGE_RIGHT]->m_isVisible = true;
		m_ppGameUI[PLAYER_LEFT]->m_isVisible = true;
		m_ppGameUI[PLAYER_RIGHT]->m_isVisible = true;

		if (!a_isOnLeftPage)
		{
			m_ppGameUI[GAGE_LEFT]->m_custom.scaleX = a_playerConcentration / (float)P_CONCENTRATION_MAX_NUM;
			m_ppGameUI[GAGE_LEFT]->m_custom.rgba = 0x0404B4FF;
			m_ppGameUI[GAGE_LEFT]->m_alpha = 255 * a_playerConcentration / (float)P_CONCENTRATION_MAX_NUM+40;
			m_ppGameUI[GAGE_RIGHT]->m_custom.scaleX = a_transferConcentration / (float)P_CONCENTRATION_MAX_NUM;
			m_ppGameUI[GAGE_RIGHT]->m_custom.rgba = 0xB18904FF;
			m_ppGameUI[GAGE_RIGHT]->m_alpha = 255 * a_transferConcentration / (float)P_CONCENTRATION_MAX_NUM+40;

			//m_ppGameUI[PLAYER_LEFT]->m_custom.rgba = 0x0404B4FF;
			m_ppGameUI[PLAYER_LEFT]->m_alpha = 255 * a_playerConcentration / (float)P_CONCENTRATION_MAX_NUM + 40;
			//m_ppGameUI[PLAYER_RIGHT]->m_custom.rgba = 0xB18904FF;
			m_ppGameUI[PLAYER_RIGHT]->m_alpha = 255 * a_transferConcentration / (float)P_CONCENTRATION_MAX_NUM + 40;

		} else
		{
			m_ppGameUI[GAGE_RIGHT]->m_custom.scaleX = a_playerConcentration / (float)P_CONCENTRATION_MAX_NUM;
			m_ppGameUI[GAGE_RIGHT]->m_custom.rgba = 0x0404B4FF;
			m_ppGameUI[GAGE_RIGHT]->m_alpha = 255 * a_playerConcentration / (float)P_CONCENTRATION_MAX_NUM+40;
			m_ppGameUI[GAGE_LEFT]->m_custom.scaleX = a_transferConcentration / (float)P_CONCENTRATION_MAX_NUM;
			m_ppGameUI[GAGE_LEFT]->m_custom.rgba = 0xB18904FF;
			m_ppGameUI[GAGE_LEFT]->m_alpha = 255 * a_transferConcentration / (float)P_CONCENTRATION_MAX_NUM+40;

			//m_ppGameUI[PLAYER_RIGHT]->m_custom.rgba = 0x0404B4FF;
			m_ppGameUI[PLAYER_RIGHT]->m_alpha = 255 * a_playerConcentration / (float)P_CONCENTRATION_MAX_NUM + 40;
			//m_ppGameUI[PLAYER_LEFT]->m_custom.rgba = 0xB18904FF;
			m_ppGameUI[PLAYER_LEFT]->m_alpha = 255 * a_transferConcentration / (float)P_CONCENTRATION_MAX_NUM + 40;
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
