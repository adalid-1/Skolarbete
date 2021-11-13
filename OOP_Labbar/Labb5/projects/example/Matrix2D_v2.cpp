#include "Matrix2D_v2.h"
#include "Vector2D_v2.h"
#include "Math.h"

//*******************************************************************************************************************************************************************
//Konstruktors

//Initiera matris med givna värden
Matrix2D_v2::Matrix2D_v2(float i0_0, float i0_1, float i0_2, float i1_0, float i1_1, float i1_2, float i2_0, float i2_1, float i2_2)
{
	_matrix[0][0] = i0_0;
	_matrix[0][1] = i0_1;
	_matrix[0][2] = i0_2;

	_matrix[1][0] = i1_0;
	_matrix[1][1] = i1_1;
	_matrix[1][2] = i1_2;

	_matrix[2][0] = i1_0;
	_matrix[2][1] = i2_1;
	_matrix[2][2] = i2_2;

}

//Default, identitetsmatris


Matrix2D_v2::Matrix2D_v2(void)
{
	set(0, 0, 1.0);
	set(0, 1, 0.0);
	set(0, 2, 0.0);

	set(1, 0, 0.0);
	set(1, 1, 1.0);
	set(1, 2, 0.0);

	set(2, 0, 0.0);
	set(2, 1, 0.0);
	set(2, 2, 1.0);
}

Matrix2D_v2::Matrix2D_v2(float i0_0, float i0_1, float i1_0, float i1_1)
{
	_matrix[0][0] = i0_0;
	_matrix[0][1] = i0_1;
	_matrix[0][2] = 0;

	_matrix[1][0] = i1_0;
	_matrix[1][1] = i1_1;
	_matrix[1][2] = 0;
	
	_matrix[2][0] = 0;
	_matrix[2][1] = 0;
	_matrix[2][2] = 1;


}
//Kopieringskonstruktor
Matrix2D_v2::Matrix2D_v2(Matrix2D_v2& matOther)
{


	_matrix[0][0] = matOther.get(0, 0);
	_matrix[0][1] = matOther.get(0, 1);
	_matrix[0][2] = matOther.get(0, 2);
	

	_matrix[1][0] = matOther.get(1, 0);
	_matrix[1][1] = matOther.get(1, 1);
	_matrix[1][2] = matOther.get(1, 2);

	_matrix[2][0] = matOther.get(2, 0);
	_matrix[2][1] = matOther.get(2, 1);
	_matrix[2][2] = matOther.get(2, 2);


}

//Rotationsmatris, skapar en rotationsmatris som man kan använda för att snurra på saker. 
Matrix2D_v2 Matrix2D_v2::rotation(const float radians)
{
	Matrix2D_v2 rotationMatrix(cos(radians), -sin(radians), sin(radians), cos(radians));

	return rotationMatrix;
}

Matrix2D_v2 Matrix2D_v2::secRotation(const float radians)
{
	Matrix2D_v2 temp(cos(radians), -(sin(radians)), sin(radians), cos(radians));
	temp = temp * Matrix2D_v2(1, 0, 0, 1);

	return temp;

}
//*******************************************************************************************************************************************************************
//Setter & Getter


float Matrix2D_v2::get(int row, int elem)
{
	return _matrix[row][elem];

}

void Matrix2D_v2::set(int row, int elem, float value)
{
	_matrix[row][elem] = value;

}

Vector2D_v2 Matrix2D_v2::getPos()
{
	Vector2D_v2 position(_matrix[0][2], _matrix[1][2], _matrix[2][2]);
	return position;
}

float Matrix2D_v2::getX()
{
	return _matrix[0][2];
}

float Matrix2D_v2::getY()
{
	return _matrix[1][2];
}

void Matrix2D_v2::setPos(float x, float y)
{
	_matrix[0][2] = x;
	_matrix[1][2] = y;

}

void Matrix2D_v2::move(Vector2D_v2 vec)
{
	_matrix[0][2] += vec.getX();
	_matrix[1][2] += vec.getY();


}

void Matrix2D_v2::setAll(float i00, float i01, float i10, float i11)
{
	_matrix[0][0] = i00;
	_matrix[0][1] = i01;
	_matrix[1][0] = i10;
	_matrix[1][1] = i11;


}

void Matrix2D_v2::setAll(float i0_0, float i0_1, float i0_2, float i1_0, float i1_1, float i1_2, float i2_0, float i2_1, float i2_2)
{
	_matrix[0][0] = i0_0;
	_matrix[0][1] = i0_1;
	_matrix[0][2] = i0_2;

	_matrix[1][0] = i1_0;
	_matrix[1][1] = i1_1;
	_matrix[1][2] = i1_2;

	_matrix[2][0] = i2_0;
	_matrix[2][1] = i2_1;
	_matrix[2][2] = i2_2;

}

void Matrix2D_v2::resetRotation()
{
	//Does not reset position
	_matrix[0][0] = 1.0;
	_matrix[0][1] = 0;

	_matrix[1][0] = 0;
	_matrix[1][1] = 1.0;

	_matrix[2][0] = 0;
	_matrix[2][1] = 0;
	_matrix[2][2] = 1.0;
}

//*******************************************************************************************************************************************************************
//Matris-specifika räknemetoder

//Metod för att få transponatet av en matris
Matrix2D_v2 Matrix2D_v2::transpose()
{
	Matrix2D_v2 newMat(get(0, 0), get(1, 0), get(0, 1), get(1, 1));
	return newMat;
}

//Metod för att multiplicera två matriser, *operatorn överlagrad
Matrix2D_v2 Matrix2D_v2::operator*(Matrix2D_v2& matOther)
{

	Matrix2D_v2 fin_mat;

	float i0_0 = get(0, 0) * matOther.get(0, 0) + get(0, 1) * matOther.get(1, 0);	  //multiplicerar raderna i matris ett med kolumnerna från matris två. 
	float i0_1 = get(0, 0) * matOther.get(0, 1) + get(0, 1) * matOther.get(1, 1);    //Sedan adderas produkterna så att man får 4 nya element. 
	float i1_0 = get(1, 0) * matOther.get(0, 0) + get(1, 1) * matOther.get(1, 0);   //googla matris matrismultiplikation om du vill veta mer. 
	float i1_1 = get(1, 0) * matOther.get(0, 1) + get(1, 1) * matOther.get(1, 1);  //

	
	fin_mat._matrix[0][0] = (_matrix[0][0] * matOther._matrix[0][0]) +
		(_matrix[0][1] * matOther._matrix[1][0]) +
		(_matrix[0][2] * matOther._matrix[2][0]);

	fin_mat._matrix[1][0] = (_matrix[1][0] * matOther._matrix[0][0]) +
		(_matrix[1][1] * matOther._matrix[1][0]) +
		(_matrix[1][2] * matOther._matrix[2][0]);

	fin_mat._matrix[2][0] = (_matrix[2][0] * matOther._matrix[0][0]) +
		(_matrix[2][1] * matOther._matrix[1][0]) +
		(_matrix[2][2] * matOther._matrix[2][0]);



	fin_mat._matrix[0][1] = (_matrix[0][0] * matOther._matrix[0][1]) +
		(_matrix[0][1] * matOther._matrix[1][1]) +
		(_matrix[0][2] * matOther._matrix[2][1]);

	fin_mat._matrix[1][1] = (_matrix[1][0] * matOther._matrix[0][1]) +
		(_matrix[1][1] * matOther._matrix[1][1]) +
		(_matrix[1][2] * matOther._matrix[2][1]);

	fin_mat._matrix[2][1] = (_matrix[2][0] * matOther._matrix[0][1]) +
		(_matrix[2][1] * matOther._matrix[1][1]) +
		(_matrix[2][2] * matOther._matrix[2][1]);



	fin_mat._matrix[0][2] = (_matrix[0][0] * matOther._matrix[0][2]) +
		(_matrix[0][1] * matOther._matrix[1][2]) +
		(_matrix[0][2] * matOther._matrix[2][2]);

	fin_mat._matrix[1][2] = (_matrix[1][0] * matOther._matrix[0][2]) +
		(_matrix[1][1] * matOther._matrix[1][2]) +
		(_matrix[1][2] * matOther._matrix[2][2]);

	fin_mat._matrix[2][2] = (_matrix[2][0] * matOther._matrix[0][2]) +
		(_matrix[2][1] * matOther._matrix[1][2]) +
		(_matrix[2][2] * matOther._matrix[2][2]);

	

	  //multiplicerar raderna i matris ett med kolumnerna från matris två. 
	   //Sedan adderas produkterna så att man får nya element.                                 
	return fin_mat;																
}

//Metod för att transformera en 2Dvektor.  *operatorn överlagrad
Vector2D_v2 Matrix2D_v2::operator*(Vector2D_v2& vector)
{

	float newX = _matrix[0][0] * vector.getX() + _matrix[0][1] * vector.getY(); // +_matrix[0][2] * vector.getZ();			//multiplicerar elementen i raderna med elementen i kolumnen som vektorn utgör
	
	float newY = _matrix[1][0] * vector.getX() + _matrix[1][1] * vector.getY();// +_matrix[1][2] * vector.getZ();		   //och adderar sedan produkterna så att man får 2 element som utgör den nya vektorn
	//float newZ = _matrix[2][0] * vector.getX() + _matrix[2][1] * vector.getY() + _matrix[2][2] * vector.getZ();

	Vector2D_v2 newVector(newX, newY);                                          //Den nya vektorn skapas med värdena från uträkningarna ovan och returneras. 
	
	
	return newVector;
}


Matrix2D_v2 Matrix2D_v2::TranslateMatrix(Vector2D_v2 v)
{
	Matrix2D_v2 transMat(1.0f, 0, v.getX(), 
						 0, 1.0f, v.getY(),
						 0,   0,     1.0f);
	
	return transMat;
}


//*******************************************************************************************************************************************************************
//Tilldelnings-operator =
//Fungerar som vanlig tilldelning, elementen kopieras över från vänster matris till motsvarande index i höger matris. 
void Matrix2D_v2::operator=(Matrix2D_v2& matOther)
{
	_matrix[0][0] = matOther.get(0, 0);
	_matrix[0][1] = matOther.get(0, 1);
	_matrix[0][2] = matOther.get(0, 2);

	_matrix[1][0] = matOther.get(1, 0);
	_matrix[1][1] = matOther.get(1, 1);
	_matrix[1][2] = matOther.get(1, 2);

	_matrix[2][0] = matOther.get(2, 0);
	_matrix[2][1] = matOther.get(2, 1);
	_matrix[2][2] = matOther.get(2, 2);
	//Matrix2D
}

bool Matrix2D_v2::operator==(Matrix2D_v2& matOther)
{
	if (_matrix[0][0] == matOther.get(0, 0) && _matrix[0][1] == matOther.get(0, 1) && _matrix[1][0] == matOther.get(1, 0) && _matrix[1][1] == matOther.get(1, 1))
		return true;

}



//*******************************************************************************************************************************************************************
//Destructor~
Matrix2D_v2::~Matrix2D_v2(void)
{
}
