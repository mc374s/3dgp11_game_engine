#ifndef _STAGE_DATA_H_
#define _STAGE_DATA_H_

struct STAGE_DATA;

extern STAGE_DATA stage00_setData[];
extern STAGE_DATA stage01_setData[];
extern STAGE_DATA stage02_setData[];
extern STAGE_DATA stage03_setData[];
extern STAGE_DATA stage04_setData[];
extern STAGE_DATA stage05_setData[];
extern STAGE_DATA stage06_setData[];
extern STAGE_DATA stage07_setData[];
extern STAGE_DATA stage08_setData[];
extern STAGE_DATA stage09_setData[];
extern STAGE_DATA stage10_setData[];
extern STAGE_DATA stage11_setData[];
extern STAGE_DATA stage12_setData[];
extern STAGE_DATA stage13_setData[];
extern STAGE_DATA stage14_setData[];
extern STAGE_DATA stage15_setData[];
extern STAGE_DATA stage16_setData[];
extern STAGE_DATA stage17_setData[];
extern STAGE_DATA stage18_setData[];

typedef Vector3 v3;

#define GH (GROUND_HEIGHT)
#define PW (PAGE_WIDTH)
#define PH (PAGE_HEIGHT)

//#define STAGE_MAX_NUM (20)


extern STAGE_DATA* stageSetData[];


extern int e_stageHeight[];
extern int e_startPagination[];
extern v3 e_initPos[];
extern int e_initLife[];


#endif // !_STAGE_DATA_H_
