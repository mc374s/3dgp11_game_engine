#include "game.h"

PageRight::PageRight()
{
	
	m_bg.m_pSprData = &e_sprPageRight;

	//pObjManager->init();
	pPlayerManager->init();

}

void PageRight::update()
{
	//pObjManager->updata();
	pPlayerManager->player->update();
}

void PageRight::draw()
{

	m_bg.draw();
	//pObjManager->draw();
	pPlayerManager->player->draw();
	drawString(0, PAGE_HEIGHT - 32, "PAGE_RIGHT", COLOR_YELLOW, STR_LEFT, 32, 32);

}