#ifndef _BOOK_H_
#define _BOOK_H_

#define PAGINATION_MAX (2)

class Page;

class Book
{
private:

public:
	int m_step;
	int m_timer;

	int m_width;
	int m_height;
	int m_marginLeft;
	int m_marginTop;
	int m_marginRight;
	int m_marginBottom;
	int m_bookDepth;
	int m_coverDepth;

	Cube *m_pBookLeft;
	Cube *m_pBookRight;
	Cube *m_pCoverLeft;
	Cube *m_pCoverRight;

	float m_cameraAngleXY = 0.0f, m_cameraAngleZY = 0.0f;
	float m_cameraDistance = 0.66f;

	Book(int a_width, int a_height, int a_marginLeft, int a_marginTop, int a_marginRight, int a_marginBottom, int a_bookDepth, int a_coverDepth);
	~Book();


	// メンバー関数の関数ポインタ
	void(Book::*m_pfMove)();
	void(Book::*m_pfMoveOld)();

	float m_openAngle = 0;
	float m_openSpeed = 0;
	float m_openSpeedAcc = 0;
	XMFLOAT3 m_position = { 0,0,0 };
	bool m_isClosed;
	bool m_isOpened;

	// Page 0 is reserved
	Page* m_ppPages[PAGINATION_MAX] = { nullptr };

	void init();
	void update();
	void draw();

	void closeBook();
	void openBook();
};

#endif // !_BOOK_H_
