#ifndef _GAME_UI_H_
#define _GAME_UI_H_

class GameUI:public OBJ2DEX
{
private:

public:
	GameUI();
	~GameUI();

	void(*m_pfMove)(GameUI*);

	void init();
	void update();
	void draw();

};



#endif // !_GAME_UI_H_
