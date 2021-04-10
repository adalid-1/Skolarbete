#pragma once

#include "code/shape.h"
#include <vector>
class BreakoutBall :
	public Shape
{
public:
	BreakoutBall(float radie);
	~BreakoutBall(void);

	void render();
	void update();
	void setPos(float x, float y);
	float getRadie();

	Vector2D_v2 p1;
	Vector2D_v2 p2;
private:
	float _radie;
protected:


};

