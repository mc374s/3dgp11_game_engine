#include "game.h"
#include "map_obj.h"

#include "stage_data.h"

STAGE_DATA stage00_setData[] = {

	//STAGE_DATA(0, M_TYPE::IVY_THICK, M_DRAW::UP, true, v3(0,0,0),true, v3(PW,22,0), 10),
	//STAGE_DATA(0, M_TYPE::IVY_THICK, M_DRAW::DOWN, true, v3(0,PH - 22,0),true, v3(PW,22,0), 10),
	//STAGE_DATA(0, M_TYPE::IVY_THICK, M_DRAW::LEFT, true, v3(0,0,0),true, v3(22,PH,0), 10),
	//STAGE_DATA(0, M_TYPE::IVY_THICK, M_DRAW::UP, true, v3(300,500,0),true, v3(600,22,0), 10),
	//STAGE_DATA(0, M_TYPE::IVY_THICK, M_DRAW::UP, false, v3(0,0,0),true, v3(PW,22,0), 10),
	//STAGE_DATA(0, M_TYPE::IVY_THICK, M_DRAW::DOWN, false, v3(0,PH - 22,0),true, v3(PW,22,0), 10),
	//STAGE_DATA(0, M_TYPE::IVY_THICK, M_DRAW::UP, true, v3(300,500,0),true, v3(600,22,0), 10),
	//STAGE_DATA(0, M_TYPE::IVY_THICK, M_DRAW::RIGHT, false, v3(PW-22,0,0),true, v3(22,PH,0), 10),

	//STAGE_DATA(0, M_TYPE::TREE_A, M_DRAW::UP, true, v3(50,100,0),false, v3(0,0,0), 10),
	//STAGE_DATA(0, M_TYPE::TREE_A, M_DRAW::UP, false, v3(100,100,0),false, v3(0,0,0), 10),
	//STAGE_DATA(0, M_TYPE::HOUSE, M_DRAW::UP, true, v3(200,100,0),false, v3(0,0,0), 10),
	//STAGE_DATA(0, M_TYPE::HOUSE, M_DRAW::UP, false, v3(200,100,0),false, v3(0,0,0), 10),

	//ページ 1
	STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,130,1),		true, v3(PW,22,0), 10),
	STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,350,1),		true, v3(PW,22,0), 10),
	STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,580,1),		true, v3(PW,22,0), 10),
	STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,750,1),		true, v3(PW,22,0), 10),
	STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,930,1),		true, v3(120,22,0), 10),
	STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(400,930,1),		true, v3(220,22,0), 10),
	STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::LEFT,	v3(250,750,1),		true, v3(22,200,0), 10),
	STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,1150,1),		true, v3(PW,22,0), 10),
	STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,1330,1),		true, v3(PW,22,0), 10),
	STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::LEFT,	v3(PW/2,1330,1),	true, v3(22,330,0), 10),
	STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,1520,1),		true, v3(310,22,0), 10),
	STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(315,1650,1),		true, v3(310,22,0), 10),
	STAGE_DATA(1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,1750,1),		true, v3(PW,22,0), 10),

	//STAGE_DATA(0, M_TYPE::KEY, M_DRAW::UP, true, v3(300,400,1),true, v3(50,50,0), 10),
	//STAGE_DATA(0, M_TYPE::DOOR, M_DRAW::UP, false, v3(200,200,1),true, v3(50,100,0), 10),

	STAGE_DATA(1, 0, M_TYPE::IVY_THIN,				M_DRAW::UP,		v3(120,930,1),		true, v3(280,22,0), LOW_CONCENTRATION),
	STAGE_DATA(1, 0, M_TYPE::HIGH_CONCENTRATION,	M_DRAW::UP,		v3(0,350,0),		true, v3(PW,230,0), 5),
	STAGE_DATA(1, 0, M_TYPE::DOOR,					M_DRAW::UP,		v3(10,1676,0),		true, v3(51,76,0), 10),
	STAGE_DATA(1, 0, M_TYPE::KEY,					M_DRAW::UP,		v3(10,930-50,0),	true, v3(50,50,0), 10),


	//ページ 2
	STAGE_DATA(2, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,240,1),		true, v3(PW,22,0), 10),
	STAGE_DATA(2, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,470,1),		true, v3(PW,22,0), 10),
	STAGE_DATA(2, 0, M_TYPE::IVY_THICK,				M_DRAW::LEFT,	v3(310,470,1),		true, v3(22,280,0), 10),
	STAGE_DATA(2, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,750,1),		true, v3(170,22,0), 10),
	STAGE_DATA(2, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(310,750,1),		true, v3(310,22,0), 10),
	STAGE_DATA(2, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(PW/2,1150,1),	true, v3(PW/2,22,0), 10),
	STAGE_DATA(2, 0, M_TYPE::IVY_THICK,				M_DRAW::LEFT,	v3(PW/2,930,1),		true, v3(22,220,0), 10),
	STAGE_DATA(2, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,1430,1),		true, v3(PW,22,0), 10),
	STAGE_DATA(2, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,1750,1),		true, v3(PW,22,0), 10),

	STAGE_DATA(2, 0, M_TYPE::IVY_THIN,				M_DRAW::UP,		v3(170,750,1),		true, v3(140,22,0), LOW_CONCENTRATION),
	STAGE_DATA(2, 0, M_TYPE::IVY_THIN,				M_DRAW::UP,		v3(0,930,1),		true, v3(PW,22,0), LOW_CONCENTRATION),
	STAGE_DATA(2, 0, M_TYPE::IVY_THIN,				M_DRAW::UP,		v3(0,1150,1),		true, v3(PW/2,22,0), LOW_CONCENTRATION),
	STAGE_DATA(2, 0, M_TYPE::IVY_THIN,				M_DRAW::UP,		v3(0,1560,1),		true, v3(PW,22,0), LOW_CONCENTRATION),



	STAGE_DATA(2, 0, M_TYPE::HIGH_CONCENTRATION,	M_DRAW::UP,	v3(310,470,0),		true, v3(310,280,0), 5),



	/*STAGE_DATA(0, M_TYPE::TREE_A, M_DRAW::UP, true, v3(50,100,0),false, v3(0,0,0), 10),
	STAGE_DATA(0, M_TYPE::TREE_A, M_DRAW::UP, false, v3(100,100,0),false, v3(0,0,0), 10),
	STAGE_DATA(0, M_TYPE::HOUSE, M_DRAW::UP, true, v3(200,100,0),false, v3(0,0,0), 10),
	STAGE_DATA(0, M_TYPE::HOUSE, M_DRAW::UP, false, v3(200,100,0),false, v3(0,0,0), 10),
	STAGE_DATA(0, M_TYPE::IVY_BIG, M_DRAW::UP, false, v3(200,400,0),true, v3(79,47,0), 10),
	STAGE_DATA(0, M_TYPE::IVY_THICK, M_DRAW::UP, true, v3(300,500,0),true, v3(600,22,0), 10),
	STAGE_DATA(0, M_TYPE::IVY_THICK, M_DRAW::UP, false, v3(300,100,0),true, v3(600,22,0), 10),
	STAGE_DATA(0, M_TYPE::IVY_THIN, M_DRAW::UP, false, v3(200,200,0),true, v3(200,22,0), 10),
	STAGE_DATA(0, M_TYPE::IVY_THIN, M_DRAW::DOWN, false, v3(200,222,0),true, v3(200,22,0), 10),
	STAGE_DATA(0, M_TYPE::IVY_THIN, M_DRAW::LEFT, false, v3(178,400,0),true, v3(22,200,0), 10),
	STAGE_DATA(0, M_TYPE::IVY_THIN, M_DRAW::RIGHT, false, v3(422,400,0),true, v3(22,200,0), 10),*/

	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};