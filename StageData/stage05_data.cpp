#include "../game.h"
#include "../map_obj.h"

#include "../stage_data.h"

STAGE_DATA stage05_setData[] = {

	// ページ１
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 5], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,300,1),		true, v3(155,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 5], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(PW / 2,300,1),		true, v3(PW / 2,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 5], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(400,500,1),		true, v3(155,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 5], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(250,700,1),		true, v3(155,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 5], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,900,1),		true, v3(PW,11,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 5], 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,		v3(PW / 2,0,1),		true, v3(11,300,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 5], 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(155,300 - 8,1),		true, v3(155,11,0), 0, recoveryControl),
	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 6], 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(0,850 - 8,1),		true, v3(155,11,0), 0, recoveryControl),



	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 5], 0, M_TYPE::KEY_2_1,					M_DRAW::UP,		v3(20,220 - 99,0),	true, v3(117, 131,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 5] , 0, M_TYPE::BIRD_7,				M_DRAW::UP,		v3(340,300 - 165,0),	false, v3(158,165,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 5] , 0, M_TYPE::BIRD_8,				M_DRAW::MIRROR,		v3(200,900 - 148,0),	false, v3(192,148,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 5] , 0, M_TYPE::BIRD_2,				M_DRAW::UP,		v3(50,900 - 137,0),	false, v3(138,137,0), 10),




	//ページ２
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 5] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,150,1),		true, v3(155,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 5] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(155,300,1),		true, v3(465,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 5] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,500,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 5] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,900,1),		true, v3(PW,11,0), 10),



	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 5] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(155,150,1),		true, v3(11,150,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 5] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,300,1),		true, v3(11,200,0), 10),






	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 6] + 1, 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(PW / 2,220 - 8,1),		true, v3(160,11,0), 3, recoveryControl),
	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 6] + 1, 0, M_TYPE::PASSABLE_UP,				M_DRAW::UP,		v3(500,540,1),		true, v3(120,11,0), 3, recoveryControl),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 5] + 1,0, M_TYPE::DOOR_2_1,					M_DRAW::UP,		v3(480,470 - 99,0),	true, v3(117, 131,0), 8),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 5] + 1, 0, M_TYPE::BIRD_3,				M_DRAW::MIRROR,		v3(120,500 - 91,0),	false, v3(190,91,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 5] + 1, 0, M_TYPE::BIRD_5,				M_DRAW::UP,		v3(165,900 - 85,0),	false, v3(57,85,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 5] + 1, 0, M_TYPE::BIRD_1,				M_DRAW::UP,		v3(225,900 - 146,0),	false, v3(182,146,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 5] + 1, 0, M_TYPE::BIRD_4,				M_DRAW::UP,		v3(410,900 - 85,0),	false, v3(58,85,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 5] + 1, 0, M_TYPE::BIRD_8,				M_DRAW::MIRROR,		v3(220,300 - 148,0),	false, v3(192,148,0), 10),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};