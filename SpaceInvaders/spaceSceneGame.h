#ifndef _SPACESCENEGAME_H_
#define	_SPACESCENEGAME_H_

// SpaceSceneGameクラスの定義
class SpaceSceneGame :public Scene, public Singleton<SpaceSceneGame>
{
private:
	int		stageNo;
	char*	str_game;

public:
	SpaceSceneGame() { init(); };
	~SpaceSceneGame() {
		if (m_pNextScene)
		{
			//delete nextScene;
			m_pNextScene = nullptr;
		}
		if (str_game)
		{
			str_game = nullptr;
		}
	};
	void init();
	void update();
	void draw();

};

#define SCENE_GAME_SPACE (SpaceSceneGame::getInstance())


// スコア関係
void score_init();
void score_add(int add);
void score_draw();

#endif // !_SCENEGAME_H_
