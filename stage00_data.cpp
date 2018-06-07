#include "game.h"
#include "map_obj.h"

#include "stage_data.h"

int e_stageHeight[] = {
	(1150 - 76) - (PH - 100),
	(900 - 76) - (PH - 100),
	(900 - 76) - (PH - 100),
	(900 - 76) - (PH - 100),
	(900 - 76) - (PH - 100),
	(900 - 76) - (PH - 100),
};

int e_startPagination[] = {
	61,
	67,
	73,
	79,
	85,
	91,
};

v3 e_initPos[] = {
	{ 80,400,5 },
	{ 80,400,5 },
	{ 80,400,5 },
	{ 80,400,5 },
	{ 80,400,5 },
	{ 80,400,5 },
};

const int STAGE_MAX_NUM = ARRAYSIZE(e_startPagination)/*sizeof(e_startPagination) / sizeof(int)*/;


int START_PAGINATION = e_startPagination[0];

int STAGE_HEIGHT = e_stageHeight[0];

v3 INIT_POS = e_initPos[0];


STAGE_DATA stage00_setData[] = {

	// ページ１
	STAGE_DATA(e_startPagination[0], 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,220,1),		true, v3(470,17,0), 10),
	STAGE_DATA(e_startPagination[0], 0, M_TYPE::RECOVERY_UP,				M_DRAW::UP,		v3(470,220,1),		true, v3(150,22,0), 2, recoveryControl),

	STAGE_DATA(e_startPagination[0], 0, M_TYPE::IVY_THICK,				M_DRAW::LEFT,		v3(PW / 2,0,1),		true, v3(17,220,0), 10),

	STAGE_DATA(e_startPagination[0], 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,420,1),		true, v3(PW,17,0), 10),
	STAGE_DATA(e_startPagination[0], 0, M_TYPE::IVY_THICK,				M_DRAW::LEFT,	v3(PW / 2,420,1),		true, v3(17,260,0), 10),
	STAGE_DATA(e_startPagination[0], 0, M_TYPE::HIGH_CONCENTRATION,		M_DRAW::UP,		v3(0,420,0),		true, v3(PW / 2,260,0), 3),

	STAGE_DATA(e_startPagination[0], 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,680,1),		true, v3(155,17,0), 10),
	STAGE_DATA(e_startPagination[0], 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(PW / 2,680,1),		true, v3(310,17,0), 10),
	STAGE_DATA(e_startPagination[0], 0, M_TYPE::RECOVERY_UP,				M_DRAW::UP,		v3(155,680,1),		true, v3(155,22,0), 2, recoveryControl),

	STAGE_DATA(e_startPagination[0], 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,1150,1),		true, v3(PW,17,0), 10),


	//STAGE_DATA(e_startPagination[0], 0, M_TYPE::RECOVERY_DOWN,			M_DRAW::DOWN,	v3(465,680,1),		true, v3(155,22,0), 3, recoveryControl),
	STAGE_DATA(e_startPagination[0], 0, M_TYPE::KEY,						M_DRAW::UP,		v3(PW / 2,1150 - 30,0),	true, v3(50,30,0), 10),




	STAGE_DATA(e_startPagination[0], 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,1050,1),		true, v3(PW,17,0), 10),


	STAGE_DATA(e_startPagination[0], 0, M_TYPE::DOOR,					M_DRAW::UP,		v3(50,220 - 76,0),	true, v3(51,76,0), LOW_CONCENTRATION),




	//ページ２
	STAGE_DATA(e_startPagination[0]+1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,220,1),		true, v3(PW / 2,17,0), 10),
	STAGE_DATA(e_startPagination[0]+1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(470,220,1),		true, v3(150,17,0), 10),
	STAGE_DATA(e_startPagination[0]+1, 0, M_TYPE::IVY_THICK,				M_DRAW::LEFT,	v3(PW / 2,220,1),		true, v3(17,320,0), 10),
	STAGE_DATA(e_startPagination[0]+1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,540,1),		true, v3(PW,17,0), 10),
	STAGE_DATA(e_startPagination[0]+1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,900,1),		true, v3(PW,17,0), 10),
	STAGE_DATA(e_startPagination[0]+1, 0, M_TYPE::IVY_THICK,				M_DRAW::UP,		v3(0,1150,1),		true, v3(PW,17,0), 10),


	STAGE_DATA(e_startPagination[0]+1, 0, M_TYPE::RECOVERY_DOWN,			M_DRAW::DOWN,	v3(PW / 2,215,1),		true, v3(160,22,0), 2, recoveryControl),
	//STAGE_DATA(e_startPagination[0]+1, 0, M_TYPE::RECOVERY_UP,				M_DRAW::UP,		v3(500,540,1),		true, v3(120,22,0), 3, recoveryControl),

	STAGE_DATA(e_startPagination[0]+1, 0, M_TYPE::HIGH_CONCENTRATION,		M_DRAW::UP,		v3(0,220,0),		true, v3(PW / 2,320,0), 3),

	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};