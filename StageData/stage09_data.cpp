#include "../game.h"
#include "../map_obj.h"

#include "../stage_data.h"

STAGE_DATA stage09_setData[] = {

	// ページ１
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(155,250,1),		true, v3(465,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,480,1),		true, v3(155,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(PW/2,480,1),		true, v3(PW/2,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,680,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,1050,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(PW/2,1250,1),		true, v3(PW/2,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,1500,1),		true, v3(PW,11,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9],0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(155,250,1),		true, v3(11,230,0), 10),




	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9], 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(0,250 - 8,1),		true, v3(155,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9], 0, M_TYPE::PASSABLE_UP,			M_DRAW::UP,	v3(155,490 - 8,1),		true, v3(155,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9], 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(0,1250 - 8,1),		true, v3(PW/2,11,0), 0, recoveryControl),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9], 0, M_TYPE::KEY,						M_DRAW::UP,		v3(50,480 - 111,0),	true, v3(124,111,0), 10),





	//ページ２
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(120,250,1),		true, v3(35,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(PW/2,250,1),		true, v3(PW/2,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,480,1),		true, v3(465,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,850,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,1400,1),		true, v3(PW,11,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,1500,1),		true, v3(PW,11,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(120,260,1),		true, v3(11,220,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(465,260,1),		true, v3(11,220,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW/2,850,1),		true, v3(11,550,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9] + 1,0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(155,250 - 8,1),		true, v3(155,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9] + 1, 0, M_TYPE::PASSABLE_UP,			M_DRAW::UP,	    v3(0,255 - 8,1),		true, v3(120,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9] + 1, 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(465,485 - 8,1),		true, v3(155,11,0), 0, recoveryControl),



	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9] + 1,0,M_TYPE::DOOR,					M_DRAW::UP,		v3(550,1500 - 111,0),	true, v3(124,111,0), 8),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9] + 1,0, M_TYPE::HIGH_CONCENTRATION,		M_DRAW::UP,		v3(PW/2,850,0),		true, v3(PW/2 ,550,0), 3),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 9] + 1,0, M_TYPE::RECOVERY,				M_DRAW::UP,		v3(500,1400 - 64,0),	true, v3(64,64,0), 2),



	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2] + 1, 0, M_TYPE::KEY,						M_DRAW::UP,		v3(120,900 - 30,0),	true, v3(50,30,0), 10),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};