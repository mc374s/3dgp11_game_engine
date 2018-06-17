﻿#include "game.h"
#include "map_obj.h"

#include "stage_data.h"

int e_stageHeight[] = {
	0,////ステージセレクトダミーデータ
	0,////ステージセレクトダミーデータ

	0,////チュートリアルダミーデータ

	0,
	0,
	(840) - (PH - 100),
	0,
	(900) - (PH - 100),
	(900) - (PH - 100),//6

	(1039) - (PH - 100),//7

	(5000) - (PH-100),//8
	(840) - (PH - 100),
	0,
	(900) - (PH - 100),
	(1039) - (PH - 100),//13

	0,//14
	0,
	(840) - (PH - 100),
	0,
	(900) - (PH - 100),
	(1039) - (PH - 100),//19

};

int e_startPagination[] = {
	3,////ステージ 1-1~4-3 セレクトページ目
	5,////ステージ 5-1~8-3 セレクトページ目


	11 - 4,//チュートリアルのページ目

	17 - 4,
	23 - 4,

	29 - 4,
	35 - 4,
	41 - 4,

	47 - 4,
	67 - 4,
	73 - 4,

	79 - 4,
	85 - 4,
	91 - 4,

	97 - 4,
	117 - 4,
	123 - 4,

	//129-4,
	//135-4,
	//141-4,
	//147-4,
};

v3 e_initPos[] = {
	{ 80,300,5 },////ステージセレクトダミーデータ
{ 80,300,5 },////ステージセレクトダミーデータ


{ 80,300,5 },////チュートリアルダミーデータ

{ 80,250,5 },//1
{ 80,580,5 },//2
{ 80,180,5 },//3
{ 80,180,5 },//4
{ 80,400,5 },//5
{ 80,400,5 },//6


{ 80,400,5 },//7
{ 80,100,5 },//
{ 80,180,5 },//
{ 80,180,5 },//
{ 80,400,5 },//
{ 80,400,5 },//12


{ 80,250,5 },//13
{ 80,580,5 },//
{ 80,180,5 },//
{ 80,180,5 },//
{ 80,400,5 },//
{ 80,400,5 },//18
};

int e_initLife[] = {
	1,////ステージセレクトダミーデータ
	1,////ステージセレクトダミーデータ

	1,////チュートリアルダミーデータ

	1,
	1,
	1,
	1,
	1,
	1,

	2,
	2,
	2,
	2,
	2,
	2,

	3,
	3,
	3,
	3,
	3,
	3,
};

const int STAGE_SELECT_MAX_NUM = 2;

const int STAGE_MAX_NUM = ARRAYSIZE(e_startPagination)/*sizeof(e_startPagination) / sizeof(int)*/;


int START_PAGINATION = e_startPagination[0];

int STAGE_HEIGHT = e_stageHeight[0];

v3 INIT_POS = e_initPos[0];

int P_LIFE_MAX = e_initLife[0];


STAGE_DATA* stageSetData[] = {
	stage_select00_setData,
	stage_select01_setData,

	stage00_setData,
	stage01_setData,
	stage02_setData,
	stage03_setData,
	stage04_setData,
	stage05_setData,
	stage06_setData,
	stage07_setData,
	stage08_setData,
	stage09_setData,
	stage10_setData,
	stage11_setData,
	stage12_setData,
	stage13_setData,
	stage14_setData,
	stage15_setData,
	stage16_setData,
	stage17_setData,
	stage18_setData,
};



STAGE_DATA stage00_setData[] = {

	// ページ 左

	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 0], 0, M_TYPE::GAME_RULE_LEFT,				M_DRAW::UP,		v3(0,0,0),					false, v3(0,0,0), 10),


	// ページ 右
	STAGE_DATA(e_startPagination[STAGE_SELECT_MAX_NUM + 0] + 1, 0, M_TYPE::GAME_RULE_RIGHT,		M_DRAW::UP,		v3(0,0,0),					false, v3(0,0,0), 10),


	// END
	STAGE_DATA(-1,-1, M_TYPE::NONE, M_DRAW::UP, v3(0,0,0),false, v3(0,0,0)),
};
