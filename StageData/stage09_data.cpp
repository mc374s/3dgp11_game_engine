#include "../game.h"
#include "../map_obj.h"

#include "../stage_data.h"

STAGE_DATA stage09_setData[] = {

	// ページ１
	STAGE_DATA(e_startPagination[9], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,250,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[9], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,560,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[9], 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,840,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[9], 0 , M_TYPE::HIGH_CONCENTRATION,		M_DRAW::UP,		v3(0,260,0),		true, v3(PW ,310,0), 3),

	STAGE_DATA(e_startPagination[9], 0, M_TYPE::KEY,						M_DRAW::UP,		v3(PW / 2,560 - 58,0),	true, v3(70,58,0), 10),
	STAGE_DATA(e_startPagination[9],0  ,M_TYPE::DOOR,					M_DRAW::UP,		v3(60,840 - 76,0),	true, v3(70,76,0), LOW_CONCENTRATION),





	//ページ２
	STAGE_DATA(e_startPagination[9] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,410,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[9] + 1, 0, M_TYPE::BORDER_INNER,				M_DRAW::UP,		v3(0,840,1),		true, v3(PW,11,0), 10),
	STAGE_DATA(e_startPagination[9] + 1,0, M_TYPE::HIGH_CONCENTRATION,		M_DRAW::UP,		v3(0,420,0),		true, v3(PW ,430,0), 3),



	//STAGE_DATA(e_startPagination[2] + 1, 0, M_TYPE::KEY,						M_DRAW::UP,		v3(120,900 - 30,0),	true, v3(50,30,0), 10),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};