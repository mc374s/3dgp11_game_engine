#ifndef _OBJ2D_H_
#define _OBJ2D_H_


class SpaceOBJ2D
{
private:

public:
	SPRITE_DATA* data;
	Vector3 pos;
	Vector3 speed;
	void(*move)(SpaceOBJ2D* obj);
	int state;
	int timer;
	int type;
	int hp;

	Vector3 size;

	SpaceOBJ2D()
	{
		clear();
	};

	virtual ~SpaceOBJ2D()
	{
		clear();
	};

	virtual void clear()
	{
		data = nullptr;
		pos = Vector3(0, 0, 0);
		speed = Vector3(0, 0, 0);

		move = nullptr;
		state = 0;
		timer = 0;
		type = 0;
		hp = 0;
		size = Vector3(0, 0, 0);
	};

	virtual void draw()
	{
		if (data)
		{
			data->draw(pos);

			/*GL::DrawLine(pos.x - size.x / 2, pos.y - size.y / 2, pos.x + size.x / 2, pos.y - size.y / 2, COLOR_RED);
			GL::DrawLine(pos.x - size.x / 2, pos.y + size.y / 2, pos.x + size.x / 2, pos.y + size.y / 2, COLOR_RED);
			GL::DrawLine(pos.x - size.x / 2, pos.y - size.y / 2, pos.x - size.x / 2, pos.y + size.y / 2, COLOR_RED);
			GL::DrawLine(pos.x + size.x / 2, pos.y - size.y / 2, pos.x + size.x / 2, pos.y + size.y / 2, COLOR_RED);*/
		}
	};

	static SpaceOBJ2D* searchSet(void(*_move)(SpaceOBJ2D* obj), Vector3 _pos, SpaceOBJ2D** _begin, int _MAX, int _type = 0, int _hp = 0)
	{
		for (int i = 0; i < _MAX; i++) {
			if (_begin[i]->move) continue;
			_begin[i]->move = _move;
			_begin[i]->pos = _pos;
			_begin[i]->type = _type;
			_begin[i]->hp = _hp;
			return _begin[i];
		}
		return nullptr;
	};

};

#endif // !_OBJ2D_H_
