#include "../Game.h"

void ShotManager::Init()
{
	for (int i = 0; i < P_SHOT_MAX; i++)
	{
		if (pPShot[i])
		{
			delete pPShot[i];
			pPShot[i] = nullptr;
		}
		pPShot[i] = new SpaceOBJ2D();
	}

	for (int i = 0; i < E_SHOT_MAX; i++)
	{
		if (pEShot[i])
		{
			delete pEShot[i];
			pEShot[i] = nullptr;
		}
		pEShot[i] = new SpaceOBJ2D();
	}
}

void ShotManager::Update()
{
	for (int i = 0; i < P_SHOT_MAX; i++)
	{
		if (pPShot[i]->move)
		{
			pPShot[i]->move(pPShot[i]);
		}
	}

	for (int i = 0; i < E_SHOT_MAX; i++)
	{
		if (pEShot[i]->move)
		{
			pEShot[i]->move(pEShot[i]);
		}
	}
}

void ShotManager::Draw()
{
	for (int i = 0; i < P_SHOT_MAX; i++)
	{
		if (pPShot[i] && pPShot[i]->move)
		{
			pPShot[i]->draw();
		}
	}

	for (int i = 0; i < E_SHOT_MAX; i++)
	{
		if (pPShot[i] && pEShot[i]->move)
		{
			pEShot[i]->draw();
		}
	}
}


void normalPShot(SpaceOBJ2D *obj)
{
	switch (obj->state)
	{
	case 0:
		obj->move = normalPShot;
		obj->data = &spr_player_shot_a00;
		obj->size = Vector3(obj->data->width, obj->data->height, 0);
		obj->speed.y = -P_SHOT_SPEED;
		obj->state++;
		//break;
	case 1:
		obj->pos.y += obj->speed.y;
		if (obj->pos.y < 0)
		{
			obj->pos.y = 0;
			obj->state++;
		}
		break;
	case 2:
		obj->timer++;
		if (obj->timer > 30)
		{
			obj->clear();
		}
		break;
	default:
		break;
	}
}

void normalEShot(SpaceOBJ2D *obj)
{
	switch (obj->state)
	{
	case 0:
		obj->move = normalEShot;
		obj->data = spr_enemy_shot[obj->type];
		obj->size = Vector3(obj->data->width - 8, obj->data->height - 8, 0);
		obj->speed.y = E_SHOT_SPEED;
		obj->state++;
		//break;
	case 1:
		obj->pos.y += obj->speed.y;
		if (obj->pos.y > GROUND_HEIGHT)
		{
			obj->pos.y = GROUND_HEIGHT;
			obj->state++;
		}
		break;
	case 2:
		obj->timer++;
		if (obj->timer > 60)
		{
			obj->clear();
		}
		break;
	default:
		break;
	}
}