#ifndef _GAME_UI_H_
#define _GAME_UI_H_

#define UI_OBJ_MAX_NUM	(36)
#define UI_STAMP_MAX_NUM (5)

enum UI_NO
{
	GAGE_FRAME,
	GAGE_LEFT,
	GAGE_RIGHT,
};



class GameUI:public OBJ2DEX
{
private:

public:
	GameUI();
	~GameUI();

	bool m_isVisible;

	//void(*m_pfMove)(GameUI*);

	void init();
	void update();
	void draw();

};

class GameUIManager:public Singleton<GameUIManager>, public Manager
{
private:
	OBJ2D m_life_stamp[UI_STAMP_MAX_NUM];
	int m_life;

public:

	GameUIManager();
	~GameUIManager();

	GameUI* m_ppGameUI[UI_OBJ_MAX_NUM] = { nullptr };

	void init();
	void update();
	void draw();

	void setInkGage(int a_playerConcentration, int a_transferConcentration, bool a_isOnLeftPage, bool a_isTranscriptAble);
};

#define pGameUIManager	(GameUIManager::getInstance())



#endif // !_GAME_UI_H_
