#ifndef _JUDGE_H_
#define _JUDGE_H_


void Judge();

bool checkRectAB(SpaceOBJ2D* _A, SpaceOBJ2D* _B);

class Barrier;
bool checkRect2Barrier(SpaceOBJ2D* _A, Barrier* _B);

bool CheckHitRectCenter(float ax, float ay, int aw, int ah, float bx, float by, int bw, int bh);

#endif // !_JUDGE_H_
