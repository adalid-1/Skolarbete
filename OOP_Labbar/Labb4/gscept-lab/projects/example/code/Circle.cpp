#include "Circle.h"
#include "assignmentapp.h"
#include "Vector2D.h"

Circle::Circle(float radie)
{
	_radie = radie;

		Vector2D radieVector(_radie, 0);
	Example::AssignmentApp::LineData line;
	
	
	float i = 0.0f;
	for(i; i<2.0f; i +=0.01f)
	{
	
	_rotMatrix = _rotMatrix.rotation(i*3.14f);
	Vector2D punkt = _rotMatrix * radieVector;
	_rotMatrix = _rotMatrix.rotation((i+0.01f)*3.14f);
	Vector2D punkt2 = _rotMatrix * radieVector;
	_rotMatrix = _rotMatrix.rotation(0.0f);
	
	punkter.push_back(punkt);
	punkter.push_back(punkt2);
	}
}


Circle::~Circle(void)
{
}

void Circle::render()
{

	Example::AssignmentApp::LineData line;
	line.c1.SetRgb(getColourR(), getColourG(), getColourB());
	line.c2.SetRgb(getColourR(), getColourG(), getColourB());


	for(int i =0 , iLen = punkter.size() - 2; i < iLen; i +=2)
	{
	Matrix2D temp;
	
	line.x1 = punkter[i].getX() + _posVector.getX();
	line.y1 = punkter[i].getY() + _posVector.getY();
	line.x2 = punkter[i + 1].getX() + _posVector.getX();
	line.y2 = punkter[i + 1].getY() + _posVector.getY();
	line.c1.g = 1.0;
	Example::AssignmentApp::DrawLine(line);
	
	}
	Example::AssignmentApp::DrawLine(line);

}




void Circle::setPos(float x, float y)
{
	 _posVector.setY(y);
	 _posVector.setX(x);


}



void Circle::rotate(float radian)
{
	Matrix2D temp;
	temp = temp.secRotation(radian);
	_rotMatrix = _rotMatrix * temp.secRotation(radian);

	for (int i = 0, iLen = punkter.size() - 2; i < iLen; i += 2)
	{
		punkter[i] = _rotMatrix * punkter[i];
		punkter[i + 1] = _rotMatrix * punkter[i + 1];
	}
	_rotMatrix.resetMat();
}
