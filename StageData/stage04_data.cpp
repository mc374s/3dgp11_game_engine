#include "../game.h"
#include "../map_obj.h"

#include "../stage_data.h"

STAGE_DATA stage04_setData[] = {

	// ページ１
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 4], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,220,1),		true, v3(470,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 4], 0, M_TYPE::PASSABLE_UP,				M_DRAW::UP,		v3(470,220,1),		true, v3(150,11,0), 0, recoveryControl),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 4], 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,		v3(PW / 2,0,1),		true, v3(11,220,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 4], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,420,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 4], 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,420,1),		true, v3(11,260,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 4], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,680,1),		true, v3(155,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 4], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(PW / 2,680,1),		true, v3(310,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 4], 0, M_TYPE::PASSABLE_UP,				M_DRAW::UP,		v3(155,680,1),		true, v3(155,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 4], 0, M_TYPE::RECOVERY,				M_DRAW::UP,		v3(50,680 - 64,0),	true, v3(64,64,0), 2),

	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5], 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(465,680-8,1),		true, v3(155,11,0), 0, recoveryControl),



	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 4], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,900,1),		true, v3(PW,11,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 4], 0, M_TYPE::DOOR_1_1,					M_DRAW::UP,		v3(50,220 - 99,0),	true, v3(111,99,0), 8),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 4], 0, M_TYPE::BIRD_6,				M_DRAW::UP,		v3(390,680 - 99,0),	false, v3(182,111,0), 10),


	//ページ２
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 4] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,220,1),		true, v3(PW / 2,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 4] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(470,220,1),		true, v3(150,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 4] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,231,1),		true, v3(11,309,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 4] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,540,1),		true, v3(500,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 4] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,900,1),		true, v3(PW,11,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 4] + 1, 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(PW / 2,220 - 8,1),		true, v3(160,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 4] + 1, 0, M_TYPE::PASSABLE_UP,				M_DRAW::UP,		v3(500,540,1),		true, v3(120,11,0), 0, recoveryControl),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 4] + 1, 0, M_TYPE::HIGH_CONCENTRATION,		M_DRAW::UP,		v3(0,220,0),		true, v3(PW / 2,320,0), 3),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 4] + 1, 0, M_TYPE::KEY_1_1,						M_DRAW::UP,		v3(120,900 - 99,0),	true, v3(111,99,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 4] + 1, 0, M_TYPE::BIRD_2,				M_DRAW::UP,		v3(70,220 - 137,0),	false, v3(138,137,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 4] + 1, 0, M_TYPE::BIRD_7,				M_DRAW::UP,		v3(350,540 - 165,0),	false, v3(158,165,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 4] + 1, 0, M_TYPE::BIRD_5,				M_DRAW::UP,		v3(400,900 - 85,0),	false, v3(57,85,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2 + 4] + 1, 0, M_TYPE::BIRD_4,				M_DRAW::UP,		v3(457,900 - 85,0),	false, v3(58,85,0), 10),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};