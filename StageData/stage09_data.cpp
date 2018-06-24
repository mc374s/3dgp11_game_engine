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

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9],0,M_TYPE::DOOR_1_1,					M_DRAW::UP,		v3(30,1200 - 111,0),	true, v3(111,99,0), 8),




	//ページ２
	
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,440,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(PW/2,620,1),		true, v3(155,11,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,950,1),		true, v3(PW,11,0), 10),




	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] + 1,0,M_TYPE::DOOR_1_1,					M_DRAW::UP,		v3(550,1500 - 99,0),	true, v3(111,99,0), 8),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 4 + 9] + 1, 0, M_TYPE::DOOR_1_1,				M_DRAW::UP,		v3(100,1500 - 99,0),	true, v3(111, 99, 0), 10),
	





	 

	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 2] + 1, 0, M_TYPE::KEY_1_1,						M_DRAW::UP,		v3(120,900 - 30,0),	true, v3(50,30,0), 10),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};