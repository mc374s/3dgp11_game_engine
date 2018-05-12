#ifndef _GAME_H_
#define	_GAME_H_

#include "./3dgp/3dgp_system.h"
#include "./3dgp/framework.h"
#include "./3dgp/game_system.h"
#include "./3dgp/Template.h"
#include "./3dgp/Scene.h"

//#include <list>
//using namespace std;


// Test game
#define VIEW_WIDTH (900)
#define VIEW_HEIGHT (950)

#define GROUND_HEIGHT (VIEW_HEIGHT-64)

enum ENEMY_TYPE
{
	ENEMY_A,
	ENEMY_B,
	ENEMY_C,
	ENEMY_UFO,
	ENEMY_SHOT,
};



#include "SoundData.h"
#include "Tools.h"
#include "SprData.h"

#include "./SpaceInvaders/spaceOBJ2D.h"
#include "./SpaceInvaders/spacePlayer.h"
#include "./SpaceInvaders/Enemy.h"
#include "./SpaceInvaders/Shot.h"
#include "./SpaceInvaders/Effect.h"
#include "./SpaceInvaders/barrierData.h"
#include "./SpaceInvaders/Barrier.h"
#include "./SpaceInvaders/Judge.h"

#include "./SpaceInvaders/spaceSceneTitle.h"
#include "./SpaceInvaders/spaceSceneGame.h"

//Real game

#define PAGE_WIDTH	(620)
#define PAGE_HEIGHT (700)

#include "book.h"

#include "scene_title.h"
#include "scene_main.h"

#endif // !_GAME_H_
