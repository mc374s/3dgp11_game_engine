#include "../game.h"
#include "../map_obj.h"

#include "../stage_data.h"

STAGE_DATA stage13_setData[] = {

	// ページ１
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(150,200,1),		true, v3(470,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(150,400,1),		true, v3(200,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(150,600,1),		true, v3(200,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(150,800,1),		true, v3(200,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,1100,1),		true, v3(PW,11,0), 10),


	//足場
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(465,500,1),		true, v3(75,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(465,700,1),		true, v3(75,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(465,900,1),		true, v3(75,11,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(150,200,1),		true, v3(11,600,0), 10),

	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13], 0, M_TYPE::KEY,						M_DRAW::UP,		v3(PW / 2,PH / 2 - 111,0),	true, v3(124,111,0), 10),


	//ページ２
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0, M_TYPE::BORDER_INNER,			M_DRAW::UP,		v3(0,200,1),		true, v3(470 ,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0, M_TYPE::BORDER_INNER,			M_DRAW::UP,		v3(270,400,1),		true, v3(200 ,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0, M_TYPE::BORDER_INNER,			M_DRAW::UP,		v3(270,600,1),		true, v3(200 ,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0, M_TYPE::BORDER_INNER,			M_DRAW::UP,		v3(270,800,1),		true, v3(211 ,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0, M_TYPE::BORDER_INNER,			M_DRAW::UP,		v3(0,1100,1),		true, v3(PW ,11,0), 10),

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(470,200,1),		true, v3(11,600,0), 10),


	//足場
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0 , M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(75,400,1),		true, v3(75,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0 , M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(75,600,1),		true, v3(75,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0 , M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(75,800,1),		true, v3(75,11,0), 10),



	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0, M_TYPE::RECOVERY,				M_DRAW::UP,		v3(100,PH / 2 - 64,0),	true, v3(64,64,0), 2),
	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 5 + 13] + 1, 0, M_TYPE::DOOR,					M_DRAW::UP,		v3(450,PH / 2 - 111,0),	true, v3(124,111,0), 8),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};
