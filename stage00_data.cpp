#include "game.h"
#include "map_obj.h"

#include "stage_data.h"

int e_stageHeight[] = {
	0,
	0,
	0,
	(850) - (PH - 100),
	(680) - (PH - 100),
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
	{80,300,5 },//0
{ 80,200,5 },//1
{ 80,400,5 },//2
{ 80,180,5 },//3
{ 80,180,5 },//4
{ 80,400,5 },//5
};

int e_initLife[] = {
	4,
	2,
	2,
	2,
	2,
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


	// ページ 右
	STAGE_DATA(e_startPagination[0] + 1, 0, M_TYPE::GAME_RULE_RIGHT,		M_DRAW::UP,		v3(0,0,0),					false, v3(0,0,0), 10),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};