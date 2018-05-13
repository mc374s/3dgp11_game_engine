#include "Game.h"

Player::Player()
{
	OBJ2DEX::clear();
	m_pAnimeData = e_pAnimePlayerStandby;
	//m_pAnimeData = e_pAnimePlayerJump;
	m_size = Vector3(95, 45, 4);
	m_command = 0x0;
	m_pos.y = GROUND_HEIGHT;
	
	m_pSprData = &m_pAnimeData[0];

	mode = MODE_NORMAL;
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

	// X方向移動
	switch (m_command & (PAD_LEFT | PAD_RIGHT))
	{
	case PAD_LEFT:
		m_speed.x -= P_SPEED_AX;
		m_custom.reflectX = true;
		break;
	case PAD_RIGHT:
		m_speed.x += P_SPEED_AX;
		m_custom.reflectX = false;
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

	// Y方向移動
	m_speed.y += GRIVATY;
	if (m_command & PAD_TRG1)
	{
		m_speed.y += P_JUMP_POWER;
	}

	if (m_speed.x > P_SPEED_X_MAX)
	{
		m_speed.x = P_SPEED_X_MAX;
	}
	if (m_speed.x < -P_SPEED_X_MAX)
	{
		m_speed.x = -P_SPEED_X_MAX;
	}


	// 移動
	m_pos += m_speed;

	if (m_pos.x > PAGE_WIDTH - m_size.x / 2)
	{
		m_pos.x = PAGE_WIDTH - m_size.x / 2;
	}
	if (m_pos.x < m_size.x / 2)
	{
		m_pos.x = m_size.x / 2;
	}

	if (m_pos.y > PAGE_HEIGHT - m_size.y / 2)
	{
		m_pos.y = PAGE_HEIGHT - m_size.y / 2;
	}

	if (m_pos.y > GROUND_HEIGHT)
	{
		m_pos.y = GROUND_HEIGHT;
		m_speed.y = 0;
	}

	// アニメーションデータ
	if (m_speed.x != 0 && m_speed.y == 0 && m_pAnimeData != e_pAnimePlayerRun)
	{
		m_animeNO = 0;
		m_pAnimeData = e_pAnimePlayerRun;
	}
	if (m_speed.y != 0 && m_pAnimeData != e_pAnimePlayerJump)
	{
		m_animeNO = 0;
		m_pAnimeData = e_pAnimePlayerJump;
	}
	if (m_speed.x == 0 && m_speed.y == 0 && m_pAnimeData != e_pAnimePlayerStandby)
	{
		m_animeNO = 0;
		m_pAnimeData = e_pAnimePlayerStandby;
	}
}

void Player::update()
{
	switch (mode)
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
	OBJ2DEX::draw();

#ifdef DEBUG

	drawRectangle(m_pos.x - m_size.x / 2, m_pos.y - m_size.y, m_size.x, m_size.y, 0, 0xFFFFFF40);

	char buf[256];
	sprintf_s(buf, " posX: %f\n posY: %f\n speedX: %f\n speedY: %f\n", m_pos.x, m_pos.y, m_speed.x, m_speed.y);
	drawString(0, 0, buf, 0x000000FF, STR_LEFT);

#endif // DEBUG
}

