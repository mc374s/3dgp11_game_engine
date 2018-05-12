#ifndef _PLAYER_H_
#define _PLAYER_H_

#define P_SPEED_X (6)

class SpacePlayer :public SpaceOBJ2D
{
private:

public:
	SpacePlayer();
	void Move();

};

class PlayerManager :public Singleton<PlayerManager>
{
private:

public:
	SpacePlayer* pSpacePlayer;
	void init();
	void update();
	void draw();
	PlayerManager() {};
	~PlayerManager() {
		delete pSpacePlayer; 
		pSpacePlayer = nullptr;
	};
	void addHP();
	void subHP();
	bool isAlive();
	void showHP();
};

#define pPlayerManager (PlayerManager::getInstance())

#endif // !_PLAYER_H_
