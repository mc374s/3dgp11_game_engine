﻿#include "game.h"
#include "sprite_data.h"
#include "stage_data.h"

#include "paper.h"
#include "book.h"

#include "map_obj.h"

void MapObj::memberCopy(const MapObj& a_inputObj)
{
	OBJ2DEX::memberCopy(a_inputObj);
	m_command = a_inputObj.m_command;
	m_drawDirection = a_inputObj.m_drawDirection;
	m_isHitAble = a_inputObj.m_isHitAble;
	m_repeatDrawSize = a_inputObj.m_repeatDrawSize;
	m_pfMove = a_inputObj.m_pfMove;

	m_initConcentration = a_inputObj.m_initConcentration;

	m_isVisibleAlways = a_inputObj.m_isVisibleAlways;
	m_isVisible = a_inputObj.m_isVisible;

}

MapObj::MapObj()
{
	clear();
}

MapObj::MapObj(const MapObj& a_inputObj):OBJ2DEX(a_inputObj)
{
	memberCopy(a_inputObj);
	
}

MapObj::~MapObj()
{
	clear();
}

const MapObj& MapObj::operator=(const MapObj& a_right)
{
	memberCopy(a_right);
	return *this;
}


void MapObj::clear()
{
	OBJ2DEX::clear();
	m_pfMove = nullptr;
	m_command = 0x0;
	m_concentration = 10;
	m_drawDirection = M_DRAW::UP;
	m_repeatDrawSize = Vector3(0, 0, 0);
	m_size = Vector3(0, 0, 0);
	m_isHitAble = false;
	m_isVisibleAlways = true;
	m_isVisible = true;
}

// stageData による初期化
void MapObj::init()
{
	m_isInit = true;
	m_initPos = m_pos;
	m_pSprData = &e_pSprItem[m_type];
	m_initConcentration = m_concentration;

	switch (m_type)
	{
	case M_TYPE::HOUSE:
	case M_TYPE::TREE_A:
	case M_TYPE::TREE_B:

	case M_TYPE::GAME_RULE_LEFT:
	case M_TYPE::GAME_RULE_RIGHT:

	case M_TYPE::IVY_BIG:
	case M_TYPE::KEY:
	case M_TYPE::DOOR:
		m_repeatDrawSize = { m_pSprData->width,m_pSprData->height,0 };
		break;
	case M_TYPE::IVY_THIN:
	case M_TYPE::IVY_THICK:
		m_repeatDrawSize = m_size;
		break;
	case M_TYPE::RECOVERY_UP:
	case M_TYPE::RECOVERY_DOWN:
		m_repeatDrawSize = m_size;
		m_repeatDrawSize.y = m_pSprData->height;
		m_pAnimeData = e_pAnimeRecovery;
		//m_isVisibleAlways = true;
		//m_isVisible = true;
		break;
	case M_TYPE::HIGH_CONCENTRATION:
		m_repeatDrawSize = m_size;
		m_custom.rgba = 0xFF0000FF;
		m_alpha = 255 * m_concentration / P_CONCENTRATION_MAX;
		break;
	default:
		break;
	}

	switch (m_drawDirection)
	{
	case M_DRAW::DOWN:
		m_custom.reflectX = true;
		m_custom.angle = 180;
		break;
	case M_DRAW::LEFT:
		m_custom.angle = -90;
		m_repeatDrawSize.x = m_size.y;
		m_repeatDrawSize.y = m_size.x;
		break;
	case M_DRAW::RIGHT:
		m_custom.reflectX = true;
		m_custom.angle = 90;
		m_repeatDrawSize.x = m_size.y;
		m_repeatDrawSize.y = m_size.x;
		break;
	default:
		break;
	}
}


void MapObj::update()
{
	if (m_pfMove){
		m_pfMove(this);
	}
	animation();
}
void MapObj::safeInit(MapObj& a_objIn, int a_liveInPagination, M_TYPE a_mapObjType, M_DRAW a_drawDirection, Vector3 a_pos, bool a_isHitAble, Vector3 a_size, int a_concentration, void(*a_pfMove)(MapObj*))
{

	a_objIn.clear();
	a_objIn.m_liveInPagination = a_liveInPagination;
	a_objIn.m_type = a_mapObjType;
	a_objIn.m_drawDirection = a_drawDirection;
	a_objIn.m_pos = a_pos;
	a_objIn.m_isHitAble = a_isHitAble;
	a_objIn.m_size = a_size;
	a_objIn.m_concentration = a_concentration;
	a_objIn.m_pfMove = a_pfMove;
	a_objIn.init();
}

void MapObj::hitAdjust(OBJ2DEX* a_pObj)
{
	// objがthisの上にある(thisを上から進入としてる)
	if (a_pObj->m_pos.y - a_pObj->m_size.y < m_pos.y && a_pObj->m_pos.y > m_pos.y
		&& fabs(a_pObj->m_pos.x - m_pos.x - m_size.x / 2) < (a_pObj->m_size.x + m_size.x) / 2 && a_pObj->m_speed.y > 0)
	{
		a_pObj->m_pos.y = m_pos.y - 0.1f;
		a_pObj->m_speed.y = 0;
	}
	// objがthisの下にある(thisを下から進入としてる)
	else if (a_pObj->m_pos.y - a_pObj->m_size.y < m_pos.y + m_size.y && a_pObj->m_pos.y>m_pos.y + m_size.y 
		&& fabs(a_pObj->m_pos.x - m_pos.x - m_size.x / 2) < (a_pObj->m_size.x + m_size.x) / 2 && a_pObj->m_speed.y < 0)
	{
		a_pObj->m_pos.y = m_pos.y + m_size.y + a_pObj->m_size.y + 0.1f;
		a_pObj->m_speed.y = 0;
	}
	// objがthisの左にある(thisを右から進入としてる)
	else if (a_pObj->m_pos.x - a_pObj->m_size.x / 2 < m_pos.x && a_pObj->m_pos.x + a_pObj->m_size.x / 2 > m_pos.x
		&& fabs(a_pObj->m_pos.y - m_pos.y - (m_size.y + a_pObj->m_size.y) / 2) < (a_pObj->m_size.y + m_size.y) / 2 && a_pObj->m_speed.x > 0)
	{
		a_pObj->m_pos.x = m_pos.x - a_pObj->m_size.x / 2 - 0.1f;
		//a_pObj->m_speed.y = 0;
		a_pObj->m_speed.x = 0;
	}
	// objがthisの右にある(thisを左から進入としてる)
	else if (a_pObj->m_pos.x + a_pObj->m_size.x / 2 > m_pos.x + m_size.x && a_pObj->m_pos.x - a_pObj->m_size.x / 2 < m_pos.x + m_size.x
		&& fabs(a_pObj->m_pos.y - m_pos.y - (m_size.y + a_pObj->m_size.y) / 2) < (a_pObj->m_size.y + m_size.y) / 2 && a_pObj->m_speed.x < 0)
	{
		a_pObj->m_pos.x = m_pos.x + m_size.x + a_pObj->m_size.x / 2 + 0.1f;
		//a_pObj->m_speed.y = 0;
		a_pObj->m_speed.x = 0;
	}
}

void MapObj::draw()
{
#ifdef DEBUG

	drawRectangle(m_pos.x, m_pos.y, m_size.x, m_size.y, 0, 0xFFFFFF40);
	drawRectangle(m_pos.x, m_pos.y, m_size.x, m_size.y, 0, 0xFFFFFF40);

#endif // DEBUG

	if (m_type == M_TYPE::RECOVERY_DOWN || m_type == M_TYPE::RECOVERY_UP) {
		m_alpha = 255 * m_concentration / P_CONCENTRATION_MAX + 180;
	}
	else{
		m_alpha = 255 * m_concentration / P_CONCENTRATION_MAX;
	}

	// 繰り返し描画のため、一旦SPRITE_BOTTOMの初期データを保存
	int sprWidth = m_pSprData->width;
	int sprHeight = m_pSprData->height;

	m_pSprData->width = m_repeatDrawSize.x;
	m_pSprData->height = m_repeatDrawSize.y;
	if (m_drawDirection == M_DRAW::LEFT || m_drawDirection == M_DRAW::RIGHT)
	{
		m_pSprData->ofsX = -m_pSprData->width / 2 + m_pSprData->height / 2;
		m_pSprData->ofsY = -m_pSprData->ofsX;
	}

	// 繰り返し描画開始
	OBJ2DEX::draw();
	// 繰り返し描画終了

	// SPRITE_BOTTONのデータを初期に戻す
	m_pSprData->width = sprWidth;
	m_pSprData->height = sprHeight;
	m_pSprData->ofsX = 0;
	m_pSprData->ofsY = 0;


#ifdef DEBUG

	drawRectangle(m_pos.x, m_pos.y, 4, 4, 0, 0x0000FFFF);

#endif // DEBUG

}



STAGE_DATA* stageSetData[] = {
	stage00_setData,
	stage01_setData,
	stage02_setData,
	stage03_setData,
	stage04_setData,
	stage05_setData,
	stage06_setData,
};


StageManager::StageManager()
{

}

StageManager::~StageManager() 
{
}


void StageManager::init(int a_stageNO)
{
	m_stageNO = a_stageNO;
	m_timer = 0;
	m_pStageData = stageSetData[m_stageNO];
	STAGE_HEIGHT = e_stageHeight[m_stageNO];
	START_PAGINATION = e_startPagination[m_stageNO];
	INIT_POS = e_initPos[m_stageNO];
	P_LIFE_MAX = e_initLife[m_stageNO];

	pBook->initStartPaper(START_PAGINATION / 2);

}

void StageManager::update()
{
	if (m_pStageData)
	{
		m_timer++;
		while (m_pStageData && m_pStageData->appearTime <= m_timer)
		{
			if (m_pStageData->appearTime < 0) {
				m_pStageData = nullptr;
				m_timer = 0;
				break;
			}
			MapObj::safeInit(m_mapObj, m_pStageData->m_liveInPagination, m_pStageData->mapObjType, m_pStageData->drawDirection, m_pStageData->pos, m_pStageData->isHitAble, m_pStageData->size, m_pStageData->concentration, m_pStageData->pfMove);

			pBook->m_ppPapers[m_mapObj.m_liveInPagination / 2]->m_mapObjList[m_mapObj.m_liveInPagination % 2].push_back(m_mapObj);

			m_pStageData++;
		}
	}
}


void recoveryControl(MapObj* a_pObj)
{
	if (a_pObj->m_concentration <= 0)
	{
		a_pObj->m_timer++;
	}
	if (a_pObj->m_timer > 180)
	{
		a_pObj->m_timer = 0;
		a_pObj->m_concentration = a_pObj->m_initConcentration;
	}
}