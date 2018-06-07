#ifndef _PAPER_H_
#define _PAPER_H_

#define PAPER_DEPTH (1)

class MapObj;

class Paper :public Scene, public Singleton<Paper>
{
private:
	Cube *m_pCube;
	View *m_pViewFront;
	View *m_pViewBack;

public:


	Paper(int a_papeNO = 1, int a_pageWidth = PAGE_WIDTH, int a_pageHeight = PAGE_HEIGHT, int a_paperDepth = PAPER_DEPTH, UINTCOLOR a_materialColor = 0xC5B596FF/*0xd8ceb9FF*/);
	~Paper();


	int m_width;
	int m_height;
	int m_depth;
	UINTCOLOR m_materialColor;
	const int m_paperNO;

	int m_paginationFront;
	int m_paginationBack;

	OBJ2D *m_pBG;
	bool m_isActive;
	XMFLOAT3 m_initPos;
	CUSTOM3D m_custom3d;

	std::vector<MapObj*> m_pMapObjList[2];
	std::vector<OBJ2D*> m_pBlurAreaList[2];
	std::vector<OBJ2D*> m_pTranscriptionList[2];

	float m_viewAdjust;
	void syncViewCustom3d();

	void clear();
	void init();
	void update();
	void draw();

};


#endif // !_PAPER_H_