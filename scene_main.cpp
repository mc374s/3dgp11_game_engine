#include "game.h"
#include "sprite_data.h"
#include "sound_data.h"
#include "obj2d.h"
#include "book.h"

#include "map_obj.h"
#include "player.h"
#include "judge.h"
#include "game_ui.h"
#include "scene_title.h"

#include "scene_main.h"

SceneMain::SceneMain()
{
	//init();

	m_pBook = new Book(PAGE_WIDTH, PAGE_HEIGHT, 20, 10, 0, 10, 8);

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

	switch (m_step)
	{
	case STEP::INIT:
		//init();
		//pMapObjManager->init(0);
		pObjManager->init();
		pPlayerManager->init();
		pMapObjManager->init(0);

		pGameUIManager->init();

		m_pStr = "";
		m_timer = 0;
		m_step = STEP::BEGIN;
		//break;
	case STEP::BEGIN:

		m_pBook->update();

		m_isBookClosed = m_pBook->m_isClosed;
		m_isBookOpened = m_pBook->m_isOpened;

		pMapObjManager->stageUpdate();
		if (pPlayerManager->m_pPlayer->m_isOnScrollArea && m_isBookOpened)
		{
			pMapObjManager->setScroll(pPlayerManager->m_pPlayer->m_speed, pPlayerManager->m_pPlayer->m_liveInPagination, pPlayerManager->m_pPlayer->m_mode==P_MODE::RESTART);
		}

		pGameUIManager->update();

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


}

void SceneMain::draw()
{
	View::clear();

	m_pBG->draw();

	m_pBook->draw();

	pGameUIManager->draw();

	drawString(SCREEN_WIDTH / 2, 100, m_pStr, COLOR_YELLOW >> 8 << 8 | 0xD0, STR_CENTER, 80, 80);
	if (m_step==STEP::END && m_timer & 0x20)
	{
		drawString(SCREEN_WIDTH / 2, 400, "Click [x] to TITLE", COLOR_WHITE >> 8 << 8 | 0xA0, STR_CENTER, 40, 40);
	}


}