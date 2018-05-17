#ifndef _PAGE_LEFT_H_
#define _PAGE_LEFT_H_

class PageLeft :public Scene, public Singleton<PageLeft>
{
private:
	OBJ2D m_bg;
	const bool m_isLeftPage = true;

public:
	PageLeft();
	~PageLeft() {
		if (m_pNextScene)
		{
			//delete nextScene;
			m_pNextScene = nullptr;
		}
	};
	bool activePlayer(bool a_doActive = true);

	void update();
	void draw();

};


#define PAGE_LEFT (PageLeft::getInstance())



#endif // !_PAGE_LEFT_H_