#include "game.h"
#include "obj2d.h"
#include "player.h"
#include "map_obj.h"
#include "sound_data.h"

#include "paper.h"
#include "book.h"
#include "effect.h"

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

	static bool isBookClosed = false, isBookOpened = true, isStageCleared = false;

	static Player* pPlayer = pPlayerManager->m_pPlayer;
	static int judgePagination = pPlayer->m_liveInPagination;

	static std::vector<MapObj>* pMapObjList = nullptr;
	static std::vector<OBJ2D>* pBlurList = nullptr;

	// When Restart, ignore Judgement
	if (pPlayer->m_mode == P_MODE::RESTART)
	{
		pPlayer->m_newblurAreaList.clear();
		return;
	}
	pPlayer->m_isDamaged = false;
	isBookClosed = pBook->m_isClosed;
	isBookOpened = pBook->m_isOpened;
	if (isBookOpened)
	{
		judgePagination = pPlayer->m_liveInPagination;
	}
	else
	{
		if (pPlayer->m_pBorder)
		{
			pPlayer->m_pBorder->m_step = STEP::INIT;
			pPlayer->m_pBorder->m_doReverseMove = true;
			pPlayer->m_pBorder = nullptr;
		}
	}
	if (isBookClosed)
	{
		judgePagination = pPlayer->m_liveInPagination + (pPlayer->m_liveInPagination % 2 ? 1 : -1);
	}
	pMapObjList = &(pBook->m_ppPapers[judgePagination / 2]->m_mapObjList[judgePagination % 2]);
	pBlurList = &(pBook->m_ppPapers[judgePagination / 2]->m_blurAreaList[judgePagination % 2]);

	if (isBookClosed)
	{
		//pPlayerManager->m_isTranscriptAble = true;
		//pPlayerManager->m_isTranscriptCanceled = false;
		pPlayerManager->manageConcentration();
	}
	else
	{
		pPlayerManager->m_step = STEP::INIT;
	}

	if (isBookOpened || isBookClosed)
	{
		isStageCleared = true;
		for (MapObj &it : *pMapObjList)
		{
			if (isBookOpened && it.m_isHitAble && checkHitPlayerToMapObjOpened(pPlayer, &it) && pPlayer->m_concentration>0.0f)
			{
				//it.clear();

				if (it.m_type == M_TYPE::PASSABLE_UP) {
					if (pPlayer->m_speed.y < 0 && (pPlayer->m_pos.y + pPlayer->m_speed.y < it.m_pos.y)) {
						//上方向すり抜けobjの下より、プレイヤーの足元位置のほうが上になったら回復
						pPlayer->m_concentration += it.m_concentration;
						it.m_concentration = 0;
						if (pPlayer->m_concentration > 10) {
							pPlayer->m_concentration = 10;
						}
						Effect::searchSet(pEffectManager->m_ppEffect, EFF_OBJ_MAX_NUM, Vector3(pPlayer->m_pos.x, it.m_initPos.y, 0.0f), pPlayer->m_liveInPagination, effectRecoveryPassed, 1);
						MFAudioPlay(SE_SPLASH);
					}
					else if (/*pPlayer->m_pos.y - pPlayer->m_speed.y <= it.m_pos.y + GRIVATY*/pPlayer->m_speed.y > 0.0f) {
						it.hitAdjust(pPlayer);
					}
				}

				if (it.m_type == M_TYPE::PASSABLE_DOWN) {
					if (pPlayer->m_speed.y > 0 && (pPlayer->m_pos.y - pPlayer->m_size.y + pPlayer->m_speed.y > it.m_pos.y + it.m_size.y)/* && (pPlayer->m_pos.y + pPlayer->m_speed.y > it.m_pos.y + it.m_size.y)*/) {
						//下方向すり抜けobjの上より、プレイヤーの頭上位置のほうが下になったら回復
						pPlayer->m_concentration += it.m_concentration;
						it.m_concentration = 0;
						if (pPlayer->m_concentration > 10) {
							pPlayer->m_concentration = 10;
						}
						Effect::searchSet(pEffectManager->m_ppEffect, EFF_OBJ_MAX_NUM, Vector3(pPlayer->m_pos.x, it.m_initPos.y + it.m_size.y, 0.0f), pPlayer->m_liveInPagination, effectRecoveryPassed, 0);
						MFAudioPlay(SE_SPLASH);
					}
					else if (pPlayer->m_speed.y < 0.0f) {
						it.hitAdjust(pPlayer);
					}
				}

				if (it.m_type != M_TYPE::HIGH_CONCENTRATION && it.m_type != M_TYPE::NONE
					&& (it.m_type < M_TYPE::DOOR_1_1 || it.m_type > M_TYPE::KEY_5_1)&& it.m_type != M_TYPE::PASSABLE_UP && it.m_type != M_TYPE::PASSABLE_DOWN
					&& (pPlayer->m_concentration <= it.m_concentration/*it.m_concentration > LOW_CONCENTRATION || pPlayer->m_concentration > LOW_CONCENTRATION*/))
				{
					it.hitAdjust(pPlayer);
				}


				if (it.m_type == M_TYPE::HIGH_CONCENTRATION)
				{
					pPlayer->m_isDamaged = true;
					/*if (pPlayer->m_concentration < it.m_concentration)
					{
					pPlayer->m_mode = P_MODE::RESTART;
					}*/
				}

				if (it.m_type == M_TYPE::RECOVERY) {
					/*if (pPlayer->m_concentration <= (P_CONCENTRATION_MAX - it.m_concentration)) {
						pPlayer->m_concentration += it.m_concentration;
						it.clear();
					}
					else{
						it.m_concentration -= (P_CONCENTRATION_MAX - pPlayer->m_concentration);
						pPlayer->m_concentration = 10.0f;
					}*/
					MFAudioPlay(SE_START);
					pPlayer->m_concentration = 10.0f;
					it.clear();
				}


				// 鍵関係
				if (it.m_type >= M_TYPE::DOOR_1_1 && it.m_type <= M_TYPE::KEY_5_1)
				{
					if (it.m_type % 2 != 0) {
						// KEY
						if (!pPlayer->m_isKeyHandled){
							pPlayer->m_isKeyHandled = true;
							//pPlayer->m_pKeyObj->m_pSprData = it.m_pSprData;
							//pPlayer->m_pKeyObj->m_pos = it.m_pos;
							//pPlayer->m_pKeyObj->m_type = it.m_type;
							pPlayer->m_pKeyObj[pPlayer->m_keyCounter] = it;
							++pPlayer->m_keyCounter;
							it.m_isHitAble = false;
							it.m_concentration = /*LOW_CONCENTRATION*/0;
							//Effect::searchSet(pEffectManager->m_ppEffect, EFF_OBJ_MAX_NUM, it.m_pos, pPlayer->m_liveInPagination, effectGoal, it.m_keyType, false, true);
							MFAudioPlay(SE_KEY_GOT);
						}
					}
					else{
						// DOOR
						if (pPlayer->m_isKeyHandled && pPlayer->m_pKeyObj[pPlayer->m_keyCounter - 1].m_type == it.m_type + 1)
						{
							pPlayer->m_isKeyHandled = false;
							//pPlayer->m_pKeyObj.m_pSprData = it.m_pSprData;
							//pPlayer->m_pKeyObj->m_pSprData = nullptr;
							//pPlayer->m_pKeyObj->m_pos = it.m_pos;
							pPlayer->m_pKeyObj[pPlayer->m_keyCounter - 1].m_liveInPagination = it.m_liveInPagination;
							pPlayer->m_pKeyObj[pPlayer->m_keyCounter - 1].m_setPos = it.m_pos;
							//pPlayer->m_pKeyObj[pPlayer->m_keyCounter - 1].m_setPos.z = it.m_initPos.y - it.m_pos.y;
							pPlayer->m_pKeyObj[pPlayer->m_keyCounter - 1].m_initPos = it.m_initPos;
							pPlayer->m_pKeyObj[pPlayer->m_keyCounter - 1].m_isHitAble = false;
							pPlayer->m_pKeyObj[pPlayer->m_keyCounter - 1].m_timer = 0;
							//pPlayer->m_pKeyObj[pPlayer->m_keyCounter - 1].m_pos = it.m_pos;
							it.m_isHitAble = false;
							it.m_concentration = P_CONCENTRATION_MAX;
							if (pPlayer->m_keyCounter == STAGE_KEY_NUM) {
								pPlayer->m_mode = P_MODE::CLEAR;
								if (pPlayer->m_pBorder)
								{
									pPlayer->m_pBorder->m_step = STEP::INIT;
									pPlayer->m_pBorder->m_doReverseMove = true;
									pPlayer->m_pBorder = nullptr;
								}
							}
							Effect::searchSet(pEffectManager->m_ppEffect, EFF_OBJ_MAX_NUM, it.m_initPos, pPlayer->m_liveInPagination, effectGoal, it.m_keyType);
							MFAudioPlay(SE_DOOR_OPENED);
						}
						// Stage Clear Judge
						//isStageCleared &= !it.m_isHitAble;

					}
				}
			}

			if (isBookClosed && it.m_isHitAble && checkHitPlayerToMapObjClosed(pPlayer, &it))
			{
				// 
				//if ((pPlayer->m_concentration < it.m_concentration || pPlayer->m_concentration < LOW_CONCENTRATION) && it.m_concentration > LOW_CONCENTRATION)
				// プレイヤーの濃度より高いObjは転写できない
				if (pPlayer->m_concentration <= it.m_concentration && 
					((it.m_type < M_TYPE::DOOR_1_1 || it.m_type > M_TYPE::KEY_5_1) && it.m_type != M_TYPE::HIGH_CONCENTRATION &&
						it.m_type != M_TYPE::PASSABLE_UP && it.m_type != M_TYPE::PASSABLE_DOWN && it.m_type !=M_TYPE::RECOVERY))
				{
					pPlayerManager->m_isTranscriptAble = false;
					//break;
				}
			}

		}

		// 転写元判定
		//if (isBookOpened)
		//{
		//	for (auto &it : pObjManager->m_transcriptionList) {

		//		if (pPlayer->m_liveInPagination == it.m_liveInPagination && checkObjOpened(pPlayer, &(it)) && it.m_concentration > 0)
		//		{
		//			// TODO : 関数化

		//			if (pPlayer->m_concentration < P_CONCENTRATION_MAX)
		//			{
		//				if (it.m_concentration + pPlayer->m_concentration > P_CONCENTRATION_MAX)
		//				{
		//					it.m_concentration -= P_CONCENTRATION_MAX - pPlayer->m_concentration;
		//					pPlayer->m_concentration = P_CONCENTRATION_MAX;
		//				}
		//				else
		//				{
		//					pPlayer->m_concentration += it.m_concentration;
		//					it.m_concentration = 0;
		//				}

		//				pPlayer->m_alpha = 255 * pPlayer->m_concentration / P_CONCENTRATION_MAX;
		//				it.m_alpha = 255 * it.m_concentration / P_CONCENTRATION_MAX;
		//			}
		//			break;
		//		}
		//	}
		//}


		// 滲んだとこと判定
		pPlayer->m_isOnBlurArea = false;
		if (isBookOpened)
		{
			for (auto &it : *pBlurList) {

				if (it.m_isHitAble && checkObjOpened(pPlayer, &(it)))
				{
					pPlayer->m_isOnBlurArea = true;
					break;
				}
			}
		}


		// 被ってる滲むObjは作らない
		bool isRepeated = false;
		for (auto &newIt : pPlayer->m_newblurAreaList) {
			isRepeated = false;
			for (auto &it : *pBlurList) {

				if (checkObjOpened(&newIt, &(it)))
				{
					isRepeated = true;
					break;
				}
			}
			if (!isRepeated)
			{
				pPlayer->m_concentration -= P_BLUR_SPEED;
				pBlurList->push_back(newIt);
			}
		}
		pPlayer->m_newblurAreaList.clear();
	}


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