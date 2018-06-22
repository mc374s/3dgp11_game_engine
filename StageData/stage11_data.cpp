#include "../game.h"
#include "../map_obj.h"

#include "../stage_data.h"

STAGE_DATA stage11_setData[] = {

	// ページ１
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 11], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,220,1),		true, v3(470,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 11], 0, M_TYPE::PASSABLE_UP,				M_DRAW::UP,		v3(470,220,1),		true, v3(150,11,0), 2, recoveryControl),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 11], 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,		v3(PW / 2,0,1),		true, v3(11,220,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 11], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,420,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 11], 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,420,1),		true, v3(11,260,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 11], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,680,1),		true, v3(155,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 11], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(PW / 2,680,1),		true, v3(310,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 11], 0, M_TYPE::PASSABLE_UP,				M_DRAW::UP,		v3(155,680,1),		true, v3(155,11,0), 2, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 11], 0, M_TYPE::RECOVERY,				M_DRAW::UP,		v3(50,680 - 64,0),	true, v3(64,64,0), 2),

	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5], 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(465,680-8,1),		true, v3(155,11,0), 0, recoveryControl),



	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 11], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,900,1),		true, v3(PW,11,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 11], 0, M_TYPE::DOOR,					M_DRAW::UP,		v3(50,220 - 111,0),	true, v3(124,111,0), 8),


	//ページ２
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 11] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,220,1),		true, v3(PW / 2,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 11] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(470,220,1),		true, v3(150,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 11] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,220,1),		true, v3(11,320,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 11] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,540,1),		true, v3(500,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 11] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,900,1),		true, v3(PW,11,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 11] + 1, 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(PW / 2,220 - 8,1),		true, v3(160,11,0), 2, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 11] + 1, 0, M_TYPE::PASSABLE_UP,				M_DRAW::UP,		v3(500,540,1),		true, v3(120,11,0), 2, recoveryControl),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 11] + 1, 0, M_TYPE::HIGH_CONCENTRATION,		M_DRAW::UP,		v3(0,220,0),		true, v3(PW / 2,320,0), 3),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 11] + 1, 0, M_TYPE::KEY,						M_DRAW::UP,		v3(120,900 - 111,0),	true, v3(124,111,0), 10),

	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};