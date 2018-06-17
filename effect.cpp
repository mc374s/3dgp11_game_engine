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

Effect* Effect::searchSet(Effect** a_ppBegin, int a_maxNum, Vector3 a_pos, int a_liveInPagination, void(*a_pfMove)(Effect*), int a_type, bool a_isReflect)
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
		if (a_liveInPagination % 2 != 0)
		{
			a_ppBegin[i]->m_pos = a_pos;
		}
		else
		{
			a_ppBegin[i]->m_pos = a_pos;
			a_ppBegin[i]->m_pos.x = SCREEN_WIDTH / 2 + a_ppBegin[i]->m_pos.x / PAGE_WIDTH*(SCREEN_WIDTH / 2);
		}
		a_ppBegin[i]->m_pos.y = a_pos.y / PAGE_HEIGHT*SCREEN_HEIGHT;
		a_ppBegin[i]->m_type = a_type;
		a_ppBegin[i]->m_pfMove = a_pfMove;
		a_ppBegin[i]->m_custom.reflectX = a_isReflect;
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
			drawRectangle(pEff->m_pos.x - 2, pEff->m_pos.y - 4, 4, 4, 0, 0x0000FFFF);
			if (!pEff->m_isVisibleAlways)
			{
				pEff->m_isVisible = false;
			}
		}
	}

}

void EffectManager::setScroll(Vector3 a_speed, int a_liveInPagination, bool a_isRestart)
{
	for (auto &it : m_ppEffect)
	{
		it->m_pos.y -= a_speed.y;
		if (a_speed.y < 0 && it->m_pos.y > it->m_initPos.y && a_isRestart)
		{
			it->m_pos.y = it->m_initPos.y;
		}
		if (a_speed.y > 0 && it->m_pos.y < it->m_initPos.y - STAGE_HEIGHT)
		{
			it->m_pos.y = it->m_initPos.y - STAGE_HEIGHT;
		}
	}

}

void effectPlayerInit(Effect *obj) {
	switch (obj->m_step)
	{
	case STEP::INIT:
		obj->m_pAnimeData = e_pAnimeStamp;
		obj->m_pSprData = &obj->m_pAnimeData[0];
		obj->m_pos.y -= 30;
		obj->m_isVisible = true;
		obj->m_pfMove = effectPlayerInit;
		pEffectManager->isStampDown = false;
		obj->m_timer = 0;
		obj->m_alpha = 0;
		obj->m_initPos = obj->m_pos;
		obj->m_step = STEP::BEGIN;
		//break;
	case STEP::BEGIN:
		obj->m_isVisible = true;
		obj->m_timer++;
		obj->m_alpha += 10;
		if (obj->m_alpha >= 255) obj->m_step = STEP::BEGIN + 1;
		break;
	case STEP::BEGIN + 1:
		obj->m_isVisible = true;
		obj->m_timer++;
		if (obj->m_animeNO == 4) pEffectManager->isStampDown = true;
		if (obj->m_timer > 100) obj->m_alpha -= 10;
		if (obj->m_timer > 130) obj->m_step = STEP::FINISH;
		break;
	case STEP::FINISH:
		obj->clear();
		break;
	default:
		break;
	}

}

void effectJumpUp(Effect *obj) {
	switch (obj->m_step)
	{
	case STEP::INIT:
		obj->m_pAnimeData = e_pAnimeEffJumpUp;
		obj->m_pSprData = &obj->m_pAnimeData[0];
		obj->m_isVisible = true;
		obj->m_pfMove = effectJumpUp;
		obj->m_timer = 0;
		obj->m_initPos = obj->m_pos;
		obj->m_step = STEP::BEGIN;
		//break;
	case STEP::BEGIN:
		obj->m_isVisible = true;
		obj->m_timer++;
		if (obj->m_timer > 24) obj->m_step = STEP::FINISH;
		break;
	case STEP::FINISH:
		obj->clear();
		break;
	default:
		break;
	}

}

void effectJumpDown(Effect *obj) {
	switch (obj->m_step)
	{
	case STEP::INIT:
		obj->m_pAnimeData = e_pAnimeEffJumpDown;
		obj->m_pSprData = &obj->m_pAnimeData[0];
		obj->m_isVisible = true;
		obj->m_pfMove = effectJumpDown;
		obj->m_timer = 0;
		obj->m_initPos = obj->m_pos;
		obj->m_step = STEP::BEGIN;
		//break;
	case STEP::BEGIN:
		obj->m_isVisible = true;
		obj->m_timer++;
		if (obj->m_timer > 24) obj->m_step = STEP::FINISH;
		break;
	case STEP::FINISH:
		obj->clear();
		break;
	default:
		break;
	}

}

void effectRecoveryPassed(Effect* a_pObj)
{
	switch (a_pObj->m_step)
	{
	case STEP::INIT:
		a_pObj->m_pAnimeData = e_pAnimeEffRecoveryPassed;
		a_pObj->m_pSprData = &a_pObj->m_pAnimeData[0];
		a_pObj->m_pfMove = effectRecoveryPassed;
		a_pObj->m_timer = 0;
		if (a_pObj->m_type == 1)
		{
			a_pObj->m_custom.reflectX = true;
			a_pObj->m_custom.angle = 180;
		}
		if (a_pObj->m_type == 0)
		{
			a_pObj->m_pos.y += a_pObj->m_pSprData->height;
		}
		a_pObj->m_initPos = a_pObj->m_pos;
		a_pObj->m_step = STEP::BEGIN;
		//break;
	case STEP::BEGIN:
		if (a_pObj->m_animeCounter > 0) {
			a_pObj->clear();
			a_pObj->m_step = STEP::END;
		}
		break;
	case STEP::END:
		a_pObj->m_step = STEP::FINISH;
		//break;
	case STEP::FINISH:
		break;
	default:
		break;
	}
}

void effectDisappear(Effect* a_pObj)
{
	switch (a_pObj->m_step)
	{
	case STEP::INIT:
		a_pObj->m_pAnimeData = e_pAnimeEffDisappear;
		a_pObj->m_pSprData = &a_pObj->m_pAnimeData[0];
		a_pObj->m_pfMove = effectDisappear;
		a_pObj->m_timer = 0;
		
		a_pObj->m_initPos = a_pObj->m_pos;
		a_pObj->m_step = STEP::BEGIN;
		//break;
	case STEP::BEGIN:
		if (a_pObj->m_animeCounter > 0) {
			a_pObj->clear();
			a_pObj->m_step = STEP::END;
		}
		break;
	case STEP::END:
		a_pObj->m_step = STEP::FINISH;
		//break;
	case STEP::FINISH:
		break;
	default:
		break;
	}
}

void effectMakeTranscription(Effect* a_pObj)
{
	switch (a_pObj->m_step)
	{
	case STEP::INIT:
		a_pObj->m_pAnimeData = e_pAnimeEffMakeTranscription;
		a_pObj->m_pSprData = &a_pObj->m_pAnimeData[0];
		a_pObj->m_pfMove = effectMakeTranscription;
		a_pObj->m_timer = 0;

		a_pObj->m_initPos = a_pObj->m_pos;
		a_pObj->m_step = STEP::BEGIN;
		//break;
	case STEP::BEGIN:
		if (a_pObj->m_animeCounter > 0) {
			a_pObj->clear();
			a_pObj->m_step = STEP::END;
		}
		break;
	case STEP::END:
		a_pObj->m_step = STEP::FINISH;
		//break;
	case STEP::FINISH:
		break;
	default:
		break;
	}
}

void effectDamaging(Effect* a_pObj)
{
	switch (a_pObj->m_step)
	{
	case STEP::INIT:
		a_pObj->m_pAnimeData = e_pAnimeEffDamaging;
		a_pObj->m_pSprData = &a_pObj->m_pAnimeData[0];
		a_pObj->m_pfMove = effectDamaging;
		a_pObj->m_timer = 0;

		a_pObj->m_initPos = a_pObj->m_pos;
		a_pObj->m_step = STEP::BEGIN;
		//break;
	case STEP::BEGIN:
		if (a_pObj->m_animeCounter > 0) {
			a_pObj->clear();
			a_pObj->m_step = STEP::END;
		}
		break;
	case STEP::END:
		a_pObj->m_step = STEP::FINISH;
		//break;
	case STEP::FINISH:
		break;
	default:
		break;
	}
}

void effectRunning(Effect* a_pObj)
{
	switch (a_pObj->m_step)
	{
	case STEP::INIT:
		a_pObj->m_pAnimeData = e_pAnimeEffRunning;
		a_pObj->m_pSprData = &a_pObj->m_pAnimeData[0];
		a_pObj->m_pfMove = effectRunning;
		a_pObj->m_timer = 0;
		a_pObj->m_initPos = a_pObj->m_pos;
		a_pObj->m_step = STEP::BEGIN;
		//break;
	case STEP::BEGIN:
		if (a_pObj->m_animeCounter > 0) {
			a_pObj->clear();
			a_pObj->m_step = STEP::END;
		}
		break;
	case STEP::END:
		a_pObj->m_step = STEP::FINISH;
		//break;
	case STEP::FINISH:
		break;
	default:
		break;
	}
}

void effectOnBlurArea(Effect* a_pObj)
{
	switch (a_pObj->m_step)
	{
	case STEP::INIT:
		a_pObj->m_pAnimeData = e_pAnimeEffOnBlurArea;
		a_pObj->m_pSprData = &a_pObj->m_pAnimeData[0];
		a_pObj->m_pfMove = effectOnBlurArea;
		a_pObj->m_timer = 0;
		a_pObj->m_initPos = a_pObj->m_pos;
		a_pObj->m_step = STEP::BEGIN;
		//break;
	case STEP::BEGIN:
		if (a_pObj->m_animeCounter > 0) {
			a_pObj->clear();
			a_pObj->m_step = STEP::END;
		}
		break;
	case STEP::END:
		a_pObj->m_step = STEP::FINISH;
		//break;
	case STEP::FINISH:
		break;
	default:
		break;
	}
}