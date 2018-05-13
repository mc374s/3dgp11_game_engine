#ifndef _PLAYER_H_
#define _PLAYER_H_

#define P_SPEED_AX		(0.5)
#define P_SPEED_X_MAX	(5)

#define GRIVATY			(1)
#define P_SPEED_Y_MAX	(4)
#define P_JUMP_POWER	(-16)


enum P_MODE
{
	MODE_NORMAL,
	MODE_POSE,
};

class Player:public OBJ2DEX
{
private:

public:

	int m_command;
	int mode;

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
	Player *player = nullptr;

	void init() {
		if (!player)
		{
			player = new Player;
			pObjManager->m_pObj[OBJ2D::searchSet(pObjManager->m_pObj, OBJ_MAX_NUM)] = player;
		}
	};
	PlayerManager() {};
	~PlayerManager() {};

};

#define pPlayerManager (PlayerManager::getInstance())



#endif // !_PLAYER_H_
