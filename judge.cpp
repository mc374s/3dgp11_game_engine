﻿#include "game.h"
#include "player.h"
#include "map_obj.h"
#include "scene_main.h"

#include "obj2d.h"

#include "judge.h"


bool checkObjOpened(OBJ2D* a_pObjA, OBJ2D* a_pObjB)
{
	return checkHitRectZ(a_pObjA->m_pos.x, a_pObjA->m_pos.y, a_pObjA->m_size.x, a_pObjA->m_size.y,
		a_pObjB->m_pos.x, a_pObjB->m_pos.y, a_pObjB->m_size.x, a_pObjB->m_size.y);
}

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
	static bool isBookClosed = false, isBookOpened = true, isTrancriptAble = true;

	// When Restart, ignore Judgement
	if (pPlayer->m_mode == P_MODE_INIT)
	{
		pObjManager->m_newblurAreaList.clear();
		return;
	}

	isBookClosed = SCENE_MAIN->m_isBookClosed;
	isBookOpened = SCENE_MAIN->m_isBookOpened;
	if (isBookClosed)
	{
		pPlayerManager->manageConcentration();
		pPlayerManager->m_isTranscriptAble = true;
		pPlayerManager->m_isTranscriptCanceled = false;
	}
	if (!isBookClosed)
	{
		pPlayerManager->m_state = STATE_INIT;
	}

	for (auto &mapObj : pMapObjManager->m_mapObjList)
	{
		if (isBookOpened && mapObj.m_isHitAble && pPlayer->m_isOnLeftPage == mapObj.m_isOnLeftPage
			&& checkHitPlayerToMapObjOpened(pPlayer, &mapObj))
		{
			//mapObj.clear();
			if (mapObj.m_type != MAPOBJ_HIGH_CONCENTRATION && mapObj.m_type != MAPOBJ_NONE
				&& mapObj.m_type != MAPOBJ_DOOR && mapObj.m_type != MAPOBJ_KEY
				&& (mapObj.m_concentration > LOW_CONCENTRATION || pPlayer->m_concentration > LOW_CONCENTRATION))
			{
				mapObj.hitAdjust(pPlayer);
			}

			if (mapObj.m_type == MAPOBJ_HIGH_CONCENTRATION)
			{
				if (pPlayer->m_concentration < mapObj.m_concentration)
				{
					pPlayer->m_mode = P_MODE_INIT;
				}
			}


			// 鍵関係
			if (mapObj.m_type == MAPOBJ_KEY)
			{
				pPlayer->m_isKeyHandled = true;
				pPlayer->m_keyObj.m_pSprData = mapObj.m_pSprData;
				mapObj.m_isHitAble = false;
				mapObj.m_alpha = 0;
			}
			if (mapObj.m_type == MAPOBJ_DOOR && pPlayer->m_isKeyHandled)
			{
				//pPlayer->m_isKeyHandled = false;
				pPlayer->m_keyObj.m_pSprData = mapObj.m_pSprData;
				pPlayer->m_mode = P_MODE_CLEAR;
				//mapObj.clear();
			}
		}
		if (isBookClosed && mapObj.m_isHitAble && pPlayer->m_isOnLeftPage != mapObj.m_isOnLeftPage
			&& checkHitPlayerToMapObjClosed(pPlayer, &mapObj))
		{
			if ((pPlayer->m_concentration < mapObj.m_concentration || pPlayer->m_concentration < LOW_CONCENTRATION) && mapObj.m_concentration > LOW_CONCENTRATION)
			{
				pPlayerManager->m_isTranscriptAble = false;
				if (mapObj.m_type == MAPOBJ_HIGH_CONCENTRATION)
				{
					pPlayerManager->m_isTranscriptAble = true;
					pPlayerManager->m_isTranscriptCanceled = true;
				}
			}
		}
	}

	for (int i = 0; i < MAPOBJ_MAX_NUM; i++)
	{
		
	}

	// 転写元判定
	for (auto &it : pObjManager->m_transcriptionList) {

		if (pPlayer->m_isOnLeftPage == it.m_isOnLeftPage && checkObjOpened(pPlayer, &(it)) && it.m_concentration > 1)
		{
			// TODO : 関数化

			if (pPlayer->m_concentration < P_CONCENTRATION_MAX_NUM)
			{
				if (it.m_concentration - 1 + pPlayer->m_concentration > P_CONCENTRATION_MAX_NUM)
				{
					it.m_concentration -= P_CONCENTRATION_MAX_NUM - pPlayer->m_concentration;
					pPlayer->m_concentration = P_CONCENTRATION_MAX_NUM;
				}
				else
				{
					pPlayer->m_concentration += it.m_concentration - 1;
					it.m_concentration = 1;
				}

				pPlayer->m_alpha = 255 * pPlayer->m_concentration / P_CONCENTRATION_MAX_NUM;
				it.m_alpha = 255 * it.m_concentration / P_CONCENTRATION_MAX_NUM;
			}
			break;
		}
	}


	// 滲んだとこと判定
	pPlayer->m_isOnBlurArea = false;
	if (isBookOpened)
	{
		for (auto &it : pObjManager->m_blurAreaList) {

			if (pPlayer->m_isOnLeftPage == it.m_isOnLeftPage && checkObjOpened(pPlayer, &(it)))
			{
				pPlayer->m_isOnBlurArea = true;
				break;
			}
		}
	}


	// 被ってる滲むObjは作らない
	bool isRepeated = false;
	for (auto &newIt : pObjManager->m_newblurAreaList) {
		isRepeated = false;
		for (auto it : pObjManager->m_blurAreaList) {

			if (newIt.m_isOnLeftPage == it.m_isOnLeftPage && checkObjOpened(&(newIt), &(it)))
			{
				isRepeated = true;
				break;
			}
		}
		if (!isRepeated)
		{
			pObjManager->m_blurAreaList.push_back(newIt);
		}
	}
	pObjManager->m_newblurAreaList.clear();

}

bool checkHitRectZ(float ax, float ay, int aw, int ah, float bx, float by, int bw, int bh)
{
	float al = ax - aw / 2;		//物体Aの左端(Left)
	float ar = ax + aw / 2;
	float au = ay - ah;
	float ad = ay;

	float bl = bx - bw / 2;		//物体Bの左端(Left)
	float br = bx + bw / 2;
	float bu = by - bh;
	float bd = by;

	//当たっていない条件
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