#include "game.h"
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
	static MapObj** ppMapObj = pMapObjManager->m_ppMapObjs;
	static bool isBookClosed = false, isBookOpened = true, isTrancriptAble = true;

	// When Restart, ignore Judgement
	if (pPlayer->m_mode == P_MODE::RESTART)
	{
		pObjManager->m_newblurAreaList.clear();
		return;
	}

	isBookClosed = SCENE_MAIN->m_isBookClosed;
	isBookOpened = SCENE_MAIN->m_isBookOpened;
	if (isBookClosed)
	{
		pPlayerManager->m_isTranscriptAble = true;
		pPlayerManager->m_isTranscriptCanceled = false;
		pPlayerManager->manageConcentration();
	}
	if (!isBookClosed)
	{
		pPlayerManager->m_step = STEP::INIT;
	}


	for (int i = 0; i < MAPOBJ_MAX_NUM; i++)
	{
		if (isBookOpened && ppMapObj[i] && ppMapObj[i]->m_isHitAble && pPlayer->m_liveInPagination == ppMapObj[i]->m_liveInPagination 
			&& checkHitPlayerToMapObjOpened(pPlayer, ppMapObj[i]))
		{
			//ppMapObj[i]->clear();
			if (ppMapObj[i]->m_type != M_TYPE::HIGH_CONCENTRATION && ppMapObj[i]->m_type != M_TYPE::NONE
				&& ppMapObj[i]->m_type != M_TYPE::DOOR && ppMapObj[i]->m_type != M_TYPE::KEY && ppMapObj[i]->m_type != M_TYPE::RECOVERY_UP && ppMapObj[i]->m_type != M_TYPE::RECOVERY_DOWN
				&& (pPlayer->m_concentration <= ppMapObj[i]->m_concentration/*ppMapObj[i]->m_concentration > LOW_CONCENTRATION || pPlayer->m_concentration > LOW_CONCENTRATION*/))
			{
				ppMapObj[i]->hitAdjust(pPlayer);
			}


			if (ppMapObj[i]->m_type == M_TYPE::HIGH_CONCENTRATION)
			{
				if (pPlayer->m_concentration < ppMapObj[i]->m_concentration)
				{
					pPlayer->m_mode = P_MODE::RESTART;
				}
			}

			if (ppMapObj[i]->m_type == M_TYPE::RECOVERY_UP)
			{
				if (pPlayer->m_speed.y < 0) {
					//上方向すり抜けobjの下より、プレイヤーの足元位置のほうが上になったら回復
					if (pPlayer->m_pos.y < ppMapObj[i]->m_pos.y + ppMapObj[i]->m_size.y) {
						pPlayer->m_concentration = 10;
					}
				}
				else ppMapObj[i]->hitAdjust(pPlayer);
			}

			if (ppMapObj[i]->m_type == M_TYPE::RECOVERY_DOWN)
			{
				if (pPlayer->m_speed.y >= 0) {
					//下方向すり抜けobjの上より、プレイヤーの頭上位置のほうが下になったら回復
					if (pPlayer->m_pos.y - pPlayer->m_size.y > ppMapObj[i]->m_pos.y) {
						pPlayer->m_concentration = 10;
					}
				}
				else ppMapObj[i]->hitAdjust(pPlayer);
			}


			// 鍵関係
			if (ppMapObj[i]->m_type == M_TYPE::KEY)
			{
				pPlayer->m_isKeyHandled = true;
				pPlayer->m_keyObj->m_pSprData = ppMapObj[i]->m_pSprData;
				ppMapObj[i]->m_isHitAble = false;
				ppMapObj[i]->m_concentration = LOW_CONCENTRATION;
			}
			if (ppMapObj[i]->m_type == M_TYPE::DOOR && pPlayer->m_isKeyHandled)
			{
				pPlayer->m_isKeyHandled = false;
				//pPlayer->m_keyObj.m_pSprData = ppMapObj[i]->m_pSprData;
				pPlayer->m_keyObj->m_pSprData = nullptr;
				pPlayer->m_mode = P_MODE::CLEAR;
				ppMapObj[i]->m_isHitAble = false;
				ppMapObj[i]->m_concentration = P_CONCENTRATION_MAX_NUM;
			}
		}
		if (isBookClosed && ppMapObj[i] && ppMapObj[i]->m_isHitAble && pPlayer->m_liveInPagination != ppMapObj[i]->m_liveInPagination
			&& checkHitPlayerToMapObjClosed(pPlayer, ppMapObj[i]))
		{
			// 
			//if ((pPlayer->m_concentration < ppMapObj[i]->m_concentration || pPlayer->m_concentration < LOW_CONCENTRATION) && ppMapObj[i]->m_concentration > LOW_CONCENTRATION)
			// プレイヤーの濃度より高いObjは転写できない
			if (pPlayer->m_concentration < ppMapObj[i]->m_concentration && (ppMapObj[i]->m_type != M_TYPE::KEY || ppMapObj[i]->m_type == M_TYPE::DOOR))
			{
				pPlayerManager->m_isTranscriptAble = false;
				if (ppMapObj[i]->m_type == M_TYPE::HIGH_CONCENTRATION)
				{
					pPlayerManager->m_isTranscriptAble = true;
					pPlayerManager->m_isTranscriptCanceled = true;
				}
			}
		}
	}

	// 転写元判定
	if (isBookOpened)
	{
		for (auto &it : pObjManager->m_transcriptionList) {

			if (pPlayer->m_liveInPagination == it.m_liveInPagination && checkObjOpened(pPlayer, &(it)) && it.m_concentration > 1)
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
	}


	// 滲んだとこと判定
	pPlayer->m_isOnBlurArea = false;
	if (isBookOpened)
	{
		for (auto &it : pObjManager->m_blurAreaList) {

			if (pPlayer->m_liveInPagination == it.m_liveInPagination && checkObjOpened(pPlayer, &(it)))
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

			if (newIt.m_liveInPagination == it.m_liveInPagination && checkObjOpened(&(newIt), &(it)))
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