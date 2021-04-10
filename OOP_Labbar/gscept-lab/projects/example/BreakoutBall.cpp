#include "BreakoutBall.h"
#include "code/assignmentapp.h"
#include "Vector2D_v2.h"

BreakoutBall::BreakoutBall(float radie)
{
	_radie = radie;

	Vector2D_v2 radieVector(_radie, 0);
	Example::AssignmentApp::LineData line;


	
	for (float i = 0.0f; i < 2.2f; i += 0.04f)
	{

		_posRotMatrix = _posRotMatrix.rotation(i*3.14f);
		Vector2D_v2 punkt = _posRotMatrix * radieVector;
		_posRotMatrix = _posRotMatrix.rotation((i + 0.04f)*3.14f);
		Vector2D_v2 punkt2 = _posRotMatrix * radieVector;
		

		punkter.push_back(punkt);
		punkter.push_back(punkt2);
	}
}


BreakoutBall::~BreakoutBall(void)
{
}

void BreakoutBall::render()
{

	Example::AssignmentApp::LineData line;
	line.c1.SetRgb(getColourR(), getColourG(), getColourB());
	line.c2.SetRgb(getColourR(), getColourG(), getColourB());

	
	for (int i = 0, iLen = punkter.size() - 2; i < iLen; i += 2)
	{



		Matrix2D temp;

		punkter[i] = _posRotMatrix * punkter[i];
		punkter[i + 1] = _posRotMatrix * punkter[i + 1];



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


void BreakoutBall::update()
{
	

}



void BreakoutBall::setPos(float x, float y)
{
	_posRotMatrix.setPos(x, y);


}

float BreakoutBall::getRadie()
{
	return _radie;
}
