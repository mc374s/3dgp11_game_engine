#ifndef _MAP_OBJ_H_
#define _MAP_OBJ_H_

#include "obj2d.h"

#define LOW_CONCENTRATION (4)

#define MAPOBJ_MAX_NUM (64)

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
	MAPOBJ_HIGH_CONCENTRATION,

	MAPOBJ_MAX_TYPE,
};

enum DRAW_DIRECTION
{
	DRAW_UP,
	DRAW_DOWN,
	DRAW_LEFT,
	DRAW_RIGHT,
};

// 基準座標左上
class MapObj : public OBJ2DEX
{
private:

public:

	int m_command; //プレイヤーのキー入力
	int m_concentration; //濃度
	int m_drawDirection;
	bool m_isHitAble;
	Vector3 m_repeatDrawSize;

	void hitAdjust(OBJ2DEX* a_pObj);
	//void judgePlayer(OBJ2DEX* a_pObj);

	void(*m_pfMove)(MapObj*);

	void clear();

	MapObj(/*int a_type = 0*/);
	virtual ~MapObj() {
		clear();
	};

	void init();

	void update();
	void draw();

	static int searchSet(MapObj** a_ppBegin, int a_maxNum, MAPOBJ_TYPE a_mapObjType, DRAW_DIRECTION a_drawDirection, bool a_isOnLeftPage, Vector3 a_pos, bool a_isHitAble, Vector3 a_size, int a_concentration = 10, void(*a_pfMove)(MapObj*) = nullptr);

};

struct STAGE_DATA {
	int appearTime;
	MAPOBJ_TYPE mapObjType;
	DRAW_DIRECTION drawDirection;
	bool isOnLeftPage;
	Vector3 pos;
	bool isHitAble;
	Vector3 size;
	int concentration;
	void(*pfMove)(MapObj*);
	/**
	a_ppearTime:		出現のフレーム数
	a_mapObjType:		Objの種類(MAPOBJ_***)
	a_drawDirection:	描画の方向(DRAW_***)
	a_isOnLeftPage:		このObjは左ページのものかどうか
	a_pos:				ページ内での描画の位置(Objの左上が基準点)
	a_isHitAble:		判定があるかどうか
	a_size:				判定サイズ(描画方向と無関係)
	a_concentraction:	濃度
	a_pfMove:			このObjを動かす関数ポインタ
	*/
	STAGE_DATA(int a_appearTime, MAPOBJ_TYPE a_mapObjType, DRAW_DIRECTION a_drawDirection, bool a_isOnLeftPage, Vector3 a_pos, bool a_isHitAble, Vector3 a_size, int a_concentration = 10, void(*a_pfMove)(MapObj*) = nullptr) :
		appearTime(a_appearTime),
		mapObjType(a_mapObjType),
		drawDirection(a_drawDirection),
		isOnLeftPage(a_isOnLeftPage),
		pos(a_pos),
		isHitAble(a_isHitAble),
		size(a_size),
		concentration(a_concentration),
		pfMove(a_pfMove) {};
};

class MapObjManager : public Singleton<MapObjManager>, public Manager
{
private:

public:

	MapObj* m_ppMapObj[MAPOBJ_MAX_NUM] = {nullptr};

	STAGE_DATA* m_pStageData;
	int m_stageNo;

	void init(int m_stageNo = 0);
	void stageUpdate();
	void update();
	void draw();

	MapObjManager() {};
	~MapObjManager();

	bool isAlive();

	void setScroll(Vector3 a_speed, bool a_isOnLeftPage);

};

#define pMapObjManager (MapObjManager::getInstance())




#endif // !_MAP_OBJ_H_
