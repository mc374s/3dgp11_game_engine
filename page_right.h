#ifndef _PAGE_RIGHT_H_
#define _PAGE_RIGHT_H_

class PageRight :public Scene, public Singleton<PageRight>
{
private:
	OBJ2D m_bg;
	bool m_isPlayerActive = false;
public:
	PageRight();
	~PageRight() {
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


#define PAGE_RIGHT (PageRight::getInstance())

#endif // !_PAGE_RIGHT_H_
