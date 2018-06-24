#include "../game.h"
#include "../map_obj.h"

#include "../stage_data.h"


STAGE_DATA stage06_setData[] = {

	// ページ１
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,220,1),		true, v3(155,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6], 0, M_TYPE::PASSABLE_UP,				M_DRAW::UP,		v3(155,220,1),		true, v3(155,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(465,220,1),		true, v3(155,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,440,1),		true, v3(PW / 2,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(465,440,1),		true, v3(155,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,660,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,850,1),		true, v3(465,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,1039,1),		true, v3(PW,11,0), 10),



	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6], 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,0,1),		true, v3(11,220,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6], 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(155,220,1),		true, v3(11,220,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6], 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(465,220,1),		true, v3(11,220,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6], 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,660,1),		true, v3(11,190,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6], 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,850,1),		true, v3(11,189,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6], 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(PW / 2,220 - 8,1),		true, v3(155,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6], 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(PW / 2,440 - 8,1),		true, v3(155,11,0), 0, recoveryControl),
	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6], 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(0,850 - 8,1),		true, v3(155,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6], 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(465,850 - 8,1),		true, v3(155,11,0), 0, recoveryControl),



	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6], 0, M_TYPE::HIGH_CONCENTRATION,		M_DRAW::UP,		v3(470,230,0),		true, v3(145,210,0), 3),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6], 0, M_TYPE::HIGH_CONCENTRATION,		M_DRAW::UP,		v3(PW / 2,850,0),		true, v3(PW / 2,189,0), 3),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6], 0, M_TYPE::KEY_3_1,					M_DRAW::UP,		v3(20,180 - 99,0),	true, v3(101, 133,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6] , 0, M_TYPE::GRAVE_10,				M_DRAW::MIRROR,		v3(250,440 - 84,0),	false, v3(76,84,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6] , 0, M_TYPE::GRAVE_11,				M_DRAW::UP,		v3(80,660 - 153,0),	false, v3(261,153,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6] , 0, M_TYPE::GRAVE_3,				M_DRAW::UP,		v3(280,600 - 100,0),	false, v3(122,100,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6] , 0, M_TYPE::GRAVE_9,				M_DRAW::UP,		v3(350,850 - 77,0),	false, v3(56,77,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6] , 0, M_TYPE::GRAVE_6,				M_DRAW::UP,		v3(120,1010 - 102,0),	false, v3(66,102,0), 10),



	//ページ２
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,325,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,545,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,850,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,1039,1),		true, v3(PW,11,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,545,1),		true, v3(11,305,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(155,850,1),		true, v3(11,189,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(465,850,1),		true, v3(11,189,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6] + 1, 0, M_TYPE::RECOVERY,				    M_DRAW::UP,		v3(550,850 - 64,0),	true, v3(71,64,0), 2),





	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6] + 1, 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(PW / 2,220 - 8,1),		true, v3(160,11,0), 3, recoveryControl),
	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6] + 1, 0, M_TYPE::PASSABLE_UP,				M_DRAW::UP,		v3(500,540,1),		true, v3(120,11,0), 3, recoveryControl),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6] + 1, 0, M_TYPE::HIGH_CONCENTRATION,		M_DRAW::UP,		v3(0,325,0),		true, v3(PW,220,0), 3),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6] + 1,0, M_TYPE::DOOR_3_1,					M_DRAW::UP,		v3(PW / 2,1039 - 99,0),	true, v3(101, 133,0), 8),
	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6] + 1 , 0, M_TYPE::GRAVE_3,				M_DRAW::UP,		v3(100,250 - 100,0),	false, v3(122,100,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6] + 1 , 0, M_TYPE::GRAVE_7,				M_DRAW::MIRROR,		v3(160,230 - 121,0),	false, v3(80,121,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6] + 1 , 0, M_TYPE::GRAVE_10,				M_DRAW::UP,		v3(250,325 - 84,0),	false, v3(76,84,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6] + 1 , 0, M_TYPE::GRAVE_5,				M_DRAW::UP,		v3(400,325 - 95,0),	false, v3(74,95,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6] + 1 , 0, M_TYPE::GRAVE_2,				M_DRAW::UP,		v3(170,850 - 74,0),	false, v3(68,74,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6] + 1 , 0, M_TYPE::GRAVE_2,				M_DRAW::UP,		v3(238,850 - 74,0),	false, v3(68,74,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6] + 1 , 0, M_TYPE::GRAVE_1,				M_DRAW::UP,		v3(80,850 - 54,0),	false, v3(82,54,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 6] + 1 , 0, M_TYPE::GRAVE_9,				M_DRAW::UP,		v3(520,1039 - 77,0),	false, v3(56,77,0), 10),

	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};
