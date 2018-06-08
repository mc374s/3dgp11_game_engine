#include "game.h"
#include "sprite_data.h"
#include "effect.h"

////////////////////////////////////////////////////////
// クラス: Effect 関数

Effect::Effect()
{
	clear();
}

void Effect::memberCopy(const Effect& a_inputObj)
{
	OBJ2D::memberCopy(a_inputObj);

	m_isVisible = a_inputObj.m_isVisible;
	m_isVisibleAlways = a_inputObj.m_isVisibleAlways;

}

Effect::Effect(const Effect& a_inputObj) :OBJ2DEX(a_inputObj)
{
	memberCopy(a_inputObj);
}

Effect::~Effect()
{
	clear();
}

const Effect& Effect::operator=(const Effect& a_right)
{
	memberCopy(a_right);
	return *this;
}


void Effect::init()
{
	m_isInit = true;
	m_isVisible = false;
	m_isVisibleAlways = false;
	m_custom.scaleMode = SCALE_MODE::CENTER;
}

void Effect::update()
{
	if (m_pfMove)
	{
		m_pfMove(this);
		animation();
	}
}

void Effect::draw()
{
	OBJ2DEX::draw();
}

int Effect::searchSet(Effect** a_ppBegin, int a_maxNum, Vector3 a_pos, int a_liveInPagination, void(*a_pfMove)(Effect*))
{
	for (int i = 0; i < a_maxNum; i++)
	{
		if (a_ppBegin[i] && a_ppBegin[i]->m_isInit) {
			continue;
		}
		if (!a_ppBegin[i]) {
			a_ppBegin[i] = new Effect;
		}
		else {
			a_ppBegin[i]->clear();
		}
		a_ppBegin[i]->m_pos = a_pos;
		a_ppBegin[i]->m_pfMove = a_pfMove;
		a_ppBegin[i]->init();
		//a_ppBegin[i]->m_liveInPagination = a_liveInPagination;

		pObjManager->m_ppObjs[GET_IDLE_OBJ_NO] = a_ppBegin[i];
		return i;
	}
	return -1;
}

////////////////////////////////////////////////////////


////////////////////////////////////////////////////////
// クラス: EffectManager 関数
EffectManager::EffectManager()
{

}

EffectManager::~EffectManager()
{
	for (auto &pEff : m_ppEffect)
	{
		if (pEff)
		{
			delete pEff;
			pEff = nullptr;
		}
	}

}

void EffectManager::init()
{
	/////////////////////////////////////////////////////////////////////////////////
	// Initialize m_ppEffect
	for (auto &pEff : m_ppEffect)
	{
		pEff = nullptr;
	}

	isStampDown = false;

}

void EffectManager::update()
{
	for (auto &pEff : m_ppEffect)
	{
		if (pEff)
		{
			pEff->update();
		}
	}
}

void EffectManager::draw()
{
	for (auto &pEff : m_ppEffect)
	{
		if (pEff && pEff->m_pSprData && pEff->m_isVisible)
		{
			pEff->draw();
			if (!pEff->m_isVisibleAlways)
			{
				pEff->m_isVisible = false;
			}
		}
	}

}

void effectPlayerInit(Effect *obj) {
	switch (obj->m_step)
	{
	case INIT:
		obj->m_pAnimeData = e_pAnimeStamp;
		obj->m_pSprData = &obj->m_pAnimeData[0];
		obj->m_pos.y -= 30;
		obj->m_isVisible = true;
		obj->m_pfMove = effectPlayerInit;
		pEffectManager->isStampDown = false;
		obj->m_timer = 0;
		obj->m_alpha = 0;
		obj->m_step = BEGIN;
		//break;
	case BEGIN:
		obj->m_isVisible = true;
		obj->m_timer++;
		obj->m_alpha += 10;
		if (obj->m_alpha >= 255) obj->m_step = BEGIN + 1;
		break;
	case BEGIN + 1:
		obj->m_isVisible = true;
		obj->m_timer++;
		if (obj->m_animeNO == 7) pEffectManager->isStampDown = true;
		if (obj->m_timer > 100) obj->m_alpha -= 10;
		if (obj->m_timer > 130) obj->m_step = FINISH;
		break;
	case FINISH:
		obj->clear();
		break;
	default:
		break;
	}

}

void effectJumpUp(Effect *obj) {
	switch (obj->m_step)
	{
	case INIT:
		obj->m_pAnimeData = e_pAnimeEffJumpUp;
		obj->m_pSprData = &obj->m_pAnimeData[0];
		obj->m_isVisible = true;
		obj->m_pfMove = effectJumpUp;
		obj->m_timer = 0;
		obj->m_step = BEGIN;
		//break;
	case BEGIN:
		obj->m_isVisible = true;
		obj->m_timer++;
		if (obj->m_timer > 24) obj->m_step = FINISH;
		break;
	case FINISH:
		obj->clear();
		break;
	default:
		break;
	}

}

void effectJumpDown(Effect *obj) {
	switch (obj->m_step)
	{
	case INIT:
		obj->m_pAnimeData = e_pAnimeEffJumpDown;
		obj->m_pSprData = &obj->m_pAnimeData[0];
		obj->m_isVisible = true;
		obj->m_pfMove = effectJumpDown;
		obj->m_timer = 0;
		obj->m_step = BEGIN;
		//break;
	case BEGIN:
		obj->m_isVisible = true;
		obj->m_timer++;
		if (obj->m_timer > 24) obj->m_step = FINISH;
		break;
	case FINISH:
		obj->clear();
		break;
	default:
		break;
	}

}