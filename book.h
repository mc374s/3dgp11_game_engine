#ifndef _BOOK_H_
#define _BOOK_H_

class Book
{
private:

public:
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

	Book(int a_width, int a_height, int a_marginLeft, int a_marginTop, int a_marginRight, int a_marginBottom, int a_bookDepth, int a_coverDepth);
	~Book();

	void draw();
};


#endif // !_BOOK_H_
