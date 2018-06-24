#include "../game.h"
#include "../map_obj.h"

#include "../stage_data.h"

STAGE_DATA stage10_setData[] = {

	// ページ１
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,150,1),		true, v3(155,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(PW / 2,150,1),		true, v3(PW / 2,11,0), 10),
	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 10], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(155,350,1),		true, v3(155,11,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,800,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,1800,1),		true, v3(155,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(PW / 2,1800,1),		true, v3(PW / 2,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(200,2000,1),		true, v3(155,11,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(350,2100,1),		true, v3(155,11,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(200,2300,1),		true, v3(155,11,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,2500,1),		true, v3(PW,11,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10], 0, M_TYPE::PASSABLE_UP,			M_DRAW::UP,		v3(155,150,1),		true, v3(155,11,0), 2, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10], 0, M_TYPE::PASSABLE_UP,			M_DRAW::UP,		v3(155,1800,1),		true, v3(155,11,0), 2, recoveryControl),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10], 0, M_TYPE::KEY_1_1,						M_DRAW::UP,		v3(50,1800 - 99,0),	true, v3(111,99,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10], 0,M_TYPE::DOOR_1_1,						M_DRAW::UP,		v3(50,2500 - 99,0),	true, v3(111,99,0), 8),





	//ページ２
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10] + 1,  0, M_TYPE::BORDER_INNER,					M_DRAW::UP,		v3(0,150,1),		true, v3(PW / 2,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10] + 1,  0, M_TYPE::BORDER_INNER,					M_DRAW::UP,		v3(465,150,1),		true, v3(155,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10] + 1,  0, M_TYPE::BORDER_INNER,					M_DRAW::UP,		v3(155,800,1),		true, v3(465,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10] + 1,  0, M_TYPE::BORDER_INNER,					M_DRAW::UP,		v3(155,1800,1),		true, v3(PW/2,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10] + 1,  0, M_TYPE::BORDER_INNER,					M_DRAW::UP,		v3(0,2500,1),		true, v3(PW,11,0), 10),

	

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10] + 1, 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,		v3(PW/2,140,1),		true, v3(155,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10] + 1, 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,		v3(0,800,1),		true, v3(155,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10] + 1, 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,		v3(0,1800,1),		true, v3(155,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10] + 1, 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,		v3(465,1800,1),		true, v3(155,11,0), 0, recoveryControl),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10] + 1,0, M_TYPE::HIGH_CONCENTRATION,		M_DRAW::UP,		v3(0,0,0),		true, v3(PW ,2500,0), 3),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 10] + 1,0, M_TYPE::RECOVERY,				M_DRAW::UP,		v3(500,1800 - 64,0),	true, v3(64,64,0), 2),



	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};