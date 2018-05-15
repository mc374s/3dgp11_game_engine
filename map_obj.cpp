#include "game.h"
#include "sprite_data.h"
#include "stage_data.h"

#include "map_obj.h"


MapObj::MapObj(int a_type)
{
	clear();
	m_command = 0x0;
	m_type = a_type;
	switch (m_type)
	{
	case MAPOBJ_HOUSE:
		m_size = Vector3(56, 100, 14);

		break;
	case MAPOBJ_TREE_A:
		m_size = Vector3(120, 52, 36);

		break;
	case MAPOBJ_TREE_B:
		m_size = Vector3(208, 92, 28);
		
		break;
	case MAPOBJ_IVY_BIG:
		m_size = Vector3(312, 120, 56);
		
		break;
	case MAPOBJ_IVY_THIN:
		m_size = Vector3(104, 108, 16);
	
		break;
	case MAPOBJ_IVY_THICK:
		m_size = Vector3(80, 124, 8);
		
		break;
	case MAPOBJ_DOOR:
		m_size = Vector3(84, 88, 8);
		
		break;
	case MAPOBJ_KEY:
		m_size = Vector3(220, 196, 32);
		
		break;
	default:
		break;
	}

	m_pSprData = &e_pSprItem[m_type];

}

void MapObj::init(int a_type)
{
	m_type = a_type;
}


void MapObj::update()
{
	if (m_pfMove)
	{
		m_pfMove(this);

		animation();

	}
}
int MapObj::searchSet(MapObj** a_ppBegin, int a_maxNum, void(*a_pfMove)(MapObj*), int a_type, Vector3 &a_pos, int a_concentration)
{
	for (int i = 0; i < a_maxNum; i++)
	{
		if (a_ppBegin[i] && a_ppBegin[i]->m_isInit) {
			continue;
		}
		a_ppBegin[i] = new MapObj(a_type);
		a_ppBegin[i]->m_type = a_type;
		a_ppBegin[i]->m_pfMove = a_pfMove;
		a_ppBegin[i]->m_pos = a_pos;
		a_ppBegin[i]->m_isInit = true;
		a_ppBegin[i]->m_concentration = a_concentration;
		pObjManager->m_ppObj[GET_IDLE_OBJ_NO] = a_ppBegin[i];
		return i;
	}
	return -1;
}

void MapObj::hitAdjust(OBJ2DEX* a_pObj)
{
	// objÇ™thisÇÃëOÇ…Ç†ÇÈ

	// objÇ™thisÇÃå„ÇÎÇ…Ç†ÇÈ

	// objÇ™thisÇÃç∂Ç≈Ç†ÇÈ

	// objÇ™thisÇÃâEÇ≈Ç†ÇÈ

}

void MapObj::draw()
{
#ifdef DEBUG

	drawRectangle(m_pos.x - m_size.x / 2, m_pos.y - m_size.y, m_size.x, m_size.y, 0xFFFFFF80);

#endif // DEBUG

	OBJ2DEX::draw();

}


STAGE_DATA* stageSetData[] = {
	stage00_setData,
	stage01_setData,
};

void MapObjManager::init(int a_stageNo)
{
	m_stageNo = a_stageNo;
	m_timer = 0;
	m_pStageData = stageSetData[m_stageNo];
	for (int i = 0; i < MAPOBJ_MAX_NUM; i++)
	{
		m_ppMapObj[i] = nullptr;
	}

}

void MapObjManager::stageUpdate()
{
	m_timer++;

	while (m_pStageData && m_pStageData->appearTime <= m_timer)
	{
		if (m_pStageData->pfMove == nullptr) {
			if (m_stageNo > 0)
			{
				m_pStageData = stageSetData[m_stageNo];
				m_timer = 0;
			}
			break;
		}
		MapObj::searchSet(m_ppMapObj, MAPOBJ_MAX_NUM, m_pStageData->pfMove, m_pStageData->mapObjType, m_pStageData->pos, m_pStageData->concentration);
		m_pStageData++;
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

bool MapObjManager::isAlive()
{
	int num = 0;
	for (int i = 0; i < MAPOBJ_MAX_NUM; i++)
	{
		if (m_ppMapObj[i] && m_ppMapObj[i]->m_isInit)
		{
			num++;
		}
	}
	if (num == 0)
	{
		return false;
	}
	return true;
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
	sprintf_s(buf, "\nItem Num: %d\n", num);
	drawString(0, 50, buf, 0x000000FF);

#endif // DEBUG
}
