#pragma once

class Vector2D_v2
{
private:
	float _Vector[3];

public:
	//Initalisering
	Vector2D_v2(void);
	Vector2D_v2(float x, float y);
	Vector2D_v2(float x, float y, float z);
	Vector2D_v2(const Vector2D_v2& vOther);




	//Destructor
	~Vector2D_v2(void);

	//Räkneoperationer på vektorer
	Vector2D_v2 addVector(Vector2D_v2 vFirst, Vector2D_v2 vSecond);
	Vector2D_v2 subVector(Vector2D_v2 vFirst, Vector2D_v2 vSecond);
	Vector2D_v2 multScalarVector(float scalar, Vector2D_v2 Vector);
	float scalProdVector(Vector2D_v2 vFirst, Vector2D_v2 vSecond);
	float lenVector(Vector2D_v2 Vector);
	Vector2D_v2 unitVector(Vector2D_v2 Vector);
	Vector2D_v2 reflect(Vector2D_v2 v, Vector2D_v2 n);

	//Logiska operationer på vektorer
	bool Vector2D_v2::areEqual(Vector2D_v2 vFirst, Vector2D_v2 vSecond);
	bool Vector2D_v2::areNotEqual(Vector2D_v2 vFirst, Vector2D_v2 vSecond);

	//Setters & getters
	float getX();
	float getY();
	float getZ();
	void setX(float Xnew);
	void setY(float Ynew);
	void setZ(float Znew);
	void setXY(float Xnew, float Ynew);


	//operator överlagring//

	//Adderar två vektorer
	Vector2D_v2 operator+(const Vector2D_v2& other);

	//Subtraherar två vektorer
	Vector2D_v2 operator-(const Vector2D_v2& vSecond);

	//multiplicerar vektor med skälär
	Vector2D_v2 operator*(const float& scalar);

	//skalärprodukt vektor vektor
	float Vector2D_v2::operator*(const Vector2D_v2& vSecond);

	//Logiska operatorer mellan vektorer == och !=
	bool operator==(const Vector2D_v2& vSecond);
	bool Vector2D_v2::operator!=(const Vector2D_v2& vSecond);

	//Kopiering med = tecken 
	Vector2D_v2 Vector2D_v2::operator=(const Vector2D_v2& vOther);
};

