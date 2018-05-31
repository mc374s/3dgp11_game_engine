#include "game.h"
#include "player.h"
#include "page.h"
#include "paper.h"


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

	float coverWidth = a_width + a_marginLeft + a_marginRight;
	float coverHeight = a_height + a_marginTop + a_marginBottom;/*
	m_pBookLeft = new Cube(XMFLOAT3(0, 0, 0), XMFLOAT3(a_width, a_height, a_bookDepth), 0xF0FFFFFF);
	m_pBookLeft->m_custom3d.position = XMFLOAT3(-a_width / 2, 0, a_bookDepth / 2);

	m_pBookRight = new Cube(XMFLOAT3(0, 0, 0), XMFLOAT3(a_width, a_height, a_bookDepth), 0xF0FFFFFF);
	m_pBookRight->m_custom3d.position = XMFLOAT3(a_width / 2, 0, a_bookDepth / 2);*/


	m_ppPapers[COVER_FRONT] = new Paper(COVER_FRONT, coverWidth, coverHeight, m_coverDepth, 0x664029FF);
	m_ppPapers[COVER_FRONT]->m_custom3d.position = m_ppPapers[COVER_FRONT]->m_initPos = { coverWidth / 2, 0, m_coverDepth / 2 };
	m_ppPapers[COVER_FRONT]->m_isActive = true;

	m_ppPapers[COVER_BACK] = new Paper(COVER_BACK, coverWidth, coverHeight, m_coverDepth, 0x664029FF);
	m_ppPapers[COVER_BACK]->m_custom3d.position = m_ppPapers[COVER_BACK]->m_initPos = { coverWidth / 2, 0, m_coverDepth + PAPER_LAST*PAPER_DEPTH + m_coverDepth / 2 };
	m_ppPapers[COVER_FRONT]->m_isActive = true;

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
	m_isOpened = true;
	m_openAngle = 0;
	m_position.z -= m_coverDepth;
}

int g_keyCounter = 0;

void Book::update()
{
	//////////////////////////////////////////////////////////////
	// For Book update

	// TODO : 本を閉じ開く [C] キーが getInputKey() の中のPAD_TRG3と衝突、解決要請
	// 原因はKEY_BOARDがexternで更新していることと予測
	if (/*KEY_DOWN('C')*/ KEY_TRACKER.pressed.C || PAD_TRACKER.x == PAD_TRACKER.PRESSED/*KEY_TRACKER.IsKeyPressed(Keyboard::Keys::C)*/) {
		/*if (m_pfMove == &Book::closeBook){
			m_pfMove = &Book::openBook;
		} else {
			m_pfMove = &Book::closeBook;
		}*/
		if (m_isOpened)
		{
			m_pfMove = &Book::closeBook;
		}
		if (m_isClosed)
		{
			m_pfMove = &Book::openBook;
		}
		g_keyCounter++;
	}
	if (m_pfMove)
	{
		(this->*m_pfMove)();
	}


	////////////////////////////////////////////////////////////////////////////////
	// For Pages update
	static int frame = 1;
	m_speed.x = m_speed.y = m_speed.z = 0;
	m_angleChangeSpeed.x = m_angleChangeSpeed.y = m_angleChangeSpeed.z = 0;
	/*if (frame==1)
	{
		m_speed.z = -m_bookDepth - 2 * m_coverDepth;
		frame++;
	}*/
	if (KEY_BOARD.Up){
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
	}
	/*if (KEY_BOARD.PageUp){
		m_speed.z = 4;
	}
	if (KEY_BOARD.PageDown){
		m_speed.z = -4;
	}*/

	if (KEY_BOARD.T) {
		m_angleChangeSpeed.y = 1;
	}
	if (KEY_BOARD.G) {
		m_angleChangeSpeed.y = -1;
	}
	if (KEY_BOARD.F) {
		m_angleChangeSpeed.x = 1;
	}
	if (KEY_BOARD.H) {
		m_angleChangeSpeed.x = -1;
	}
	if (KEY_BOARD.R) {
		m_angleChangeSpeed.z = 1;
	}
	if (KEY_BOARD.Y) {
		m_angleChangeSpeed.z = -1;
	}

	static int paperNO = 0;
	float angle = 0;

	if (KEY_TRACKER.pressed.D8){
		paperNO++;
		m_position.z -= m_ppPapers[paperNO]->m_depth;
	}
	if (KEY_TRACKER.pressed.D7){
		m_position.z += m_ppPapers[paperNO]->m_depth;
		paperNO--;
	}
	if (KEY_BOARD.Home){
		angle = 1;
	}
	if (KEY_BOARD.End) {
		angle = -1;
	}

	m_position += m_speed;
	m_angleYawPitchRoll += m_angleChangeSpeed;

	for (auto &it : m_ppPapers)
	{
		if (it)
		{

			if (it->m_paperNO == paperNO)
			{
				it->m_custom3d.angleYawPitchRoll.x += angle;
			}
			// 本とページの位置を同調かねて座標系の違いによる修正
			it->m_custom3d.angleYawPitchRoll += m_angleChangeSpeed;
			//angle -= 1;
			it->m_custom3d.position = m_position;
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
	for (auto &it : m_ppPapers)
	{
		if (it)
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
		m_openSpeedAcc += 0.005;
		m_openSpeed += m_openSpeedAcc;
		m_openAngle -= m_openSpeed;
		/*m_position.z += m_openSpeed * 5.0f;
		m_position.y += m_openSpeed * 3.0f;*/
		if (m_openAngle <= -90) {
			m_isClosed = true;
			m_openAngle = -90;
			/*m_position.z = 450;
			m_position.y = 270;*/
			m_step = STEP::END;
		}
		break;
	case STEP::END:
		/*m_openAngle = -90;
		m_cameraAngleZY = -0.90f;
		m_position.z = 450;
		m_position.y = 270;*/

		m_step = STEP::FINISH;
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
		m_openAngle += 3;
		/*m_position.z -= 15;
		m_position.y -= 9;*/
		if (m_openAngle > 0) {
			m_isOpened = true;
			m_openAngle = 0;
			/*m_position.z = 0;
			m_position.y = 0;*/
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