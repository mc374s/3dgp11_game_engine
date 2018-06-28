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

	m_speedAlpha = a_inputObj.m_speedAlpha;
	m_angle = a_inputObj.m_angle;
	m_speedAngle = a_inputObj.m_speedAngle;
	m_speedAngleAcc = a_inputObj.m_speedAngleAcc;
	m_speedAngleMax = a_inputObj.m_speedAngleMax;
	m_radius = a_inputObj.m_radius;
	m_speedRadius = a_inputObj.m_speedRadius;
	m_radiusMax = a_inputObj.m_radiusMax;
	m_doReverseMove = a_inputObj.m_doReverseMove;

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

	m_speedAlpha = 0;
	m_speedAngle = m_angle = m_speedAngleAcc = m_speedAngleMax = { 0.0f,0.0f,0.0f };
	m_radius = 0.0f;
	m_speedRadius = 0.0f;
	m_radiusMax = 0.0f;
	m_doReverseMove = false;
}

Effect::Effect()
{
	clear();
}


void Effect::init()
{
	m_isVisible = true;
	m_isVisibleAlways = true;
	m_custom.scaleMode = SCALE_MODE::CENTER;

	m_isInit = true;
}

void Effect::update()
{
	if (m_pfMove)
	{
		m_pfMove(this);
		if (m_pfMove == effectRecoveryPassed || m_pfMove == effectGoal/* || m_pfMove == effectStampMove || m_pfMove == effectStampShadowMove*/) {
			m_pos.y = m_initPos.y - SCROLL_Y;
		}
	}
	animation();
}

void Effect::draw()
{

	OBJ2DEX::draw();
	/*if (m_isVisible)
	{
		OBJ2DEX::draw();
		if (!m_isVisibleAlways)
		{
			m_isVisible = false;
		}
	}*/
}
// フルスクリーンの座標系にエフェクトを出すときにa_liveInPaginationを奇数に設定必要がある
// ページの座標系にエフェクトを出すときにa_liveInPaginationはそのページナンバーを設定必要がある
Effect* Effect::searchSet(Effect** a_ppBegin, int a_maxNum, Vector3 a_pos, int a_liveInPagination, void(*a_pfMove)(Effect*), int a_type, bool a_isReflect, bool a_doReverseMove)
{
	for (int i = 0; i < a_maxNum; i++)
	{
		if (a_ppBegin[i] && a_ppBegin[i]->m_isInit) {
			continue;
		}
		
		a_ppBegin[i]->clear();
		a_ppBegin[i]->init();
		a_ppBegin[i]->m_liveInPagination = a_liveInPagination;

		a_ppBegin[i]->m_pos.z = a_pos.z;
		a_ppBegin[i]->m_pos.x = a_pos.x / PAGE_WIDTH*(SCREEN_WIDTH / 2);
		if (a_liveInPagination % 2 == 0){
			a_ppBegin[i]->m_pos.x += SCREEN_WIDTH / 2;
		}
		a_ppBegin[i]->m_pos.y = a_pos.y / PAGE_HEIGHT*SCREEN_HEIGHT;
		a_ppBegin[i]->m_initPos = a_ppBegin[i]->m_setPos = a_ppBegin[i]->m_pos;
		a_ppBegin[i]->m_type = a_type;
		a_ppBegin[i]->m_pfMove = a_pfMove;
		a_ppBegin[i]->m_custom.reflectX = a_isReflect;
		a_ppBegin[i]->m_doReverseMove = a_doReverseMove;
		//a_ppBegin[i]->init();

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
	// 描画順番を並び替え　pos.z : 小さい順から描画していく 
	//static Effect *temp = nullptr;
	//for (int i = 1, j = 0; i < EFF_OBJ_MAX_NUM; i++)
	//{
	//	if (m_ppEffect[i - 1] && m_ppEffect[i]/* && (m_ppEffect[i - 1]->m_liveInPagination == m_ppObjs[i]->m_liveInPagination)*/)
	//	{
	//		if (m_ppEffect[i - 1]->m_pos.z < m_ppEffect[i]->m_pos.z)
	//		{
	//			j = i;
	//			do
	//			{
	//				temp = m_ppEffect[j - 1];
	//				m_ppEffect[j - 1] = m_ppEffect[j];
	//				m_ppEffect[j] = temp;
	//				j--;
	//			} while (j > 0 && m_ppEffect[j - 1]->m_pos.z < m_ppEffect[j]->m_pos.z);
	//		}
	//	}
	//}

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
	static int num = 0;
	num = 0;
	for (auto &pEff : m_ppEffect)
	{
		if (pEff && pEff->m_pSprData/* && pEff->m_isVisible*/)
		{
			
			if (pEff->m_pfMove == effectCircleMove)
			{
				MyBlending::setMode(framework::s_pDeviceContext, BLEND_MODE::BLEND_ADD);
			}
			pEff->draw();
			MyBlending::setMode(framework::s_pDeviceContext, BLEND_MODE::BLEND_ALPHA);
			//drawRectangle(pEff->m_pos.x - 2, pEff->m_pos.y - 4, 4, 4, 0, 0x0000FFFF);
			
			/*if (!pEff->m_isVisibleAlways)
			{
				pEff->m_isVisible = false;
			}*/
		}
		if (pEff && pEff->m_isInit)
		{
			num++;
		}
	}

#ifdef DEBUG
	static char buf[256];
	sprintf_s(buf, "Effect obj Num: %d", num);
	drawString(0, 600, buf);

#endif // DEBUG


}

void EffectManager::setScroll(Vector3 a_speed, int a_liveInPagination, bool a_isRestart)
{
	for (auto &it : m_ppEffect)
	{
		if (it && it->m_isInit && it->m_pfMove!=effectCircleMove)
		{
			it->m_pos.y -= a_speed.y;
			if (a_speed.y < 0 && it->m_pos.y > it->m_initPos.y/* && a_isRestart*/)
			{
				it->m_pos.y = it->m_initPos.y;
			}
			if (a_speed.y > 0 && it->m_pos.y < it->m_initPos.y - STAGE_HEIGHT/* && a_isRestart*/)
			{
				it->m_pos.y = it->m_initPos.y - STAGE_HEIGHT;
			}
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
		obj->m_pAnimeData = e_pAnimeEffJumpDown;
		obj->m_pSprData = &obj->m_pAnimeData[0];
		obj->m_isVisible = true;
		obj->m_pfMove = effectJumpUp;
		obj->m_timer = 0;
		obj->m_initPos = obj->m_pos;
		obj->m_step = STEP::BEGIN;
		//break;
	case STEP::BEGIN:
		if (obj->m_animeCounter > 0) {
			obj->m_step = STEP::END;
			obj->clear();
		}
		break;
	case STEP::END:
		obj->m_step = STEP::FINISH;
		//break;
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
		obj->m_pAnimeData = e_pAnimeEffJumpUp;
		obj->m_pSprData = &obj->m_pAnimeData[0];
		obj->m_custom.scaleMode = SCALE_MODE::BOTTOMCENTER;
		obj->m_custom.scaleX = obj->m_custom.scaleY = 0.7f;
		//obj->m_alpha = 180;
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
			a_pObj->m_step = STEP::END;
			a_pObj->clear();
		}
		break;
	case STEP::END:
		a_pObj->m_step = STEP::FINISH;
		//break;
	case STEP::FINISH:
		a_pObj->clear();
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
			a_pObj->m_step = STEP::END;
			a_pObj->clear();
		}
		break;
	case STEP::END:
		a_pObj->m_step = STEP::FINISH;
		//break;
	case STEP::FINISH:
		a_pObj->clear();
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
			a_pObj->m_step = STEP::END;
			a_pObj->clear();
		}
		break;
	case STEP::END:
		a_pObj->m_step = STEP::FINISH;
		//break;
	case STEP::FINISH:
		a_pObj->clear();
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
		a_pObj->m_alpha = 180;
		a_pObj->m_initPos = a_pObj->m_pos;
		a_pObj->m_step = STEP::BEGIN;
		//break;
	case STEP::BEGIN:
		if (a_pObj->m_animeCounter > 0) {
			a_pObj->m_step = STEP::END;
			a_pObj->clear();
		}
		break;
	case STEP::END:
		a_pObj->m_step = STEP::FINISH;
		//break;
	case STEP::FINISH:
		a_pObj->clear();
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
		a_pObj->m_alpha = 180;
		a_pObj->m_step = STEP::BEGIN;
		//break;
	case STEP::BEGIN:
		if (a_pObj->m_animeCounter > 0) {
			a_pObj->m_step = STEP::END;
			a_pObj->clear();
		}
		break;
	case STEP::END:
		a_pObj->m_step = STEP::FINISH;
		//break;
	case STEP::FINISH:
		a_pObj->clear();
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
		//a_pObj->m_pAnimeData = e_pAnimeEffOnBlurArea;
		a_pObj->m_pSprData = &e_pAnimeEffOnBlurArea[0];
		a_pObj->m_pfMove = effectOnBlurArea;
		a_pObj->m_custom.centRotate = false;
		a_pObj->m_custom.centY = a_pObj->m_pos.y - 45.0f;
		a_pObj->m_custom.centX = a_pObj->m_pos.x;
		a_pObj->m_custom.scaleMode = SCALE_MODE::CENTER;
		a_pObj->m_timer = 0;
		a_pObj->m_alpha = 255;
		//a_pObj->m_pos.y += 45.0f;
		a_pObj->m_initPos = a_pObj->m_pos;
		a_pObj->m_step = STEP::BEGIN;
		//break;
	case STEP::BEGIN:
		a_pObj->m_alpha -= 2;
		a_pObj->m_custom.angle -= 3;
		//a_pObj->m_custom.scaleX = a_pObj->m_custom.scaleY += 0.04;
		if (a_pObj->m_alpha <= 0) {
			a_pObj->m_step = STEP::END;
			a_pObj->clear();
		}
		break;
	case STEP::END:
		a_pObj->m_step = STEP::FINISH;
		//break;
	case STEP::FINISH:
		a_pObj->clear();
		break;
	default:
		break;
	}
}

void effectGageOnBlurArea(Effect* a_pObj) 
{
	switch (a_pObj->m_step)
	{
	case STEP::INIT:
		a_pObj->m_pAnimeData = e_pAnimeEffGageOnBlurArea;
		a_pObj->m_pSprData = &a_pObj->m_pAnimeData[0];
		a_pObj->m_pfMove = effectGageOnBlurArea;
		a_pObj->m_timer = 0;
		a_pObj->m_initPos = a_pObj->m_pos;
		//a_pObj->m_alpha = 180;
		a_pObj->m_step = STEP::BEGIN;
		//break;
	case STEP::BEGIN:
		a_pObj->m_alpha -= 2;
		if (a_pObj->m_animeCounter > 0) {
			a_pObj->m_step = STEP::END;
			a_pObj->clear();
		}
		break;
	case STEP::END:
		a_pObj->m_step = STEP::FINISH;
		//break;
	case STEP::FINISH:
		a_pObj->clear();
		break;
	default:
		break;
	}
}

void effectCircleMove(Effect* a_pObj)
{
	switch (a_pObj->m_step)
	{
	case STEP::INIT:
		a_pObj->m_pSprData = &e_sprWhiteCircle;
		a_pObj->m_pfMove = effectCircleMove;
		a_pObj->m_timer = 0;
		a_pObj->m_alpha = rand() % 100;
		a_pObj->m_speedAlpha = 3;
		a_pObj->m_custom.scaleY = 1.0f + (rand() / (float)RAND_MAX)*0.15f - 0.075f;
		a_pObj->m_custom.scaleX = 1.0f + (rand() / (float)RAND_MAX)*0.15f - 0.075f;


		//a_pObj->m_custom3d.position.x = rand() % (SCREEN_WIDTH + 200) - 100 - PAGE_WIDTH;
		a_pObj->m_initPos.x = PAGE_WIDTH / 2 + a_pObj->m_pos.x;
		a_pObj->m_custom3d.position.y = rand() % 500 - 100 + a_pObj->m_pos.y;
		a_pObj->m_initPos.z = -rand() % PAGE_WIDTH + a_pObj->m_pos.z;

		a_pObj->m_speedAcc.x = (rand() % 10 - 5) / 10.0f;
		a_pObj->m_speedAcc.y = rand() / RAND_MAX + 0.3;
		a_pObj->m_speedAcc.z = (rand() % 10 - 5) / 10.0f;

		a_pObj->m_speedMax.x = rand() % 30 + 3.0f;
		a_pObj->m_speedMax.y = rand() % 2 + 0.5f;
		a_pObj->m_speedMax.z = rand() % 30 + 3.0f;

		a_pObj->m_speedAngle.y = (rand() % 4 == 0 ? -1 : 1)*(rand() % 5 / 10.0f + 0.1) / 100.0f;

		a_pObj->m_radius = rand() % 400 + 200.0f;
		a_pObj->m_speedRadius = 0.15;
		a_pObj->m_radiusMax = rand() % 300 + (float)PAGE_WIDTH;

		if (a_pObj->m_type == 1){
			a_pObj->m_speedAcc.x *= 4.0f;
			a_pObj->m_speedAcc.y *= 2.0f;
			a_pObj->m_speedAcc.z *= 4.0f;

			a_pObj->m_speedMax.x *= 4.0f;
			a_pObj->m_speedMax.y *= 2.0f;
			a_pObj->m_speedMax.z *= 4.0f;

			a_pObj->m_speedAngle.y *= 4.0f;

			//a_pObj->m_radius = rand() % 400 + 200;
			a_pObj->m_speedRadius *= 1.0f;
			a_pObj->m_radiusMax *= 0.6f;
			a_pObj->m_custom.rgba = ((rand() % 0xFF) << 24) | ((rand() % 0xFF) << 16) | ((rand() % 0xFF) << 8);
		}
		//a_pObj->m_custom.rgba = ((rand() % 0xFF) << 24) | ((rand() % 0xFF) << 16) | ((rand() % 0xFF) << 8);
		//a_pObj->m_initPos = a_pObj->m_pos;
		a_pObj->m_step = STEP::BEGIN;
		//break;
	case STEP::BEGIN:

		a_pObj->m_alpha += a_pObj->m_speedAlpha;
		if (a_pObj->m_alpha <= 0 || a_pObj->m_alpha >= 100) {
			a_pObj->m_speedAlpha = -a_pObj->m_speedAlpha;
		}

		//a_pObj->m_speed += a_pObj->m_speedAcc;
		//if (fabsf(a_pObj->m_speed.x) > a_pObj->m_speedMax.x)
		//{
		//	a_pObj->m_speedAcc.x = -a_pObj->m_speedAcc.x;
		//}
		///*if (fabsf(a_pObj->m_speed.y) > a_pObj->m_speedMax.y)
		//{
		//	a_pObj->m_speedAcc.y = -a_pObj->m_speedAcc.y;
		//}*/
		/*a_pObj->m_speed.z += a_pObj->m_speedAcc.z;
		if (fabsf(a_pObj->m_speed.z) > a_pObj->m_speedMax.z)
		{
			a_pObj->m_speedAcc.z = a_pObj->m_speedAcc.z;
		}*/

		a_pObj->m_angle.y += a_pObj->m_speedAngle.y;

		a_pObj->m_radius += a_pObj->m_speedRadius;
		if (a_pObj->m_radius>a_pObj->m_radiusMax)
		{
			a_pObj->m_radius = a_pObj->m_radiusMax;
		}
		/*if (a_pObj->m_radius > a_pObj->m_speedMax.z)
		{
			a_pObj->m_radius = a_pObj->m_speedMax.z;
		}*/
		//a_pObj->m_speed.x = a_pObj->m_radius*sinf(a_pObj->m_speedAngle.y);
		a_pObj->m_speed.y += a_pObj->m_speedAcc.y;
		if (a_pObj->m_speed.y > a_pObj->m_speedMax.y)
		{
			a_pObj->m_speed.y = a_pObj->m_speedMax.y;
		}
		//a_pObj->m_speed.z = a_pObj->m_radius*cosf(a_pObj->m_speedAngle.y);
		
		a_pObj->m_custom3d.position.x = a_pObj->m_radius*cosf(a_pObj->m_angle.y) + a_pObj->m_initPos.x;
		a_pObj->m_custom3d.position.y += a_pObj->m_speed.y;
		a_pObj->m_custom3d.position.z = a_pObj->m_radius*sinf(a_pObj->m_angle.y) + a_pObj->m_initPos.z;

		if (a_pObj->m_custom3d.position.y > SCREEN_HEIGHT)
		{
			a_pObj->m_step = STEP::END;
			a_pObj->clear();
		}
		break;
	case STEP::END:
		a_pObj->m_step = STEP::FINISH;
		//break;
	case STEP::FINISH:
		a_pObj->clear();
		break;
	default:
		break;
	}
}

void effectStampMove(Effect* a_pObj)
{
	switch (a_pObj->m_step)
	{
	case STEP::INIT:
		a_pObj->m_pSprData = &e_sprEffStamp;
		a_pObj->m_pfMove = effectStampMove;
		a_pObj->m_timer = 0;
		a_pObj->m_isVisible = true;
		a_pObj->m_initPos = a_pObj->m_setPos = a_pObj->m_pos;
		a_pObj->m_pos.x -= 120.0f;
		a_pObj->m_pos.y -= 160.0f;
		a_pObj->m_custom.scaleX = a_pObj->m_custom.scaleY = 1.5f;
		a_pObj->m_speedAcc.x = 120.0f / (20.0f*20.0f);
		a_pObj->m_speedAcc.y = 160.0f / (20.0f*20.0f);
		pEffectManager->isStampDown = false;
		a_pObj->m_step = STEP::BEGIN;
		//break;
	case STEP::BEGIN:
		a_pObj->m_custom.scaleX -= 0.03f;
		if (a_pObj->m_custom.scaleX < 1.0f)
		{
			a_pObj->m_custom.scaleX = 1.0f;
		}
		a_pObj->m_custom.scaleY = a_pObj->m_custom.scaleX;

		a_pObj->m_speed += a_pObj->m_speedAcc;
		a_pObj->m_pos += a_pObj->m_speed;
		if (a_pObj->m_pos.y > a_pObj->m_setPos.y) {
			a_pObj->m_pos = a_pObj->m_setPos;
			a_pObj->m_custom.scaleY = a_pObj->m_custom.scaleX = 1.0f;
			a_pObj->m_step = STEP::BEGIN + 1;
		}
		break;
	case STEP::BEGIN+1:
		a_pObj->m_timer++;
		if (a_pObj->m_timer > 60) {
			a_pObj->m_timer = 0;
			pEffectManager->isStampDown = true;
			a_pObj->m_step = STEP::END;
			a_pObj->clear();
		}
		break;
	case STEP::BEGIN + 2:
		a_pObj->m_timer++;
		if (a_pObj->m_timer>30) {
			a_pObj->m_timer = 0;
			a_pObj->m_step = STEP::BEGIN + 2;
		}
		break;
	case STEP::END:
		a_pObj->m_step = STEP::FINISH;
		//break;
	case STEP::FINISH:
		a_pObj->clear();
		break;
	default:
		break;
	}
}

void effectStampShadowMove(Effect* a_pObj)
{
	switch (a_pObj->m_step)
	{
	case STEP::INIT:
		a_pObj->m_pSprData = &e_sprEffStampShadow;
		a_pObj->m_pfMove = effectStampShadowMove;
		a_pObj->m_timer = 0;
		a_pObj->m_alpha = 60;
		a_pObj->m_pos.x += 10;
		a_pObj->m_initPos = a_pObj->m_setPos = a_pObj->m_pos;
		a_pObj->m_pos.x += 20.0f;
		a_pObj->m_pos.y += 30.0f;
		a_pObj->m_custom.scaleX = a_pObj->m_custom.scaleY = 2.0f;
		a_pObj->m_speedAcc.x = -20.0f / (20.0f*20.0f);
		a_pObj->m_speedAcc.y = -30.0f / (20.0f*20.0f);
		//pEffectManager->isStampDown = false;
		a_pObj->m_step = STEP::BEGIN;
		//break;
	case STEP::BEGIN:
		a_pObj->m_custom.scaleX -= 0.06f;
		if (a_pObj->m_custom.scaleX < 1.0f)
		{
			a_pObj->m_custom.scaleX = 1.0f;
		}
		a_pObj->m_custom.scaleY = a_pObj->m_custom.scaleX;
		a_pObj->m_alpha += 5;

		a_pObj->m_speed += a_pObj->m_speedAcc;
		a_pObj->m_pos += a_pObj->m_speed;
		if (a_pObj->m_pos.y < a_pObj->m_setPos.y) {
			a_pObj->m_pos = a_pObj->m_setPos;
			a_pObj->m_custom.scaleY = a_pObj->m_custom.scaleX = 1.0f;
			a_pObj->m_step = STEP::BEGIN + 1;
		}
		break;
	case STEP::BEGIN + 1:
		a_pObj->m_timer++;
		if (a_pObj->m_timer > 60) {
			a_pObj->m_timer = 0;
			//pEffectManager->isStampDown = true;
			a_pObj->m_step = STEP::END;
			a_pObj->clear();
		}
		break;
	case STEP::BEGIN + 2:
		a_pObj->m_timer++;
		if (a_pObj->m_timer>30) {
			a_pObj->m_timer = 0;
			a_pObj->m_step = STEP::BEGIN + 2;
		}
		break;
	case STEP::END:
		a_pObj->m_step = STEP::FINISH;
		//break;
	case STEP::FINISH:
		a_pObj->clear();
		break;
	default:
		break;
	}
}

void effectStar(Effect* a_pObj)
{
	switch (a_pObj->m_step)
	{
	case STEP::INIT:
		a_pObj->m_pAnimeData = e_pAnimeEffStar;
		a_pObj->m_pSprData = &a_pObj->m_pAnimeData[0];
		a_pObj->m_pfMove = effectStar;
		a_pObj->m_timer = 0;
		a_pObj->m_custom.scaleY = a_pObj->m_custom.scaleX =/* rand() % 30 / 100.0f +*/ 0.4f;
		a_pObj->m_custom.scaleMode = SCALE_MODE::CENTER;
		a_pObj->m_custom.centRotate = false;
		a_pObj->m_custom.centX = a_pObj->m_pos.x;
		a_pObj->m_custom.centY = a_pObj->m_pos.y - 55.0f;
		a_pObj->m_initPos = a_pObj->m_pos;
		a_pObj->m_speedAcc.x = rand() % 10 / 100.0f - 0.05;
		a_pObj->m_speedAcc.y = -rand() % 10 / 100.0f;
		a_pObj->m_step = STEP::BEGIN;
		//break;
	case STEP::BEGIN:
		//a_pObj->m_speed += a_pObj->m_speedAcc;
		//a_pObj->m_pos += a_pObj->m_speed;
		//a_pObj->m_custom.angle += 4;
		if (a_pObj->m_animeCounter > 0) {
			a_pObj->m_step = STEP::END;
			a_pObj->clear();
		}
		break;
	case STEP::END:
		a_pObj->m_step = STEP::FINISH;
		//break;
	case STEP::FINISH:
		a_pObj->clear();
		break;
	default:
		break;
	}
}

void effectCloseBook(Effect* a_pObj)
{
	switch (a_pObj->m_step)
	{
	case STEP::INIT:
		a_pObj->m_pAnimeData = e_pAnimeEffCloseBook;
		a_pObj->m_pSprData = &a_pObj->m_pAnimeData[0];
		a_pObj->m_pfMove = effectCloseBook;
		a_pObj->m_timer = 0;
		a_pObj->m_initPos = a_pObj->m_pos;
		//a_pObj->m_alpha = 180;
		a_pObj->m_step = STEP::BEGIN;
		//break;
	case STEP::BEGIN:
		if (a_pObj->m_animeCounter > 0) {
			a_pObj->m_step = STEP::END;
			a_pObj->clear();
		}
		break;
	case STEP::END:
		a_pObj->m_step = STEP::FINISH;
		//break;
	case STEP::FINISH:
		a_pObj->clear();
		break;
	default:
		break;
	}
}

void effectBookAura(Effect* a_pObj) {
	switch (a_pObj->m_step)
	{
	case STEP::INIT:
		a_pObj->m_pSprData = &e_sprEffBookAura;
		a_pObj->m_pfMove = effectBookAura;

		a_pObj->m_custom.angle = 180;
		a_pObj->m_custom.scaleX = a_pObj->m_custom.scaleY = 1.03f;

		a_pObj->m_timer = 0;
		a_pObj->m_initPos = a_pObj->m_pos;
		a_pObj->m_alpha = 0;
		a_pObj->m_speedAlpha = 2;
		a_pObj->m_step = STEP::BEGIN;
		//break;
	case STEP::BEGIN:
		a_pObj->m_alpha += a_pObj->m_speedAlpha;
		if (a_pObj->m_alpha > 255) {
			a_pObj->m_alpha = 255;
			a_pObj->m_speedAlpha = -a_pObj->m_speedAlpha;
		}
		if (a_pObj->m_alpha < 0) {
			a_pObj->m_step = STEP::END;
			a_pObj->clear();
		}
		break;
	case STEP::END:
		a_pObj->m_step = STEP::FINISH;
		//break;
	case STEP::FINISH:
		a_pObj->clear();
		break;
	default:
		break;
	}
}

//void effectCurtain(Effect* a_pObj) 
//{
//	switch (a_pObj->m_step)
//	{
//	case STEP::INIT:
//		a_pObj->m_pSprData = &e_sprWhite;
//		a_pObj->m_pfMove = effectCurtain;
//		a_pObj->m_timer = 0;
//		pEffectManager->m_doClear = false;
//		a_pObj->m_step = STEP::BEGIN;
//		//break;
//	case STEP::BEGIN:
//
//		if (fabsf(a_pObj->m_alpha - a_pObj->m_setAlpha) < FLT_EPSILON) {
//			a_pObj->clear();
//
//			a_pObj->m_step = STEP::END;
//		}
//		break;
//	case STEP::END:
//		a_pObj->m_step = STEP::FINISH;
//		//break;
//	case STEP::FINISH:
//		break;
//	default:
//		break;
//	}
//}


void effectGoal(Effect* a_pObj)
{
	switch (a_pObj->m_step)
	{
	case STEP::INIT:
		a_pObj->m_pSprData = &e_pSprEffGoal[a_pObj->m_type];
		a_pObj->m_pfMove = effectGoal;
		a_pObj->m_timer = 0;
		a_pObj->m_initPos = a_pObj->m_pos;
		a_pObj->m_alpha = 0;
		a_pObj->m_speedAlpha = 4;
		a_pObj->m_custom.scaleMode = SCALE_MODE::CENTER;
		a_pObj->m_custom.scaleY = a_pObj->m_custom.scaleX = 5.0f;
		a_pObj->m_speedAcc.x = -0.01f;
		if (a_pObj->m_doReverseMove)
		{
			a_pObj->m_alpha = 255;
			a_pObj->m_speedAlpha = -4;
			a_pObj->m_custom.scaleY = a_pObj->m_custom.scaleX = 1.0f;
			a_pObj->m_speedAcc.x = 0.01f;
		}

		a_pObj->m_timer = 0;
		a_pObj->m_step = STEP::BEGIN;
		//break;
	case STEP::BEGIN:
		//++a_pObj->m_timer;
		//if (a_pObj->m_timer % 20 == 0) {
		//	Effect::searchSet(pEffectManager->m_ppEffect, EFF_OBJ_MAX_NUM, a_pObj->m_pos, a_pObj->m_liveInPagination, effectGoal, a_pObj->m_type);
		//}
		a_pObj->m_speed.x += a_pObj->m_speedAcc.x;
		a_pObj->m_custom.scaleX += a_pObj->m_speed.x;
		if (a_pObj->m_doReverseMove)
		{
			if (a_pObj->m_custom.scaleX > 5.0f)
			{
				a_pObj->m_custom.scaleX = 5.0f;
				a_pObj->m_step = STEP::END;
			}
		}
		else
		{
			if (a_pObj->m_custom.scaleX < 1.0f)
			{
				a_pObj->m_custom.scaleX = 1.0f;
				a_pObj->m_step = STEP::END;
			}
		}
		a_pObj->m_custom.scaleY = a_pObj->m_custom.scaleX;
		a_pObj->m_alpha += a_pObj->m_speedAlpha;
		break;
	case STEP::END:
		a_pObj->m_step = STEP::FINISH;
		//break;
	case STEP::FINISH:
		a_pObj->clear();
		break;
	default:
		break;
	}
}

void effectEnterBlurArea(Effect* a_pObj)
{
	switch (a_pObj->m_step)
	{
	case STEP::INIT:
		a_pObj->m_pSprData = &e_sprEffPlayerBorder;
		a_pObj->m_pfMove = effectEnterBlurArea;
		a_pObj->m_timer = 0;
		a_pObj->m_initPos = a_pObj->m_pos;
		a_pObj->m_alpha = 0;
		a_pObj->m_speedAlpha = 4;
		a_pObj->m_custom.scaleMode = SCALE_MODE::CENTER;
		a_pObj->m_custom.scaleY = a_pObj->m_custom.scaleX = 5.0f;
		a_pObj->m_speed.x = 0;
		a_pObj->m_speedAcc.x = -0.01f;
		if (a_pObj->m_doReverseMove)
		{
			a_pObj->m_alpha = 255;
			a_pObj->m_speedAlpha = -10;
			a_pObj->m_custom.scaleY = a_pObj->m_custom.scaleX = 1.2f;
			a_pObj->m_speed.x = 0;
			a_pObj->m_speedAcc.x = 0.01f;
		}

		//a_pObj->m_custom.rgba = 0xFCAD8AFF;
		a_pObj->m_timer = 0;
		a_pObj->m_step = STEP::BEGIN;
		//break;
	case STEP::BEGIN:
		//++a_pObj->m_timer;
		//if (a_pObj->m_timer % 20 == 0) {
		//	Effect::searchSet(pEffectManager->m_ppEffect, EFF_OBJ_MAX_NUM, a_pObj->m_pos, a_pObj->m_liveInPagination, effectGoal, a_pObj->m_type);
		//}
		a_pObj->m_speed.x += a_pObj->m_speedAcc.x;
		a_pObj->m_custom.scaleX += a_pObj->m_speed.x;
		if (a_pObj->m_doReverseMove)
		{
			if (a_pObj->m_custom.scaleX > 1.5f)
			{
				a_pObj->m_custom.scaleX = 1.5f;
				a_pObj->m_step = STEP::FINISH;
			}
		}
		else
		{
			if (a_pObj->m_custom.scaleX < 1.2f)
			{
				a_pObj->m_custom.scaleX = 1.2f;
				a_pObj->m_step = STEP::END;
			}
		}
		a_pObj->m_custom.scaleY = a_pObj->m_custom.scaleX;
		a_pObj->m_alpha += a_pObj->m_speedAlpha;
		if (a_pObj->m_alpha>160)
		{
			a_pObj->m_alpha = 160;
		}
		break;
	case STEP::END:
		//a_pObj->m_step = STEP::FINISH;
		break;
	case STEP::FINISH:
		a_pObj->clear();
		break;
	default:
		break;
	}
}

void effectSpiral(Effect* a_pObj)
{
	switch (a_pObj->m_step)
	{
	case STEP::INIT:
		a_pObj->m_pSprData = &e_pSprEffSpirals[rand() % 5];
		a_pObj->m_pfMove = effectSpiral;

		a_pObj->m_custom.scaleY = a_pObj->m_custom.scaleX = 0.5f;

		a_pObj->m_timer = 0;
		a_pObj->m_initPos = a_pObj->m_pos;
		a_pObj->m_alpha = 60;
		a_pObj->m_speedAlpha = 4;
		a_pObj->m_step = STEP::BEGIN;
		//break;
	case STEP::BEGIN:
		if (a_pObj->m_timer > 0){
			++a_pObj->m_timer;
			if (a_pObj->m_timer == 60) {
				//a_pObj->m_alpha = 255;
				a_pObj->m_speedAlpha = -a_pObj->m_speedAlpha;
			}
			if (a_pObj->m_timer > 60) {
				a_pObj->m_custom.scaleX -= 0.01f;
			}
		}
		else
		{
			a_pObj->m_custom.scaleX += 0.02f;
		}
		a_pObj->m_custom.angle += 2;
		if (a_pObj->m_custom.scaleX > 1.0f) {
			a_pObj->m_custom.scaleX = 1.0f;
		}
		a_pObj->m_custom.scaleY = a_pObj->m_custom.scaleX;
		a_pObj->m_alpha += a_pObj->m_speedAlpha;
		if (a_pObj->m_alpha > 255) {
			a_pObj->m_alpha = 255;
			++a_pObj->m_timer;
		}
		if (a_pObj->m_alpha < 0) {
			a_pObj->m_step = STEP::END;
		}
		break;
	case STEP::END:
		a_pObj->m_step = STEP::FINISH;
		//break;
	case STEP::FINISH:
		a_pObj->clear();
		break;
	default:
		break;
	}
}

void effectClearStar(Effect* a_pObj)
{
	switch (a_pObj->m_step)
	{
	case STEP::INIT:
		a_pObj->m_pAnimeData = e_pAnimeEffClearStar;
		a_pObj->m_pSprData = &a_pObj->m_pAnimeData[0];
		a_pObj->m_pfMove = effectClearStar;
		a_pObj->m_timer = 0;
		a_pObj->m_initPos = a_pObj->m_pos;
		a_pObj->m_step = STEP::BEGIN;
		//break;
	case STEP::BEGIN:
		if (a_pObj->m_animeCounter > 0) {
			a_pObj->m_step = STEP::END;
			a_pObj->clear();
		}
		break;
	case STEP::END:
		a_pObj->m_step = STEP::FINISH;
		//break;
	case STEP::FINISH:
		a_pObj->clear();
		break;
	default:
		break;
	}
}

void effectFirework(Effect* a_pObj)
{
	switch (a_pObj->m_step)
	{
	case STEP::INIT:
		a_pObj->m_pAnimeData = e_pAnimeEffFirework;
		a_pObj->m_pSprData = &a_pObj->m_pAnimeData[0];
		a_pObj->m_pfMove = effectFirework;
		a_pObj->m_timer = 0;
		a_pObj->m_initPos = a_pObj->m_pos;
		a_pObj->m_step = STEP::BEGIN;
		if (a_pObj->m_type == 1) {
			a_pObj->m_custom.rgba = ((rand() % 0x80 + 0x80) << 24) | ((rand() % 0x80 + 0x80) << 16) | ((rand() % 0x80 + 0x80) << 8);
		}
		//break;
	case STEP::BEGIN:
		if (a_pObj->m_animeCounter > 0) {
			a_pObj->m_step = STEP::END;
			a_pObj->clear();
		}
		break;
	case STEP::END:
		a_pObj->m_step = STEP::FINISH;
		//break;
	case STEP::FINISH:
		a_pObj->clear();
		break;
	default:
		break;
	}
}