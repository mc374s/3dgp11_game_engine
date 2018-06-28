#include "../game.h"
#include "../map_obj.h"

#include "../stage_data.h"

STAGE_DATA stage13_setData[] = {

	// ページ１
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,220,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,520,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,720,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,1020,1),		true, v3(PW,11,0), 10),



	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,0,1),		true, v3(11,220,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,520,1),		true, v3(11,200,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::KEY_5_3,					M_DRAW::UP,		v3(490,220 - 99,0),	true, v3(128,99,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::DOOR_5_3,					M_DRAW::UP,		v3(480,720 - 99,0),	true, v3(128,99,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::KEY_5_2,					M_DRAW::UP,		v3(100,720 - 99,0),	true, v3(128,99,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::DOOR_5_2,					M_DRAW::UP,		v3(100,1020 - 99,0),	true, v3(128,99,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::DESERT_6,				M_DRAW::UP,		v3(230,520 - 47,0),	false, v3(132,47,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::DESERT_8,				M_DRAW::UP,		v3(430,520 - 93,0),	false, v3(185,93,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::DESERT_4,				M_DRAW::UP,		v3(500,1020 - 49,0),	false, v3(59,49,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::DESERT_4,				M_DRAW::UP,		v3(440,1020 - 49,0),	false, v3(59,49,0), 10),


	//ページ２
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,370,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(465,730,1),		true, v3(75,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(200,900,1),		true, v3(75,11,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,1020,1),		true, v3(PW,11,0), 10),



	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0, M_TYPE::DESERT_5,				M_DRAW::MIRROR,		v3(50,370 - 131,0),	false, v3(154,131,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0, M_TYPE::DESERT_2,				M_DRAW::UP,		v3(110,370 - 32,0),	false, v3(178,32,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0, M_TYPE::DESERT_7,				M_DRAW::UP,		v3(420,370 - 29,0),	false, v3(146,29,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0, M_TYPE::DESERT_1,				M_DRAW::MIRROR,		v3(420,1020 - 115,0),	false, v3(163,115,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0, M_TYPE::DESERT_5,				M_DRAW::UP,		v3(30,1020 - 131,0),	false, v3(154,131,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0, M_TYPE::DESERT_4,				M_DRAW::MIRROR,		v3(360,1020 - 49,0),	false, v3(59,49,0), 10),





	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 12] + 1,0, M_TYPE::DOOR,					M_DRAW::UP,		v3(PW / 2,1039 - 111,0),	true, v3(124,111,0), 8),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};
