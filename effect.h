#ifndef _EFFECT_H_
#define _EFFECT_H_

#include "obj2d.h"

#define EFF_OBJ_MAX_NUM	(36)
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


	void(*m_pfMove)(Effect*);

	void init();
	void update();
	void draw();

	static Effect* searchSet(Effect** a_ppBegin, int a_maxNum, Vector3 a_pos, int a_liveInPagination, void(*a_pfMove)(Effect*) = nullptr);

};

class EffectManager : public Singleton<EffectManager>, public Manager
{
private:

public:

	EffectManager();
	~EffectManager();

	Effect* m_ppEffect[EFF_OBJ_MAX_NUM] = { nullptr };

	bool isStampDown;

	void init();
	void update();
	void draw();

};

#define pEffectManager	(EffectManager::getInstance())

void effectPlayerInit(Effect* obj);
void effectRecoverySplash(Effect* obj);
void effectJumpUp(Effect* obj);
void effectJumpDown(Effect* obj);



#endif // !_EFFECT_H_