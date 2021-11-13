#pragma once
#include "Vector2D.h"

class Matrix2D
{

private:
	float _matrix[2][2];

     
public:
	//Konstruktors
	Matrix2D(void);
	Matrix2D(float i0_0, float i0_1, float i1_0,float i1_1);
	Matrix2D(Matrix2D& matOther);
	
	
	Matrix2D rotation(const float radians);
	Matrix2D secRotation(const float radians);
	
	


	float get(int row, int elem);
	void set(int row, int elem, float value);
	void setAll(float i00, float i01, float i10, float i11);


	Matrix2D transpose();
	void operator=(Matrix2D& matOther);
	Matrix2D operator*(Matrix2D& matOther);
	Vector2D operator*(Vector2D& vector); //Denna kräver att "Vector2D.h" är includad.
	//Matrix2D operator()(Matrix2D& Matris);
	



	~Matrix2D(void);
};

