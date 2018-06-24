#ifndef _MAP_OBJ_H_
#define _MAP_OBJ_H_

#include "obj2d.h"

#define LOW_CONCENTRATION (4)

#define MAPOBJ_MAX_NUM	(256)

// MapObj Type
enum M_TYPE
{
	NONE = -1,
	BORDER_INNER = 0,
	PASSABLE_UP,
	PASSABLE_DOWN,
	RECOVERY,
	DOOR,
	KEY,
	HIGH_CONCENTRATION,

	GAME_RULE_LEFT,
	GAME_RULE_RIGHT,

	STAGE_SELECT00_LEFT,
	STAGE_SELECT00_RIGHT,
	STAGE_SELECT01_LEFT,
	STAGE_SELECT01_RIGHT,

	STAGE_INTRO01_LEFT,
	STAGE_INTRO01_RIGHT,
	STAGE_INTRO02_LEFT,
	STAGE_INTRO02_RIGHT,
	STAGE_INTRO03_LEFT,
	STAGE_INTRO03_RIGHT,
	STAGE_INTRO04_LEFT,
	STAGE_INTRO04_RIGHT,
	STAGE_INTRO05_LEFT,
	STAGE_INTRO05_RIGHT,

	FOREST_1,
	FOREST_2,
	FOREST_3,
	FOREST_4,
	FOREST_5,
	FOREST_6,
	FOREST_7,
	FOREST_8,
	FOREST_9,
	FOREST_10,
	FOREST_11,

	BIRD_1,
	BIRD_2,
	BIRD_3,
	BIRD_4,
	BIRD_5,
	BIRD_6,
	BIRD_7,
	BIRD_8,

	GRAVE_1,
	GRAVE_2,
	GRAVE_3,
	GRAVE_4,
	GRAVE_5,
	GRAVE_6,
	GRAVE_7,
	GRAVE_8,
	GRAVE_9,
	GRAVE_10,
	GRAVE_11,

	SNOW_1,
	SNOW_2,
	SNOW_3,
	SNOW_4,
	SNOW_5,
	SNOW_6,
	SNOW_7,
	SNOW_8,

	DESERT_1,
	DESERT_2,
	DESERT_3,
	DESERT_4,
	DESERT_5,
	DESERT_6,
	DESERT_7,
	DESERT_8,

	TUTORIAL_1,
	TUTORIAL_2,
	TUTORIAL_3,
	TUTORIAL_4,

	MAX_M_TYPE,
};

// MapObj Draw Direction
enum M_DRAW
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	MIRROR,
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

	static void safeInit(MapObj& a_objIn, int a_liveInPagination, M_TYPE a_mapObjType, M_DRAW a_drawDirection, Vector3 a_pos, bool a_isHitAble, Vector3 a_size, float a_concentration = 10, void(*a_pfMove)(MapObj*) = nullptr);


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
	float concentration;
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
	STAGE_DATA(int a_liveInPagination, int a_appearTime, M_TYPE a_mapObjType, M_DRAW a_drawDirection, Vector3 a_pos, bool a_isHitAble, Vector3 a_size, float a_concentration = 10, void(*a_pfMove)(MapObj*) = nullptr) :
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


class StageManager : public Singleton<StageManager>, public Manager
{
private:

public:

	STAGE_DATA* m_pStageData;
	int m_stageNO;
	MapObj m_mapObj;

	void init(int m_stageNO = 0);

	void update();

	StageManager();
	~StageManager();
};




void recoveryControl(MapObj* a_pObj);




#define pStageManager (StageManager::getInstance())




#endif // !_MAP_OBJ_H_
