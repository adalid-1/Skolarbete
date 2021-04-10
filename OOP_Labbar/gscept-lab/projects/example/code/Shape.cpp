#include "Shape.h"
#include "2d\2dapp.h"
#include "assignmentapp.h"


Shape::Shape(void)
{
	isPlayer = false;

}



Shape::~Shape(void)
{}

	void Shape::setPos(float x, float y)
	{

	_posRotMatrix.setPos(x, y);
	}

	Vector2D_v2 Shape::getPos()
	{
		


		return _posRotMatrix.getPos();
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

	void Shape::setVelocity(float x, float y)
	{
		_velocity.setX(x);
		_velocity.setY(y);

	}

	float Shape::getVelocityX()
	{
		return _velocity.getX();
	}

	float Shape::getVelocityY()
	{
		return _velocity.getY();
	}


	void Shape::render()
	{
		
	}

	void Shape::update()
	{
		_posRotMatrix.move(_velocity);
		int size = punkter.size();

		
		/*
		if (_posRotMatrix.getX() > 1 || _posRotMatrix.getX() < -1)
		{
			_velocity.setX(-1.0f * _velocity.getX());
		}
		if (_posRotMatrix.getY() > 1 || _posRotMatrix.getY() < -1)
		{
			_velocity.setY(-1.0f * _velocity.getY());
		}
		*/


		if (_posRotMatrix.getX() > 1)
		{
			//normal from right wall
			Vector2D_v2 rnormal(-1, 0);

			_velocity = _velocity.reflect(_velocity, rnormal);
		}
		else if (_posRotMatrix.getX() < -1)
		{
			//normal from left wall
			Vector2D_v2 lnormal(1, 0);

			_velocity = _velocity.reflect(_velocity, lnormal);
		}
		if (_posRotMatrix.getY() > 1)
		{
			//normal from top wall
			Vector2D_v2 tnormal(0, -1);

			_velocity = _velocity.reflect(_velocity, tnormal);
		}
		else if (_posRotMatrix.getY() < -1)
		{
			//normal from bottom wall
			Vector2D_v2 bnormal(0, 1);

			_velocity = _velocity.reflect(_velocity, bnormal);
		}




		

	}

	void Shape::rotate(float radian)
	{
		Matrix2D_v2 temp;
		temp = temp.secRotation(radian);
		_posRotMatrix = _posRotMatrix * temp.secRotation(radian);

		//float i0_0 = _posRotMatrix.get(0, 0) * temp.get(0, 0) + _posRotMatrix.get(0, 1) * temp.get(1, 0);	  //multiplicerar raderna i matris ett med kolumnerna från matris två. 
		//float i0_1 = _posRotMatrix.get(0, 0) * temp.get(0, 1) + _posRotMatrix.get(0, 1) * temp.get(1, 1);    //Sedan adderas produkterna så att man får 4 nya element. 
		//float i1_0 = _posRotMatrix.get(1, 0) * temp.get(0, 0) + _posRotMatrix.get(1, 1) * temp.get(1, 0);   //googla matris matrismultiplikation om du vill veta mer. 
		//float i1_1 = _posRotMatrix.get(1, 0) * temp.get(0, 1) + _posRotMatrix.get(1, 1) * temp.get(1, 1);  //
		//																			  //
		//_posRotMatrix.set(0, 0, i0_0);
		//_posRotMatrix.set(0, 1, i0_1);
		//_posRotMatrix.set(1, 0, i1_0);
		//_posRotMatrix.set(1, 1, i1_1);

	}
	