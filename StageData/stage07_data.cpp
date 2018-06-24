#include "../game.h"
#include "../map_obj.h"

#include "../stage_data.h"

STAGE_DATA stage07_setData[] = {

	// ページ１
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 7], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(100,240,1),		true, v3(100,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 7], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(250,850,1),		true, v3(155,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 7], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,1100,1),		true, v3(PW,11,0), 10),






	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 7], 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(0,300 - 8,1),		true, v3(PW,11,0), 0, recoveryControl),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 7],0, M_TYPE::DOOR,					M_DRAW::UP,		v3(90,240 - 111,0),	true, v3(124,111,0), 8),




	//ページ２


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 7] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(PW/2,500,1),		true, v3(155,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 7] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,720,1),		true, v3(PW,11,0), 10),



	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 7] + 1, 0, M_TYPE::KEY,					M_DRAW::UP,		v3(PW/2,500 - 111,0),	true, v3(124,111,0), 10),




	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};