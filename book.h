#ifndef _BOOK_H_
#define _BOOK_H_

#define INNER_PAPER_MAX_NUM (80)

enum PAPER_NO
{
	COVER_FRONT = 0,
	PAPER_FIRST,
	PAPER_LAST = INNER_PAPER_MAX_NUM,
	COVER_BACK,
	MAX_PAPER_NO,
};

class Page;
class Paper;

class Book
{
private:

public:
	int m_step;
	int m_timer;

	float m_width;
	float m_height;
	float m_marginLeft;
	float m_marginTop;
	float m_marginRight;
	float m_marginBottom;
	float m_bookDepth;
	float m_coverDepth;

	Paper *m_ppPapers[PAPER_NO::MAX_PAPER_NO] = { nullptr };

	Book(int a_width, int a_height, int a_marginLeft, int a_marginTop, int a_marginRight, int a_marginBottom, int a_coverDepth);
	~Book();


	// メンバー関数の関数ポインタ
	void(Book::*m_pfMove)();
	void(Book::*m_pfMoveOld)();

	float m_openAngle = 0;
	float m_openSpeed = 0;
	float m_openSpeedAcc = 0;
	XMFLOAT3 m_position;
	XMFLOAT3 m_initPos;
	XMFLOAT3 m_speed;
	XMFLOAT3 m_speedAcc;
	XMFLOAT3 m_speedMax;
	XMFLOAT3 m_angleChangeSpeed;
	XMFLOAT3 m_angleYawPitchRoll;

	float m_centerPaper;

	bool m_isClosed;
	bool m_isOpened;

	void init();
	void update();
	void draw();

	void closeBook();
	void openBook();

};

#endif // !_BOOK_H_
