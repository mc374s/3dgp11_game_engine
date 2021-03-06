﻿#include "game.h"
#include "sprite_data.h"
#include "game_ui.h"
#include "effect.h"

#include "book.h"
#include "paper.h"

#include "sound_data.h"
//#include <list>

#include "player.h"

Player::Player()
{
	OBJ2DEX::clear();
	//init(); 
}

void Player::init()
{
	m_pAnimeData = e_pAnimePlayerYawn;
	m_pSprData = &m_pAnimeData[0];
	m_command = 0x0;
	m_pos = INIT_POS;
	m_setPos = m_initPos = m_pos;
	m_scrolledDistance = { 0,0,0 };
	m_liveInPagination = START_PAGINATION;
	SCROLL_Y = 0.0f;
	m_pSprData = &m_pAnimeData[0];
	m_step = STEP::INIT;
	m_mode = P_MODE::RESTART;
	m_alpha = 0;
	m_isKeyHandled = false;
	//m_pKeyObjOld = nullptr;
	//m_pKeyObj = nullptr;
	/*if (m_pKeyObj)
	{
		m_pKeyObj[m_keyCounter].clear();
		m_pKeyObj[m_keyCounter].m_alpha = 0;
	}
	else
	{

		m_pKeyObj = new OBJ2D;
		m_pKeyObj[m_keyCounter].m_alpha = 0;
	}*/
	//m_pKeyObj[m_keyCounter].m_pSprData = &e_sprWhite;
	for (int i = 0; i < P_KEY_MAX_NUM; i++)
	{
		m_pKeyObj[i].clear();
		m_pKeyObj[i].m_alpha = 0;
	}
	m_keyCounter= 0;
	m_life = P_LIFE_MAX;

	m_hitObj.m_pSprData = &e_sprHitObj;
	//m_hitObj.m_size = { m_hitObj.m_pSprData->width,m_hitObj.m_pSprData->height,0 };
	m_hitObj.m_size = { 10,10,0 };
	m_hitObj.m_custom.rgba = 0xFFFFFFFF;
	m_hitObj.m_alpha = 10;
	m_newblurAreaList.clear();
	m_damageTimer = 0;
	m_eyes.m_pSprData = &e_sprEyes;
	m_concentration = P_CONCENTRATION_MAX;
	m_pBorder = nullptr;

	m_isInit = true;

}

Player::~Player()
{
	m_pAnimeData = nullptr;
	//SAFE_DELETE(m_pKeyObj);
}

void Player::restart()
{
	m_pAnimeData = e_pAnimePlayerYawn;
	//m_pAnimeData = e_pAnimePlayerJump;
	m_size = Vector3(60, 45, 4);
	m_command = 0x0;
	m_pos = INIT_POS;
	m_setPos = m_initPos = m_pos;
	m_scrolledDistance = { 0,0,0 };
	SCROLL_Y = 0.0f;
	m_liveInPagination = START_PAGINATION;

	m_pSprData = &m_pAnimeData[0];
	m_step = STEP::INIT;
	m_mode = P_MODE::NORMAL;
	m_montionState = P_STATE::DROPPING;
	m_concentration = P_CONCENTRATION_MAX;
	m_blurSpeed = P_BLUR_SPEED;
	m_alpha = 255;
	m_transferConcentration = 0;
	m_timer = 0;
	m_isOnBlurArea = false;
	m_isMoving = true;
	m_isOnGround = false;
	if (m_isKeyHandled)
	{
		m_pKeyObj[m_keyCounter - 1].m_alpha = 0;
		m_pKeyObj[m_keyCounter - 1].m_pos = m_pKeyObj[m_keyCounter - 1].m_setPos = m_pos;
		m_pKeyObj[m_keyCounter - 1].m_liveInPagination = m_liveInPagination;
	}
	m_speed = { 0,-0.1f,0 };
	m_speedAcc = { P_SPEED_AX,P_JUMP_POWER,0 };
	m_speedMax = { P_SPEED_X_MAX,P_SPEED_Y_MAX,0 };
	m_isOnScrollArea = false;
	m_jumpCounter = 1;
	m_damageTimer = 0;
	m_custom.reflectX = true;

	m_isInit = true;
}

void Player::normalMove()
{
	// input
	m_command = getInputKey();

	syncKeyPos();
	// 滲む範囲でのスピード入れ替え
	static int blurTimer = 0;
	blurTimer++;
	if (m_isOnBlurArea) {
		m_blurSpeed = P_BLUR_SPEED_ON_BLUR_AREA;
		if (m_pBorder == nullptr && !m_isDamaged && m_mode!=P_MODE::CLEAR){
			m_pBorder = Effect::searchSet(pEffectManager->m_ppEffect, EFF_OBJ_MAX_NUM, m_pos, m_liveInPagination, effectEnterBlurArea, 0, m_custom.reflectX);
		}
		//else if (m_pBorder && m_pBorder->m_pSprData) {
		//	// draw 関数に引越し
		//	m_pBorder->m_pSprData->copy(m_pSprData);
		//	//m_pBorder->m_pSprData->height	= m_pSprData->height;
		//	//m_pBorder->m_pSprData->width	= m_pSprData->width;
		//	//m_pBorder->m_pSprData->top		= m_pSprData->top;
		//	//m_pBorder->m_pSprData->left		= m_pSprData->left;
		//	//m_pBorder->m_pSprData->ofsX		= m_pSprData->ofsX;
		//	//m_pBorder->m_pSprData->ofsY		= m_pSprData->ofsY;
		//	m_pBorder->m_pos.x = m_pos.x / PAGE_WIDTH*(SCREEN_WIDTH / 2);
		//	if (m_liveInPagination % 2 == 0) {
		//		m_pBorder->m_pos.x += SCREEN_WIDTH / 2;
		//	}
		//	m_pBorder->m_pos.y = m_pos.y / PAGE_HEIGHT*SCREEN_HEIGHT;
		//	//m_pBorder->m_pos = m_pos;
		//	m_pBorder->m_custom.reflectX = m_custom.reflectX;
		//}
		//if ((blurTimer % 5 == 1) /*&& m_isMoving*/ && !m_isDamaged) {
		//	Effect::searchSet(pEffectManager->m_ppEffect, EFF_OBJ_MAX_NUM, m_pos + Vector3(60 * cosf(blurTimer*0.01745f*8), 60 * sinf(blurTimer*0.01745f*8), 0), m_liveInPagination, effectStar, 0, m_custom.reflectX);
		//	//Effect::searchSet(pEffectManager->m_ppEffect, EFF_OBJ_MAX_NUM, m_pos + Vector3(0.0f, 20.0f, 0.0f), m_liveInPagination, effectOnBlurArea);
		//}
		//if ((blurTimer % 40 == 0) /*&& m_isMoving*/ && !m_isDamaged) {
		//	//Effect::searchSet(pEffectManager->m_ppEffect, EFF_OBJ_MAX_NUM, m_pos + Vector3(60 * cosf(blurTimer*0.01745f*8), 60 * sinf(blurTimer*0.01745f*8), 0), m_liveInPagination, effectStar, 0, m_custom.reflectX);
		//	//Effect::searchSet(pEffectManager->m_ppEffect, EFF_OBJ_MAX_NUM, Vector3(270.0f, 50.0f, 0.0f), 1, effectGageOnBlurArea);
		//}
	} else {
		blurTimer = 0;
		m_blurSpeed = P_BLUR_SPEED;
		if (m_pBorder)
		{
			m_pBorder->m_step = STEP::INIT;
			m_pBorder->m_doReverseMove = true;
			m_pBorder = nullptr;
		}
	}
	// 濃度計算：動いてるときに減っていく
	if (fabsf(m_speed.x - 0.0f) > FLT_EPSILON || fabsf(m_speed.y - 0.0f) > FLT_EPSILON)
	{

		//m_concentration -= m_blurSpeed;
		m_isMoving = true;
	}
	else
	{
		m_isMoving = false;
	}

	if (m_isDamaged){
		m_damageTimer++;
		if (m_damageTimer % 20 == 0) {
			Effect::searchSet(pEffectManager->m_ppEffect, EFF_OBJ_MAX_NUM, m_pos + Vector3(rand() % 50 - 25, rand() % 50 - 25, 0), m_liveInPagination, effectDamaging, 0, m_custom.reflectX);
			if (m_damageTimer % 40 == 0){
				MFAudioPlay(SE_FALL);
			}
		}
		if (m_damageTimer % 20 < 10) {
			m_custom.rgba = 0xFF0000FF;
		}
		else{
			m_custom.rgba = 0xFFFFFFFF;
		}
		m_concentration -= P_BLUR_SPEED_ON_HIGT_CONCENTRATION_AREA;
	}else
	{
		m_damageTimer = 0;
		m_custom.rgba = 0xFFFFFFFF;
	}
	if (m_concentration < 0.0f)
	{
		if (m_mode != P_MODE::CLEAR)
		{
			//Effect::searchSet(pEffectManager->m_ppEffect, EFF_OBJ_MAX_NUM, Vector3(m_pos.x, m_pos.y - m_size.y / 2, 0), m_liveInPagination, effectDisappear);
			//MFAudioPlay(SE_DEAD);
			m_mode = P_MODE::RESTART;
		}
		else{
			m_concentration = 0.0f;
		}

	}
	m_alpha = 255 * (m_concentration) / P_CONCENTRATION_MAX + 20;

	// プレーヤーの状態判断
	if (fabsf(m_speed.y - 0.0f) < FLT_EPSILON && m_montionState != P_STATE::JUMPING && !m_isOnGround)
	{
		m_montionState = P_STATE::STANDBY;
		m_isOnGround = true;
		Effect::searchSet(pEffectManager->m_ppEffect, EFF_OBJ_MAX_NUM, m_pos, m_liveInPagination, effectJumpUp);
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

	static int pressFrame = 0, chargeMaxFrame = 12;
	if ((KEY_BOARD.Z || GAME_PAD.buttons.a) && pressFrame < chargeMaxFrame && m_jumpCounter < P_JUMP_MAX_NUM)
	{
		m_speed.y += m_speedAcc.y;
		if (pressFrame == 0) {
			Effect::searchSet(pEffectManager->m_ppEffect, EFF_OBJ_MAX_NUM, m_pos, m_liveInPagination, effectJumpDown);
		}
		pressFrame++;
	}
	if ((KEY_TRACKER.released.Z || PAD_TRACKER.a == PAD_TRACKER.RELEASED) && m_jumpCounter < P_JUMP_MAX_NUM)
	{
		pressFrame = 0;
		m_jumpCounter++;
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
		m_jumpCounter = 0;
	}
	if (m_speed.y < -m_speedMax.y)
	{
		m_speed.y = -m_speedMax.y;
	}
	if (m_speed.y > m_speedMax.y)
	{
		m_speed.y = m_speedMax.y;
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

	//if (m_pos.y <= P_SCROLL_Y_BOTTOM && m_pos.y >= P_SCROLL_Y_TOP) {
	//	m_isOnScrollArea = false;
	//}

	m_type = 0;//debug
	// TODO : スピードが高い場合の判定
	if (m_pos.y - m_size.y < P_SCROLL_Y_TOP && m_pos.y/* - m_speed.y */> P_SCROLL_Y_TOP && m_speed.y <= 0 && m_scrolledDistance.y > 0)
	{
		/*if (m_scrolledDistance.y > -P_JUMP_POWER_BLUR)
		{

		}*/
		m_pos.y = P_SCROLL_Y_TOP + m_size.y - 0.1;
		m_isOnScrollArea = true;
		m_type = 1;//debug
	}
	if (m_pos.y > P_SCROLL_Y_BOTTOM && m_pos.y - m_size.y < P_SCROLL_Y_BOTTOM && m_speed.y > 0 && m_scrolledDistance.y < STAGE_HEIGHT && m_isOnScrollArea == false)
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
			//m_speed.y = 0;
		}
		if (m_scrolledDistance.y > STAGE_HEIGHT)
		{
			m_scrolledDistance.y = STAGE_HEIGHT;
			//m_speed.y = 0;
		}
		SCROLL_Y = m_scrolledDistance.y;
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

	if (m_pos.y > PAGE_HEIGHT + m_size.y + 100.0f)
	{
		//Effect::searchSet(pEffectManager->m_ppEffect, EFF_OBJ_MAX_NUM, Vector3(m_pos.x, m_pos.y - m_size.y / 2, 0), m_liveInPagination, effectDisappear);
		//MFAudioPlay(SE_DEAD);
		if (m_mode == P_MODE::NORMAL) {
			m_mode = P_MODE::RESTART;
		}
		if (m_mode == P_MODE::CLEAR) {
			m_pos.y = PAGE_HEIGHT + m_size.y + 100.0f;
		}
	}

	if (m_pos.y < m_size.y)
	{
		m_pos.y = m_size.y;
		m_speed.y = 0;
	}


	// 鍵移動
	/*if (m_pKeyObj[m_keyCounter - 1].m_pSprData)
	{
		syncKeyPos();
	}*/

	// アニメーションデータ
	if (fabsf(m_speed.x - 0.0f) > FLT_EPSILON && m_isOnGround && m_pAnimeData != e_pAnimePlayerRun)
	{
		m_animeNO = 0;
		m_pAnimeData = e_pAnimePlayerRun;
	}

	static Effect* pRuningEff = nullptr;
	if (m_pAnimeData == e_pAnimePlayerRun && m_animeNO == 0 && m_isOnGround && !m_isOnBlurArea) {
		pRuningEff = Effect::searchSet(pEffectManager->m_ppEffect, EFF_OBJ_MAX_NUM, m_pos + Vector3(m_custom.reflectX ? -20 : 40, 0, 0), m_liveInPagination, effectRunning, 0, m_custom.reflectX);
	}
	if (pRuningEff && m_isOnGround) {
		pRuningEff->m_pos.x += m_speed.x;
		pRuningEff->m_pos.y = m_pos.y / PAGE_HEIGHT*SCREEN_HEIGHT;
	}
	if (!m_isOnGround && pRuningEff)
	{
		pRuningEff->clear();
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

	/*if (m_life < 0)
	{
		m_mode = P_MODE::DEAD;
	}*/
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

}

void Player::restartMove()
{

	m_isMoving = false;
	switch (m_step)
	{
	case STEP::INIT:
		if (m_pBorder)
		{
			m_pBorder->m_step = STEP::INIT;
			m_pBorder->m_doReverseMove = true;
			m_pBorder = nullptr;
		}
		if (m_concentration < P_CONCENTRATION_MAX) {
			Effect::searchSet(pEffectManager->m_ppEffect, EFF_OBJ_MAX_NUM, Vector3(m_pos.x, m_pos.y - m_size.y / 2, 0), m_liveInPagination, effectDisappear);
			MFAudioPlay(SE_DEAD);
		}
		m_speed.x = 0;
		m_speed.y = 0;
		m_alpha = 0;
		if (m_isKeyHandled){
			m_pKeyObj[m_keyCounter - 1].m_alpha = 0;
		}
		m_step = STEP::BEGIN;
		m_liveInPagination = START_PAGINATION;
		m_timer = 0;
		m_isOnScrollArea = false;
		m_speed.y = -m_scrolledDistance.y / 10.0f;
		//MFAudioPlay(SE_DEAD);
		//break;
	case STEP::BEGIN:
		m_timer++;
		if (m_timer > 80 || (m_life == P_LIFE_MAX && m_timer > 20))
		{
			m_timer = 0;
			//m_speed.y = -m_scrolledDistance.y / 10;
			m_step = STEP::BEGIN + 1;
		}
		break;
	case STEP::BEGIN+1:
		m_isOnScrollArea = true;
		m_pos.y += m_speed.y;
		m_scrolledDistance.y += m_speed.y;
		SCROLL_Y = m_scrolledDistance.y;
		if (m_isOnScrollArea)
		{
			if (m_speed.y*m_scrolledDistance.y >= 0)
			{
				//m_speed.y = 0;
				//m_isOnScrollArea = false;
				m_scrolledDistance.y = 0;
				SCROLL_Y = m_scrolledDistance.y;
				--m_life;
				if (m_life >= 0) {
					m_pos = INIT_POS;
					//Effect::searchSet(pEffectManager->m_ppEffect, EFF_OBJ_MAX_NUM, INIT_POS, m_liveInPagination, effectPlayerInit);
					Effect::searchSet(pEffectManager->m_ppEffect, EFF_OBJ_MAX_NUM, INIT_POS, START_PAGINATION, effectStampShadowMove);
					Effect::searchSet(pEffectManager->m_ppEffect, EFF_OBJ_MAX_NUM, INIT_POS, START_PAGINATION, effectStampMove);
				}
				else {
					m_mode = P_MODE::DEAD;
					break;
				}
				m_step = STEP::END;
			}
		}
		syncKeyPos();
		if (m_isKeyHandled) {
			m_pKeyObj[m_keyCounter - 1].m_alpha = 0;
		}
		break;
	case STEP::END:
		if (pEffectManager->isStampDown) {
			restart();
			pEffectManager->isStampDown = false;
			//m_speed.y = 0;
			//m_isOnScrollArea = false;


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
	m_hitObj.m_liveInPagination = m_liveInPagination;

	// プレイヤーが通過したところにランダムで滲む判定用Objを配置
	static Vector3 randAdjust;
	static Vector3 initSize = m_size / 2.0f;
	for (int i = 0, maxInOnce = 3; i < maxInOnce; i++) {

		/*randAdjust = { (float)(rand() % (int)(fabsf(m_speed.x) + m_size.x)), (float)(rand() % (int)(fabsf(m_speed.y) + m_size.y)),0 };
		if (fabsf(m_speed.x - 0.0f) < FLT_EPSILON && !m_isOnGround) {
			randAdjust.x -= m_size.x / 2 - 10.0f;
			randAdjust.y -= m_size.y / 2 - 10.0f;
		}
		if (m_isOnGround) {
			randAdjust.x += m_size.x / 2 - 10.0f;
		}

		if (fabsf(m_speed.x - 0.0f) > FLT_EPSILON) {
			randAdjust.x *= (m_speed.x / fabsf(m_speed.x));
		}
		if (fabsf(m_speed.y - 0.0f) > FLT_EPSILON) {
			randAdjust.y *= (m_speed.y / fabsf(m_speed.y));
		}*/
		randAdjust.x = (float)(rand() % (int)initSize.x - initSize.x / 2.0f);
		randAdjust.y = -(float)(rand() % (int)initSize.y + initSize.y / 2.0f);

		m_hitObj.m_pos = m_pos + randAdjust;
		m_hitObj.m_initPos = m_hitObj.m_pos + m_scrolledDistance;
		m_hitObj.m_custom.angle = rand() % 180;
		m_hitObj.m_alpha = rand() % 5 + 10;
		m_hitObj.m_pfMove = &OBJ2D::blur;
		m_newblurAreaList.push_back(m_hitObj);
	}
}

void Player::update()
{
	switch (m_mode)
	{
	case P_MODE::START:
		if (pEffectManager->isStampDown) m_mode = P_MODE::NORMAL;
		break;
	case P_MODE::CLEAR:
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

	//if (m_isKeyHandled || m_mode == P_MODE::CLEAR) {
	//	m_pKeyObj[m_keyCounter - 1].draw();
	//	//m_pKeyObj[m_keyCounter - 1].m_pos = m_pos - Vector3(!m_custom.reflectX ? -m_size.x / 2 : m_pKeyObj[m_keyCounter - 1].m_pSprData->width + m_size.x / 2, m_pKeyObj[m_keyCounter - 1].m_pSprData->height, 0);
	//}
	if (m_pBorder && m_pBorder->m_pSprData) {
		m_pBorder->m_pSprData->copy(m_pSprData);
		//m_pBorder->m_pSprData->height	= m_pSprData->height;
		//m_pBorder->m_pSprData->width	= m_pSprData->width;
		//m_pBorder->m_pSprData->top		= m_pSprData->top;
		//m_pBorder->m_pSprData->left		= m_pSprData->left;
		//m_pBorder->m_pSprData->ofsX		= m_pSprData->ofsX;
		//m_pBorder->m_pSprData->ofsY		= m_pSprData->ofsY;
		m_pBorder->m_pos.x = m_pos.x / PAGE_WIDTH*(SCREEN_WIDTH / 2);
		if (m_liveInPagination % 2 == 0) {
			m_pBorder->m_pos.x += SCREEN_WIDTH / 2;
		}
		m_pBorder->m_pos.y = m_pos.y / PAGE_HEIGHT*SCREEN_HEIGHT;
		//m_pBorder->m_pos = m_pos;
		m_pBorder->m_custom.reflectX = m_custom.reflectX;
	}

	OBJ2DEX::draw();
	if (m_mode == P_MODE::NORMAL || m_mode == P_MODE::CLEAR)
	{
		//*(m_eyes.m_pSprData) = *(m_pSprData);
		m_eyes.m_pSprData->copy(m_pSprData);
		//m_eyes.m_pSprData->texNum = m_pSprData->texNum + 1;
		m_eyes.m_pos = m_pos;
		m_eyes.m_custom = m_custom;
		m_eyes.draw();
	}

#ifdef DEBUG

	char buf[512];
	sprintf_s(buf, "ScrolledDisY: %f \nPosY: %f \nSpeedY: %f \nConcentration: %lf \nBlurSpeed: %lf \n\nLife: %d \nSTAGE_HEIGHT: %d \nState: %d",
		m_scrolledDistance.y, m_pos.y, m_speed.y, m_concentration, m_blurSpeed, m_life, STAGE_HEIGHT, m_montionState);
	drawString(0, 200, buf, 0x000000FF, STR_LEFT, 24, 24);

	drawRectangle(m_pos.x - 2, m_pos.y - 4, 4, 4, 0, 0x0000FFFF);

	//if (m_type == 0)
	//{
	//	drawRectangle(0, 0, PAGE_WIDTH, P_SCROLL_Y_TOP, 0, 0xFFFFFF40);
	//	drawRectangle(0, P_SCROLL_Y_BOTTOM, PAGE_WIDTH, PAGE_HEIGHT - P_SCROLL_Y_BOTTOM, 0, 0xFFFFFF40);
	//}
	//else
	//{
	//	if (m_type == 1)
	//	{
	//		drawRectangle(0, 0, PAGE_WIDTH, P_SCROLL_Y_TOP, 0, 0xFF000080);
	//	}
	//	if (m_type == 2)
	//	{
	//		drawRectangle(0, P_SCROLL_Y_BOTTOM, PAGE_WIDTH, PAGE_HEIGHT - P_SCROLL_Y_BOTTOM, 0, 0x0000FF80);
	//	}
	//} 

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

void Player::syncKeyPos()
{
	if (m_isKeyHandled && m_mode != P_MODE::CLEAR && m_pKeyObj[m_keyCounter - 1].m_isHitAble)
	{
		m_pKeyObj[m_keyCounter - 1].m_alpha = 255;
		m_pKeyObj[m_keyCounter - 1].m_setPos = m_pos - Vector3(!m_custom.reflectX ? -m_size.x / 2 : m_pKeyObj[m_keyCounter - 1].m_pSprData->width + m_size.x / 2, m_pKeyObj[m_keyCounter - 1].m_pSprData->height, 0);
		if (m_pKeyObj[m_keyCounter - 1].m_setPos.x > PAGE_WIDTH - m_pKeyObj[m_keyCounter - 1].m_pSprData->width - m_size.x) {
			m_pKeyObj[m_keyCounter - 1].m_setPos.x = PAGE_WIDTH - m_pKeyObj[m_keyCounter - 1].m_pSprData->width - m_size.x;
		}
		if (m_pKeyObj[m_keyCounter - 1].m_setPos.x < 0 + m_size.x) {
			m_pKeyObj[m_keyCounter - 1].m_setPos.x = 0 + m_size.x;
		}
		if (m_pKeyObj[m_keyCounter - 1].m_setPos.y > PAGE_HEIGHT - m_pKeyObj[m_keyCounter - 1].m_pSprData->height) {
			m_pKeyObj[m_keyCounter - 1].m_setPos.y = PAGE_HEIGHT - m_pKeyObj[m_keyCounter - 1].m_pSprData->height;
		}
		if (m_pKeyObj[m_keyCounter - 1].m_setPos.y < 0) {
			m_pKeyObj[m_keyCounter - 1].m_setPos.y = 0;
		}
	}

	for (int i = 0; i < P_KEY_MAX_NUM; i++)
	{
		if (!m_pKeyObj[i].m_isHitAble && m_pKeyObj[i].m_pSprData){
			//m_pKeyObj[i].m_setPos.y = m_pKeyObj[i].m_pos.y = m_pKeyObj[i].m_initPos.y - SCROLL_Y/* - m_pKeyObj[i].m_initPos.z*/;
			//m_pKeyObj[i].m_setPos.x = m_pKeyObj[i].m_pos.x = m_pKeyObj[i].m_initPos.x;
			//continue;
			++m_pKeyObj[i].m_timer;
			if (m_pKeyObj[i].m_timer < 20) {
				m_pKeyObj[i].m_setPos.y = m_pKeyObj[i].m_initPos.y - SCROLL_Y/* - m_pKeyObj[i].m_initPos.z*/;
				m_pKeyObj[i].m_setPos.x = m_pKeyObj[i].m_initPos.x;
			}
			else if(m_pKeyObj[i].m_pSprData){
				m_pKeyObj[i].m_timer = 40;
				m_pKeyObj[i].m_setPos.y = m_pKeyObj[i].m_pos.y = m_pKeyObj[i].m_initPos.y - SCROLL_Y/* - m_pKeyObj[i].m_initPos.z*/;
				m_pKeyObj[i].m_setPos.x = m_pKeyObj[i].m_pos.x = m_pKeyObj[i].m_initPos.x;
				continue;
			}
		}

		if (m_pKeyObj[i].m_pos.x < m_pKeyObj[i].m_setPos.x) {
			m_pKeyObj[i].m_pos.x += (m_pKeyObj[i].m_setPos.x - m_pKeyObj[i].m_pos.x) / 5;
			if (m_pKeyObj[i].m_pos.x > m_pKeyObj[i].m_setPos.x) {
				m_pKeyObj[i].m_pos.x = m_pKeyObj[i].m_setPos.x;
			}
		}
		if (m_pKeyObj[i].m_pos.x > m_pKeyObj[i].m_setPos.x) {
			m_pKeyObj[i].m_pos.x += (m_pKeyObj[i].m_setPos.x - m_pKeyObj[i].m_pos.x) / 5;
			if (m_pKeyObj[i].m_pos.x < m_pKeyObj[i].m_setPos.x) {
				m_pKeyObj[i].m_pos.x = m_pKeyObj[i].m_setPos.x;
			}
		}
		if (m_pKeyObj[i].m_pos.y < m_pKeyObj[i].m_setPos.y) {
			m_pKeyObj[i].m_pos.y += (m_pKeyObj[i].m_setPos.y - m_pKeyObj[i].m_pos.y) / 5;
			if (m_pKeyObj[i].m_pos.y > m_pKeyObj[i].m_setPos.y) {
				m_pKeyObj[i].m_pos.y = m_pKeyObj[i].m_setPos.y;
			}
		}
		if (m_pKeyObj[i].m_pos.y > m_pKeyObj[i].m_setPos.y) {
			m_pKeyObj[i].m_pos.y += (m_pKeyObj[i].m_setPos.y - m_pKeyObj[i].m_pos.y) / 5;
			if (m_pKeyObj[i].m_pos.y < m_pKeyObj[i].m_setPos.y) {
				m_pKeyObj[i].m_pos.y = m_pKeyObj[i].m_setPos.y;
			}
		}
	}

}

void Player::setScrollKeys(Vector3 a_speed)
{
	for (OBJ2D &it : pPlayerManager->m_pPlayer->m_pKeyObj)
	{
		if (!it.m_isHitAble)
		{
			it.m_pos.y -= a_speed.y;
			it.m_setPos.y -= a_speed.y;
			if (a_speed.y < 0 && it.m_pos.y > it.m_initPos.y)
			{
				it.m_pos.y = it.m_initPos.y;
				it.m_setPos.y= it.m_initPos.y;
			}
			if (a_speed.y > 0 && it.m_pos.y < it.m_initPos.y - STAGE_HEIGHT)
			{
				it.m_pos.y = it.m_initPos.y - STAGE_HEIGHT;
				it.m_setPos.y = it.m_initPos.y - STAGE_HEIGHT;
			}
			//it.m_setPos.y = it.m_pos.y;
		}
	}
}

////////////////////////////////////////////////////////////////////////

// Player Manager Class
PlayerManager::PlayerManager()
{
	//init();
	m_isTranscriptAble = false;
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
		//Effect::searchSet(pEffectManager->m_ppEffect, EFF_OBJ_MAX_NUM, INIT_POS, m_pPlayer->m_liveInPagination, effectPlayerInit);
		//m_pPlayer->m_mode = P_MODE::RESTART;
	}
	else
	{
		m_pPlayer->clear();
		m_pPlayer->init();
		//Effect::searchSet(pEffectManager->m_ppEffect, EFF_OBJ_MAX_NUM, INIT_POS, m_pPlayer->m_liveInPagination, effectPlayerInit);
		//m_pPlayer->m_mode = P_MODE::RESTART;
	}
	m_isTranscriptAble = false;
}

void PlayerManager::update()
{
	if (m_pPlayer)
	{
		m_pPlayer->update();
	}
}

void PlayerManager::draw(int a_liveInPagination)
{
	if (m_pPlayer)
	{
		for (int i = 0; i < P_KEY_MAX_NUM; i++)
		{
			if (a_liveInPagination == m_pPlayer->m_pKeyObj[i].m_liveInPagination) {
				m_pPlayer->m_pKeyObj[i].draw();
			}
		}
		if (m_pPlayer->m_liveInPagination == a_liveInPagination){
			m_pPlayer->draw();
		}
	}
}

void PlayerManager::manageConcentration()
{
	static float transferConcentration = 0, transferSpeed = 0;

	switch (m_step)
	{
	case STEP::INIT:
		m_isTranscriptAble = true;
		m_isTranscriptCanceled = false;
		m_step = STEP::INIT + 1;
		if (m_pPlayer->m_isKeyHandled){
			m_pPlayer->m_pKeyObj[m_pPlayer->m_keyCounter - 1].m_alpha = 0;
		}
		break;
	case STEP::INIT+1:
		m_isPlayerOnLeft = m_pPlayer->m_liveInPagination % 2 != 0;
		m_concentration = m_pPlayer->m_concentration;
		transferSpeed = 0;
		if (m_isTranscriptAble)
		{
			if (m_concentration > /*P_TRANSFER_CONCENTRATION_MAX*/0.0f)
			{
				//m_pPlayer->m_concentration /= 2;

				//m_pPlayer->m_transferConcentration = m_concentration - m_pPlayer->m_concentration;
				transferConcentration = m_concentration >= P_TRANSFER_CONCENTRATION_MAX ? P_TRANSFER_CONCENTRATION_MAX : m_concentration;
				m_pPlayer->m_transferConcentration = m_concentration;
				m_pPlayer->m_concentration = m_concentration - m_pPlayer->m_transferConcentration;
				m_step = STEP::BEGIN;
			}
			/*else
			{
				m_step = STEP::END;
			}*/
		}
		else
		{
			m_step = STEP::END;
		}
		break;
	case STEP::BEGIN:
		transferSpeed += 0.07f;
		m_pPlayer->m_transferConcentration -= transferSpeed;
		if (m_pPlayer->m_transferConcentration < /*P_TRANSFER_CONCENTRATION_MAX*/transferConcentration)
		{
			m_pPlayer->m_transferConcentration = /*P_TRANSFER_CONCENTRATION_MAX*/transferConcentration;
			if (fabsf(transferConcentration- m_concentration)<FLT_EPSILON){
				m_isTranscriptCanceled = true;
			}
			m_isTranscriptAble = true;
			m_step = STEP::FINISH;
		}
		m_pPlayer->m_concentration = m_concentration - m_pPlayer->m_transferConcentration;
		/*if (m_isTranscriptCanceled)
		{
			transferConcentration = 0;
			m_pPlayer->m_transferConcentration = 0;
			m_pPlayer->m_concentration = m_concentration;
			m_isTranscriptAble = false;
			m_step = STEP::INIT;
		}*/

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
		transferConcentration = 0;
		m_pPlayer->m_transferConcentration = 0;
		m_pPlayer->m_concentration = m_concentration;
		m_isTranscriptAble = false;
		m_step = STEP::FINISH;
		//break;
	case STEP::FINISH:

		break;
	default:
		break;
	}
	if (m_step >= STEP::BEGIN)
	{
		pGameUIManager->showInkTransferGage(m_pPlayer->m_concentration, m_pPlayer->m_transferConcentration, m_isPlayerOnLeft, m_isTranscriptAble, m_pPlayer->m_pSprData, m_pPlayer->m_custom.reflectX);
	}

}

void PlayerManager::transcriptPlayer(int a_concentration)
{
	if (m_pPlayer && m_pPlayer->m_mode!=P_MODE::DEAD)
	{
		if (m_isTranscriptAble)
		{
			// 転写元を作成
			m_transcriptionObj.m_isInit = true;
			m_transcriptionObj.m_pos = m_pPlayer->m_pos;
			m_transcriptionObj.m_initPos = m_transcriptionObj.m_pos + m_pPlayer->m_scrolledDistance;
			m_transcriptionObj.m_size = m_pPlayer->m_size;
			m_transcriptionObj.m_pos.z--;
			m_transcriptionObj.m_custom = m_pPlayer->m_custom;
			m_transcriptionObj.m_concentration = m_pPlayer->m_transferConcentration;
			m_transcriptionObj.m_alpha = 255 * m_transcriptionObj.m_concentration / 10 + 40;
			m_transcriptionObj.m_pSprData = m_pPlayer->m_pSprData;
			m_transcriptionObj.m_liveInPagination = m_pPlayer->m_liveInPagination;

			pBook->m_ppPapers[m_pPlayer->m_liveInPagination / 2]->m_transcriptionList[m_pPlayer->m_liveInPagination % 2].push_back(m_transcriptionObj);

			if (m_isTranscriptCanceled)
			{
				m_pPlayer->m_mode = P_MODE::RESTART;
			}
			else
			{
				// 隣のページへ転写
				m_pPlayer->m_liveInPagination += m_pPlayer->m_liveInPagination % 2 ? 1 : -1;
				m_pPlayer->m_pos.x = PAGE_WIDTH - m_pPlayer->m_pos.x;
				if (m_pPlayer->m_isKeyHandled){
					if (m_pPlayer->m_isKeyHandled && m_pPlayer->m_pKeyObj[m_pPlayer->m_keyCounter - 1].m_isHitAble) {
						m_pPlayer->m_pKeyObj[m_pPlayer->m_keyCounter - 1].m_setPos.x = PAGE_WIDTH - m_pPlayer->m_pKeyObj[m_pPlayer->m_keyCounter - 1].m_pos.x - m_pPlayer->m_pKeyObj[m_pPlayer->m_keyCounter - 1].m_pSprData->width;
						m_pPlayer->m_pKeyObj[m_pPlayer->m_keyCounter - 1].m_pos.x = m_pPlayer->m_pKeyObj[m_pPlayer->m_keyCounter - 1].m_setPos.x;
						m_pPlayer->m_pKeyObj[m_pPlayer->m_keyCounter - 1].m_liveInPagination += m_pPlayer->m_pKeyObj[m_pPlayer->m_keyCounter - 1].m_liveInPagination % 2 ? 1 : -1;
					}
				}
				m_pPlayer->m_speed = { 0,-0.1f,0 };
				m_pPlayer->m_isOnGround = false;
				m_pPlayer->m_jumpCounter = 1;
				m_pPlayer->m_custom.reflectX = !m_pPlayer->m_custom.reflectX;
				m_pPlayer->m_timer = 0;
				//m_pPlayer->m_montionState = P_STATE::STANDBY;
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
