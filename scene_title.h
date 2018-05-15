#ifndef _SCENE_TITLE_H_
#define _SCENE_TITLE_H_

#include "obj2d.h"

// SceneTitleƒNƒ‰ƒX‚Ì’è‹`
class SceneTitle :public Scene, public Singleton<SceneTitle>
{
private:
	OBJ2D m_bg;
public:
	SceneTitle();
	~SceneTitle() {
		if (m_pNextScene)
		{
			//delete nextScene;
			m_pNextScene = nullptr;
		}
	};
	void update();
	void draw();

};


#define SCENE_TITLE (SceneTitle::getInstance())


#endif // !_SCENE_TITLE_H_
