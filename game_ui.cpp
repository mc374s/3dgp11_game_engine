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
	clear();
}

void GameUI::clear()
{
	OBJ2DEX::clear();
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
	m_selectedStageNO = 0;
	// UI for Ink Gage
	m_ppGameUI[A_LEFT_DIVISION]->m_pSprData = &e_sprGageDivisionAllocation;
	m_ppGameUI[A_LEFT_DIVISION]->m_isVisibleAlways = false;
	m_ppGameUI[A_LEFT_DIVISION]->m_isVisible = false;
	m_ppGameUI[A_LEFT_DIVISION]->m_pos = { SCREEN_WIDTH / 2 - m_ppGameUI[A_LEFT_DIVISION]->m_pSprData->width / 2 - 100.0f,SCREEN_HEIGHT / 2 + 260.0f,0.0f };
	m_ppGameUI[A_LEFT_DIVISION]->m_size = { e_sprGageDivisionAllocation.width,e_sprGageDivisionAllocation.height,0.0f };

	*m_ppGameUI[A_RIGHT_DIVISION] = *m_ppGameUI[A_LEFT_DIVISION];
	m_ppGameUI[A_RIGHT_DIVISION]->m_pos.x = SCREEN_WIDTH / 2 + m_ppGameUI[A_RIGHT_DIVISION]->m_pSprData->width / 2 + 100.0f;
	m_ppGameUI[A_RIGHT_DIVISION]->m_custom.reflectX = true;

	m_ppGameUI[A_LEFT_GAGE]->m_pSprData = &e_sprGageAllocation;
	m_ppGameUI[A_LEFT_GAGE]->m_isVisibleAlways = false;
	m_ppGameUI[A_LEFT_GAGE]->m_isVisible = false;
	m_ppGameUI[A_LEFT_GAGE]->m_custom.rgba = 0x735E60FF;
	//m_ppGameUI[A_LEFT_GAGE]->m_alpha = 200;
	m_ppGameUI[A_LEFT_GAGE]->m_pos.x = m_ppGameUI[A_LEFT_DIVISION]->m_pos.x;
	m_ppGameUI[A_LEFT_GAGE]->m_pos.y = m_ppGameUI[A_LEFT_DIVISION]->m_pos.y - 10;
	m_ppGameUI[A_LEFT_GAGE]->m_size = { e_sprGageDivisionAllocation.width,e_sprGageDivisionAllocation.height,0 };
	m_ppGameUI[A_LEFT_GAGE]->m_custom.scaleMode = SCALE_MODE::RIGHTCENTER;

	*m_ppGameUI[A_RIGHT_GAGE] = *m_ppGameUI[A_LEFT_GAGE];

	//m_ppGameUI[A_RIGHT_GAGE]->m_custom.rgba = 0xDD0000FF;
	m_ppGameUI[A_RIGHT_GAGE]->m_pos.x = m_ppGameUI[A_RIGHT_DIVISION]->m_pos.x;
	m_ppGameUI[A_RIGHT_GAGE]->m_pos.y = m_ppGameUI[A_RIGHT_DIVISION]->m_pos.y - 10;
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
	m_ppGameUI[A_LEFT_PLAYER]->m_pos = { SCREEN_WIDTH / 2 - 350,SCREEN_HEIGHT / 2 + 200,1 };
	//m_ppGameUI[A_LEFT_PLAYER]->m_size = { m_ppGameUI[A_LEFT_PLAYER]->m_pSprData->width,m_ppGameUI[A_LEFT_PLAYER]->m_pSprData->height,0 };
	m_ppGameUI[A_LEFT_PLAYER]->m_custom.scaleMode = SCALE_MODE::BOTTOMCENTER;
	m_ppGameUI[A_LEFT_PLAYER]->m_custom.scaleX = m_ppGameUI[A_LEFT_PLAYER]->m_custom.scaleY = 1.2f;

	*m_ppGameUI[A_RIGHT_PLAYER] = *m_ppGameUI[A_LEFT_PLAYER];
	m_ppGameUI[A_RIGHT_PLAYER]->m_pos.x = SCREEN_WIDTH / 2 + 350;
	//m_ppGameUI[A_RIGHT_PLAYER]->m_size= { m_ppGameUI[A_RIGHT_PLAYER]->m_pSprData->width,m_ppGameUI[A_RIGHT_PLAYER]->m_pSprData->height,0 };
	m_ppGameUI[A_LEFT_PLAYER]->m_custom.reflectX = true;

	// UI for Error Mark
	*m_ppGameUI[ERROR_MARK] = *m_ppGameUI[A_LEFT_PLAYER];
	m_ppGameUI[ERROR_MARK]->m_pSprData = &e_sprErrorMark;

	// UI for Player Concentration Gage
	m_ppGameUI[C_GAGE_ANIME]->m_isVisibleAlways = false;
	m_ppGameUI[C_GAGE_ANIME]->m_isVisible = false;
	m_ppGameUI[C_GAGE_ANIME]->m_custom.scaleMode = SCALE_MODE::CENTER;
	*m_ppGameUI[C_GAGE] = *m_ppGameUI[C_PLAYER_FACE] = *m_ppGameUI[C_DIVISION] = *m_ppGameUI[C_GAGE_ANIME];

	m_ppGameUI[C_DIVISION]->m_pSprData = &e_sprGageDivision;
	m_ppGameUI[C_DIVISION]->m_pos = m_ppGameUI[C_DIVISION]->m_initPos = { 0,0,0 };
	*m_ppGameUI[C_DIVISION_WHITE] = *m_ppGameUI[C_DIVISION];
	m_ppGameUI[C_DIVISION_WHITE]->m_pSprData = &e_sprGageDivisionWhite;
	m_ppGameUI[C_DIVISION_WHITE]->m_alpha = 180;

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
	m_ppGameUI[PAUSE_PANEL]->m_setPos = m_ppGameUI[PAUSE_PANEL]->m_initPos = m_ppGameUI[PAUSE_PANEL]->m_pos = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f };
	m_ppGameUI[PAUSE_PANEL]->m_isVisibleAlways = false;
	m_ppGameUI[PAUSE_PANEL]->m_isVisible = false;

	*m_ppGameUI[PAUSE_SELECTED] = *m_ppGameUI[PAUSE_PANEL];
	m_ppGameUI[PAUSE_SELECTED]->m_pSprData = &e_sprPauseSelected;
	m_ppGameUI[PAUSE_SELECTED]->m_setPos.x = m_ppGameUI[PAUSE_SELECTED]->m_initPos.x = m_ppGameUI[PAUSE_PANEL]->m_pos.x - 208;
	m_ppGameUI[PAUSE_SELECTED]->m_setPos.y = m_ppGameUI[PAUSE_SELECTED]->m_initPos.y = m_ppGameUI[PAUSE_PANEL]->m_pos.y - 52;

	// UI for Retry
	m_ppGameUI[RETRY_PANEL]->m_pSprData = &e_sprRetryPanel;
	m_ppGameUI[RETRY_PANEL]->m_setPos = m_ppGameUI[RETRY_PANEL]->m_initPos = m_ppGameUI[RETRY_PANEL]->m_pos = { SCREEN_WIDTH / 2, SCREEN_HEIGHT - 220,0.0f };
	m_ppGameUI[RETRY_PANEL]->m_isVisibleAlways = false;
	m_ppGameUI[RETRY_PANEL]->m_isVisible = false;

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

	// UI for X button
	m_ppGameUI[X_BUTTON]->m_isVisibleAlways = false;
	m_ppGameUI[X_BUTTON]->m_isVisible = false;
	m_ppGameUI[X_BUTTON]->m_pSprData = &e_sprXButton;
	m_ppGameUI[X_BUTTON]->m_initPos = m_ppGameUI[X_BUTTON]->m_pos = { SCREEN_WIDTH / 2,SCREEN_HEIGHT - 100,0.0f };
	m_ppGameUI[X_BUTTON]->m_alpha = 255;

	// UI for Scroll Mode
	m_ppGameUI[SCROLL_MODE]->m_pSprData = &e_sprScrollMode;
	m_ppGameUI[SCROLL_MODE]->m_isVisibleAlways = false;
	m_ppGameUI[SCROLL_MODE]->m_isVisible = false;
	m_ppGameUI[SCROLL_MODE]->m_initPos = m_ppGameUI[SCROLL_MODE]->m_pos = { 0.0f,0.0f,0.0f };
	m_ppGameUI[SCROLL_MODE]->m_alpha = 40;

	//UI for Scroll Arrow
	m_ppGameUI[SCROLL_TOP]->m_pSprData = m_ppGameUI[SCROLL_BOTTOM]->m_pSprData = &e_sprScrollArrow;
	m_ppGameUI[SCROLL_TOP]->m_isVisibleAlways = m_ppGameUI[SCROLL_BOTTOM]->m_isVisibleAlways = false;
	m_ppGameUI[SCROLL_TOP]->m_isVisible = m_ppGameUI[SCROLL_BOTTOM]->m_isVisible = false;
	m_ppGameUI[SCROLL_TOP]->m_initPos = m_ppGameUI[SCROLL_TOP]->m_pos = { SCREEN_WIDTH / 2,50.0f,0.0f };
	m_ppGameUI[SCROLL_BOTTOM]->m_initPos = m_ppGameUI[SCROLL_BOTTOM]->m_pos = { SCREEN_WIDTH / 2,SCREEN_HEIGHT - 50,0.0f };
	m_ppGameUI[SCROLL_BOTTOM]->m_custom.angle = 180;


	// UI for Game Over & Clear & Stage Clear
	m_ppGameUI[STAGE_CLEAR_BEHIND]->m_isVisibleAlways = false;
	m_ppGameUI[STAGE_CLEAR_BEHIND]->m_isVisible = false;
	m_ppGameUI[STAGE_CLEAR_BEHIND]->m_initPos = m_ppGameUI[STAGE_CLEAR_BEHIND]->m_pos = { SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2,0.0f };

	*m_ppGameUI[GAME_OVER_BEHIND] = *m_ppGameUI[GAME_OVER_FRONT] = *m_ppGameUI[GAME_CLEAR_TEXT] = *m_ppGameUI[STAGE_CLEAR_FRONT] = *m_ppGameUI[STAGE_CLEAR_BEHIND];
	m_ppGameUI[STAGE_CLEAR_BEHIND]->m_custom.scaleX = m_ppGameUI[STAGE_CLEAR_BEHIND]->m_custom.scaleY = 1.7f;
	m_ppGameUI[STAGE_CLEAR_FRONT]->m_custom.scaleX = m_ppGameUI[STAGE_CLEAR_FRONT]->m_custom.scaleY = 1.7f;

	m_ppGameUI[GAME_CLEAR_TEXT]->m_pSprData = &e_sprGameClear;
	m_ppGameUI[STAGE_CLEAR_BEHIND]->m_pSprData = &e_sprStageClearBehind;
	m_ppGameUI[STAGE_CLEAR_FRONT]->m_pSprData = &e_sprStageClearFront;
	m_ppGameUI[GAME_OVER_BEHIND]->m_initPos.y = m_ppGameUI[GAME_OVER_BEHIND]->m_pos.y += -100.0f;
	m_ppGameUI[GAME_OVER_BEHIND]->m_pSprData = &e_sprGameOverBehind;
	m_ppGameUI[GAME_OVER_FRONT]->m_initPos.y = m_ppGameUI[GAME_OVER_FRONT]->m_pos.y += -100.0f;
	m_ppGameUI[GAME_OVER_FRONT]->m_pSprData = &e_sprGameOverFront;

	// UI for Stage Selection
	m_ppGameUI[STAGE_SELECTED]->m_pSprData = &e_sprStageSelected;
	m_ppGameUI[STAGE_SELECTED]->m_isVisibleAlways = false;
	m_ppGameUI[STAGE_SELECTED]->m_isVisible = false;
	m_ppGameUI[STAGE_SELECTED]->m_setPos = m_ppGameUI[STAGE_SELECTED]->m_initPos = m_ppGameUI[STAGE_SELECTED]->m_pos = { SCREEN_WIDTH / 4.0f,170.0f,0.0f };
	m_ppGameUI[STAGE_SELECTED]->m_alpha = 0;

	// UI for Stage Cleared
	m_ppGameUI[STAGE_CLEARED]->m_pSprData = &e_sprClearMark;
	//m_ppGameUI[STAGE_CLEARED]->m_custom.scaleX = m_ppGameUI[STAGE_CLEARED]->m_custom.scaleY = 0.15f;
	m_ppGameUI[STAGE_CLEARED]->m_alpha = 160;
	m_ppGameUI[STAGE_CLEARED]->m_isVisibleAlways = true;
	m_ppGameUI[STAGE_CLEARED]->m_isVisible = true;
	m_ppGameUI[STAGE_CLEARED]->m_setPos = m_ppGameUI[STAGE_CLEARED]->m_initPos = m_ppGameUI[STAGE_CLEARED]->m_pos = { PAGE_WIDTH / 2 + 50,150.0f,0.0f };

	// UI for Title
	m_ppGameUI[TITLE_STAMP]->m_pSprData = &e_sprTitleStamp;
	m_ppGameUI[TITLE_STAMP]->m_isVisibleAlways = false;
	m_ppGameUI[TITLE_STAMP]->m_isVisible = false;
	m_ppGameUI[TITLE_STAMP]->m_setPos = m_ppGameUI[TITLE_STAMP]->m_initPos = m_ppGameUI[TITLE_STAMP]->m_pos = { 100.0f,100.0f,0.0f };

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

void GameUIManager::drawStageClearedMark(int a_pagination)
{
	if (m_ppGameUI[STAGE_CLEARED] && m_ppGameUI[STAGE_CLEARED]->m_isVisible)
	{
		for (int i = STAGE_SELECT_MAX_NUM + 1, realStageNO = 0; i < STAGE_MAX_NUM;) {
			if (m_stageClearFlag[i] && /*(realStageNO / 12 == m_selectedStageNO / 12)*/a_pagination == m_stageSecectionPagination[i]/* && (realStageNO / 6 % 2 != a_pagination % 2)*/) {
				m_ppGameUI[STAGE_CLEARED]->m_pos.x = m_ppGameUI[STAGE_CLEARED]->m_initPos.x /*+ realStageNO % 12 / 6 * SCREEN_WIDTH / 2*/;
				if (realStageNO % 6 < 3) {
					m_ppGameUI[STAGE_CLEARED]->m_pos.y = m_ppGameUI[STAGE_CLEARED]->m_initPos.y + realStageNO % 6 * 59.0f;
				}
				else {
					m_ppGameUI[STAGE_CLEARED]->m_pos.y = m_ppGameUI[STAGE_CLEARED]->m_initPos.y + (realStageNO % 6 - 1) * 59.0f + 205.0f;
				}
				m_ppGameUI[STAGE_CLEARED]->draw();
			}
			++i;
			if ((i - STAGE_SELECT_MAX_NUM) % 4 == 0) {
				++i;
			}
			realStageNO = i - STAGE_SELECT_MAX_NUM - ((i - STAGE_SELECT_MAX_NUM) / 4 + 1);

		}
	}
}

void GameUIManager::drawTitleStamp(int a_pagination) {
	if (m_ppGameUI[TITLE_STAMP] && m_ppGameUI[TITLE_STAMP]->m_isVisible)
	{
		if (a_pagination == 0) {
			m_ppGameUI[TITLE_STAMP]->draw();
		}
	}
}


void GameUIManager::draw()
{
	//drawStageClearedMark();
	/*if (m_ppGameUI[STAGE_CLEARED] && m_ppGameUI[STAGE_CLEARED]->m_isVisible) {
		m_ppGameUI[STAGE_CLEARED]->m_isVisible = false;
	}*/
	
	for (auto &pObj : m_ppGameUI)
	{
		if (pObj && pObj->m_pSprData && pObj->m_isVisible && pObj != m_ppGameUI[STAGE_CLEARED] && pObj != m_ppGameUI[TITLE_STAMP])
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

void GameUIManager::showInkTransferGage(float a_playerConcentration, float a_transferConcentration, bool a_isOnLeftPage, bool a_isTranscriptAble, SPRITE_DATA* a_pPlayerSprData, bool a_isRefect)
{
	static SPRITE_DATA* pPlayerSprData = nullptr;

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
		if (a_pPlayerSprData && pPlayerSprData!= a_pPlayerSprData){
			//*(m_ppGameUI[A_LEFT_PLAYER]->m_pSprData) = *(m_ppGameUI[A_RIGHT_PLAYER]->m_pSprData) = (*a_pPlayerSprData);
			pPlayerSprData = a_pPlayerSprData;
			//m_ppGameUI[A_LEFT_PLAYER]->m_pSprData->texNum = 8;
			m_ppGameUI[A_LEFT_PLAYER]->m_pSprData->height	= a_pPlayerSprData->height * 6;
			m_ppGameUI[A_LEFT_PLAYER]->m_pSprData->width	= a_pPlayerSprData->width * 6;
			m_ppGameUI[A_LEFT_PLAYER]->m_pSprData->top		= a_pPlayerSprData->top * 6;
			m_ppGameUI[A_LEFT_PLAYER]->m_pSprData->left		= a_pPlayerSprData->left * 6;
			m_ppGameUI[A_LEFT_PLAYER]->m_pSprData->ofsX		= a_pPlayerSprData->ofsX * 6;
			m_ppGameUI[A_LEFT_PLAYER]->m_pSprData->ofsY		= a_pPlayerSprData->ofsY * 6; 
			//m_ppGameUI[A_RIGHT_PLAYER]->m_pSprData->texNum = 8;
			m_ppGameUI[A_RIGHT_PLAYER]->m_pSprData->height = a_pPlayerSprData->height * 6;
			m_ppGameUI[A_RIGHT_PLAYER]->m_pSprData->width = a_pPlayerSprData->width * 6;
			m_ppGameUI[A_RIGHT_PLAYER]->m_pSprData->top = a_pPlayerSprData->top * 6;
			m_ppGameUI[A_RIGHT_PLAYER]->m_pSprData->left = a_pPlayerSprData->left * 6;
			m_ppGameUI[A_RIGHT_PLAYER]->m_pSprData->ofsX = a_pPlayerSprData->ofsX * 6;
			m_ppGameUI[A_RIGHT_PLAYER]->m_pSprData->ofsY = a_pPlayerSprData->ofsY * 6;
			//*(m_ppGameUI[A_LEFT_PLAYER]->m_pSprData) = *(m_ppGameUI[A_RIGHT_PLAYER]->m_pSprData);
			//m_ppGameUI[A_LEFT_PLAYER]->m_custom.scaleX = m_ppGameUI[A_RIGHT_PLAYER]->m_custom.scaleX = m_ppGameUI[A_LEFT_PLAYER]->m_custom.scaleY = m_ppGameUI[A_RIGHT_PLAYER]->m_custom.scaleY = 6.0f;
		}
		else {

		}
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
			a_isRefect = !a_isRefect;
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
			m_ppGameUI[A_RIGHT_PLAYER]->m_custom.reflectX = a_isRefect;
			m_ppGameUI[A_LEFT_PLAYER]->m_custom.reflectX = !a_isRefect;

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
			m_ppGameUI[A_LEFT_PLAYER]->m_custom.reflectX = a_isRefect;
			m_ppGameUI[A_RIGHT_PLAYER]->m_custom.reflectX = !a_isRefect;

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
			if (a_isOnLeftPage){
				m_ppGameUI[ERROR_MARK]->m_pos.x = m_ppGameUI[A_LEFT_PLAYER]->m_pos.x;
			}
			else {
				m_ppGameUI[ERROR_MARK]->m_pos.x = m_ppGameUI[A_RIGHT_PLAYER]->m_pos.x;
			}
			m_ppGameUI[ERROR_MARK]->m_isVisible = true;

		}

	}
}

void GameUIManager::showPlayerConcentration(float a_playerConcentration, int a_playerLife, bool a_isDamaged, bool a_isOnBlurArea, Vector3 a_pos)
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
		if (a_isOnBlurArea){
			m_ppGameUI[C_DIVISION_WHITE]->m_isVisible = true;
		}
	}

	m_ppGameUI[C_GAGE_ANIME]->m_pos.x = m_ppGameUI[C_GAGE]->m_pos.x + m_ppGameUI[C_GAGE]->m_custom.scaleX*m_ppGameUI[C_GAGE]->m_pSprData->width;
	m_ppGameUI[C_GAGE_ANIME]->m_custom.rgba = m_ppGameUI[C_GAGE]->m_custom.rgba;
	m_ppGameUI[C_GAGE_ANIME]->animation();
	//m_ppGameUI[C_PLAYER_FACE]->m_alpha = 255 * a_playerConcentration / (float)P_CONCENTRATION_MAX;

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
		//m_ppGameUI[PAUSE_SELECTED]->m_setPos.x = m_ppGameUI[PAUSE_PANEL]->m_initPos.x - 208;
		//m_ppGameUI[PAUSE_SELECTED]->m_setPos.y = m_ppGameUI[PAUSE_PANEL]->m_initPos.y - 52 + a_slelectedNO * 90.0f;
		m_ppGameUI[PAUSE_SELECTED]->m_pos.x = m_ppGameUI[PAUSE_PANEL]->m_initPos.x - 208.0f;
		//m_ppGameUI[PAUSE_SELECTED]->m_setPos.y = m_ppGameUI[PAUSE_PANEL]->m_initPos.y - 74.0f + a_slelectedNO * 60.0f;
		m_ppGameUI[PAUSE_SELECTED]->m_pos.y = m_ppGameUI[PAUSE_PANEL]->m_initPos.y - 74.0f + a_slelectedNO * 60.0f;
	}

	/*if (m_ppGameUI[PAUSE_SELECTED]->m_pos.x < m_ppGameUI[PAUSE_SELECTED]->m_setPos.x) {
		m_ppGameUI[PAUSE_SELECTED]->m_pos.x += 10.0f;
		if (m_ppGameUI[PAUSE_SELECTED]->m_pos.x > m_ppGameUI[PAUSE_SELECTED]->m_setPos.x) {
			m_ppGameUI[PAUSE_SELECTED]->m_pos.x = m_ppGameUI[PAUSE_SELECTED]->m_setPos.x;
		}
	}
	if (m_ppGameUI[PAUSE_SELECTED]->m_pos.x > m_ppGameUI[PAUSE_SELECTED]->m_setPos.x) {
		m_ppGameUI[PAUSE_SELECTED]->m_pos.x -= 10.0f;
		if (m_ppGameUI[PAUSE_SELECTED]->m_pos.x < m_ppGameUI[PAUSE_SELECTED]->m_setPos.x) {
			m_ppGameUI[PAUSE_SELECTED]->m_pos.x = m_ppGameUI[PAUSE_SELECTED]->m_setPos.x;
		}
	}

	if (m_ppGameUI[PAUSE_SELECTED]->m_pos.y < m_ppGameUI[PAUSE_SELECTED]->m_setPos.y) {
		m_ppGameUI[PAUSE_SELECTED]->m_pos.y += 10.0f;
		if (m_ppGameUI[PAUSE_SELECTED]->m_pos.y > m_ppGameUI[PAUSE_SELECTED]->m_setPos.y) {
			m_ppGameUI[PAUSE_SELECTED]->m_pos.y = m_ppGameUI[PAUSE_SELECTED]->m_setPos.y;
		}
	}
	if (m_ppGameUI[PAUSE_SELECTED]->m_pos.y > m_ppGameUI[PAUSE_SELECTED]->m_setPos.y) {
		m_ppGameUI[PAUSE_SELECTED]->m_pos.y -= 10.0f;
		if (m_ppGameUI[PAUSE_SELECTED]->m_pos.y < m_ppGameUI[PAUSE_SELECTED]->m_setPos.y) {
			m_ppGameUI[PAUSE_SELECTED]->m_pos.y = m_ppGameUI[PAUSE_SELECTED]->m_setPos.y;
		}
	}*/
}

void GameUIManager::showRetryPanel(int a_slelectedNO)
{
	if (m_ppGameUI[RETRY_PANEL])
	{
		m_ppGameUI[RETRY_PANEL]->m_isVisible = true;
		m_ppGameUI[PAUSE_SELECTED]->m_isVisible = true;
		
		//m_ppGameUI[PAUSE_SELECTED]->m_setPos.x = m_ppGameUI[RETRY_PANEL]->m_initPos.x - 208;
		m_ppGameUI[PAUSE_SELECTED]->m_pos.x = m_ppGameUI[RETRY_PANEL]->m_initPos.x - 208.0f;
		//m_ppGameUI[PAUSE_SELECTED]->m_setPos.y = m_ppGameUI[RETRY_PANEL]->m_initPos.y - 52.0f + a_slelectedNO * 90.0f;
		m_ppGameUI[PAUSE_SELECTED]->m_pos.y = m_ppGameUI[RETRY_PANEL]->m_initPos.y - 52.0f + a_slelectedNO * 90.0f;
	}

	/*if (m_ppGameUI[PAUSE_SELECTED]->m_pos.x < m_ppGameUI[PAUSE_SELECTED]->m_setPos.x) {
		m_ppGameUI[PAUSE_SELECTED]->m_pos.x += 10.0f;
		if (m_ppGameUI[PAUSE_SELECTED]->m_pos.x > m_ppGameUI[PAUSE_SELECTED]->m_setPos.x) {
			m_ppGameUI[PAUSE_SELECTED]->m_pos.x = m_ppGameUI[PAUSE_SELECTED]->m_setPos.x;
		}
	}
	if (m_ppGameUI[PAUSE_SELECTED]->m_pos.x > m_ppGameUI[PAUSE_SELECTED]->m_setPos.x) {
		m_ppGameUI[PAUSE_SELECTED]->m_pos.x -= 10.0f;
		if (m_ppGameUI[PAUSE_SELECTED]->m_pos.x < m_ppGameUI[PAUSE_SELECTED]->m_setPos.x) {
			m_ppGameUI[PAUSE_SELECTED]->m_pos.x = m_ppGameUI[PAUSE_SELECTED]->m_setPos.x;
		}
	}

	if (m_ppGameUI[PAUSE_SELECTED]->m_pos.y < m_ppGameUI[PAUSE_SELECTED]->m_setPos.y) {
		m_ppGameUI[PAUSE_SELECTED]->m_pos.y += 30.0f;
		if (m_ppGameUI[PAUSE_SELECTED]->m_pos.y > m_ppGameUI[PAUSE_SELECTED]->m_setPos.y) {
			m_ppGameUI[PAUSE_SELECTED]->m_pos.y = m_ppGameUI[PAUSE_SELECTED]->m_setPos.y;
		}
	}
	if (m_ppGameUI[PAUSE_SELECTED]->m_pos.y > m_ppGameUI[PAUSE_SELECTED]->m_setPos.y) {
		m_ppGameUI[PAUSE_SELECTED]->m_pos.y -= 30.0f;
		if (m_ppGameUI[PAUSE_SELECTED]->m_pos.y < m_ppGameUI[PAUSE_SELECTED]->m_setPos.y) {
			m_ppGameUI[PAUSE_SELECTED]->m_pos.y = m_ppGameUI[PAUSE_SELECTED]->m_setPos.y;
		}
	}*/
}

void GameUIManager::showHelpButton(bool a_showHelp)
{
	if (a_showHelp) {
		m_ppGameUI[HELP]->m_isVisible = false;
		m_ppGameUI[HELP_BUTTON]->m_isVisible = true;
	}
	if ((KEY_BOARD.Q || GAME_PAD.IsLeftShoulderPressed()) || a_showHelp) {
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

void GameUIManager::showScrollMode()
{
	static int alphaSpeed = 10, timer = 0;
	timer++;
	m_ppGameUI[SCROLL_MODE]->m_isVisible = true;
	m_ppGameUI[SCROLL_TOP]->m_isVisible = true;
	m_ppGameUI[SCROLL_BOTTOM]->m_isVisible = true;
	m_ppGameUI[SCROLL_MODE]->m_alpha += alphaSpeed;
	if (m_ppGameUI[SCROLL_MODE]->m_alpha > 255) {
		m_ppGameUI[SCROLL_MODE]->m_alpha = 255;
	}
	if ((KEY_TRACKER.released.E || PAD_TRACKER.rightShoulder == PAD_TRACKER.RELEASED) && timer > 30) {
		m_ppGameUI[SCROLL_MODE]->m_alpha = 40;
		timer = 0;
	}
}

void GameUIManager::showStageSelected(int a_selectedStageNO, bool a_doReset)
{
	m_selectedStageNO = a_selectedStageNO;
	if (a_doReset)
	{
		m_ppGameUI[STAGE_SELECTED]->m_pos = m_ppGameUI[STAGE_SELECTED]->m_initPos;
		m_ppGameUI[STAGE_SELECTED]->m_alpha = 0;
		return;
	}
	m_ppGameUI[STAGE_SELECTED]->m_isVisible = true;
	m_ppGameUI[STAGE_SELECTED]->m_alpha += 10;
	if (a_selectedStageNO % 12 < 6) {
		m_ppGameUI[STAGE_SELECTED]->m_custom.reflectX = true;
		m_ppGameUI[STAGE_SELECTED]->m_setPos.x = m_ppGameUI[STAGE_SELECTED]->m_initPos.x;
	}
	else {
		m_ppGameUI[STAGE_SELECTED]->m_custom.reflectX = false;
		m_ppGameUI[STAGE_SELECTED]->m_setPos.x = m_ppGameUI[STAGE_SELECTED]->m_initPos.x + SCREEN_WIDTH / 2.0f;
	}

	if (a_selectedStageNO % 6 < 3){
		m_ppGameUI[STAGE_SELECTED]->m_setPos.y = m_ppGameUI[STAGE_SELECTED]->m_initPos.y + a_selectedStageNO % 6 * 59.0f;
	}
	else {
		m_ppGameUI[STAGE_SELECTED]->m_setPos.y = m_ppGameUI[STAGE_SELECTED]->m_initPos.y + (a_selectedStageNO % 6 - 1) * 59.0f + 205.0f;
	}

	if (m_ppGameUI[STAGE_SELECTED]->m_pos.x < m_ppGameUI[STAGE_SELECTED]->m_setPos.x){
		m_ppGameUI[STAGE_SELECTED]->m_pos.x += (m_ppGameUI[STAGE_SELECTED]->m_setPos.x - m_ppGameUI[STAGE_SELECTED]->m_pos.x) / 5;
		if (m_ppGameUI[STAGE_SELECTED]->m_pos.x > m_ppGameUI[STAGE_SELECTED]->m_setPos.x) {
			m_ppGameUI[STAGE_SELECTED]->m_pos.x = m_ppGameUI[STAGE_SELECTED]->m_setPos.x;
		}
	}
	if (m_ppGameUI[STAGE_SELECTED]->m_pos.x > m_ppGameUI[STAGE_SELECTED]->m_setPos.x) {
		m_ppGameUI[STAGE_SELECTED]->m_pos.x += (m_ppGameUI[STAGE_SELECTED]->m_setPos.x - m_ppGameUI[STAGE_SELECTED]->m_pos.x) / 5;
		if (m_ppGameUI[STAGE_SELECTED]->m_pos.x < m_ppGameUI[STAGE_SELECTED]->m_setPos.x) {
			m_ppGameUI[STAGE_SELECTED]->m_pos.x = m_ppGameUI[STAGE_SELECTED]->m_setPos.x;
		}
	}

	if (m_ppGameUI[STAGE_SELECTED]->m_pos.y < m_ppGameUI[STAGE_SELECTED]->m_setPos.y) {
		m_ppGameUI[STAGE_SELECTED]->m_pos.y += (m_ppGameUI[STAGE_SELECTED]->m_setPos.y - m_ppGameUI[STAGE_SELECTED]->m_pos.y) / 5;
		if (m_ppGameUI[STAGE_SELECTED]->m_pos.y > m_ppGameUI[STAGE_SELECTED]->m_setPos.y) {
			m_ppGameUI[STAGE_SELECTED]->m_pos.y = m_ppGameUI[STAGE_SELECTED]->m_setPos.y;
		}
	}
	if (m_ppGameUI[STAGE_SELECTED]->m_pos.y > m_ppGameUI[STAGE_SELECTED]->m_setPos.y) {
		m_ppGameUI[STAGE_SELECTED]->m_pos.y += (m_ppGameUI[STAGE_SELECTED]->m_setPos.y - m_ppGameUI[STAGE_SELECTED]->m_pos.y) / 5;
		if (m_ppGameUI[STAGE_SELECTED]->m_pos.y < m_ppGameUI[STAGE_SELECTED]->m_setPos.y) {
			m_ppGameUI[STAGE_SELECTED]->m_pos.y = m_ppGameUI[STAGE_SELECTED]->m_setPos.y;
		}
	}

}

