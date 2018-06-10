﻿#include "game.h"
#include "map_obj.h"

#include "stage_data.h"

STAGE_DATA stage04_setData[] = {

	// ページ１
	STAGE_DATA(e_startPagination[4], 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,220,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[4], 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,460,1),		true, v3(155,11,0), 10),
	STAGE_DATA(e_startPagination[4], 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(310,460,1),		true, v3(310,11,0), 10),
	STAGE_DATA(e_startPagination[4], 0, M_TYPE::IVY_THICK,				M_DRAW::LEFT,	v3(PW / 2,231,1),		true, v3(11,229,0), 10),
	STAGE_DATA(e_startPagination[4], 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,680,1),		true, v3(PW,11,0), 10),




	STAGE_DATA(e_startPagination[4], 0, M_TYPE::RECOVERY_UP,			M_DRAW::UP,		v3(155,460,1),		true, v3(155,11,0), 3, recoveryControl),

	STAGE_DATA(e_startPagination[4], 0, M_TYPE::KEY,						M_DRAW::UP,		v3(400,440 - 30,0),	true, v3(50,30,0), 10),







	//ページ２
	STAGE_DATA(e_startPagination[4] + 1,  0, M_TYPE::IVY_THICK,					M_DRAW::UP,		v3(0,680,1),		true, v3(PW,11,0), 10),


	STAGE_DATA(e_startPagination[4] + 1, 0, M_TYPE::RECOVERY_DOWN,			M_DRAW::DOWN,		v3(0,220-8,1),		true, v3(PW,11,0), 3, recoveryControl),

	STAGE_DATA(e_startPagination[4] + 1, 0, M_TYPE::IVY_THICK,				M_DRAW::LEFT,	v3(PW / 2,231,1),		true, v3(11,449,0), 10),


	STAGE_DATA(e_startPagination[4] + 1,	 0,	M_TYPE::DOOR,						M_DRAW::UP,		v3(550,680 - 76,0),	true, v3(51,76,0), LOW_CONCENTRATION),


	// END
	STAGE_DATA(6 - 1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};