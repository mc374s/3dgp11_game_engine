#include "game.h"
#include "map_obj.h"

#include "stage_data.h"

int e_stageHeight[] = {
	0,////ステージセレクトダミーデータ
	0,////ステージセレクトダミーデータ

	0,	//1章まえがき
	0,					//STAGE 1-1
	0,					//STAGE 1-2
	(840) - (PH - 100),	//STAGE 1-3

	0,	//2章まえがき
	0,					//STAGE 2-1
	(900) - (PH - 100),	//STAGE 2-2
	(900) - (PH - 100),	//STAGE 2-3

	0,	//3章まえがき
	(1039) - (PH - 100),//STAGE 3-1
	(1020) - (PH - 100),//STAGE 3-2
	(1550) - (PH - 100),//STAGE 3-3

	0,	//4章まえがき
	(1150) - (PH - 100),//STAGE 4-1
	(3000) - (PH - 100),//STAGE 4-2
	(1500) - (PH - 100),//STAGE 4-3

	0,	//5章まえがき
	(1200) - (PH - 100),//STAGE 5-1
	(1000) - (PH - 100),//STAGE 5-2			
	0,					//STAGE 5-3

	//(840) - (PH - 100),
	//0,
	//(900) - (PH - 100),
	//(1039) - (PH - 100),//19

};

int e_startPagination[] = {
	3,////ステージ 1-1~4-3 セレクトページ目
	5,////ステージ 5-1~8-3 セレクトページ目

	7,//1章まえがき
	9, //STAGE 1-1 
	15,//STAGE 1-2
	21,//STAGE 1-3

	27,//2章まえがき
	29,//STAGE 2-1
	35,//STAGE 2-2
	41,//STAGE 2-3

	47,//3章まえがき
	53,//STAGE 3-1  
	59,//STAGE 3-2
	65,//STAGE 3-3

	71,//4章まえがき
	73,//STAGE 4-1
	79,//STAGE 4-2
	85,//STAGE 4-3
	
	91,//5章まえがき
	97,//STAGE 5-1
	103,//STAGE 5-2
	109,//STAGE 5-3

	//129-4,
	//135-4,
	//141-4,
	//147-4,
};

v3 e_initPos[] = {
	{ 80,300,5 },////ステージセレクトダミーデータ
	{ 80,300,5 },////ステージセレクトダミーデータ

	{ 80,300,5 },//まえがきダミー
	{ 80,250,5 },//STAGE 1-1
	{ 80,580,5 },//STAGE 1-2
	{ 80,180,5 },//STAGE 1-3

	{ 80,300,5 },//まえがきダミー
	{ 80,180,5 },//STAGE 2-1
	{ 80,400,5 },//STAGE 2-2
	{ 80,400,5 },//STAGE 2-3

	{ 80,300,5 },//まえがきダミー
	{ 80,400,5 },//STAGE 3-1
	{ 80,430,5 },//STAGE 3-2
	{ 220,400,5 },//STAGE 3-3

	{ 80,300,5 },//まえがきダミー
	{ 80,140,5 },//STAGE 4-1
	{ 80,180,5 },//STAGE 4-2
	{ 70,180,5 },//STAGE 4-3

	{ 80,300,5 },//まえがきダミー
	{ 250,180,5 },//STAGE 5-1
	{ 80,180,5 },//STAGE 5-2
	{ 80,580,5 },//STAGE 5-3

	//{ 80,180,5 },//
	//{ 80,180,5 },//
	//{ 80,400,5 },//
	//{ 80,400,5 },//18
};

int e_initLife[] = {
	1,////ステージセレクトダミーデータ
	1,////ステージセレクトダミーデータ

	1,//まえがきダミー
	1,//STAGE 1-1
	1,//STAGE 1-2
	1,//STAGE 1-3

	1,//まえがきダミー
	1,//STAGE 2-1
	1,//STAGE 2-2
	1,//STAGE 2-3

	1,//まえがきダミー
	1,//STAGE 3-1
	2,//STAGE 3-2
	2,//STAGE 3-3

	1,//まえがきダミー
	2,//STAGE 4-1
	1,//STAGE 4-2
	2,//STAGE 4-3

	1,//まえがきダミー
	2,//STAGE 5-1
	3,//STAGE 5-2
	3,//STAGE 5-3

	//3,
	//3,
	//3,
	//3,
};

int e_stageKeyNum[] = {
	1,////ステージセレクトダミーデータ
	1,////ステージセレクトダミーデータ

	1,//まえがきダミー
	4,//STAGE 1-1
	1,//STAGE 1-2
	1,//STAGE 1-3

	1,//まえがきダミー
	1,//STAGE 2-1
	1,//STAGE 2-2
	1,//STAGE 2-3

	1,//まえがきダミー
	1,//STAGE 3-1
	1,//STAGE 3-2
	1,//STAGE 3-3

	1,//まえがきダミー
	5,//STAGE 4-1
	1,//STAGE 4-2
	1,//STAGE 4-3

	1,//まえがきダミー
	3,//STAGE 5-1
	2,//STAGE 5-2
	1,//STAGE 5-3

	  //3,
	  //3,
	  //3,
	  //3,
};


const int STAGE_SELECT_MAX_NUM = 2;

// Be sure that STAGE_MAX_NUM is lowwer than STAGE_LIMITTED_NUM
const int STAGE_MAX_NUM = ARRAYSIZE(e_startPagination)/*sizeof(e_startPagination) / sizeof(int)*/;


int START_PAGINATION = e_startPagination[0];

int STAGE_HEIGHT = e_stageHeight[0];

v3 INIT_POS = e_initPos[0];

int P_LIFE_MAX = e_initLife[0];

int STAGE_KEY_NUM = e_stageKeyNum[0];


STAGE_DATA* stageSetData[] = {
	stage_select00_setData,
	stage_select01_setData,

	stage_intro01_setData,
	stage00_setData,//STAGE 1-1
	stage01_setData,//STAGE 1-2
	stage02_setData,//STAGE 1-3

	stage_intro02_setData,
	stage03_setData,//STAGE 2-1
	stage04_setData,//STAGE 2-2
	stage05_setData,//STAGE 2-3

	stage_intro03_setData,
	stage06_setData,//STAGE 3-1
	stage07_setData,//STAGE 3-2
	stage08_setData,//STAGE 3-3

	stage_intro04_setData,
	stage09_setData,//STAGE 4-1
	stage10_setData,//STAGE 4-2
	stage11_setData,//STAGE 4-3

	stage_intro05_setData,
	stage12_setData,//STAGE 5-1
	stage13_setData,//STAGE 5-2
	stage14_setData,//STAGE 5-3
	//stage15_setData,
	//stage16_setData,
	//stage17_setData,
	//stage18_setData,
};


//STAGE 1-1
STAGE_DATA stage00_setData[] = {

	//// ページ 左
	//
	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 0], 0, M_TYPE::GAME_RULE_LEFT,				M_DRAW::UP,		v3(0,0,0),					false, v3(0,0,0), 10),
	//
	//
	//// ページ 右
	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 0] + 1, 0, M_TYPE::GAME_RULE_RIGHT,		M_DRAW::UP,		v3(0,0,0),					false, v3(0,0,0), 10),

	// ページ１
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 0], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,PH / 2,1),		true, v3(PW,11,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 0], 0, M_TYPE::KEY_1_1,						M_DRAW::UP,		v3(100,PH / 2 - 99,0),	true, v3(111, 99, 0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 0], 0, M_TYPE::DOOR_2_1,						M_DRAW::UP,		v3(250,PH / 2 - 131,0),	true, v3(117,131,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 0], 0, M_TYPE::KEY_3_1,						M_DRAW::UP,		v3(400,PH / 2 - 133,0),	true, v3(101,133,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 0], 0, M_TYPE::DOOR_3_2,						M_DRAW::UP,		v3(550,PH / 2 - 133,0),	true, v3(101,133,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 0], 0, M_TYPE::FOREST_1,				M_DRAW::UP,		v3(60,PH / 2 - 36,0),	false, v3(83,36,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 0], 0, M_TYPE::FOREST_7,				M_DRAW::UP,		v3(120,PH / 2 - 138,0),	false, v3(91,138,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 0], 0, M_TYPE::FOREST_2,				M_DRAW::UP,		v3(450,PH / 2 - 43,0),	false, v3(57,43,0), 10),
														 
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 0], 0, M_TYPE::TUTORIAL_1,				M_DRAW::UP,		v3(350,200,0),	false, v3(102,26,0), 10),
														 
	//ページ２											 
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 0] + 1, 0, M_TYPE::BORDER_INNER,			M_DRAW::UP,		v3(0,PH / 2,1),		true, v3(PW ,11,0), 10),
	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1] + 1, 0, M_TYPE::RECOVERY,				M_DRAW::UP,		v3(100,PH / 2 - 64,0),	true, v3(71,64,0), 2),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 0] + 1, 0, M_TYPE::DOOR_1_1,					M_DRAW::UP,		v3(100,PH / 2 - 99,0),	true, v3(111, 99, 0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 0] + 1, 0, M_TYPE::KEY_2_1,					M_DRAW::UP,		v3(250,PH / 2 - 131,0),	true, v3(117,131,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 0] + 1, 0, M_TYPE::DOOR_3_1,					M_DRAW::UP,		v3(400,PH / 2 - 133,0),	true, v3(101,133,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 0] + 1, 0, M_TYPE::KEY_3_2,					M_DRAW::UP,		v3(550,PH / 2 - 133,0),	true, v3(101,133,0), 10),
														 
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 0] + 1, 0, M_TYPE::FOREST_9,				M_DRAW::UP,		v3(205,PH / 2 - 107,0),	false, v3(33,107,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 0] + 1, 0, M_TYPE::FOREST_3,				M_DRAW::UP,		v3(220,PH / 2 - 56,0),	false, v3(119,56,0), 10),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};	