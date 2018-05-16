#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "obj2d.h"

#define P_SPEED_AX		(0.5)
#define P_SPEED_X_MAX	(5)

#define GRIVATY			(1)
#define P_SPEED_Y_MAX	(16)
#define P_JUMP_POWER	(-16)
#define P_JUMP_MAX_NUM	(1)

enum P_MODE
{
	MODE_NORMAL,
};

enum P_STATE
{
	P_STATE_ON_GROUND,
	P_STATE_JUMPING,
	P_STATE_DROPPING,
};

class Player:public OBJ2DEX
{
private:

public:

	int m_command;
	int m_mode;
	int m_state;

	Player();
	~Player();
	void update();
	void draw();

	void normalMove();

};

class PlayerManager:public Singleton<PlayerManager>, public Manager
{
private:

public:
	PlayerManager() {};
	~PlayerManager() {};

	Player *m_pPlayer = nullptr;

	void init();
	void transcriptPlayer();


};

#define pPlayerManager (PlayerManager::getInstance())



#endif // !_PLAYER_H_
