#include "game.h"
#include "sprite_data.h"
#include "book.h"

#include "scene_title.h"
#include "page_left.h"
#include "page_right.h"
#include "map_obj.h"
#include "judge.h"

#include "game_ui.h"
#include "player.h"

#include "scene_main.h"

SceneMain::SceneMain()
{
	//init();

	m_pBook = new Book(PAGE_WIDTH, PAGE_HEIGHT, 20, 10, 0, 10, 40, 8);
	m_pViewLeftPage = new View(PAGE_WIDTH, PAGE_HEIGHT);
	m_pViewRightPage = new View(PAGE_WIDTH, PAGE_HEIGHT);

	m_bg.m_pSprData = &e_sprMainBG;
	//m_bg.m_pos = { SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2,0 };
	m_childrenSceneNO = 0;

	m_pChildrenScene[0] = PAGE_LEFT;
	m_pChildrenScene[1] = PAGE_RIGHT;

	pObjManager->init();
	pMapObjManager->init(0);

	pGameUIManager->init();

	m_pStr = "";

}

void SceneMain::init()
{

	Scene::init();
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
	switch (m_state)
	{
	case STATE_INIT:
		//init();
		pObjManager->init();
		//pMapObjManager->init(0);
		m_state = STATE_BEGIN;
		//break;
	case STATE_BEGIN:
		m_pBook->update();
		m_isBookClosed = m_pBook->m_isClosed;
		m_isBookOpened = m_pBook->m_isOpened;
		updateChildScenes();

		pMapObjManager->stageUpdate();
		if (pPlayerManager->m_pPlayer->m_isOnScrollArea && m_isBookOpened)
		{
			pMapObjManager->setScroll(pPlayerManager->m_pPlayer->m_speed, pPlayerManager->m_pPlayer->m_isOnLeftPage);
		}

		judgeAll();

		if (pPlayerManager->m_pPlayer->m_mode == MODE_CLEAR)
		{
			m_pStr = "GAME CLEAR";
			m_timer++;
			if (m_timer > 120)
			{
				//m_state = STATE_INIT;
				//changeScene(SCENE_TITLE);
			}
		}

		if (pPlayerManager->m_pPlayer->m_mode == MODE_DEAD)
		{

			m_pStr = "GAME OVER";
			m_timer++;
			if (m_timer > 120)
			{
				m_state = STATE_END;
			}
		}

		break;
	case STATE_END:


		break;
	default:
		break;
	}

	if (GetAsyncKeyState(VK_HOME) & 0xF000)
	{
		m_state = STATE_INIT;
		changeScene(SCENE_TITLE);
	}


	
	
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

	pGameUIManager->draw();

#ifdef DEBUG

	drawString(SCREEN_WIDTH / 2, 100, m_pStr, COLOR_YELLOW >> 8 << 8 | 0x80, STR_CENTER, 80, 80);
	drawString(0, 0, "Click [HOME] to SCENE_TITLE", COLOR_RED >> 8 << 8 | 0x80, STR_LEFT, 32, 32);
	char buf[256];

	//sprintf_s(buf, "m_cameraDistance: %f", m_pBook->m_cameraDistance);
	//drawString(0, 400, buf);

#endif // DEBUG


}

void SceneMain::updateChildScenes()
{
	// Update page's scene
	for (int i = 0; i < CHILDREN_SCENE_MAX; i++)
	{
		if (m_pChildrenScene[i] && m_pBook->m_isOpened)
		{
			m_pChildrenScene[i]->update();
			if (m_pChildrenScene[i]->m_pNextScene)
			{
				m_pChildrenScene[i] = m_pChildrenScene[i]->m_pNextScene;
				m_pChildrenScene[i]->update();
			}
		}
	}


	// View Update
	// Left Side
	m_pViewLeftPage->m_custom3d.angleYawPitchRoll.x = m_pBook->m_openAngle;
	// Right Side
	m_pViewRightPage->m_custom3d.angleYawPitchRoll.x = -m_pBook->m_openAngle;

	// 本とTargetViewの位置を同調かねて座標系の違いによる
	m_pViewLeftPage->m_custom3d.position = m_pBook->m_postion;
	m_pViewLeftPage->m_custom3d.position.y = -m_pBook->m_postion.y;
	//m_pViewLeftPage->m_custom3d.position.z -= 0.1;
	// Right Side
	m_pViewRightPage->m_custom3d.position = m_pBook->m_postion;
	m_pViewRightPage->m_custom3d.position.y = -m_pBook->m_postion.y;
	//m_pViewRightPage->m_custom3d.position.z -= 0.1;
	// bucause of the depth test is ON, set a different depth between page surface and view
	m_pViewRightPage->m_custom3d.position.z = m_pViewLeftPage->m_custom3d.position.z -= 0.1;
}