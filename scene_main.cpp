#include "game.h"
#include "sprite_data.h"
#include "sound_data.h"
#include "obj2d.h"
#include "book.h"

#include "map_obj.h"
#include "player.h"
#include "judge.h"
#include "game_ui.h"
#include "effect.h"
#include "scene_title.h"

#include "scene_main.h"

SceneMain::SceneMain()
{
	//init();

	m_pBook = new Book(PAGE_WIDTH, PAGE_HEIGHT, 20, 10, 0, 10, 14);

	m_pBG = new OBJ2D;
	m_pBG->m_pSprData = &e_sprMainBG;
	//m_bg.m_pos = { SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2,0 };

	//pObjManager->init();
	//pPlayerManager->init();
	//pMapObjManager->init(0);

	//pGameUIManager->init();

	m_pStr = "";
}

void SceneMain::init()
{
	//MFAudioPlay(BGM_TITLE, true);
	/*MFAudioStop(BGM_TITLE);
	MFAudioPause(BGM_TITLE);
	MFAudioContinue(BGM_TITLE);*/
	Scene::init();
	m_pausedOption = PAUSED_SELECTION::TO_GAME;
}

SceneMain::~SceneMain()
{
	if (m_pNextScene)
	{
		//delete nextScene;
		m_pNextScene = nullptr;
	}
	SAFE_DELETE(m_pBook);
	SAFE_DELETE(m_pBG);
};

void SceneMain::update()
{	
	if (KEY_TRACKER.pressed.Space || PAD_TRACKER.menu == PAD_TRACKER.PRESSED)
	{
		m_isPaused = true;
	}

	if (m_isPaused)
	{
		pGameUIManager->showPausePanel(m_pausedOption);
		if (KEY_TRACKER.pressed.S || PAD_TRACKER.leftStickUp == PAD_TRACKER.PRESSED)
		{
			m_pausedOption++;
		}
		if (KEY_TRACKER.pressed.W || PAD_TRACKER.leftStickDown == PAD_TRACKER.PRESSED)
		{
			m_pausedOption--;
		}
		m_pausedOption = abs(m_pausedOption) % (int)PAUSED_SELECTION::MAX_PAUSED_SELECTION_NUM;
		if (KEY_TRACKER.released.Z || PAD_TRACKER.a == PAD_TRACKER.RELEASED)
		{
			if (m_pausedOption == PAUSED_SELECTION::TO_GAME)
			{
				m_isPaused = false;
			}
			if (m_pausedOption == PAUSED_SELECTION::TO_TITLE)
			{
				m_isPaused = false;
				m_step = STEP::INIT;
				changeScene(SCENE_TITLE);
			}
		}

		return;
	}

	switch (m_step)
	{
	case STEP::INIT:
		//init();
		//pMapObjManager->init(0);
		m_pBook->init();
		pObjManager->init();
		pGameUIManager->init();
		pEffectManager->init();

		pMapObjManager->init(0);
		pPlayerManager->init();
		//break;
	case STEP::INIT+1:

		m_pStr = "";
		m_timer = 0;
		m_step = STEP::INIT + 2;
		m_pausedOption = PAUSED_SELECTION::TO_GAME;
		//break;
	case STEP::INIT+2:

		m_pBook->update();
		m_isBookClosed = m_pBook->m_isClosed;
		m_isBookOpened = m_pBook->m_isOpened;
		if (KEY_TRACKER.pressed.Z || PAD_TRACKER.a == PAD_TRACKER.PRESSED)
		{
			m_pBook->m_pfMove = &Book::startReading;
			pObjManager->init();
			pGameUIManager->init();
			pEffectManager->init();

			pMapObjManager->init(0);
			pPlayerManager->init();

		}
		if (m_isBookOpened)
		{
			m_step = STEP::BEGIN;
		}
		pMapObjManager->stageUpdate();
		pMapObjManager->update();
		break;
	case STEP::BEGIN:

		m_pBook->update();

		m_isBookClosed = m_pBook->m_isClosed;
		m_isBookOpened = m_pBook->m_isOpened;

		pMapObjManager->stageUpdate();
		pMapObjManager->update();
		if (m_isBookOpened)
		{

			pGameUIManager->showPlayerConcentration(pPlayerManager->m_pPlayer->m_concentration, pPlayerManager->m_pPlayer->getLife());
			if (pPlayerManager->m_pPlayer->m_isOnScrollArea)
			{
				pMapObjManager->setScroll(pPlayerManager->m_pPlayer->m_speed, pPlayerManager->m_pPlayer->m_liveInPagination, pPlayerManager->m_pPlayer->m_mode == P_MODE::RESTART);
			}
		}

		//pGameUIManager->update();
		pEffectManager->update();

		judgeAll();

		if (pPlayerManager->m_pPlayer->m_mode == P_MODE::CLEAR)
		{
			m_pStr = "GAME CLEAR";
			m_timer++;
			if (m_timer > 300)
			{
				m_step = STEP::INIT;
				changeScene(SCENE_TITLE);
			}
		}

		if (pPlayerManager->m_pPlayer->m_mode == P_MODE::DEAD)
		{

			m_pStr = "GAME OVER"; 
			m_timer = 0;
			m_step = STEP::END;

		}

		break;
	case STEP::END:
		m_timer++;
		if (KEY_TRACKER.pressed.C || PAD_TRACKER.x == PAD_TRACKER.PRESSED || m_timer > 600)
		{
			m_timer = 0;
			m_step = STEP::INIT;
			changeScene(SCENE_TITLE);
		}
		break;
	default:
		break;
	}

	if (KEY_TRACKER.pressed.End || PAD_TRACKER.back == PAD_TRACKER.PRESSED)
	{
		if (m_pBook->m_step>STEP::END)
		{
			m_pBook->m_pfMove = &Book::finishReading;
			m_step = STEP::INIT + 1;
		}
	}


}

void SceneMain::draw()
{
	View::clear();

	m_pBG->draw();

	m_pBook->draw();

	if (m_step >= STEP::BEGIN) {
		pGameUIManager->draw();
		pEffectManager->draw();
	}

	drawString(SCREEN_WIDTH / 2, 100, m_pStr, COLOR_YELLOW >> 8 << 8 | 0xD0, STR_CENTER, 80, 80);
	if (m_step==STEP::END && m_timer & 0x20)
	{
		drawString(SCREEN_WIDTH / 2, 400, "Click [x] to TITLE", COLOR_WHITE >> 8 << 8 | 0xA0, STR_CENTER, 40, 40);
	}


}