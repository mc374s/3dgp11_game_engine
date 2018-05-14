#ifndef _OBJ2D_H_
#define _OBJ2D_H_

#define OBJ_MAX_NUM	(128)

class OBJ2D
{
private:

public:
	OBJ2D() {
		clear();
	};

	virtual ~OBJ2D() {
		clear();
	};

	SPRITE_DATA* m_pSprData;
	Vector3 m_pos;
	Vector3 m_speed;
	Vector3 m_size;

	CUSTOM m_custom;

	int m_timer;
	int m_state;
	int m_alpha;
	int m_type;

	bool m_isInit;
	bool m_isOnLeftPage = true;

	virtual void clear() {
		m_pSprData = nullptr;
		m_pos = Vector3(0, 0, 0);
		m_speed = m_size = Vector3(0, 0, 0);
		m_timer = 0;
		m_state = 0;
		m_alpha = 255;
		m_isInit = false;

		m_isOnLeftPage = true;

		m_type = 0;
	};
	virtual void update() {};

	virtual void draw() {
		if (m_pSprData)
		{
			m_custom.rgba = m_custom.rgba >> 8 << 8 | m_alpha;
			m_pSprData->draw(m_pos.x, m_pos.y, &m_custom);
		}
	};

	static int searchSet(OBJ2D** a_ppBegin, int a_max) {
		for (int i = 0; i < a_max; i++)
		{
			if (a_ppBegin[i] && a_ppBegin[i]->m_isInit) {
				continue;
			}
			return i;
		}
		return -1;
	}

};

class OBJ2DEX : public OBJ2D
{
private:

public:

	int m_aframe;
	int m_animeNO;

	SPRITE_DATA* m_pAnimeData;

	OBJ2DEX() {
		clear();
	};
	virtual ~OBJ2DEX() {
		clear();
	};

	virtual void clear() {
		OBJ2D::clear();
		m_aframe = 0;
		m_animeNO = 0;
		m_pAnimeData = nullptr;
	}

	virtual void update() {};
	virtual void animation();

	virtual void draw();

};

class Manager
{
public:
	int m_timer;
	int m_state;
	Manager() {
		m_timer = 0;
		m_state = 0;
	};
	virtual ~Manager() {};

private:

};


class ObjManager : public Singleton<ObjManager>, public Manager
{
private:

public:
	OBJ2D* m_pObj[OBJ_MAX_NUM] = { nullptr };

	void init();
	void updata(bool a_isLeftPage = true);
	void draw(bool a_isLeftPage = true);

	ObjManager() {};
	~ObjManager() {
		for (int i = 0; i < OBJ_MAX_NUM; i++)
		{
			if (m_pObj[i])
			{
				delete m_pObj[i];
			}
		}
		ZeroMemory(m_pObj, sizeof(m_pObj));
		//delete[] m_pObj;
	};

};

#define pObjManager (ObjManager::getInstance())


#endif // !_OBJ2D_H_
