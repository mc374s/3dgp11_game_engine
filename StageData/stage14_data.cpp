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
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,1100,1),		true, v3(11,200,0), 10),



	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::PASSABLE_UP,				M_DRAW::UP,		v3(120,200,1),		true, v3(120,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::PASSABLE_DOWN,				M_DRAW::DOWN,		v3(360,195,1),		true, v3(120,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::PASSABLE_DOWN,				M_DRAW::DOWN,		v3(0,1100,1),		true, v3(PW,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::PASSABLE_DOWN,				M_DRAW::DOWN,		v3(0,1295,1),		true, v3(155,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::PASSABLE_DOWN,				M_DRAW::DOWN,		v3(155,1395,1),		true, v3(465,11,0), 0, recoveryControl),




	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::DOOR_3_1,					M_DRAW::UP,		v3(500,1300 - 133,0),	true, v3(101, 133,0), 10),




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


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::PASSABLE_UP,				M_DRAW::UP,		v3(0,200,1),		true, v3(155,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::PASSABLE_DOWN,				M_DRAW::DOWN,		v3(465,195,1),		true, v3(155,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::PASSABLE_DOWN,				M_DRAW::DOWN,		v3(0,595,1),		true, v3(PW/2,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::PASSABLE_UP,				M_DRAW::UP,		v3(0,1100,1),		true, v3(155,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::PASSABLE_UP,				M_DRAW::UP,		v3(0,1300,1),		true, v3(PW,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::PASSABLE_DOWN,				M_DRAW::DOWN,		v3(80,1395,1),		true, v3(80,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::PASSABLE_DOWN,				M_DRAW::DOWN,		v3(240,1395,1),		true, v3(80,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::PASSABLE_DOWN,				M_DRAW::DOWN,		v3(400,1395,1),		true, v3(80,11,0), 0, recoveryControl),




	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::KEY_5_1,					M_DRAW::UP,		v3(0,1480 - 133,0),	true, v3(101, 133,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::KEY_3_1,					M_DRAW::UP,		v3(500,800 - 133,0),	true, v3(101, 133,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::DOOR_5_1,					M_DRAW::UP,		v3(500,600 - 133,0),	true, v3(101, 133,0), 10),


	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 12] + 1,0, M_TYPE::DOOR,					M_DRAW::UP,		v3(PW / 2,1039 - 111,0),	true, v3(124,111,0), 8),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};