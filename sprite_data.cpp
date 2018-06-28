﻿//******************************************************************************
//
//
//		2D画像データ
//
//
//******************************************************************************

// インクルード
#include "game.h"

#include "sprite_data.h"


// 2D画像ロードデータ
LOAD_TEXTURE e_loadTexture[] = {
	{ TEX_COVER_FRONT,				"./DATA/Images/Book/cover_front.png" },
	{ TEX_COVER_BACK,				"./DATA/Images/Book/cover_back.png" },
	{ TEX_PAGE,						"./DATA/Images/Book/page.png" },

	{ TEX_WHITE,					"./DATA/Images/white.png"},
	{ TEX_WHITE_CIRCLE,				"./DATA/Images/particle_circle.png", true },
	{ TEX_MAIN,						"./DATA/Images/main_bg.png"},
	{ TEX_PLAYER,					"./DATA/Images/player.png"},
	{ TEX_PLAYER_EYES,				"./DATA/Images/player_eyes.png" },
	{ TEX_PLAYER_LARGE,				"./DATA/Images/player_big.png" },

	{ TEX_BORDER_INNER,				"./DATA/Images/Map/border_inner.png" },
	{ TEX_PASSABLE,					"./DATA/Images/Map/passable.png" },
	{ TEX_RECOVERY,					"./DATA/Images/Map/recovery.png" },
	{ TEX_MAP_OBJ_FOREST,			"./DATA/Images/Map/map_obj_1.png" },
	{ TEX_MAP_OBJ_BIRD,				"./DATA/Images/Map/map_obj_2.png" },
	{ TEX_MAP_OBJ_GRAVE,			"./DATA/Images/Map/map_obj_3.png" },
	{ TEX_MAP_OBJ_SNOW,				"./DATA/Images/Map/map_obj_4.png" },
	{ TEX_MAP_OBJ_DESERT,			"./DATA/Images/Map/map_obj_5.png" },
	{ TEX_TUTORIAL,					"./DATA/Images/Map/moji.png"},
	{ TEX_GOAL_SET,					"./DATA/Images/Map/goal_set.png" },
	{ TEX_PASSABLE_ARROW,			"./DATA/Images/Map/passable_arrow.png" },


	{ TEX_SMOKE,					"./DATA/Images/particle-smoke5.png" },
	{ TEX_LIFE_STAMP,				"./DATA/Images/UI/stamp.png"},

	{ TEX_NUMBERS,					"./DATA/Images/UI/numbers.png" },
	
	{ TEX_PAUSE_PANEL,				"./DATA/Images/UI/pause_panel.png" },
	{ TEX_PAUSE_SELECTED,			"./DATA/Images/UI/pause_selected.png" },
	{ TEX_RETRY_PANEL,				"./DATA/Images/UI/retry_panel.png" },

	{ TEX_ANIME_STAMP,				"./DATA/Images/Effect/stamp_pressing.png" },

	{ TEX_GAGE_DIVISION_ALLOCATION,	"./DATA/Images/UI/gage_division_allocation.png" },
	{ TEX_GAGE_DIVISION,			"./DATA/Images/UI/gage_division.png" },
	{ TEX_GAGE_DIVISION_WHITE,		"./DATA/Images/UI/gage_division_white.png" },
	{ TEX_ANIME_GAGE,				"./DATA/Images/UI/gage_ink_white.png" },
	{ TEX_PLAYER_FACE,				"./DATA/Images/UI/player_face.png" },

	{ TEX_EFF_DISAPPEAR,			"./DATA/Images/Effect/disappear.png" },
	{ TEX_EFF_JUMP_UP,				"./DATA/Images/Effect/jump_up.png" },
	{ TEX_EFF_JUMP_DOWN,			"./DATA/Images/Effect/jump_down.png" },
	{ TEX_EFF_MAKE_TRANSCRIPTION,	"./DATA/Images/Effect/make_transcription.png" },
	{ TEX_EFF_RECOVERY_PASSED,		"./DATA/Images/Effect/recovery_passed.png" },
	{ TEX_EFF_DAMAGING,				"./DATA/Images/Effect/damaging.png" },
	{ TEX_EFF_RUNNING,				"./DATA/Images/Effect/running.png" },
	{ TEX_EFF_ON_BLUR_AREA,			"./DATA/Images/Effect/on_blur_area.png" },
	{ TEX_EFF_STAMP_AND_SHADOW,		"./DATA/Images/Effect/stamp_and_shadow.png" },
	{ TEX_EFF_STAR,					"./DATA/Images/Effect/star.png" },
	{ TEX_EFF_CLOSE_BOOK,			"./DATA/Images/Effect/close_book.png" },
	{ TEX_EFF_GAGE_ON_BLUR_AREA,	"./DATA/Images/Effect/gage_effect.png" },
	{ TEX_EFF_BOOK_AURA,			"./DATA/Images/Effect/book_aura.png", true },
	{ TEX_EFF_GOAL,					"./DATA/Images/Effect/goal_effect.png" },
	{ TEX_EFF_PLAYER_BORDER,		"./DATA/Images/Effect/player_border.png" },
	{ TEX_EFF_SPIRALS,				"./DATA/Images/Effect/spirals.png" },
	{ TEX_EFF_CLEAR_STAR,			"./DATA/Images/Effect/clear_star.png" },
	{ TEX_EFF_FIREWORK,				"./DATA/Images/Effect/firework.png" },

	{ TEX_GAME_RULE_LEFT,			"./DATA/Images/Book/game_rule_left.png" },
	{ TEX_GAME_RULE_RIGHT,			"./DATA/Images/Book/game_rule_right.png" },

	{ TEX_HELP,						"./DATA/Images/UI/help.png" },
	{ TEX_HELP_BUTTON,				"./DATA/Images/UI/help_button.png" },

	{ TEX_X_BUTTON,					"./DATA/Images/UI/x_button.png" },
	
	{ TEX_SCROLL_MODE,				"./DATA/Images/UI/scroll_mode.png" },
	{ TEX_SCROLL_ARROW,				"./DATA/Images/UI/scroll_arrow.png" },

	{ TEX_STAGE_CLEAR,				"./DATA/Images/UI/stage_clear.png" },
	{ TEX_GAME_CLEAR,				"./DATA/Images/UI/game_clear.png" },
	{ TEX_GAME_OVER,				"./DATA/Images/UI/game_over.png" },
	{ TEX_STAGE_CLEAR_BEHIND,		"./DATA/Images/UI/stage_clear_behind.png" },
	{ TEX_STAGE_CLEAR_FRONT,		"./DATA/Images/UI/stage_clear_front.png" },
	{ TEX_GAME_OVER_BEHIND,			"./DATA/Images/UI/game_over_behind.png" },
	{ TEX_GAME_OVER_FRONT,			"./DATA/Images/UI/game_over_front.png" },
	{ TEX_CLEAR_MARK,				"./DATA/Images/UI/clear_mark.png" },

	{ TEX_STAGE_SELECT00_LEFT,			"./DATA/Images/UI/stage_select00_left.png" },
	{ TEX_STAGE_SELECT00_RIGHT,			"./DATA/Images/UI/stage_select00_right.png" },
	{ TEX_STAGE_SELECT01_LEFT,			"./DATA/Images/UI/stage_select01_left.png" },
	{ TEX_STAGE_SELECT01_RIGHT,			"./DATA/Images/UI/stage_select01_right.png" },

	{ TEX_STAGE_INTRO01_LEFT,			"./DATA/Images/UI/stage_intro01_left.png" },
	{ TEX_STAGE_INTRO01_RIGHT,			"./DATA/Images/UI/stage_intro01_right.png" },
	{ TEX_STAGE_INTRO02_LEFT,			"./DATA/Images/UI/stage_intro02_left.png" },
	{ TEX_STAGE_INTRO02_RIGHT,			"./DATA/Images/UI/stage_intro02_right.png" },
	{ TEX_STAGE_INTRO03_LEFT,			"./DATA/Images/UI/stage_intro03_left.png" },
	{ TEX_STAGE_INTRO03_RIGHT,			"./DATA/Images/UI/stage_intro03_right.png" },
	{ TEX_STAGE_INTRO04_LEFT,			"./DATA/Images/UI/stage_intro04_left.png" },
	{ TEX_STAGE_INTRO04_RIGHT,			"./DATA/Images/UI/stage_intro04_right.png" },
	{ TEX_STAGE_INTRO05_LEFT,			"./DATA/Images/UI/stage_intro05_left.png" },
	{ TEX_STAGE_INTRO05_RIGHT,			"./DATA/Images/UI/stage_intro05_right.png" },



	{ TEX_STAGE_SELECTED,			"./DATA/Images/UI/stage_selected.png" },



	{ -1, NULL },
};

// 背景
SPRITE_LEFTTOP	e_sprMainBG = SPRITE_LEFTTOP(TEX_MAIN, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

// Book texture
SPRITE_LEFTTOP e_sprPage = SPRITE_LEFTTOP(TEX_PAGE, 0, 0, PAGE_WIDTH, PAGE_HEIGHT);


SPRITE_LEFTTOP e_sprCoverFront = SPRITE_LEFTTOP(TEX_COVER_FRONT, 0, 0, PAGE_WIDTH + 0 + 20, PAGE_HEIGHT + 10 + 10);
SPRITE_LEFTTOP e_sprCoverBack = SPRITE_LEFTTOP(TEX_COVER_BACK, 0, 0, PAGE_WIDTH + 0 + 20, PAGE_HEIGHT + 10 + 10);

// キャラなど

//SPRITE_BOTTOM e_pAnimePlayerStandby[] = {
//
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 0, 95, 120, 55, 8),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 1, 95, 120, 55, 8),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 2, 95, 120, 55, 8),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 3, 95, 120, 55, 8),
//	SPRITE_BOTTOM(-1, 0, 0, 0, 0),
//};

SPRITE_BOTTOM e_pAnimePlayerStandby[] = {

	SPRITE_BOTTOM(TEX_PLAYER, 0 + 86 * 0, 0, 86, 55, 8),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 86 * 1, 0, 86, 55, 8),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 86 * 2, 0, 86, 55, 8),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 86 * 3, 0, 86, 55, 8),
	SPRITE_BOTTOM(-1, 0, 0, 0, 0),
};

//SPRITE_BOTTOM e_pAnimePlayerYawn[] = {
//
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 0, 177, 120, 73, 8),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 1, 177, 120, 73, 8),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 2, 177, 120, 73, 8),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 3, 177, 120, 73, 8),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 4, 177, 120, 73, 8),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 5, 177, 120, 73, 8),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 6, 177, 120, 73, 8),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 7, 177, 120, 73, 8),
//	SPRITE_BOTTOM(-1, 0, 0, 0, 0),
//};

SPRITE_BOTTOM e_pAnimePlayerYawn[] = {

	SPRITE_BOTTOM(TEX_PLAYER, 0 + 86 * 0, 85, 86, 78, 8),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 86 * 1, 85, 86, 78, 8),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 86 * 2, 85, 86, 78, 8),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 86 * 3, 85, 86, 78, 8),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 86 * 4, 85, 86, 78, 8),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 86 * 5, 85, 86, 78, 8),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 86 * 6, 85, 86, 78, 8),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 86 * 7, 85, 86, 78, 8),
	SPRITE_BOTTOM(-1, 0, 0, 0, 0),
};

//SPRITE_BOTTOM e_pAnimePlayerRun[] = {
//
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 0, 0, 120, 50, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 1, 0, 120, 50, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 2, 0, 120, 50, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 3, 0, 120, 50, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 4, 0, 120, 50, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 5, 0, 120, 50, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 6, 0, 120, 50, 5),
//	SPRITE_BOTTOM(-1, 0, 0, 0, 0),
//};

SPRITE_BOTTOM e_pAnimePlayerRun[] = {

	SPRITE_BOTTOM(TEX_PLAYER, 0 + 146 * 0, 200, 146, 46, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 146 * 1, 200, 146, 46, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 146 * 2, 200, 146, 46, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 146 * 3, 200, 146, 46, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 146 * 4, 200, 146, 46, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 146 * 5, 200, 146, 46, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 146 * 6, 200, 146, 46, 5),
	SPRITE_BOTTOM(-1, 0, 0, 0, 0),
};

//SPRITE_BOTTOM e_pAnimePlayerJump[] = {
//
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 0, 285, 120, 65, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 1, 285, 120, 65, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 2, 285, 120, 65, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 3, 285, 120, 65, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 4, 285, 120, 65, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 5, 285, 120, 65, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 6, 285, 120, 65, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 7, 285, 120, 65, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 8, 285, 120, 65, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 9, 285, 120, 65, 5),
//	SPRITE_BOTTOM(TEX_PLAYER, 0 + 120 * 10, 285, 120, 65, 5),
//	SPRITE_BOTTOM(-1, 0, 0, 0, 0),
//};
SPRITE_BOTTOM e_pAnimePlayerJumpUp[] = {

	SPRITE_BOTTOM(TEX_PLAYER, 0 + 100 * 0, 280, 100, 57, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 100 * 1, 280, 100, 57, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 100 * 2, 280, 100, 57, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 100 * 3, 280, 100, 57, 5),
	SPRITE_BOTTOM(-1, 0, 0, 0, 0),
};

SPRITE_BOTTOM e_pAnimePlayerJump[] = {

	SPRITE_BOTTOM(TEX_PLAYER, 0 + 100 * 0, 370, 100, 60, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 100 * 1, 370, 100, 60, 5),
	SPRITE_BOTTOM(-1, 0, 0, 0, 0),
};

SPRITE_BOTTOM e_pAnimePlayerJumpDown[] = {

	SPRITE_BOTTOM(TEX_PLAYER, 0 + 100 * 0, 470, 100, 57, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 100 * 1, 470, 100, 57, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 100 * 2, 470, 100, 57, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 100 * 3, 470, 100, 57, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 100 * 4, 470, 100, 57, 5),
	SPRITE_BOTTOM(TEX_PLAYER, 0 + 100 * 5, 470, 100, 57, 5),
	SPRITE_BOTTOM(-1, 0, 0, 0, 0),
};

SPRITE_BOTTOM e_sprEyes = SPRITE_BOTTOM(TEX_PLAYER_EYES, 0, 0, 0, 0);

// マップ関係、アイテム

SPRITE_LEFTTOP e_pAnimeRecovery[] =
{
	SPRITE_LEFTTOP(TEX_PASSABLE,    0, 0, 130,  17,0,0,15),
	SPRITE_LEFTTOP(TEX_PASSABLE,    130, 0, 130,  17,0,0,15),
	SPRITE_LEFTTOP(TEX_PASSABLE,    130 * 2, 0, 130,  17,0,0,15),
	SPRITE_LEFTTOP(TEX_PASSABLE,    130 * 3, 0, 130,  17,0,0,15 ),
	SPRITE_LEFTTOP(-1,0,0,0,0),
};


SPRITE_LEFTTOP e_pSprItem[] =
{
	SPRITE_LEFTTOP(TEX_BORDER_INNER, 0, 0, 125, 17),	// M_TYPE::BORDER_INNER
	e_pAnimeRecovery[0],								// M_TYPE::PASSABLE_UP
	e_pAnimeRecovery[0],								// M_TYPE::PASSABLE_DOWN
	SPRITE_LEFTTOP(TEX_RECOVERY,	 0, 0,	71, 64),	// M_TYPE::RECOVERY

	SPRITE_LEFTTOP(TEX_GOAL_SET, 100, 0, 111, 99),		// M_TYPE::KEY_1_1:
	SPRITE_LEFTTOP(TEX_GOAL_SET, 100, 99, 111, 99),		// M_TYPE::DOOR_1_1:

	SPRITE_LEFTTOP(TEX_GOAL_SET, 100, 198, 117, 131),	// M_TYPE::DOOR_2_1:
	SPRITE_LEFTTOP(TEX_GOAL_SET, 100, 329, 117, 131),	// M_TYPE::KEY_2_1:

	SPRITE_LEFTTOP(TEX_GOAL_SET, 100, 461, 101, 133),	// M_TYPE::DOOR_3_1:
	SPRITE_LEFTTOP(TEX_GOAL_SET, 100, 594, 101, 133),	// M_TYPE::KEY_3_1:
	SPRITE_LEFTTOP(TEX_GOAL_SET, 201, 461, 101, 133),	// M_TYPE::DOOR_3_2:
	SPRITE_LEFTTOP(TEX_GOAL_SET, 201, 594, 101, 133),	// M_TYPE::KEY_3_2:

	SPRITE_LEFTTOP(TEX_GOAL_SET, 100, 726, 100, 129),	// M_TYPE::DOOR_4_1:
	SPRITE_LEFTTOP(TEX_GOAL_SET, 100, 855, 100, 129),	// M_TYPE::KEY_4_1:
	SPRITE_LEFTTOP(TEX_GOAL_SET, 200, 726, 100, 129),	// M_TYPE::DOOR_4_2:
	SPRITE_LEFTTOP(TEX_GOAL_SET, 200, 855, 100, 129),	// M_TYPE::KEY_4_2:
	SPRITE_LEFTTOP(TEX_GOAL_SET, 300, 726, 100, 129),	// M_TYPE::DOOR_4_3:
	SPRITE_LEFTTOP(TEX_GOAL_SET, 300, 855, 100, 129),	// M_TYPE::KEY_4_3:

	SPRITE_LEFTTOP(TEX_GOAL_SET, 100, 984, 128, 99),	// M_TYPE::DOOR_5_1:
	SPRITE_LEFTTOP(TEX_GOAL_SET, 100, 1083, 128, 99),	// M_TYPE::KEY_5_1:
	SPRITE_LEFTTOP(TEX_GOAL_SET, 228, 984, 128, 99),	// M_TYPE::DOOR_5_2:
	SPRITE_LEFTTOP(TEX_GOAL_SET, 228, 1083, 128, 99),	// M_TYPE::KEY_5_2:
	SPRITE_LEFTTOP(TEX_GOAL_SET, 356, 984, 128, 99),	// M_TYPE::DOOR_5_3:
	SPRITE_LEFTTOP(TEX_GOAL_SET, 356, 1083, 128, 99),	// M_TYPE::KEY_5_3:


	SPRITE_LEFTTOP(TEX_WHITE, 0, 0,  32,  32),// M_TYPE::HIGH_CONCENTRATION
	SPRITE_LEFTTOP(TEX_GAME_RULE_LEFT, 0, 0,  PAGE_WIDTH,  PAGE_HEIGHT),// M_TYPE::GAME_RULE_LEFT
	SPRITE_LEFTTOP(TEX_GAME_RULE_RIGHT, 0, 0,  PAGE_WIDTH,  PAGE_HEIGHT),// M_TYPE::GAME_RULE_RIGHT

	SPRITE_LEFTTOP(TEX_STAGE_SELECT00_LEFT, 0, 0, PAGE_WIDTH, PAGE_HEIGHT),		// M_TYPE::STAGE_SELECT00_LEFT
	SPRITE_LEFTTOP(TEX_STAGE_SELECT00_RIGHT, 0, 0, PAGE_WIDTH, PAGE_HEIGHT),	// M_TYPE::STAGE_SELECT00_RIGHT
	SPRITE_LEFTTOP(TEX_STAGE_SELECT01_LEFT, 0, 0, PAGE_WIDTH, PAGE_HEIGHT),		// M_TYPE::STAGE_SELECT01_LEFT
	SPRITE_LEFTTOP(TEX_STAGE_SELECT01_RIGHT, 0, 0, PAGE_WIDTH, PAGE_HEIGHT),	// M_TYPE::STAGE_SELECT01_RIGHT

	SPRITE_LEFTTOP(TEX_STAGE_INTRO01_LEFT, 0, 0, PAGE_WIDTH, PAGE_HEIGHT),	// M_TYPE::STAGE_INTRO01_LEFT
	SPRITE_LEFTTOP(TEX_STAGE_INTRO01_RIGHT, 0, 0, PAGE_WIDTH, PAGE_HEIGHT),	// M_TYPE::STAGE_INTRO01_RIGHT
	SPRITE_LEFTTOP(TEX_STAGE_INTRO02_LEFT, 0, 0, PAGE_WIDTH, PAGE_HEIGHT),	// M_TYPE::STAGE_INTRO02_LEFT
	SPRITE_LEFTTOP(TEX_STAGE_INTRO02_RIGHT, 0, 0, PAGE_WIDTH, PAGE_HEIGHT),	// M_TYPE::STAGE_INTRO02_RIGHT
	SPRITE_LEFTTOP(TEX_STAGE_INTRO03_LEFT, 0, 0, PAGE_WIDTH, PAGE_HEIGHT),	// M_TYPE::STAGE_INTRO03_LEFT
	SPRITE_LEFTTOP(TEX_STAGE_INTRO03_RIGHT, 0, 0, PAGE_WIDTH, PAGE_HEIGHT),	// M_TYPE::STAGE_INTRO03_RIGHT
	SPRITE_LEFTTOP(TEX_STAGE_INTRO04_LEFT, 0, 0, PAGE_WIDTH, PAGE_HEIGHT),	// M_TYPE::STAGE_INTRO04_LEFT
	SPRITE_LEFTTOP(TEX_STAGE_INTRO04_RIGHT, 0, 0, PAGE_WIDTH, PAGE_HEIGHT),	// M_TYPE::STAGE_INTRO04_RIGHT
	SPRITE_LEFTTOP(TEX_STAGE_INTRO05_LEFT, 0, 0, PAGE_WIDTH, PAGE_HEIGHT),	// M_TYPE::STAGE_INTRO05_LEFT
	SPRITE_LEFTTOP(TEX_STAGE_INTRO05_RIGHT, 0, 0, PAGE_WIDTH, PAGE_HEIGHT),	// M_TYPE::STAGE_INTRO05_RIGHT


	SPRITE_LEFTTOP(TEX_MAP_OBJ_FOREST, 0, 143 * 0, 83, 36),		// M_TYPE::FOREST_1
	SPRITE_LEFTTOP(TEX_MAP_OBJ_FOREST, 0, 143 * 1, 57, 43),		// M_TYPE::FOREST_2
	SPRITE_LEFTTOP(TEX_MAP_OBJ_FOREST, 0, 143 * 2, 119, 56),	// M_TYPE::FOREST_3
	SPRITE_LEFTTOP(TEX_MAP_OBJ_FOREST, 0, 143 * 3, 169, 25),	// M_TYPE::FOREST_4
	SPRITE_LEFTTOP(TEX_MAP_OBJ_FOREST, 0, 143 * 4, 168, 26),	// M_TYPE::FOREST_5
	SPRITE_LEFTTOP(TEX_MAP_OBJ_FOREST, 0, 143 * 5, 89, 143),	// M_TYPE::FOREST_6
	SPRITE_LEFTTOP(TEX_MAP_OBJ_FOREST, 0, 143 * 6, 91, 138),	// M_TYPE::FOREST_7
	SPRITE_LEFTTOP(TEX_MAP_OBJ_FOREST, 0, 143 * 7, 115, 128),	// M_TYPE::FOREST_8
	SPRITE_LEFTTOP(TEX_MAP_OBJ_FOREST, 0, 143 * 8, 33, 107),	// M_TYPE::FOREST_9
	SPRITE_LEFTTOP(TEX_MAP_OBJ_FOREST, 0, 143 * 9, 44, 113),	// M_TYPE::FOREST_10
	SPRITE_LEFTTOP(TEX_MAP_OBJ_FOREST, 0, 143 * 10, 146, 110),	// M_TYPE::FOREST_11

	SPRITE_LEFTTOP(TEX_MAP_OBJ_BIRD, 0, 165 * 0, 182, 146),		// M_TYPE::BIRD_1
	SPRITE_LEFTTOP(TEX_MAP_OBJ_BIRD, 0, 165 * 1, 138, 137),		// M_TYPE::BIRD_2
	SPRITE_LEFTTOP(TEX_MAP_OBJ_BIRD, 0, 165 * 2, 190, 91),		// M_TYPE::BIRD_3
	SPRITE_LEFTTOP(TEX_MAP_OBJ_BIRD, 0, 165 * 3, 58, 85),		// M_TYPE::BIRD_4
	SPRITE_LEFTTOP(TEX_MAP_OBJ_BIRD, 0, 165 * 4, 57, 85),		// M_TYPE::BIRD_5
	SPRITE_LEFTTOP(TEX_MAP_OBJ_BIRD, 0, 165 * 5, 182, 111),		// M_TYPE::BIRD_6
	SPRITE_LEFTTOP(TEX_MAP_OBJ_BIRD, 0, 165 * 6, 158, 165),		// M_TYPE::BIRD_7
	SPRITE_LEFTTOP(TEX_MAP_OBJ_BIRD, 0, 165 * 7, 192, 148),		// M_TYPE::BIRD_8

	SPRITE_LEFTTOP(TEX_MAP_OBJ_GRAVE, 0, 153 * 0, 82, 54),		// M_TYPE::GRAVE_1
	SPRITE_LEFTTOP(TEX_MAP_OBJ_GRAVE, 0, 153 * 1, 68, 74),		// M_TYPE::GRAVE_2
	SPRITE_LEFTTOP(TEX_MAP_OBJ_GRAVE, 0, 153 * 2, 122, 100),	// M_TYPE::GRAVE_3
	SPRITE_LEFTTOP(TEX_MAP_OBJ_GRAVE, 0, 153 * 3, 50, 89),		// M_TYPE::GRAVE_4
	SPRITE_LEFTTOP(TEX_MAP_OBJ_GRAVE, 0, 153 * 4, 74, 95),		// M_TYPE::GRAVE_5
	SPRITE_LEFTTOP(TEX_MAP_OBJ_GRAVE, 0, 153 * 5, 66, 102),		// M_TYPE::GRAVE_6
	SPRITE_LEFTTOP(TEX_MAP_OBJ_GRAVE, 0, 153 * 6, 80, 121),		// M_TYPE::GRAVE_7
	SPRITE_LEFTTOP(TEX_MAP_OBJ_GRAVE, 0, 153 * 7, 80, 146),		// M_TYPE::GRAVE_8
	SPRITE_LEFTTOP(TEX_MAP_OBJ_GRAVE, 0, 153 * 8, 56, 77),		// M_TYPE::GRAVE_9
	SPRITE_LEFTTOP(TEX_MAP_OBJ_GRAVE, 0, 153 * 9, 76, 84),		// M_TYPE::GRAVE_10
	SPRITE_LEFTTOP(TEX_MAP_OBJ_GRAVE, 0, 153 * 10, 261, 153),	// M_TYPE::GRAVE_11

	SPRITE_LEFTTOP(TEX_MAP_OBJ_SNOW, 0, 141 * 0, 87, 82),		// M_TYPE::SNOW_1
	SPRITE_LEFTTOP(TEX_MAP_OBJ_SNOW, 0, 141 * 1, 187, 103),		// M_TYPE::SNOW_2
	SPRITE_LEFTTOP(TEX_MAP_OBJ_SNOW, 0, 141 * 2, 146, 71),		// M_TYPE::SNOW_3
	SPRITE_LEFTTOP(TEX_MAP_OBJ_SNOW, 0, 141 * 3, 73, 83),		// M_TYPE::SNOW_4
	SPRITE_LEFTTOP(TEX_MAP_OBJ_SNOW, 0, 141 * 4, 80, 82),		// M_TYPE::SNOW_5
	SPRITE_LEFTTOP(TEX_MAP_OBJ_SNOW, 0, 141 * 5, 45, 52),		// M_TYPE::SNOW_6
	SPRITE_LEFTTOP(TEX_MAP_OBJ_SNOW, 0, 141 * 6, 39, 38),		// M_TYPE::SNOW_7
	SPRITE_LEFTTOP(TEX_MAP_OBJ_SNOW, 0, 141 * 7, 119, 141),		// M_TYPE::SNOW_8

	SPRITE_LEFTTOP(TEX_MAP_OBJ_DESERT, 0, 131 * 0, 163, 115),	// M_TYPE::DESERT_1
	SPRITE_LEFTTOP(TEX_MAP_OBJ_DESERT, 0, 131 * 1, 178, 32),	// M_TYPE::DESERT_2
	SPRITE_LEFTTOP(TEX_MAP_OBJ_DESERT, 0, 131 * 2, 69, 90),		// M_TYPE::DESERT_3
	SPRITE_LEFTTOP(TEX_MAP_OBJ_DESERT, 0, 131 * 3, 59, 49),		// M_TYPE::DESERT_4
	SPRITE_LEFTTOP(TEX_MAP_OBJ_DESERT, 0, 131 * 4, 154, 131),	// M_TYPE::DESERT_5
	SPRITE_LEFTTOP(TEX_MAP_OBJ_DESERT, 0, 131 * 5, 132, 47),	// M_TYPE::DESERT_6
	SPRITE_LEFTTOP(TEX_MAP_OBJ_DESERT, 0, 131 * 6, 146, 29),	// M_TYPE::DESERT_7
	SPRITE_LEFTTOP(TEX_MAP_OBJ_DESERT, 0, 131 * 7, 185, 93),	// M_TYPE::DESERT_8

	SPRITE_LEFTTOP(TEX_TUTORIAL, 0, 0, 102, 26),	// M_TYPE::TUTORIAL_1
	SPRITE_LEFTTOP(TEX_TUTORIAL, 0, 26, 157, 26),	// M_TYPE::TUTORIAL_2
	SPRITE_LEFTTOP(TEX_TUTORIAL, 0, 52, 309, 54),	// M_TYPE::TUTORIAL_3
	SPRITE_LEFTTOP(TEX_TUTORIAL, 0, 106, 239, 55),	// M_TYPE::TUTORIAL_4
	SPRITE_LEFTTOP(TEX_TUTORIAL, 0, 161, 334, 24),	// M_TYPE::TUTORIAL_5
	SPRITE_LEFTTOP(TEX_TUTORIAL, 0, 185, 327, 60),	// M_TYPE::TUTORIAL_6
	SPRITE_LEFTTOP(TEX_TUTORIAL, 0, 245, 310, 63),	// M_TYPE::TUTORIAL_7
	SPRITE_LEFTTOP(TEX_TUTORIAL, 0, 308, 335, 61),	// M_TYPE::TUTORIAL_8

	SPRITE_LEFTTOP(TEX_PASSABLE_ARROW, 0, 0, 74, 94),	// M_TYPE::PASSABLE_ARROW

	SPRITE_LEFTTOP(-1, 0, 0, 0, 0),
};

// UI関係
SPRITE_LEFTTOP e_sprLifeStamp = SPRITE_LEFTTOP(TEX_LIFE_STAMP, 0, 0, 40, 32);

SPRITE_LEFTTOP e_sprWhite = SPRITE_LEFTTOP(TEX_WHITE, 0, 0, 32, 32);
SPRITE_CENTER e_sprGageDivisionAllocation = SPRITE_CENTER(TEX_GAGE_DIVISION_ALLOCATION, 0, 0, 366, 70);
SPRITE_CENTER sprGageAllocationUnder = SPRITE_CENTER(TEX_WHITE, 0, 0, 34 * 10, 30);
SPRITE_CENTER e_sprGageAllocation = SPRITE_CENTER(TEX_WHITE, 0, 0, 34 * 10, 30);


SPRITE_LEFTTOP e_sprGageDivision = SPRITE_LEFTTOP(TEX_GAGE_DIVISION, 0, 0, 456, 128);
SPRITE_LEFTTOP e_sprGageDivisionWhite = SPRITE_LEFTTOP(TEX_GAGE_DIVISION_WHITE, 0, 0, 456, 128);
SPRITE_LEFTTOP e_sprGage = SPRITE_LEFTTOP(TEX_WHITE, 0, 0, 34 * 10 - 5, 30);
SPRITE_LEFTTOP e_sprGageUnder = SPRITE_LEFTTOP(TEX_WHITE, 0, 0, 34 * 10, 30);
SPRITE_LEFTTOP e_pAnimeGage[] = {
	SPRITE_LEFTTOP(TEX_ANIME_GAGE,  0, 0, 10, 30, 0, 0, 10),
	SPRITE_LEFTTOP(TEX_ANIME_GAGE, 10, 0, 10, 30, 0, 0, 10),
	SPRITE_LEFTTOP(TEX_ANIME_GAGE, 20, 0, 10, 30, 0, 0, 10),
	SPRITE_LEFTTOP(TEX_ANIME_GAGE, 30, 0, 10, 30, 0, 0, 10),
	SPRITE_LEFTTOP(TEX_ANIME_GAGE, 40, 0, 10, 30, 0, 0, 10),
	SPRITE_LEFTTOP(-1, 0, 0, 0, 0),
};

SPRITE_BOTTOM e_sprLargePlayer = SPRITE_BOTTOM(TEX_PLAYER_LARGE, 0, 0, 32, 32);

SPRITE_LEFTTOP e_pSprPlayerFace[] = {
	SPRITE_LEFTTOP(TEX_PLAYER_FACE, 0  , 0, 90, 90),
	SPRITE_LEFTTOP(TEX_PLAYER_FACE, 90 , 0, 90, 90),
	SPRITE_LEFTTOP(TEX_PLAYER_FACE, 180, 0, 90, 90),
};

SPRITE_CENTER e_sprNumbers = SPRITE_CENTER(TEX_NUMBERS, 0, 0, 76, 118);

SPRITE_CENTER e_sprPausePanel = SPRITE_CENTER(TEX_PAUSE_PANEL, 0, 0, 670, 380);
SPRITE_CENTER e_sprPauseSelected = SPRITE_CENTER(TEX_PAUSE_SELECTED, 0, 0, 75, 77);
SPRITE_CENTER e_sprRetryPanel = SPRITE_CENTER(TEX_RETRY_PANEL, 0, 0, 333, 144);

SPRITE_CENTER e_sprStageClear = SPRITE_CENTER(TEX_STAGE_CLEAR, 0, 0, 932, 360);
SPRITE_CENTER e_sprGameClear = SPRITE_CENTER(TEX_GAME_CLEAR, 0, 0, 932, 360);
SPRITE_CENTER e_sprGameOver = SPRITE_CENTER(TEX_GAME_OVER, 0, 0, 932, 360);
SPRITE_CENTER e_sprStageClearBehind = SPRITE_CENTER(TEX_STAGE_CLEAR_BEHIND, 0, 0, 1009, 360);
SPRITE_CENTER e_sprStageClearFront = SPRITE_CENTER(TEX_STAGE_CLEAR_FRONT, 0, 0, 1009, 360);
SPRITE_CENTER e_sprGameOverBehind = SPRITE_CENTER(TEX_GAME_OVER_BEHIND, 0, 0, 1009, 360);
SPRITE_CENTER e_sprGameOverFront = SPRITE_CENTER(TEX_GAME_OVER_FRONT, 0, 0, 1009, 360);

SPRITE_CENTER e_sprXButton = SPRITE_CENTER(TEX_X_BUTTON, 0, 0, 48, 48);

SPRITE_CENTER e_sprHelp = SPRITE_CENTER(TEX_HELP, 0, 0, 800, 600);
//SPRITE_LEFTTOP e_sprHelpButton = SPRITE_LEFTTOP(TEX_HELP_BUTTON, 0, 0, 150, 50);
SPRITE_LEFTTOP e_sprHelpButton = SPRITE_LEFTTOP(TEX_HELP_BUTTON, 0, 0, 132, 54);
SPRITE_LEFTTOP e_sprScrollMode = SPRITE_LEFTTOP(TEX_SCROLL_MODE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
SPRITE_CENTER e_sprScrollArrow = SPRITE_CENTER(TEX_SCROLL_ARROW, 0, 0, 79, 58);

SPRITE_LEFTTOP e_pSprStageSelection[] = {
	SPRITE_LEFTTOP(TEX_STAGE_SELECT00_LEFT, 0, 0, PAGE_WIDTH, PAGE_HEIGHT),
	SPRITE_LEFTTOP(TEX_STAGE_SELECT00_RIGHT, 0, 0, PAGE_WIDTH, PAGE_HEIGHT),
	SPRITE_LEFTTOP(TEX_STAGE_SELECT01_LEFT, 0, 0, PAGE_WIDTH, PAGE_HEIGHT),
	SPRITE_LEFTTOP(TEX_STAGE_SELECT01_RIGHT, 0, 0, PAGE_WIDTH, PAGE_HEIGHT),
	SPRITE_LEFTTOP(-1, 0, 0, 0, 0),
};

SPRITE_CENTER e_sprStageSelected = SPRITE_CENTER(TEX_STAGE_SELECTED, 0, 0, 128, 17);

SPRITE_CENTER e_sprClearMark = SPRITE_CENTER(TEX_CLEAR_MARK, 0, 0, 57, 32);

// Effect関係
SPRITE_CENTER e_sprWhiteCircle = SPRITE_CENTER(TEX_WHITE_CIRCLE, 0, 0, 32, 32);
SPRITE_CENTER e_sprHitObj = SPRITE_CENTER(TEX_SMOKE, 0, 0, 64, 64);

SPRITE_CENTER e_pAnimeStamp[] =
{
	SPRITE_CENTER(TEX_ANIME_STAMP,111 * 0,0,111,126,20),
	SPRITE_CENTER(TEX_ANIME_STAMP,111 * 1,0,111,126,8),
	SPRITE_CENTER(TEX_ANIME_STAMP,111 * 2,0,111,126,8),
	SPRITE_CENTER(TEX_ANIME_STAMP,111 * 3,0,111,126,8),
	SPRITE_CENTER(TEX_ANIME_STAMP,111 * 4,0,111,126,8),
	SPRITE_CENTER(TEX_ANIME_STAMP,111 * 5,0,111,126,8),
	SPRITE_CENTER(TEX_ANIME_STAMP,111 * 6,0,111,126,50),
	SPRITE_CENTER(-1, 0, 0, 0, 0),
};

SPRITE_BOTTOM e_pAnimeEffJumpUp[] = {
	SPRITE_BOTTOM(TEX_EFF_JUMP_UP, 290 * 0, 0, 290, 143, 8),
	SPRITE_BOTTOM(TEX_EFF_JUMP_UP, 290 * 1, 0, 290, 143, 8),
	SPRITE_BOTTOM(TEX_EFF_JUMP_UP, 290 * 2, 0, 290, 143, 8),
	//SPRITE_BOTTOM(TEX_EFF_JUMP_UP, 290 * 3, 0, 290, 143, 6),
	SPRITE_BOTTOM(-1, 0, 0, 0, 0)
};
SPRITE_BOTTOM e_pAnimeEffJumpDown[] = {
	SPRITE_BOTTOM(TEX_EFF_JUMP_DOWN, 143 * 0, 0, 143, 23, 6),
	SPRITE_BOTTOM(TEX_EFF_JUMP_DOWN, 143 * 1, 0, 143, 23, 6),
	SPRITE_BOTTOM(TEX_EFF_JUMP_DOWN, 143 * 2, 0, 143, 23, 6),
	SPRITE_BOTTOM(TEX_EFF_JUMP_DOWN, 143 * 3, 0, 143, 23, 6),
	SPRITE_BOTTOM(-1, 0, 0, 0, 0),
};
SPRITE_BOTTOM e_pAnimeEffRecoveryPassed[] = {
	SPRITE_BOTTOM(TEX_EFF_RECOVERY_PASSED, 59 * 0, 0, 59, 69, 6),
	SPRITE_BOTTOM(TEX_EFF_RECOVERY_PASSED, 59 * 1, 0, 59, 69, 6),
	SPRITE_BOTTOM(TEX_EFF_RECOVERY_PASSED, 59 * 2, 0, 59, 69, 6),
	SPRITE_BOTTOM(TEX_EFF_RECOVERY_PASSED, 59 * 3, 0, 59, 69, 6),
	SPRITE_BOTTOM(-1, 0, 0, 0, 0),
};

SPRITE_CENTER e_pAnimeEffDisappear[] = {
	SPRITE_CENTER(TEX_EFF_DISAPPEAR, 236 * 0, 0, 236, 206, 5),
	SPRITE_CENTER(TEX_EFF_DISAPPEAR, 236 * 1, 0, 236, 206, 5),
	SPRITE_CENTER(TEX_EFF_DISAPPEAR, 236 * 2, 0, 236, 206, 5),
	SPRITE_CENTER(TEX_EFF_DISAPPEAR, 236 * 3, 0, 236, 206, 5),
	SPRITE_CENTER(-1, 0, 0, 0, 0),
};

SPRITE_CENTER e_pAnimeEffMakeTranscription[] = {
	SPRITE_CENTER(TEX_EFF_MAKE_TRANSCRIPTION, 246 * 6, 0, 246, 214, 2),
	SPRITE_CENTER(TEX_EFF_MAKE_TRANSCRIPTION, 246 * 5, 0, 246, 214, 2),
	SPRITE_CENTER(TEX_EFF_MAKE_TRANSCRIPTION, 246 * 4, 0, 246, 214, 2),
	SPRITE_CENTER(TEX_EFF_MAKE_TRANSCRIPTION, 246 * 3, 0, 246, 214, 2),
	SPRITE_CENTER(TEX_EFF_MAKE_TRANSCRIPTION, 246 * 2, 0, 246, 214, 2),
	SPRITE_CENTER(TEX_EFF_MAKE_TRANSCRIPTION, 246 * 1, 0, 246, 214, 2),
	SPRITE_CENTER(TEX_EFF_MAKE_TRANSCRIPTION, 246 * 0, 0, 246, 214, 2),
	SPRITE_CENTER(-1, 0, 0, 0, 0),
};

SPRITE_BOTTOM e_pAnimeEffDamaging[] = {
	SPRITE_BOTTOM(TEX_EFF_DAMAGING, 82 * 0, 0, 82, 83, 8),
	SPRITE_BOTTOM(TEX_EFF_DAMAGING, 82 * 1, 0, 82, 83, 8),
	SPRITE_BOTTOM(TEX_EFF_DAMAGING, 82 * 2, 0, 82, 83, 8),
	SPRITE_BOTTOM(TEX_EFF_DAMAGING, 82 * 3, 0, 82, 83, 8),
	SPRITE_BOTTOM(-1, 0, 0, 0, 0),
};

SPRITE_BOTTOM e_pAnimeEffRunning[] = {
	SPRITE_BOTTOM(TEX_EFF_RUNNING, 120 * 0, 0, 120, 22, 2),
	SPRITE_BOTTOM(TEX_EFF_RUNNING, 120 * 1, 0, 120, 22, 2),
	SPRITE_BOTTOM(TEX_EFF_RUNNING, 120 * 2, 0, 120, 22, 2),
	SPRITE_BOTTOM(TEX_EFF_RUNNING, 120 * 3, 0, 120, 22, 2),
	SPRITE_BOTTOM(TEX_EFF_RUNNING, 120 * 4, 0, 120, 22, 2),
	SPRITE_BOTTOM(-1, 0, 0, 0, 0),
};

SPRITE_BOTTOM e_pAnimeEffOnBlurArea[] = {
	SPRITE_BOTTOM(TEX_EFF_ON_BLUR_AREA, 0, 0, 28, 6),
	//SPRITE_BOTTOM(TEX_EFF_ON_BLUR_AREA, 85 * 1, 0, 85, 80, 4),
	//SPRITE_BOTTOM(TEX_EFF_ON_BLUR_AREA, 85 * 2, 0, 85, 80, 4),
	//SPRITE_BOTTOM(TEX_EFF_ON_BLUR_AREA, 85 * 3, 0, 85, 80, 4),
	SPRITE_BOTTOM(-1, 0, 0, 0, 0),
};

SPRITE_BOTTOM e_sprEffStamp = SPRITE_BOTTOM(TEX_EFF_STAMP_AND_SHADOW, 0, 0, 105, 102);
SPRITE_BOTTOM e_sprEffStampShadow = SPRITE_BOTTOM(TEX_EFF_STAMP_AND_SHADOW, 0, 102, 112, 104);

SPRITE_BOTTOM e_pAnimeEffStar[] = {
	SPRITE_BOTTOM(TEX_EFF_STAR, 84 * 0, 0, 84, 75, 10),
	SPRITE_BOTTOM(TEX_EFF_STAR, 84 * 1, 0, 84, 75, 10),
	SPRITE_BOTTOM(TEX_EFF_STAR, 84 * 2, 0, 84, 75, 10),
	SPRITE_BOTTOM(TEX_EFF_STAR, 84 * 3, 0, 84, 75, 10),
	SPRITE_BOTTOM(-1, 0, 0, 0, 0),
};

SPRITE_CENTER e_pAnimeEffCloseBook[] = {
	SPRITE_CENTER(TEX_EFF_CLOSE_BOOK, 398 * 0, 0, 398, 354, 3),
	SPRITE_CENTER(TEX_EFF_CLOSE_BOOK, 398 * 1, 0, 398, 354, 4),
	SPRITE_CENTER(TEX_EFF_CLOSE_BOOK, 398 * 2, 0, 398, 354, 8),
	SPRITE_CENTER(TEX_EFF_CLOSE_BOOK, 398 * 3, 0, 398, 354, 6),
	SPRITE_CENTER(-1, 0, 0, 0, 0),
};

SPRITE_CENTER e_pAnimeEffGageOnBlurArea[] = {
	SPRITE_CENTER(TEX_EFF_GAGE_ON_BLUR_AREA, 382 * 0, 0, 382, 68, 6),
	SPRITE_CENTER(TEX_EFF_GAGE_ON_BLUR_AREA, 382 * 1, 0, 382, 68, 8),
	SPRITE_CENTER(TEX_EFF_GAGE_ON_BLUR_AREA, 382 * 2, 0, 382, 68, 10),
	SPRITE_CENTER(TEX_EFF_GAGE_ON_BLUR_AREA, 382 * 3, 0, 382, 68, 8),
	SPRITE_CENTER(TEX_EFF_GAGE_ON_BLUR_AREA, 382 * 4, 0, 382, 68, 6),
	SPRITE_CENTER(-1, 0, 0, 0, 0),
};

SPRITE_CENTER e_sprEffBookAura = SPRITE_CENTER(TEX_EFF_BOOK_AURA, 0, 0, 686, 766);

SPRITE_LEFTTOP e_pSprEffGoal[] = {
	SPRITE_LEFTTOP(TEX_EFF_GOAL, 100,   0, 111,  99),
	SPRITE_LEFTTOP(TEX_EFF_GOAL, 100,  99, 117, 131),
	SPRITE_LEFTTOP(TEX_EFF_GOAL, 100, 232, 101, 131),
	SPRITE_LEFTTOP(TEX_EFF_GOAL, 100, 361, 100, 129),
	SPRITE_LEFTTOP(TEX_EFF_GOAL, 100, 460, 128,  99),
	SPRITE_LEFTTOP(-1, 0, 0, 0, 0),
};

SPRITE_BOTTOM e_sprEffPlayerBorder = SPRITE_BOTTOM(TEX_EFF_PLAYER_BORDER, 0, 0, 0, 0);

SPRITE_CENTER e_pSprEffSpirals[] = {
	SPRITE_CENTER(TEX_EFF_SPIRALS, 0, 80 * 0, 80, 80),
	SPRITE_CENTER(TEX_EFF_SPIRALS, 0, 80 * 1, 80, 80),
	SPRITE_CENTER(TEX_EFF_SPIRALS, 0, 80 * 2, 80, 80),
	SPRITE_CENTER(TEX_EFF_SPIRALS, 0, 80 * 3, 80, 80),
	SPRITE_CENTER(-1, 0, 0, 0, 0),
};

SPRITE_CENTER e_pAnimeEffClearStar[] = {
	SPRITE_CENTER(TEX_EFF_CLEAR_STAR, 200 * 0, 0, 200, 189, 6),
	SPRITE_CENTER(TEX_EFF_CLEAR_STAR, 200 * 1, 0, 200, 189, 6),
	SPRITE_CENTER(TEX_EFF_CLEAR_STAR, 200 * 2, 0, 200, 189, 6),
	SPRITE_CENTER(TEX_EFF_CLEAR_STAR, 200 * 3, 0, 200, 189, 6),
	SPRITE_CENTER(TEX_EFF_CLEAR_STAR, 200 * 4, 0, 200, 189, 6),
	SPRITE_CENTER(-1, 0, 0, 0, 0),
};

SPRITE_CENTER e_pAnimeEffFirework[] = {
	SPRITE_CENTER(TEX_EFF_CLEAR_STAR, 486 * 0, 0, 486, 645, 4),
	SPRITE_CENTER(TEX_EFF_CLEAR_STAR, 486 * 1, 0, 486, 645, 4),
	SPRITE_CENTER(TEX_EFF_CLEAR_STAR, 486 * 2, 0, 486, 645, 4),
	SPRITE_CENTER(TEX_EFF_CLEAR_STAR, 486 * 3, 0, 486, 645, 4),
	SPRITE_CENTER(TEX_EFF_CLEAR_STAR, 486 * 4, 0, 486, 645, 4),
	SPRITE_CENTER(TEX_EFF_CLEAR_STAR, 486 * 5, 0, 486, 645, 4),
	SPRITE_CENTER(TEX_EFF_CLEAR_STAR, 486 * 6, 0, 486, 645, 4),
	SPRITE_CENTER(TEX_EFF_CLEAR_STAR, 486 * 7, 0, 486, 645, 4),
	SPRITE_CENTER(TEX_EFF_CLEAR_STAR, 486 * 8, 0, 486, 645, 4),
	SPRITE_CENTER(TEX_EFF_CLEAR_STAR, 486 * 9, 0, 486, 645, 4),
	SPRITE_CENTER(TEX_EFF_CLEAR_STAR, 486 * 10, 0, 486, 645, 4),
	SPRITE_CENTER(-1, 0, 0, 0, 0),
};

//******************************************************************************
