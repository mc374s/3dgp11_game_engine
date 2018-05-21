#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "obj2d.h"

#define P_SPEED_AX			(0.5)
#define P_SPEED_X_MAX		(5)
#define P_SPEED_AX_BLUR		(0.7)
#define P_SPEED_X_MAX_BLUR	(5)

#define GRIVATY				(0.15)
#define P_SPEED_Y_MAX		(12)
#define P_JUMP_POWER		(-16)

#define P_SPEED_Y_MAX_BLUR	(18)
#define P_JUMP_POWER_BLUR	(-18)

#define P_JUMP_MAX_NUM	(1)

#define P_CONCENTRATION_DECREASE_FRAME	(100)

#define P_LIFE_MAX		(4)

#define P_SCROLL_Y_TOP		(200)
#define P_SCROLL_Y_BOTTOM	(330)

enum P_MODE
{
	P_MODE_NORMAL,
	P_MODE_CLEAR,
	P_MODE_DEAD,
	P_MODE_INIT,
};

enum P_STATE
{
	P_STATE_STANDY,
	P_STATE_JUMPING,
	P_STATE_DROPPING,
	P_STATE_MOVING,
};

class Player:public OBJ2DEX
{
private:

public:

	int m_command;
	int m_mode;
	int m_montionState;
	//int m_concentration;
	int m_transferConcentration;
	bool m_isOnGround;
	bool m_isMoving;
	bool m_isOnBlurArea;
	bool m_isOnScrollArea;

	bool m_isKeyHandled;
	OBJ2D m_keyObj;

	Vector3 m_initPos;

	Player();
	~Player();
	void init();
	void update();
	void draw();

	static int m_life;
	static int getLife();
	void setLife(int a_life);
	
	void normalMove();
	void initMove();

};

class PlayerManager:public Singleton<PlayerManager>, public Manager
{
private:
	//int m_transferConcentration = 0;
public:
	PlayerManager() { init(); };
	~PlayerManager() {};

	Player *m_pPlayer = nullptr;
	bool m_isTranscriptAble = true;
	bool m_isTranscriptCanceled = false;

	void init();
	void transcriptPlayer(int a_concentration = 1);
	void manageConcentration();

	int m_concentration = 10;

	Vector3 getMapScroll();

};

#define pPlayerManager (PlayerManager::getInstance())



#endif // !_PLAYER_H_
