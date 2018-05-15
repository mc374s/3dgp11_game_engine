#ifndef _PLAYER_H_
#define _PLAYER_H_

#define P_SPEED_AX		(0.5)
#define P_SPEED_X_MAX	(5)

#define GRIVATY			(1)
#define P_SPEED_Y_MAX	(4)
#define P_JUMP_POWER	(-6)


enum P_MODE
{
	MODE_NORMAL,
};

class Player:public OBJ2DEX
{
private:

public:

	int m_command;
	int m_mode;

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
