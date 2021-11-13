#include "Square.h"
#include "assignmentapp.h"
#include "Vector2D.h"



Square::Square(float sidan)
{
	sida = sidan;
	hSida = sidan/2.0;
	
	

	bottomLeft.setXY( - hSida,  - hSida);
	bottomRight.setXY(  + hSida,  - hSida);
	TopRight.setXY( + hSida,  + hSida);
	TopLeft.setXY( - hSida,  + hSida);
	_posVector.setXY(0.0,0.0);
	
	
}

Square::Square(float sidan, float x, float y)
{
	sida = sidan;
	hSida = sidan / 2.0f;



	bottomLeft.setXY(-hSida, -hSida);
	bottomRight.setXY(+hSida, -hSida);
	TopRight.setXY(+hSida, +hSida);
	TopLeft.setXY(-hSida, +hSida);
	_posVector.setXY(x, y);


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
	line.c1.SetRgb(getColourR(), getColourG(), getColourB());
	line.c2.SetRgb(getColourR(), getColourG(), getColourB());


	

	line.x1 = bottomLeft.getX()+ _posVector.getX();
	line.y1 = bottomLeft.getY()+ _posVector.getY();
	line.x2 = bottomRight.getX()+ _posVector.getX();
	line.y2 = bottomRight.getY()+ _posVector.getY();
	//line.c1.b = getColour;
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

void Square::rotate(float radian)
{
	Matrix2D temp;
	temp = temp.secRotation(radian);
	_rotMatrix = _rotMatrix * temp.secRotation(radian);

	bottomLeft = _rotMatrix * bottomLeft;
	bottomRight = _rotMatrix * bottomRight;
	TopRight = _rotMatrix * TopRight;
	TopLeft = _rotMatrix * TopLeft;
	_rotMatrix.resetMat();
}


