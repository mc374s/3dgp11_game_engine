#ifndef _GAME_SYSTEM_H_
#define _GAME_SYSTEM_H_

#include <cmath>
#include "sprite_string.h"

typedef unsigned int D3DCOLOR;
//*****************************************************************************
//		�R�c�x�N�g��
//*****************************************************************************
//------------------------------------------------------
//	�R�c�x�N�g����{�\����
//------------------------------------------------------
typedef struct Vector {
	float	x, y, z;
} Vector;

//------------------------------------------------------
//	�R�c�x�N�g���\����
//------------------------------------------------------
typedef struct Vector3 : public Vector
{
public:
	//	�R���X�g���N�^
	Vector3() {};
	inline Vector3(float x, float y, float z) { this->x = x, this->y = y, this->z = z; }
	inline Vector3(const Vector& v) { this->x = v.x, this->y = v.y, this->z = v.z; }

	//	�����v�Z
	inline float Length() { return sqrtf(x*x + y*y + z*z); }
	inline float LengthSq() { return x*x + y*y + z*z; }

	//	���K��
	void Normalize()
	{
		float l = Length();
		if (l != .0f) { x /= l; y /= l; z /= l; }
	}

	//	�I�y���[�^�[
	inline Vector3& operator = (const Vector& v) { x = v.x; y = v.y; z = v.z; return *this; }
	inline Vector3& operator += (const Vector3& v) { x += v.x; y += v.y; z += v.z; return *this; }
	inline Vector3& operator -= (const Vector3& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
	inline Vector3& operator *= (float v) { x *= v; y *= v; z *= v; return *this; }
	inline Vector3& operator /= (float v) { x /= v; y /= v; z /= v; return *this; }

	inline Vector3 operator + () const { Vector3 ret(x, y, z); return ret; }
	inline Vector3 operator - () const { Vector3 ret(-x, -y, -z); return ret; }

	inline Vector3 operator + (const Vector3& v) const { return Vector3(x + v.x, y + v.y, z + v.z); }
	inline Vector3 operator - (const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
	inline Vector3 operator * (float v) const { Vector3 ret(x*v, y*v, z*v); return ret; }
	inline Vector3 operator / (float v) const { Vector3 ret(x / v, y / v, z / v); return ret; }

	bool operator == (const Vector3& v) const { return (x == v.x) && (y == v.y) && (z == v.z); }
	bool operator != (const Vector3& v) const { return (x != v.x) || (y != v.y) || (z != v.z); }

} Vector3;

//------------------------------------------------------
//	�O��
//------------------------------------------------------
inline void Vector3Cross(Vector& out, Vector& v1, Vector& v2)
{
	out.x = v1.y*v2.z - v1.z*v2.y;
	out.y = v1.z*v2.x - v1.x*v2.z;
	out.z = v1.x*v2.y - v1.y*v2.x;
}

//------------------------------------------------------
//	����
//------------------------------------------------------
inline float Vector3Dot(Vector& v1, Vector& v2)
{
	return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}


//*****************************************************************************************************************************
//
//	define��`
//
//*****************************************************************************************************************************
// �L�[���x��
const int	PAD_UP		= (1 << 0);
const int	PAD_DOWN	= (1 << 1);
const int	PAD_LEFT	= (1 << 2);
const int	PAD_RIGHT	= (1 << 3);
const int	PAD_START	= (1 << 4);
const int	PAD_TRG1	= (1 << 5);
const int	PAD_TRG2	= (1 << 6);
const int	PAD_TRG3	= (1 << 7);
const int	PAD_ENTER	= (1 << 8);
const int	PAD_SELECT	= (1 << 8);
const int	PAD_TRG4	= (1 << 9);
const int	PAD_L1		= (1 << 10);
const int	PAD_R1		= (1 << 11);
const int	PAD_L2		= (1 << 12);
const int	PAD_R2		= (1 << 13);
const int	PAD_L3		= (1 << 14);
const int	PAD_R3		= (1 << 15);

const int	COLOR_WHITE		= 0xFFFFFFFF;
const int	COLOR_BLACK		= 0x000000FF;
const int	COLOR_GRAY		= 0x808080FF;
const int	COLOR_RED		= 0xFF0000FF;
const int	COLOR_ORANGE	= 0xFFA500FF;
const int	COLOR_YELLOW	= 0xFFFF00FF;
const int	COLOR_GREEN		= 0x008000FF;
const int	COLOR_BLUE		= 0x0000FFFF;
const int	COLOR_CYAN		= 0x00FFFFFF;
const int	COLOR_VIOLET	= 0x800080FF;


extern int m_command;


#define TEX_MAX (64)

enum STATE_STEP
{
	STATE_INIT = 0,
	STATE_BEGIN,

	STATE_END = 20,

	STATE_FINISH = 40,
};

class Sprite;

struct LOAD_TEXTURE
{
	int		texNum;			// �e�N�X�`���ԍ�
	char	*fileName;		// �t�@�C����
	Sprite* img;
};

extern LOAD_TEXTURE *g_load_texture[TEX_MAX];


struct CUSTOM
{
	float	scaleX, scaleY;
	float	angle;
	bool	reflectX;
	bool	centRotate;
	float	centX, centY;
	int		scaleMode;

	D3DCOLOR argb;

	CUSTOM(float _scaleX = 1.0f, float _scaleY = 1.0f, float _angle = .0f, bool _reflectX = false, bool _centRotate = true, float _centX = .0f, float _centY = .0f, int _scaleMode = 0, D3DCOLOR _argb = 0xFFFFFFFF)
	{
		scaleX = _scaleX;
		scaleY = _scaleY;
		angle = _angle;
		reflectX = _reflectX;
		centRotate = _centRotate;
		centX = _centX;
		centY = _centY;
		scaleMode = _scaleMode;
		argb = _argb;
	};

	void clear()
	{
		scaleX = 1.0f;
		scaleY = 1.0f;
		angle = .0f;
		reflectX = false;
		centRotate = true;
		centX = .0f;
		centY = .0f;
		scaleMode = 0;
		argb = 0xFFFFFFFF;
	};

};

struct SPRITE_DATA
{
	int		texNum = 0;
	float	left, top;
	float	width, height;
	float	ofsX, ofsY;
	int	frameNum;
	SPRITE_DATA(int _texNum, float _left, float _top, float _width, float _height, float _ofsX = 0, float _ofsY = 0,int _frameNum = 1){
		texNum = _texNum;
		left = _left;
		top = _top;
		width = _width;
		height = _height;
		ofsX = _ofsX;
		ofsY = _ofsY;
		frameNum = _frameNum;
	};
	void draw(Vector3 &_pos, CUSTOM *_custom = nullptr) {
		if (_custom){
			draw(_pos.x, _pos.y, _custom);
		}
		else{
			draw(_pos.x, _pos.y);
		}
	};
	void draw(float _x, float _y, CUSTOM *_custom = nullptr);
};

typedef SPRITE_DATA SPRITE_LEFTTOP;

struct SPRITE_CENTER : public SPRITE_DATA
{
	SPRITE_CENTER(int texNum, float left, float top, float width, float height, int _frameNum = 1) : SPRITE_DATA(texNum, left, top, width, height, -width / 2, -height / 2, _frameNum) {};
};

struct SPRITE_BOTTOM : public SPRITE_DATA
{
	SPRITE_BOTTOM(int texNum, float left, float top, float width, float height, int _frameNum = 1) : SPRITE_DATA(texNum, left, top, width, height, -width / 2, -height, _frameNum) {};
};


class TextureManager
{
private:

public:
	TextureManager() {};
	~TextureManager() {
		releaseTexture();
	};

	void loadTexture(LOAD_TEXTURE _data[]);

	void releaseTexture();

	static TextureManager* getInstance() {
		static TextureManager instance;
		return &instance;
	};

};

#define pTextureManager (TextureManager::getInstance())

int getInputKey();

void drawString(int _x = 0, int _y = 0, char *_buf = nullptr, D3DCOLOR _color = 0xFFFFFFFF, int _format = STR_LEFT, int _sizeX = 32, int _sizeY = 32, float _angle = .0f);

void drawRectangle(float _x, float _y, float _w, float _h, float _angle = 0.0, UINTCOLOR _color = 0xFFFFFFFF);



//class View: extend from class RenderTarget
class RenderTarget;
class View
{
private:
	RenderTarget *m_pRenderTarget;

public:
	View(int a_viewWidth, int a_viewHeight);
	~View();

	CUSTOM3D m_custom3d;

	void set(float a_drawX, float a_drawY, float a_drawWidth, float a_drawHeight, float a_srcX = .0f, float a_srcY = .0f, float a_srcWidth = .0f, float a_srcHeight = .0f, float a_rotateAngle = .0f, UINTCOLOR a_blendColor = 0xFFFFFFFF);
	static void clear();
};


// Class Cube: extend from class Primitive3d
class Primitive3D;
class Cube
{
private:
	Primitive3D *m_pPrimitive;
public:
	Cube(const XMFLOAT3 &a_position, const XMFLOAT3 &a_size, const UINTCOLOR &a_blendColor);
	~Cube();
	XMFLOAT3	m_position;
	XMFLOAT3	m_size;
	UINTCOLOR	m_blendColor;
	CUSTOM3D	m_custom3d;

	void draw();

};

#endif // !_GAME_SYSTEM_H_