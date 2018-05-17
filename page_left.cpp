#include "game.h"
#include "sprite_data.h"
#include "obj2d.h"
#include "player.h"

#include "page_left.h"

PageLeft::PageLeft()
{

	m_bg.m_pSprData = &e_sprPageLeft;

	//pObjManager->init();
	pPlayerManager->init();

}

void PageLeft::update()
{
	/*if (pPlayerManager->m_pPlayerTsuta->m_isOnLeftPage && m_isLeftPage)
	{
		pPlayerManager->m_pPlayerTsuta->update();
	}*/

	pObjManager->updata(m_isLeftPage);
}

void PageLeft::draw()
{

	m_bg.draw();
	/*if (pPlayerManager->m_pPlayerTsuta->m_isOnLeftPage && m_isLeftPage)
	{
		pPlayerManager->m_pPlayerTsuta->draw();
	}*/
	pObjManager->draw(m_isLeftPage);

	drawString(0, PAGE_HEIGHT - 32, "PAGE_LEFT", COLOR_YELLOW, STR_LEFT, 32, 32);
	drawRectangle(618, 0, 2, PAGE_HEIGHT, 0, 0x000000FF);
}