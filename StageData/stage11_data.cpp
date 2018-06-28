#include "../game.h"
#include "../map_obj.h"

#include "../stage_data.h"

STAGE_DATA stage11_setData[] = {

	// ページ１
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(60,200,1),		true, v3(75,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(200,350,1),		true, v3(75,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(60,500,1),		true, v3(75,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(465,500,1),		true, v3(75,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,800,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(465,930,1),		true, v3(75,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(280,1100,1),		true, v3(75,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(100,1100,1),		true, v3(75,11,0), 10),

	
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::PASSABLE_DOWN,				M_DRAW::DOWN,		v3(0,565,1),		true, v3(PW,11,0), 2),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::DOOR_4_3,					M_DRAW::UP,		v3(80,1100 - 129,0),	true, v3(100,129,0), 8),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::SNOW_8,				M_DRAW::UP,		v3(50,800 - 141,0),	false, v3(119,141,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::SNOW_1,				M_DRAW::UP,		v3(450,800 - 82,0),	false, v3(87,82,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::SNOW_6,				M_DRAW::UP,		v3(100,100,0),	false, v3(45,52,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::SNOW_7,				M_DRAW::UP,		v3(400,200,0),	false, v3(39,38,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::SNOW_6,				M_DRAW::UP,		v3(500,300,0),	false, v3(45,52,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::SNOW_7,				M_DRAW::UP,		v3(200,400,0),	false, v3(39,38,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::SNOW_6,				M_DRAW::UP,		v3(400,500,0),	false, v3(45,52,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::SNOW_7,				M_DRAW::UP,		v3(300,600,0),	false, v3(39,38,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::SNOW_7,				M_DRAW::UP,		v3(420,650,0),	false, v3(39,38,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::SNOW_6,				M_DRAW::UP,		v3(250,690,0),	false, v3(45,52,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::SNOW_7,				M_DRAW::UP,		v3(200,850,0),	false, v3(39,38,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::SNOW_6,				M_DRAW::UP,		v3(300,990,0),	false, v3(45,52,0), 10),


	//ページ２
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,250,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,570,1),		true, v3(465,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(420,730,1),		true, v3(75,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(465,920,1),		true, v3(75,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(200,1100,1),		true, v3(75,11,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,250,1),		true, v3(11,320,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::PASSABLE_UP,				M_DRAW::UP,		v3(465,570,1),		true, v3(155,11,0), 0),

	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 11] + 1, 0, M_TYPE::HIGH_CONCENTRATION,		M_DRAW::UP,		v3(0,220,0),		true, v3(PW / 2,320,0), 3),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::KEY_4_3,						M_DRAW::UP,		v3(100,570 - 129,0),	true, v3(111,129,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::SNOW_2,				M_DRAW::UP,		v3(400,250 - 103,0),	false, v3(187,103,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::SNOW_3,				M_DRAW::UP,		v3(60,250 - 71,0),	false, v3(146,71,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::SNOW_6,				M_DRAW::UP,		v3(150,70,0),	false, v3(45,52,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::SNOW_7,				M_DRAW::UP,		v3(280,100,0),	false, v3(39,38,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::SNOW_1,				M_DRAW::UP,		v3(340,570 - 82,0),	false, v3(87,82,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::SNOW_6,				M_DRAW::UP,		v3(350,400,0),	false, v3(45,52,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::SNOW_7,				M_DRAW::UP,		v3(430,340,0),	false, v3(39,38,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::SNOW_7,				M_DRAW::UP,		v3(530,500,0),	false, v3(39,38,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::SNOW_7,				M_DRAW::UP,		v3(230,450,0),	false, v3(39,38,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::SNOW_6,				M_DRAW::UP,		v3(100,350,0),	false, v3(45,52,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::SNOW_7,				M_DRAW::UP,		v3(530,630,0),	false, v3(39,38,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::SNOW_7,				M_DRAW::UP,		v3(230,750,0),	false, v3(39,38,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::SNOW_6,				M_DRAW::UP,		v3(100,850,0),	false, v3(45,52,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::SNOW_7,				M_DRAW::UP,		v3(350,900,0),	false, v3(39,38,0), 10),

	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};