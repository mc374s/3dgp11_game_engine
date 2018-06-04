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
extern SPRITE_CENTER e_sprGageTranscription;
extern SPRITE_CENTER e_sprGageDivisionTranscription;
extern SPRITE_CENTER e_sprLifeStamp;
extern SPRITE_CENTER e_sprLargePlayer;

extern SPRITE_LEFTTOP e_sprGage;
extern SPRITE_LEFTTOP e_sprGageDivision;

extern SPRITE_CENTER e_sprNumbers;

extern SPRITE_CENTER e_sprPausePanel;
extern SPRITE_CENTER e_sprPauseSelected;

extern SPRITE_LEFTTOP e_sprTestPlayText;

extern SPRITE_CENTER e_pAnimeStamp[];

// Effect関係
extern SPRITE_CENTER e_sprHitObj;

#endif // !_SPRDATA_H_
