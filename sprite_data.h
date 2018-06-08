#ifndef _SPRDATA_H_
#define	_SPRDATA_H_

extern LOAD_TEXTURE e_loadTexture[];

// 背景
extern SPRITE_LEFTTOP	e_sprTitleBG;
extern SPRITE_LEFTTOP	e_sprMainBG;

// Book texture
extern SPRITE_LEFTTOP e_sprCoverFront;
extern SPRITE_LEFTTOP e_sprCoverBack;
extern SPRITE_LEFTTOP e_sprPageLeft;
extern SPRITE_LEFTTOP e_sprPageRight;

// キャラなど
//extern SPRITE_BOTTOM e_pSprPlayerStandby[];
//extern SPRITE_BOTTOM* e_pAnimePlayerStandby[][9];


extern SPRITE_BOTTOM e_pAnimePlayerStandby[];
extern SPRITE_BOTTOM e_pAnimePlayerYawn[];

extern SPRITE_BOTTOM e_pAnimePlayerRun[];
extern SPRITE_BOTTOM e_pAnimePlayerJump[];

// マップ関係、アイテム
extern SPRITE_LEFTTOP e_pSprItem[];
extern SPRITE_LEFTTOP e_pAnimeRecoveryUp[];
extern SPRITE_LEFTTOP e_pAnimeRecoveryDown[];


// UI関係
extern SPRITE_LEFTTOP e_sprWhite;
extern SPRITE_CENTER e_sprGageAllocation;
extern SPRITE_CENTER e_sprGageDivisionAllocation;
extern SPRITE_CENTER e_sprLargePlayer;

extern SPRITE_LEFTTOP e_pSprPlayerFace[];
extern SPRITE_LEFTTOP e_sprGageDivision;
extern SPRITE_LEFTTOP e_sprGage;
extern SPRITE_LEFTTOP e_pAnimeGage[];
extern SPRITE_LEFTTOP e_sprLifeStamp;


extern SPRITE_CENTER e_sprNumbers;

extern SPRITE_CENTER e_sprPausePanel;
extern SPRITE_CENTER e_sprPauseSelected;

extern SPRITE_LEFTTOP e_sprTestPlayText;


// Effect関係
extern SPRITE_CENTER e_sprHitObj;

extern SPRITE_CENTER e_pAnimeStamp[];
extern SPRITE_BOTTOM e_pAnimeEffDisappear[];
extern SPRITE_BOTTOM e_pAnimeEffJumpUp[];
extern SPRITE_BOTTOM e_pAnimeEffJumpDown[];
extern SPRITE_BOTTOM e_pAnimeEffMakeTranscription[];

#endif // !_SPRDATA_H_
