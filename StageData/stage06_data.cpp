#include "../game.h"
#include "../map_obj.h"

#include "../stage_data.h"


STAGE_DATA stage06_setData[] = {

	// ページ１
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 6], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,300,1),		true, v3(155,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 6], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(PW / 2,300,1),		true, v3(PW / 2,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 6], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(400,500,1),		true, v3(155,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 6], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(250,700,1),		true, v3(155,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 6], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,900,1),		true, v3(PW,11,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 6], 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,		v3(PW / 2,0,1),		true, v3(11,300,0), 10),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 6], 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(155,300 - 8,1),		true, v3(155,11,0), 0, recoveryControl),
	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 6], 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(0,850 - 8,1),		true, v3(155,11,0), 0, recoveryControl),







	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 6], 0, M_TYPE::KEY,					M_DRAW::UP,		v3(20,220 - 58,0),	true, v3(70,58,0), 10),




	//ページ２
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 6] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,150,1),		true, v3(155,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 6] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(155,300,1),		true, v3(465,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 6] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,500,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 6] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,900,1),		true, v3(PW,11,0), 10),



	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 6] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(155,150,1),		true, v3(11,150,0), 10),
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 6] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::LEFT,	v3(PW / 2,300,1),		true, v3(11,200,0), 10),






	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 6] + 1, 0, M_TYPE::PASSABLE_DOWN,			M_DRAW::DOWN,	v3(PW / 2,220 - 8,1),		true, v3(160,11,0), 3, recoveryControl),
	//STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 6] + 1, 0, M_TYPE::PASSABLE_UP,				M_DRAW::UP,		v3(500,540,1),		true, v3(120,11,0), 3, recoveryControl),


	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 6] + 1,0, M_TYPE::DOOR,					M_DRAW::UP,		v3(500,500 - 76,0),	true, v3(70,76,0), LOW_CONCENTRATION),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};