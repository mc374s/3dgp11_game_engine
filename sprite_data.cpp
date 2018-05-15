//******************************************************************************
//
//
//		2D画像データ
//
//
//******************************************************************************

// インクルード
#include "game.h"

#include "sprite_data.h"

// ラベル定義
enum TEX_NO {
	TEX_TITLE,
	TEX_MAIN,
	TEX_PLAYER,

	TEX_PAGE_LEFT,
	TEX_PAGE_RIGHT,
	TEX_MAP_OBJECT,
};

// 2D画像ロードデータ
LOAD_TEXTURE e_loadTexture[] = {
	{ TEX_TITLE,		"./DATA/Images/default_bg.jpg"},
	{ TEX_MAIN,			"./DATA/Images/default_bg.jpg"},
	{ TEX_PLAYER,		"./DATA/Images/character.png"},


	{ TEX_PAGE_LEFT,	"./DATA/Images/page_left.png" },
	{ TEX_PAGE_RIGHT,	"./DATA/Images/page_right.png" },
	{ TEX_MAP_OBJECT,	"./DATA/Images/map_object.png" },
	{ -1, NULL }
};

// 背景
SPRITE_LEFTTOP	e_sprTitleBG = SPRITE_LEFTTOP(TEX_TITLE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
SPRITE_LEFTTOP	e_sprMainBG = SPRITE_LEFTTOP(TEX_MAIN, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

// Book texture
SPRITE_LEFTTOP e_sprPageLeft = SPRITE_LEFTTOP(TEX_PAGE_LEFT, 0, 0, PAGE_WIDTH, PAGE_HEIGHT);
SPRITE_LEFTTOP e_sprPageRight = SPRITE_LEFTTOP(TEX_PAGE_RIGHT, 0, 0, PAGE_WIDTH, PAGE_HEIGHT);

// キャラなど

//SPRITE_BOTTOM e_pSprPlayerStandby[] = {
//
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 0, 80, 95, 45, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 1, 80, 95, 45, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 2, 80, 95, 45, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 3, 80, 95, 45, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 4, 80, 95, 45, 5),
//	SPRITE_BOTTOM(-1, 0, 0, 0, 0),
//
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 0, 176, 95, 45, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 1, 176, 95, 45, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 2, 176, 95, 45, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 3, 176, 95, 45, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 4, 176, 95, 45, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 5, 176, 95, 45, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 6, 176, 95, 45, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 7, 176, 95, 45, 5),
//	SPRITE_BOTTOM(-1, 0, 0, 0, 0),
//};
//
//SPRITE_BOTTOM* e_pAnimePlayerStandby[][9] = {
//	{
//		&e_pSprPlayerStandby[0],
//		&e_pSprPlayerStandby[1],
//		&e_pSprPlayerStandby[2],
//		&e_pSprPlayerStandby[3],
//		&e_pSprPlayerStandby[4],
//		&e_pSprPlayerStandby[5],
//	},
//	{
//		&e_pSprPlayerStandby[6],
//		&e_pSprPlayerStandby[7],
//		&e_pSprPlayerStandby[8],
//		&e_pSprPlayerStandby[9],
//		&e_pSprPlayerStandby[10],
//		&e_pSprPlayerStandby[11],
//		&e_pSprPlayerStandby[12],
//		&e_pSprPlayerStandby[13],
//		&e_pSprPlayerStandby[14],
//	},
//};

SPRITE_BOTTOM e_pAnimePlayerStandby[] = {

	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 0, 80, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 1, 80, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 2, 80, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 3, 80, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 4, 80, 95, 45, 5),
	SPRITE_BOTTOM(-1, 0, 0, 0, 0),
};

SPRITE_BOTTOM e_pAnimePlayerYawn[] = {

	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 0, 176, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 1, 176, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 2, 176, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 3, 176, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 4, 176, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 5, 176, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 6, 176, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 7, 176, 95, 45, 5),
	SPRITE_BOTTOM(-1, 0, 0, 0, 0),
};

SPRITE_BOTTOM e_pAnimePlayerRun[] = {

	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 0, 0, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 1, 0, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 2, 0, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 3, 0, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 4, 0, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 5, 0, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 6, 0, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 7, 0, 95, 45, 5),
	SPRITE_BOTTOM(-1, 0, 0, 0, 0),
};

SPRITE_BOTTOM e_pAnimePlayerJump[] = {

	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 0, 288, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 1, 288, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 2, 288, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 3, 288, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 4, 288, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 5, 288, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 6, 288, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 7, 288, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 8, 288, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 9, 288, 95, 45, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 95 * 10, 288, 95, 45, 5),
	SPRITE_BOTTOM(-1, 0, 0, 0, 0),
};


// マップ関係、アイテム
SPRITE_BOTTOM e_pSprItem[] =
{
	SPRITE_BOTTOM(TEX_MAP_OBJECT,   0, 0, 147,  92),// ITEM_HOUSE
	SPRITE_BOTTOM(TEX_MAP_OBJECT, 147, 0, 101, 122),// ITEM_TREE_A
	SPRITE_BOTTOM(TEX_MAP_OBJECT, 248, 0,  99, 112),// MAPOBJ_TREE_B
	SPRITE_BOTTOM(TEX_MAP_OBJECT, 347, 0,  79,  47),// MAPOBJ_IVY_BIG
	SPRITE_BOTTOM(TEX_MAP_OBJECT, 573, 0, 125,  22),// MAPOBJ_IVY_THIN
	SPRITE_BOTTOM(TEX_MAP_OBJECT, 448, 0, 125,  17),// MAPOBJ_IVY_THICK
	SPRITE_BOTTOM(TEX_MAP_OBJECT, 715, 0,  51,  76),// MAPOBJ_DOOR
	SPRITE_BOTTOM(TEX_MAP_OBJECT, 802, 0,  36,  28),// MAPOBJ_KEY

	SPRITE_BOTTOM(-1, 0, 0, 0, 0),
};

//******************************************************************************
