#include "game.h"
#include "sprite_data.h"
#include "effect.h"

////////////////////////////////////////////////////////
// クラス: Effect 関数

void Effect::memberCopy(const Effect& a_inputObj)
{
	OBJ2DEX::memberCopy(a_inputObj);
	
	m_isVisible = a_inputObj.m_isVisible;
	m_isVisibleAlways = a_inputObj.m_isVisibleAlways;
	m_isAnimeOnce = a_inputObj.m_isAnimeOnce;
	recordedAnimeNO = a_inputObj.recordedAnimeNO;

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

void Effect::clear()
{
	OBJ2DEX::clear();
	m_isVisible = false;
	m_isVisibleAlways = false;
	m_isAnimeOnce = false;
	recordedAnimeNO = 0;
	m_pfMove = nullptr;
}

Effect::Effect()
{
	clear();
}


void Effect::init()
{

	m_isInit = true;
	m_isVisible = true;
	m_isVisibleAlways = true;
	m_isAnimeOnce = false;
	recordedAnimeNO = 0;
	m_custom.scaleMode = SCALE_MODE::CENTER;
}

void Effect::update()
{
	if (m_pfMove)
	{
		m_pfMove(this);
	}
	animation();
}

void Effect::draw()
{
	if (m_isVisible)
	{
		OBJ2DEX::draw();
		if (!m_isVisibleAlways)
		{
			m_isVisible = false;
		}
	}
}

Effect* Effect::searchSet(Effect** a_ppBegin, int a_maxNum, int a_liveInPagination, Vector3 a_pos, void(*a_pfMove)(Effect*))
{
	for (int i = 0; i < a_maxNum; i++)
	{
		if (a_ppBegin[i]->m_isInit) {
			continue;
		}
		else {
			a_ppBegin[i]->clear();
		}
		a_ppBegin[i]->m_liveInPagination = a_liveInPagination;
		a_ppBegin[i]->m_pos = a_pos;
		a_ppBegin[i]->m_pfMove = a_pfMove;
		a_ppBegin[i]->init();

		return a_ppBegin[i];
	}
	return nullptr;
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
		if (pEff)
		{
			pEff->clear();
		}
		if (!pEff)
		{
			pEff = new Effect();
		}
	}

	isStampDown = false;
	m_ppEffect[ANIME_STAMP]->m_isVisibleAlways = false;
	m_ppEffect[ANIME_STAMP]->m_isVisible = false;

}

void EffectManager::update()
{
	for (auto &pEff : m_ppEffect)
	{
		if (pEff)
		{

			pEff->update();

			pEff->recordedAnimeNO = pEff->m_animeNO;
			pEff->m_isVisible = true;

			
			if (pEff == recordedPTR && pEff->m_animeNO == 7)
			{
				isStampDown = true;
			}
			if (pEff->m_isAnimeOnce && pEff->recordedAnimeNO > pEff->m_animeNO)
			{
				pEff->clear();
			}

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
		}
	}

}

void EffectManager::setPlayerInitAnimation(Vector3 a_pos) {
	m_ppEffect[ANIME_STAMP]->m_pAnimeData = e_pAnimeStamp;
	m_ppEffect[ANIME_STAMP]->m_pSprData = &m_ppEffect[ANIME_STAMP]->m_pAnimeData[0];
	m_ppEffect[ANIME_STAMP]->m_pos = Vector3(a_pos.x,a_pos.y - 30,a_pos.z);
	m_ppEffect[ANIME_STAMP]->m_isVisible = true;
	m_ppEffect[ANIME_STAMP]->m_isAnimeOnce = true;
	m_ppEffect[ANIME_STAMP]->m_pfMove = movePlayerInitAnimation;
	isStampDown = false;
	recordedPTR = m_ppEffect[ANIME_STAMP];
}

void movePlayerInitAnimation(Effect *obj) {
	switch (obj->m_step)
	{
	case INIT:
		obj->m_timer = 0;
		obj->m_alpha = 0;
		obj->m_step = BEGIN;
		//break;
	case BEGIN:
		obj->m_timer++;
		obj->m_alpha += 10;
		if (obj->m_timer > 100) obj->m_step = BEGIN + 1;
		break;
	case BEGIN + 1:
		obj->m_alpha -= 10;
		break;
	}
	

}

