#include "game.h"
#include "map_obj.h"

#include "stage_data.h"


STAGE_DATA stage_select00_setData[] = {

	// ページ 左

	STAGE_DATA(e_startPagination[0], 0, M_TYPE::STAGE_SELECT00_LEFT,			M_DRAW::UP,		v3(0,0,0),					false, v3(0,0,0), 10),


	// ページ 右
	STAGE_DATA(e_startPagination[0] + 1, 0, M_TYPE::STAGE_SELECT00_RIGHT,		M_DRAW::UP,		v3(0,0,0),					false, v3(0,0,0), 10),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};