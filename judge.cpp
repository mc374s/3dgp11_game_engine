#include "game.h"
#include "player.h"
#include "map_obj.h"
#include "scene_main.h"

#include "judge.h"



bool checkHitPlayerToMapObjOpened(Player* a_pPlayer, MapObj* a_pMapObj)
{
	return checkHitRectZ(a_pPlayer->m_pos.x, a_pPlayer->m_pos.y, a_pPlayer->m_size.x, a_pPlayer->m_size.y, 
		a_pMapObj->m_pos.x + a_pMapObj->m_size.x / 2, a_pMapObj->m_pos.y + a_pMapObj->m_size.y, a_pMapObj->m_size.x, a_pMapObj->m_size.y);
}
bool checkHitPlayerToMapObjClosed(Player* a_pPlayer, MapObj* a_pMapObj)
{
	return checkHitRectZ(PAGE_WIDTH - a_pPlayer->m_pos.x, a_pPlayer->m_pos.y, a_pPlayer->m_size.x, a_pPlayer->m_size.y,
		a_pMapObj->m_pos.x + a_pMapObj->m_size.x / 2, a_pMapObj->m_pos.y + a_pMapObj->m_size.y, a_pMapObj->m_size.x, a_pMapObj->m_size.y);
}

void judgeAll()
{
	static Player* pPlayer = pPlayerManager->m_pPlayer;
	static MapObj** ppMapObj = pMapObjManager->m_ppMapObj;
	static bool isBookClosed = false, isBookOpened = true, isTrancriptAble = true;
	isBookClosed = SCENE_MAIN->m_isBookClosed;
	isBookOpened = SCENE_MAIN->m_isBookOpened;
	if (isBookClosed)
	{
		pPlayerManager->m_isTranscriptAble = true;
		//pPlayerManager->manageConcentration();
	}

	for (int i = 0; i < MAPOBJ_MAX_NUM; i++)
	{
		if (isBookOpened && ppMapObj[i] && ppMapObj[i]->m_isHitAble && pPlayer->m_isOnLeftPage == ppMapObj[i]->m_isOnLeftPage 
			&& checkHitPlayerToMapObjOpened(pPlayer, ppMapObj[i]))
		{
			//ppMapObj[i]->clear();
			if (ppMapObj[i]->m_type != MAPOBJ_HIGH_CONCENTRATION && ppMapObj[i]->m_type != MAPOBJ_NONE)
			{
				ppMapObj[i]->hitAdjust(pPlayer);
			}
		}
		if (isBookClosed && ppMapObj[i] && ppMapObj[i]->m_isHitAble && pPlayer->m_isOnLeftPage != ppMapObj[i]->m_isOnLeftPage
			&& checkHitPlayerToMapObjClosed(pPlayer, ppMapObj[i]))
		{
			if (pPlayer->m_concentration <= ppMapObj[i]->m_concentration)
			{
				pPlayerManager->m_isTranscriptAble = false;
			}
		}
	}
}

bool checkHitRectZ(float ax, float ay, int aw, int ah, float bx, float by, int bw, int bh)
{
	float al = ax - aw / 2;		//•¨‘ÌA‚Ì¶’[(Left)
	float ar = ax + aw / 2;
	float au = ay - ah;
	float ad = ay;

	float bl = bx - bw / 2;		//•¨‘ÌB‚Ì¶’[(Left)
	float br = bx + bw / 2;
	float bu = by - bh;
	float bd = by;

	//“–‚½‚Á‚Ä‚¢‚È‚¢ğŒ
	if (aw <= 0 || ah <= 0 || bw <= 0 || bh <= 0)
	{
		return  false;
	}
	if (al > br)
	{
		return false;
	}
	if (ar < bl)
	{
		return false;
	}
	if (au > bd)
	{
		return false;
	}
	if (ad < bu)
	{
		return false;
	}
	return true;
}