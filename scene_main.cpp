#include "Game.h"

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

	PAGE_LEFT->activePlayer(m_isPlayerOnLeftPage);
	m_isPlayerOnLeftPage = !m_isPlayerOnLeftPage;
	PAGE_RIGHT->activePlayer(m_isPlayerOnLeftPage);
	pPlayerManager->player->m_pos.x = PAGE_WIDTH - pPlayerManager->player->m_pos.x;

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
	if (GetAsyncKeyState('Z') < 0) {
		PAGE_LEFT->activePlayer(m_isPlayerOnLeftPage);
		m_isPlayerOnLeftPage = !m_isPlayerOnLeftPage;
		PAGE_RIGHT->activePlayer(m_isPlayerOnLeftPage);
		pPlayerManager->player->m_pos.x = PAGE_WIDTH - pPlayerManager->player->m_pos.x;
	}

	if (GetAsyncKeyState(VK_HOME) & 0xF000)
	{
		changeScene(SCENE_TITLE);
	}
	// Update page's scene
	for (int i = 0; i < CHILDREN_SCENE_MAX; i++)
	{
		if (m_pChildrenScene[i])
		{
			m_pChildrenScene[i]->update();
			if (m_pChildrenScene[i]->m_pNextScene)
			{
				m_pChildrenScene[i] = m_pChildrenScene[i]->m_pNextScene;
				m_pChildrenScene[i]->update();
			}
		}
	}

	static float aXY = 0.0f, aZY = 0.0f;
	static float d = 0.65f;
	// Change Book and Views' Angle
	if (GetAsyncKeyState('8') & 0xF000) {
		m_bookRotateAngle += 1;
		aZY += 0.01f;
		m_bookPostion.z -= 5;
		m_bookPostion.y -= 3;
		if (m_bookRotateAngle > 0) {
			m_bookRotateAngle = 0;
			aZY = 0.0f;
			m_bookPostion.z = 0;
			m_bookPostion.y = 0;
		}
	}
	if (GetAsyncKeyState('7') & 0xF000) {
		if (m_bookRotateAngle > -90) {
			m_bookRotateAngle -= 1;
			aZY -= 0.01f;
			m_bookPostion.z += 5;
			m_bookPostion.y += 3;
		}
		if (m_bookRotateAngle == -90) {
			m_bookRotateAngle -= 1;
			aZY = -0.90f;
			m_bookPostion.z = 450;
			m_bookPostion.y = 270;


			PAGE_LEFT->activePlayer(m_isPlayerOnLeftPage);
			m_isPlayerOnLeftPage = !m_isPlayerOnLeftPage;
			PAGE_RIGHT->activePlayer(m_isPlayerOnLeftPage);
			pPlayerManager->player->m_pos.x = PAGE_WIDTH - pPlayerManager->player->m_pos.x;
		}
	}

	e_camera.upDirection = { sinf(aZY)*sinf(aXY), cosf(aZY), sinf(aZY)*cosf(aXY), 0 };
	e_camera.eyePosition = { -fabs(d)*cosf(aZY)*sinf(aXY), fabs(d)*sinf(aZY)/* + 310 / (float)SCREEN_WIDTH*/, -fabs(d)*cosf(aZY)*cosf(aXY),0 };

	// Left Size
	m_pBook->m_pBookLeft->m_custom3d.angleYawPitchRoll.x	= m_bookRotateAngle;
	m_pBook->m_pCoverLeft->m_custom3d.angleYawPitchRoll.x	= m_bookRotateAngle;
	m_pViewLeftPage->m_custom3d.angleYawPitchRoll.x			= m_bookRotateAngle;
	// Right Side
	m_pBook->m_pBookRight->m_custom3d.angleYawPitchRoll.x	= -m_bookRotateAngle;
	m_pBook->m_pCoverRight->m_custom3d.angleYawPitchRoll.x	= -m_bookRotateAngle;
	m_pViewRightPage->m_custom3d.angleYawPitchRoll.x		= -m_bookRotateAngle;

	m_pBook->m_pBookLeft->m_custom3d.position= m_bookPostion;
	m_pBook->m_pCoverLeft->m_custom3d.position = m_bookPostion;
	m_pViewLeftPage->m_custom3d.position = m_bookPostion;
	m_pViewLeftPage->m_custom3d.position.y = -m_bookPostion.y;
	m_pViewLeftPage->m_custom3d.position.z -= 0.1;
	// Right Side
	m_pBook->m_pBookRight->m_custom3d.position = m_bookPostion;
	m_pBook->m_pCoverRight->m_custom3d.position = m_bookPostion;
	m_pViewRightPage->m_custom3d.position = m_bookPostion;
	m_pViewRightPage->m_custom3d.position.y = -m_bookPostion.y;
	m_pViewRightPage->m_custom3d.position.z -= 0.1;

	// bucause of the depth test is ON, set a different depth between page surface and view
	//m_pViewRightPage->m_custom3d.position.z = m_pViewLeftPage->m_custom3d.position.z = -0.1;
	
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
	drawString(SCREEN_WIDTH / 2, 100, "M A I N", COLOR_YELLOW, STR_CENTER, 80, 80);
	drawString(0, 0, "Click [HOME] to SCENE_TITLE", COLOR_RED, STR_LEFT, 32, 32);
	drawString(0, 40, "Press [1] to Right View", COLOR_GREEN, STR_LEFT, 24, 24);
	drawString(0, 70, "Press [4] to Slanting View", COLOR_GREEN, STR_LEFT, 24, 24);
	drawString(0, 110, "Press [7] to CLOSE Book", COLOR_YELLOW, STR_LEFT, 32, 32);
	drawString(0, 150, "Press [8] to OPEN Book", COLOR_YELLOW, STR_LEFT, 32, 32);

}