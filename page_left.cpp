#include "game.h"

PageLeft::PageLeft()
{
	m_bg.m_pSprData = &e_sprPageLeft;

}

void PageLeft::update()
{

}

void PageLeft::draw()
{
	
	m_bg.draw();

	drawString(0, PAGE_HEIGHT - 32, "PAGE_LEFT", COLOR_YELLOW, STR_LEFT, 32, 32);

}