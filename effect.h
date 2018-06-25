#ifndef _EFFECT_H_
#define _EFFECT_H_

#include "obj2d.h"

#define EFF_OBJ_MAX_NUM	(256)
#define EFF_STAMP_MAX_NUM (5)


class Effect :public OBJ2DEX
{
private:

public:
	virtual void memberCopy(const Effect& a_inputObj);
	Effect();
	Effect(const Effect& a_inputObj);
	virtual ~Effect();
	const Effect& operator=(const Effect& a_right);

	void clear();

	bool m_isVisibleAlways;
	bool m_isVisible;

	int m_speedAlpha;
	XMFLOAT3 m_angle;
	XMFLOAT3 m_speedAngle;
	XMFLOAT3 m_speedAngleAcc;
	XMFLOAT3 m_speedAngleMax;
	float m_radius;
	float m_speedRadius;
	float m_radiusMax;

	void(*m_pfMove)(Effect*);

	void init();
	void update();
	void draw();

	static Effect* searchSet(Effect** a_ppBegin, int a_maxNum, Vector3 a_pos, int a_liveInPagination, void(*a_pfMove)(Effect*) = nullptr, int a_type = 0, bool a_isReflect = false);

};

class EffectManager : public Singleton<EffectManager>, public Manager
{
private:

public:

	EffectManager();
	~EffectManager();

	Effect* m_ppEffect[EFF_OBJ_MAX_NUM] = { nullptr };

	bool isStampDown;
	//bool m_doClear;

	void init();
	void update();
	void draw();

	void setScroll(Vector3 a_speed, int a_liveInPagination, bool a_isRestart);
};

#define pEffectManager	(EffectManager::getInstance())

void effectPlayerInit(Effect* obj);
//void effectRecoverySplash(Effect* obj);
void effectJumpUp(Effect* obj);
void effectJumpDown(Effect* obj);

void effectRecoveryPassed(Effect* a_pObj);
void effectDisappear(Effect* a_pObj);
void effectMakeTranscription(Effect* a_pObj);

void effectDamaging(Effect* a_pObj);
void effectRunning(Effect* a_pObj);
void effectOnBlurArea(Effect* a_pObj);

void effectCircleMove(Effect* a_pObj);
void effectStampMove(Effect* a_pObj);
void effectStampShadowMove(Effect* a_pObj);

void effectStar(Effect* a_pObj);
void effectCloseBook(Effect* a_pObj);

void effectGageOnBlurArea(Effect* a_pObj);

//void effectCurtain(Effect* a_pObj);

#endif // !_EFFECT_H_