#include "../game.h"
#include "../map_obj.h"

#include "../stage_data.h"

STAGE_DATA stage01_setData[] = {

	// ページ１											
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 1], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,300,1),		true, v3(PW,11,0), 10),
														
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 1], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,650,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 1], 0, M_TYPE::DOOR_1_1,					M_DRAW::UP,		v3(50,300 - 99,0),	true, v3(111,99,0), 8),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 1], 0, M_TYPE::FOREST_5,				M_DRAW::UP,		v3(360,650 - 26,0),	false, v3(168,26,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 1], 0, M_TYPE::FOREST_8,				M_DRAW::UP,		v3(470,650 - 128,0),	false, v3(115,128,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 1], 0, M_TYPE::FOREST_11,				M_DRAW::UP,		v3(160,300 - 110,0),	false, v3(146,110,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 1], 0, M_TYPE::TUTORIAL_2,				M_DRAW::UP,		v3(300,500,0),	false, v3(157,26,0), 10),

	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 1], 0, M_TYPE::PASSABLE_UP,				M_DRAW::UP,		v3(155,680,1),		true, v3(155,22,0), 3, recoveryControl),
	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 1], 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(465,680,1),		true, v3(155,22,0), 3, recoveryControl),







	//ページ２
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 1] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,500,1),		true, v3(PW,11,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 1] + 1, 0, M_TYPE::KEY_1_1,						M_DRAW::UP,		v3(PW / 2,500 - 99,0),	true, v3(111,99,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 1] + 1, 0, M_TYPE::TUTORIAL_8,				M_DRAW::UP,		v3(150,300,0),	false, v3(335,61,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 1] + 1, 0, M_TYPE::FOREST_6,				M_DRAW::UP,		v3(470,500 - 143,0),	false, v3(89,143,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 1] + 1, 0, M_TYPE::FOREST_10,				M_DRAW::UP,		v3(140,500 - 113,0),	false, v3(44,113,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1 + 1] + 1, 0, M_TYPE::FOREST_4,				M_DRAW::UP,		v3(160,500 - 25,0),	false, v3(169,25,0), 10),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};