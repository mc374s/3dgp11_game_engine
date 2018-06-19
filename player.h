#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "obj2d.h"

#define P_SPEED_AX			(0.5f)
#define P_SPEED_X_MAX		(3.5f)

#define P_BLUR_SPEED							(0.005f)
#define P_BLUR_SPEED_ON_BLUR_AREA				(0.0f)
#define P_BLUR_SPEED_ON_HIGT_CONCENTRATION_AREA	(0.006f)

#define GRIVATY				(0.20f)
#define P_SPEED_Y_MAX		(10)
#define P_JUMP_POWER		(-2)

#define P_JUMP_MAX_NUM	(1)

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
	float m_transferConcentration;
	bool m_isOnGround;
	bool m_isMoving;
	bool m_isOnBlurArea;
	bool m_isOnScrollArea;
	bool m_isDamaged;
	int m_damageTimer;
	int m_jumpCounter;

	bool m_isKeyHandled;
	OBJ2D* m_keyObj;
	OBJ2D m_eyes;

	Vector3 m_scrolledDistance;
	Vector3 m_scrolledDistanceAdjust;
	float m_blurSpeed;
	Vector3 m_setPos;
	OBJ2D m_hitObj;
	std::vector<OBJ2D> m_newblurAreaList;

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
	void startMove();

};

class PlayerManager:public Singleton<PlayerManager>, public Manager
{
private:
	//int m_transferConcentration = 0;
public:
	PlayerManager();
	~PlayerManager();

	Player *m_pPlayer = nullptr;
	OBJ2D m_hitObj;
	OBJ2D m_transcriptionObj;
	bool m_isPlayerOnLeft;
	bool m_isTranscriptAble = true;
	bool m_isTranscriptCanceled = false;

	void transcriptPlayer(int a_concentration = 1);
	void manageConcentration();

	float m_concentration = P_CONCENTRATION_MAX;

	void init();
	void update();
	void draw(int a_liveInPagination = START_PAGINATION);

};

#define pPlayerManager (PlayerManager::getInstance())



#endif // !_PLAYER_H_
