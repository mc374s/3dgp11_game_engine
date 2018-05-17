#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "obj2d.h"

#define P_SPEED_AX		(0.5)
#define P_SPEED_X_MAX	(5)

#define GRIVATY			(1)
#define P_SPEED_Y_MAX	(16)
#define P_JUMP_POWER	(-16)
#define P_JUMP_MAX_NUM	(1)


#define P_CONCENTRATION_MAX_NUM			(10)
#define P_CONCENTRATION_DECREASE_SPEED	(80)

#define P_LIFE_MAX		(4)

enum P_MODE
{
	MODE_NORMAL,
	MODE_DAMAGE
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
	int m_life;
public:

	int m_command;
	int m_mode;
	int m_state;
	int m_concentration;
	int m_transferConcentration;
	bool m_isOnGround;

	Player();
	~Player();
	void init();
	void update();
	void draw();

	int getLife();
	void setLife(int a_life);
	
	void normalMove();

};

class PlayerManager:public Singleton<PlayerManager>, public Manager
{
private:
	//int m_transferConcentration = 0;
public:
	PlayerManager() { init(); };
	~PlayerManager() {};

	Player *m_pPlayer = nullptr;
	bool m_isTranscriptAble;

	void init();
	void transcriptPlayer(int a_concentration = 1);
	void manageConcentration();

	int m_concentration = 10;
	int m_transferConcentration = 0;
	int m_transfer;


};

#define pPlayerManager (PlayerManager::getInstance())



#endif // !_PLAYER_H_
