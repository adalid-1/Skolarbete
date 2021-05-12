#include "Circle.h"
#include "assignmentapp.h"
#include "Vector2D.h"

Circle::Circle(float radie)
{
	_radie = radie;

		Vector2D_v2 radieVector(_radie, 0);
	Example::AssignmentApp::LineData line;
	
	
	float i = 0.0f;
	float linelength = 0.05f;
	for(i; i<2.0f; i += linelength)
	{
	_posRotMatrix = _posRotMatrix.rotation(i*3.14f);
	Vector2D_v2 punkt = _posRotMatrix * radieVector;
	_posRotMatrix = _posRotMatrix.rotation((i+ linelength)*3.14f);
	Vector2D_v2 punkt2 = _posRotMatrix * radieVector;
	_posRotMatrix = _posRotMatrix.rotation(0.0f);
	
	punkter.push_back(punkt);
	punkter.push_back(punkt2);
	}
}


float Circle::getRadie()
{
	return _radie;
}

void Circle::rotate(float radian)
{
	Matrix2D_v2 temp;
	temp = temp.secRotation(radian);
	_posRotMatrix = _posRotMatrix * temp.secRotation(radian);

	for (int i = 0, iLen = punkter.size() - 2; i < iLen; i += 2)
	{
		punkter[i] = _posRotMatrix * punkter[i];
		punkter[i + 1] = _posRotMatrix * punkter[i + 1];
	}
	_posRotMatrix.resetRotation();
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
	line.x1 = punkter[i].getX() + _posRotMatrix.getX();
	line.y1 = punkter[i].getY() + _posRotMatrix.getY();
	line.x2 = punkter[i + 1].getX() + _posRotMatrix.getX();
	line.y2 = punkter[i + 1].getY() + _posRotMatrix.getY();
	line.c1.g = 1.0;
	Example::AssignmentApp::DrawLine(line);
	}
	Example::AssignmentApp::DrawLine(line);

}




void Circle::setPos(float x, float y)
{
	 _posRotMatrix.setPos(x, y);
}