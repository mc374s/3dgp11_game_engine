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

	virtual void clear();
	virtual void update() {};

	virtual void draw();

	static int searchSet(OBJ2D** a_ppBegin, int a_max);

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

	virtual void clear();

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
	OBJ2D* m_ppObj[OBJ_MAX_NUM] = { nullptr };

	void init();
	void updata(bool a_isLeftPage = true);
	void draw(bool a_isLeftPage = true);

	ObjManager() {};
	~ObjManager();

};

#define pObjManager (ObjManager::getInstance())

#define GET_IDLE_OBJ_NO (OBJ2D::searchSet(pObjManager->m_ppObj, OBJ_MAX_NUM))


#endif // !_OBJ2D_H_
