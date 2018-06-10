#include "game.h"
#include "map_obj.h"

#include "stage_data.h"

STAGE_DATA stage02_setData[] = {

	// ページ１
	STAGE_DATA(e_startPagination[2], 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,300,1),		true, v3(PW,11,0), 10),

	STAGE_DATA(e_startPagination[2], 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,650,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[2], 0, M_TYPE::DOOR,					M_DRAW::UP,		v3(50,300 - 76,0),	true, v3(70,76,0), LOW_CONCENTRATION),


	//STAGE_DATA(e_startPagination[1], 0, M_TYPE::RECOVERY_UP,				M_DRAW::UP,		v3(155,680,1),		true, v3(155,22,0), 3, recoveryControl),
	//STAGE_DATA(e_startPagination[1], 0, M_TYPE::RECOVERY_DOWN,			M_DRAW::DOWN,	v3(465,680,1),		true, v3(155,22,0), 3, recoveryControl),







	//ページ２
	STAGE_DATA(e_startPagination[2] + 1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,500,1),		true, v3(PW,11,0), 10),

	STAGE_DATA(e_startPagination[2] + 1, 0, M_TYPE::KEY,						M_DRAW::UP,		v3(PW / 2,500 - 58,0),	true, v3(70,58,0), 10),

	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};