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

	void rotate(float radian);

	Vector2D p1;
	Vector2D p2;
private:
	float _radie;
protected:
	
		
};

