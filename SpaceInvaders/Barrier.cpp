#include "../Game.h"

BarrierManager::~BarrierManager()
{
	for (int i = 0; i < BARRIER_NUM; i++)
	{
		for (int j = 0; j < BARRIER_MAXY; j++)
		{
			for (int k = 0; k < BARRIER_MAXX; k++)
			{
				if (pBarrier[i][j][k])
				{
					delete pBarrier[i][j][k];
				}
			}
		}
	}

}

void BarrierManager::init()
{
	for (int i = 0; i < BARRIER_NUM; i++)
	{
		for (int j = 0; j < BARRIER_MAXY; j++)
		{
			for (int k = 0; k < BARRIER_MAXX; k++)
			{
				if (pBarrier[i][j][k])
				{
					delete pBarrier[i][j][k];
					pBarrier[i][j][k] = nullptr;
				}
				pBarrier[i][j][k] = new Barrier();
				if (barrierData[j][k])
				{
					pBarrier[i][j][k]->data = &spr_green00;
					pBarrier[i][j][k]->size = Vector3(pBarrier[i][j][k]->data->width, pBarrier[i][j][k]->data->height, 0);
				}

				pBarrier[i][j][k]->pos = Vector3(i * 220 + 70 + k*spr_green00.width, 700 + j*spr_green00.height, 0);
			}
		}
	}

}

void BarrierManager::update()
{

}

void BarrierManager::draw()
{
	for (int i = 0; i < BARRIER_NUM; i++)
	{
		for (int j = 0; j < BARRIER_MAXY; j++)
		{
			for (int k = 0; k < BARRIER_MAXX; k++)
			{
				if (pBarrier[i][j][k]->data)
				{
					pBarrier[i][j][k]->draw();
				}
			}
		}
	}
}

void BarrierManager::explosion(int _num, int _y, int _x)
{
	int n, y, x;
	n = _num;
	y = _y - 2 > 0 ? _y - 2 : 0;
	x = _x - 2 > 0 ? _x - 2 : 0;
	for (int j = y; j < BARRIER_MAXY &&j < _y + 3; j++)
	{
		for (int k = x; k < BARRIER_MAXX && k < _x + 3; k++)
		{
			int temp = rand() % 4;
			if (temp >= fabs(y-_y)-1 || temp >= fabs(x - _x)-1)
			{
				pBarrier[n][j][k]->clear();

			}
		}
	}
}