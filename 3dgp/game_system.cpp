#include "game_system.h"

#include "framework.h"
#include "blend.h"
#include "sprite.h"


LOAD_TEXTURE *g_load_texture[TEX_MAX] = { nullptr };

void SPRITE_DATA::draw(float _x, float _y, CUSTOM *_custom) {
	if (texNum >= 0 && texNum < TEX_MAX && g_load_texture[texNum] && g_load_texture[texNum]->img)
	{
		if (_custom) {
			g_load_texture[texNum]->img->render(framework::s_pDeviceContext, _x + ofsX, _y + ofsY, _custom->scaleX*width, _custom->scaleY*height, left, top, width, height, _custom->argb, _custom->angle, _custom->centRotate, _custom->centX, _custom->centY, _custom->reflectX, _custom->scaleMode);
		}
		else {
			g_load_texture[texNum]->img->render(framework::s_pDeviceContext, _x + ofsX, _y + ofsY, width, height, left, top, width, height, 0xFFFFFFFF, 0.0f);
		}
	}
}

void TextureManager::loadTexture(LOAD_TEXTURE _data[])
{
	for (int i = _data[0].texNum; _data[i].texNum != -1 || _data[i].fileName != NULL; i++)
	{
		/*const size_t cSize = strlen(_data[i].fileName) + 1;
		wchar_t *wcFileName = new wchar_t[cSize];
		
		size_t temp;
		mbstowcs_s(&temp, wcFileName, cSize, _data[i].fileName, cSize);*/

		_data[i].img = new Sprite(framework::s_pDevice, _data[i].fileName);
		g_load_texture[i] = &_data[i];
		//delete[] wcFileName;
	}
}

void TextureManager::releaseTexture()
{
	int i;
	for (i = 0; i < TEX_MAX; i++)
	{
		if (g_load_texture[i])
		{
			delete g_load_texture[i]->img;
			ZeroMemory(g_load_texture[i], sizeof(*g_load_texture[i]));
			
		}
	}
	ZeroMemory(g_load_texture, sizeof(LOAD_TEXTURE)*i);
}

int m_command = 0x0;

int  getInputKey()
{
	int m_command = 0x0;

	if (GetAsyncKeyState(VK_UP) & 0xF000) {
		m_command |= PAD_UP;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0xF000) {
		m_command |= PAD_DOWN;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0xF000){
		m_command |= PAD_LEFT;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0xF000){
		m_command |= PAD_RIGHT;
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x0001) {
		m_command |= PAD_START;
	}
	if (GetAsyncKeyState(VK_RETURN) & 0x0001) { 
		m_command |= PAD_ENTER;
	}
	if (GetAsyncKeyState('Z') & 0x0001) {
		m_command |= PAD_TRG1;
	}
	if (GetAsyncKeyState('X') & 0x0001) {
		m_command |= PAD_TRG2;
	}
	if (GetAsyncKeyState('C') & 0x0001) {
		m_command |= PAD_TRG3;
	}
	if (GetAsyncKeyState('V') & 0x0001) {
		m_command |= PAD_TRG4;
	}

	return m_command;
}

void drawString(int _x, int _y, char *_buf, D3DCOLOR _color, int _format, int _sizeX, int _sizeY, float _angle)
{
	drawSprString(framework::s_pDeviceContext, _x, _y, _buf, _color, _format, _sizeX, _sizeY, _angle);
}

void drawRectangle(float _x, float _y, float _w, float _h, float _angle, UINTCOLOR _color)
{
	static Sprite rect(framework::s_pDevice);
	//MyBlending::setMode(framework::m_pDeviceContext, BLEND_REPLACE);
	rect.render(framework::s_pDeviceContext, _x, _y, _w, _h, _angle, _color);
	//MyBlending::setMode(framework::m_pDeviceContext, BLEND_ALPHA);
}


///////////////////////////////////////////////////////////////
// Class View
View::View(int a_viewWidth, int a_viewHeight) 
{
	m_pRenderTarget = new RenderTarget(framework::s_pDevice, a_viewWidth, a_viewHeight);
}

View::~View()
{
	if (m_pRenderTarget)
	{
		delete m_pRenderTarget;
		m_pRenderTarget = NULL;
	}
}

// View, looks like a textured sprite
void View::set(float a_drawX, float a_drawY, float a_drawWidth, float a_drawHeight, float a_srcX, float a_srcY, float a_srcWidth, float a_srcHeight, float a_rotateAngle, UINTCOLOR a_blendColor)
{
	m_pRenderTarget->render3D(framework::s_pDeviceContext, a_drawX, a_drawY, a_drawWidth, a_drawHeight, a_srcX, a_srcY, a_srcWidth, a_srcHeight, a_rotateAngle, a_blendColor, &m_custom3d);
}

// Reset ViewPort to real screen
void View::clear()
{
	framework::s_pDeviceContext->OMSetRenderTargets(1, &framework::s_pRenderTargetView, framework::s_pDepthStencilView);

	e_camera.viewPort.Width = SCREEN_WIDTH;
	e_camera.viewPort.Height = SCREEN_HEIGHT;
	framework::s_pDeviceContext->RSSetViewports(1, &e_camera.viewPort);
	setRenderTargetWH(SCREEN_WIDTH, SCREEN_HEIGHT);
}

///////////////////////////////////////////////////////////

// Class Cube
Cube::Cube(const XMFLOAT3 &a_position, const XMFLOAT3 &a_size, const UINTCOLOR &a_blendColor) :m_position(a_position), m_size(a_size), m_blendColor(a_blendColor)
{
	m_pPrimitive = new Primitive3D(framework::s_pDevice); 
	m_pPrimitive->initialize(framework::s_pDevice, GEOMETRY_CUBE);
}

Cube::~Cube()
{
	if (m_pPrimitive)
	{
		delete m_pPrimitive;
		m_pPrimitive = NULL;
	}
}

void Cube::draw()
{
	m_pPrimitive->drawCube(framework::s_pDeviceContext, m_position, m_size, m_blendColor, &m_custom3d);
}

////////////////////////////////////////////////////////////