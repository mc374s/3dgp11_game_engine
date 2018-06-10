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
	pBook->init();
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
	m_stageNO = 0;
}

SceneMain::~SceneMain()
{
	if (m_pNextScene)
	{
		//delete nextScene;
		m_pNextScene = nullptr;
	}
	SAFE_DELETE(m_pBG);
};

void SceneMain::update()
{	
	if ((KEY_TRACKER.pressed.Space || PAD_TRACKER.menu == PAD_TRACKER.PRESSED) && m_step >= STEP::INIT + 2)
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
		if (KEY_TRACKER.released.C || PAD_TRACKER.x == PAD_TRACKER.RELEASED)
		{
			if (m_pausedOption == PAUSED_SELECTION::TO_GAME)
			{
				m_isPaused = false;
			}
			if (m_pausedOption == PAUSED_SELECTION::TO_TITLE)
			{
				m_isPaused = false;
				m_stageNO = 0;
				pStageManager->init(m_stageNO);
				pBook->m_pfMove = &Book::finishReading;
				m_pausedOption = PAUSED_SELECTION::TO_GAME;
				m_step = STEP::INIT + 1;
			}
		}

		return;
	}

	switch (m_step)
	{
	case STEP::INIT:
		//init();
		pBook->clearAll();
		m_stageNO = 0;
		m_pStr = "";
		m_timer = 0;
		pStageManager->init(m_stageNO);
		pGameUIManager->init();
		m_step = STEP::INIT + 1;
		//break;
	case STEP::INIT + 1:
		// Title Scene
		m_pStr = "";
		m_timer = 0;
		pBook->update();
		pStageManager->update();
		if (KEY_TRACKER.pressed.C || PAD_TRACKER.x == PAD_TRACKER.PRESSED)
		{
			if (!pBook->m_pfMove)
			{
				pBook->m_pfMove = &Book::startReading;
			}
		}
		if (pBook->m_isOpened)
		{
			if (m_stageNO > 0)
			{
				m_step = STEP::INIT + 3;
			}
			else
			{
				m_step = STEP::INIT + 2;
			}
		}
		break;
	case STEP::INIT + 2:
		// Stage 00
		m_pStr = "";
		if ((KEY_TRACKER.pressed.C || PAD_TRACKER.x == PAD_TRACKER.PRESSED) && pBook->m_step == STEP::FINISH)
		{
			m_stageNO++;
			pStageManager->init(m_stageNO);
			pBook->m_pfMove = &Book::turnPages;
			pBook->m_targetPaperNO = START_PAGINATION / 2;
			m_step = STEP::INIT + 3;
			break;
		}
		pBook->update();
		pStageManager->update();
		break;
	case STEP::INIT + 3:
		// Stage 01~??
		m_pStr = "";
		m_timer = 0;
		pBook->update();
		pStageManager->update();
		if (pBook->m_step == STEP::FINISH)
		{
			pGameUIManager->init();
			pEffectManager->init();
			pPlayerManager->init();
			m_step = STEP::BEGIN;
		}
		break;
	case STEP::BEGIN:

		pBook->update();

		if (pBook->m_isOpened)
		{
			pGameUIManager->showPlayerConcentration(pPlayerManager->m_pPlayer->m_concentration, pPlayerManager->m_pPlayer->getLife(), pPlayerManager->m_pPlayer->m_isDamaged);
			if (pPlayerManager->m_pPlayer->m_isOnScrollArea)
			{
				pBook->setScroll(pPlayerManager->m_pPlayer->m_speed, pPlayerManager->m_pPlayer->m_liveInPagination, pPlayerManager->m_pPlayer->m_mode == P_MODE::RESTART);
				pEffectManager->setScroll(pPlayerManager->m_pPlayer->m_speed, pPlayerManager->m_pPlayer->m_liveInPagination, pPlayerManager->m_pPlayer->m_mode == P_MODE::RESTART);
			}

			if (KEY_TRACKER.pressed.E || PAD_TRACKER.rightShoulder == PAD_TRACKER.PRESSED)
			{
				m_step = STEP::BEGIN + 1;
				m_timer = 0;
				pPlayerManager->m_pPlayer->m_setPos.y = pPlayerManager->m_pPlayer->m_pos.y;
				break;
			}
			pPlayerManager->update();
		}

		pStageManager->update();
		pEffectManager->update();

		pGameUIManager->update();
		judgeAll();

		if (pPlayerManager->m_pPlayer->m_mode == P_MODE::CLEAR)
		{
			m_pStr = "GAME CLEAR";
			m_timer++;
			if (m_timer > 300 || KEY_TRACKER.pressed.C || PAD_TRACKER.x == PAD_TRACKER.PRESSED)
			{
				m_stageNO++;
				if (m_stageNO >= STAGE_MAX_NUM)
				{
					m_pStr = "";
					//pBook->clear();
					m_stageNO = 0;
					pStageManager->init(m_stageNO);
					pBook->m_pfMove = &Book::turnPages;
					pBook->m_targetPaperNO = START_PAGINATION / 2;
					m_step = STEP::INIT + 2;
					/*pBook->m_pfMove = &Book::finishReading;
					m_step = STEP::INIT + 1;*/
				}
				else
				{
					//pBook->clear();
					pStageManager->init(m_stageNO);
					pBook->m_pfMove = &Book::turnPages;
					pBook->m_targetPaperNO = START_PAGINATION / 2;
					m_step = STEP::INIT + 3;
				}
				m_timer = 0;
			}
		}

		if ((KEY_TRACKER.pressed.PageUp || PAD_TRACKER.back == PAD_TRACKER.PRESSED || PAD_TRACKER.leftTrigger == PAD_TRACKER.PRESSED) && pBook->m_step > STEP::END)
		{
			--m_stageNO;
			m_step = STEP::INIT + 3;
			if (m_stageNO <= 0)
			{
				m_stageNO = 0;
				m_step = STEP::INIT + 2;
			}
			m_timer = 0;
			pStageManager->init(m_stageNO);
			pBook->m_pfMove = &Book::turnPages;
			pBook->m_targetPaperNO = START_PAGINATION / 2;

		}
		if ((KEY_TRACKER.pressed.PageDown || PAD_TRACKER.rightTrigger == PAD_TRACKER.PRESSED) && pBook->m_step > STEP::END)
		{
			++m_stageNO;
			m_step = STEP::INIT + 3;
			if (m_stageNO >= STAGE_MAX_NUM)
			{
				m_stageNO = 0;
				m_step = STEP::INIT + 2;
			}
			pStageManager->init(m_stageNO);
			pBook->m_pfMove = &Book::turnPages;
			pBook->m_targetPaperNO = START_PAGINATION / 2;
			m_timer = 0;

		}

		if (pPlayerManager->m_pPlayer->m_mode == P_MODE::DEAD)
		{

			m_pStr = "GAME OVER"; 
			m_timer = 0;
			m_step = STEP::END;

		}


		break;

	case STEP::BEGIN + 1:
		m_timer++;
		if (m_timer > 20)
		{
			if (KEY_BOARD.W || GAME_PAD.IsLeftThumbStickUp())
			{
				pBook->setScroll(Vector3(0, -10, 0), pPlayerManager->m_pPlayer->m_liveInPagination, true);
				pEffectManager->setScroll(Vector3(0, -10, 0), pPlayerManager->m_pPlayer->m_liveInPagination, true);
				pPlayerManager->m_pPlayer->m_pos.y += 10;
				if (pPlayerManager->m_pPlayer->m_pos.y > pPlayerManager->m_pPlayer->m_setPos.y + pPlayerManager->m_pPlayer->m_scrolledDistance.y)
				{
					pPlayerManager->m_pPlayer->m_pos.y = pPlayerManager->m_pPlayer->m_setPos.y + pPlayerManager->m_pPlayer->m_scrolledDistance.y;
				}
			}
			if (KEY_BOARD.S || GAME_PAD.IsLeftThumbStickDown())
			{
				pBook->setScroll(Vector3(0, 10, 0), pPlayerManager->m_pPlayer->m_liveInPagination, true);
				pEffectManager->setScroll(Vector3(0, 10, 0), pPlayerManager->m_pPlayer->m_liveInPagination, true);
				pPlayerManager->m_pPlayer->m_pos.y -= 10;
				if (pPlayerManager->m_pPlayer->m_pos.y < pPlayerManager->m_pPlayer->m_setPos.y - STAGE_HEIGHT + pPlayerManager->m_pPlayer->m_scrolledDistance.y)
				{
					pPlayerManager->m_pPlayer->m_pos.y = pPlayerManager->m_pPlayer->m_setPos.y - STAGE_HEIGHT + pPlayerManager->m_pPlayer->m_scrolledDistance.y;
				}
			}
		}
		pEffectManager->update();

		pGameUIManager->update();
		pGameUIManager->showPlayerConcentration(pPlayerManager->m_pPlayer->m_concentration, pPlayerManager->m_pPlayer->getLife(), pPlayerManager->m_pPlayer->m_isDamaged);

		if (KEY_TRACKER.pressed.E || PAD_TRACKER.rightShoulder == PAD_TRACKER.PRESSED)
		{
			m_step = STEP::BEGIN + 2;
			m_timer = 0;
			break;
		}
		break;
	case STEP::BEGIN+2:
		if (pPlayerManager->m_pPlayer->m_pos.y > pPlayerManager->m_pPlayer->m_setPos.y)
		{
			pBook->setScroll(Vector3(0, 10, 0), pPlayerManager->m_pPlayer->m_liveInPagination, true);
			pEffectManager->setScroll(Vector3(0, 10, 0), pPlayerManager->m_pPlayer->m_liveInPagination, true);
			pPlayerManager->m_pPlayer->m_pos.y -= 10;
			if (pPlayerManager->m_pPlayer->m_pos.y <= pPlayerManager->m_pPlayer->m_setPos.y)
			{
				pPlayerManager->m_pPlayer->m_pos.y = pPlayerManager->m_pPlayer->m_setPos.y;
			}
		}
		if (pPlayerManager->m_pPlayer->m_pos.y < pPlayerManager->m_pPlayer->m_setPos.y)
		{
			pBook->setScroll(Vector3(0, -10, 0), pPlayerManager->m_pPlayer->m_liveInPagination, true);
			pEffectManager->setScroll(Vector3(0, -10, 0), pPlayerManager->m_pPlayer->m_liveInPagination, true);
			pPlayerManager->m_pPlayer->m_pos.y += 10;
			if (pPlayerManager->m_pPlayer->m_pos.y >= pPlayerManager->m_pPlayer->m_setPos.y)
			{
				pPlayerManager->m_pPlayer->m_pos.y = pPlayerManager->m_pPlayer->m_setPos.y;
			}
		}
		if (fabsf(pPlayerManager->m_pPlayer->m_pos.y - pPlayerManager->m_pPlayer->m_setPos.y) < FLT_EPSILON)
		{
			m_step = STEP::BEGIN;
			break;
		}
		pGameUIManager->showPlayerConcentration(pPlayerManager->m_pPlayer->m_concentration, pPlayerManager->m_pPlayer->getLife(), pPlayerManager->m_pPlayer->m_isDamaged);
		break;
	case STEP::END:
		m_timer++;
		if (KEY_TRACKER.pressed.C || PAD_TRACKER.x == PAD_TRACKER.PRESSED || m_timer > 600)
		{
			m_timer = 0;
			pStageManager->init(m_stageNO);
			pBook->m_pfMove = &Book::finishReading;
			m_step = STEP::INIT + 1;
		}
		break;
	default:
		break;
	}

	if (KEY_TRACKER.pressed.Enter)
	{
		if (pBook->m_step > STEP::END)
		{
			m_stageNO = 0;
			pStageManager->init(m_stageNO);
			pBook->m_pfMove = &Book::finishReading;
			m_step = STEP::INIT + 1;
		}
	}
	if (m_step >= STEP::BEGIN)
	{
		pGameUIManager->showHelpButton();
	}


}

void SceneMain::draw()
{
	View::clear();

	m_pBG->draw();

	pBook->draw();

	pGameUIManager->draw();
	pEffectManager->draw();

	drawString(SCREEN_WIDTH / 2, 100, m_pStr, COLOR_YELLOW >> 8 << 8 | 0xD0, STR_CENTER, 80, 80);
	if (m_step==STEP::END && m_timer & 0x20)
	{
		drawString(SCREEN_WIDTH / 2, 400, "Click [x] to TITLE", COLOR_WHITE >> 8 << 8 | 0xA0, STR_CENTER, 40, 40);
	}
#ifdef  DEBUG
	char buf[256];
	sprintf_s(buf, "StageNO: %d \nm_step %d", m_stageNO, m_step);
	drawString(SCREEN_WIDTH / 2, 400, buf, COLOR_WHITE >> 8 << 8 | 0xA0, STR_CENTER, 40, 40);

#endif //  DEBUG


}