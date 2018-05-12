#ifndef _SPACESCENETITLE_H_
#define	_SPACESCENETITLE_H_

#include <thread>

// SceneTitleƒNƒ‰ƒX‚Ì’è‹`
class SpaceSceneTitle :public Scene, public Singleton<SpaceSceneTitle>
{
private:
	SpaceOBJ2D bg;
public:
	SpaceSceneTitle();
	~SpaceSceneTitle() {
		if (m_pNextScene)
		{
			//delete nextScene;
			m_pNextScene = nullptr;
		}
	};
	void update();
	void draw();

};


#define SCENE_TITLE_SPACE (SpaceSceneTitle::getInstance())

#endif // !_SPACESCENETITLE_H_
