#ifndef _GAME_UI_H_
#define _GAME_UI_H_

#include "obj2d.h"

#define UI_OBJ_MAX_NUM	(36)
#define UI_STAMP_MAX_NUM (10)

enum UI_NO
{
	A_LEFT_PLAYER,		//A::Allocation
	A_RIGHT_PLAYER,		//A::Allocation
	A_LEFT_GAGE_UNDER,	//A::Allocation
	A_RIGHT_GAGE_UNDER,	//A::Allocation
	A_LEFT_GAGE,		//A::Allocation
	A_RIGHT_GAGE,		//A::Allocation
	A_LEFT_DIVISION,	//A::Allocation
	A_RIGHT_DIVISION,	//A::Allocation

	C_GAGE_UNDER,		//C::Concentration
	C_GAGE_ANIME,		//C::Concentration
	C_GAGE,				//C::Concentration
	C_PLAYER_FACE,		//C::Concentration
	C_DIVISION,			//C::Concentration

	STAMP,
	STAMP_MAX = STAMP + UI_STAMP_MAX_NUM,

	PAUSE_PANEL,
	PAUSE_SELECTED,


	HELP,
	HELP_BUTTON,

	X_BUTTON,

	SCROLL_MODE,

	STAGE_CLEAR_TEXT,
	GAME_CLEAR_TEXT,
	GAME_OVER_TEXT,

	STAGE_CLEAR_BEHIND,
	STAGE_CLEAR_FRONT,
	GAME_OVER_BEHIND,
	GAME_OVER_FRONT,

	STAGE_SELECTED,

	MAX_UI_NO,
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
	TO_GAME,
	TO_TITLE,
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

	void clear();
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

	GameUI* m_ppGameUI[MAX_UI_NO + 1] = { nullptr };
	Numbers* m_ppNumbers[MAX_NUMS_NO + 1];

	void init();
	void update();
	void draw();

	void showInkTransferGage(float a_playerConcentration, float a_transferConcentration, bool a_isOnLeftPage, bool a_isTranscriptAble, SPRITE_DATA* a_pPlayerSprData = nullptr, bool a_isRefect = true);
	void showPlayerConcentration(float a_playerConcentration, int a_playerLife, bool a_isDamaged = false, Vector3 a_pos = Vector3(0, 0, 0));
	void showPausePanel(int a_selectedNO = 0);
	void showHelpButton();
	void showXButton();
	void showScrollMode();
	void showStageSelected(int a_stageNO = 0, bool a_doReset = false);
};

#define pGameUIManager	(GameUIManager::getInstance())



#endif // !_GAME_UI_H_
