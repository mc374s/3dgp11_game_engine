#include "../game.h"
#include "../map_obj.h"

#include "../stage_data.h"

STAGE_DATA stage14_setData[] = {

	// ページ１
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,300,1),		true, v3(PW,11,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,650,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14], 0, M_TYPE::DOOR,					M_DRAW::UP,		v3(50,300 - 111,0),	true, v3(124,111,0), 8),


	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1], 0, M_TYPE::PASSABLE_UP,				M_DRAW::UP,		v3(155,680,1),		true, v3(155,22,0), 3, recoveryControl),
	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 1], 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(465,680,1),		true, v3(155,22,0), 3, recoveryControl),







	//ページ２
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,500,1),		true, v3(PW,11,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 14] + 1, 0, M_TYPE::KEY,						M_DRAW::UP,		v3(PW / 2,500 - 111,0),	true, v3(124,111,0), 10),

	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};