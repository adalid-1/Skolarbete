#pragma once
#include "shape.h"
class Square :
	public Shape
{
public:
	Square(float sida);
	~Square(void);

	void render();
	void setPos(float x, float y);
	Square::Square(float sidan, float x, float y);
private:
	float sida;
	float hSida;
	Vector2D bottomLeft;
	Vector2D bottomRight;
	Vector2D TopRight;
	Vector2D TopLeft;


	void rotate(float radian);

};

