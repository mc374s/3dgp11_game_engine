#ifndef _SCENE_MAIN_H_
#define _SCENE_MAIN_H_


class OBJ2D;

class SceneMain :public Scene, public Singleton<SceneMain>
{
private:
	OBJ2D* m_pBG;
	int m_stageNO;
	int m_selectedStageNO;

	bool m_isPlayerOnLeftPage = true;
	bool m_stageClearFlag[STAGE_LIMITTED_NUM];
	bool m_isPaused = false;
	int m_selectionNO;
	
public:
	SceneMain();
	~SceneMain();

	bool m_isBookOpened;
	bool m_isBookClosed;

	void init();
	void update();
	void draw();

	bool pause();
	void gameMain();
	//void stageSelection();
	void turnPagesController();
	void viewMode();
	void endViewMode();
};


#define SCENE_MAIN (SceneMain::getInstance())

#endif // !_SCENE_MAIN_H_
