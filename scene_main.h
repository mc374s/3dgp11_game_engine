#ifndef _SCENE_MAIN_H_
#define _SCENE_MAIN_H_

#define CHILDREN_SCENE_MAX (2)
enum CHILDREN_NO
{
	CHILD_LEFT,
	CHILD_RIGHT,
};

class OBJ2D;
class Book;

class SceneMain :public Scene, public Singleton<SceneMain>
{
private:
	OBJ2D* m_pBG;
	Book *m_pBook;
	char *m_pStr;


	bool m_isPlayerOnLeftPage = true;

	
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
