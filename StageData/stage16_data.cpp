#include "../game.h"
#include "../map_obj.h"

#include "../stage_data.h"

STAGE_DATA stage16_setData[] = {

	// ページ１
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 16], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,220,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 16], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,460,1),		true, v3(155,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 16], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(310,460,1),		true, v3(310,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 16], 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,231,1),		true, v3(11,229,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 16], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,680,1),		true, v3(PW,11,0), 10),




	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 16], 0, M_TYPE::PASSABLE_UP,			M_DRAW::UP,		v3(155,460,1),		true, v3(155,11,0), 0),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 16], 0, M_TYPE::KEY_1_1,						M_DRAW::UP,		v3(400,440 - 99,0),	true, v3(111,99,0), 10),







	//ページ２
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 16] + 1,  0, M_TYPE::BORDER_INNER,					M_DRAW::UP,		v3(0,680,1),		true, v3(PW,11,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 16] + 1, 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,		v3(0,220 - 8,1),		true, v3(PW,11,0), 0),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 16] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,231,1),		true, v3(11,449,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 16] + 1,	 0,	M_TYPE::DOOR_1_1,						M_DRAW::UP,		v3(530,680 - 99,0),	true, v3(111,99,0), 8),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};