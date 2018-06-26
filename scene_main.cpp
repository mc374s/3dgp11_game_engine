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

#include "stage_data.h"
#include "scene_main.h"

SceneMain::SceneMain()
{
	//init();
	pBook->init();
	m_pBG = new OBJ2D;
	m_pBG->m_pSprData = &e_sprMainBG;
	//m_bg.m_pos = { SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2,0 };
	for (int i = STAGE_SELECT_MAX_NUM; i < STAGE_MAX_NUM; i++) {
		if ((i - STAGE_SELECT_MAX_NUM) % 4 == 0) {
			m_stageClearFlag[i] = true;
		}
		else {
			m_stageClearFlag[i] = false;
		}
	}
	//m_stageClearFlag[STAGE_MAX_NUM - 1] = false;

	m_stageClearFlag[STAGE_MAX_NUM] = true;
	//pObjManager->init();
	//pPlayerManager->init();
	//pMapObjManager->init(0);

	//pGameUIManager->init();

}

void SceneMain::init()
{
	//MFAudioPlay(BGM_MAIN, true);
	/*MFAudioStop(BGM_MAIN);
	MFAudioPause(BGM_MAIN);
	MFAudioContinue(BGM_MAIN);*/
	Scene::init();
	m_selectionNO = PAUSED_SELECTION::TO_GAME;
	m_stageNO = 0;
	m_selectedStageNO = 0;
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
	if (pause()){
		return;
	}

	switch (m_step)
	{
	case STEP::INIT:
		//init();
		++m_timer;
		pBook->update();
		if (!pBook->m_pfMove && m_timer > 20)
		{
			pBook->clearAll();
			m_stageNO = 0;
			m_timer = 0;
			pStageManager->init(m_stageNO);
			pEffectManager->init();
			pGameUIManager->init();
			for (int i = STAGE_SELECT_MAX_NUM, real = 0; i < STAGE_MAX_NUM; ++i, real = i - STAGE_SELECT_MAX_NUM) {
				pGameUIManager->m_stageSecectionPagination[i] = e_startPagination[real / 16] + (real) / 8 % 2;
			}
			/*for (int i = STAGE_SELECT_MAX_NUM; i < STAGE_MAX_NUM; i++) {
				m_stageClearFlag[i] = false;
			}
			m_stageClearFlag[STAGE_MAX_NUM] = true;*/
			m_timer = 0;
			m_step = STEP::INIT + 1;
		}
		break;
	case STEP::INIT + 1:
		// Title Scene
		pGameUIManager->m_ppGameUI[STAGE_CLEARED]->m_isVisible = true;
		m_timer++;
		if (m_timer % 30 == 0)
		{
			Effect::searchSet(pEffectManager->m_ppEffect, EFF_OBJ_MAX_NUM, Vector3(0.0f, 0.0f, 0.0f), 1, effectCircleMove);
		}

		if (m_timer % 300 == 1)
		{/*
			Effect::searchSet(pEffectManager->m_ppEffect, EFF_OBJ_MAX_NUM, Vector3(0.0f, 0.0f, 0.0f), 1, effectBookAura)->m_custom3d.position
				= XMFLOAT3(pBook->m_coverWidth / 2, pBook->m_coverHeight / 2, 0.0f);*/
		}
		pBook->update();
		pStageManager->update();
		if (KEY_TRACKER.pressed.C || PAD_TRACKER.x == PAD_TRACKER.PRESSED)
		{
			if (!pBook->m_pfMove)
			{
				pBook->initStartPaper(START_PAGINATION / 2);
				pStageManager->init(m_stageNO);
				pBook->m_pfMove = &Book::turnPages;
				pBook->m_targetPaperNO = START_PAGINATION / 2;
				pBook->m_pfMove = &Book::startReading;
			}
		}
		if (pBook->m_isClosed)
		{
			pBook->initStartPaper(START_PAGINATION / 2);
			pStageManager->init(m_stageNO);
			pBook->darkenPapers(0);
		}
		if (pBook->m_isOpened)
		{
			m_timer = 0;
			if (m_stageNO >= STAGE_SELECT_MAX_NUM)
			{
				m_step = STEP::INIT + 4;	
			}
			else
			{
				pBook->darkenPapers(0);
				m_selectedStageNO = 0;
				pBook->m_pfMove = nullptr;
				pBook->m_step = STEP::FINISH;
				m_step = STEP::INIT + 2;
				break;
			}
		}
		if (!pBook->m_pfMove){
			pGameUIManager->showXButton();
		}
		pEffectManager->update();
		break;
	case STEP::INIT + 2:
		// Stage Select
		pGameUIManager->m_ppGameUI[STAGE_CLEARED]->m_isVisible = true;

		if (pBook->m_isOpened && pBook->m_step==STEP::FINISH)
		{
			pGameUIManager->showStageSelected(m_selectedStageNO);

			if (KEY_TRACKER.pressed.W || PAD_TRACKER.leftStickUp == PAD_TRACKER.PRESSED) {
				--m_selectedStageNO;
				if (m_selectedStageNO < (m_selectedStageNO + 1) / 6 * 6) {
					m_selectedStageNO = (m_selectedStageNO + 1) / 6 * 6 + 5;
				}
				/*f (m_selectedStageNO % 11 == 0 && m_stageNO > 0) {
					--m_stageNO;
					pStageManager->init(m_stageNO); 
					pBook->m_pfMove = &Book::turnPages;
					pBook->m_targetPaperNO = START_PAGINATION / 2;
					pBook->initStartPaper(START_PAGINATION / 2);
					m_timer = 0;
					break;
				}*/
			}
			if (KEY_TRACKER.pressed.S || PAD_TRACKER.leftStickDown == PAD_TRACKER.PRESSED) {
				++m_selectedStageNO;
				if (m_selectedStageNO > (m_selectedStageNO - 1) / 6 * 6 + 5) {
					//m_selectedStageNO = STAGE_MAX_NUM - STAGE_SELECT_MAX_NUM - 1;
					m_selectedStageNO = (m_selectedStageNO - 1) / 6 * 6;
					/*m_selectedStageNO = STAGE_SELECT_MAX_NUM;
					m_timer = 0;
					pStageManager->init(m_selectedStageNO);
					pBook->m_pfMove = &Book::turnPages;
					pBook->m_targetPaperNO = START_PAGINATION / 2;
					m_step = STEP::INIT + 3;
					break;*/
				}
				/*if (m_selectedStageNO != 0 && m_selectedStageNO % 12 == 0 && m_stageNO < STAGE_SELECT_MAX_NUM) {
					++m_stageNO;
					pStageManager->init(m_stageNO);
					pBook->m_pfMove = &Book::turnPages;
					pBook->m_targetPaperNO = START_PAGINATION / 2;
					pBook->initStartPaper(START_PAGINATION / 2);
					m_timer = 0;
					break;
				}*/
			}
			if (KEY_TRACKER.pressed.A || PAD_TRACKER.leftStickLeft == PAD_TRACKER.PRESSED) {
				if (m_selectedStageNO < 12) {
					m_selectedStageNO += 6;
					m_selectedStageNO %= 12; 
				}
			}
			if (KEY_TRACKER.pressed.D || PAD_TRACKER.leftStickRight == PAD_TRACKER.PRESSED) {
				if (m_selectedStageNO < 12){
					m_selectedStageNO += 6;
					m_selectedStageNO %= 12;
				}

			}


			if ((KEY_TRACKER.pressed.C || PAD_TRACKER.x == PAD_TRACKER.PRESSED) && pBook->m_step == STEP::FINISH)
			{
				m_selectedStageNO = (pBook->m_currentPaperNO - 1) * 12 + m_selectedStageNO % 12;
				m_stageNO = m_selectedStageNO + (m_selectedStageNO / 3 + 1) + STAGE_SELECT_MAX_NUM;

				if (m_selectedStageNO % 3 == 0) {
					--m_stageNO;
					m_step = STEP::INIT + 3;
				}
				else {
					m_step = STEP::INIT + 4;
				}
				m_timer = 0;
				pStageManager->init(m_stageNO);
				pBook->m_pfMove = &Book::turnPages;
				if (m_stageNO > 5) {
					pBook->m_pfMove = &Book::closeBook;
				}
				pBook->m_targetPaperNO = START_PAGINATION / 2;
				pBook->initStartPaper(START_PAGINATION / 2);

				break;
			}

		}
		else{
			m_selectedStageNO = m_selectedStageNO / 12 * 12;
			pGameUIManager->showStageSelected(m_selectedStageNO, true);
		}

		// 強制正規化
		if (m_selectedStageNO > STAGE_MAX_NUM-1 - STAGE_SELECT_MAX_NUM - 1 - (STAGE_MAX_NUM - STAGE_SELECT_MAX_NUM) / 4) {
			m_selectedStageNO = STAGE_MAX_NUM - 1 - STAGE_SELECT_MAX_NUM - 1 - (STAGE_MAX_NUM - STAGE_SELECT_MAX_NUM) / 4;
		}
		m_selectedStageNO = (pBook->m_currentPaperNO - 1) * 12 + m_selectedStageNO % 12;
		turnPagesController();

		pBook->update();
		pStageManager->update();
		pEffectManager->update();

		break;
	case STEP::INIT + 3:
		//Stage 00
		m_timer++;
		if (m_timer > 120)
		{
			pGameUIManager->showXButton();
		}
		if ((KEY_TRACKER.pressed.C || PAD_TRACKER.x == PAD_TRACKER.PRESSED || m_timer > 240) && pBook->m_step == STEP::FINISH)
		{
			m_stageNO++;
			pStageManager->init(m_stageNO);
			pBook->m_pfMove = &Book::turnPages;
			pBook->m_targetPaperNO = START_PAGINATION / 2;
			pBook->initStartPaper(START_PAGINATION / 2);
			m_timer = 0;
			m_step = STEP::INIT + 4;

			break;
		}
		pBook->update();
		pStageManager->update();
		pEffectManager->update();
		turnPagesController();
		//m_step = STEP::INIT + 4;
		break;
	case STEP::INIT + 4:
		// Stage 01~??
		m_timer = 0;
		pBook->update();
		pStageManager->update();
		pEffectManager->update();
		if (pBook->m_step == STEP::FINISH)
		{
			pGameUIManager->init();
			//pEffectManager->init();
			pPlayerManager->init();
			pGameUIManager->m_ppGameUI[STAGE_CLEARED]->m_isVisible = false;
			m_step = STEP::BEGIN;
		}
		break;
	case STEP::BEGIN:

		gameMain();

#ifdef  DEBUG
		turnPagesController();
#endif //  DEBUG


		break;
	case STEP::BEGIN + 1:

		viewMode();

		break;
	case STEP::BEGIN+2:

		endViewMode();

		break;
	case STEP::END:
		m_timer++;
		if (m_timer > 30)
		{
			//pGameUIManager->showXButton();
			pGameUIManager->m_ppGameUI[GAME_OVER_BEHIND]->m_isVisible = true;
			pGameUIManager->m_ppGameUI[GAME_OVER_FRONT]->m_isVisible = true;

			pGameUIManager->showRetryPanel(m_selectionNO);
			if (KEY_TRACKER.pressed.S || PAD_TRACKER.leftStickUp == PAD_TRACKER.PRESSED)
			{
				m_selectionNO++;
			}
			if (KEY_TRACKER.pressed.W || PAD_TRACKER.leftStickDown == PAD_TRACKER.PRESSED)
			{
				m_selectionNO--;
			}
			m_selectionNO = abs(m_selectionNO) % (int)RETRY_SELECTION::MAX_RETRY_SELECTION_NUM;
			if (KEY_TRACKER.released.C || PAD_TRACKER.x == PAD_TRACKER.RELEASED)
			{
				if (m_selectionNO == RETRY_SELECTION::TO_RETRY) {

					m_timer = 0;
					pStageManager->init(m_stageNO);
					//pBook-
					pBook->m_pfMove = &Book::closeBook;
					m_step = STEP::INIT + 1;
				}
				if (m_selectionNO == RETRY_SELECTION::TO_TITLE_RETRY) {

					m_stageNO = 0;
					pStageManager->init(m_stageNO);
					pBook->m_pfMove = &Book::finishReading;
					m_selectionNO = RETRY_SELECTION::TO_RETRY;
					m_step = STEP::INIT + 1;
				}
			}

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
	//pEffectManager->draw();
	if (m_step >= STEP::BEGIN || m_step == STEP::INIT + 1) {
		//pEffectManager->draw();
	}
	pEffectManager->draw();
	pGameUIManager->draw();


#ifdef  DEBUG
	char buf[256];
	sprintf_s(buf, "STAGE %d \nStageNO: %d \nm_step %d \nm_selectedStageNO %d", m_stageNO - STAGE_SELECT_MAX_NUM, m_stageNO, m_step, m_selectedStageNO);
	drawString(SCREEN_WIDTH / 2, 400, buf, COLOR_WHITE >> 8 << 8 | 0xA0, STR_CENTER, 40, 40);

#endif //  DEBUG

	if (m_step == STEP::INIT) {
		drawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0x000000FF & (unsigned int)((20 - m_timer) / 20.0f * 255));
	}

}

bool SceneMain::pause()
{
	if ((KEY_TRACKER.pressed.Space || PAD_TRACKER.menu == PAD_TRACKER.PRESSED) && m_step > STEP::INIT && m_step != STEP::END && pBook->m_isOpened) {
		m_isPaused = true;
	}

	if (m_isPaused)
	{
		pGameUIManager->showPausePanel(m_selectionNO);
		if (KEY_TRACKER.pressed.S || PAD_TRACKER.leftStickUp == PAD_TRACKER.PRESSED)
		{
			m_selectionNO++;
		}
		if (KEY_TRACKER.pressed.W || PAD_TRACKER.leftStickDown == PAD_TRACKER.PRESSED)
		{
			m_selectionNO--;
		}
		m_selectionNO = abs(m_selectionNO) % (int)PAUSED_SELECTION::MAX_PAUSED_SELECTION_NUM;
		if (KEY_TRACKER.released.C || PAD_TRACKER.x == PAD_TRACKER.RELEASED)
		{
			if (m_selectionNO == PAUSED_SELECTION::TO_GAME){
				m_isPaused = false;
			}
			if (m_selectionNO == PAUSED_SELECTION::TO_TITLE_PAUSE){
				m_isPaused = false;

				/*for (int i = STAGE_SELECT_MAX_NUM; i < STAGE_MAX_NUM; i++) {
					m_stageClearFlag[i] = false;
				}
				m_stageClearFlag[STAGE_MAX_NUM] = true;*/

				m_stageNO = 0;
				pStageManager->init(m_stageNO);
				pBook->m_pfMove = &Book::finishReading;
				m_selectionNO = PAUSED_SELECTION::TO_GAME;
				m_step = STEP::INIT + 1;
			}
		}
	}
	return m_isPaused;
}

void SceneMain::gameMain()
{

	pBook->update();

	if (pBook->m_isOpened)
	{
		pPlayerManager->update();
		pGameUIManager->showPlayerConcentration(pPlayerManager->m_pPlayer->m_concentration, pPlayerManager->m_pPlayer->getLife(), pPlayerManager->m_pPlayer->m_isDamaged);
		if (pPlayerManager->m_pPlayer->m_isOnScrollArea)
		{
			pBook->setScroll(pPlayerManager->m_pPlayer->m_speed, pPlayerManager->m_pPlayer->m_liveInPagination, pPlayerManager->m_pPlayer->m_mode == P_MODE::RESTART);
			pEffectManager->setScroll(pPlayerManager->m_pPlayer->m_speed, pPlayerManager->m_pPlayer->m_liveInPagination, pPlayerManager->m_pPlayer->m_mode == P_MODE::RESTART);
			pPlayerManager->m_pPlayer->setScrollKeys(pPlayerManager->m_pPlayer->m_speed);
		}

		if (KEY_TRACKER.pressed.E || PAD_TRACKER.rightShoulder == PAD_TRACKER.PRESSED)
		{// To Scroll View Mode
			m_step = STEP::BEGIN + 1;
			m_timer = 0;
			pPlayerManager->m_pPlayer->m_setPos.y = pPlayerManager->m_pPlayer->m_pos.y;
			return;
		}
	}

	pStageManager->update();
	pEffectManager->update();

	pGameUIManager->update();
	judgeAll();

	if (pPlayerManager->m_pPlayer->m_mode == P_MODE::CLEAR)
	{
		m_timer++;
		m_stageClearFlag[m_stageNO] = true;

		// ステージクリア情報をUIManagerに渡す
		if (!m_stageClearFlag[STAGE_MAX_NUM + 1]) {
			memcpy(pGameUIManager->m_stageClearFlag, m_stageClearFlag, STAGE_LIMITTED_NUM);
		}

		m_stageClearFlag[STAGE_MAX_NUM] = true;
		for (int i = STAGE_SELECT_MAX_NUM; i < STAGE_MAX_NUM; i++) {
			m_stageClearFlag[STAGE_MAX_NUM] &= m_stageClearFlag[i];
		}

		if (m_timer > 40) {

			if (m_stageClearFlag[STAGE_MAX_NUM] == true) {
				pGameUIManager->m_ppGameUI[GAME_CLEAR_TEXT]->m_isVisible = true;
				if (m_timer % 5 == 0)
				{
					Effect::searchSet(pEffectManager->m_ppEffect, EFF_OBJ_MAX_NUM, Vector3(-PAGE_WIDTH / 4, 0.0f, 0.0f), 1, effectCircleMove, 1);
				}
			}
			else {
				pGameUIManager->m_ppGameUI[STAGE_CLEAR_BEHIND]->m_isVisible = true;
				pGameUIManager->m_ppGameUI[STAGE_CLEAR_BEHIND]->m_custom.scaleX = pGameUIManager->m_ppGameUI[STAGE_CLEAR_BEHIND]->m_custom.scaleY -= 0.04;

				if (pGameUIManager->m_ppGameUI[STAGE_CLEAR_BEHIND]->m_custom.scaleX < 1.0f)
				{
					pGameUIManager->m_ppGameUI[STAGE_CLEAR_BEHIND]->m_custom.scaleX = pGameUIManager->m_ppGameUI[STAGE_CLEAR_BEHIND]->m_custom.scaleY = 1.0;
					if (m_timer > 80) {
						pGameUIManager->m_ppGameUI[STAGE_CLEAR_FRONT]->m_isVisible = true;
						pGameUIManager->m_ppGameUI[STAGE_CLEAR_FRONT]->m_custom.scaleX = pGameUIManager->m_ppGameUI[STAGE_CLEAR_FRONT]->m_custom.scaleY -= 0.04;
						if (pGameUIManager->m_ppGameUI[STAGE_CLEAR_FRONT]->m_custom.scaleX < 1.0f) {
							pGameUIManager->m_ppGameUI[STAGE_CLEAR_FRONT]->m_custom.scaleX = pGameUIManager->m_ppGameUI[STAGE_CLEAR_FRONT]->m_custom.scaleY = 1.0;
						}
					}

				}

				//pGameUIManager->m_ppGameUI[STAGE_CLEAR_TEXT]->m_isVisible = true;
			}
			if (m_timer > 120)
			{
				pGameUIManager->showXButton();
				if ((KEY_TRACKER.pressed.C || PAD_TRACKER.x == PAD_TRACKER.PRESSED) || (m_timer > 360 && !m_stageClearFlag[STAGE_MAX_NUM]))
				{
					m_stageNO++;
					if (m_stageNO >= STAGE_MAX_NUM)
					{
						m_stageNO = /*STAGE_SELECT_MAX_NUM*/0;
					}
					if (m_stageClearFlag[STAGE_MAX_NUM] == true) {
						for (int i = 1; i < STAGE_MAX_NUM; i++) {
							m_stageClearFlag[i] = false;
						}
						m_stageClearFlag[STAGE_MAX_NUM + 1] = true;
						/*m_selectedStageNO = 0;
						pStageManager->init(m_selectedStageNO);
						pBook->m_pfMove = &Book::turnPages;
						pBook->m_targetPaperNO = START_PAGINATION / 2;
						m_step = STEP::INIT + 2;*/
						m_stageNO = 0;
						pStageManager->init(m_stageNO);
						pBook->m_pfMove = &Book::finishReading;
						m_step = STEP::INIT + 1;
					}
					else
					{
						/*if (m_stageClearFlag[m_selectedStageNO]) {
						for (int i = STAGE_SELECT_MAX_NUM; i < STAGE_MAX_NUM; i++) {
						if (!m_stageClearFlag[i]) {
						m_selectedStageNO = i;
						break;
						}
						}
						}*/
						pStageManager->init(m_stageNO);
						pBook->m_pfMove = &Book::turnPages;
						pBook->m_targetPaperNO = START_PAGINATION / 2;
						pBook->initStartPaper(START_PAGINATION / 2);
						if (m_stageNO == 0) {
							m_step = STEP::INIT + 1;
						}
						else if ((m_stageNO - STAGE_SELECT_MAX_NUM) % 4 == 0) {
							m_step = STEP::INIT + 3;
						}
						else {
							m_step = STEP::INIT + 4;
						}
					}
					m_timer = 0;
				}
			}
		}
	}


	if (pPlayerManager->m_pPlayer->m_mode == P_MODE::DEAD)
	{
		m_timer = 0;
		pBook->darkenPapers(120);
		m_step = STEP::END;

	}
}

void SceneMain::turnPagesController()
{

	if ((KEY_TRACKER.pressed.PageUp || PAD_TRACKER.back == PAD_TRACKER.PRESSED || PAD_TRACKER.leftTrigger == PAD_TRACKER.PRESSED) && pBook->m_step > STEP::END && pBook->m_isOpened)
	{
		--m_stageNO;
		if (m_stageNO < 0) {
			m_stageNO = 0;
			return;
		}
		if (m_stageNO < STAGE_SELECT_MAX_NUM) {
			m_step = STEP::INIT + 2;
		}
		//if (m_selectedStageNO == STAGE_SELECT_MAX_NUM) {
		//	m_step = STEP::INIT + 3;
		//}
		if (m_stageNO >= STAGE_SELECT_MAX_NUM) {
			if ((m_stageNO - STAGE_SELECT_MAX_NUM) % 4 == 0) {
				m_step = STEP::INIT + 3;
			}
			else {
				m_step = STEP::INIT + 4;
			}
		}
		m_timer = 0;
		pStageManager->init(m_stageNO);
		pBook->m_pfMove = &Book::turnPages;
		pBook->m_targetPaperNO = START_PAGINATION / 2;
		pBook->initStartPaper(START_PAGINATION / 2);
		return;

	}
	else if ((KEY_TRACKER.pressed.PageDown || PAD_TRACKER.rightTrigger == PAD_TRACKER.PRESSED) && pBook->m_step > STEP::END && pBook->m_isOpened)
	{
		++m_stageNO;
		if (m_stageNO >= STAGE_MAX_NUM) {
			m_stageNO = STAGE_SELECT_MAX_NUM;
		}
		//if (m_selectedStageNO == STAGE_SELECT_MAX_NUM) {
		//	m_step = STEP::INIT + 3;
		//}
		if (m_stageNO >= STAGE_SELECT_MAX_NUM) {
			if ((m_stageNO - STAGE_SELECT_MAX_NUM) % 4 == 0) {
				m_step = STEP::INIT + 3;
			}
			else {
				m_step = STEP::INIT + 4;
			}
		}
		pStageManager->init(m_stageNO);
		pBook->m_pfMove = &Book::turnPages;
		pBook->m_targetPaperNO = START_PAGINATION / 2;
		pBook->initStartPaper(START_PAGINATION / 2);
		m_timer = 0;
		return;

	}
}

void SceneMain::viewMode()
{
	m_timer++;
	if (m_timer > 20)
	{
		if (KEY_BOARD.W || GAME_PAD.IsLeftThumbStickUp())
		{
			pBook->setScroll(Vector3(0, -10, 0), pPlayerManager->m_pPlayer->m_liveInPagination, true);
			pEffectManager->setScroll(Vector3(0, -10, 0), pPlayerManager->m_pPlayer->m_liveInPagination, true);
			pPlayerManager->m_pPlayer->m_pos.y += 10;
			if (pPlayerManager->m_pPlayer->m_isKeyHandled) {
				pPlayerManager->m_pPlayer->m_pKeyObj[pPlayerManager->m_pPlayer->m_keyCounter - 1].m_pos.y += 10;
			}
			pPlayerManager->m_pPlayer->setScrollKeys(Vector3(0, -10, 0));
			if (pPlayerManager->m_pPlayer->m_pos.y > pPlayerManager->m_pPlayer->m_setPos.y + pPlayerManager->m_pPlayer->m_scrolledDistance.y)
			{
				pPlayerManager->m_pPlayer->m_pos.y = pPlayerManager->m_pPlayer->m_setPos.y + pPlayerManager->m_pPlayer->m_scrolledDistance.y;
				if (pPlayerManager->m_pPlayer->m_isKeyHandled) {
					pPlayerManager->m_pPlayer->m_pKeyObj[pPlayerManager->m_pPlayer->m_keyCounter - 1].m_pos.y = pPlayerManager->m_pPlayer->m_pos.y - pPlayerManager->m_pPlayer->m_pKeyObj[pPlayerManager->m_pPlayer->m_keyCounter - 1].m_pSprData->height;
				}
			}
		}
		if (KEY_BOARD.S || GAME_PAD.IsLeftThumbStickDown())
		{
			pBook->setScroll(Vector3(0, 10, 0), pPlayerManager->m_pPlayer->m_liveInPagination, true);
			pEffectManager->setScroll(Vector3(0, 10, 0), pPlayerManager->m_pPlayer->m_liveInPagination, true);
			pPlayerManager->m_pPlayer->m_pos.y -= 10;
			if (pPlayerManager->m_pPlayer->m_isKeyHandled){
				pPlayerManager->m_pPlayer->m_pKeyObj[pPlayerManager->m_pPlayer->m_keyCounter - 1].m_pos.y -= 10;
			}
			pPlayerManager->m_pPlayer->setScrollKeys(Vector3(0, 10, 0));
			if (pPlayerManager->m_pPlayer->m_pos.y < pPlayerManager->m_pPlayer->m_setPos.y - STAGE_HEIGHT + pPlayerManager->m_pPlayer->m_scrolledDistance.y)
			{
				pPlayerManager->m_pPlayer->m_pos.y = pPlayerManager->m_pPlayer->m_setPos.y - STAGE_HEIGHT + pPlayerManager->m_pPlayer->m_scrolledDistance.y;
				if (pPlayerManager->m_pPlayer->m_isKeyHandled) {
					pPlayerManager->m_pPlayer->m_pKeyObj[pPlayerManager->m_pPlayer->m_keyCounter - 1].m_pos.y = pPlayerManager->m_pPlayer->m_pos.y - pPlayerManager->m_pPlayer->m_pKeyObj[pPlayerManager->m_pPlayer->m_keyCounter - 1].m_pSprData->height;
				}
			}
		}
	}
	pEffectManager->update();
	pGameUIManager->showScrollMode();
	pGameUIManager->update();
	pGameUIManager->showPlayerConcentration(pPlayerManager->m_pPlayer->m_concentration, pPlayerManager->m_pPlayer->getLife(), pPlayerManager->m_pPlayer->m_isDamaged);

	if (KEY_TRACKER.pressed.E || PAD_TRACKER.rightShoulder == PAD_TRACKER.PRESSED)
	{
		m_step = STEP::BEGIN + 2;
		m_timer = 0;
		return;
	}
}

void SceneMain::endViewMode()
{
	judgeAll();
	if (pPlayerManager->m_pPlayer->m_pos.y > pPlayerManager->m_pPlayer->m_setPos.y)
	{
		pBook->setScroll(Vector3(0, 30, 0), pPlayerManager->m_pPlayer->m_liveInPagination, true);
		pEffectManager->setScroll(Vector3(0, 30, 0), pPlayerManager->m_pPlayer->m_liveInPagination, true);
		pPlayerManager->m_pPlayer->m_pos.y -= 30;
		if (pPlayerManager->m_pPlayer->m_isKeyHandled) {
			pPlayerManager->m_pPlayer->m_pKeyObj[pPlayerManager->m_pPlayer->m_keyCounter - 1].m_pos.y -= 30;
		}
		pPlayerManager->m_pPlayer->setScrollKeys(Vector3(0, 30, 0));
		if (pPlayerManager->m_pPlayer->m_pos.y <= pPlayerManager->m_pPlayer->m_setPos.y)
		{
			pPlayerManager->m_pPlayer->m_pos.y = pPlayerManager->m_pPlayer->m_setPos.y;
			if (pPlayerManager->m_pPlayer->m_isKeyHandled) {
				pPlayerManager->m_pPlayer->m_pKeyObj[pPlayerManager->m_pPlayer->m_keyCounter - 1].m_pos.y = pPlayerManager->m_pPlayer->m_pos.y - pPlayerManager->m_pPlayer->m_pKeyObj[pPlayerManager->m_pPlayer->m_keyCounter - 1].m_pSprData->height;
			}
		}
	}
	if (pPlayerManager->m_pPlayer->m_pos.y < pPlayerManager->m_pPlayer->m_setPos.y)
	{
		pBook->setScroll(Vector3(0, -30, 0), pPlayerManager->m_pPlayer->m_liveInPagination, true);
		pEffectManager->setScroll(Vector3(0, -30, 0), pPlayerManager->m_pPlayer->m_liveInPagination, true);
		pPlayerManager->m_pPlayer->m_pos.y += 30;
		if (pPlayerManager->m_pPlayer->m_isKeyHandled) {
			pPlayerManager->m_pPlayer->m_pKeyObj[pPlayerManager->m_pPlayer->m_keyCounter - 1].m_pos.y += 30;
		}
		pPlayerManager->m_pPlayer->setScrollKeys(Vector3(0, -30, 0));
		if (pPlayerManager->m_pPlayer->m_pos.y >= pPlayerManager->m_pPlayer->m_setPos.y)
		{
			pPlayerManager->m_pPlayer->m_pos.y = pPlayerManager->m_pPlayer->m_setPos.y;
			if (pPlayerManager->m_pPlayer->m_isKeyHandled) {
				pPlayerManager->m_pPlayer->m_pKeyObj[pPlayerManager->m_pPlayer->m_keyCounter - 1].m_pos.y = pPlayerManager->m_pPlayer->m_pos.y - pPlayerManager->m_pPlayer->m_pKeyObj[pPlayerManager->m_pPlayer->m_keyCounter - 1].m_pSprData->height;
			}
		}
	}
	if (fabsf(pPlayerManager->m_pPlayer->m_pos.y - pPlayerManager->m_pPlayer->m_setPos.y) < FLT_EPSILON)
	{
		m_step = STEP::BEGIN;
		return;
	}
	pGameUIManager->showScrollMode();
	pGameUIManager->showPlayerConcentration(pPlayerManager->m_pPlayer->m_concentration, pPlayerManager->m_pPlayer->getLife(), pPlayerManager->m_pPlayer->m_isDamaged);

}