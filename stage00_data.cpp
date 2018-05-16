#include "game.h"
#include "map_obj.h"

#include "stage_data.h"

STAGE_DATA stage00_setData[] = {
	// 本の枠
	STAGE_DATA(0, MAPOBJ_IVY_THICK, DRAW_UP, true, v3(0,0,0),true, v3(PW,22,0), 10),
	STAGE_DATA(0, MAPOBJ_IVY_THICK, DRAW_DOWN, true, v3(0,PH - 22,0),true, v3(PW,22,0), 10),
	STAGE_DATA(0, MAPOBJ_IVY_THICK, DRAW_LEFT, true, v3(0,0,0),true, v3(22,PH,0), 10),
	//STAGE_DATA(0, MAPOBJ_IVY_THICK, DRAW_UP, true, v3(300,500,0),true, v3(600,22,0), 10),
	STAGE_DATA(0, MAPOBJ_IVY_THICK, DRAW_UP, false, v3(0,0,0),true, v3(PW,22,0), 10),
	STAGE_DATA(0, MAPOBJ_IVY_THICK, DRAW_DOWN, false, v3(0,PH - 22,0),true, v3(PW,22,0), 10),
	//STAGE_DATA(0, MAPOBJ_IVY_THICK, DRAW_UP, true, v3(300,500,0),true, v3(600,22,0), 10),
	STAGE_DATA(0, MAPOBJ_IVY_THICK, DRAW_RIGHT, false, v3(PW-22,0,0),true, v3(22,PH,0), 10),
	// 濃度の高いマスク
	STAGE_DATA(0, MAPOBJ_HIGH_CONCENTRATION, DRAW_UP, true, v3(200,200,1),false, v3(200,100,0), 5),

	STAGE_DATA(0, MAPOBJ_TREE_A, DRAW_UP, true, v3(50,100,0),false, v3(0,0,0), 10),
	STAGE_DATA(0, MAPOBJ_TREE_A, DRAW_UP, false, v3(100,100,0),false, v3(0,0,0), 10),
	STAGE_DATA(0, MAPOBJ_HOUSE, DRAW_UP, true, v3(200,100,0),false, v3(0,0,0), 10),
	STAGE_DATA(0, MAPOBJ_HOUSE, DRAW_UP, false, v3(200,100,0),false, v3(0,0,0), 10),
	STAGE_DATA(0, MAPOBJ_IVY_BIG, DRAW_UP, false, v3(200,400,0),true, v3(79,47,0), 10),
	STAGE_DATA(0, MAPOBJ_IVY_THICK, DRAW_UP, true, v3(300,500,0),true, v3(600,22,0), 10),
	STAGE_DATA(0, MAPOBJ_IVY_THICK, DRAW_UP, false, v3(300,100,0),true, v3(600,22,0), 10),
	STAGE_DATA(0, MAPOBJ_IVY_THIN, DRAW_UP, false, v3(200,200,0),true, v3(200,22,0), 10),
	STAGE_DATA(0, MAPOBJ_IVY_THIN, DRAW_DOWN, false, v3(200,222,0),true, v3(200,22,0), 10),
	STAGE_DATA(0, MAPOBJ_IVY_THIN, DRAW_LEFT, false, v3(178,400,0),true, v3(22,200,0), 10),
	STAGE_DATA(0, MAPOBJ_IVY_THIN, DRAW_RIGHT, false, v3(422,400,0),true, v3(22,200,0), 10),
	STAGE_DATA(-1, MAPOBJ_NONE, DRAW_UP, false, v3(0,0,0),false, v3(0,0,0)),
};