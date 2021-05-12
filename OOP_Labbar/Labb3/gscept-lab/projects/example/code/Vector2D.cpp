#include "Vector2D.h"
#include<iostream>


//*******************************************************************************************************************************************************************
//Konstruktors

Vector2D::Vector2D(void)
{
	_Vector[0] = 0.0;
	_Vector[1] = 0.0;
}

//Vi kommer att lagra x-v�rdet i index 0 och y-v�rde i index 1 som standard.
Vector2D::Vector2D(float x, float y)
{
	_Vector[0] = x;
	_Vector[1] = y;
}


Vector2D::Vector2D(const Vector2D& vOther)
{
	_Vector[0] = vOther._Vector[0];
	_Vector[1] = vOther._Vector[1];
	
}


//*******************************************************************************************************************************************************************
//Setters & Getters



float Vector2D::getX() 
{return _Vector[0];}

float Vector2D::getY()
{return _Vector[1];}

void Vector2D::setX(float Xnew)
{
	_Vector[0] = Xnew;

}

void Vector2D::setY(float Ynew)
{
	_Vector[1] = Ynew;

}

void Vector2D::setXY(float Xnew, float Ynew)
{
	_Vector[0] = Xnew;
	_Vector[1] = Ynew;

}

//*******************************************************************************************************************************************************************
//Matematiska funktioner

//Adderar tv� vektorer
Vector2D Vector2D::addVector(Vector2D vFirst, Vector2D vSecond)
{
	Vector2D vNew;                                                   //Skapar en ny vektor (inneh�ller resultatet av ber�kningen)
	vNew._Vector[0] = vFirst._Vector[0] + vSecond._Vector[0];       //Nya vektorn f�r x-v�rde som �r summan av tv� vektorers x-v�rde adderade
	vNew._Vector[1] = vFirst._Vector[1] + vSecond._Vector[1];	   //Nya vektorn f�r y-v�rde som �r summan av tv� vektorers y-v�rde adderade
	return vNew;												  //Den nya vektorn returneras
} 


//Subtraherar tv� vektorer
Vector2D Vector2D::subVector(Vector2D vFirst, Vector2D vSecond)
{
	Vector2D vNew;													//Skapar en ny vektor (inneh�ller resultatet av ber�kningen)
	vNew._Vector[0] = vFirst._Vector[0] - vSecond._Vector[0];      //Nya vektorn f�r x-v�rde som �r differensen av tv� vektorers x-v�rden.
	vNew._Vector[1] = vFirst._Vector[1] - vSecond._Vector[1];     //Nya vektorn f�r y-v�rde som �r differensen av tv� vektorers y-v�rden.
	return vNew;												 //Den nya vektorn returneras 
}

//multiplikation vektor med skal�r
Vector2D Vector2D::multScalarVector(float scalar, Vector2D Vector) //OBS skal�ren m�ste vara en float
{
	Vector2D newVec;											 //Skapar en ny vektor (inneh�ller resultatet av ber�kningen)
	newVec._Vector[0] = scalar * Vector._Vector[0];			    //Nya vektorn f�r x-v�rde som �r produkten av en skal�r och det gammla x-v�rdet.
	newVec._Vector[1] = scalar * Vector._Vector[1];			   //Nya vektorn f�r y-v�rde som �r produkten av en skal�r och det gammla y-v�rdet.
	return newVec;											  //Den nya vektorn returneras


}

//Scal�rprodukten av tv� vektorer
float Vector2D::scalProdVector(Vector2D vFirst, Vector2D vSecond)
{
	float scalar = vFirst._Vector[0] * vSecond._Vector[0] + vFirst._Vector[1] * vSecond._Vector[1];
	//X-v�rdena fr�n de inmatade vektorerna multipliceras och adderas med produkten av Y-v�rdena som ocks� multiplicerats med varandra.

	return scalar; 

}

//L�ngden av en vektor
float Vector2D::lenVector(Vector2D Vector)	
{
	float length = sqrt(Vector._Vector[0]*Vector._Vector[0] +Vector._Vector[1]*Vector._Vector[1]);
	//L�ngden av en vektor ber�knas: sqrt(x^2 + y^2)
	return length;
}

//Enhets vektor
Vector2D Vector2D::unitVector(Vector2D Vector)
{
	Vector2D Unit;													//Ny (enhets)vektor skapas
	 Unit._Vector[0] = Vector._Vector[0] / lenVector(Vector);	   //x-v�rdet delas med l�ngden av vektorn
	 Unit._Vector[1] = Vector._Vector[1] / lenVector(Vector);	  //y-v�rdet delas med l�ngden av vektorn
	
	 return Unit;                                               //Vektorn returneras
}



//*******************************************************************************************************************************************************************

//Logiska funktioner 
//�r vektorerna lika? ==
bool Vector2D::areEqual(Vector2D vFirst, Vector2D vSecond)
{
	if(vFirst._Vector[0] == vSecond._Vector[0] &&			//Om x-v�rden �r likadana och
		vFirst._Vector[1] == vSecond._Vector[1])		   //y-v�rden �r samma s�:
	{return true;}										  //Returnera true.

	return false;										//Annars returneras false.

}
//�r vektorerna olika? !=
bool Vector2D::areNotEqual(Vector2D vFirst, Vector2D vSecond)
{
	if(vFirst._Vector[0] != vSecond._Vector[0] &&		//Om x-v�rdena inte �r likadana och
		vFirst._Vector[1] != vSecond._Vector[1])       //y-v�rdena inte �r samma s�:
	{return true;}									  //Returnera true.

	return false;									//Annars returneras false. 

}




//*******************************************************************************************************************************************************************
//Operator �verlagring
//Matematiska operatorer




//Operator �verlagring Addition av vektorer
Vector2D Vector2D::operator+(const Vector2D& vSecond)
{
	//return addVector(*this, vSecond);                          FIXA S� ATT DESSA ANROPAR MOTSVARANDE FUNKTIONER SOM REDAN �R DEFINERADE
	Vector2D vNew;												
	vNew._Vector[0] = _Vector[0] + vSecond._Vector[0];
	vNew._Vector[1] = _Vector[1] + vSecond._Vector[1];
	return vNew;
}
//Operator �verlagring Subtraktion av vektorer
Vector2D Vector2D::operator-(const Vector2D& vSecond)
{
	Vector2D vNew;
	vNew._Vector[0] = _Vector[0] - vSecond._Vector[0];
	vNew._Vector[1] = _Vector[1] - vSecond._Vector[1];
	return vNew;
}

	//Operator �verlagring multiplikation skal�r med vektor
Vector2D Vector2D::operator*(const float& scalar)
{
	Vector2D newVec;
	newVec._Vector[0] = scalar * _Vector[0];
	newVec._Vector[1] = scalar * _Vector[1];
	return newVec;

}

//Operator �verlagring skal�rprodukt
float Vector2D::operator*(const Vector2D& vSecond)
{
	float scalar = _Vector[0] * vSecond._Vector[0] + _Vector[1] * vSecond._Vector[1];

	return scalar; 

}


//*******************************************************************************************************************************************************************
//Logiska operatorer


//Operator �verlagring j�mf�relse med == 
bool Vector2D::operator==(const Vector2D& vSecond)
{
	if(_Vector[0] == vSecond._Vector[0] && 
		_Vector[0] == vSecond._Vector[0])
	{return true;}

	return false;

}

//Operator �verlagring j�mf�relse med !=
bool Vector2D::operator!=(const Vector2D& vSecond)
{
	if(_Vector[0] != vSecond._Vector[0] && 
		_Vector[0] != vSecond._Vector[0])
	{return true;}

	return false;

}

//*******************************************************************************************************************************************************************
//Tilldelnings-operator =


Vector2D Vector2D::operator=(const Vector2D& vOther)
{
    
	this->_Vector[0] = vOther._Vector[0];
	this->_Vector[1] = vOther._Vector[1];
	return *this;


    
}



//*******************************************************************************************************************************************************************
//Destructor


Vector2D::~Vector2D(void)
{


}
