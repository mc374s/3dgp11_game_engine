#include "game.h"
#include "map_obj.h"

#include "stage_data.h"


STAGE_DATA stage_intro01_setData[] = {

	// ページ 左

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 0], 0, M_TYPE::STAGE_INTRO01_LEFT,			M_DRAW::UP,		v3(0,0,0),					false, v3(0,0,0), 10),


	// ページ 右
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 0] + 1, 0, M_TYPE::STAGE_INTRO01_RIGHT,		M_DRAW::UP,		v3(0,0,0),					false, v3(0,0,0), 10),

	//STAGE_DATA(e_startPagination[0] + 1, 0, M_TYPE::HIGH_CONCENTRATION,		M_DRAW::UP,		v3(0,PH / 2,0),					false, v3(PW,PH / 2,0), 6),

	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};