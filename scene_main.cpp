#include "game.h"
#include "sprite_data.h"
#include "book.h"

#include "scene_title.h"
#include "page_left.h"
#include "page_right.h"

#include "scene_main.h"

SceneMain::SceneMain()
{
	Scene::init();

	m_bg.m_pSprData = &e_sprMainBG;
	//m_bg.m_pos = { SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2,0 };
	
	m_pBook = new Book(PAGE_WIDTH, PAGE_HEIGHT, 20, 10, 0, 10, 40, 8);
	m_pViewLeftPage = new View(PAGE_WIDTH, PAGE_HEIGHT);
	m_pViewRightPage = new View(PAGE_WIDTH, PAGE_HEIGHT);
	m_childrenSceneNO = 0;

	m_pChildrenScene[0] = PAGE_LEFT;
	m_pChildrenScene[1] = PAGE_RIGHT;

	pObjManager->init();

}
SceneMain::~SceneMain()
{
	if (m_pNextScene)
	{
		//delete nextScene;
		m_pNextScene = nullptr;
	}
	SAFE_DELETE(m_pBook);
	SAFE_DELETE(m_pViewLeftPage);
	SAFE_DELETE(m_pViewRightPage);
};

void SceneMain::update()
{	
	if (GetAsyncKeyState(VK_HOME) & 0xF000)
	{
		changeScene(SCENE_TITLE);
	}
	// Update page's scene
	for (int i = 0; i < CHILDREN_SCENE_MAX; i++)
	{
		if (m_pChildrenScene[i] && m_pBook->m_openAngle == 0)
		{
			m_pChildrenScene[i]->update();
			if (m_pChildrenScene[i]->m_pNextScene)
			{
				m_pChildrenScene[i] = m_pChildrenScene[i]->m_pNextScene;
				m_pChildrenScene[i]->update();
			}
		}
	}

	m_pBook->update();

	// Left Side
	m_pViewLeftPage->m_custom3d.angleYawPitchRoll.x			= m_pBook->m_openAngle;
	// Right Side
	m_pViewRightPage->m_custom3d.angleYawPitchRoll.x		= -m_pBook->m_openAngle;

	// –{‚ÆTargetView‚ÌˆÊ’u‚ð“¯’²‚©‚Ë‚ÄÀ•WŒn‚Ìˆá‚¢‚É‚æ‚é
	m_pViewLeftPage->m_custom3d.position	= m_pBook->m_postion;
	m_pViewLeftPage->m_custom3d.position.y	= -m_pBook->m_postion.y;
	//m_pViewLeftPage->m_custom3d.position.z -= 0.1;
	// Right Side
	m_pViewRightPage->m_custom3d.position	= m_pBook->m_postion;
	m_pViewRightPage->m_custom3d.position.y = -m_pBook->m_postion.y;
	//m_pViewRightPage->m_custom3d.position.z -= 0.1;
	// bucause of the depth test is ON, set a different depth between page surface and view
	m_pViewRightPage->m_custom3d.position.z = m_pViewLeftPage->m_custom3d.position.z -= 0.1;
	
}

void SceneMain::draw()
{
	View::clear();

	m_bg.draw();

	m_pBook->draw();

	// Draw Left Scene
	m_pViewLeftPage->set(-PAGE_WIDTH, -PAGE_HEIGHT / 2, PAGE_WIDTH, PAGE_HEIGHT, 0, 0, PAGE_WIDTH, PAGE_HEIGHT);
	
	if (m_pChildrenScene[CHILD_LEFT]){
		m_pChildrenScene[CHILD_LEFT]->draw();
	}
	View::clear();

	// Draw Right Scene
	m_pViewRightPage->set(0, -PAGE_HEIGHT / 2, PAGE_WIDTH, PAGE_HEIGHT, 0, 0, PAGE_WIDTH, PAGE_HEIGHT);
	if (m_pChildrenScene[CHILD_RIGHT]){
		m_pChildrenScene[CHILD_RIGHT]->draw();
	}
	View::clear();

	drawString(SCREEN_WIDTH / 2, 100, "M A I N", COLOR_YELLOW >> 8 << 8 | 0x80, STR_CENTER, 80, 80);
	drawString(0, 0, "Click [HOME] to SCENE_TITLE", COLOR_RED >> 8 << 8 | 0x80, STR_LEFT, 32, 32);
	char buf[256];
	sprintf_s(buf, "m_cameraDistance: %f", m_pBook->m_cameraDistance);
	drawString(0, 400, buf);

}