#include "game.h"
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
	// プレイヤーが通過したところにランダムで滲む判定用Objを配置
	if (pPlayerManager->m_pPlayer->m_isOnLeftPage == m_isLeftPage && pPlayerManager->m_pPlayer->m_isMoving){
		pObjManager->m_hitObj.m_isOnLeftPage = m_isLeftPage;
		Vector3 pos = pPlayerManager->m_pPlayer->m_pos;
		Vector3 speed = pPlayerManager->m_pPlayer->m_speed;
		Vector3 size = pPlayerManager->m_pPlayer->m_size;
		Vector3 randPos;
		for (int i = 0; i < 3; i++){

			randPos = { rand() % (int)(fabsf(speed.x) + size.x) - size.x / 2, (float)(rand() % (int)(fabsf(speed.y) + size.y)),0 };
			if (speed.y == 0)
			{
				randPos.x += size.x;
			}
			if (speed.y != 0)
			{
				randPos.y += size.y;
			}
			if (speed.x != 0)
			{
				randPos.x *= (speed.x / fabsf(speed.x));
			}
			if (speed.y != 0)
			{
				randPos.y *= (speed.y / fabsf(speed.y));
			}
			pObjManager->m_hitObj.m_pos = pos - randPos;
			pObjManager->m_hitObj.m_custom.angle = rand() % 90;
			pObjManager->m_hitObj.m_alpha = rand() % 20 + 20;
			pObjManager->m_newblurArea.push_back(pObjManager->m_hitObj);
		}
	}

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