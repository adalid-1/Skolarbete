#pragma once
#include "shape.h"
#include <vector>
class Cirkel :
	public Shape
{
public:
	Cirkel(float radie);
	~Cirkel(void);

	void render();
	void setPos(float x, float y);

	Vector2D p1;
	Vector2D p2;
private:
	float _radie;
protected:
	
		
};

