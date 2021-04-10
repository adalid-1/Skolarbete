#pragma once
#pragma once
#include "Vector2D_v2.h"

class Matrix2D_v2
{

private:
	float _matrix[3][3];


public:
	//Konstruktors
	Matrix2D_v2(void);
	Matrix2D_v2(float i0_0, float i0_1, float i1_0, float i1_1);
	Matrix2D_v2(float i0_0, float i0_1, float i0_2, float i1_0, float i1_1, float i1_2, float i2_0, float i2_1, float i2_2);
	Matrix2D_v2(Matrix2D_v2& matOther);


	Matrix2D_v2 rotation(const float radians);
	Matrix2D_v2 secRotation(const float radians);




	float get(int row, int elem);
	void set(int row, int elem, float value);
	Vector2D_v2 getPos();
	float getX();
	float getY();
	void setPos(float x, float y);

	void move(Vector2D_v2 vec);
	
	void setAll(float i00, float i01, float i10, float i11);
	void setAll(float i0_0, float i0_1, float i0_2, float i1_0, float i1_1, float i1_2, float i2_0, float i2_1, float i2_2);
	void resetMat();


	bool Matrix2D_v2::operator==(Matrix2D_v2& matOther);
	Matrix2D_v2 transpose();
	Matrix2D_v2 TranslateMatrix(Vector2D_v2 v);
	void operator=(Matrix2D_v2& matOther);
	Matrix2D_v2 operator*(Matrix2D_v2& matOther);
	Vector2D_v2 operator*(Vector2D_v2& vector); //Denna kräver att "Vector2D.h" är includad.

	//Matrix2D_v2 operator()(Matrix2D_v2& Matris);




	~Matrix2D_v2(void);
};

