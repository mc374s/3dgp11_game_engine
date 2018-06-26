#include "../game.h"
#include "../map_obj.h"

#include "../stage_data.h"

STAGE_DATA stage10_setData[] = {

	// ページ１
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(100,240,1),		true, v3(520,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,350,1),		true, v3(100,11,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10], 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,		v3(0,235,1),		true, v3(100,11,0), 2, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10], 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,		v3(100,345,1),		true, v3(520,11,0), 2, recoveryControl),





	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10], 0, M_TYPE::KEY_1_1,						M_DRAW::UP,		v3(50,1800 - 99,0),	true, v3(111,99,0), 10),





	//ページ２
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10] + 1,  0, M_TYPE::BORDER_INNER,					M_DRAW::UP,		v3(0,350,1),		true, v3(80,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10] + 1,  0, M_TYPE::BORDER_INNER,					M_DRAW::UP,		v3(160,350,1),		true, v3(80,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10] + 1,  0, M_TYPE::BORDER_INNER,					M_DRAW::UP,		v3(320,350,1),		true, v3(80,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10] + 1,  0, M_TYPE::BORDER_INNER,					M_DRAW::UP,		v3(480,350,1),		true, v3(140,11,0), 10),


	
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10] + 1, 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,		v3(80,345,1),		true, v3(80,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10] + 1, 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,		v3(240,345,1),		true, v3(80,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10] + 1, 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,		v3(400,345,1),		true, v3(80,11,0), 0, recoveryControl),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10] + 1, 0, M_TYPE::PASSABLE_UP,			M_DRAW::UP,		v3(0,240,1),		true, v3(PW,11,0), 0, recoveryControl),
	


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10] + 1, 0,M_TYPE::DOOR_1_1,						M_DRAW::UP,		v3(10,350 - 99,0),	true, v3(111,99,0), 8),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};