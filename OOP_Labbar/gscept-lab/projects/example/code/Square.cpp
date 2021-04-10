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
	_posRotMatrix.setPos(0.0,0.0);
	
	punkter.push_back(bottomLeft);
	punkter.push_back(bottomRight);
	punkter.push_back(TopRight);
	punkter.push_back(TopLeft);

	punkter2.push_back(Vector2D_v2());
	punkter2.push_back(Vector2D_v2());
	punkter2.push_back(Vector2D_v2());
	punkter2.push_back(Vector2D_v2());
	
}

Square::Square(float sidan, float x, float y)
{
	sida = sidan;
	hSida = sidan / 2.0f;



	bottomLeft.setXY(-hSida, -hSida);
	bottomRight.setXY(+hSida, -hSida);
	TopRight.setXY(+hSida, +hSida);
	TopLeft.setXY(-hSida, +hSida);
	
	_posRotMatrix.setPos(x, y);


}



Square::~Square(void)
{
}

void Square::setPos(float x, float y)
{
	_posRotMatrix.setPos(x, y);

}

//void Square::rotate(float radians)
//{
//	_posRotMatrix = _posRotMatrix.rotation(radians);
//	bottomLeft = _posRotMatrix * bottomLeft;
//	bottomRight = _posRotMatrix * bottomRight;
//	TopRight = _posRotMatrix * TopRight;
//	TopLeft = _posRotMatrix * TopLeft;
//	//_posRotMatrix = Matrix2D();
//
//	//bottomLeft.setXY((_posRotMatrix * bottomLeft).getX(), (_posRotMatrix * bottomLeft).getY());
//	//bottomRight.setXY((_posRotMatrix * bottomRight).getX(), (_posRotMatrix * bottomRight).getY());
//	//TopRight.setXY((_posRotMatrix * TopRight).getX(), (_posRotMatrix * TopRight).getY());
//	//TopLeft.setXY((_posRotMatrix * TopLeft).getX(), (_posRotMatrix * TopLeft).getY());
//	//
//
//}

void Square::render()
{
	Example::AssignmentApp::LineData line;
	line.c1.SetRgb(getColourR(), getColourG(), getColourB());
	line.c2.SetRgb(getColourR(), getColourG(), getColourB());

	//Vector2D_v2 btmLeft = _posRotMatrix * bottomLeft;
	bottomLeft = _posRotMatrix * bottomLeft;
	bottomRight = _posRotMatrix * bottomRight;
	TopRight = _posRotMatrix * TopRight;
	TopLeft = _posRotMatrix * TopLeft;
	_posRotMatrix.resetMat();
	

	line.x1 = bottomLeft.getX()+ _posRotMatrix.getX();
	line.y1 = bottomLeft.getY()+ _posRotMatrix.getY();
	line.x2 = bottomRight.getX()+ _posRotMatrix.getX();
	line.y2 = bottomRight.getY()+ _posRotMatrix.getY();
	Example::AssignmentApp::DrawLine(line);
	//Btm left
	punkter2[0].setXY(line.x1, line.y1);
	//Btm Right
	punkter2[1].setXY(line.x2, line.y2);

	line.x1 = bottomRight.getX()+ _posRotMatrix.getX();
	line.y1 = bottomRight.getY()+ _posRotMatrix.getY();
	line.x2 = TopRight.getX()+ _posRotMatrix.getX();
	line.y2 = TopRight.getY()+ _posRotMatrix.getY();
	Example::AssignmentApp::DrawLine(line);
	punkter[2].setXY(line.x2, line.y2);
	

	line.x1 = TopRight.getX()+ _posRotMatrix.getX();
	line.y1 = TopRight.getY()+ _posRotMatrix.getY();
	line.x2 = TopLeft.getX()+ _posRotMatrix.getX();
	line.y2 = TopLeft.getY()+ _posRotMatrix.getY();
	Example::AssignmentApp::DrawLine(line);

	line.x1 = TopLeft.getX()+ _posRotMatrix.getX();
	line.y1 = TopLeft.getY()+ _posRotMatrix.getY();
	line.x2 = bottomLeft.getX()+ _posRotMatrix.getX();
	line.y2 = bottomLeft.getY()+ _posRotMatrix.getY();
	Example::AssignmentApp::DrawLine(line);

	line.x1 = bottomRight.getX() + _posRotMatrix.getX();

	//line.x1 = bottomLeft.getX();
	//line.y1 = bottomLeft.getY() ;
	//line.x2 = bottomRight.getX();
	//line.y2 = bottomRight.getY();
	////line.c1.b = getColour;
	//Example::AssignmentApp::DrawLine(line);
	//line.x1 = bottomRight.getX();
	//line.y1 = bottomRight.getY();
	//line.x2 = TopRight.getX() ;
	//line.y2 = TopRight.getY() ;
	//Example::AssignmentApp::DrawLine(line);
	//line.x1 = TopRight.getX() ;
	//line.y1 = TopRight.getY() ;
	//line.x2 = TopLeft.getX() ;
	//line.y2 = TopLeft.getY() ;
	//Example::AssignmentApp::DrawLine(line);
	//line.x1 = TopLeft.getX();
	//line.y1 = TopLeft.getY() ;
	//line.x2 = bottomLeft.getX() ;
	//line.y2 = bottomLeft.getY() ;
	//Example::AssignmentApp::DrawLine(line);

}

