#include "game.h"
#include "sprite_data.h"
#include "obj2d.h"

#include "player.h"


Player::Player()
{
	OBJ2DEX::clear();
	m_pAnimeData = e_pAnimePlayerStandby;
	//m_pAnimeData = e_pAnimePlayerJump;
	m_size = Vector3(60, 45, 4);
	m_command = 0x0;
	m_pos = { 200,200,5 };
	
	m_pSprData = &m_pAnimeData[0];

	m_mode = MODE_NORMAL;
	m_state = P_STATE_ON_GROUND;
	m_concentration = P_CONCENTRATION_MAX_NUM;
	m_transferConcentration = 0;

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
	// 繝励Ξ繝ｼ繝､繝ｼ縺ｮ迥ｶ諷句愛譁ｭ
	if (m_speed.y == 0 && m_state != P_STATE_JUMPING)
	{
		m_state = P_STATE_ON_GROUND;
	}
	if (m_speed.y < 0)
	{
		m_state = P_STATE_JUMPING;
	}
	if (m_speed.y > 0)
	{
		m_state = P_STATE_DROPPING;
	}
	// X譁ｹ蜷醍ｧｻ蜍・
	switch (m_command & (PAD_LEFT | PAD_RIGHT))
	{
	case PAD_LEFT:
		m_speed.x -= P_SPEED_AX;
		m_custom.reflectX = false;
		break;
	case PAD_RIGHT:
		m_speed.x += P_SPEED_AX;
		m_custom.reflectX = true;
		break;
	default:
		if (m_speed.x > 0) {
			m_speed.x -= P_SPEED_AX / 2;
			if (m_speed.x < 0) m_speed.x = 0;
		}
		if (m_speed.x < 0) {
			m_speed.x += P_SPEED_AX / 2;
			if (m_speed.x > 0) m_speed.x = 0;
		}
		break;
	}

	// Y譁ｹ蜷醍ｧｻ蜍・
	m_speed.y += GRIVATY;
	// 貅懊ａ繧ｸ繝｣繝ｳ繝・
	//static float power = 0;
	//if ((m_command & PAD_TRG1))
	//{
	//	if (power > -30)
	//	{
	//		power += P_JUMP_POWER;
	//	}
	//	// TODO : reverse the animetion
	//}
	//if (KEY_UP('Z'))
	//{
	//	m_speed.y += power;
	//	power = 0;
	//}

	static int pressFrame = 0, chargeMaxFrame = 12, jumpCounter = 0;
	if ((m_command & PAD_TRG1) && (pressFrame < chargeMaxFrame) && jumpCounter < P_JUMP_MAX_NUM)
	{
		m_speed.y += P_JUMP_POWER;
		pressFrame++;
	}
	if (KEY_UP('Z') && jumpCounter < P_JUMP_MAX_NUM)
	{
		pressFrame = 0;
		jumpCounter++;
	}
	if (m_state == P_STATE_ON_GROUND)
	{
		jumpCounter = 0;
	}
	if (m_speed.y < -P_SPEED_Y_MAX)
	{
		m_speed.y = -P_SPEED_Y_MAX;
	}


	if (m_speed.x > P_SPEED_X_MAX)
	{
		m_speed.x = P_SPEED_X_MAX;
	}
	if (m_speed.x < -P_SPEED_X_MAX)
	{
		m_speed.x = -P_SPEED_X_MAX;
	}


	// 遘ｻ蜍・
	m_pos += m_speed;

	if (m_pos.x > PAGE_WIDTH - m_size.x / 2)
	{
		m_pos.x = PAGE_WIDTH - m_size.x / 2;
		m_speed.x = 0;
	}
	if (m_pos.x < m_size.x / 2)
	{
		m_pos.x = m_size.x / 2;
		m_speed.x = 0;
	}

	if (m_pos.y > PAGE_HEIGHT - m_size.y / 2)
	{
		m_pos.y = PAGE_HEIGHT - m_size.y / 2;
		m_speed.y = 0;
	}
	if (m_pos.y < 100 - m_size.y / 2)
	{
		m_pos.y = 100 - m_size.y / 2;
		m_speed.y = 0;
	}

	// 豼・ｺｦ險育ｮ暦ｼ壼虚縺・※繧九→縺阪↓貂帙▲縺ｦ縺・￥
	if (m_pAnimeData != e_pAnimePlayerStandby)
	{
		m_timer++;
		if (m_timer > P_CONCENTRATION_DECREASE_SPEED)
		{
			m_timer = 0;
			m_concentration--;
			if (m_concentration < 0)
			{
				m_concentration = P_CONCENTRATION_MAX_NUM;
			}
		}
	}

	// 繧｢繝九Γ繝ｼ繧ｷ繝ｧ繝ｳ繝・・繧ｿ
	if (m_speed.x != 0 && m_state == P_STATE_ON_GROUND && m_pAnimeData != e_pAnimePlayerRun)
	{
		m_animeNO = 0;
		m_pAnimeData = e_pAnimePlayerRun;
	}
	if ((m_state == P_STATE_DROPPING || m_state == P_STATE_JUMPING) && m_pAnimeData != e_pAnimePlayerJump)
	{
		m_animeNO = 0;
		m_pAnimeData = e_pAnimePlayerJump;
	}
	if (m_speed.x == 0 && m_state == P_STATE_ON_GROUND && m_pAnimeData != e_pAnimePlayerStandby)
	{
		m_animeNO = 0;
		m_pAnimeData = e_pAnimePlayerStandby;
	}
}

void Player::update()
{
	switch (m_mode)
	{
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

#ifdef DEBUG

	char buf[256];
	sprintf_s(buf, " posX: %f\n posY: %f\n speedX: %f\n speedY: %f\n State: %d\n Concentration: %d", m_pos.x, m_pos.y, m_speed.x, m_speed.y, m_state, m_concentration);
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
		m_transferConcentration = m_pPlayer->m_concentration - 1;
		m_state = STATE_BEGIN;
		//break;
	case STATE_BEGIN:
		if (KEY_DOWN('A')) {
			m_pPlayer->m_isOnLeftPage ? (m_transferConcentration--) : (m_transferConcentration++);
		}
		if (KEY_DOWN('D')) {
			m_pPlayer->m_isOnLeftPage ? (m_transferConcentration++) : (m_transferConcentration--);
		}

		if (m_transferConcentration < 1) {
			m_transferConcentration = 1;
		}

		if (m_transferConcentration > m_concentration - 1) {
			m_transferConcentration = m_concentration - 1;
		}
		m_pPlayer->m_concentration = m_transferConcentration;
		break;
	default:
		break;
	}

}

void PlayerManager::transcriptPlayer(int a_concentration)
{
	if (m_pPlayer && m_isTranscriptAble)
	{
		OBJ2D *pObj2dTemp = nullptr;
		pObj2dTemp = pObjManager->m_ppObj[GET_IDLE_OBJ_NO];
		pObj2dTemp->m_isInit = true;
		pObj2dTemp->m_pos = m_pPlayer->m_pos;
		pObj2dTemp->m_pos.z--;
		pObj2dTemp->m_custom = m_pPlayer->m_custom;
		pObj2dTemp->m_alpha = 255 * (m_concentration - m_transferConcentration) / 10;
		pObj2dTemp->m_pSprData = m_pPlayer->m_pSprData;
		pObj2dTemp->m_isOnLeftPage = m_pPlayer->m_isOnLeftPage;
		m_pPlayer->m_isOnLeftPage = !m_pPlayer->m_isOnLeftPage;

		m_pPlayer->m_pos.x = PAGE_WIDTH - m_pPlayer->m_pos.x;
		m_pPlayer->m_speed = { 0,0,0 };
		m_pPlayer->m_custom.reflectX = !m_pPlayer->m_custom.reflectX;

		m_state = STATE_INIT;
	}
}
