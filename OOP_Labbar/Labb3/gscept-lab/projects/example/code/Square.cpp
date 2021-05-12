#include "Square.h"
#include "assignmentapp.h"
#include "Vector2D.h"



Square::Square(float sidan)
{
	halfSideLen = sidan/2.0;
	//Find corners
	bottomLeft.setXY( - halfSideLen,  - halfSideLen);
	bottomRight.setXY(  + halfSideLen,  - halfSideLen);
	TopRight.setXY( + halfSideLen,  + halfSideLen);
	TopLeft.setXY( - halfSideLen,  + halfSideLen);
	_posVector.setXY(0.0,0.0);
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
	//Line colours
	line.c1.SetRgb(getColourR(), getColourG(), getColourB());
	line.c2.SetRgb(getColourR(), getColourG(), getColourB());

	//Making lines
	line.x1 = bottomLeft.getX()+ _posVector.getX();
	line.y1 = bottomLeft.getY()+ _posVector.getY();
	line.x2 = bottomRight.getX()+ _posVector.getX();
	line.y2 = bottomRight.getY()+ _posVector.getY();
	Example::AssignmentApp::DrawLine(line);

	line.x1 = bottomRight.getX()+ _posVector.getX();
	line.y1 = bottomRight.getY()+ _posVector.getY();
	line.x2 = TopRight.getX()+ _posVector.getX();
	line.y2 = TopRight.getY()+ _posVector.getY();
	Example::AssignmentApp::DrawLine(line);

	line.x1 = TopRight.getX()+ _posVector.getX();
	line.y1 = TopRight.getY()+ _posVector.getY();
	line.x2 = TopLeft.getX()+ _posVector.getX();
	line.y2 = TopLeft.getY()+ _posVector.getY();
	Example::AssignmentApp::DrawLine(line);

	line.x1 = TopLeft.getX()+ _posVector.getX();
	line.y1 = TopLeft.getY()+ _posVector.getY();
	line.x2 = bottomLeft.getX()+ _posVector.getX();
	line.y2 = bottomLeft.getY()+ _posVector.getY();
	Example::AssignmentApp::DrawLine(line);
}

