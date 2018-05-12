#include "Game.h"

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
}

Book::~Book()
{
	SAFE_DELETE(m_pBookLeft);
	SAFE_DELETE(m_pBookRight);
	SAFE_DELETE(m_pCoverLeft);
	SAFE_DELETE(m_pCoverRight);
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