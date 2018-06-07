#ifndef _GAME_H_
#define	_GAME_H_


#include "./3dgp/3dgp_system.h"
#include "./3dgp/framework.h"
#include "./3dgp/mf_audio.h"
#include "./3dgp/game_system.h"
#include "./3dgp/template.h"
#include "./3dgp/scene.h"

#define DEBUG

#include <vector>

#define PAGE_WIDTH	(620)
#define PAGE_HEIGHT (700)

#define GROUND_HEIGHT (600)


#define CAMERA_BEST_DISTANCE (0.66f)
#define CAMERA_MAX_DISTANCE (1.45f)

#define CAMERA_BEST_DISTANCE_PX (CAMERA_BEST_DISTANCE*SCREEN_WIDTH)


#define P_CONCENTRATION_MAX_NUM			(10)

extern int START_PAGINATION;
extern int STAGE_HEIGHT;
extern Vector3 INIT_POS;
extern const int STAGE_MAX_NUM;

// TODO : Systemly Learn how Header.h and Source.cpp work


#endif // !_GAME_H_
