#include "game.h"

PageRight::PageRight()
{
	
	m_bg.m_pSprData = &e_sprPageRight;

	//pObjManager->init();
	pPlayerManager->init();

}

bool PageRight::activePlayer(bool a_doActive)
{
	return m_isPlayerActive = a_doActive;
}

void PageRight::update()
{
	if (m_isPlayerActive)
	{
		pPlayerManager->player->update();
	}
}

void PageRight::draw()
{

	m_bg.draw();
	if (m_isPlayerActive)
	{
		pPlayerManager->player->draw();
	}
	drawString(0, PAGE_HEIGHT - 32, "PAGE_RIGHT", COLOR_YELLOW, STR_LEFT, 32, 32);

}