#include "Game.h"

void loadTextureProgress()
{
	pTextureManager->loadTexture(load_texture);		// 2D画像の一括ロード
}
void loadAudioProgress()
{
	pMFAudioManager->loadAudios(audio_data);			// 音声データの一括ロード
}

SceneTitle::SceneTitle()
{
	Scene::init();
	//pTextureManager->loadTexture(load_texture);		// 2D画像の一括ロード
	std::thread loadThread_1(loadTextureProgress);
	loadThread_1.detach();
	/*std::thread loadThread_2(loadAudioProgress);
	loadThread_2.detach();*/
	// pMFAudioManager->loadAudios(audio_data);

	m_bg.data = &e_sprN64;
	m_bg.pos = { SCREEN_WIDTH / 2,SCREEN_HEIGHT / 2,0 };
	
}

void SceneTitle::update()
{
	if (getInputKey() == PAD_START)
	{
		changeScene(SCENE_MAIN);
	}
}

void SceneTitle::draw()
{
	View::clear();

	m_bg.draw();
	drawString(SCREEN_WIDTH / 2, 100, "T I T L E", COLOR_YELLOW, STR_CENTER, 80, 80);
	drawString(0, 0, "Click [SPACE] to SCENE_MAIN", COLOR_RED, STR_LEFT, 32, 32);
	
}