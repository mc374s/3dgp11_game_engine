#ifndef _GAME_H_
#define	_GAME_H_

#include "./3dgp/3dgp_system.h"
#include "./3dgp/framework.h"
#include "./3dgp/game_system.h"
#include "./3dgp/template.h"
#include "./3dgp/scene.h"

//#include <list>
//using namespace std;
#define DEBUG


#define PAGE_WIDTH	(620)
#define PAGE_HEIGHT (700)

#define GROUND_HEIGHT (600)

#define CAMERA_BEST_DISTANCE (0.65)
#define CAMERA_MAX_DISTANCE (1.45)

#include "sound_data.h"
#include "tools.h"
#include "sprite_data.h"


// Transcription game

#include "obj2d.h"
#include "player.h"

#include "page_left.h"
#include "page_right.h"

// Real game

#include "book.h"

#include "scene_title.h"
#include "scene_main.h"

#endif // !_GAME_H_
