#include "../game.h"
#include "../map_obj.h"

#include "../stage_data.h"

STAGE_DATA stage02_setData[] = {

	// ページ１
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,250,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,560,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,840,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2], 0 , M_TYPE::HIGH_CONCENTRATION,		M_DRAW::UP,		v3(0,260,0),		true, v3(PW ,310,0), 3),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2], 0, M_TYPE::KEY,						M_DRAW::UP,		v3(PW / 2,560 - 111,0),	true, v3(124,111,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2],0  ,M_TYPE::DOOR,					M_DRAW::UP,		v3(60,840 - 111,0),	true, v3(124,111,0), 8),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2],0  ,M_TYPE::TUTORIAL_3,					M_DRAW::UP,		v3(150,130,0),	false, v3(309,54,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2], 0, M_TYPE::FOREST_3,				M_DRAW::UP,		v3(200,250 - 56,0),	false, v3(119,56,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2], 0, M_TYPE::FOREST_4,				M_DRAW::UP,		v3(80,250 - 25,0),	false, v3(169,25,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2], 0, M_TYPE::FOREST_11,				M_DRAW::UP,		v3(440,250 - 110,0),	false, v3(146,110,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2], 0, M_TYPE::FOREST_7,				M_DRAW::UP,		v3(360,840 - 138,0),	false, v3(91,138,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2], 0, M_TYPE::FOREST_8,				M_DRAW::UP,		v3(430,840 - 128,0),	false, v3(115,128,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2],0, M_TYPE::FOREST_1,				M_DRAW::UP,		v3(450,840 - 36,0),	false, v3(44,113,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2],0, M_TYPE::FOREST_8,				M_DRAW::UP,		v3(470,840 - 128,0),	false, v3(44,113,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2],0, M_TYPE::FOREST_9,				M_DRAW::UP,		v3(350,250 - 113,0),	false, v3(44,113,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2],0, M_TYPE::FOREST_10,				M_DRAW::UP,		v3(250,250 - 113,0),	false, v3(44,113,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2],0, M_TYPE::FOREST_11,				M_DRAW::UP,		v3(480,250 - 113,0),	false, v3(44,113,0), 10),


	//ページ２
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,410,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,840,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2] + 1,0, M_TYPE::HIGH_CONCENTRATION,		M_DRAW::UP,		v3(0,410,0),		true, v3(PW ,430,0), 3),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2] + 1, 0, M_TYPE::FOREST_6,				M_DRAW::MIRROR,		v3(60,410 - 143,0),	false, v3(89,143,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2] + 1, 0, M_TYPE::FOREST_9,				M_DRAW::UP,		v3(398,410 - 107,0),	false, v3(33,107,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2] + 1, 0, M_TYPE::FOREST_10,				M_DRAW::UP,		v3(408,410 - 113,0),	false, v3(44,113,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2] + 1, 0, M_TYPE::FOREST_1,				M_DRAW::UP,		v3(330,410 - 36,0),	false, v3(83,36,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2] + 1, 0, M_TYPE::FOREST_2,				M_DRAW::UP,		v3(490,410 - 43,0),	false, v3(57,43,0), 10),

	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2] + 1, 0, M_TYPE::KEY,						M_DRAW::UP,		v3(120,900 - 30,0),	true, v3(50,30,0), 10),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};