#include "game.h"
#include "map_obj.h"

#include "stage_data.h"

int e_stageHeight[] = {
	0,
	(1150 - 30) - (PH - 100),
	(900) - (PH - 100),
	(900) - (PH - 100),
	(900) - (PH - 100),
	(900) - (PH - 100),
};

int e_startPagination[] = {
	61,
	67,
	73,
	79,
	85,
	91,
};

v3 e_initPos[] = {
	{ 80,400,5 },
	{ 80,400,5 },
	{ 80,400,5 },
	{ 80,400,5 },
	{ 80,400,5 },
	{ 80,400,5 },
};

int e_initLife[] = {
	4,
	5,
	6,
	7,
	8,
	9,
};

const int STAGE_MAX_NUM = ARRAYSIZE(e_startPagination)/*sizeof(e_startPagination) / sizeof(int)*/;


int START_PAGINATION = e_startPagination[0];

int STAGE_HEIGHT = e_stageHeight[0];

v3 INIT_POS = e_initPos[0];

int P_LIFE_MAX = e_initLife[0];

STAGE_DATA stage00_setData[] = {

	// ページ 左

	STAGE_DATA(e_startPagination[0], 0, M_TYPE::GAME_RULE_LEFT,				M_DRAW::UP,		v3(0,0,0),					false, v3(0,0,0), 10),
	STAGE_DATA(e_startPagination[0], 0, M_TYPE::IVY_THICK,					M_DRAW::UP,		v3(0,PH-30,1),				true, v3(PW,20,0), 10),
	STAGE_DATA(e_startPagination[0], 0, M_TYPE::KEY,						M_DRAW::UP,		v3(PW / 2,PH - 30-30,0),	true, v3(50,30,0), 10),


	// ページ 右
	STAGE_DATA(e_startPagination[0] + 1, 0, M_TYPE::GAME_RULE_RIGHT,		M_DRAW::UP,		v3(0,0,0),					false, v3(0,0,0), 10),
	STAGE_DATA(e_startPagination[0] + 1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,PH - 30,1),			true, v3(PW,20,0), 10),
	STAGE_DATA(e_startPagination[0] + 1, 0, M_TYPE::DOOR,					M_DRAW::UP,		v3(PW/2,PH - 30 - 76,0),	true, v3(51,76,0), LOW_CONCENTRATION),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};