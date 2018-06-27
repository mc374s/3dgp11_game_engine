#include "../game.h"
#include "../map_obj.h"

#include "../stage_data.h"

STAGE_DATA stage09_setData[] = {

	// ページ１
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,150,1),		true, v3(120,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(200,300,1),		true, v3(120,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(400,350,1),		true, v3(120,11,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,450,1),		true, v3(120,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(200,600,1),		true, v3(120,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,750,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,1200,1),		true, v3(PW,11,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9],0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW/2,0,1),		true, v3(11,750,0), 10),



	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9], 0, M_TYPE::KEY_1_1,						M_DRAW::UP,		v3(400,350 - 99,0),	true, v3(111,99,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9],0,M_TYPE::DOOR_1_1,					M_DRAW::UP,		v3(30,1200 - 99,0),	true, v3(111,99,0), 8),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] , 0, M_TYPE::SNOW_6,				M_DRAW::UP,		v3(30,230,0),	false, v3(45,52,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] , 0, M_TYPE::SNOW_7,				M_DRAW::UP,		v3(180,380,0),	false, v3(39,38,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] , 0, M_TYPE::SNOW_7,				M_DRAW::UP,		v3(100,500,0),	false, v3(39,38,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] , 0, M_TYPE::SNOW_1,				M_DRAW::UP,		v3(325,750 - 82,0),	false, v3(87,82,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] , 0, M_TYPE::SNOW_1,				M_DRAW::UP,		v3(425,750 - 82,0),	false, v3(87,82,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] , 0, M_TYPE::SNOW_1,				M_DRAW::UP,		v3(525,750 - 82,0),	false, v3(87,82,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] , 0, M_TYPE::SNOW_6,				M_DRAW::UP,		v3(400,520,0),	false, v3(45,52,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] , 0, M_TYPE::SNOW_6,				M_DRAW::UP,		v3(500,560,0),	false, v3(45,52,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] , 0, M_TYPE::SNOW_7,				M_DRAW::UP,		v3(340,600,0),	false, v3(39,38,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] , 0, M_TYPE::SNOW_6,				M_DRAW::UP,		v3(350,850,0),	false, v3(45,52,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] , 0, M_TYPE::SNOW_7,				M_DRAW::UP,		v3(500,890,0),	false, v3(39,38,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] , 0, M_TYPE::SNOW_7,				M_DRAW::UP,		v3(100,920,0),	false, v3(39,38,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] , 0, M_TYPE::SNOW_7,				M_DRAW::UP,		v3(240,950,0),	false, v3(39,38,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] , 0, M_TYPE::SNOW_6,				M_DRAW::UP,		v3(390,1000,0),	false, v3(45,52,0), 10),



	//ページ２
	
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,440,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(PW/2,620,1),		true, v3(155,11,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,950,1),		true, v3(PW,11,0), 10),




	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] + 1,0,M_TYPE::DOOR_1_1,					M_DRAW::UP,		v3(550,1500 - 99,0),	true, v3(111,99,0), 8),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] + 1, 0, M_TYPE::DOOR_1_1,				M_DRAW::UP,		v3(100,1500 - 99,0),	true, v3(111, 99, 0), 10),
	
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] + 1, 0, M_TYPE::SNOW_3,				M_DRAW::UP,		v3(450,440 - 71,0),	false, v3(146,71,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] + 1, 0, M_TYPE::SNOW_6,				M_DRAW::UP,		v3(100,150,0),	false, v3(45,52,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] + 1, 0, M_TYPE::SNOW_7,				M_DRAW::UP,		v3(200,250,0),	false, v3(39,38,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] + 1, 0, M_TYPE::SNOW_6,				M_DRAW::UP,		v3(300,220,0),	false, v3(45,52,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] + 1, 0, M_TYPE::SNOW_7,				M_DRAW::UP,		v3(400,300,0),	false, v3(39,38,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] + 1, 0, M_TYPE::SNOW_7,				M_DRAW::UP,		v3(450,100,0),	false, v3(39,38,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] + 1, 0, M_TYPE::SNOW_2,				M_DRAW::MIRROR,		v3(100,950 - 103,0),	false, v3(187,103,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] + 1, 0, M_TYPE::SNOW_6,				M_DRAW::UP,		v3(100,760,0),	false, v3(45,52,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] + 1, 0, M_TYPE::SNOW_7,				M_DRAW::UP,		v3(200,650,0),	false, v3(39,38,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] + 1, 0, M_TYPE::SNOW_7,				M_DRAW::UP,		v3(400,860,0),	false, v3(39,38,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] + 1, 0, M_TYPE::SNOW_6,				M_DRAW::UP,		v3(280,720,0),	false, v3(45,52,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] + 1, 0, M_TYPE::SNOW_7,				M_DRAW::UP,		v3(510,820,0),	false, v3(39,38,0), 10),

	 

	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2] + 1, 0, M_TYPE::KEY_1_1,						M_DRAW::UP,		v3(120,900 - 30,0),	true, v3(50,30,0), 10),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};