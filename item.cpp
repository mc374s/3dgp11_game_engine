#include "game.h"
#include "sprite_data.h"
#include "stage_data.h"

#include "item.h"


Item::Item(int a_type)
{
	clear();
	m_command = 0x0;
	m_type = a_type;
	switch (m_type)
	{
	case ITEM_HOUSE:
		m_size = Vector3(56, 100, 14);

		break;
	case ITEM_TREE_A:
		m_size = Vector3(120, 52, 36);

		break;
	case ITEM_TREE_B:
		m_size = Vector3(208, 92, 28);
		
		break;
	case ITEM_IVY_BIG:
		m_size = Vector3(312, 120, 56);
		
		break;
	case ITEM_IVY_THIN:
		m_size = Vector3(104, 108, 16);
	
		break;
	case ITEM_IVY_THICK:
		m_size = Vector3(80, 124, 8);
		
		break;
	case ITEM_DOOR:
		m_size = Vector3(84, 88, 8);
		
		break;
	case ITEM_KEY:
		m_size = Vector3(220, 196, 32);
		
		break;
	default:
		break;
	}

	m_pSprData = &e_pSprItem[m_type];

}

void Item::init(int a_type)
{
	m_type = a_type;
}


void Item::update()
{
	if (m_pfMove)
	{
		m_pfMove(this);

		animation();

	}
}
int Item::searchSet(Item** a_ppBegin, int a_maxNum, void(*a_pfMove)(Item*), int a_type, Vector3 &a_pos, int a_concentration)
{
	for (int i = 0; i < a_maxNum; i++)
	{
		if (a_ppBegin[i] && a_ppBegin[i]->m_isInit) {
			continue;
		}
		a_ppBegin[i] = new Item(a_type);
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

void Item::hitAdjust(OBJ2DEX* a_pObj)
{
	// objÇ™thisÇÃëOÇ…Ç†ÇÈ

	// objÇ™thisÇÃå„ÇÎÇ…Ç†ÇÈ

	// objÇ™thisÇÃç∂Ç≈Ç†ÇÈ

	// objÇ™thisÇÃâEÇ≈Ç†ÇÈ

}

void Item::draw()
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

void ItemManager::init(int a_stageNo)
{
	m_stageNo = a_stageNo;
	m_timer = 0;
	m_pStageData = stageSetData[m_stageNo];
	for (int i = 0; i < ITEM_MAX_NUM; i++)
	{
		m_ppItem[i] = nullptr;
	}

}

void ItemManager::stageUpdate()
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
		Item::searchSet(m_ppItem, ITEM_MAX_NUM, m_pStageData->pfMove, m_pStageData->itemType, m_pStageData->pos, m_pStageData->concentration);
		m_pStageData++;
	}
}

void ItemManager::update()
{
	for (int i = 0; i < ITEM_MAX_NUM; i++)
	{
		if (m_ppItem[i] && m_ppItem[i]->m_pfMove && m_ppItem[i]->m_state >= STATE_END + 2)
		{
			m_ppItem[i]->m_pfMove(m_ppItem[i]);
		}
	}
}

bool ItemManager::isAlive()
{
	int num = 0;
	for (int i = 0; i < ITEM_MAX_NUM; i++)
	{
		if (m_ppItem[i] && m_ppItem[i]->m_isInit)
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

void ItemManager::draw()
{
	int num = 0;
	for (int i = 0; i < ITEM_MAX_NUM; i++)
	{
		if (m_ppItem[i] && m_ppItem[i]->m_isInit)
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
