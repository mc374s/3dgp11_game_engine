#ifndef _SCENE_MAIN_H_
#define _SCENE_MAIN_H_

#define CHILDREN_SCENE_MAX (2)
enum CHILDREN_NO
{
	CHILD_LEFT,
	CHILD_RIGHT,
};

class SceneMain :public Scene, public Singleton<SceneMain>
{
private:
	OBJ2D m_bg;
	Book *m_pBook;
	View *m_pViewLeftPage;
	View *m_pViewRightPage;

	Scene *m_pChildrenScene[2];

	bool m_isPlayerOnLeftPage = true;

	float m_bookRotateAngle = 0;
	XMFLOAT3 m_bookPostion = { 0,0,0 };
	
public:
	SceneMain();
	~SceneMain();

	int m_childrenSceneNO;

	void update();
	void draw();
};


#define SCENE_MAIN (SceneMain::getInstance())

#endif // !_SCENE_MAIN_H_
