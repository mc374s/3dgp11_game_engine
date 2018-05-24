#include "game.h"
#include "sprite_data.h"
#include "sound_data.h"
#include "scene_main.h"

#include "scene_title.h"



#include <thread>

void loadTextureProgress()
{
	pTextureManager->loadTexture(e_loadTexture);		// 2D画像の一括ロード
}
void loadAudioProgress()
{
	pMFAudioManager->loadAudios(audio_data);			// 音声データの一括ロード
}

SceneTitle::SceneTitle()
{
	Scene::init();
	//pTextureManager->loadTexture(e_loadTexture);		// 2D画像の一括ロード
	std::thread loadThread_1(loadTextureProgress);
	loadThread_1.detach();
	/*std::thread loadThread_2(loadAudioProgress);
	loadThread_2.detach();*/
	//pMFAudioManager->loadAudios(audio_data);

	//m_bg.m_pos = { SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2,0 };

	//pObjManager->init();
	//pPlayerManager->init();
	//pPlayerManager->m_pPlayerTsuta->m_isOnLeftPage = false;
	
}

void SceneTitle::update()
{
	switch (m_step) {
	case 0:
		m_bg.m_pSprData = &e_sprTitleBG;

		MFAudioPlay(BGM_TITLE, true);
		m_step++;
		//break;

	case 1:
		if (KEY_BOARD.Space)
		{
			MFAudioStop(BGM_TITLE);
			changeScene(SCENE_MAIN);
		}
	}
}

void SceneTitle::draw()
{
	View::clear();

	m_bg.draw();

	drawString(SCREEN_WIDTH / 2, 100, "T I T L E", COLOR_YELLOW, STR_CENTER, 80, 80);
	drawString(0, 0, "Click [SPACE] to SCENE_MAIN", COLOR_RED, STR_LEFT, 32, 32);
	
}