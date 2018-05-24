#include "game.h"
#include "sprite_data.h"
#include "book.h"

#include "scene_title.h"

#include "map_obj.h"
#include "judge.h"

#include "game_ui.h"
#include "player.h"
#include "sound_data.h"

#include "scene_main.h"

SceneMain::SceneMain()
{
	//init();

	m_pBook = new Book(PAGE_WIDTH, PAGE_HEIGHT, 20, 10, 0, 10, 40, 8);

	m_bg.m_pSprData = &e_sprMainBG;
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

		judgeAll();

		if (pPlayerManager->m_pPlayer->m_mode == P_MODE::CLEAR)
		{
			m_pStr = "GAME CLEAR";
			m_timer++;
			if (m_timer > 120)
			{
				//m_state = STEP::RESTART;
				//changeScene(SCENE_TITLE);
			}
		}

		if (pPlayerManager->m_pPlayer->m_mode == P_MODE::DEAD)
		{

			m_pStr = "GAME OVER";
			m_timer++;
			if (m_timer > 120)
			{
				m_step = STEP::END;
			}
		}

		break;
	case STEP::END:


		break;
	default:
		break;
	}

	if (KEY_BOARD.Home || GAME_PAD.IsBackPressed())
	{
		m_step = STEP::INIT;
		changeScene(SCENE_TITLE);
	}

}

void SceneMain::draw()
{
	View::clear();

	m_bg.draw();

	m_pBook->draw();

	pGameUIManager->draw();

	drawString(SCREEN_WIDTH / 2, 100, m_pStr, COLOR_YELLOW >> 8 << 8 | 0x80, STR_CENTER, 80, 80);
	drawString(0, 0, "Click [HOME] to SCENE_TITLE", COLOR_RED >> 8 << 8 | 0x80, STR_LEFT, 32, 32);


}