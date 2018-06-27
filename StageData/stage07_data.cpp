#include "../game.h"
#include "../map_obj.h"

#include "../stage_data.h"

STAGE_DATA stage07_setData[] = {

	// ページ１
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 7], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(100,240,1),		true, v3(100,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 7], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(250,580,1),		true, v3(155,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 7], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,680,1),		true, v3(PW,11,0), 10),



	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 7], 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(0,300 - 8,1),		true, v3(PW,11,0), 0, recoveryControl),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 7], 0, M_TYPE::DOOR_3_1,					M_DRAW::UP,		v3(90,240 - 133,0),	true, v3(101, 133,0), 8),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 7] , 0, M_TYPE::GRAVE_9,				M_DRAW::UP,		v3(120,680 - 77,0),	false, v3(56,77,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 7] , 0, M_TYPE::GRAVE_10,				M_DRAW::UP,		v3(500,680 - 84,0),	false, v3(76,84,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 7] , 0, M_TYPE::GRAVE_5,				M_DRAW::UP,		v3(420,680 - 95,0),	false, v3(74,95,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 7] , 0, M_TYPE::GRAVE_6,				M_DRAW::UP,		v3(150,480,0),	false, v3(66,102,0), 10),


	//ページ２


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 7] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(PW / 2,500,1),		true, v3(155,11,0), 10),
	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 7] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,720,1),		true, v3(PW,11,0), 10),



	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 7] + 1, 0, M_TYPE::KEY_3_1,					M_DRAW::UP,		v3(PW/2,500 - 133,0),	true, v3(101, 133,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 7] + 1, 0, M_TYPE::GRAVE_3,				M_DRAW::MIRROR,		v3(400,200,0),	false, v3(122,100,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 7] + 1, 0, M_TYPE::GRAVE_3,				M_DRAW::UP,		v3(100,400,0),	false, v3(122,100,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 7] + 1, 0, M_TYPE::GRAVE_4,				M_DRAW::UP,		v3(450,40,0),	false, v3(50,89,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 7] + 1, 0, M_TYPE::GRAVE_8,				M_DRAW::UP,		v3(200,100,0),	false, v3(80,146,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 7] + 1, 0, M_TYPE::GRAVE_7,				M_DRAW::UP,		v3(100,200,0),	false, v3(80,121,0), 10),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};