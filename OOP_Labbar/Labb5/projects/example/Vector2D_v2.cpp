#include "Vector2D_v2.h"
#include<iostream>


//*******************************************************************************************************************************************************************
//Konstruktors

Vector2D_v2::Vector2D_v2(void)
{
	_Vector[0] = 0.0;
	_Vector[1] = 0.0;
	_Vector[2] = 1.0;
}

//Vi kommer att lagra x-värdet i index 0 och y-värde i index 1 som standard.
Vector2D_v2::Vector2D_v2(float x, float y)
{
	_Vector[0] = x;
	_Vector[1] = y;
	_Vector[2] = 1.0;
}

Vector2D_v2::Vector2D_v2(float x, float y, float z)
{
	_Vector[0] = x;
	_Vector[1] = y;
	_Vector[2] = z;

}


Vector2D_v2::Vector2D_v2(const Vector2D_v2& vOther)
{
	_Vector[0] = vOther._Vector[0];
	_Vector[1] = vOther._Vector[1];
	_Vector[2] = vOther._Vector[2];

}


//*******************************************************************************************************************************************************************
//Setters & Getters



float Vector2D_v2::getX()
{
	return _Vector[0];
}

float Vector2D_v2::getY()
{
	return _Vector[1];
}

float Vector2D_v2::getZ()
{
	return _Vector[2];
}

void Vector2D_v2::setX(float Xnew)
{
	_Vector[0] = Xnew;

}

void Vector2D_v2::setY(float Ynew)
{
	_Vector[1] = Ynew;

}

void Vector2D_v2::setZ(float Znew)
{
	_Vector[2] = Znew;
}

void Vector2D_v2::setXY(float Xnew, float Ynew)
{
	_Vector[0] = Xnew;
	_Vector[1] = Ynew;

}

//*******************************************************************************************************************************************************************
//Matematiska funktioner

//Adderar två vektorer
Vector2D_v2 Vector2D_v2::addVector(Vector2D_v2 vFirst, Vector2D_v2 vSecond)
{
	Vector2D_v2 vNew;                                                   //Skapar en ny vektor (innehåller resultatet av beräkningen)
	vNew._Vector[0] = vFirst._Vector[0] + vSecond._Vector[0];       //Nya vektorn får x-värde som är summan av två vektorers x-värde adderade
	vNew._Vector[1] = vFirst._Vector[1] + vSecond._Vector[1];	   //Nya vektorn får y-värde som är summan av två vektorers y-värde adderade
	return vNew;												  //Den nya vektorn returneras
}


//Subtraherar två vektorer
Vector2D_v2 Vector2D_v2::subVector(Vector2D_v2 vFirst, Vector2D_v2 vSecond)
{
	Vector2D_v2 vNew;													//Skapar en ny vektor (innehåller resultatet av beräkningen)
	vNew._Vector[0] = vFirst._Vector[0] - vSecond._Vector[0];      //Nya vektorn får x-värde som är differensen av två vektorers x-värden.
	vNew._Vector[1] = vFirst._Vector[1] - vSecond._Vector[1];     //Nya vektorn får y-värde som är differensen av två vektorers y-värden.
	return vNew;												 //Den nya vektorn returneras 
}

//multiplikation vektor med skalär
Vector2D_v2 Vector2D_v2::multScalarVector(float scalar, Vector2D_v2 Vector) //OBS skalären måste vara en float
{
	Vector2D_v2 newVec;											 //Skapar en ny vektor (innehåller resultatet av beräkningen)
	newVec._Vector[0] = scalar * Vector._Vector[0];			    //Nya vektorn får x-värde som är produkten av en skalär och det gammla x-värdet.
	newVec._Vector[1] = scalar * Vector._Vector[1];			   //Nya vektorn får y-värde som är produkten av en skalär och det gammla y-värdet.
	return newVec;											  //Den nya vektorn returneras


}

//Scalärprodukten av två vektorer
float Vector2D_v2::scalProdVector(Vector2D_v2 vFirst, Vector2D_v2 vSecond)
{
	float scalar = vFirst._Vector[0] * vSecond._Vector[0] + vFirst._Vector[1] * vSecond._Vector[1];
	//X-värdena från de inmatade vektorerna multipliceras och adderas med produkten av Y-värdena som också multiplicerats med varandra.

	return scalar;

}

//Längden av en vektor
float Vector2D_v2::lenVector(Vector2D_v2 Vector)
{
	float length = sqrt(Vector._Vector[0] * Vector._Vector[0] + Vector._Vector[1] * Vector._Vector[1]);
	//Längden av en vektor beräknas: sqrt(x^2 + y^2)
	return length;
}

//Enhets vektor
Vector2D_v2 Vector2D_v2::unitVector(Vector2D_v2 Vector)
{
	Vector2D_v2 Unit;													//Ny (enhets)vektor skapas
	Unit._Vector[0] = Vector._Vector[0] / lenVector(Vector);	   //x-värdet delas med längden av vektorn
	Unit._Vector[1] = Vector._Vector[1] / lenVector(Vector);	  //y-värdet delas med längden av vektorn

	return Unit;                                               //Vektorn returneras
}

Vector2D_v2 Vector2D_v2::reflect(Vector2D_v2 v, Vector2D_v2 n)
{
	return v - n * 2 * (v * n);
}



//*******************************************************************************************************************************************************************

//Logiska funktioner 
//är vektorerna lika? ==
bool Vector2D_v2::areEqual(Vector2D_v2 vFirst, Vector2D_v2 vSecond)
{
	if (vFirst._Vector[0] == vSecond._Vector[0] &&			//Om x-värden är likadana och
		vFirst._Vector[1] == vSecond._Vector[1] &&
		vFirst._Vector[2] == vSecond._Vector[2])		   //y-värden är samma så:
	{
		return true;
	}										  //Returnera true.

	return false;										//Annars returneras false.

}
//är vektorerna olika? !=
bool Vector2D_v2::areNotEqual(Vector2D_v2 vFirst, Vector2D_v2 vSecond)
{
	if (vFirst._Vector[0] != vSecond._Vector[0] &&		//Om x-värdena inte är likadana och
		vFirst._Vector[1] != vSecond._Vector[1] &&
		vFirst._Vector[2] != vSecond._Vector[2])       //y-värdena inte är samma så:
	{
		return true;
	}									  //Returnera true.

	return false;									//Annars returneras false. 

}




//*******************************************************************************************************************************************************************
//Operator överlagring
//Matematiska operatorer




//Operator överlagring Addition av vektorer
Vector2D_v2 Vector2D_v2::operator+(const Vector2D_v2& vSecond)
{
	//return addVector(*this, vSecond);                          FIXA SÅ ATT DESSA ANROPAR MOTSVARANDE FUNKTIONER SOM REDAN ÄR DEFINERADE
	Vector2D_v2 vNew;
	vNew._Vector[0] = _Vector[0] + vSecond._Vector[0];
	vNew._Vector[1] = _Vector[1] + vSecond._Vector[1];
	return vNew;
}
//Operator överlagring Subtraktion av vektorer
Vector2D_v2 Vector2D_v2::operator-(const Vector2D_v2& vSecond)
{
	Vector2D_v2 vNew;
	vNew._Vector[0] = _Vector[0] - vSecond._Vector[0];
	vNew._Vector[1] = _Vector[1] - vSecond._Vector[1];
	return vNew;
}

//Operator överlagring multiplikation skalär med vektor
Vector2D_v2 Vector2D_v2::operator*(const float& scalar)
{
	Vector2D_v2 newVec;
	newVec._Vector[0] = scalar * _Vector[0];
	newVec._Vector[1] = scalar * _Vector[1];
	return newVec;

}

//Operator överlagring skalärprodukt
float Vector2D_v2::operator*(const Vector2D_v2& vSecond)
{
	float scalar = _Vector[0] * vSecond._Vector[0] + _Vector[1] * vSecond._Vector[1];

	return scalar;

}


//*******************************************************************************************************************************************************************
//Logiska operatorer


//Operator överlagring jämförelse med == 
bool Vector2D_v2::operator==(const Vector2D_v2& vSecond)
{
	if (_Vector[0] == vSecond._Vector[0] &&
		_Vector[0] == vSecond._Vector[0])
	{
		return true;
	}

	return false;

}

//Operator överlagring jämförelse med !=
bool Vector2D_v2::operator!=(const Vector2D_v2& vSecond)
{
	if (_Vector[0] != vSecond._Vector[0] &&
		_Vector[0] != vSecond._Vector[0])
	{
		return true;
	}

	return false;

}
//*******************************************************************************************************************************************************************
//Tilldelnings-operator =


Vector2D_v2 Vector2D_v2::operator=(const Vector2D_v2& vOther)
{

	this->_Vector[0] = vOther._Vector[0];
	this->_Vector[1] = vOther._Vector[1];
	this->_Vector[2] = vOther._Vector[2];
	return *this;
}



//*******************************************************************************************************************************************************************
//Destructor
Vector2D_v2::~Vector2D_v2(void)
{


}
