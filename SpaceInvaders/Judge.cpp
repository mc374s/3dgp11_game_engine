#include "../Game.h"

void Judge()
{
	for (int i = 0; i < P_SHOT_MAX; i++)
	{
		for (int j = 0; j < ENEMY_MAXY; j++)
		{
			for (int k = 0; k < ENEMY_MAXX; k++)
			{
				if (checkRectAB(pShotManager->pPShot[i], pEnemyManager->pEnemy[j][k]))
				{
					pShotManager->pPShot[i]->clear();
					SpaceOBJ2D::searchSet(enemyExplosion, pEnemyManager->pEnemy[j][k]->pos, pEffectManager->pEffect, EFFECT_MAX, pEnemyManager->pEnemy[j][k]->type);
					MFAudioPlay(SE_KILLED);
					pEnemyManager->pEnemy[j][k]->clear();
					//score_add(20);
					break;
				}
			}
		}
		if (pEnemyManager->pUFO->data && checkRectAB(pShotManager->pPShot[i], pEnemyManager->pUFO))
		{
			pShotManager->pPShot[i]->clear();
			SpaceOBJ2D::searchSet(enemyExplosion, pEnemyManager->pUFO->pos, pEffectManager->pEffect, EFFECT_MAX, pEnemyManager->pUFO->type);
			MFAudioPlay(SE_UFO1);
			pEnemyManager->pUFO->clear();
			//score_add((rand() % 6 + 1) * 50);
			break;
		}
		for (int n = 0; n < BARRIER_NUM; n++)
		{
			for (int y = 0; y < BARRIER_MAXY; y++)
			{
				for (int x = 0; x < BARRIER_MAXX; x++)
				{
					if (pBarrierManager->pBarrier[n][y][x]->data && checkRect2Barrier(pShotManager->pPShot[i], pBarrierManager->pBarrier[n][y][x]))
					{
						//pBarrierManager->pBarrier[n][y][x]->clear();
						pBarrierManager->explosion(n, y, x);
						pShotManager->pPShot[i]->clear();
						break;
					}
				}
			}
		}
	}


	for (int i = 0; i < E_SHOT_MAX; i++)
	{
		for (int j = 0; j < P_SHOT_MAX; j++)
		{
			if (checkRectAB(pShotManager->pEShot[i], pShotManager->pPShot[j]))
			{
				pShotManager->pEShot[i]->clear();
				SpaceOBJ2D::searchSet(enemyExplosion, pShotManager->pPShot[j]->pos, pEffectManager->pEffect, EFFECT_MAX,ENEMY_SHOT);
				MFAudioPlay(SE_KILLED);
				pShotManager->pPShot[j]->clear();
				break;
			}
		}
		if (checkRectAB(pShotManager->pEShot[i], pPlayerManager->pSpacePlayer))
		{
			pShotManager->pEShot[i]->clear();
			SpaceOBJ2D::searchSet(enemyExplosion, pPlayerManager->pSpacePlayer->pos, pEffectManager->pEffect, EFFECT_MAX);
			MFAudioPlay(SE_EXPLOSION);
			pPlayerManager->subHP();
			break;
		}
		for (int n = 0; n < BARRIER_NUM; n++)
		{
			for (int y = 0; y < BARRIER_MAXY; y++)
			{
				for (int x = 0; x < BARRIER_MAXX; x++)
				{
					if (pBarrierManager->pBarrier[n][y][x]->data && checkRect2Barrier(pShotManager->pEShot[i], pBarrierManager->pBarrier[n][y][x]))
					{
						//pBarrierManager->pBarrier[n][y][x]->clear();
						SpaceOBJ2D::searchSet(enemyExplosion, pShotManager->pEShot[i]->pos, pEffectManager->pEffect, EFFECT_MAX, ENEMY_SHOT);
						pBarrierManager->explosion(n, y, x);
						pShotManager->pEShot[i]->clear();
						break;
					}
				}
			}
		}
	}
}

bool checkRectAB(SpaceOBJ2D* _A, SpaceOBJ2D* _B)
{
	return CheckHitRectCenter(_A->pos.x, _A->pos.y, _A->size.x, _A->size.y, _B->pos.x, _B->pos.y, _B->size.x, _B->size.y);
}

bool checkRect2Barrier(SpaceOBJ2D* _A, Barrier* _B)
{
	return CheckHitRectCenter(_A->pos.x, _A->pos.y, _A->size.x, _A->size.y, _B->pos.x, _B->pos.y, _B->size.x, _B->size.y);
}

bool CheckHitRectCenter(float ax, float ay, int aw, int ah, float bx, float by, int bw, int bh)
{
	float al = ax - aw / 2;		//•¨‘ÌA‚Ì¶’[(Left)
	float ar = ax + aw / 2;
	float au = ay - ah / 2;
	float ad = ay + ah / 2;

	float bl = bx - bw / 2;		//•¨‘ÌB‚Ì¶’[(Left)
	float br = bx + bw / 2;
	float bu = by - bh / 2;
	float bd = by + bh / 2;

	//“–‚½‚Á‚Ä‚¢‚È‚¢ğŒ
	if (aw <= 0 || ah <= 0 || bw <= 0 || bh <= 0)
	{
		return  false;
	}
	if (al>br)
	{
		return false;
	}
	if (ar<bl)
	{
		return false;
	}
	if (au>bd)
	{
		return false;
	}
	if (ad<bu)
	{
		return false;
	}
	return true;
}