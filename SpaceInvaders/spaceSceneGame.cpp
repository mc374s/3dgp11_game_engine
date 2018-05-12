//******************************************************************************
//
//
//		ゲーム本体
//
//
//******************************************************************************

// インクルード
#include "../Game.h"
#include <iostream>


void pause_init();
bool pause();
void pause_draw();

// 変数宣言

//******************************************************************************
//
//		初期設定
//
//******************************************************************************

// 初期設定
void SpaceSceneGame::init()
{
	Scene::init();				// 基底クラスのinit関数呼び出しに変更
	str_game = nullptr;
	pause_init();
}

//******************************************************************************
//
//		更新処理
//
//******************************************************************************

// 更新処理
void SpaceSceneGame::update()
{
	command = getInputKey();
	MFAudioCheckLoops();

	// ソフトリセット
	/*if ((command & PAD_START) && (command & PAD_SELECT)) {
		changeScene(SCENE_TITLE_SPACE);
		return;
	}*/

	if (command & PAD_ENTER) {
		changeScene(SCENE_TITLE_SPACE);
		return;
	}

	// ポーズ処理
	if (pause()) return;

	switch (m_state) {
	case 0:			// ゲーム初期設定

		// 初期設定
		stageNo = 0;
		score_init();

		//init()
		pPlayerManager->init();
		pEffectManager->init();

		m_state++;
		//break;
	case 1:			// ステージ初期設定
		
		//init()
		pEnemyManager->init(stageNo);
		pBarrierManager->init();

		m_timer = 0;
		m_state++;
		//break;
	case 2:			// ゲーム本編

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

	case 3:			// ゲームオーバーへの切り替え
		

		// 5秒経過したらゲームタイトルへ切り替え
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
//		描画処理
//
//******************************************************************************

// 描画処理
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
//		ポーズ処理
//
//******************************************************************************


bool		pause_fg;

//------------------------------------------------------------------------------

// ポーズ初期設定
void pause_init()
{
	pause_fg = false;
}

// ポーズ処理
bool pause()
{
	if (command & PAD_START) pause_fg = !pause_fg;
	
	return pause_fg;
}

// ポーズ描画
void pause_draw()
{
	drawString(VIEW_WIDTH / 2, 180, (pause_fg) ? "PAUSE" : "", COLOR_WHITE, STR_CENTER, 32, 32);		// PAUSE M
}

//******************************************************************************
//
//		スコア関連
//
//******************************************************************************

int score;
int rank[RANKS_MAX] = { 0 };

//------------------------------------------------------------------------------

// スコア初期化
void score_init()
{
	score = 0;
	//saveData("DATA\\saveData.dat", score);
	loadData("DATA\\saveData.dat", rank);
}

// スコア加算
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

// スコア表示
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
