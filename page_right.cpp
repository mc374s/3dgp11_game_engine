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
	/*if (!pPlayerManager->m_pPlayerTsuta->m_isOnLeftPage && !m_pagination)
	{
		pPlayerManager->m_pPlayerTsuta->update();
	}*/
	// プレイヤーが通過したところにランダムで滲む判定用Objを配置
	if (pPlayerManager->m_pPlayer->m_liveInPagination == m_pagination && pPlayerManager->m_pPlayer->m_isMoving){
		pObjManager->m_hitObj.m_liveInPagination = m_pagination;
		Vector3 pos = pPlayerManager->m_pPlayer->m_pos;
		Vector3 speed = pPlayerManager->m_pPlayer->m_speed;
		Vector3 size = pPlayerManager->m_pPlayer->m_size;
		Vector3 randAdjust;
		for (int i = 0; i < 3; i++){
			randAdjust = { (float)(rand() % (int)(fabsf(speed.x) + size.x)), (float)(rand() % (int)(fabsf(speed.y) + size.y)),0 };
			if (speed.x == 0 && !pPlayerManager->m_pPlayer->m_isOnGround)
			{
				randAdjust.x -= size.x / 2;
				randAdjust.y -= size.y / 2;
			}
			if (pPlayerManager->m_pPlayer->m_isOnGround)
			{
				randAdjust.x += size.x / 2;
			}

			if (speed.x != 0)
			{
				randAdjust.x *= (speed.x / fabsf(speed.x));
			}
			if (speed.y != 0)
			{
				randAdjust.y *= (speed.y / fabsf(speed.y));
			}
			pObjManager->m_hitObj.m_pos = pos - randAdjust;
			pObjManager->m_hitObj.m_custom.angle = rand() % 190;
			pObjManager->m_hitObj.m_alpha = rand() % 20 + 20;
			pObjManager->m_newblurAreaList.push_back(pObjManager->m_hitObj);
		}
	}

	pObjManager->update(m_pagination);
}

void PageRight::draw()
{

	m_bg.draw();
	/*if (!pPlayerManager->m_pPlayerTsuta->m_isOnLeftPage && !m_pagination)
	{
		pPlayerManager->m_pPlayerTsuta->draw();
	}*/
	pObjManager->draw(m_pagination);

	drawRectangle(0, 0, 4, PAGE_HEIGHT, 0, 0x000000FF);

}