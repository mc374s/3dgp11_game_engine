#include "game.h"
#include "player.h"
#include "page.h"
#include "sound_data.h"

#include "book.h"

Book::Book(int a_width, int a_height, int a_marginLeft, int a_marginTop, int a_marginRight, int a_marginBottom, int a_bookDepth, int a_coverDepth):
m_width(a_width),
m_height(a_height),
m_marginLeft(a_marginLeft),
m_marginTop(a_marginTop),
m_marginRight(a_marginRight),
m_marginBottom(a_marginBottom),
m_bookDepth(a_bookDepth),
m_coverDepth(a_coverDepth)
{

	float coverWidth = a_width + a_marginLeft + a_marginRight;
	float coverHeight = a_height + a_marginTop + a_marginBottom;
	m_pBookLeft = new Cube(XMFLOAT3(-a_width / 2, 0, a_bookDepth / 2), XMFLOAT3(a_width, a_height, a_bookDepth), 0xF0FFFFFF);
	m_pBookRight = new Cube(XMFLOAT3(a_width / 2, 0, a_bookDepth / 2), XMFLOAT3(a_width, a_height, a_bookDepth), 0xF0FFFFFF);
	m_pCoverLeft = new Cube(XMFLOAT3(-coverWidth / 2, 0, a_bookDepth + a_coverDepth / 2), XMFLOAT3(coverWidth, coverHeight, a_coverDepth), 0xFF6100FF);
	m_pCoverRight = new Cube(XMFLOAT3(coverWidth / 2, 0, a_bookDepth + a_coverDepth / 2), XMFLOAT3(coverWidth, coverHeight, a_coverDepth), 0xFF6100FF);

	init();

	// Page 0 is reserved
	for (int i = 0, pagination = 1; i < PAGINATION_MAX; ++i, ++pagination)
	{
		if (!m_ppPages[i])
		{ 
			m_ppPages[i] = new Page(m_width, m_height, pagination);
		}
	}


}

Book::~Book()
{
	SAFE_DELETE(m_pBookLeft);
	SAFE_DELETE(m_pBookRight);
	SAFE_DELETE(m_pCoverLeft);
	SAFE_DELETE(m_pCoverRight);
	for (auto &it : m_ppPages)
	{
		SAFE_DELETE(it);
	}
}

void Book::init()
{
	m_step = STEP::INIT;
	m_timer = 0;
	m_pfMove = nullptr;
	m_pfMoveOld = nullptr;
	m_isClosed = false;
	m_isOpened = true;
	m_openAngle = 0;
	m_cameraAngleXY = 0.0f;
	m_cameraAngleZY = 0.0f;
	m_cameraDistance = CAMERA_BEST_DISTANCE;
	m_position = { .0f,.0f,.0f };
}

int g_keyCounter = 0;

void Book::update()
{
	//////////////////////////////////////////////////////////////
	// For Book update

	// Open and Close Book
	// Change Book and Views' Angle
	if (KEY_BOARD.D8) {
		m_pfMove = &Book::openBook;
	}
	if (KEY_BOARD.D7) {
		m_pfMove = &Book::closeBook;
	}

	if (KEY_BOARD.Up){
		m_cameraDistance -= 0.01;
		if (m_cameraDistance < CAMERA_BEST_DISTANCE){
			m_cameraDistance = CAMERA_BEST_DISTANCE;
		}
	}
	if (KEY_BOARD.Down){
		m_cameraDistance += 0.01;
		if (m_cameraDistance > CAMERA_MAX_DISTANCE){							  
			m_cameraDistance = CAMERA_MAX_DISTANCE;
		}
	}

	// TODO : 本を閉じ開く [C] キーが getInputKey() の中のPAD_TRG3と衝突。解決：winAPPスタート時に一回KEY_TRACKER.Reset()
	if (/*KEY_DOWN('C')*/ KEY_TRACKER.pressed.C || PAD_TRACKER.x == PAD_TRACKER.PRESSED/*KEY_TRACKER.IsKeyPressed(Keyboard::Keys::C)*/) {
		if (m_isOpened)
		{
			m_pfMove = &Book::closeBook;
		}
		/*if (m_isClosed)
		{
			m_pfMove = &Book::openBook;
		}*/
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

	// 左右BookのYaw回転と位置を同調
	m_pBookLeft->m_custom3d.angleYawPitchRoll.x = m_openAngle;
	m_pCoverLeft->m_custom3d.angleYawPitchRoll.x = m_openAngle;

	m_pBookRight->m_custom3d.angleYawPitchRoll.x = -m_openAngle;
	m_pCoverRight->m_custom3d.angleYawPitchRoll.x = -m_openAngle;

	m_pBookLeft->m_custom3d.position = m_position;
	m_pCoverLeft->m_custom3d.position = m_position;

	m_pBookRight->m_custom3d.position = m_position;
	m_pCoverRight->m_custom3d.position = m_position;
	// 本全体の回転はカメラワークに任せる
	e_camera.upDirection = { sinf(m_cameraAngleZY)*sinf(m_cameraAngleXY), cosf(m_cameraAngleZY), sinf(m_cameraAngleZY)*cosf(m_cameraAngleXY), 0 };
	e_camera.eyePosition = { -fabs(m_cameraDistance)*cosf(m_cameraAngleZY)*sinf(m_cameraAngleXY), fabs(m_cameraDistance)*sinf(m_cameraAngleZY)/* + 310 / (float)SCREEN_WIDTH*/, -fabs(m_cameraDistance)*cosf(m_cameraAngleZY)*cosf(m_cameraAngleXY),0 };


	////////////////////////////////////////////////////////////////////////////////
	// For Pages update
	for (auto &it : m_ppPages)
	{
		if (it)
		{

			// 本とページの位置を同調かねて座標系の違いによる修正

			it->m_custom3d.position = m_position;
			it->m_custom3d.position.y = -m_position.y;
			it->m_custom3d.position.z = m_position.z - 0.1;
			if (it->m_pagination % 2 != 0)
			{// Page 1,3,5,7...
				it->m_custom3d.angleYawPitchRoll.x = m_openAngle;
			} else
			{// Page 2,4,6,8...
				it->m_custom3d.angleYawPitchRoll.x = -m_openAngle;
			}
			//Always Need to Update Page View's m_custom3d
			it->syncViewCustom3d();
			if (m_isOpened)
			{
				it->update();
			}
		}
	}

}

void Book::draw()
{
	if (m_pBookLeft){
		m_pBookLeft->draw();
	}
	if (m_pBookRight){
		m_pBookRight->draw();
	}
	if (m_pCoverLeft){
		m_pCoverLeft->draw();
	}
	if (m_pCoverRight) {
		m_pCoverRight->draw();
	}

	for (auto &it : m_ppPages)
	{
		if (it && it->m_isActive)
		{
			it->draw();
		}
	}

#ifdef DEBUG

	char buf[256];
	sprintf_s(buf, "Key Counter: %d", g_keyCounter);
	drawString(0, 300, buf);
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
		m_isClosed = false;
		m_isOpened = false;
		m_step = STEP::BEGIN;
		break;
	case STEP::BEGIN:
		m_openSpeedAcc += 0.01;
		m_openSpeed += m_openSpeedAcc;
		m_openAngle -= m_openSpeed;
		m_cameraAngleZY -= m_openSpeed*0.01f;
		m_position.z += m_openSpeed * 5.0f;
		m_position.y += m_openSpeed * 3.0f;
		if (m_openAngle <= -90) {
			m_timer = 0;
			m_isClosed = true;
			m_openAngle = -90;
			m_cameraAngleZY = -0.90f;
			m_position.z = 450;
			m_position.y = 270;
			m_step = STEP::END;
		}
		break;
	case STEP::END:
		m_timer++;
		if (m_timer > 120)
		{
			m_timer = 0;
			m_step = STEP::FINISH;
		}
		/*m_openAngle = -90;
		m_cameraAngleZY = -0.90f;
		m_position.z = 450;
		m_position.y = 270;*/
		//MFAudioPlay(SE_SHOT);
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
		m_isClosed = false;
		m_isOpened = false;
		m_step = STEP::BEGIN;
		break;
	case STEP::BEGIN:
		m_isClosed = false;
		m_openAngle += 5;
		m_cameraAngleZY += 0.05f;
		m_position.z -= 25;
		m_position.y -= 15;
		if (m_openAngle > 0) {
			m_isOpened = true;
			m_openAngle = 0;
			m_cameraAngleZY = 0.0f;
			m_position.z = 0;
			m_position.y = 0;
			m_step = STEP::END;
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