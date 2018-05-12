#ifndef _SHOT_H_
#define _SHOT_H_


#define E_SHOT_MAX (8)
#define P_SHOT_MAX (1)

#define P_SHOT_SPEED (26)
#define E_SHOT_SPEED (8)


class ShotManager :public Singleton<ShotManager>
{
private:

public:
	SpaceOBJ2D* pPShot[P_SHOT_MAX];
	SpaceOBJ2D* pEShot[E_SHOT_MAX];
	void Init();
	void Update();
	void Draw();
	ShotManager() {};
	~ShotManager() {
		for (int i = 0; i < P_SHOT_MAX; i++)
		{
			delete pPShot[i];
			pPShot[i] = nullptr;
		}
		for (int i = 0; i < E_SHOT_MAX; i++)
		{
			delete pEShot[i];
			pEShot[i] = nullptr;
		}
	}
};

#define pShotManager (ShotManager::getInstance())

void normalPShot(SpaceOBJ2D *obj);
void normalEShot(SpaceOBJ2D *obj);

#endif // !_SHOT_H_
