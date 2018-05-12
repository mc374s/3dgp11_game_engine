//******************************************************************************
//
//
//		2D画像データ
//
//
//******************************************************************************

// インクルード
#include "Game.h"

// ラベル定義
enum {
	TITLEBG,
	BG,
	INVADERS,


	LOGOS,
	N64,
	PAGE_LEFT,
	PAGE_RIGHT,
};

// 2D画像ロードデータ
LOAD_TEXTURE load_texture[] = {
	{ TITLEBG,		"./DATA/Images/TITLE.png"},
	{ BG,			"./DATA/Images/BG.png"},
	{ INVADERS,		"./DATA/Images/invaders512.png"},


	{ LOGOS,		"./DATA/Images/logos.jpg" },
	{ N64,			"./DATA/Images/n64.png" },
	{ PAGE_LEFT,	"./DATA/Images/page_left.png" },
	{ PAGE_RIGHT,	"./DATA/Images/page_right.png" },
	{ -1, NULL }
};

// 背景
SPRITE_LEFTTOP	spr_background = SPRITE_LEFTTOP(BG, 0, 0, VIEW_WIDTH, VIEW_HEIGHT);
SPRITE_LEFTTOP	spr_background_title = SPRITE_LEFTTOP(TITLEBG, 0, 0, VIEW_WIDTH, VIEW_HEIGHT);

// キャラなど
SPRITE_CENTER spr_enemy_a00 = SPRITE_CENTER(INVADERS, 0, 0, 52, 40);
SPRITE_CENTER spr_enemy_a01 = SPRITE_CENTER(INVADERS, 56, 0, 52, 40);
SPRITE_CENTER spr_enemy_b00 = SPRITE_CENTER(INVADERS, 0, 44, 40, 40);
SPRITE_CENTER spr_enemy_b01 = SPRITE_CENTER(INVADERS, 44, 44, 40, 40);
SPRITE_CENTER spr_enemy_c00 = SPRITE_CENTER(INVADERS, 0, 88, 56, 40);
SPRITE_CENTER spr_enemy_c01 = SPRITE_CENTER(INVADERS, 60, 88, 56, 40);
SPRITE_CENTER spr_player00 = SPRITE_CENTER(INVADERS, 0, 132, 52, 40);
SPRITE_CENTER spr_player01 = SPRITE_CENTER(INVADERS, 64, 180, 52, 36);
SPRITE_CENTER spr_enemy_explosion00 = SPRITE_CENTER(INVADERS, 0, 176, 60, 40);
SPRITE_CENTER spr_shot_explosion00 = SPRITE_CENTER(INVADERS, 72, 220, 28, 44);
SPRITE_CENTER spr_enemy_shot_a00 = SPRITE_CENTER(INVADERS, 0, 220, 20, 44);
SPRITE_CENTER spr_enemy_shot_b00 = SPRITE_CENTER(INVADERS, 24, 220, 20, 44);
SPRITE_CENTER spr_enemy_shot_c00 = SPRITE_CENTER(INVADERS, 48, 220, 20, 44);
SPRITE_CENTER spr_player_shot_a00 = SPRITE_CENTER(INVADERS, 0, 308, 12, 44);
SPRITE_CENTER spr_ufo00 = SPRITE_CENTER(INVADERS, 0, 268, 72, 36);
SPRITE_CENTER spr_green00 = SPRITE_CENTER(INVADERS, 4, 360, 4, 4);

SPRITE_DATA* spr_enemy[][2] =
{
	{ &spr_enemy_a00, &spr_enemy_a01 },
	{ &spr_enemy_b00, &spr_enemy_b01 },
	{ &spr_enemy_c00, &spr_enemy_c01 },
};
SPRITE_DATA* spr_explosion[] =
{
	&spr_enemy_explosion00,
	&spr_enemy_explosion00,
	&spr_enemy_explosion00,
	&spr_enemy_explosion00,
	&spr_shot_explosion00,
};

SPRITE_DATA* spr_enemy_shot[] =
{
	&spr_enemy_shot_a00,
	&spr_enemy_shot_b00,
	&spr_enemy_shot_c00,
};



//

SPRITE_CENTER e_sprLogos = SPRITE_CENTER(LOGOS, 0, 0, 1920, 1080);
SPRITE_CENTER e_sprN64 = SPRITE_CENTER(N64, 0, 0, 900, 877);
SPRITE_LEFTTOP e_sprPageLeft = SPRITE_LEFTTOP(PAGE_LEFT, 0, 0, 620, 700);
SPRITE_LEFTTOP e_sprPageRight = SPRITE_LEFTTOP(PAGE_RIGHT, 0, 0, 620, 700);


//******************************************************************************
