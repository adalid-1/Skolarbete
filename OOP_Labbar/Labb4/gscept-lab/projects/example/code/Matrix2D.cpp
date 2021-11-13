#include "Matrix2D.h"
#include "Vector2D.h"
#include "Math.h"

//*******************************************************************************************************************************************************************
//Konstruktors

//Initiera matris med givna v�rden
Matrix2D::Matrix2D(float i0_0, float i0_1, float i1_0,float i1_1)
{
	_matrix[0][0]= i0_0;
	_matrix[0][1]= i0_1;
	_matrix[1][0]= i1_0;
	_matrix[1][1]= i1_1;
}

//Default, identitetsmatris
Matrix2D::Matrix2D(void)
{
	set(0, 0, 1.0);
	set(0, 1, 0.0);
	set(1, 0, 0.0);
	set(1, 1, 1.0);
}
//Kopieringskonstruktor
Matrix2D::Matrix2D(Matrix2D& matOther)
{
	set(0, 0, matOther.get(0, 0));//Fixa 
	set(0, 1, matOther.get(0, 1));
	set(1, 0, matOther.get(1, 0));
	set(1, 1, matOther.get(1, 1));

}

void Matrix2D::resetMat()
{
	_matrix[0][0] = 1.0;
	_matrix[0][1] = 0;

	_matrix[1][0] = 0;
	_matrix[1][1] = 1.0;
}


//Rotationsmatris, skapar en rotationsmatris som man kan anv�nda f�r att snurra p� saker. 
Matrix2D Matrix2D::rotation(const float radians)
{
	Matrix2D rotationMatrix(cos(radians), -sin(radians), sin(radians), cos(radians));

	return rotationMatrix;
}

Matrix2D Matrix2D::secRotation(const float radians)
{
return ((Matrix2D(cos(radians), -(sin(radians)), sin(radians), cos(radians)))*(Matrix2D(_matrix[0][0], _matrix[0][1], _matrix[1][0], _matrix[1][1])));

}
//*******************************************************************************************************************************************************************
//Setter & Getter


float Matrix2D::get(int row, int elem)
{
	return _matrix[row][elem];

}

void Matrix2D::set(int row, int elem, float value)
{
	_matrix[row][elem] = value;

}

void Matrix2D::setAll(float i00, float i01, float i10, float i11)
{
	_matrix[0][0] = i00;
	_matrix[0][1] = i01;
	_matrix[1][0] = i10;
	_matrix[1][1] = i11; 


}



//*******************************************************************************************************************************************************************
//Matris-specifika r�knemetoder

//Metod f�r att f� transponatet av en matris
Matrix2D Matrix2D::transpose()
{
	Matrix2D newMat(get(0, 0), get(1, 0), get(0, 1), get(1, 1));
	return newMat;
}

//Metod f�r att multiplicera tv� matriser, *operatorn �verlagrad
Matrix2D Matrix2D::operator*(Matrix2D& matOther)
{
	
	float i0_0 = get(0, 0) * matOther.get(0, 0) + get(0, 1) * matOther.get(1, 0);	  //multiplicerar raderna i matris ett med kolumnerna fr�n matris tv�. 
	float i0_1 = get(0, 0) * matOther.get(0, 1) + get(0, 1) * matOther.get(1, 1);    //Sedan adderas produkterna s� att man f�r 4 nya element. 
	float i1_0 = get(1, 0) * matOther.get(0, 0) + get(1, 1) * matOther.get(1, 0);   //googla matris matrismultiplikation om du vill veta mer. 
	float i1_1 = get(1, 0) * matOther.get(0, 1) + get(1, 1) * matOther.get(1, 1);  //
																				  //
	Matrix2D product(i0_0, i0_1, i1_0, i1_1);                                    //Skapar en ny matris med produkterna fr�n utr�kningarna ovan.                                
	return product;																//som returneras.
}

//Metod f�r att transformera en 2Dvektor.  *operatorn �verlagrad
Vector2D Matrix2D::operator*(Vector2D& vector)                               
{
	float newX = get(0, 0) * vector.getX() + get(0, 1) * vector.getY();			//multiplicerar elementen i raderna med elementen i kolumnen som vektorn utg�r
	float newY = get(1, 0) * vector.getX() + get(1, 1) * vector.getY();		   //och adderar sedan produkterna s� att man f�r 2 element som utg�r den nya vektorn
																			  //
	Vector2D newVector(newX, newY);                                          //Den nya vektorn skapas med v�rdena fr�n utr�kningarna ovan och returneras. 
	return newVector;
}
/*
//Metod f�r att multiplicera ihop element i en matris
Matrix2D Matrix2D::operator()(Matrix2D& Matris)
{
	Matrix2D newMatrix; 
	newMatrix._matrix[0][0] = _matrix[0][0] * Matris._matrix[0][0];
	newMatrix._matrix[0][1] = _matrix[0][1] * Matris._matrix[0][1];
	newMatrix._matrix[1][0] = _matrix[1][0] * Matris._matrix[1][0];
	newMatrix._matrix[1][1] = _matrix[1][1] * Matris._matrix[1][1];
	
	return newMatrix;


}
*/


//*******************************************************************************************************************************************************************
//Tilldelnings-operator =
//Fungerar som vanlig tilldelning, elementen kopieras �ver fr�n v�nster matris till motsvarande index i h�ger matris. 
void Matrix2D::operator=(Matrix2D& matOther)     
{
	set(0, 0, matOther.get(0, 0));
	set(0, 1, matOther.get(0, 1));
	set(1, 0, matOther.get(1, 0));
	set(1, 1, matOther.get(1, 1));

}



//*******************************************************************************************************************************************************************
//Destructor~

Matrix2D::~Matrix2D(void)
{
}
