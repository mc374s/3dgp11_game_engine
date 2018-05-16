#include "game.h"
#include "map_obj.h"

#include "stage_data.h"

STAGE_DATA stage00_setData[] = {
	STAGE_DATA(0, MAPOBJ_TREE_A, DRAW_UP, true, v3(50,100,0),false, v3(0,0,0), 10),
	STAGE_DATA(10, MAPOBJ_TREE_A, DRAW_UP, false, v3(100,100,0),false, v3(0,0,0), 10),
	STAGE_DATA(20, MAPOBJ_HOUSE, DRAW_UP, true, v3(200,100,0),false, v3(100,20,0), 10),
	STAGE_DATA(30, MAPOBJ_HOUSE, DRAW_UP, false, v3(200,100,0),false, v3(100,20,0), 10),
	STAGE_DATA(40, MAPOBJ_IVY_BIG, DRAW_UP, false, v3(200,400,0),true, v3(100,20,0), 10),
	STAGE_DATA(50, MAPOBJ_IVY_THICK, DRAW_UP, true, v3(200,500,0),true, v3(600,22,0), 10),
	STAGE_DATA(60, MAPOBJ_IVY_THIN, DRAW_UP, true, v3(200,550,0),true, v3(200,22,0), 10),
	STAGE_DATA(50, MAPOBJ_IVY_THICK, DRAW_UP, false, v3(200,100,0),true, v3(600,22,0), 10),
	STAGE_DATA(60, MAPOBJ_IVY_THIN, DRAW_UP, false, v3(200,150,0),true, v3(200,22,0), 10),
	STAGE_DATA(-1, MAPOBJ_NONE, DRAW_UP, false, v3(0,0,0),false, v3(0,0,0)),
};