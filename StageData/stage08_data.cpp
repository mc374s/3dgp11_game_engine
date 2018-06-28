#include "../game.h"
#include "../map_obj.h"

#include "../stage_data.h"

STAGE_DATA stage08_setData[] = {

	// ページ１
	

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(155,250,1),		true, v3(465,11,0), 10),
	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,480,1),		true, v3(155,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,480,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,680,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,1050,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(PW / 2,1250,1),		true, v3(PW / 2,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,1550,1),		true, v3(PW,11,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8],0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(155,250,1),		true, v3(11,230,0), 10),




	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8], 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(0,250 - 8,1),		true, v3(155,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8], 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(0,1250 - 8,1),		true, v3(PW / 2,11,0), 0, recoveryControl),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8], 0, M_TYPE::KEY_3_1,						M_DRAW::UP,		v3(50,480 - 133,0),	true, v3(101, 133,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] , 0, M_TYPE::GRAVE_9,				M_DRAW::UP,		v3(380,250 - 77,0),	false, v3(56,77,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] , 0, M_TYPE::GRAVE_9,				M_DRAW::UP,		v3(440,250 - 77,0),	false, v3(56,77,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] , 0, M_TYPE::GRAVE_9,				M_DRAW::UP,		v3(500,250 - 77,0),	false, v3(56,77,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] , 0, M_TYPE::GRAVE_1,				M_DRAW::UP,		v3(520,480 - 54,0),	false, v3(82,54,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] , 0, M_TYPE::GRAVE_10,				M_DRAW::UP,		v3(20,1050 - 84,0),	false, v3(76,84,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] , 0, M_TYPE::GRAVE_10,				M_DRAW::MIRROR,		v3(100,1050 - 84,0),	false, v3(76,84,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] , 0, M_TYPE::GRAVE_10,				M_DRAW::UP,		v3(180,1050 - 84,0),	false, v3(76,84,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] , 0, M_TYPE::GRAVE_10,				M_DRAW::MIRROR,		v3(260,1050 - 84,0),	false, v3(76,84,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] , 0, M_TYPE::GRAVE_6,				M_DRAW::UP,		v3(220,800,0),	false, v3(66,102,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] , 0, M_TYPE::GRAVE_7,				M_DRAW::UP,		v3(450,800,0),	false, v3(80,121,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] , 0, M_TYPE::GRAVE_11,				M_DRAW::UP,		v3(50,1550 - 153,0),	false, v3(261,153,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] , 0, M_TYPE::GRAVE_6,				M_DRAW::UP,		v3(300,1400,0),	false, v3(66,102,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] , 0, M_TYPE::GRAVE_6,				M_DRAW::MIRROR,		v3(380,1300,0),	false, v3(66,102,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] , 0, M_TYPE::GRAVE_6,				M_DRAW::UP,		v3(460,1370,0),	false, v3(66,102,0), 10),


	//ページ２
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(120,250,1),		true, v3(35,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(PW / 2,250,1),		true, v3(PW / 2,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,480,1),		true, v3(476,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,850,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,1400,1),		true, v3(PW,11,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,1550,1),		true, v3(PW,11,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(120,260,1),		true, v3(11,220,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(465,260,1),		true, v3(11,220,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,850,1),		true, v3(11,550,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1,0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(155,250 - 8,1),		true, v3(155,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1, 0, M_TYPE::PASSABLE_UP,			M_DRAW::UP,	    v3(0,260 - 10,1),		true, v3(120,11,0), 0, recoveryControl),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1, 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(465,480 - 8,1),		true, v3(155,11,0), 0, recoveryControl),



	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1,0,M_TYPE::DOOR_3_1,					M_DRAW::UP,		v3(500,1550 - 133,0),	true, v3(101, 133,0), 8),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1,0, M_TYPE::HIGH_CONCENTRATION,		M_DRAW::UP,		v3(321,861,0),		true, v3(299 ,539,0), 3),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1,0, M_TYPE::RECOVERY,				M_DRAW::UP,		v3(500,1400 - 64,0),	true, v3(71,64,0), 2),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1 , 0, M_TYPE::GRAVE_1,				M_DRAW::UP,		v3(350,480 - 54,0),	false, v3(82,54,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1 , 0, M_TYPE::GRAVE_10,				M_DRAW::MIRROR,		v3(150,480 - 84,0),	false, v3(76,84,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1 , 0, M_TYPE::GRAVE_8,				M_DRAW::MIRROR,		v3(460,50,0),	false, v3(80,146,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1 , 0, M_TYPE::GRAVE_5,				M_DRAW::UP,		v3(350,250 - 95,0),	false, v3(74,95,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1 , 0, M_TYPE::GRAVE_11,				M_DRAW::MIRROR,		v3(340,850 - 153,0),	false, v3(261,153,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1 , 0, M_TYPE::GRAVE_4,				M_DRAW::UP,		v3(320,700,0),	false, v3(50,89,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1 , 0, M_TYPE::GRAVE_4,				M_DRAW::MIRROR,		v3(150,550,0),	false, v3(50,89,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1 , 0, M_TYPE::GRAVE_3,				M_DRAW::UP,		v3(200,650,0),	false, v3(122,100,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1 , 0, M_TYPE::GRAVE_2,				M_DRAW::UP,		v3(20,1400 - 74,0),	false, v3(68,74,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1 , 0, M_TYPE::GRAVE_2,				M_DRAW::UP,		v3(88,1400 - 74,0),	false, v3(68,74,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1 , 0, M_TYPE::GRAVE_2,				M_DRAW::UP,		v3(156,1400 - 74,0),	false, v3(68,74,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1 , 0, M_TYPE::GRAVE_2,				M_DRAW::UP,		v3(224,1400 - 74,0),	false, v3(68,74,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 3 + 8] + 1 , 0, M_TYPE::GRAVE_8,				M_DRAW::UP,		v3(150,1100,0),	false, v3(80,146,0), 10),

	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2] + 1, 0, M_TYPE::KEY_1_1,						M_DRAW::UP,		v3(120,900 - 30,0),	true, v3(50,30,0), 10),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};