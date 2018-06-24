#include "../game.h"
#include "../map_obj.h"

#include "../stage_data.h"

STAGE_DATA stage13_setData[] = {

	// ページ１
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,PH / 2,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::KEY_1_1,						M_DRAW::UP,		v3(PW / 2,PH / 2 - 99,0),	true, v3(111,99,0), 10),


	//ページ２
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0, M_TYPE::BORDER_INNER,			M_DRAW::UP,		v3(0,PH / 2,1),		true, v3(PW ,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0, M_TYPE::RECOVERY,				M_DRAW::UP,		v3(100,PH / 2 - 64,0),	true, v3(71,64,0), 2),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0, M_TYPE::DOOR_1_1,					M_DRAW::UP,		v3(450,PH / 2 - 99,0),	true, v3(111,99,0), 8),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};
