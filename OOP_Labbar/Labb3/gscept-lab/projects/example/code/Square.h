#pragma once
#include "shape.h"
class Square : public Shape
{
public:
	Square(float sideLen);
	~Square(void);

	void render();
	void setPos(float x, float y);
	Square(float sidan, float x, float y);
private:
	float halfSideLen;
	Vector2D bottomLeft;
	Vector2D bottomRight;
	Vector2D TopRight;
	Vector2D TopLeft;
};

