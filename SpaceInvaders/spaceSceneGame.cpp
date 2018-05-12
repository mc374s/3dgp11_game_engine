//******************************************************************************
//
//
//		�Q�[���{��
//
//
//******************************************************************************

// �C���N���[�h
#include "../Game.h"
#include <iostream>


void pause_init();
bool pause();
void pause_draw();

// �ϐ��錾

//******************************************************************************
//
//		�����ݒ�
//
//******************************************************************************

// �����ݒ�
void SpaceSceneGame::init()
{
	Scene::init();				// ���N���X��init�֐��Ăяo���ɕύX
	str_game = nullptr;
	pause_init();
}

//******************************************************************************
//
//		�X�V����
//
//******************************************************************************

// �X�V����
void SpaceSceneGame::update()
{
	command = getInputKey();
	MFAudioCheckLoops();

	// �\�t�g���Z�b�g
	/*if ((command & PAD_START) && (command & PAD_SELECT)) {
		changeScene(SCENE_TITLE_SPACE);
		return;
	}*/

	if (command & PAD_ENTER) {
		changeScene(SCENE_TITLE_SPACE);
		return;
	}

	// �|�[�Y����
	if (pause()) return;

	switch (m_state) {
	case 0:			// �Q�[�������ݒ�

		// �����ݒ�
		stageNo = 0;
		score_init();

		//init()
		pPlayerManager->init();
		pEffectManager->init();

		m_state++;
		//break;
	case 1:			// �X�e�[�W�����ݒ�
		
		//init()
		pEnemyManager->init(stageNo);
		pBarrierManager->init();

		m_timer = 0;
		m_state++;
		//break;
	case 2:			// �Q�[���{��

		//update()
		pPlayerManager->update();
		pEnemyManager->update();
		pEffectManager->update();
		pBarrierManager->update();
		Judge();
		//BGM_Check();
		if (!pPlayerManager->isAlive())
		{
			m_timer = 0;
			m_state++;
		}
		// clear stage
		if (pEnemyManager->move_state == 2)
		{
			// reset stage
			stageNo++;
			m_state = 1;
		}
		break;

	case 3:			// �Q�[���I�[�o�[�ւ̐؂�ւ�
		

		// 5�b�o�߂�����Q�[���^�C�g���֐؂�ւ�
		m_timer++;
		str_game = (m_timer & 0x20) ? "GAME OVER" : "";
		if (m_timer > 5 * 60) changeScene(SCENE_TITLE_SPACE);
		break;
	default:
		break;
	}
}

//******************************************************************************
//
//		�`�揈��
//
//******************************************************************************

// �`�揈��
void SpaceSceneGame::draw()
{

	//draw()
	spr_background.draw(Vector3(0, 0, 0));

	pEnemyManager->draw();
	pPlayerManager->draw();
	pEffectManager->draw();
	pBarrierManager->draw();

	drawRectangle(0, GROUND_HEIGHT, VIEW_WIDTH, 3, 0, COLOR_RED);

	drawString(VIEW_WIDTH / 2, 360, str_game, COLOR_RED, STR_CENTER, 64, 64);  // GAME OVER L

	score_draw();
	pause_draw();
}

//******************************************************************************
//******************************************************************************
//
//		�|�[�Y����
//
//******************************************************************************


bool		pause_fg;

//------------------------------------------------------------------------------

// �|�[�Y�����ݒ�
void pause_init()
{
	pause_fg = false;
}

// �|�[�Y����
bool pause()
{
	if (command & PAD_START) pause_fg = !pause_fg;
	
	return pause_fg;
}

// �|�[�Y�`��
void pause_draw()
{
	drawString(VIEW_WIDTH / 2, 180, (pause_fg) ? "PAUSE" : "", COLOR_WHITE, STR_CENTER, 32, 32);		// PAUSE M
}

//******************************************************************************
//
//		�X�R�A�֘A
//
//******************************************************************************

int score;
int rank[RANKS_MAX] = { 0 };

//------------------------------------------------------------------------------

// �X�R�A������
void score_init()
{
	score = 0;
	//saveData("DATA\\saveData.dat", score);
	loadData("DATA\\saveData.dat", rank);
}

// �X�R�A���Z
void score_add(int add)
{
	score += add;
	if (score > 99999999) score = 99999999;
	if (score > rank[0])
	{
		saveData("DATA\\saveData.dat", score);
		loadData("DATA\\saveData.dat", rank);
	}
}

// �X�R�A�\��
void score_draw()
{
	char	buf[256];
	sprintf_s(buf, 256, "SCORE %-8d", score);
	drawString(0, 8, buf);//M

	sprintf_s(buf, 256, "HI-SCORE %-8d", rank[0]);
	drawString(VIEW_WIDTH / 2, 8, buf, COLOR_CYAN, STR_CENTER);//M

	drawString(700, VIEW_HEIGHT - 30, "PRESS [ENTER] RETURN TO TITLE", COLOR_WHITE, STR_CENTER, 16, 16);//S
}

//******************************************************************************
