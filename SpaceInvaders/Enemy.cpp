#include "../Game.h"

void EnemyManager::init(int _stageNo)
{
	x = 0;
	y = ENEMY_MAXY - 1;
	timer = 0;
	anime = 0x1;
	move_state = 0;
	shot_state = 0;
	shot_timer = 0;
	wall_fg = false;
	mx = ENEMY_SPEEDX;
	my = 0;
	if (_stageNo > ENEMY_DOWN_MAX_NUM)
	{
		_stageNo = ENEMY_DOWN_MAX_NUM;
	}
	for (int i = 0; i < ENEMY_MAXY; i++)
	{
		for (int j = 0; j < ENEMY_MAXX; j++)
		{
			if (pEnemy[i][j])
			{
				delete pEnemy[i][j];
				pEnemy[i][j] = nullptr;
			}
			pEnemy[i][j] = new SpaceOBJ2D();

			switch (i)
			{
			case 0:
				pEnemy[i][j]->type = ENEMY_B;
				break;
			case 1:
			case 2:
				pEnemy[i][j]->type = ENEMY_A;
				break;
			case 3:
			case 4:
				pEnemy[i][j]->type = ENEMY_C;
			default:
				break;
			}
			pEnemy[i][j]->pos = Vector3(j*CHIP_SIZE + ENEMY_INIT_ADJUSTX, (i + _stageNo)*CHIP_SIZE + ENEMY_INIT_ADJUSTY, 0);
		}
	}
	if (pTemp != nullptr)
	{
		delete pTemp;
		pTemp = nullptr;
	}
	pTemp = new SpaceOBJ2D();

	if (!pUFO || _stageNo == 0)
	{
		if (!pUFO)
		{
			pUFO = new SpaceOBJ2D();
		}
	}
	disLeft = CHIP_SIZE + ENEMY_INIT_ADJUSTX;
	disTop = CHIP_SIZE + ENEMY_INIT_ADJUSTY;
}

void EnemyManager::update()
{
	if (move_state > 0)
	{
		engageShot();
	}
	moveEnemy();
	moveUFO();

}

void EnemyManager::draw()
{
	for (int i = 0; i < ENEMY_MAXY; i++)
	{
		for (int j = 0; j < ENEMY_MAXX; j++)
		{
			if (pEnemy[i][j] && pEnemy[i][j]->data)
			{
				pEnemy[i][j]->draw();
			}
		}
	}
	if (pUFO && pUFO->data)
	{
		pUFO->draw();
	}
	if (pTemp && pTemp->data)
	{
		pTemp->draw();
	}
}

EnemyManager::~EnemyManager()
{
	for (int i = 0; i < ENEMY_MAXY; i++)
	{
		for (int j = 0; j < ENEMY_MAXX; j++)
		{
			if (pEnemy[i][j])
			{
				delete pEnemy[i][j];
				pEnemy[i][j] = nullptr;
			}
		}
	}
	delete pUFO;
	pUFO = nullptr;
	delete pTemp;
	pTemp = nullptr;
}


void EnemyManager::moveEnemy()
{
	switch (move_state)
	{
	case 0:
		MFAudioPlay(SE_MOVE2);
		pEnemy[y][x]->data = spr_enemy[pEnemy[y][x]->type][0];
		pEnemy[y][x]->size = Vector3(pEnemy[y][x]->data->width, pEnemy[y][x]->data->height, 0);
		x++;
		if (x >= ENEMY_MAXX)
		{
			x = 0;
			y--;
			if (y < 0)
			{
				y = ENEMY_MAXY - 1;
				timer = 0;
				move_state++;
			}
		}
		break;
	case 1:

		if (command & PAD_TRG3)
		{
			clear2LastEnemy();
		}
		pTemp->clear();
		pEnemy[y][x]->pos.x += mx;
		if (pEnemy[y][x]->pos.x + mx > VIEW_WIDTH - pEnemy[y][x]->size.x / 2.0f || pEnemy[y][x]->pos.x + mx < pEnemy[y][x]->size.x / 2.0f)
		{
			wall_fg = true;
		}
		if (pEnemy[y][x]->pos.y + my > ENEMY_DAWN_MAXY)
		{
			my = 0;
		}
		if (my != 0)
		{
			//*pTemp = *pEnemy[y][x];
		}
		pEnemy[y][x]->pos.y += my;
		if (pEnemy[y][x]->data)
		{
			pEnemy[y][x]->data = spr_enemy[pEnemy[y][x]->type][anime];
		}

		do
		{
			x++;
			if (x >= ENEMY_MAXX)
			{
				x = 0;
				y--;
				if (y < 0)
				{
					y = ENEMY_MAXY - 1;
					anime ^= 0x1;
					anime ? MFAudioPlay(SE_MOVE1) : MFAudioPlay(SE_MOVE2);
					if (isAlive())
					{
						if (wall_fg)
						{
							mx = -mx;
							my = ENEMY_SPEEDY;
							wall_fg = false;
						}
						else
						{
							my = 0;
						}

					}
					else
					{
						// stage clear
						pPlayerManager->addHP();
						move_state++;
						break;
					}
				}
			}
		} while (!pEnemy[y][x]->data);
		
		break;
	case 2:
		// do something
		break;
	default:
		break;
	}
}

bool EnemyManager::isAlive()
{
	for (int i = 0; i < ENEMY_MAXY; i++)
	{
		for (int j = 0; j < ENEMY_MAXX; j++)
		{
			if (pEnemy[i][j]->data)
			{
				return true;
			}
		}
	}
	return false;
}

void EnemyManager::clear2LastEnemy()
{
	bool last_fg = false;
	for (int i = 0; i < ENEMY_MAXY; i++)
	{
		for (int j = 0; j < ENEMY_MAXX; j++)
		{
			if (pEnemy[i][j]->data && !last_fg)
			{
				last_fg = true;
				x = j;
				y = i;
			}
			else
			{
				pEnemy[i][j]->clear();
			}
		}
	}
}

void EnemyManager::engageShot()
{
	int rx, ry;
	switch (shot_state)
	{
	case 0:
		rx = rand() % ENEMY_MAXX;
		ry = rand() % ENEMY_MAXY;
		if (pEnemy[ry][rx]->data && ((pEnemy[ry][rx]->pos.x < pPlayerManager->pSpacePlayer->pos.x + 200 && pEnemy[ry][rx]->pos.x > pPlayerManager->pSpacePlayer->pos.x - 200) || rand() % 10 > 8))
		{
			SpaceOBJ2D::searchSet(normalEShot, pEnemy[ry][rx]->pos, pShotManager->pEShot, E_SHOT_MAX, pEnemy[ry][rx]->type);
		}
		shot_state++;
		shot_timer = 0;
		//break;

	case 1:
		shot_timer++;
		if (shot_timer > 4)
		{
			shot_state--;
		}
		break;
	default:
		break;
	}

}

void EnemyManager::moveUFO()
{
	switch (pUFO->state)
	{
	case 0:
		pUFO->timer++;
		if (pUFO->timer > 10 * 60)
		{
			pUFO->state++;
		}
		break;
	case 1:
		pUFO->data = &spr_ufo00;
		pUFO->size = Vector3(pUFO->data->width, pUFO->data->height, 0);
		pUFO->pos = Vector3(VIEW_WIDTH + pUFO->size.x, 60, 0);
		pUFO->type = ENEMY_UFO;
		pUFO->speed.x = -4;
		pUFO->timer = 0;
		pUFO->state++;
		//break;
	case 2:
		pUFO->timer++;
		if (pUFO->timer % 11 == 10)
		{
			MFAudioPlay(SE_UFO2);
		}
		pUFO->pos.x += pUFO->speed.x;
		if (pUFO->pos.x < 0 - pUFO->size.x)
		{
			pUFO->clear();
		}
		break;
	default:
		break;
	}
}