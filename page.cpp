#include "game.h"

#include "sprite_data.h"
#include "obj2d.h"
#include "player.h"
#include "map_obj.h"

#include "page.h"


Page::Page(int a_pageWidth, int a_pageHeight, int a_pagination) :m_pagination(a_pagination), m_width(a_pageWidth), m_height(a_pageHeight)
{
	m_bg.m_pSprData = &e_sprPageLeft;
	m_pView = new View(m_width, m_height);
}

void Page::init()
{
	pPlayerManager->init();
}

Page::~Page()
{
	if (m_pNextScene)
	{
		//delete nextScene;
		m_pNextScene = nullptr;
	}
}

void Page::update()
{
	//�y�[�W�̓��e���X�V
	/*if (m_pInnerScene)
	{
		if (m_pInnerScene->m_pNextScene)
		{
			m_pInnerScene = m_pInnerScene->m_pNextScene;
		}
		m_pInnerScene->update();
	}*/

	//�y�[�W�̓��e���X�V

	// �v���C���[���ʉ߂����Ƃ���Ƀ����_���ş��ޔ���pObj��z�u
	if (pPlayerManager->m_pPlayer->m_liveInPagination == m_pagination && pPlayerManager->m_pPlayer->m_isMoving) {
		pObjManager->m_hitObj.m_liveInPagination = m_pagination;
		Vector3 pos = pPlayerManager->m_pPlayer->m_pos;
		Vector3 speed = pPlayerManager->m_pPlayer->m_speed;
		Vector3 size = pPlayerManager->m_pPlayer->m_size;
		Vector3 randAdjust;
		for (int i = 0; i < 3; i++) {
			randAdjust = { (float)(rand() % (int)(fabsf(speed.x) + size.x)), (float)(rand() % (int)(fabsf(speed.y) + size.y)),0 };
			if (speed.x == 0 && !pPlayerManager->m_pPlayer->m_isOnGround)
			{
				randAdjust.x -= size.x / 2;
				randAdjust.y -= size.y / 2;
			}
			if (pPlayerManager->m_pPlayer->m_isOnGround)
			{
				randAdjust.x += size.x / 2;
			}

			if (speed.x != 0)
			{
				randAdjust.x *= (speed.x / fabsf(speed.x));
			}
			if (speed.y != 0)
			{
				randAdjust.y *= (speed.y / fabsf(speed.y));
			}
			pObjManager->m_hitObj.m_pos = pos - randAdjust;
			pObjManager->m_hitObj.m_custom.angle = rand() % 180;
			pObjManager->m_hitObj.m_alpha = rand() % 20 + 20;
			pObjManager->m_newblurAreaList.push_back(pObjManager->m_hitObj);
		}
	}


	pObjManager->update(m_pagination);
}

void Page::draw()
{
	//View::clear();
	//m_pView->set(-PAGE_WIDTH, -PAGE_HEIGHT / 2, PAGE_WIDTH, PAGE_HEIGHT, 0, 0, PAGE_WIDTH, PAGE_HEIGHT);

	m_bg.draw();

	pObjManager->draw(m_pagination);

	drawRectangle(PAGE_WIDTH - 4, 0, 4, PAGE_HEIGHT, 0, 0x000000FF);

	View::clear();
	//char buf[256];
	//sprintf_s(buf, "Player Concentration: %d\nTransfer Concentration: %d", pPlayerManager->m_pPlayer->m_concentration, pPlayerManager->m_concentration - pPlayerManager-//>m_transferConcentration);
	//drawString(0, 300, buf);

}