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

	void rota(float radian);

	Vector2D_v2 bottomLeft;
	Vector2D_v2 bottomRight;
	Vector2D_v2 top;

private:
	float _base;
	float _height;
};
