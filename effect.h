#ifndef _EFFECT_H_
#define _EFFECT_H_

#include "obj2d.h"

#define EFFECT_OBJ_MAX_NUM	(36)
#define EFFECT_STAMP_MAX_NUM (5)

enum EFFECT_NO
{
	ANIME_STAMP,
};


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

	bool m_isAnimeOnce;
	int recordedAnimeNO;

	void(*m_pfMove)(Effect*);

	void init();
	void update();
	void draw();

	static Effect* searchSet(Effect** a_ppBegin, int a_maxNum, int a_liveInPagination, Vector3 a_pos, void(*a_pfMove)(Effect*) = nullptr);

};

class EffectManager : public Singleton<EffectManager>, public Manager
{
private:

public:

	EffectManager();
	~EffectManager();

	Effect* m_ppEffect[EFFECT_OBJ_MAX_NUM] = { nullptr };
	Effect* recordedPTR;

	bool isStampDown;

	void init();
	void update();
	void draw();

	void setPlayerInitAnimation(Vector3 a_pos);

};

#define pEffectManager	(EffectManager::getInstance())

void movePlayerInitAnimation(Effect* obj);



#endif // !_EFFECT_H_

