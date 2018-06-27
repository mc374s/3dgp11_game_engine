#include "../game.h"
#include "../map_obj.h"

#include "../stage_data.h"

STAGE_DATA stage13_setData[] = {

	// ページ１
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,220,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,520,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,720,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,1020,1),		true, v3(PW,11,0), 10),



	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,0,1),		true, v3(11,220,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,520,1),		true, v3(11,200,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::KEY_3_1,					M_DRAW::UP,		v3(510,220 - 133,0),	true, v3(101, 133,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::DOOR_3_1,					M_DRAW::UP,		v3(500,720 - 133,0),	true, v3(101, 133,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::KEY_3_2,					M_DRAW::UP,		v3(100,720 - 133,0),	true, v3(101, 133,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::DOOR_3_2,					M_DRAW::UP,		v3(100,1020 - 133,0),	true, v3(101, 133,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::DESERT_6,				M_DRAW::UP,		v3(230,1100 - 47,0),	false, v3(132,47,0), 10),



	//ページ２
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,370,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(465,730,1),		true, v3(75,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(200,900,1),		true, v3(75,11,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,1020,1),		true, v3(PW,11,0), 10),









	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 12] + 1,0, M_TYPE::DOOR,					M_DRAW::UP,		v3(PW / 2,1039 - 111,0),	true, v3(124,111,0), 8),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};
