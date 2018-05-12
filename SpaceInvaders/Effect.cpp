#include "../Game.h"

void EffectManager::init()
{
	for (int i = 0; i < EFFECT_MAX; i++)
	{
		if (pEffect[i])
		{
			delete pEffect[i];
			pEffect[i] = nullptr;
		}
		pEffect[i] = new SpaceOBJ2D();
	}
}

void EffectManager::update()
{
	for (int i = 0; i < EFFECT_MAX; i++)
	{
		if (pEffect[i]->move)
		{
			pEffect[i]->move(pEffect[i]);
		}
	}
}

void EffectManager::draw()
{
	for (int i = 0; i < EFFECT_MAX; i++)
	{
		if (pEffect[i]->data)
		{
			pEffect[i]->draw();
		}
		else if (pEffect[i]->state == 2)
		{
			
			char buf[32];
			sprintf_s(buf, 32, "%d", pEffect[i]->hp);
			drawString(pEffect[i]->pos.x - 20, pEffect[i]->pos.y - 20, buf);//m
			
		}
	}
}

void enemyExplosion(SpaceOBJ2D* obj)
{
	switch (obj->state)
	{
	case 0:
		obj->move = enemyExplosion;
		obj->data = spr_explosion[obj->type];

		//obj->hp mean score
		switch (obj->type)
		{
		case ENEMY_B:
			obj->hp = 30;
			break;
		case ENEMY_UFO:
			obj->hp = (rand() % 6 + 1) * 50;
			break;
		case ENEMY_A:
			obj->hp = 20;
			break;
		case ENEMY_C:
			obj->hp = 10;
			break;
		default:
			obj->hp = 0;
			break;
		}
		obj->state++;
		//break;
	case 1:
		obj->timer++;
		if (obj->timer > 40)
		{
			obj->timer = 0;
			if (obj->type != ENEMY_UFO)
			{
				score_add(obj->hp);
				obj->clear();
			}
			else
			{
				obj->data = nullptr;
				obj->state++;
			}
		}
		break;
	case 2:
		obj->timer++;
		if (obj->timer > 40)
		{
			score_add(obj->hp);
			obj->clear();
		}
	default:
		break;
	}
}