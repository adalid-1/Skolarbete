#include "Circle.h"
#include "assignmentapp.h"
#include "Vector2D.h"

Circle::Circle(float radie)
{
	_radie = radie;

	Vector2D radieVector(_radie, 0);
	Example::AssignmentApp::LineData line;
	
	//Setup points around center
	float linelength = 0.05;
	for(float i = 0.0f; i<2.0f; i += linelength)
	{
	_rotMatrix = _rotMatrix.rotation(i*3.14f);
	Vector2D punkt = _rotMatrix * radieVector;
	_rotMatrix = _rotMatrix.rotation((i+ linelength)*3.14f);
	Vector2D punkt2 = _rotMatrix * radieVector;

	punkter.push_back(punkt);
	punkter.push_back(punkt2);
	}
}

Circle::~Circle(void)
{}

void Circle::render()
{
	Example::AssignmentApp::LineData line;
	line.c1.SetRgb(getColourR(), getColourG(), getColourB());
	line.c2.SetRgb(getColourR(), getColourG(), getColourB());

	for(int i =0 , iLen = punkter.size() - 2; i <= iLen; i +=2)
	{
	line.x1 = punkter[i].getX() + _posVector.getX();
	line.y1 = punkter[i].getY() + _posVector.getY();
	line.x2 = punkter[i + 1].getX() + _posVector.getX();
	line.y2 = punkter[i + 1].getY() + _posVector.getY();
	line.c1.g = 1.0;
	Example::AssignmentApp::DrawLine(line);
	}
}

void Circle::setPos(float x, float y)
{
	 _posVector.setY(y);
	 _posVector.setX(x);
}