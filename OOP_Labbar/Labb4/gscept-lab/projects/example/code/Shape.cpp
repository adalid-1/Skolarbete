#include "Shape.h"
#include "2d\2dapp.h"
#include "assignmentapp.h"


Shape::Shape(void)
{


}



Shape::~Shape(void)
{}

	void Shape::setPos(float x, float y)
	{
	_posVector.setXY(x,y);
	}

	void Shape::MoveX(float speed)
	{
		_posVector.setX(_posVector.getX() + speed);
	}

	void Shape::MoveY(float speed)
	{
		_posVector.setY(_posVector.getY() + speed);
	}

	float Shape::getColourR()
	{return _colourR;}
	float Shape::getColourG()
	{return _colourG;}
	float Shape::getColourB()
	{
		return _colourB;
	}

	void Shape::setColourR(float colour)
	{_colourR = colour;}
	void Shape::setColourG(float colour)
	{_colourG = colour;}
	void Shape::setColourB(float colour)
	{
		_colourB = colour;
	}
	void Shape::setColours(float colourR, float colourG, float colourB)
	{
	_colourR = colourR;
	_colourG = colourG;
	_colourB = colourB;
	}


	void Shape::render()
	{
		
	}

	
	 void Shape::rotate(float radian)
	{
		Matrix2D temp;
		_rotMatrix = _rotMatrix.rotation(radian);
	
	}
	