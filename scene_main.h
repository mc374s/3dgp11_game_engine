#ifndef _SCENE_MAIN_H_
#define _SCENE_MAIN_H_

class SceneMain :public Scene, public Singleton<SceneMain>
{
private:
	SpaceOBJ2D m_bg;
	Book *m_pBook;
	View *m_pViewLeftPage;
	View *m_pViewRightPage;

	Scene *m_pIncudeScene;

	bool m_isPlayerLeft = true;

	float m_bookRotateAngle = 0;
	XMFLOAT3 m_bookPostion = { 0,0,0 };
	
public:
	SceneMain();
	~SceneMain();
	void update();
	void draw();

	/*void enterScene(Scene* a_pNextScene) {
		a_pNextScene->m_pNextScene = nullptr;
		a_pNextScene->init();
		m_pNextScene = a_pNextScene;
	};*/
};


#define SCENE_MAIN (SceneMain::getInstance())

#endif // !_SCENE_MAIN_H_
