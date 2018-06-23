#include "game.h"
#include "map_obj.h"

#include "stage_data.h"

STAGE_DATA stage_select01_setData[] = {

	// ページ 左

	STAGE_DATA(e_startPagination[1], 0, M_TYPE::STAGE_SELECT01_LEFT,			M_DRAW::UP,		v3(0,0,0),					false, v3(0,0,0), 10),


	// ページ 右
	STAGE_DATA(e_startPagination[1] + 1, 0, M_TYPE::STAGE_SELECT01_RIGHT,		M_DRAW::UP,		v3(0,0,0),					false, v3(0,0,0), 10),

	//STAGE_DATA(e_startPagination[1] + 1, 0, M_TYPE::HIGH_CONCENTRATION,		M_DRAW::UP,		v3(0,0,0),					false, v3(PW,PH,0), 6),

	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};