#ifndef _MAP_OBJ_H_
#define _MAP_OBJ_H_

#include "obj2d.h"

#define MAPOBJ_MAX_NUM (24)

enum MAPOBJ_TYPE
{
	MAPOBJ_NONE = -1,
	MAPOBJ_HOUSE = 0,
	MAPOBJ_TREE_A,
	MAPOBJ_TREE_B,
	MAPOBJ_IVY_BIG,
	MAPOBJ_IVY_THIN,
	MAPOBJ_IVY_THICK,
	MAPOBJ_DOOR,
	MAPOBJ_KEY,

	MAPOBJ_MAX_TYPE,
};

class MapObj : public OBJ2DEX
{
private:

public:

	int m_command; //プレイヤーのキー入力
	int m_concentration; //濃度

	void hitAdjust(OBJ2DEX* a_pObj);

	void(*m_pfMove)(MapObj*);

	MapObj(int a_type = 0);
	~MapObj() {
		clear();
	};

	void init(int a_type);

	void clear() {
		OBJ2DEX::clear();
		m_pfMove = nullptr;
		m_command = 0x0;
	};

	void update();
	void draw();

	static int searchSet(MapObj** a_ppBegin, int a_maxNum, void(*a_pfMove)(MapObj*), int a_type, Vector3 &a_pos = Vector3(0, 0, 0), int a_concentration = 10);

};

struct STAGE_DATA {
	int appearTime;
	void(*pfMove)(MapObj*);
	int mapObjType;
	Vector3 pos;
	int concentration;
	bool isOnLeftPage;
	STAGE_DATA(int a_appearTime, void(*a_pfMove)(MapObj*), int a_MAP_OBJType, Vector3 a_pos, int a_concentration, bool a_isOnLeftPage)
		:appearTime(a_appearTime), pfMove(a_pfMove), mapObjType(a_MAP_OBJType), pos(a_pos), concentration(a_concentration),isOnLeftPage(a_isOnLeftPage) {};
};

class MapObjManager : public Singleton<MapObjManager>, public Manager
{
private:

public:

	MapObj* m_ppMapObj[MAPOBJ_MAX_NUM];

	STAGE_DATA* m_pStageData;
	int m_stageNo;

	void init(int m_stageNo = 0);
	void stageUpdate();
	void update();
	void draw();

	MapObjManager() {};
	~MapObjManager() {
		/*for (int i = 0; i < MAP_OBJ_MAX_NUM; i++)
		{
		if (pMAP_OBJ[i]) {
		delete pMAP_OBJ[i];
		pMAP_OBJ[i] = nullptr;
		}
		}*/
	};

	bool isAlive();

};

#define pMapObjManager (MapObjManager::getInstance())




#endif // !_MAP_OBJ_H_
