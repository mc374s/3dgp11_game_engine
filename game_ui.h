#ifndef _GAME_UI_H_
#define _GAME_UI_H_

#include "obj2d.h"

#define UI_OBJ_MAX_NUM	(36)
#define UI_STAMP_MAX_NUM (5)

enum UI_NO
{
	GAGE_FRAME,
	GAGE_LEFT,
	GAGE_RIGHT,
	PLAYER_LEFT,
	PLAYER_RIGHT,
	PLAYER_CONCENTRATION,

	STAMP,
	STAMP_MAX = STAMP + UI_STAMP_MAX_NUM,

	PAUSE_PANEL,
	PAUSE_SELECTED,

	TEST_PLAY_TEXT,
};

enum NUMS_NO
{
	CURRENT_CONCENTRATION,
	LEFT_CONCENTRATION,
	RIGHT_CONCENTRATION,

	MAX_NUMS_NO,
};

enum PAUSED_SELECTION
{
	TO_TITLE,
	TO_GAME,
	MAX_PAUSED_SELECTION_NUM,
};

class Numbers;

class GameUI:public OBJ2DEX
{
private:

public:
	virtual void memberCopy(const GameUI& a_inputObj);
	GameUI();
	GameUI(const GameUI& a_inputObj);
	virtual ~GameUI();
	const GameUI& operator=(const GameUI& a_right);

	bool m_isVisibleAlways;
	bool m_isVisible;


	//void(*m_pfMove)(GameUI*);

	void init();
	void update();
	void draw();

};

class GameUIManager:public Singleton<GameUIManager>, public Manager
{
private:

public:

	GameUIManager();
	~GameUIManager();

	GameUI* m_ppGameUI[UI_OBJ_MAX_NUM] = { nullptr };
	Numbers* m_ppNumbers[MAX_NUMS_NO + 1];

	void init();
	void update();
	void draw();

	void showInkTransferGage(int a_playerConcentration, int a_transferConcentration, bool a_isOnLeftPage, bool a_isTranscriptAble);
	void showPlayerConcentration(int a_playerConcentration, Vector3 a_pos = Vector3(0, 0, 0));
	void showPlayerLife(int a_playerLife);
	void showPausePanel(int a_selectedNO = 0);
};

#define pGameUIManager	(GameUIManager::getInstance())



#endif // !_GAME_UI_H_
