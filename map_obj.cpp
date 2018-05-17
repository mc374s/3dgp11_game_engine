#include "game.h"
#include "sprite_data.h"
#include "stage_data.h"

#include "map_obj.h"

void MapObj::clear()
{
	OBJ2DEX::clear();
	m_pfMove = nullptr;
	m_command = 0x0;
	m_concentration = 10;
	m_drawDirection = DRAW_UP;
	m_repeatDrawSize = Vector3(0, 0, 0);
	m_isHitAble = false;
}

MapObj::MapObj(/*int a_type*/)
{
	clear();
	m_command = 0x0;

}

// stageData による初期化
void MapObj::init()
{
	m_isInit = true;

	m_pSprData = &e_pSprItem[m_type];

	switch (m_type)
	{
	case MAPOBJ_HOUSE:
	case MAPOBJ_TREE_A:
	case MAPOBJ_TREE_B:

	case MAPOBJ_IVY_BIG:
	case MAPOBJ_KEY:
	case MAPOBJ_DOOR:
		m_repeatDrawSize = { m_pSprData->width,m_pSprData->height,0 };
		break;
	case MAPOBJ_IVY_THIN:
	case MAPOBJ_IVY_THICK:
		m_repeatDrawSize = m_size;
		break;
	case MAPOBJ_HIGH_CONCENTRATION:
		m_repeatDrawSize = m_size;
		m_custom.rgba = 0x000000FF;
		m_alpha = 255 * m_concentration / 10;
		break;
	default:
		break;
	}
	switch (m_drawDirection)
	{
	case DRAW_DOWN:
		m_custom.reflectX = true;
		m_custom.angle = 180;
		break;
	case DRAW_LEFT:
		m_custom.angle = -90;
		m_repeatDrawSize.x = m_size.y;
		m_repeatDrawSize.y = m_size.x;
		break;
	case DRAW_RIGHT:
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
	if (m_pfMove)
	{
		m_pfMove(this);

		animation();

	}
}
int MapObj::searchSet(MapObj** a_ppBegin, int a_maxNum, MAPOBJ_TYPE a_mapObjType, DRAW_DIRECTION a_drawDirection, bool a_isOnLeftPage, Vector3 a_pos, bool a_isHitAble, Vector3 a_size, int a_concentration, void(*a_pfMove)(MapObj*))
{
	for (int i = 0; i < a_maxNum; i++)
	{
		if (a_ppBegin[i] && a_ppBegin[i]->m_isInit) {
			continue;
		}
		//a_ppBegin[i] = new MapObj(a_mapObjType);
		a_ppBegin[i]->m_type = a_mapObjType;
		a_ppBegin[i]->m_drawDirection = a_drawDirection;
		a_ppBegin[i]->m_isOnLeftPage = a_isOnLeftPage;
		a_ppBegin[i]->m_pos = a_pos;
		a_ppBegin[i]->m_isHitAble = a_isHitAble;
		a_ppBegin[i]->m_size = a_size;
		a_ppBegin[i]->m_concentration = a_concentration;
		a_ppBegin[i]->m_pfMove = a_pfMove;
		a_ppBegin[i]->init();

		pObjManager->m_ppObj[GET_IDLE_OBJ_NO] = a_ppBegin[i];
		return i;
	}
	return -1;
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


	// 繰り返し描画のため、一旦SPRITE_BOTTOMの初期データを保存
	int sprWidth = m_pSprData->width;
	int sprHeight = m_pSprData->height;

	m_pSprData->width = m_repeatDrawSize.x;
	m_pSprData->height = m_repeatDrawSize.y;
	if (m_drawDirection == DRAW_LEFT || m_drawDirection == DRAW_RIGHT)
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
};


MapObjManager::~MapObjManager() 
{
	for (int i = 0; i < MAPOBJ_MAX_NUM; i++)
	{
		if (m_ppMapObj[i] && !m_ppMapObj[i]->m_isInit)
		{
			delete m_ppMapObj[i];
			m_ppMapObj[i] = nullptr;
		}
	}
}


void MapObjManager::init(int a_stageNo)
{
	m_stageNo = a_stageNo;
	m_timer = 0;
	m_pStageData = stageSetData[m_stageNo];
	for (int i = 0; i < MAPOBJ_MAX_NUM; i++)
	{
		if (m_ppMapObj[i])
		{
			delete m_ppMapObj[i];
			m_ppMapObj[i] = nullptr;
		}
		if (!m_ppMapObj[i])
		{
			m_ppMapObj[i] = new MapObj();
		}
	}

}
void MapObjManager::update()
{
	for (int i = 0; i < MAPOBJ_MAX_NUM; i++)
	{
		if (m_ppMapObj[i] && m_ppMapObj[i]->m_pfMove && m_ppMapObj[i]->m_state >= STATE_END + 2)
		{
			m_ppMapObj[i]->m_pfMove(m_ppMapObj[i]);
		}
	}
}

void MapObjManager::draw()
{
	int num = 0;
	for (int i = 0; i < MAPOBJ_MAX_NUM; i++)
	{
		if (m_ppMapObj[i] && m_ppMapObj[i]->m_isInit)
		{
			num++;
		}
	}
#ifdef DEBUG

	char buf[256];
	sprintf_s(buf, "MapObj Num: %d\n", num);
	drawString(0, 150, buf, 0x000000FF);

#endif // DEBUG
}

void MapObjManager::stageUpdate()
{
	m_timer++;

	while (m_pStageData && m_pStageData->appearTime <= m_timer)
	{
		if (m_pStageData->appearTime < 0) {
			m_pStageData = nullptr;
			if (m_stageNo > 0)
			{
				m_pStageData = stageSetData[m_stageNo];
				m_timer = 0;
			}
			break;
		}
		MapObj::searchSet(m_ppMapObj, MAPOBJ_MAX_NUM, m_pStageData->mapObjType, m_pStageData->drawDirection, m_pStageData->isOnLeftPage, m_pStageData->pos, m_pStageData->isHitAble, m_pStageData->size, m_pStageData->concentration, m_pStageData->pfMove);
		m_pStageData++;
	}
}


bool MapObjManager::isAlive()
{
	int num = 0;
	for (int i = 0; i < MAPOBJ_MAX_NUM; i++)
	{
		if (m_ppMapObj[i] && m_ppMapObj[i]->m_isInit)
		{
			num++;
			return true;
		}
	}
	return false;
}

void MapObjManager::setScroll(Vector3 a_speed, bool a_isOnLeftPage)
{
	for (int i = 0; i < MAPOBJ_MAX_NUM; i++)
	{
		if (m_ppMapObj[i] && m_ppMapObj[i]->m_isInit && m_ppMapObj[i]->m_isOnLeftPage == a_isOnLeftPage)
		{
			m_ppMapObj[i]->m_pos.y -= a_speed.y;
		}
	}
}
