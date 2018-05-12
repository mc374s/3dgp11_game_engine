#ifndef _BARRIER_H_
#define _BARRIER_H


#define BARRIER_NUM (4)

class Barrier
{
public:
	Vector3 pos;
	Vector3 size;
	SPRITE_DATA *data;
	Barrier() {
		clear();
	};

	~Barrier() {
		clear();
	};

	void clear() {
		pos = Vector3(0, 0, 0);
		size = Vector3(0, 0, 0);
		data = nullptr;
	};

	void draw() {
		if (data)
		{
			data->draw(pos);
		}
	};
};

class BarrierManager : public Singleton<BarrierManager>
{
public:
	Barrier* pBarrier[BARRIER_NUM][BARRIER_MAXY][BARRIER_MAXX];
	BarrierManager() {};
	~BarrierManager();
	void init();
	void update();
	void draw();

	void explosion(int _num, int _y, int _x);
};

#define pBarrierManager (BarrierManager::getInstance())


#endif // !_BARRIER_H_

