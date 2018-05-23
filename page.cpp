#include "game.h"

#include "sprite_data.h"
#include "obj2d.h"

#include "page.h"


Page::Page(int a_pageWidth, int a_pageHeight, int a_pagination) :m_pagination(a_pagination), m_width(a_pageWidth), m_height(a_pageHeight)
{
	m_bg.m_pSprData = &e_sprPageLeft;

	// Create a resize unable View
	if (m_pagination % 2 != 0)
	{// Left View
		m_pView = new View(-m_width, -m_height / 2, m_width, m_height, 0, 0, m_width, m_height);
	} else
	{// Right View
		m_pView = new View(0, -m_height / 2, m_width, m_height, 0, 0, m_width, m_height);
	}
}

void Page::init()
{

}

Page::~Page()
{
	if (m_pNextScene)
	{
		//delete nextScene;
		m_pNextScene = nullptr;
	}
	SAFE_DELETE(m_pView);
}

void Page::syncViewCustom3d()
{
	m_pView->m_custom3d = m_custom3d;
}

void Page::update()
{
	//ページの内容を更新
	/*if (m_pInnerScene)
	{
		if (m_pInnerScene->m_pNextScene)
		{
			m_pInnerScene = m_pInnerScene->m_pNextScene;
		}
		m_pInnerScene->update();
	}*/

	//ページの内容を更新
	pObjManager->update(m_pagination);


	// bucause of the depth test is ON, set a different depth between page surface and view
	//m_pView->m_custom3d.position.z = m_custom3d.position.z - 0.1;
}

void Page::draw()
{
	View::clear();
	m_pView->set();

	m_bg.draw();

	pObjManager->draw(m_pagination);

	// 真ん中の黒い線
	if (m_pagination % 2 != 0)
	{// Left View
		drawRectangle(m_width - 4, 0, 4, m_height, 0, 0x000000FF);
	} else
	{// Right View
		drawRectangle(0, 0, 4, m_height, 0, 0x000000FF);
	}

#ifdef DEBUG

	char buf[256];
	sprintf_s(buf, "Pagination: %d", m_pagination);
	drawString(0, m_height - 40, buf);

#endif // DEBUG

	View::clear();

}