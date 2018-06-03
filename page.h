#ifndef _PAGE_H_
#define _PAGE_H_

class Page :public Scene, public Singleton<Page>
{
private:
	View *m_pView;

public:
	int m_width;
	int m_height;
	const int m_pagination;

	XMFLOAT3 m_position;

	OBJ2D m_bg;
	const int m_isActive = true;
	CUSTOM3D m_custom3d;

	Page(int a_pageWidth = PAGE_WIDTH, int a_pageHeight = PAGE_HEIGHT, int a_pagination = 1);
	~Page();

	void syncViewCustom3d();

	void init();
	void update();
	void draw();

};


#endif // !_PAGE_H_