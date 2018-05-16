#ifndef _MAP_OBJ_H_
#define _MAP_OBJ_H_

#include "obj2d.h"

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

	MAPOBJ_MAX_TYPE,
};

enum DRAW_DIRECTION
{
	DRAW_UP,
	DRAW_DOWN,
	DRAW_LEFT,
	DRAW_RIGHT,
};

class MapObj : public OBJ2DEX
{
private:

public:

	int m_command; //�v���C���[�̃L�[����
	int m_concentration; //�Z�x
	int m_drawDirection;
	bool m_isHitAble;
	Vector3 m_repeatDrawSize;

	void hitAdjust(OBJ2DEX* a_pObj);

	void(*m_pfMove)(MapObj*);

	void clear();

	MapObj(int a_type = 0);
	~MapObj() {
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
	a_ppearTime:		�o���̃t���[����
	a_mapObjType:		Obj�̎��(MAPOBJ_***)
	a_drawDirection:	�`��̕���(DRAW_***)
	a_isOnLeftPage:		����Obj�͍��y�[�W�̂��̂��ǂ���
	a_pos:				�y�[�W���ł̕`��̈ʒu(Obj�̉��^�񒆂���_)
	a_isHitAble:			���肪���邩�ǂ���
	a_size:				����T�C�Y(�`������Ɩ��֌W)
	a_concentraction:	�Z�x
	a_pfMove:			����Obj�𓮂����֐��|�C���^
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
