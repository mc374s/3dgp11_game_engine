#ifndef _SCENE_MAIN_H_
#define _SCENE_MAIN_H_

#define CHILDREN_SCENE_MAX (2)
enum CHILDREN_NO
{
	CHILD_LEFT,
	CHILD_RIGHT,
};

class OBJ2D;

class SceneMain :public Scene, public Singleton<SceneMain>
{
private:
	OBJ2D* m_pBG;
	char *m_pStr;
	int m_stageNO;

	bool m_isPlayerOnLeftPage = true;

	bool m_isPaused = false;
	int m_pausedOption;
	
public:
	SceneMain();
	~SceneMain();

	bool m_isBookOpened;
	bool m_isBookClosed;

	void init();
	void update();
	void draw();
};


#define SCENE_MAIN (SceneMain::getInstance())

#endif // !_SCENE_MAIN_H_
