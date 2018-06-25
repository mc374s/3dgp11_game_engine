#include "../game.h"
#include "../map_obj.h"

#include "../stage_data.h"

STAGE_DATA stage11_setData[] = {

	// ページ１
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(60,200,1),		true, v3(75,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(200,350,1),		true, v3(75,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(60,500,1),		true, v3(75,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(465,500,1),		true, v3(75,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(465,930,1),		true, v3(75,11,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(280,1100,1),		true, v3(75,11,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(100,1100,1),		true, v3(75,11,0), 10),


	
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::PASSABLE_DOWN,				M_DRAW::DOWN,		v3(0,570,1),		true, v3(PW,11,0), 2, recoveryControl),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,800,1),		true, v3(PW,11,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11], 0, M_TYPE::DOOR_1_1,					M_DRAW::UP,		v3(80,1100 - 99,0),	true, v3(111,99,0), 8),


	//ページ２
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,250,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,570,1),		true, v3(465,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(420,730,1),		true, v3(75,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(465,920,1),		true, v3(75,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(200,1100,1),		true, v3(75,11,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,250,1),		true, v3(11,320,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::PASSABLE_UP,				M_DRAW::UP,		v3(465,570,1),		true, v3(155,11,0), 0, recoveryControl),

	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 11] + 1, 0, M_TYPE::HIGH_CONCENTRATION,		M_DRAW::UP,		v3(0,220,0),		true, v3(PW / 2,320,0), 3),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 11] + 1, 0, M_TYPE::KEY_1_1,						M_DRAW::UP,		v3(100,570 - 99,0),	true, v3(111,99,0), 10),

	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};