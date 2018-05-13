#include "game.h"

PageRight::PageRight()
{
	
	m_bg.m_pSprData = &e_sprPageRight;

	//pObjManager->init();
	pPlayerManager->init();

}

void PageRight::update()
{
	/*if (!pPlayerManager->m_pPlayerTsuta->m_isOnLeftPage && !m_isLeftPage)
	{
		pPlayerManager->m_pPlayerTsuta->update();
	}*/
	pObjManager->updata(m_isLeftPage);
}

void PageRight::draw()
{

	m_bg.draw();
	/*if (!pPlayerManager->m_pPlayerTsuta->m_isOnLeftPage && !m_isLeftPage)
	{
		pPlayerManager->m_pPlayerTsuta->draw();
	}*/
	pObjManager->draw(m_isLeftPage);

	drawString(0, PAGE_HEIGHT - 32, "PAGE_RIGHT", COLOR_YELLOW, STR_LEFT, 32, 32);

}