#pragma once
#include "shape.h"
#include <vector>
class Circle :
	public Shape
{
public:
	Circle(float radie);
	~Circle(void);

	void render();
	void setPos(float x, float y);

private:
	float _radie;
	Vector2D _p1;
	Vector2D _p2;
};

