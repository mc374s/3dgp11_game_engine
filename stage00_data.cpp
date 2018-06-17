#include "game.h"
#include "map_obj.h"

#include "stage_data.h"

int e_stageHeight[] = {
	0,////ステージセレクトダミーデータ
	0,////ステージセレクトダミーデータ

	0,
	0,
	0,

	(840) - (PH - 100),
	0,
	(900) - (PH - 100),
	(900) - (PH - 100),//6

	(1039) - (PH - 100),//7

	(1500) - (PH-100),//8
	(1500) - (PH - 100),
	0,
	(900) - (PH - 100),

	(1039) - (PH - 100),//13
	0,//14
	0,

	//(840) - (PH - 100),
	//0,
	//(900) - (PH - 100),
	//(1039) - (PH - 100),//19

};

int e_startPagination[] = {
	3,////ステージ 1-1~4-3 セレクトページ目
	5,////ステージ 5-1~8-3 セレクトページ目


	7,  
	13,
	19,

	25,
	31,
	37,

	43,  
	49,
	55,

	61,
	67,
	73,

	79,
	85,
	91,

	//129-4,
	//135-4,
	//141-4,
	//147-4,
};

v3 e_initPos[] = {
	{ 80,300,5 },////ステージセレクトダミーデータ
{ 80,300,5 },////ステージセレクトダミーデータ


{ 80,250,5 },//1
{ 80,580,5 },//2
{ 80,180,5 },//3
{ 80,180,5 },//4
{ 80,400,5 },//5
{ 80,400,5 },//6


{ 80,400,5 },//7
{ 80,100,5 },//
{ 220,400,5 },//8
{ 80,580,5 },//9
{ 80,400,5 },//
{ 80,400,5 },//12


{ 80,250,5 },//13
{ 80,580,5 },//
{ 80,180,5 },//
{ 80,180,5 },//
{ 80,400,5 },//
{ 80,400,5 },//18
};

int e_initLife[] = {
	1,////ステージセレクトダミーデータ
	1,////ステージセレクトダミーデータ

	1,//0
	1,
	1,

	1,
	1,
	1,

	1,
	2,
	2,

	2,
	2,
	2,

	2,
	3,
	3,

	//3,
	//3,
	//3,
	//3,
};

const int STAGE_SELECT_MAX_NUM = 2;

const int STAGE_MAX_NUM = ARRAYSIZE(e_startPagination)/*sizeof(e_startPagination) / sizeof(int)*/;


int START_PAGINATION = e_startPagination[0];

int STAGE_HEIGHT = e_stageHeight[0];

v3 INIT_POS = e_initPos[0];

int P_LIFE_MAX = e_initLife[0];


STAGE_DATA* stageSetData[] = {
	stage_select00_setData,
	stage_select01_setData,

	stage00_setData,
	stage01_setData,
	stage02_setData,
	stage03_setData,
	stage04_setData,
	stage05_setData,
	stage06_setData,
	stage07_setData,
	stage08_setData,
	stage09_setData,
	stage10_setData,
	stage11_setData,
	stage12_setData,
	stage13_setData,
	stage14_setData,
	stage15_setData,
	stage16_setData,
	stage17_setData,
	stage18_setData,
};



STAGE_DATA stage00_setData[] = {

	//// ページ 左
	//
	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 0], 0, M_TYPE::GAME_RULE_LEFT,				M_DRAW::UP,		v3(0,0,0),					false, v3(0,0,0), 10),
	//
	//
	//// ページ 右
	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 0] + 1, 0, M_TYPE::GAME_RULE_RIGHT,		M_DRAW::UP,		v3(0,0,0),					false, v3(0,0,0), 10),

	// ページ１
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 0], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,PH / 2,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 0], 0, M_TYPE::KEY,						M_DRAW::UP,		v3(PW / 2,PH / 2 - 58,0),	true, v3(70,58,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 0], 0, M_TYPE::FOREST_1,				M_DRAW::UP,		v3(100,PH / 2 - 36,0),	false, v3(83,36,0), 10),

	//ページ２
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 0] + 1, 0, M_TYPE::BORDER_INNER,			M_DRAW::UP,		v3(0,PH / 2,1),		true, v3(PW ,11,0), 10),
	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1] + 1, 0, M_TYPE::RECOVERY,				M_DRAW::UP,		v3(100,PH / 2 - 64,0),	true, v3(64,64,0), 2),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 0] + 1, 0, M_TYPE::DOOR,					M_DRAW::UP,		v3(450,PH / 2 - 76,0),	true, v3(70,76,0), LOW_CONCENTRATION),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};