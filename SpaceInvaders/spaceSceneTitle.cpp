//******************************************************************************
//
//
//		�^�C�g��
//
//
//******************************************************************************

// �C���N���[�h
#include "../Game.h"

//******************************************************************************
//
//		�����ݒ�
//
//******************************************************************************

//void loadTextureProgress()
//{
//	pTextureManager->loadTexture(load_texture);		// 2D�摜�̈ꊇ���[�h
//}
//void loadAudioProgress()
//{
//	pMFAudioManager->loadAudios(audio_data);			// �����f�[�^�̈ꊇ���[�h
//}

// �����ݒ�
 SpaceSceneTitle::SpaceSceneTitle()
 {
	 Scene::init();

	 // �f�[�^���[�h
	// //pTextureManager->loadTexture(load_texture);		// 2D�摜�̈ꊇ���[�h
	// std::thread loadThread_1(loadTextureProgress);
	// loadThread_1.detach();
	// /*std::thread loadThread_2(loadAudioProgress);
	// loadThread_2.detach();*/
	//// pMFAudioManager->loadAudios(audio_data);
 }

//******************************************************************************
//
//		�X�V����
//
//******************************************************************************

// �X�V����
void SpaceSceneTitle::update()
{
	command = getInputKey();
	MFAudioCheckLoops();

	switch (m_state) {
	case 0:
		
		m_timer = 0;
		bg.data = &spr_background_title;
		MFAudioPlay(BGM_TITLE, true);
		m_state++;
		//break;
	case 1:
		m_timer++;

		if (command & PAD_START)
		{
			//stopAudio(BGM_TITLE);
			changeScene(SCENE_GAME_SPACE);
		}
		if (command & PAD_TRG2)
		{
			MFAudioStop(BGM_TITLE);
		}
		if (command & PAD_TRG3)
		{
			MFAudioPlay(BGM_TITLE, true);
		}
		if (command & PAD_TRG4)
		{
			//loadAudio(SE_KILLED, audio_data[SE_KILLED].fileName);
			MFAudioPlay(SE_KILLED, false);
		}

		break;
	}
}

//******************************************************************************
//
//		�`�揈��
//
//******************************************************************************

// �`�揈��
void SpaceSceneTitle::draw()
{

	bg.draw();
	char buf[128];
	drawString(VIEW_WIDTH / 2, 80, "S P A C E", COLOR_WHITE, STR_CENTER, 64, 64);//L
	drawString(VIEW_WIDTH / 2, 160, "INVADERS", COLOR_WHITE, STR_CENTER, 64, 64);//L
	drawString(VIEW_WIDTH / 2, 240, "WHITE", COLOR_WHITE, STR_CENTER, 64, 64);//L
	
	if (m_timer & 0x20) drawString(VIEW_WIDTH / 2, 400, "PRESS [SPACE] TO START", COLOR_YELLOW,STR_CENTER);//M
	sprintf_s(buf, "PRESS[Z] TO SHOT\n[%c][%c] TO MOVE\n[C] TO DEBUG \nIN GAMING", 27, 26);
	drawString(VIEW_WIDTH / 2, 500, buf, COLOR_WHITE, STR_CENTER);//M
	drawString(VIEW_WIDTH / 2, 720, "PRESS [X] TO STOP BACKGROUNDMUSIC", COLOR_CYAN, STR_CENTER);//M
	drawString(20, 830, "This game \"SPACE INVADERS WHITE\" is a pastiche of Taito Corporation's \"Space Invaders\".\nAll rights reserved by Taito Corporation.", COLOR_GRAY, STR_LEFT, 16, 16);//S
	drawString(20, 880, "All sounds are free from www.classicgaming.cc/classics/space-invaders \n\n2018 Jan", COLOR_GRAY, STR_LEFT, 16, 16);//S

	//sprintf_s(buf, "timer:%d", timer);
	//drawString(0, 0, buf, COLOR_WHITE);//M
}

//******************************************************************************
