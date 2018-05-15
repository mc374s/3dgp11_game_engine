#ifndef _ITEM_H_
#define _ITEM_H_

#include "obj2d.h"

#define ITEM_MAX_NUM (24)

enum ITEM_TYPE
{
	ITEM_NONE = -1,
	ITEM_HOUSE = 0,
	ITEM_TREE_A,
	ITEM_TREE_B,
	ITEM_IVY_BIG,
	ITEM_IVY_THIN,
	ITEM_IVY_THICK,
	ITEM_DOOR,
	ITEM_KEY,

	ITEM_MAX_TYPE,
};

class Item : public OBJ2DEX
{
private:

public:

	int m_command; //プレイヤーのキー入力
	int m_concentration; //濃度

	void hitAdjust(OBJ2DEX* a_pObj);

	void(*m_pfMove)(Item*);

	Item(int a_type = 0);
	~Item() {
		clear();
	};

	void init(int a_type);

	void clear() {
		OBJ2DEX::clear();
		m_pfMove = nullptr;
		m_command = 0x0;
	};

	void update();
	void draw();

	static int searchSet(Item** a_ppBegin, int a_maxNum, void(*a_pfMove)(Item*), int a_type, Vector3 &a_pos = Vector3(0, 0, 0), int a_concentration = 10);

};

struct STAGE_DATA {
	int appearTime;
	void(*pfMove)(Item*);
	int itemType;
	Vector3 pos;
	int concentration;
	bool isOnLeftPage;
	STAGE_DATA(int a_appearTime, void(*a_pfMove)(Item*), int a_itemType, Vector3 a_pos, int a_concentration, bool a_isOnLeftPage)
		:appearTime(a_appearTime), pfMove(a_pfMove), itemType(a_itemType), pos(a_pos), concentration(a_concentration),isOnLeftPage(a_isOnLeftPage) {};
};

class ItemManager : public Singleton<ItemManager>, public Manager
{
private:

public:

	Item* m_ppItem[ITEM_MAX_NUM];

	STAGE_DATA* m_pStageData;
	int m_stageNo;

	void init(int m_stageNo = 0);
	void stageUpdate();
	void update();
	void draw();

	ItemManager() {};
	~ItemManager() {
		/*for (int i = 0; i < ITEM_MAX_NUM; i++)
		{
		if (pItem[i]) {
		delete pItem[i];
		pItem[i] = nullptr;
		}
		}*/
	};

	bool isAlive();

};

#define pItemManager (ItemManager::getInstance())




#endif // !_ITEM_H_
