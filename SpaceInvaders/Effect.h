#ifndef _EFFECT_H_
#define _EFFECT_H_

#define EFFECT_MAX (50)

class EffectManager : public Singleton<EffectManager>
{
private:
	
public:
	SpaceOBJ2D* pEffect[EFFECT_MAX];

	void init();
	void update();
	void draw();
	EffectManager() {};
	~EffectManager()
	{
		for (int i = 0; i < EFFECT_MAX; i++)
		{
			delete pEffect[i];
			pEffect[i] = nullptr;
		}
	};

};

#define pEffectManager (EffectManager::getInstance())

void enemyExplosion(SpaceOBJ2D* obj);

#endif // !_EFFECT_H_
