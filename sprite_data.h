#ifndef _SPRDATA_H_
#define	_SPRDATA_H_

// ラベル定義
enum TEX_NO {
	TEX_COVER_FRONT,
	TEX_COVER_BACK,
	TEX_PAGE,

	TEX_WHITE,
	TEX_WHITE_CIRCLE,
	TEX_MAIN,
	TEX_PLAYER,
	TEX_PLAYER_EYES,
	TEX_PLAYER_LARGE,

	TEX_BORDER_INNER,
	TEX_PASSABLE,
	TEX_RECOVERY,
	TEX_MAP_OBJ_FOREST,
	TEX_MAP_OBJ_BIRD,
	TEX_MAP_OBJ_GRAVE,
	TEX_MAP_OBJ_SNOW,
	TEX_MAP_OBJ_DESERT,
	TEX_TUTORIAL,
	TEX_GOAL_SET,
	TEX_PASSABLE_ARROW,

	TEX_SMOKE,
	TEX_LIFE_STAMP,

	TEX_NUMBERS,

	TEX_PAUSE_PANEL,
	TEX_PAUSE_SELECTED,
	TEX_RETRY_PANEL,

	TEX_ANIME_STAMP,

	TEX_GAGE_DIVISION_ALLOCATION,
	TEX_GAGE_DIVISION,
	TEX_GAGE_DIVISION_WHITE,
	TEX_ANIME_GAGE,
	TEX_PLAYER_FACE,

	TEX_EFF_DISAPPEAR,
	TEX_EFF_JUMP_UP,
	TEX_EFF_JUMP_DOWN,
	TEX_EFF_MAKE_TRANSCRIPTION,
	TEX_EFF_RECOVERY_PASSED,
	TEX_EFF_DAMAGING,
	TEX_EFF_RUNNING,
	TEX_EFF_ON_BLUR_AREA,
	TEX_EFF_STAMP_AND_SHADOW,
	TEX_EFF_STAR,
	TEX_EFF_CLOSE_BOOK,
	TEX_EFF_GAGE_ON_BLUR_AREA,
	TEX_EFF_BOOK_AURA,
	TEX_EFF_GOAL,
	TEX_EFF_PLAYER_BORDER,
	TEX_EFF_SPIRALS,
	TEX_EFF_CLEAR_STAR,
	TEX_EFF_FIREWORK,

	TEX_GAME_RULE_LEFT,
	TEX_GAME_RULE_RIGHT,

	TEX_HELP,
	TEX_HELP_BUTTON,

	TEX_X_BUTTON,

	TEX_SCROLL_MODE,
	TEX_SCROLL_ARROW,

	TEX_STAGE_CLEAR,
	TEX_GAME_CLEAR,
	TEX_GAME_OVER,
	TEX_STAGE_CLEAR_BEHIND,
	TEX_STAGE_CLEAR_FRONT,
	TEX_GAME_OVER_BEHIND,
	TEX_GAME_OVER_FRONT,
	TEX_CLEAR_MARK,

	TEX_STAGE_SELECT00_LEFT,
	TEX_STAGE_SELECT00_RIGHT,
	TEX_STAGE_SELECT01_LEFT,
	TEX_STAGE_SELECT01_RIGHT,

	TEX_STAGE_INTRO01_LEFT,
	TEX_STAGE_INTRO01_RIGHT,
	TEX_STAGE_INTRO02_LEFT,
	TEX_STAGE_INTRO02_RIGHT,
	TEX_STAGE_INTRO03_LEFT,
	TEX_STAGE_INTRO03_RIGHT,
	TEX_STAGE_INTRO04_LEFT,
	TEX_STAGE_INTRO04_RIGHT,
	TEX_STAGE_INTRO05_LEFT,
	TEX_STAGE_INTRO05_RIGHT,

	TEX_STAGE_SELECTED,

};


extern LOAD_TEXTURE e_loadTexture[];

// 背景
extern SPRITE_LEFTTOP e_sprMainBG;

// Book texture
extern SPRITE_LEFTTOP e_sprCoverFront;
extern SPRITE_LEFTTOP e_sprCoverBack;
extern SPRITE_LEFTTOP e_sprPage;

// キャラなど
//extern SPRITE_BOTTOM e_pSprPlayerStandby[];
//extern SPRITE_BOTTOM* e_pAnimePlayerStandby[][9];


extern SPRITE_BOTTOM e_pAnimePlayerStandby[];
extern SPRITE_BOTTOM e_pAnimePlayerYawn[];

extern SPRITE_BOTTOM e_pAnimePlayerRun[];
extern SPRITE_BOTTOM e_pAnimePlayerJump[];

extern SPRITE_BOTTOM e_sprEyes;

// マップ関係、アイテム
extern SPRITE_LEFTTOP e_pSprItem[];
extern SPRITE_LEFTTOP e_pAnimeRecovery[];


// UI関係
extern SPRITE_LEFTTOP e_sprWhite;
extern SPRITE_CENTER e_sprGageAllocation;
extern SPRITE_CENTER e_sprGageDivisionAllocation;
extern SPRITE_CENTER sprGageAllocationUnder;
extern SPRITE_BOTTOM e_sprLargePlayer;

extern SPRITE_LEFTTOP e_pSprPlayerFace[];
extern SPRITE_LEFTTOP e_sprGageDivision;
extern SPRITE_LEFTTOP e_sprGageDivisionWhite;
extern SPRITE_LEFTTOP e_sprGageUnder;
extern SPRITE_LEFTTOP e_sprGage;
extern SPRITE_LEFTTOP e_pAnimeGage[];
extern SPRITE_LEFTTOP e_sprLifeStamp;


extern SPRITE_CENTER e_sprNumbers;

extern SPRITE_CENTER e_sprPausePanel;
extern SPRITE_CENTER e_sprPauseSelected;
extern SPRITE_CENTER e_sprRetryPanel;

extern SPRITE_CENTER e_sprStageClear;
extern SPRITE_CENTER e_sprGameClear;
extern SPRITE_CENTER e_sprGameOver;
extern SPRITE_CENTER e_sprStageClearBehind;
extern SPRITE_CENTER e_sprStageClearFront;
extern SPRITE_CENTER e_sprGameOverBehind;
extern SPRITE_CENTER e_sprGameOverFront;

extern SPRITE_CENTER e_sprHelp;
extern SPRITE_LEFTTOP e_sprHelpButton;
extern SPRITE_CENTER e_sprXButton;

extern SPRITE_LEFTTOP e_sprScrollMode;
extern SPRITE_CENTER e_sprScrollArrow;

extern SPRITE_LEFTTOP e_pSprStageSelection[];
extern SPRITE_CENTER e_sprStageSelected;

extern SPRITE_CENTER e_sprClearMark;

// Effect関係
extern SPRITE_CENTER e_sprWhiteCircle;

extern SPRITE_CENTER e_sprHitObj;

extern SPRITE_CENTER e_pAnimeStamp[];
extern SPRITE_BOTTOM e_pAnimeEffJumpUp[];
extern SPRITE_BOTTOM e_pAnimeEffJumpDown[];

extern SPRITE_BOTTOM e_pAnimeEffRecoveryPassed[];

extern SPRITE_CENTER e_pAnimeEffDisappear[];
extern SPRITE_CENTER e_pAnimeEffMakeTranscription[];

extern SPRITE_BOTTOM e_pAnimeEffDamaging[];
extern SPRITE_BOTTOM e_pAnimeEffRunning[];
extern SPRITE_BOTTOM e_pAnimeEffOnBlurArea[];

extern SPRITE_BOTTOM e_sprEffStamp;
extern SPRITE_BOTTOM e_sprEffStampShadow;

extern SPRITE_BOTTOM e_pAnimeEffStar[];
extern SPRITE_CENTER e_pAnimeEffCloseBook[];

extern SPRITE_CENTER e_pAnimeEffGageOnBlurArea[];

extern SPRITE_CENTER e_sprEffBookAura;

extern SPRITE_LEFTTOP e_pSprEffGoal[];

extern SPRITE_BOTTOM e_sprEffPlayerBorder;

extern SPRITE_CENTER e_pSprEffSpirals[];
extern SPRITE_CENTER e_pAnimeEffClearStar[];
extern SPRITE_CENTER e_pAnimeEffFirework[];

#endif // !_SPRDATA_H_
