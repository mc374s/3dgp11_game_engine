#include "../game.h"
#include "../map_obj.h"

#include "../stage_data.h"

STAGE_DATA stage14_setData[] = {

	// ページ１
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,200,1),		true, v3(120,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(240,200,1),		true, v3(120,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(480,200,1),		true, v3(140,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,400,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(PW/2,600,1),		true, v3(PW/2,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(PW / 2,800,1),		true, v3(PW / 2,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(10,870,1),		true, v3(80,11,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(300,1000,1),		true, v3(80,11,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(155,1300,1),		true, v3(465,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,1400,1),		true, v3(155,11,0), 10),



	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,200,1),		true, v3(11,200,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,600,1),		true, v3(11,200,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,1110,1),		true, v3(11,190,0), 10),



	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::PASSABLE_UP,				M_DRAW::UP,		v3(120,200,1),		true, v3(120,11,0), 0),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::PASSABLE_DOWN,				M_DRAW::DOWN,		v3(360,195,1),		true, v3(120,11,0), 0),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::PASSABLE_DOWN,				M_DRAW::DOWN,		v3(0,1095,1),		true, v3(PW,11,0), 0),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::PASSABLE_DOWN,				M_DRAW::DOWN,		v3(0,1295,1),		true, v3(155,11,0), 0),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::PASSABLE_DOWN,				M_DRAW::DOWN,		v3(155,1395,1),		true, v3(465,11,0), 0),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::DOOR_5_2,					M_DRAW::UP,		v3(480,1300 - 99,0),	true, v3(128, 99,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::DESERT_6,				M_DRAW::UP,		v3(160,400 - 47,0),	false, v3(132,47,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::DESERT_5,				M_DRAW::MIRROR,		v3(320,400 - 131,0),	false, v3(154,131,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::DESERT_2,				M_DRAW::UP,		v3(430,400 - 32,0),	false, v3(178,32,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::DESERT_4,				M_DRAW::UP,		v3(350,800 - 49,0),	false, v3(59,49,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::DESERT_4,				M_DRAW::UP,		v3(430,800 - 49,0),	false, v3(59,49,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::DESERT_4,				M_DRAW::UP,		v3(510,800 - 49,0),	false, v3(59,49,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::DESERT_4,				M_DRAW::MIRROR,		v3(450,600 - 49,0),	false, v3(59,49,0), 10),


	//ページ２
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(155,200,1),		true, v3(PW/2,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(PW/2,400,1),		true, v3(PW/2,11,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(PW / 2,600,1),		true, v3(PW / 2,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,800,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(155,1100,1),		true, v3(465,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,1400,1),		true, v3(80,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(160,1400,1),		true, v3(80,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(320,1400,1),		true, v3(80,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(480,1400,1),		true, v3(140,11,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,200,1),		true, v3(11,600,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,1100,1),		true, v3(11,200,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::PASSABLE_UP,				M_DRAW::UP,		v3(0,200,1),		true, v3(155,11,0), 0),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::PASSABLE_DOWN,				M_DRAW::DOWN,		v3(465,195,1),		true, v3(155,11,0), 0),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::PASSABLE_DOWN,				M_DRAW::DOWN,		v3(0,595,1),		true, v3(PW/2,11,0), 0),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::PASSABLE_UP,				M_DRAW::UP,		v3(0,1100,1),		true, v3(155,11,0), 0),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::PASSABLE_UP,				M_DRAW::UP,		v3(0,1300,1),		true, v3(PW,11,0), 0),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::PASSABLE_DOWN,				M_DRAW::DOWN,		v3(80,1395,1),		true, v3(80,11,0), 0),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::PASSABLE_DOWN,				M_DRAW::DOWN,		v3(240,1395,1),		true, v3(80,11,0), 0),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::PASSABLE_DOWN,				M_DRAW::DOWN,		v3(400,1395,1),		true, v3(80,11,0), 0),



	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::KEY_5_1,					M_DRAW::UP,		v3(0,1440 - 99,0),	true, v3(128, 99,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::KEY_5_2,					M_DRAW::UP,		v3(480,800 - 99,0),	true, v3(128, 99,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::DOOR_5_1,					M_DRAW::UP,		v3(480,600 - 99,0),	true, v3(128, 99,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::DESERT_8,				M_DRAW::UP,		v3(400,1100 - 93,0),	false, v3(185,93,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::DESERT_7,				M_DRAW::UP,		v3(250,1100 - 29,0),	false, v3(146,29,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::DESERT_5,				M_DRAW::UP,		v3(280,200 - 131,0),	false, v3(154,131,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::DESERT_4,				M_DRAW::UP,		v3(200,200 - 49,0),	false, v3(59,49,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::DESERT_4,				M_DRAW::MIRROR,		v3(450,400 - 49,0),	false, v3(59,49,0), 10),


	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 12] + 1,0, M_TYPE::DOOR,					M_DRAW::UP,		v3(PW / 2,1039 - 111,0),	true, v3(124,111,0), 8),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};