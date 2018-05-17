#ifndef _SCENE_MAIN_H_
#define _SCENE_MAIN_H_

#include "obj2d.h"

#define CHILDREN_SCENE_MAX (2)
enum CHILDREN_NO
{
	CHILD_LEFT,
	CHILD_RIGHT,
};

class Book;

class SceneMain :public Scene, public Singleton<SceneMain>
{
private:
	OBJ2D m_bg;
	Book *m_pBook;
	View *m_pViewLeftPage;
	View *m_pViewRightPage;

	Scene *m_pChildrenScene[2];

	bool m_isPlayerOnLeftPage = true;

	
public:
	SceneMain();
	~SceneMain();

	int m_childrenSceneNO;
	bool m_isBookOpened;
	bool m_isBookClosed;

	void update();
	void draw();
	
	void updateChildScenes();
};


#define SCENE_MAIN (SceneMain::getInstance())

#endif // !_SCENE_MAIN_H_
