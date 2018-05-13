#include "../Game.h"

using namespace SPACE_INVADERS;

SpacePlayer::SpacePlayer()
{
	clear();
	data = &spr_player00;
	pos = Vector3(0, 840, 0);
	size = Vector3(data->width - 20, data->height - 38, 0);
	speed.x = P_SPEED_X;
	hp = 2;
}

void SpacePlayer::Move()
{
	switch (command & (PAD_LEFT | PAD_RIGHT))
	{
	case PAD_LEFT:
		pos.x -= speed.x;
		break;
	case PAD_RIGHT:
		pos.x += speed.x;
		break;
	default:
		break;
	}

	if (pos.x < 0 + data->width / 2.0f)
	{
		pos.x = 0+ data->width / 2.0f;
	}
	if (pos.x > VIEW_WIDTH - data->width / 2.0f)
	{
		pos.x = VIEW_WIDTH - data->width / 2.0f;
	}

	if (command & PAD_TRG1)
	{
		if (SpaceOBJ2D::searchSet(normalPShot, pos, pShotManager->pPShot, P_SHOT_MAX)) 
		{
			MFAudioPlay(SE_SHOT);
		}
	}
}

void PlayerManager::init()
{
	if (pSpacePlayer)
	{
		delete pSpacePlayer;
		pSpacePlayer = nullptr;
	}
	pSpacePlayer = new SpacePlayer();
	pShotManager->Init();
	
}

void PlayerManager::update()
{
	pSpacePlayer->Move();
	pShotManager->Update();
}

void PlayerManager::draw()
{
	pShotManager->Draw();
	pSpacePlayer->draw();
	showHP();
}

void PlayerManager::addHP()
{
	if (pSpacePlayer->data)
	{
		if (pSpacePlayer->hp < 4)
		{
			pSpacePlayer->hp++;
		}
	}
}

void PlayerManager::subHP()
{
	if (pSpacePlayer->data)
	{
		if (pSpacePlayer->hp > 0)
		{
			pSpacePlayer->hp--;
		}
	}
}

bool PlayerManager::isAlive()
{
	if (pSpacePlayer->hp > 0)
	{
		return true;
	}
	else
	{
		pSpacePlayer->data = &spr_player01;
		return false;
	}
}

void PlayerManager::showHP()
{
	
	char	buf[256];
	sprintf_s(buf, 256, "%d", pSpacePlayer->hp);
	drawString(30, GROUND_HEIGHT + 30, buf);//m
	
	for (int i = 0; i < pSpacePlayer->hp - 1; i++)
	{
		spr_player00.draw(Vector3(i*spr_player00.width + 100, GROUND_HEIGHT + 40, 0));
	}
}