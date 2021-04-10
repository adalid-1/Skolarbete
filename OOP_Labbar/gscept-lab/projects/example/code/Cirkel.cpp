#include "Cirkel.h"
#include "assignmentapp.h"
#include "Vector2D.h"

Cirkel::Cirkel(float radie)
{
	_radie = radie;

		Vector2D_v2 radieVector(_radie, 0);
	Example::AssignmentApp::LineData line;
	
	
	float i = 0.0f;
	for(i; i<2.0f; i +=0.01f)
	{
	
	_posRotMatrix = _posRotMatrix.rotation(i*3.14f);
	Vector2D_v2 punkt = _posRotMatrix * radieVector;
	_posRotMatrix = _posRotMatrix.rotation((i+0.01f)*3.14f);
	Vector2D_v2 punkt2 = _posRotMatrix * radieVector;
	_posRotMatrix = _posRotMatrix.rotation(0.0f);
	
	punkter.push_back(punkt);
	punkter.push_back(punkt2);
	}
}


Cirkel::~Cirkel(void)
{
}

void Cirkel::render()
{

	Example::AssignmentApp::LineData line;
	line.c1.SetRgb(getColourR(), getColourG(), getColourB());
	line.c2.SetRgb(getColourR(), getColourG(), getColourB());


	for(int i =0 , iLen = punkter.size() - 2; i < iLen; i +=2)
	{

	
	
	Matrix2D temp;
	
	punkter[i] = _posRotMatrix * punkter[i];
	punkter[i+1] = _posRotMatrix * punkter[i+1];



	line.x1 = punkter[i].getX() + _posRotMatrix.getX();
	line.y1 = punkter[i].getY() + _posRotMatrix.getY();
	line.x2 = punkter[i + 1].getX() + _posRotMatrix.getX();
	line.y2 = punkter[i + 1].getY() + _posRotMatrix.getY();
	line.c1.g = 1.0;
	Example::AssignmentApp::DrawLine(line);
	
	}

	_posRotMatrix.resetMat();

	Example::AssignmentApp::DrawLine(line);
	
	
	
	
	
}




void Cirkel::setPos(float x, float y)
{
	 _posRotMatrix.setPos(x, y);


}