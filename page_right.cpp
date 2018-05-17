﻿#include "game.h"
#include "sprite_data.h"
#include "obj2d.h"
#include "player.h"

#include "page_right.h"

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

	drawRectangle(0, 0, 4, PAGE_HEIGHT, 0, 0x000000FF);

}