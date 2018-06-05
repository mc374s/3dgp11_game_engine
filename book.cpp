﻿#include "game.h"
#include "sprite_data.h"
#include "player.h"
#include "paper.h"
#include "sound_data.h"


#include "book.h"

Book::Book(int a_width, int a_height, int a_marginLeft, int a_marginTop, int a_marginRight, int a_marginBottom, int a_coverDepth) :
	m_width(a_width),
	m_height(a_height),
	m_marginLeft(a_marginLeft),
	m_marginTop(a_marginTop),
	m_marginRight(a_marginRight),
	m_marginBottom(a_marginBottom),
	m_coverDepth(a_coverDepth)
{

	m_coverWidth = a_width + a_marginLeft + a_marginRight;
	m_coverHeight = a_height + a_marginTop + a_marginBottom;
	/*m_pBookLeft = new Cube(XMFLOAT3(0, 0, 0), XMFLOAT3(a_width, a_height, a_bookDepth), 0xF0FFFFFF);
	m_pBookLeft->m_custom3d.position = XMFLOAT3(-a_width / 2, 0, a_bookDepth / 2);*/

	m_step = STEP::INIT;
	m_timer = 0;
	m_pfMove = nullptr;
	m_pfMoveOld = nullptr;
	m_isClosed = false;
	m_isOpened = false;
	m_openAngle = 0;


	m_ppPapers[COVER_FRONT] = new Paper(COVER_FRONT, m_coverWidth, m_coverHeight, m_coverDepth, 0xD65856FF);
	m_ppPapers[COVER_FRONT]->m_custom3d.position = m_ppPapers[COVER_FRONT]->m_initPos = { m_coverWidth / 2, 0, m_coverDepth / 2 };
	m_ppPapers[COVER_FRONT]->m_pBG->m_pSprData = &e_sprCoverFront;
	m_ppPapers[COVER_FRONT]->m_isActive = true;

	m_ppPapers[COVER_BACK] = new Paper(COVER_BACK, m_coverWidth, m_coverHeight, m_coverDepth, 0xD65856FF);
	m_ppPapers[COVER_BACK]->m_custom3d.position = m_ppPapers[COVER_BACK]->m_initPos = { m_coverWidth / 2, 0, m_coverDepth + PAPER_LAST*PAPER_DEPTH + m_coverDepth / 2 };
	m_ppPapers[COVER_BACK]->m_pBG->m_pSprData = &e_sprCoverBack;
	m_ppPapers[COVER_BACK]->m_isActive = true;

	for (int i = 0; i < PAPER_NO::MAX_PAPER_NO; i++)
	{
		if (!m_ppPapers[i])
		{
			m_ppPapers[i] = new Paper(i, m_width, m_height);
			m_ppPapers[i]->m_custom3d.position = m_ppPapers[i]->m_initPos = { m_width / 2, 0,m_coverDepth + i*PAPER_DEPTH };
		}
		//m_pPapers[i]->m_custom3d.position=XMFLOAT3()
	}
	m_bookDepth = PAPER_LAST*PAPER_DEPTH;

	init();

}

Book::~Book()
{
	for (auto &it : m_ppPapers)
	{
		SAFE_DELETE(it);
	}
}

void Book::init()
{
	m_initPos=m_position = { 0,0,0 };
	m_speed = { 0,0,0 };
	m_speedAcc = { 0,0,0 };
	m_speedMax = { 0,0,0 };
	
	m_angleYawPitchRoll = { 0,0,0, };
	m_angleChangeSpeed = { 0,0,0 };

	m_step = STEP::INIT;
	m_timer = 0;
	m_pfMove = nullptr;
	m_pfMoveOld = nullptr;
	m_isClosed = false;
	m_isOpened = false;
	m_openAngle = 0;
	m_position.z -= (m_coverDepth + 30 * PAPER_DEPTH);
	m_centerPaper = 0.5;
	m_currentPaperNO = 30;

	for (auto &it : m_ppPapers) {
		if (it)
		{
			it->m_custom3d.clear();
			it->m_custom3d.position = it->m_initPos;
			it->m_isActive = false;
		}
	}
	m_ppPapers[COVER_FRONT]->m_isActive = true;
	m_ppPapers[COVER_BACK]->m_isActive = true;





	m_position.y = m_coverHeight / 2;
	m_posLookedByCamera = { 0.0f, 0.0f, 200.0f };
	m_cameraAdjust = { m_coverWidth / 2, m_coverHeight / 2, -CAMERA_BEST_DISTANCE_PX };
	e_camera.focusPosition.vector4_f32[0] = -m_posLookedByCamera.x + m_cameraAdjust.x;
	e_camera.focusPosition.vector4_f32[1] = -m_posLookedByCamera.y + m_cameraAdjust.y;
	e_camera.eyePosition.vector4_f32[0] = e_camera.focusPosition.vector4_f32[0];
	e_camera.eyePosition.vector4_f32[1] = e_camera.focusPosition.vector4_f32[1];
	e_camera.eyePosition.vector4_f32[2] = -m_posLookedByCamera.z + m_cameraAdjust.z;

}

int g_keyCounter = 0;

void Book::update()
{
	//////////////////////////////////////////////////////////////
	// For Book update

	// TODO : 本を閉じ開く [C] キーが getInputKey() の中のPAD_TRG3と衝突、解決要請
	// 原因はKEY_BOARDがexternで更新していることと予測
	if (/*KEY_DOWN('C')*/ KEY_TRACKER.pressed.C || PAD_TRACKER.x == PAD_TRACKER.PRESSED/*KEY_TRACKER.IsKeyPressed(Keyboard::Keys::C)*/) {
		if (m_step == STEP::FINISH)
		{
			m_centerPaper = pPlayerManager->m_pPlayer->m_liveInPagination / 2 + (pPlayerManager->m_pPlayer->m_liveInPagination % 2 == 0 ? -0.5 : 0.5);
			if (m_isOpened)
			{
				m_pfMove = &Book::closeBook;
			}
			/*if (m_isClosed)
			{
				m_pfMove = &Book::openBook;
			}*/
		}
		g_keyCounter++;
	}
	if (KEY_TRACKER.released.C || PAD_TRACKER.x == PAD_TRACKER.RELEASED) {
		if (m_isClosed)
		{
			m_pfMove = &Book::openBook;
		}
	}


	if (m_pfMove)
	{
		(this->*m_pfMove)();
		if (m_pfMove == &Book::closeBook && m_step == STEP::FINISH)
		{
			m_pfMove = &Book::openBook;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	// For Pages update
	//m_speed.x = m_speed.y = m_speed.z = 0;
	/*if (frame==1)
	{
		m_speed.z = -m_bookDepth - 2 * m_coverDepth;
		frame++;
	}*/
	/*if (KEY_BOARD.Up){
		m_speed.y = 4;
	}
	if (KEY_BOARD.Down){
		m_speed.y = -4;
	}
	if (KEY_BOARD.Left){
		m_speed.x = -4;
	}
	if (KEY_BOARD.Right){
		m_speed.x = 4;
	}*/
	/*if (KEY_BOARD.PageUp){
		m_speed.z = 4;
	}
	if (KEY_BOARD.PageDown){
		m_speed.z = -4;
	}*/

	/*m_angleChangeSpeed.x = m_angleChangeSpeed.y = */m_angleChangeSpeed.z = 0;
	if (KEY_BOARD.T) {
		m_angleChangeSpeed.y = 1;
	}
	if (KEY_BOARD.G) {
		m_angleChangeSpeed.y = -1;
	}
	/*if (KEY_BOARD.F) {
		m_angleChangeSpeed.x = 1;
	}
	if (KEY_BOARD.H) {
		m_angleChangeSpeed.x = -1;
	}*/
	if (KEY_BOARD.R) {
		m_angleChangeSpeed.z = 1;
	}
	if (KEY_BOARD.Y) {
		m_angleChangeSpeed.z = -1;
	}


	if (KEY_TRACKER.pressed.D8){
		m_currentPaperNO++;
		if (m_currentPaperNO > PAPER_NO::MAX_PAPER_NO - 1)
		{
			m_currentPaperNO = PAPER_NO::MAX_PAPER_NO - 1;
		}
		m_position.z -= m_ppPapers[m_currentPaperNO]->m_depth;
	}
	if (KEY_TRACKER.pressed.D7){
		m_position.z += m_ppPapers[m_currentPaperNO]->m_depth;
		m_currentPaperNO--;
		if (m_currentPaperNO < 0)
		{
			m_currentPaperNO = 0;
		}
	}
	/*if (KEY_BOARD.Home){
		m_pfMove = &Book::startReading;
	}
	if (KEY_BOARD.End) {
		m_pfMove = &Book::finishReading;
	}*/
	//m_posLookedByCamera += m_speed;
	//m_angleYawPitchRoll.y += m_angleChangeSpeed.y;
	//m_angleYawPitchRoll.z += m_angleChangeSpeed.z;
	for (auto &it : m_ppPapers)
	{
		if (it)
		{
			// 本とページの位置を同調かねて座標系の違いによる修正
			it->m_custom3d.angleYawPitchRoll.x += m_angleChangeSpeed.x;
			it->m_custom3d.angleYawPitchRoll.y = m_angleYawPitchRoll.y;
			it->m_custom3d.angleYawPitchRoll.z = m_angleYawPitchRoll.z;
			it->m_custom3d.position = m_position;

			//Always Need to Update Page View's m_custom3d
			it->syncViewCustom3d();
			if (m_isOpened)
			{
				it->update();
			}
		}
	}

	// Move camera As moved Book is self
	e_camera.focusPosition.vector4_f32[0] = -m_posLookedByCamera.x + m_cameraAdjust.x;
	e_camera.focusPosition.vector4_f32[1] = -m_posLookedByCamera.y + m_cameraAdjust.y;
	e_camera.eyePosition.vector4_f32[0] = e_camera.focusPosition.vector4_f32[0];
	e_camera.eyePosition.vector4_f32[1] = e_camera.focusPosition.vector4_f32[1];
	e_camera.eyePosition.vector4_f32[2] = -m_posLookedByCamera.z + m_cameraAdjust.z;
	//e_camera.upDirection = { 0, 1, 0, 0 };
	e_camera.toNDC();

}

void Book::draw()
{
	for (auto &it : m_ppPapers)
	{
		if (it)
		{
			it->draw();
		}
	}

#ifdef DEBUG

	char buf[256];
	sprintf_s(buf, "Key Counter: %d \nm_posLookedByCameraY: %.1lf px \nm_posLookedByCameraZ: %.1lf px", g_keyCounter, m_posLookedByCamera.y, m_posLookedByCamera.z);
	drawString(0, 460, buf, 0x000000FF, STR_LEFT, 18, 18);
	if (KEY_DOWN('0'))
	{
		g_keyCounter = 0;
	}

#endif // DEBUG



}

// Book move function
void Book::closeBook()
{
	if (m_pfMoveOld != &Book::closeBook)
	{
		m_pfMoveOld = m_pfMove;
		m_step = STEP::INIT;
	}
	switch (m_step)
	{
	case STEP::INIT:
		m_timer = 0;
		m_openSpeed = 0;
		m_openSpeedAcc = 0;
		//m_angleChangeSpeed.y = -45.0f * m_openSpeed / 90.0f;
		m_isClosed = false;
		m_isOpened = false;
		m_centerPaper = pPlayerManager->m_pPlayer->m_liveInPagination / 2 + (pPlayerManager->m_pPlayer->m_liveInPagination % 2 == 0 ? -0.5 : 0.5);
		for (auto &it : m_ppPapers)
		{
			if (it && it->m_paperNO > m_centerPaper - 1 && it->m_paperNO < m_centerPaper + 1)
			{
				it->m_isActive = true;
			}
			else
			{
				it->m_isActive = false;
			}
		}
		m_openAngle = 180;
		m_step = STEP::BEGIN;
		break;
	case STEP::BEGIN:
		m_openSpeedAcc += 0.018;
		m_openSpeed += m_openSpeedAcc;
		m_openAngle -= m_openSpeed * 2;
		/*m_position.z += m_openSpeed * 5.0f;
		m_position.y += m_openSpeed * 3.0f;*/
		m_angleChangeSpeed.y = 45.0f * m_openSpeed / 90.0f;
		m_angleYawPitchRoll.y += m_angleChangeSpeed.y;
		if (m_angleYawPitchRoll.y > 45.0f) {
			m_angleYawPitchRoll.y = 45.0f;
			m_angleChangeSpeed.y = 0;
		}

		m_speed.y = -100.0f * m_openSpeed / 90.0f;
		m_posLookedByCamera.y += m_speed.y;
		if (m_posLookedByCamera.y < -100.0f) {
			m_posLookedByCamera.y = -100.0f;
			m_speed.y = 0.0f;
		}
		m_speed.z = 450.0f * m_openSpeed / 90.0f;
		m_posLookedByCamera.z += m_speed.z;
		if (m_posLookedByCamera.z > 450.0f) {
			m_posLookedByCamera.z = 450.0f;
			m_speed.z = 0.0f;
		}
		for (auto &it : m_ppPapers)
		{
			if (it->m_paperNO < m_centerPaper)
			{
				it->m_custom3d.angleYawPitchRoll.x -= m_openSpeed;
				if (it->m_custom3d.angleYawPitchRoll.x < 90)
				{
					it->m_custom3d.angleYawPitchRoll.x = 90;
				}
			}
			else
			{
				it->m_custom3d.angleYawPitchRoll.x += m_openSpeed;
				if (it->m_custom3d.angleYawPitchRoll.x > 90)
				{
					it->m_custom3d.angleYawPitchRoll.x = 90;
				}
			}
		}

		if (m_openAngle < 0) {
			m_isClosed = true;
			m_openAngle = 0;
			/*m_position.z = 450;
			m_position.y = 270;*/
			m_step = STEP::END;
			MFAudioPlay(SE_CLOSE);
		}
		break;
	case STEP::END:
		m_timer++;
		if (m_timer > 40)
		{
			m_timer = 0;
			m_step = STEP::FINISH;
		}
		/*m_openAngle = -90;
		m_cameraAngleZY = -0.90f;
		m_position.z = 450;
		m_position.y = 270;*/
		break;
	case STEP::FINISH:
		break;
	default:
		break;
	}
}

void Book::openBook()
{
	if (m_pfMoveOld != &Book::openBook)
	{
		m_pfMoveOld = m_pfMove;
		m_step = STEP::INIT;
	}
	switch (m_step)
	{
	case STEP::INIT:
		m_timer = 0;
		if (m_isClosed)
		{
			pPlayerManager->transcriptPlayer();
			pPlayerManager->m_step = STEP::INIT;
		}
		m_centerPaper = pPlayerManager->m_pPlayer->m_liveInPagination / 2 + (pPlayerManager->m_pPlayer->m_liveInPagination % 2 == 0 ? -0.5 : 0.5);
		for (auto &it : m_ppPapers)
		{
			if (it && it->m_paperNO > m_centerPaper - 1 && it->m_paperNO < m_centerPaper + 1)
			{
				it->m_isActive = true;
			}
			else
			{
				it->m_isActive = false;
			}
		}
		m_isClosed = false;
		m_isOpened = false;
		m_openAngle = 0;
		m_openSpeed = 4;
		m_speed.y = 100.0f * m_openSpeed / 90.0f;
		m_speed.z = -440.0f * m_openSpeed / 90.0f;
		m_angleChangeSpeed.y = -45.0f * m_openSpeed / 90.0f;
		
		m_step = STEP::BEGIN;
		MFAudioPlay(SE_OPEN);
		break;
	case STEP::BEGIN:
		m_isClosed = false;
		m_openAngle += m_openSpeed * 2;
		m_angleYawPitchRoll.y += m_angleChangeSpeed.y;
		if (m_angleYawPitchRoll.y < 0.0f) {
			m_angleYawPitchRoll.y = 0.0f;
			m_angleChangeSpeed.y = 0; 
		}

		m_posLookedByCamera.y += m_speed.y;
		if (m_posLookedByCamera.y > 0.0f) {
			m_posLookedByCamera.y = 0.0f;
			m_speed.y = 0.0f;
		}
		m_posLookedByCamera.z += m_speed.z;
		if (m_posLookedByCamera.z < 0.0f) {
			m_posLookedByCamera.z = 0.0f;
			m_speed.z = 0.0f;

			m_step = STEP::END;
		}
		
		for (auto &it : m_ppPapers)
		{
			if (it->m_paperNO < m_centerPaper)
			{
				it->m_custom3d.angleYawPitchRoll.x += m_openSpeed;
				if (it->m_custom3d.angleYawPitchRoll.x > 180)
				{
					it->m_custom3d.angleYawPitchRoll.x = 180;
				}
			}
			else
			{
				it->m_custom3d.angleYawPitchRoll.x -= m_openSpeed;
				if (it->m_custom3d.angleYawPitchRoll.x < 0)
				{
					it->m_custom3d.angleYawPitchRoll.x = 0;
				}
			}
		}
		if (m_openAngle > 180) {
			m_isOpened = true;
			m_openAngle = 180;
			/*m_position.z = 0;
			m_position.y = 0;*/
			//m_step = STEP::END;
		}
		break;
	case STEP::END:
		/*m_openAngle = 0;
		m_cameraAngleZY = 0.0f;
		m_position.z = 0;
		m_position.y = 0;*/
		m_step = STEP::FINISH;
		break;
	case STEP::FINISH:

		break;
	default:
		break;
	}
}

void Book::startReading()
{
	if (m_pfMoveOld != &Book::startReading)
	{
		m_pfMoveOld = m_pfMove;
		m_step = STEP::INIT;
	}
	switch (m_step)
	{
	case STEP::INIT:
		m_speed.x = 6.4f;
		m_angleChangeSpeed.x = 90.0f * m_speed.x * 2 / m_coverWidth;
		m_openSpeedAcc = m_openSpeed = 0;

		m_step = STEP::BEGIN;
		m_ppPapers[COVER_FRONT]->m_isActive = true;
		m_ppPapers[COVER_BACK]->m_isActive = true;
		break;
	case STEP::BEGIN:
		m_angleYawPitchRoll.x += m_angleChangeSpeed.x;
		m_posLookedByCamera.x += m_speed.x;
		
		if (m_posLookedByCamera.x > m_coverWidth / 2) {
			m_posLookedByCamera.x = m_coverWidth / 2;
			m_speed.x = 0;
			for (auto &it : m_ppPapers) {
				it->m_custom3d.angleYawPitchRoll.x = 90;
			}
			m_angleChangeSpeed.x = 0;
			m_step = STEP::END;
		}

		m_openSpeedAcc += 0.01;
		m_openSpeed += m_openSpeedAcc;
		m_angleChangeSpeed.y = 45.0f * m_openSpeed / 90.0f;
		m_angleYawPitchRoll.y += m_angleChangeSpeed.y;
		if (m_angleYawPitchRoll.y > 45.0f) {
			m_angleYawPitchRoll.y = 45.0f;
			m_angleChangeSpeed.y = 0;
		}

		/*m_speed.y = -200.0f * m_openSpeed / 90.0f;
		m_posLookedByCamera.y += m_speed.y;
		if (m_posLookedByCamera.y < -200.0f) {
			m_posLookedByCamera.y = -200.0f;
			m_speed.y = 0.0f;
		}*/
		m_speed.z = 450.0f * m_openSpeed / 90.0f;
		m_posLookedByCamera.z += m_speed.z;
		if (m_posLookedByCamera.z > 450.0f) {
			m_posLookedByCamera.z = 450.0f;
			m_speed.z = 0.0f;
		}

		m_ppPapers[COVER_FRONT]->m_isActive = true;
		m_ppPapers[COVER_BACK]->m_isActive = true;



		break;
	case STEP::END:

		m_isClosed = false;
		m_isOpened = false;
		m_ppPapers[COVER_FRONT]->m_isActive = false;
		m_ppPapers[COVER_BACK]->m_isActive = false;
		m_pfMove = &Book::openBook;

		break;
	case STEP::FINISH:

		break;
	default:
		break;
	}
}

void Book::finishReading()
{
	static int step = STEP::INIT;
	if (m_pfMoveOld != &Book::finishReading && m_pfMoveOld != &Book::closeBook)
	{
		m_pfMoveOld = m_pfMove;
		step = STEP::INIT;
	}
	switch (step)
	{
	case STEP::INIT:
		closeBook();
		m_pfMoveOld = &Book::closeBook;
		if (m_step == STEP::END)
		{
			step = STEP::INIT + 1;
		}
		break;
	case STEP::INIT+1:
		m_isClosed = false;
		m_isOpened = false;
		m_speed.x = -6.4f;
		m_speed.y = -100.0f * m_speed.x * 2 / m_coverWidth;
		m_speed.z = 200.0f * m_speed.x * 2 / m_coverWidth;
		m_angleChangeSpeed.x = 90.0f * m_speed.x * 2 / m_coverWidth;
		m_angleChangeSpeed.y = 45.0f * m_speed.x * 2 / m_coverWidth;

		for (auto &it : m_ppPapers){
			it->m_isActive = false;
		}
		m_ppPapers[COVER_FRONT]->m_isActive = true;
		m_ppPapers[COVER_BACK]->m_isActive = true;

		step = STEP::BEGIN;
		break;
	case STEP::BEGIN:

		m_ppPapers[COVER_FRONT]->m_isActive = true;
		m_ppPapers[COVER_BACK]->m_isActive = true;

		m_angleYawPitchRoll.x += m_angleChangeSpeed.x;
		m_angleYawPitchRoll.y += m_angleChangeSpeed.y;
		if (m_angleYawPitchRoll.y < 0.0f) {
			m_angleYawPitchRoll.y = 0.0f;
			m_angleChangeSpeed.y = 0;
		}

		m_posLookedByCamera.x += m_speed.x;
		if (m_posLookedByCamera.x < 0) {
			m_posLookedByCamera.x = 0;
			m_speed.x = 0;
			for (auto &it : m_ppPapers) {
				it->m_custom3d.angleYawPitchRoll.x = 0;
			}
			m_angleChangeSpeed.x = 0;
			step = STEP::END;
		}

		m_posLookedByCamera.y += m_speed.y;
		if (m_posLookedByCamera.y > 0.0f) {
			m_posLookedByCamera.y = 0.0f;
			m_speed.y = 0.0f;
		}

		m_posLookedByCamera.z += m_speed.z;
		if (m_posLookedByCamera.z < 200.0f) {
			m_posLookedByCamera.z = 200.0f;
			m_speed.z = 0.0f;
		}

		break;
	case STEP::END:

		m_isClosed = false;
		m_isOpened = false;
		m_pfMove = nullptr;
		m_pfMoveOld = nullptr;
		m_ppPapers[COVER_FRONT]->m_isActive = true;
		m_ppPapers[COVER_BACK]->m_isActive = true;
		step = STEP::FINISH;
		break;
	case STEP::FINISH:

		break;
	default:
		break;
	}
}


void Book::turnPages()
{
	switch (m_step)
	{
	case STEP::INIT:

		for (auto &it : m_ppPapers)
		{
			if ((m_openSpeed <= 0 && it->m_paperNO > m_currentPaperNO - 2 && it->m_paperNO < m_currentPaperNO + 12) || (m_openSpeed >= 0 && it->m_paperNO < m_currentPaperNO + 2 && it->m_paperNO > m_currentPaperNO - 12))
			{
				it->m_isActive = true;
			}
			else
			{
				it->m_isActive = false;
			}

			if (it->m_paperNO <= m_currentPaperNO && m_openSpeed > 0)
			{
				it->m_custom3d.angleYawPitchRoll.x += m_openSpeed;
				if (it->m_custom3d.angleYawPitchRoll.x > 180)
				{
					it->m_custom3d.angleYawPitchRoll.x = 180;
				}
				if (it->m_custom3d.angleYawPitchRoll.x < 0)
				{
					it->m_custom3d.angleYawPitchRoll.x = 0;
				}
			}
			if (it->m_paperNO >= m_currentPaperNO && m_openSpeed < 0)
			{
				it->m_custom3d.angleYawPitchRoll.x += m_openSpeed;
				if (it->m_custom3d.angleYawPitchRoll.x > 180)
				{
					it->m_custom3d.angleYawPitchRoll.x = 180;
				}
				if (it->m_custom3d.angleYawPitchRoll.x < 0)
				{
					it->m_custom3d.angleYawPitchRoll.x = 0;
				}
			}
		}

		break;
	case STEP::BEGIN:

		for (auto &it : m_ppPapers)
		{
			if (it->m_paperNO <= m_currentPaperNO && m_openSpeed > 0)
			{
				it->m_custom3d.angleYawPitchRoll.x += m_openSpeed;
				if (it->m_custom3d.angleYawPitchRoll.x > 180)
				{
					it->m_custom3d.angleYawPitchRoll.x = 180;
				}
				if (it->m_custom3d.angleYawPitchRoll.x < 0)
				{
					it->m_custom3d.angleYawPitchRoll.x = 0;
				}
			}
			if (it->m_paperNO >= m_currentPaperNO && m_openSpeed < 0)
			{
				it->m_custom3d.angleYawPitchRoll.x += m_openSpeed;
				if (it->m_custom3d.angleYawPitchRoll.x > 180)
				{
					it->m_custom3d.angleYawPitchRoll.x = 180;
				}
				if (it->m_custom3d.angleYawPitchRoll.x < 0)
				{
					it->m_custom3d.angleYawPitchRoll.x = 0;
				}
			}
		}
		break;
	case STEP::END:

		break;
	case STEP::FINISH:

		break;
	default:
		break;
	}
}