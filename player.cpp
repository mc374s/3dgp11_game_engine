#include "game.h"
#include "sprite_data.h"
#include "obj2d.h"
#include "game_ui.h"

//#include <list>

#include "player.h"


Player::Player()
{
	OBJ2DEX::clear();
	init(); 
	m_life = 4;
	m_isOnGround = true;
	m_isKeyHandled = false;
	
}
void Player::init()
{
	m_pAnimeData = e_pAnimePlayerYawn;
	//m_pAnimeData = e_pAnimePlayerJump;
	m_size = Vector3(60, 45, 4);
	m_command = 0x0;
	m_pos = { 20,-100,5 };

	m_pSprData = &m_pAnimeData[0];

	m_mode = MODE_NORMAL;
	m_montionState = P_STATE_STANDY;
	m_concentration = P_CONCENTRATION_MAX_NUM;
	m_alpha = 255;
	m_transferConcentration = 0;
	m_timer = 0;
	m_isOnBlurArea = false;
	if (!m_isKeyHandled)
	{
		m_keyObj.clear();
	}

	m_speedAcc = { P_SPEED_AX,P_JUMP_POWER,0 };
	m_speedMax = { P_SPEED_X_MAX,P_SPEED_Y_MAX,0 };
	m_isOnScrollArea = false;

	m_isInit = true;

}

Player::~Player()
{
	m_pAnimeData = nullptr;
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
	if (m_speed.x != 0 || m_speed.y != 0)
	{
		m_timer++;
		if (m_timer > P_CONCENTRATION_DECREASE_FRAME)
		{
			m_timer = 0;
			m_concentration--;
			if (m_concentration < 1)
			{
				init();
				m_life--;
				if (m_life <= 0)
				{
					m_mode = MODE_DEAD;
				}
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
	if (m_speed.y == 0 && m_montionState != P_STATE_JUMPING && !m_isOnGround)
	{
		m_isOnGround = true;
	}
	if (m_speed.y < 0)
	{
		m_montionState = P_STATE_JUMPING;
		m_isOnGround = false;
	}
	if (m_speed.y > 0)
	{
		m_montionState = P_STATE_DROPPING;
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
	m_isOnScrollArea = false;
	if (m_pos.y > P_SCROLL_Y_BOTTOM)
	{
		m_pos.y = P_SCROLL_Y_BOTTOM;
		m_isOnScrollArea = true;
	}
	if (m_pos.y < P_SCROLL_Y_TOP && m_state == P_STATE_JUMPING)
	{
		m_pos.y = P_SCROLL_Y_TOP;
		m_isOnScrollArea = true;
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
		init();
		m_life--;
	}
	if (m_pos.y < - m_size.y - 100)
	{
		m_pos.y = -m_size.y - 100;
	}

	// アニメーションデータ
	if (m_speed.x != 0 && m_isOnGround && m_pAnimeData != e_pAnimePlayerRun)
	{
		m_animeNO = 0;
		m_pAnimeData = e_pAnimePlayerRun;
	}
	if ((m_montionState == P_STATE_DROPPING || m_montionState == P_STATE_JUMPING) && !m_isOnGround && m_pAnimeData != e_pAnimePlayerJump)
	{
		m_animeNO = 0;
		m_pAnimeData = e_pAnimePlayerJump;
	}

	// 待機アニメショーン
	if (m_speed.x == 0 && m_isOnGround)
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
}

void Player::update()
{
	switch (m_mode)
	{
	case MODE_CLEAR:
	case MODE_NORMAL:
		normalMove();
		animation();
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
	if (m_isKeyHandled)
	{
		m_keyObj.m_pos = m_pos - Vector3(!m_custom.reflectX ? -m_size.x / 2 : m_keyObj.m_pSprData->width + m_size.x / 2, 2 * m_size.y, 0);
		m_keyObj.draw();
	}

#ifdef DEBUG

	char buf[256];
	sprintf_s(buf, " posX: %f\n posY: %f\n speedX: %f\n speedY: %f\n State: %d\n Concentration: %d\n TransferConcen: %d\n Life: %d",
		m_pos.x, m_pos.y, m_speed.x, m_speed.y, m_montionState, m_concentration, m_transferConcentration,m_life);
	drawString(0, 0, buf, 0x000000FF, STR_LEFT);

#endif // DEBUG
}

// Player Manager Class
void PlayerManager::init() {
	if (!m_pPlayer)
	{
		m_pPlayer = new Player;
		pObjManager->m_ppObj[OBJ2D::searchSet(pObjManager->m_ppObj, OBJ_MAX_NUM)] = m_pPlayer;
	}
}

void PlayerManager::manageConcentration()
{
	switch (m_state)
	{
	case STATE_INIT:
		m_concentration = m_pPlayer->m_concentration;
		if (m_concentration >= 2)
		{
			m_pPlayer->m_transferConcentration = 1;
			m_pPlayer->m_concentration--;
			m_state = STATE_BEGIN;
		} 
		else
		{
			m_pPlayer->m_transferConcentration = 0;
			m_pPlayer->m_concentration;
			m_state = STATE_END;
		}
		break;
	case STATE_BEGIN:

		if (m_isTranscriptAble)
		{
			if ((m_pPlayer->m_isOnLeftPage && KEY_DOWN('A')) || (!m_pPlayer->m_isOnLeftPage && KEY_DOWN('D'))) {
				m_pPlayer->m_transferConcentration++;
				m_pPlayer->m_concentration--;
			}
			if ((!m_pPlayer->m_isOnLeftPage && KEY_DOWN('A')) || (m_pPlayer->m_isOnLeftPage && KEY_DOWN('D'))) {
				m_pPlayer->m_transferConcentration--;
				m_pPlayer->m_concentration++;
			}

		}

		if (m_pPlayer->m_transferConcentration < 1) {
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
		}


		break;
	default:
		break;
	}

	pGameUIManager->setInkGage(m_pPlayer->m_concentration, m_pPlayer->m_transferConcentration, m_pPlayer->m_isOnLeftPage, m_isTranscriptAble);
}

void PlayerManager::transcriptPlayer(int a_concentration)
{
	if (m_pPlayer)
	{
		if (m_isTranscriptAble)
		{

			pObjManager->m_transcriptionObj.m_isInit = true;
			pObjManager->m_transcriptionObj.m_pos = m_pPlayer->m_pos;
			pObjManager->m_transcriptionObj.m_size = m_pPlayer->m_size;
			pObjManager->m_transcriptionObj.m_pos.z--;
			pObjManager->m_transcriptionObj.m_custom = m_pPlayer->m_custom;
			pObjManager->m_transcriptionObj.m_concentration = m_pPlayer->m_transferConcentration;
			pObjManager->m_transcriptionObj.m_alpha = 255 * pObjManager->m_transcriptionObj.m_concentration / 10;
			pObjManager->m_transcriptionObj.m_pSprData = m_pPlayer->m_pSprData;
			pObjManager->m_transcriptionObj.m_isOnLeftPage = m_pPlayer->m_isOnLeftPage;
			pObjManager->m_transcriptionList.push_back(pObjManager->m_transcriptionObj);

			if (m_isTranscriptCanceled)
			{
				m_pPlayer->init();
				m_pPlayer->m_life--;

			}
			else
			{

				m_pPlayer->m_isOnLeftPage = !m_pPlayer->m_isOnLeftPage;
				m_pPlayer->m_pos.x = PAGE_WIDTH - m_pPlayer->m_pos.x;
				m_pPlayer->m_speed = { 0,0,0 };
				m_pPlayer->m_custom.reflectX = !m_pPlayer->m_custom.reflectX;
				m_pPlayer->m_timer = 0;

			}
			m_state = STATE_INIT;
		}
		else
		{
			m_pPlayer->m_concentration = m_concentration;
			m_pPlayer->m_transferConcentration = 0;
			m_state = STATE_INIT;
		}

	}
}


int Player::getLife()
{
	return m_life;
}

void Player::setLife(int a_life)
{
	if (a_life < 0)
	{
		a_life = 0;
	}
	if (a_life > P_LIFE_MAX)
	{
		a_life = P_LIFE_MAX;
	}
	m_life = a_life;
}