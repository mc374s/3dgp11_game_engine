#include "game.h"

PageLeft::PageLeft()
{

	m_bg.m_pSprData = &e_sprPageLeft;

	//pObjManager->init();
	pPlayerManager->init();

}

bool PageLeft::activePlayer(bool a_doActive)
{
	return m_isPlayerActive = a_doActive;
}

void PageLeft::update()
{
	if (m_isPlayerActive)
	{
		pPlayerManager->player->update();
	}
}

void PageLeft::draw()
{

	m_bg.draw();
	if (m_isPlayerActive)
	{
		pPlayerManager->player->draw();
	}
	drawString(0, PAGE_HEIGHT - 32, "PAGE_LEFT", COLOR_YELLOW, STR_LEFT, 32, 32);

}