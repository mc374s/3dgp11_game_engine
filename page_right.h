#ifndef _PAGE_RIGHT_H_
#define _PAGE_RIGHT_H_

class PageRight :public Scene, public Singleton<PageRight>
{
private:
	OBJ2D m_bg;
	const int m_pagination = 2;

public:
	PageRight();
	~PageRight() {
		if (m_pNextScene)
		{
			//delete nextScene;
			m_pNextScene = nullptr;
		}
	};
	void update();
	void draw();

};


#define PAGE_RIGHT (PageRight::getInstance())

#endif // !_PAGE_RIGHT_H_
