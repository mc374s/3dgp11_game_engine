﻿#include "game.h"

#include "sprite_data.h"
#include "map_obj.h"
#include "player.h"
#include "paper.h"

#include "game_ui.h"

Paper::Paper(int a_paperNO, int a_pageWidth, int a_pageHeight, int a_paperDepth, UINTCOLOR a_materialColor)
	:m_paperNO(a_paperNO), m_width(a_pageWidth), m_height(a_pageHeight), m_depth(a_paperDepth), m_materialColor(a_materialColor)
{
	m_pBG = new OBJ2D;
	m_pBG->m_pSprData = &e_sprPage;
	m_custom3d.clear();



	m_pCube = new Cube(XMFLOAT3(.0f, .0f, .0f), XMFLOAT3(m_width, m_height, m_depth), m_materialColor);
	//m_pCube->m_custom3d.position = XMFLOAT3(-m_width / 2, 0, m_paperNO*m_depth);
	// Create a resize unable View
	m_pViewFront = new View(-m_width / 2, -m_height / 2, m_width, m_height, 0, 0, m_width, m_height);
	m_pViewBack = new View(-m_width / 2, -m_height / 2, m_width, m_height, 0, 0, m_width, m_height);
	m_pViewBack->m_doReflection = true;
	m_viewAdjust = m_depth / 2.0f + 0.6f;

	m_initPos = { 0,0,0 };
	m_pCube->m_custom3d = m_custom3d;
	m_pViewFront->m_custom3d = m_custom3d;
	m_pViewFront->m_custom3d.position.z -= m_viewAdjust;
	m_pViewBack->m_custom3d = m_custom3d;
	m_pViewBack->m_custom3d.position.z += m_viewAdjust;


	m_paginationFront = m_paperNO * 2;
	m_paginationBack = m_paperNO * 2 + 1;

	m_pCurtainFront = new OBJ2D;
	m_pCurtainFront->m_pSprData = &e_sprWhite;
	m_pCurtainFront->m_custom.scaleX = m_width / (float)m_pCurtainFront->m_pSprData->width;
	m_pCurtainFront->m_custom.scaleY = m_height / (float)m_pCurtainFront->m_pSprData->height;
	m_pCurtainFront->m_custom.rgba = 0x000000FF;
	m_pCurtainFront->m_alpha = 0;
	m_pCurtainFront->m_setAlpha = 0;
	m_pCurtainBack = new OBJ2D;
	*m_pCurtainBack = *m_pCurtainFront;


	m_isActive = false;
}

void Paper::clear()
{
	for (auto &it : m_mapObjList[0])
	{
		it.clear();
	}
	m_mapObjList[0].clear();

	for (auto &it : m_mapObjList[1])
	{
		it.clear();
	}
	m_mapObjList[1].clear();

}

void Paper::clearAll()
{
	m_mapObjList[0].clear();
	m_mapObjList[1].clear();
	m_blurAreaList[0].clear();
	m_blurAreaList[1].clear();
	m_transcriptionList[0].clear();
	m_transcriptionList[1].clear();

	m_pCurtainFront->m_custom.rgba = 0x000000FF;
	m_pCurtainFront->m_alpha = 0;
	m_pCurtainFront->m_setAlpha = 0;
	*m_pCurtainBack = *m_pCurtainFront;
}

void Paper::reloadFrontOrBack(bool a_reloadFront)
{
	static int frontOrBack = 0;
	if (a_reloadFront){
		frontOrBack = 0;
	}
	else {
		frontOrBack = 1;
	}

	for (auto &it : m_mapObjList[frontOrBack]) {
		it.clear();
	}
	m_mapObjList[frontOrBack].clear();

	for (auto &it : m_blurAreaList[frontOrBack]) {
		it.clear();
	}
	m_blurAreaList[frontOrBack].clear();

	for (auto &it : m_transcriptionList[frontOrBack]) {
		it.clear();
	}
	m_transcriptionList[frontOrBack].clear();

	/*for (auto &it : m_blurAreaList[frontOrBack]) {
		it.m_pos = it.m_initPos;
	}
	for (auto &it : m_transcriptionList[frontOrBack]) {
		it.m_pos = it.m_initPos;
	}*/

}

void Paper::init()
{
	m_isActive = false;
}

Paper::~Paper()
{
	if (m_pNextScene)
	{
		//delete nextScene;
		m_pNextScene = nullptr;
	}
	SAFE_DELETE(m_pViewFront);
	SAFE_DELETE(m_pViewBack);
	SAFE_DELETE(m_pCube);
	SAFE_DELETE(m_pBG);
	SAFE_DELETE(m_pCurtainFront);
	SAFE_DELETE(m_pCurtainBack);
}

void Paper::syncViewCustom3d()
{

	// bucause of the depth test is ON, set a different depth between page surface and view
	m_custom3d.position += m_initPos;
	m_pCube->m_custom3d = m_custom3d;
	m_pViewFront->m_custom3d = m_custom3d;
	m_pViewFront->m_custom3d.position.z -= m_viewAdjust;
	m_pViewFront->m_custom3d.position.y = -m_pViewFront->m_custom3d.position.y;
	m_pViewBack->m_custom3d = m_custom3d;
	m_pViewBack->m_custom3d.position.z += m_viewAdjust;
	m_pViewBack->m_custom3d.position.y = -m_pViewBack->m_custom3d.position.y;
}

void Paper::updateFront()
{

	//ページの内容を更新
	if (m_isActive)
	{
		for (MapObj &it : m_mapObjList[0]) {
			it.update();
		}
		for (auto it = m_blurAreaList[0].begin(); it != m_blurAreaList[0].end();) {
			/*if ((*it).m_alpha <= 0) {
				(*it).clear();
				it = m_blurAreaList[0].erase(it);
			}
			else {
				(*it).m_timer++;
				(*it).m_alpha -= ((*it).m_timer / 40);
				(*it).update();
				++it;
			}*/
			(*it).update();
			++it;
		}
		for (OBJ2D &it : m_transcriptionList[0]) {
			it.update();
		}

	}
}

void Paper::updateBack()
{

	//ページの内容を更新
	if (m_isActive)
	{
		for (MapObj &it : m_mapObjList[1]) {
			it.update();
		}
		for (auto it = m_blurAreaList[1].begin(); it != m_blurAreaList[1].end();) {
			/*if ((*it).m_alpha<=0){
				(*it).clear();
				it = m_blurAreaList[1].erase(it);
			}
			else{
				(*it).m_timer++;
				(*it).m_alpha -= ((*it).m_timer / 40);
				(*it).update();
				++it;
			}*/
			(*it).update();
			++it;
		}
		for (OBJ2D &it : m_transcriptionList[1]) {
			it.update();
		}
	}
}

void Paper::update()
{

	//ページの内容を更新
	updateFront();
	updateBack();

}


void Paper::drawFront()
{
	View::clear();


	if (m_isActive)
	{

		///////////////////////////////////////////////////////////////////////////////////////////////////
		// Front View
		m_pViewFront->set();
		m_pBG->m_custom.reflectX = false;
		m_pBG->draw();

		for (MapObj &it : m_mapObjList[0]) {
			it.draw();
		}
		for (OBJ2D &it : m_blurAreaList[0]) {
			it.draw();
#ifdef DEBUG

			if (it.m_isHitAble) {
				//drawRectangle(it.m_pos.x - it.m_size.x / 2, it.m_pos.y - it.m_size.y, it.m_size.x, it.m_size.y, 0, 0xFFFFFF80);
			}

#endif // DEBUG
		}
		for (OBJ2D &it : m_transcriptionList[0]) {
			it.draw();
		}
		pPlayerManager->draw(m_paginationFront);
		//drawRectangle(0, 0, 4, m_height, 0, 0x000000FF);

		if (m_pCurtainFront->m_alpha > m_pCurtainFront->m_setAlpha) {
			m_pCurtainFront->m_alpha -= 6;
			if (m_pCurtainFront->m_alpha < m_pCurtainFront->m_setAlpha) {
				m_pCurtainFront->m_alpha = m_pCurtainFront->m_setAlpha;
			}
		}
		if (m_pCurtainFront->m_alpha < m_pCurtainFront->m_setAlpha) {
			m_pCurtainFront->m_alpha += 6;
			if (m_pCurtainFront->m_alpha > m_pCurtainFront->m_setAlpha) {
				m_pCurtainFront->m_alpha = m_pCurtainFront->m_setAlpha;
			}
		}

		pGameUIManager->drawStageClearedMark(m_paginationFront);
		//pGameUIManager->drawTitleStamp(m_paginationFront);

		m_pCurtainFront->draw();

#ifdef DEBUG

		char buf[256];
		sprintf_s(buf, "Front: %d \nBlurObjNum: %d", m_paginationFront, m_blurAreaList[0].size());
		drawString(m_width - 240, m_height - 40, buf, 0x000000FF, STR_LEFT, 16, 16);

#endif // DEBUG
	}

}


void Paper::drawBack()
{
	View::clear();

	if (m_isActive)
	{
		View::clear();

		//////////////////////////////////////////////////////////////////////////////////////////////////
		// Back View
		m_pViewBack->set();
		m_pBG->m_custom.reflectX = true;
		m_pBG->draw();
		for (MapObj &it : m_mapObjList[1]) {
			it.draw();
		}

		MyBlending::setMode(framework::s_pDeviceContext, BLEND_ALPHA);
		for (OBJ2D &it : m_blurAreaList[1]) {
			it.draw();
#ifdef DEBUG

			if (it.m_isHitAble) {
				//drawRectangle(it.m_pos.x - it.m_size.x / 2, it.m_pos.y - it.m_size.y, it.m_size.x, it.m_size.y, 0, 0xFFFFFF80);
			}

#endif // DEBUG
		}
		MyBlending::setMode(framework::s_pDeviceContext, BLEND_ALPHA);

		for (OBJ2D &it : m_transcriptionList[1]) {
			it.draw();
		}
		pPlayerManager->draw(m_paginationBack);
		//drawRectangle(m_width - 4, 0, 4, m_height, 0, 0x000000FF);

		if (m_pCurtainBack->m_alpha > m_pCurtainBack->m_setAlpha) {
			m_pCurtainBack->m_alpha -= 6;
			if (m_pCurtainBack->m_alpha < m_pCurtainBack->m_setAlpha) {
				m_pCurtainBack->m_alpha = m_pCurtainBack->m_setAlpha;
			}
		}
		if (m_pCurtainBack->m_alpha < m_pCurtainBack->m_setAlpha) {
			m_pCurtainBack->m_alpha += 6;
			if (m_pCurtainBack->m_alpha > m_pCurtainBack->m_setAlpha) {
				m_pCurtainBack->m_alpha = m_pCurtainBack->m_setAlpha;
			}
		}

		pGameUIManager->drawStageClearedMark(m_paginationBack);
		//pGameUIManager->drawTitleStamp(m_paginationBack);


		m_pCurtainBack->draw();

#ifdef DEBUG

		char buf[256];
		sprintf_s(buf, "Back: %d \nBlurObjNum: %d", m_paginationBack, m_blurAreaList[1].size());
		drawString(0, m_height - 40, buf, 0x000000FF, STR_LEFT, 18, 18);


#endif // DEBUG

	}

}

void Paper::draw()
{
	if (m_isActive)
	{

		///////////////////////////////////////////////////////////////////////////////////////////////////
		// Front View
		if (m_custom3d.angleYawPitchRoll.x < 90)
		{
			drawFront();
			View::clear();
		}

		//////////////////////////////////////////////////////////////////////////////////////////////////
		// Back View
		if (m_custom3d.angleYawPitchRoll.x > 90)
		{
			drawBack();
			View::clear();
		}
	}

	m_pCube->draw();
	////////////////////////////////////////////////////////////////////////////////////////////////////
	// Scene Main View

}

void Paper::setScroll(Vector3 a_speed, int a_scrollNO, bool a_isRestart)
{
	for (MapObj &it : m_mapObjList[a_scrollNO])
	{
		it.m_pos.y -= a_speed.y;
		if (a_speed.y < 0 && it.m_pos.y > it.m_initPos.y)
		{
			it.m_pos.y = it.m_initPos.y;
		}
		if (a_speed.y > 0 && it.m_pos.y < it.m_initPos.y - STAGE_HEIGHT)
		{
			it.m_pos.y = it.m_initPos.y - STAGE_HEIGHT;
		}
	}

	for (auto &it : m_blurAreaList[a_scrollNO])
	{
		it.m_pos.y -= a_speed.y;
		if (a_speed.y < 0 && it.m_pos.y > it.m_initPos.y/* && a_isRestart*/)
		{
			it.m_pos.y = it.m_initPos.y;
		}
		if (a_speed.y > 0 && it.m_pos.y < it.m_initPos.y - STAGE_HEIGHT)
		{
			it.m_pos.y = it.m_initPos.y - STAGE_HEIGHT;
		}
	}

	for (auto &it : m_transcriptionList[a_scrollNO])
	{
		it.m_pos.y -= a_speed.y;
		if (a_speed.y < 0 && it.m_pos.y > it.m_initPos.y/* && a_isRestart*/)
		{
			it.m_pos.y = it.m_initPos.y;
		}
		if (a_speed.y > 0 && it.m_pos.y < it.m_initPos.y - STAGE_HEIGHT)
		{
			it.m_pos.y = it.m_initPos.y - STAGE_HEIGHT;
		}
	}
}