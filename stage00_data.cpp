#include "game.h"
#include "map_obj.h"

#include "stage_data.h"

int STAGE_HEIGHT = (1150 - 76) - (PH - 100);

STAGE_DATA stage00_setData[] = {

	//ページ 1 旧バージョン
	//STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,130,1),		true, v3(PW,17,0), 10),
	//STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,350,1),		true, v3(PW,17,0), 10),
	//STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,580,1),		true, v3(PW,17,0), 10),
	//STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,750,1),		true, v3(PW,17,0), 10),
	//STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,930,1),		true, v3(250,17,0), 10),
	//STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(400,930,1),		true, v3(220,17,0), 10),
	//STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::LEFT,	v3(250,750,1),		true, v3(17,200,0), 10),
	//STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,1150,1),		true, v3(PW,17,0), 10),
	//STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,1330,1),		true, v3(PW,17,0), 10),
	//STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::LEFT,	v3(PW/2,1330,1),	true, v3(17,330,0), 10),
	//STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,1520,1),		true, v3(310,17,0), 10),
	//STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(315,1650,1),		true, v3(310,17,0), 10),
	//STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,1750,1),		true, v3(PW,17,0), 10),

	//STAGE_DATA(1, 0, M_TYPE::KEY, M_DRAW::UP, v3(300,400,1),true, v3(50,50,0), 10),
	//STAGE_DATA(2, 0, M_TYPE::DOOR, M_DRAW::UP, v3(200,200,1),true, v3(50,100,0), 10),

	//STAGE_DATA(1, 0, M_TYPE::IVY_THIN,				M_DRAW::UP,		v3(267,930,1),		true, v3(133,22,0), LOW_CONCENTRATION),
	//STAGE_DATA(1, 0, M_TYPE::HIGH_CONCENTRATION,	M_DRAW::UP,		v3(0,350,0),		true, v3(PW,230,0), 5),
	//STAGE_DATA(1, 0, M_TYPE::KEY,					M_DRAW::UP,		v3(10,930-50,0),	true, v3(50,50,0), 10),

	//ページ１
	STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,220,1),		true, v3(PW,17,0), 10),
	STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,520,1),		true, v3(PW,17,0), 10),
	STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::LEFT,	v3(PW/2,520,1),		true, v3(17,380,0), 10),
	STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,900,1),		true, v3(PW,17,0), 10),

	STAGE_DATA(1, 0, M_TYPE::KEY,					M_DRAW::UP,		v3(400,900 - 50,0),	true, v3(50,50,0), 10),
	STAGE_DATA(1, 0, M_TYPE::DOOR,					M_DRAW::UP,		v3(530,520 - 76,0),	true, v3(51,76,0), LOW_CONCENTRATION),



	//ページ 2 旧バージョン
	//STAGE_DATA(2, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,240,1),		true, v3(PW,17,0), 10),
	//STAGE_DATA(2, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,470,1),		true, v3(PW,17,0), 10),
	//STAGE_DATA(2, 0, M_TYPE::IVY_THICK,				M_DRAW::LEFT,	v3(310,470,1),		true, v3(17,280,0), 10),
	//STAGE_DATA(2, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,750,1),		true, v3(170,17,0), 10),
	//STAGE_DATA(2, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(310,750,1),		true, v3(310,17,0), 10),
	//STAGE_DATA(2, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,1150,1),	true, v3(PW,17,0), 10),
	//STAGE_DATA(2, 0, M_TYPE::IVY_THICK,				M_DRAW::LEFT,	v3(PW/2,930,1),		true, v3(17,220,0), 10),
	//STAGE_DATA(2, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,930,1),		true, v3(PW,17,0), 10),
	//STAGE_DATA(2, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,1430,1),		true, v3(PW,17,0), 10),
	//STAGE_DATA(2, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,1750,1),		true, v3(PW,17,0), 10),

	//STAGE_DATA(2, 0, M_TYPE::IVY_THIN,				M_DRAW::UP,		v3(170,750,1),		true, v3(140,22,0), LOW_CONCENTRATION),
	//STAGE_DATA(2, 0, M_TYPE::IVY_THIN,				M_DRAW::UP,		v3(0,1150,1),		true, v3(PW/2,22,0), LOW_CONCENTRATION),
	//STAGE_DATA(2, 0, M_TYPE::IVY_THIN,				M_DRAW::UP,		v3(0,1560,1),		true, v3(PW,22,0), LOW_CONCENTRATION),

	//STAGE_DATA(2, 0, M_TYPE::DOOR,					M_DRAW::UP,		v3(200,1150 - 76,0),	true, v3(51,76,0), LOW_CONCENTRATION),
	//STAGE_DATA(2, 0, M_TYPE::HIGH_CONCENTRATION,	M_DRAW::UP,	v3(310,470,0),		true, v3(310,280,0), 5),

	//ページ２
	STAGE_DATA(2, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,350,1),		true, v3(PW/2,17,0), 10),
	STAGE_DATA(2, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(470,350,1),		true, v3(150,17,0), 10),
	STAGE_DATA(2, 0, M_TYPE::IVY_THICK,				M_DRAW::LEFT,	v3(PW/2,350,1),		true, v3(17,300,0), 10),
	STAGE_DATA(2, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,650,1),		true, v3(500,17,0), 10),
	STAGE_DATA(2, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,900,1),		true, v3(PW,17,0), 10),

	STAGE_DATA(2, 0, M_TYPE::IVY_THIN,				M_DRAW::UP,		v3(PW/2,350,1),		true, v3(160,22,0), LOW_CONCENTRATION),
	STAGE_DATA(2, 0, M_TYPE::IVY_THIN,				M_DRAW::UP,		v3(500,650,1),		true, v3(120,22,0), LOW_CONCENTRATION),

	STAGE_DATA(2, 0, M_TYPE::HIGH_CONCENTRATION,	M_DRAW::UP,		v3(0,350,0),		true, v3(PW/2,300,0), 5),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};