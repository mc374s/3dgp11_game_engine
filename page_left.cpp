#include "game.h"
#include "sprite_data.h"
#include "obj2d.h"
#include "player.h"
#include "map_obj.h"

#include "page_left.h"

PageLeft::PageLeft()
{
	m_bg.m_pSprData = &e_sprPageLeft;
}

void PageLeft::init()
{
	pPlayerManager->init();
}

void PageLeft::update()
{
	
	pObjManager->update(m_pagination);
}

void PageLeft::draw()
{

	m_bg.draw();

	pObjManager->draw(m_pagination);

	drawRectangle(PAGE_WIDTH - 4, 0, 4, PAGE_HEIGHT, 0, 0x000000FF);

	View::clear();
	//char buf[256];
	//sprintf_s(buf, "Player Concentration: %d\nTransfer Concentration: %d", pPlayerManager->m_pPlayer->m_concentration, pPlayerManager->m_concentration - pPlayerManager-//>m_transferConcentration);
	//drawString(0, 300, buf);

}