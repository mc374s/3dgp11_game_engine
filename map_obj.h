#ifndef _MAP_OBJ_H_
#define _MAP_OBJ_H_

#include "obj2d.h"

#define LOW_CONCENTRATION (4)

#define MAPOBJ_MAX_NUM	(64)

// MapObj Type
enum M_TYPE
{
	NONE = -1,
	HOUSE = 0,
	TREE_A,
	TREE_B,
	IVY_BIG,
	IVY_THIN,
	IVY_THICK,
	RECOVERY_UP,
	RECOVERY_DOWN,
	DOOR,
	KEY,
	HIGH_CONCENTRATION,

	MAX_M_TYPE,
};

// MapObj Draw Direction
enum M_DRAW
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

// 基準座標左上
class MapObj : public OBJ2DEX
{
private:

public:

	virtual void memberCopy(const MapObj& a_inputObj);
	MapObj();
	MapObj(const MapObj& a_inputObj);
	virtual ~MapObj();
	const MapObj& operator=(const MapObj& a_right);

	void clear();

	bool m_isVisibleAlways;
	bool m_isVisible;
	int m_initConcentration;

	int m_command; //プレイヤーのキー入力
	int m_drawDirection;
	bool m_isHitAble;
	Vector3 m_repeatDrawSize;
	void(*m_pfMove)(MapObj*);

	void init();
	void update();
	void draw();

	static int searchSet(MapObj** a_ppBegin, int a_maxNum, int a_liveInPagination, M_TYPE a_mapObjType, M_DRAW a_drawDirection, Vector3 a_pos, bool a_isHitAble, Vector3 a_size, int a_concentration = 10, void(*a_pfMove)(MapObj*) = nullptr);


	void hitAdjust(OBJ2DEX* a_pObj);
};


struct STAGE_DATA {
	int m_liveInPagination;
	int appearTime;
	M_TYPE mapObjType;
	M_DRAW drawDirection;
	Vector3 pos;
	bool isHitAble;
	Vector3 size;
	int concentration;
	void(*pfMove)(MapObj*);
	/**
	a_liveInPagination:		このObjはどのページに所属するのか
	a_appearTime:			出現のフレーム数
	a_mapObjType:			Objの種類(M_TYPE::***)
	a_drawDirection:		描画の方向(M_DRAW::***)
	a_pos:					ページ内での描画の位置(Objの左上が基準点)
	a_isHitAble:			判定があるかどうか
	a_size:					判定サイズ(描画方向と無関係)
	a_concentraction:		濃度
	a_pfMove:				このObjを動かす関数ポインタ
	*/
	STAGE_DATA(int a_liveInPagination, int a_appearTime, M_TYPE a_mapObjType, M_DRAW a_drawDirection, Vector3 a_pos, bool a_isHitAble, Vector3 a_size, int a_concentration = 10, void(*a_pfMove)(MapObj*) = nullptr) :
		m_liveInPagination(a_liveInPagination),
		appearTime(a_appearTime),
		mapObjType(a_mapObjType),
		drawDirection(a_drawDirection),
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

	MapObj* m_ppMapObjs[MAPOBJ_MAX_NUM] = {nullptr};

	STAGE_DATA* m_pStageData;
	int m_stageNO;

	void init(int m_stageNO = 0);
	void stageUpdate();
	void update();
	void draw();

	void mapScroll(float m_scrollHeight);

	MapObjManager();
	~MapObjManager();

	bool isAlive();

	void setScroll(Vector3 a_speed, int a_liveInPagination, bool a_isRestart);

};




void recoveryControl(MapObj* a_pObj);




#define pMapObjManager (MapObjManager::getInstance())




#endif // !_MAP_OBJ_H_
