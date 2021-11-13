#include "Square.h"
#include "assignmentapp.h"
#include "Vector2D.h"



Square::Square(float sidan)
{
	sida = sidan;
	hSida = sidan/2.0;
}


Square::~Square(void)
{
}

void Square::setPos(float x, float y)
{
	_posVector.setXY(x, y);

}

void Square::render()
{
	Example::AssignmentApp::LineData line;
	Vector2D v1;
	Vector2D v2;
	Vector2D v3;
	Vector2D v4;

	v1.setXY( _posVector.getX() - hSida, _posVector.getY() - hSida);
	v2.setXY( _posVector.getX() + hSida, _posVector.getY() - hSida);
	v3.setXY(_posVector.getX() + hSida, _posVector.getY() + hSida);
	v4.setXY(_posVector.getX() - hSida, _posVector.getY() + hSida);

	line.x1 = v1.getX();
	line.y1 = v1.getY();
	line.x2 = v2.getX();
	line.y2 = v2.getY();
	//line.c1.b = getColour;
	Example::AssignmentApp::DrawLine(line);
	line.x1 = v2.getX();
	line.y1 = v2.getY();
	line.x2 = v3.getX();
	line.y2 = v3.getY();
	Example::AssignmentApp::DrawLine(line);
	line.x1 = v3.getX();
	line.y1 = v3.getY();
	line.x2 = v4.getX();
	line.y2 = v4.getY();
	Example::AssignmentApp::DrawLine(line);
	line.x1 = v4.getX();
	line.y1 = v4.getY();
	line.x2 = v1.getX();
	line.y2 = v1.getY();
	Example::AssignmentApp::DrawLine(line);



}