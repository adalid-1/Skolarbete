#include "Triangle.h"
#include "assignmentapp.h"
#include "Vector2D.h"

Triangle::Triangle(float base, float height)
{
	_base = base;
	_height = height;
	

	bottomLeft.setXY(-_base / 2, -_height / 2);
	bottomRight.setXY(+_base / 2, -_height / 2);
	top.setXY(0.0, +_height / 2);
	_posRotMatrix.setPos(0.00001, 0.0001);
}
Triangle::~Triangle(void)
{
	
	
}

float Triangle::getBase()
{
return _base;
}
	
float Triangle::getHeight()
{
return _height;
}

void Triangle::setPos(float x, float y)
{
 _posRotMatrix.setPos(x, y);

}

void Triangle::render()
{
	Example::AssignmentApp::LineData line;

	
	line.c1.SetRgb(getColourR(), getColourG(), getColourB());
	line.c2.SetRgb(getColourR(), getColourG(), getColourB());

	


	//vektorerna roterar
	
	bottomLeft = _posRotMatrix * bottomLeft;
	bottomRight = _posRotMatrix * bottomRight;
	top = _posRotMatrix * top; 
	_posRotMatrix.resetMat();

	
	line.x1 = bottomLeft.getX()+ _posRotMatrix.getX();
	line.y1 = bottomLeft.getY() + _posRotMatrix.getY();
	line.x2 = bottomRight.getX() + _posRotMatrix.getX();
	line.y2 = bottomRight.getY() + _posRotMatrix.getY();
	//line.c1.g = getColourR();
	//line.c2.g = getColourG();
	Example::AssignmentApp::DrawLine(line);
	line.x1 = bottomRight.getX() + _posRotMatrix.getX();
	line.y1 = bottomRight.getY() + _posRotMatrix.getY();
	line.x2 = top.getX() + _posRotMatrix.getX();
	line.y2 = top.getY() + _posRotMatrix.getY();
	Example::AssignmentApp::DrawLine(line);
	line.x1 = top.getX() + _posRotMatrix.getX();
	line.y1 = top.getY() + _posRotMatrix.getY();
	line.x2 = bottomLeft.getX() + _posRotMatrix.getX();
	line.y2 = bottomLeft.getY() + _posRotMatrix.getY();
	Example::AssignmentApp::DrawLine(line);



}


void Triangle::rota(float radian){






}