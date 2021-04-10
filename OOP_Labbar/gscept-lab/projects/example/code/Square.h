#pragma once
#include "shape.h"
class Square :
	public Shape
{
public:
	Square(float sida);
	~Square(void);

	//void rotate(float radians);
	void render();
	void setPos(float x, float y);
	Square::Square(float sidan, float x, float y);
private:
	float sida;
	float hSida;
	Vector2D_v2 bottomLeft;
	Vector2D_v2 bottomRight;
	Vector2D_v2 TopRight;
	Vector2D_v2 TopLeft;


};

