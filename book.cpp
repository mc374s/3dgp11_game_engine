#include "game.h"

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
	if (GetAsyncKeyState('8') & 0xF000) {
		m_pfMove = &Book::openBook;
	}
	if (GetAsyncKeyState('7') & 0xF000) {
		m_pfMove = &Book::closeBook;
	}
	if (GetAsyncKeyState('C') & 0x0001) {
		if (m_pfMove == &Book::openBook){
			m_pfMove = &Book::closeBook;
		} else {
			m_pfMove = &Book::openBook;
		}
	}
	if (m_pfMove)
	{
		(this->*m_pfMove)();
	}

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
		m_state = STATE_BEGIN;
		break;
	case STATE_BEGIN:
		m_openAngle -= 1;
		m_cameraAngleZY -= 0.01f;
		m_postion.z += 5;
		m_postion.y += 3;
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
		m_openAngle += 1;
		m_cameraAngleZY += 0.01f;
		m_postion.z -= 5;
		m_postion.y -= 3;
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