#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "obj2d.h"

#define P_SPEED_AX			(0.5)
#define P_SPEED_X_MAX		(3.5)

#define P_BLUR_SPEED							(0.012)
#define P_BLUR_SPEED_ON_BLUR_AREA				(0.006)
#define P_BLUR_SPEED_ON_HIGT_CONCENTRATION_AREA	(0.006)

#define GRIVATY				(0.20f)
#define P_SPEED_Y_MAX		(12)
#define P_JUMP_POWER		(-5)

#define P_JUMP_MAX_NUM	(1)

#define P_LIFE_MAX		(4)

#define P_SCROLL_Y_TOP		(200)
#define P_SCROLL_Y_BOTTOM	(430)

// Player Update Mode
enum P_MODE
{
	START,
	RESTART,
	NORMAL,
	CLEAR,
	DEAD,
};

// Player State
enum P_STATE
{
	STANDBY,
	JUMPING,
	DROPPING,
	MOVING,
};

class Player:public OBJ2DEX
{
private:
	int m_life;

public:

	int m_command;
	int m_mode;
	int m_montionState;
	int m_transferConcentration;
	bool m_isOnGround;
	bool m_isMoving;
	bool m_isOnBlurArea;
	bool m_isOnScrollArea;

	bool m_isKeyHandled;
	OBJ2D* m_keyObj;

	Vector3 m_scrolledDistance;
	float m_blurSpeed;
	Vector3 m_setPos;


	Player();
	~Player();

	void init();
	void update();
	void draw();

	void restart();

	int getLife();
	void addLife(int a_life);

	void blur();

	void normalMove();
	void restartMove();

};

class PlayerManager:public Singleton<PlayerManager>, public Manager
{
private:
	//int m_transferConcentration = 0;
public:
	PlayerManager();
	~PlayerManager();

	Player *m_pPlayer = nullptr;
	bool m_isPlayerOnLeft;
	bool m_isTranscriptAble = true;
	bool m_isTranscriptCanceled = false;

	void init();
	void transcriptPlayer(int a_concentration = 1);
	void manageConcentration();

	int m_concentration = 10;

};

#define pPlayerManager (PlayerManager::getInstance())



#endif // !_PLAYER_H_
