#ifndef _ENEMY_H_
#define _ENEMY_H_

#define ENEMY_MAXX (11)
#define ENEMY_MAXY (5)

#define CHIP_SIZE (70)
#define ENEMY_INIT_ADJUSTX (70)
#define ENEMY_INIT_ADJUSTY (100)
#define ENEMY_DOWN_MAX_NUM (4)
#define ENEMY_DAWN_MAXY (VIEW_HEIGHT - 150)
#define ENEMY_SPEEDX (16.0f)
#define ENEMY_SPEEDY (30)


class EnemyManager :public Singleton<EnemyManager>
{
private:
	SpaceOBJ2D* pTemp;
	int x, y;
	int timer;
	int anime;
	bool wall_fg;
	float mx, my;
	float disLeft, disTop;
	int shot_state;
	int shot_timer;

public:
	int move_state;
	SpaceOBJ2D* pEnemy[ENEMY_MAXY][ENEMY_MAXX];
	SpaceOBJ2D* pUFO;
	void init(int _stageNo = 0);
	void update();
	void draw();
	void moveEnemy();
	void engageShot();
	bool isAlive();
	void clear2LastEnemy();
	void moveUFO();

	EnemyManager() {};
	~EnemyManager();

};

#define pEnemyManager (EnemyManager::getInstance())

#endif // !_ENEMY_H_
