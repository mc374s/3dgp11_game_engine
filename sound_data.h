﻿#ifndef _SOUND_DATA_H_
#define _SOUND_DATA_H_

enum AUDIO_NO
{
	BGM_MAIN,
	SE_START,
	SE_FALL,
	SE_OPEN,
	SE_CLOSE,
	SE_TURN,
	SE_SPLASH,

	SE_KEY_GOT,
	SE_DOOR_OPENED,
	SE_DEAD,
};

extern RESOURCE_DATA audio_data[];

#endif // !_SOUND_DATA_H_
