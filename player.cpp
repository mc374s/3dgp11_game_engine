#include "game.h"
#include "sprite_data.h"
#include "game_ui.h"
#include "effect.h"

//#include <list>

#include "player.h"

Player::Player()
{
	OBJ2DEX::clear();
	init(); 
}

void Player::init()
{
	m_pAnimeData = e_pAnimePlayerYawn;
	//m_pAnimeData = e_pAnimePlayerJump;
	m_size = Vector3(60, 45, 4);
	m_command = 0x0;
	m_pos = { 80,140,5 };
	m_initPos = m_pos;
	m_scrolledDistance = { 0,0,0 };
	m_liveInPagination = 61;

	m_pSprData = &m_pAnimeData[0];
	m_step = STEP::INIT;
	m_mode = P_MODE::NORMAL;
	m_montionState = P_STATE::STANDBY;
	m_concentration = P_CONCENTRATION_MAX_NUM;
	m_alpha = 255;
	m_transferConcentration = 0;
	m_timer = 0;
	m_isOnBlurArea = false;
	m_isMoving = false;

	m_speed = { 0,0,0 };
	m_speedAcc = { P_SPEED_AX,P_JUMP_POWER,0 };
	m_speedMax = { P_SPEED_X_MAX,P_SPEED_Y_MAX,0 };
	m_isOnScrollArea = false;

	m_isOnGround = true;
	m_isKeyHandled = false;
	if (m_keyObj)
	{
		m_keyObj->clear();
	}
	else
	{

		m_keyObj = new OBJ2D;
	}
	m_life = P_LIFE_MAX;

	m_isInit = true;

}

Player::~Player()
{
	m_pAnimeData = nullptr;
	SAFE_DELETE(m_keyObj);
}

void Player::restart()
{
	m_pAnimeData = e_pAnimePlayerYawn;
	//m_pAnimeData = e_pAnimePlayerJump;
	m_size = Vector3(60, 45, 4);
	m_command = 0x0;
	m_pos = { 80,140,5 };
	m_initPos = m_pos;
	m_scrolledDistance = { 0,0,0 };
	m_liveInPagination = 61;

	m_pSprData = &m_pAnimeData[0];
	m_step = STEP::INIT;
	m_mode = P_MODE::NORMAL;
	m_montionState = P_STATE::STANDBY;
	m_concentration = P_CONCENTRATION_MAX_NUM;
	m_alpha = 255;
	m_transferConcentration = 0;
	m_timer = 0;
	m_isOnBlurArea = false;
	m_isMoving = false;
	if (!m_isKeyHandled)
	{
		m_keyObj->clear();
	}
	m_speed = { 0,0,0 };
	m_speedAcc = { P_SPEED_AX,P_JUMP_POWER,0 };
	m_speedMax = { P_SPEED_X_MAX,P_SPEED_Y_MAX,0 };
	m_isOnScrollArea = false;

	m_isInit = true;
}

void Player::normalMove()
{
	// input
	m_command = getInputKey();

	// 滲む範囲でのスピード入れ替え
	if (m_isOnBlurArea) {
		m_speedAcc.x = P_SPEED_AX_BLUR;
		m_speedAcc.y = P_JUMP_POWER_BLUR;
		m_speedMax.x = P_SPEED_X_MAX_BLUR;
		m_speedMax.y = P_SPEED_Y_MAX_BLUR;
	} else {
		m_speedAcc.x = P_SPEED_AX;
		m_speedAcc.y = P_JUMP_POWER;
		m_speedMax.x = P_SPEED_X_MAX;
		m_speedMax.y = P_SPEED_Y_MAX;
	}
	// 濃度計算：動いてるときに減っていく
	if (fabsf(m_speed.x - 0.0f) > FLT_EPSILON || fabsf(m_speed.y - 0.0f) > FLT_EPSILON)
	{
		m_timer++;
		if (m_timer > P_CONCENTRATION_DECREASE_FRAME)
		{
			m_timer = 0;
			m_concentration--;
			if (m_concentration < 1)
			{
				m_mode = P_MODE::RESTART;
			}
		}
		m_isMoving = true;
	}
	else
	{
		m_isMoving = false;
	}
	m_alpha = 255 * m_concentration / P_CONCENTRATION_MAX_NUM;

	// プレーヤーの状態判断
	if (fabsf(m_speed.y - 0.0f) < FLT_EPSILON && m_montionState != P_STATE::JUMPING && !m_isOnGround)
	{
		m_isOnGround = true;
	}
	if (m_speed.y < 0)
	{
		m_montionState = P_STATE::JUMPING;
		m_isOnGround = false;
	}
	if (m_speed.y > 0)
	{
		m_montionState = P_STATE::DROPPING;
		m_isOnGround = false;
	}
	// X方向移動
	switch (m_command & (PAD_LEFT | PAD_RIGHT))
	{
	case PAD_LEFT:
		m_speed.x -= m_speedAcc.x;
		m_custom.reflectX = false;
		break;
	case PAD_RIGHT:
		m_speed.x += m_speedAcc.x;
		m_custom.reflectX = true;
		break;
	default:
		if (m_speed.x > 0) {
			m_speed.x -= m_speedAcc.x / 2;
			if (m_speed.x < 0) m_speed.x = 0;
		}
		if (m_speed.x < 0) {
			m_speed.x += m_speedAcc.x / 2;
			if (m_speed.x > 0) m_speed.x = 0;
		}
		break;
	}

	// Y方向移動
	m_speed.y += GRIVATY;

	static int pressFrame = 0, chargeMaxFrame = 12, jumpCounter = 0;
	if ((m_command & PAD_TRG1) && (pressFrame < chargeMaxFrame) && jumpCounter < P_JUMP_MAX_NUM)
	{
		m_speed.y += m_speedAcc.y;
		pressFrame++;
	}
	if (KEY_UP('Z') && jumpCounter < P_JUMP_MAX_NUM)
	{
		pressFrame = 0;
		jumpCounter++;
	}

	// 溜めジャンプ
	//static float power = 0;
	//if ((m_command & PAD_TRG1) && jumpCounter < P_JUMP_MAX_NUM)
	//{
	//	if (power > -30)
	//	{
	//		power += m_speedAcc.y;
	//	}
	//	// TODO : reverse the animetion
	//}
	//if (KEY_UP('Z'))
	//{
	//	m_speed.y += power;
	//	jumpCounter++;
	//	power = 0;
	//}

	
	if (m_isOnGround)
	{
		jumpCounter = 0;
	}
	if (m_speed.y < -m_speedMax.y)
	{
		m_speed.y = -m_speedMax.y;
	}


	if (m_speed.x > m_speedMax.x)
	{
		m_speed.x = m_speedMax.x;
	}
	if (m_speed.x < -m_speedMax.x)
	{
		m_speed.x = -m_speedMax.x;
	}


	// 移動
	m_pos += m_speed;


	// スクロールエリア処理
	m_isOnScrollArea = false;
	m_type = 0;//debug
	// TODO : スピードが高い場合の判定
	if (m_pos.y - m_size.y < P_SCROLL_Y_TOP && m_pos.y/* - m_speed.y */> P_SCROLL_Y_TOP && m_speed.y < 0 && m_scrolledDistance.y > 0)
	{
		/*if (m_scrolledDistance.y > -P_JUMP_POWER_BLUR)
		{
			
		}*/
		m_pos.y = P_SCROLL_Y_TOP + m_size.y - 0.1;
		m_isOnScrollArea = true;
		m_type = 1;//debug
	}
	if (m_pos.y > P_SCROLL_Y_BOTTOM && m_pos.y - m_size.y < P_SCROLL_Y_BOTTOM && m_speed.y > 0 && m_scrolledDistance.y < STAGE_HEIGHT)
	{
		m_pos.y = P_SCROLL_Y_BOTTOM;
		m_isOnScrollArea = true;
		m_type = 2;//debug
	}
	if (m_isOnScrollArea)
	{
		// スクロール距離を計算していく
		m_scrolledDistance.y += m_speed.y;
		if (m_scrolledDistance.y < 0)
		{
			m_scrolledDistance.y = 0;
			m_speed.y = 0;
		}
		if (m_scrolledDistance.y > STAGE_HEIGHT)
		{
			m_scrolledDistance.y = STAGE_HEIGHT;
			m_speed.y = 0;
		}
	}


	// ページ外チェック
	if (m_pos.x > PAGE_WIDTH - m_size.x / 2)
	{
		m_pos.x = PAGE_WIDTH - m_size.x / 2;
	}
	if (m_pos.x < m_size.x / 2)
	{
		m_pos.x = m_size.x / 2;
	}

	if (m_pos.y > PAGE_HEIGHT + m_size.y)
	{
		m_mode = P_MODE::RESTART;
	}

	if (m_pos.y < - m_size.y - 100)
	{
		m_pos.y = -m_size.y - 100;
		m_speed.y = 0;
	}

	// アニメーションデータ
	if (fabsf(m_speed.x - 0.0f) > FLT_EPSILON && m_isOnGround && m_pAnimeData != e_pAnimePlayerRun)
	{
		m_animeNO = 0;
		m_pAnimeData = e_pAnimePlayerRun;
	}
	if ((m_montionState == P_STATE::DROPPING || m_montionState == P_STATE::JUMPING) && !m_isOnGround && m_pAnimeData != e_pAnimePlayerJump)
	{
		m_animeNO = 0;
		m_pAnimeData = e_pAnimePlayerJump;
	}
	// 滲む
	if (m_isMoving) 
	{
		blur();
	}

	if (m_life <= 0)
	{
		m_mode = P_MODE::DEAD;
	}
	// 待機アニメショーン
	if (fabsf(m_speed.x - 0.0f) < FLT_EPSILON && m_isOnGround)
	{
		// 待機からあくびに切り替え
		static int waitFrame = 0, yawnFrame = 64, standyFrame = 300, randInteger = 0;
		if (m_pAnimeData != e_pAnimePlayerStandby && m_pAnimeData != e_pAnimePlayerYawn)
		{
			m_animeNO = 0;
			waitFrame = 0;
			m_pAnimeData = e_pAnimePlayerStandby;
		}
		if (m_pAnimeData == e_pAnimePlayerStandby)
		{
			waitFrame++;
			if (waitFrame > standyFrame + randInteger)
			{
				m_animeNO = 0;
				m_pAnimeData = e_pAnimePlayerYawn;
				waitFrame = 0;
				randInteger = rand() % 300;
			}
		}
		if (m_pAnimeData == e_pAnimePlayerYawn)
		{
			waitFrame++;
			if (waitFrame > yawnFrame)
			{
				m_animeNO = 0;
				m_pAnimeData = e_pAnimePlayerStandby;
				waitFrame = 0;
			}
		}
	}

	pGameUIManager->showPlayerConcentration(m_concentration);
	pGameUIManager->showPlayerLife(m_life);

}

void Player::restartMove()
{

	m_isMoving = false;
	switch (m_step)
	{
	case STEP::INIT:
		m_speed.x = 0;
		m_speed.y = -m_scrolledDistance.y / 10;
		m_alpha = 0;
		m_step = STEP::BEGIN;
		//break;
	case STEP::BEGIN:
		m_pos.y += m_speed.y;

		m_isOnScrollArea = true;
		if (m_isOnScrollArea)
		{
			m_scrolledDistance.y += m_speed.y;
			if (m_scrolledDistance.y <= 0)
			{
				//m_speed.y = 0;
				//m_isOnScrollArea = false;
				m_step = STEP::END;
				m_pos.x = 80;
				m_pos.y = 140;
				pEffectManager->setPlayerInitAnimation(m_pos);
			}
		}
		break;
	case STEP::END:
		if (pEffectManager->isStampDown) {
			restart();
			m_speed.y = 0;
			//m_isOnScrollArea = false;
			m_life--;
			m_mode = P_MODE::NORMAL;
		}
		break;
	default:
		break;

	}
}

// 滲む処理
void Player::blur()
{
	pObjManager->m_hitObj.m_liveInPagination = m_liveInPagination;

	// プレイヤーが通過したところにランダムで滲む判定用Objを配置
	Vector3 randAdjust;
	for (int i = 0, maxInOnce = 3; i < maxInOnce; i++) {
		randAdjust = { (float)(rand() % (int)(fabsf(m_speed.x) + m_size.x)), (float)(rand() % (int)(fabsf(m_speed.y) + m_size.y)),0 };
		if (fabsf(m_speed.x - 0.0f) < FLT_EPSILON && !m_isOnGround)
		{
			randAdjust.x -= m_size.x / 2;
			randAdjust.y -= m_size.y / 2;
		}
		if (m_isOnGround)
		{
			randAdjust.x += m_size.x / 2;
		}

		if (fabsf(m_speed.x - 0.0f) > FLT_EPSILON)
		{
			randAdjust.x *= (m_speed.x / fabsf(m_speed.x));
		}
		if (fabsf(m_speed.y - 0.0f) > FLT_EPSILON)
		{
			randAdjust.y *= (m_speed.y / fabsf(m_speed.y));
		}
		pObjManager->m_hitObj.m_pos = m_pos - randAdjust;
		pObjManager->m_hitObj.m_initPos = pObjManager->m_hitObj.m_pos + m_scrolledDistance;
		pObjManager->m_hitObj.m_custom.angle = rand() % 180;
		pObjManager->m_hitObj.m_alpha = rand() % 20 + 20;
		pObjManager->m_newblurAreaList.push_back(pObjManager->m_hitObj);
	}
}

void Player::update()
{
	switch (m_mode)
	{
	case P_MODE::CLEAR:
		m_timer = 0;
	case P_MODE::NORMAL:
		normalMove();
		animation();
		break;
	case P_MODE::RESTART:
		restartMove();
		break;
	default:
		break;
	}
}

void Player::draw()
{
#ifdef DEBUG

	drawRectangle(m_pos.x - m_size.x / 2, m_pos.y - m_size.y, m_size.x, m_size.y, 0, 0xFFFFFF40);

#endif // DEBUG

	OBJ2DEX::draw();
	if (m_isKeyHandled && m_keyObj->m_pSprData)
	{
		m_keyObj->m_pos = m_pos - Vector3(!m_custom.reflectX ? -m_size.x / 2 : m_keyObj->m_pSprData->width + m_size.x / 2, 2 * m_size.y, 0);
		m_keyObj->draw();
	}

#ifdef DEBUG

	char buf[256];
	sprintf_s(buf, " scrolledDisY: %f\n posY: %f\n speedX: %f\n speedY: %f\n State: %d\n Concentration: %d\n TransferConcen: %d\n Life: %d\n STAGE_HEIGHT: %d",
		m_scrolledDistance.y, m_pos.y, m_speed.x, m_speed.y, m_montionState, m_concentration, m_transferConcentration, m_life, STAGE_HEIGHT);
	drawString(0, 0, buf, 0x000000FF, STR_LEFT);
	if (m_type == 0)
	{
		drawRectangle(0, 0, PAGE_WIDTH, P_SCROLL_Y_TOP, 0, 0xFFFFFF40);
		drawRectangle(0, P_SCROLL_Y_BOTTOM, PAGE_WIDTH, PAGE_HEIGHT - P_SCROLL_Y_BOTTOM, 0, 0xFFFFFF40);
	}
	else
	{
		if (m_type == 1)
		{
			drawRectangle(0, 0, PAGE_WIDTH, P_SCROLL_Y_TOP, 0, 0xFF000080);
		}
		if (m_type == 2)
		{
			drawRectangle(0, P_SCROLL_Y_BOTTOM, PAGE_WIDTH, PAGE_HEIGHT - P_SCROLL_Y_BOTTOM, 0, 0x0000FF80);
		}
	} 

#endif // DEBUG
}


int Player::getLife()
{
	return m_life;
}

void Player::addLife(int a_life)
{
	m_life += a_life;
	if (m_life < 0)
	{
		m_life = 0;
	}
	if (m_life > P_LIFE_MAX)
	{
		m_life = P_LIFE_MAX;
	}
}

////////////////////////////////////////////////////////////////////////

// Player Manager Class
PlayerManager::PlayerManager()
{
	init();
}

PlayerManager::~PlayerManager()
{
	if (m_pPlayer)
	{
		delete m_pPlayer;
		m_pPlayer = nullptr;
	}
}

void PlayerManager::init() {
	if (!m_pPlayer)
	{
		m_pPlayer = new Player();
		m_pPlayer->clear();
		m_pPlayer->init();
		pObjManager->m_ppObjs[GET_IDLE_OBJ_NO] = m_pPlayer;
	}
	else
	{
		m_pPlayer->clear();
		m_pPlayer->init();
	}
}

void PlayerManager::manageConcentration()
{
	switch (m_step)
	{
	case STEP::INIT:
		m_isPlayerOnLeft = m_pPlayer->m_liveInPagination % 2 != 0;
		m_concentration = m_pPlayer->m_concentration;
		if (m_concentration >= 2)
		{
			m_pPlayer->m_concentration /= 2;
			m_pPlayer->m_transferConcentration = m_concentration - m_pPlayer->m_concentration;
			m_step = STEP::BEGIN;
		} 
		else
		{
			m_pPlayer->m_transferConcentration = 0;
			m_isTranscriptAble = false;
			m_step = STEP::END;
		}
		break;
	case STEP::BEGIN:

		if (m_isTranscriptAble)
		{
			/*if ((m_isPlayerOnLeft && (KEY_TRACKER.pressed.A || PAD_TRACKER.leftStickLeft == PAD_TRACKER.PRESSED)) 
				|| (!m_isPlayerOnLeft && (KEY_TRACKER.pressed.D || PAD_TRACKER.leftStickRight == PAD_TRACKER.PRESSED))) {
				m_pPlayer->m_transferConcentration++;
				m_pPlayer->m_concentration--;
			}
			if ((!m_isPlayerOnLeft && (KEY_TRACKER.pressed.A || PAD_TRACKER.leftStickLeft == PAD_TRACKER.PRESSED)) 
				|| (m_isPlayerOnLeft && (KEY_TRACKER.pressed.D || PAD_TRACKER.leftStickRight == PAD_TRACKER.PRESSED))) {
				m_pPlayer->m_transferConcentration--;
				m_pPlayer->m_concentration++;
			}*/

		}

		/*if (m_pPlayer->m_transferConcentration < 1) {
			m_pPlayer->m_transferConcentration = 1;
		}
		if (m_pPlayer->m_transferConcentration > m_concentration - 1) {
			m_pPlayer->m_transferConcentration = m_concentration - 1;
		}
		if (m_pPlayer->m_concentration < 1 ) {
			m_pPlayer->m_concentration = 1;
		}				 
		if (m_pPlayer->m_concentration > m_concentration - 1) {
			m_pPlayer->m_concentration = m_concentration - 1;
		}*/

		break;
	case STEP::END:
		m_pPlayer->m_transferConcentration = 0;
		m_isTranscriptAble = false;

		break;
	default:
		break;
	}

	pGameUIManager->showInkTransferGage(m_pPlayer->m_concentration, m_pPlayer->m_transferConcentration, m_isPlayerOnLeft, m_isTranscriptAble);
}

void PlayerManager::transcriptPlayer(int a_concentration)
{
	if (m_pPlayer)
	{
		if (m_isTranscriptAble)
		{
			// 転写元を作成
			pObjManager->m_transcriptionObj.m_isInit = true;
			pObjManager->m_transcriptionObj.m_pos = m_pPlayer->m_pos;
			pObjManager->m_transcriptionObj.m_initPos = pObjManager->m_transcriptionObj.m_pos + m_pPlayer->m_scrolledDistance;
			pObjManager->m_transcriptionObj.m_size = m_pPlayer->m_size;
			pObjManager->m_transcriptionObj.m_pos.z--;
			pObjManager->m_transcriptionObj.m_custom = m_pPlayer->m_custom;
			pObjManager->m_transcriptionObj.m_concentration = m_pPlayer->m_transferConcentration;
			pObjManager->m_transcriptionObj.m_alpha = 255 * pObjManager->m_transcriptionObj.m_concentration / 10;
			pObjManager->m_transcriptionObj.m_pSprData = m_pPlayer->m_pSprData;
			pObjManager->m_transcriptionObj.m_liveInPagination = m_pPlayer->m_liveInPagination;
			pObjManager->m_transcriptionList.push_back(pObjManager->m_transcriptionObj);

			if (m_isTranscriptCanceled)
			{
				// 転写失敗によって転写先を生成位置に強制リセット
				m_pPlayer->m_mode = P_MODE::RESTART;

			}
			else
			{
				// 隣のページへ転写
				m_pPlayer->m_liveInPagination += m_pPlayer->m_liveInPagination % 2 ? 1 : -1;
				m_pPlayer->m_pos.x = PAGE_WIDTH - m_pPlayer->m_pos.x;
				m_pPlayer->m_speed = { 0,0,0 };
				m_pPlayer->m_custom.reflectX = !m_pPlayer->m_custom.reflectX;
				m_pPlayer->m_timer = 0;

			}
			m_step = STEP::INIT;
		}
		else
		{
			m_pPlayer->m_concentration = m_concentration;
			m_pPlayer->m_transferConcentration = 0;
			m_step = STEP::INIT;
		}

	}
}

////////////////////////////////////////////////////////////////////////
