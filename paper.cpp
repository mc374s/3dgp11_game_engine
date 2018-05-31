#include "game.h"

#include "sprite_data.h"
#include "obj2d.h"
#include "page.h"

#include "paper.h"


Paper::Paper(int a_paperNO, int a_pageWidth, int a_pageHeight, int a_paperDepth, UINTCOLOR a_materialColor)
	:m_paperNO(a_paperNO), m_width(a_pageWidth), m_height(a_pageHeight), m_depth(a_paperDepth), m_materialColor(a_materialColor)
{
	m_pBG = new OBJ2D;
	m_pBG->m_pSprData = &e_sprPageLeft;

	m_pCube = new Cube(XMFLOAT3(.0f, .0f, .0f), XMFLOAT3(m_width, m_height, m_depth), m_materialColor);
	//m_pCube->m_custom3d.position = XMFLOAT3(-m_width / 2, 0, m_paperNO*m_depth);
	// Create a resize unable View
	m_pViewFront = new View(-m_width / 2, -m_height / 2, m_width, m_height, 0, 0, m_width, m_height);
	m_pViewBack = new View(-m_width / 2, -m_height / 2, m_width, m_height, 0, 0, m_width, m_height);
	m_pViewBack->m_doReflection = true;

	m_initPos = { 0,0,0 };
	m_pCube->m_custom3d = m_custom3d;
	m_pViewFront->m_custom3d = m_custom3d;
	m_pViewFront->m_custom3d.position.z -= 0.6;
	m_pViewBack->m_custom3d = m_custom3d;
	m_pViewBack->m_custom3d.position.z += 0.6;


	m_paginationFront = m_paperNO * 2;
	m_paginationBack = m_paperNO * 2 + 1;
	m_isActive = false;
}

void Paper::init()
{

}

Paper::~Paper()
{
	if (m_pNextScene)
	{
		//delete nextScene;
		m_pNextScene = nullptr;
	}
	SAFE_DELETE(m_pViewFront);
	SAFE_DELETE(m_pViewBack);
	SAFE_DELETE(m_pCube);
	SAFE_DELETE(m_pBG);
}

void Paper::syncViewCustom3d()
{

	// bucause of the depth test is ON, set a different depth between page surface and view
	m_custom3d.position += m_initPos;
	m_pCube->m_custom3d = m_custom3d;
	m_pViewFront->m_custom3d = m_custom3d;
	m_pViewFront->m_custom3d.position.z -= 0.6;
	m_pViewBack->m_custom3d = m_custom3d;
	m_pViewBack->m_custom3d.position.z += 0.6;
}

void Paper::update()
{
	//ページの内容を更新
	if (m_isActive)
	{
		pObjManager->update(m_paginationFront);
		//pObjManager->update(m_paginationBack);
	}



}

void Paper::draw()
{
	View::clear();

	m_pCube->draw();

	if (m_isActive)
	{

		///////////////////////////////////////////////////////////////////////////////////////////////////
		// Front View
		m_pViewFront->set();
		m_pBG->draw();

		pObjManager->draw(m_paginationFront);
		drawRectangle(0, 0, 4, m_height, 0, 0x000000FF);

#ifdef DEBUG

		char buf[256];
		sprintf_s(buf, "Pagination: %d", m_paginationFront);
		drawString(m_width - 40, m_height - 40, buf);

#endif // DEBUG

		View::clear();

		//////////////////////////////////////////////////////////////////////////////////////////////////
		// Back View
		m_pViewBack->set();
		m_pBG->draw();

		pObjManager->draw(m_paginationBack);
		drawRectangle(m_width - 4, 0, 4, m_height, 0, 0x000000FF);


#ifdef DEBUG

		sprintf_s(buf, "Pagination: %d", m_paginationBack);
		drawString(0, m_height - 40, buf);

#endif // DEBUG

		View::clear();
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////
	// Scene Main View

}