﻿#include "../game.h"
#include "../map_obj.h"

#include "../stage_data.h"


STAGE_DATA stage18_setData[] = {

	// ページ１
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,220,1),		true, v3(155,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18], 0, M_TYPE::PASSABLE_UP,				M_DRAW::UP,		v3(155,220,1),		true, v3(155,11,0), 0),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(465,220,1),		true, v3(155,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,440,1),		true, v3(PW / 2,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(465,440,1),		true, v3(155,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,660,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(155,850,1),		true, v3(PW / 2,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,1039,1),		true, v3(PW,11,0), 10),



	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18], 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,0,1),		true, v3(11,220,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18], 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(155,220,1),		true, v3(11,220,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18], 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(465,220,1),		true, v3(11,220,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18], 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,660,1),		true, v3(11,190,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18], 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,850,1),		true, v3(11,189,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18], 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(PW / 2,220 - 8,1),		true, v3(155,11,0), 0),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18], 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(PW / 2,440 - 8,1),		true, v3(155,11,0), 0),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18], 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(0,850 - 8,1),		true, v3(155,11,0), 0),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18], 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(465,850 - 8,1),		true, v3(155,11,0), 0),





	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18], 0, M_TYPE::HIGH_CONCENTRATION,		M_DRAW::UP,		v3(470,230,0),		true, v3(145,210,0), 3),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18], 0, M_TYPE::HIGH_CONCENTRATION,		M_DRAW::UP,		v3(PW / 2,850,0),		true, v3(PW / 2,189,0), 3),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18], 0, M_TYPE::KEY_1_1,					M_DRAW::UP,		v3(20,200 - 99,0),	true, v3(111,99,0), 10),




	//ページ２
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,325,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,545,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,850,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,1039,1),		true, v3(PW,11,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,545,1),		true, v3(11,305,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(155,850,1),		true, v3(11,189,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(465,850,1),		true, v3(11,189,0), 10),




	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18] + 1, 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(PW / 2,220 - 8,1),		true, v3(160,11,0), 3),
	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18] + 1, 0, M_TYPE::PASSABLE_UP,				M_DRAW::UP,		v3(500,540,1),		true, v3(120,11,0), 3),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18] + 1, 0, M_TYPE::HIGH_CONCENTRATION,		M_DRAW::UP,		v3(0,325,0),		true, v3(PW,220,0), 3),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 18] + 1,0, M_TYPE::DOOR_1_1,					M_DRAW::UP,		v3(PW / 2,1039 - 99,0),	true, v3(111,99,0), 8),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};