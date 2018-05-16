#include "game.h"
#include "player.h"
#include "map_obj.h"

#include "judge.h"



BOOL checkHitPlayerToMapObj(Player* a_pPlayer, MapObj* a_pMapObj)
{
	return checkHitRectZ(a_pPlayer->m_pos.x, a_pPlayer->m_pos.y, a_pPlayer->m_size.x, a_pPlayer->m_size.y, 
		a_pMapObj->m_pos.x + a_pMapObj->m_size.x / 2, a_pMapObj->m_pos.y + a_pMapObj->m_size.y, a_pMapObj->m_size.x, a_pMapObj->m_size.y);
}

void judgeAll()
{
	Player* pPlayer = pPlayerManager->m_pPlayer;
	MapObj** ppMapObj = pMapObjManager->m_ppMapObj;

	for (int i = 0; i < MAPOBJ_MAX_NUM; i++)
	{
		if (ppMapObj[i] && ppMapObj[i]->m_isHitAble && pPlayer->m_isOnLeftPage == ppMapObj[i]->m_isOnLeftPage && checkHitPlayerToMapObj(pPlayer, ppMapObj[i]))
		{
			//ppMapObj[i]->clear();
			ppMapObj[i]->hitAdjust(pPlayer);
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