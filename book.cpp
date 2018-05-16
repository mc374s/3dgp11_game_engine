#include "game.h"
#include "player.h"

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

	m_state = STATE_INIT;
	m_timer = 0;
	m_pfMove = nullptr;
	m_pfMoveOld = nullptr;
	m_isOpening = false;
	m_openAngle = 0;
}

Book::~Book()
{
	SAFE_DELETE(m_pBookLeft);
	SAFE_DELETE(m_pBookRight);
	SAFE_DELETE(m_pCoverLeft);
	SAFE_DELETE(m_pCoverRight);
}

void Book::update()
{
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

	// TODO : 本を閉じ開く [C] キーが getInputKey() の中のPAD_TRG3と衝突、解決要請
	// 原因はKEY_BOARDがexternで更新していることと予測
	if (/*KEY_TRACKER.pressed.C*/KEY_DOWN('C')/*KEY_BOARD.C*//*KEY_TRACKER.IsKeyPressed(Keyboard::Keys::C)*/) {
		if (m_pfMove == &Book::closeBook){
			m_pfMove = &Book::openBook;
		} else {
			m_pfMove = &Book::closeBook;
		}
		m_isOpening = !m_isOpening;
	}
	if (m_pfMove)
	{
		(this->*m_pfMove)();
	}

	// 左右BookのYaw回転と位置を同調
	m_pBookLeft->m_custom3d.angleYawPitchRoll.x = m_openAngle;
	m_pCoverLeft->m_custom3d.angleYawPitchRoll.x = m_openAngle;

	m_pBookRight->m_custom3d.angleYawPitchRoll.x = -m_openAngle;
	m_pCoverRight->m_custom3d.angleYawPitchRoll.x = -m_openAngle;

	m_pBookLeft->m_custom3d.position = m_postion;
	m_pCoverLeft->m_custom3d.position = m_postion;

	m_pBookRight->m_custom3d.position = m_postion;
	m_pCoverRight->m_custom3d.position = m_postion;
	// 本全体の回転はカメラワークに任せる
	e_camera.upDirection = { sinf(m_cameraAngleZY)*sinf(m_cameraAngleXY), cosf(m_cameraAngleZY), sinf(m_cameraAngleZY)*cosf(m_cameraAngleXY), 0 };
	e_camera.eyePosition = { -fabs(m_cameraDistance)*cosf(m_cameraAngleZY)*sinf(m_cameraAngleXY), fabs(m_cameraDistance)*sinf(m_cameraAngleZY)/* + 310 / (float)SCREEN_WIDTH*/, -fabs(m_cameraDistance)*cosf(m_cameraAngleZY)*cosf(m_cameraAngleXY),0 };

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
}

// Book move function
void Book::closeBook()
{
	if (m_pfMoveOld != &Book::closeBook)
	{
		m_pfMoveOld = m_pfMove;
		m_state = STATE_INIT;
	}
	switch (m_state)
	{
	case STATE_INIT:
		m_timer = 0;
		m_openSpeed = 0;
		m_openSpeedAcc = 0;
		m_state = STATE_BEGIN;
		break;
	case STATE_BEGIN:
		m_openSpeedAcc += 0.005;
		m_openSpeed += m_openSpeedAcc;
		m_openAngle -= m_openSpeed;
		m_cameraAngleZY -= m_openSpeed*0.01f;
		m_postion.z += m_openSpeed * 5.0f;
		m_postion.y += m_openSpeed * 3.0f;
		if (m_openAngle <= -90) {
			m_state = STATE_END;
		}
		break;
	case STATE_END:
		m_openAngle = -90;
		m_cameraAngleZY = -0.90f;
		m_postion.z = 450;
		m_postion.y = 270;

		pPlayerManager->transcriptPlayer();

		m_state = STATE_FINISH;
		break;
	case STATE_FINISH:

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
		m_state = STATE_INIT;
	}
	switch (m_state)
	{
	case STATE_INIT:
		m_timer = 0;
		m_state = STATE_BEGIN;
		break;
	case STATE_BEGIN:
		m_openAngle += 3;
		m_cameraAngleZY += 0.03f;
		m_postion.z -= 15;
		m_postion.y -= 9;
		if (m_openAngle > 0) {
			m_state = STATE_END;
		}
		break;
	case STATE_END:
		m_openAngle = 0;
		m_cameraAngleZY = 0.0f;
		m_postion.z = 0;
		m_postion.y = 0;
		m_state = STATE_FINISH;
		break;
	case STATE_FINISH:

		break;
	default:
		break;
	}
}