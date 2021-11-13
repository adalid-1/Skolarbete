#pragma once
#include "shape.h"
#include <vector>
class Circle :
	public Shape
{
public:
	Circle(float radie);
	
	~Circle(void);
	void rotate(float radian);
	void render();
	void setPos(float x, float y);

	float getRadie();

	Vector2D p1;
	Vector2D p2;
private:
	float _radie;
protected:
	
		
};

