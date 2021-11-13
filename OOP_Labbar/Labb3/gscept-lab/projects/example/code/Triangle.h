#pragma once
#include "shape.h"
class Triangle :
	public Shape
{
public:
	Triangle(float base, float height);
	~Triangle(void);

	void render();
	void setPos(float x, float y);

	float getBase();
	float getHeight();

	Vector2D bottomLeft;
	Vector2D bottomRight;
	Vector2D top;

private:
	float _base;
	float _height;
};
