#pragma once


class Vector2D
{
private:
	float _Vector [2];

public:
	//Initalisering
	Vector2D(void);
	Vector2D(float x, float y);
	Vector2D(const Vector2D& vOther);

	//Destructor
	~Vector2D(void);

	//Räkneoperationer på vektorer
	Vector2D addVector(Vector2D vFirst, Vector2D vSecond);
	Vector2D subVector(Vector2D vFirst, Vector2D vSecond);
	Vector2D multScalarVector(float scalar, Vector2D Vector);
	float scalProdVector(Vector2D vFirst, Vector2D vSecond);
	float lenVector(Vector2D Vector);
	Vector2D unitVector(Vector2D Vector);

	//Logiska operationer på vektorer
	bool Vector2D::areEqual(Vector2D vFirst, Vector2D vSecond);
	bool Vector2D::areNotEqual(Vector2D vFirst, Vector2D vSecond);

	//Setters & getters
	float getX();
	float getY();
	void setX(float Xnew);
	void setY(float Ynew);
	void setXY(float Xnew, float Ynew);


	//operator överlagring//

	//Adderar två vektorer
	Vector2D operator+(const Vector2D& other);

	//Subtraherar två vektorer
	Vector2D operator-(const Vector2D& vSecond);

	//multiplicerar vektor med skalär
	Vector2D operator*(const float& scalar);

	//skalärprodukt vektor vektor
	float Vector2D::operator*(const Vector2D& vSecond);
	
	//Logiska operatorer mellan vektorer == och !=
	bool operator==(const Vector2D& vSecond);
	bool Vector2D::operator!=(const Vector2D& vSecond);

	//Kopiering med = tecken 
	Vector2D Vector2D::operator=(const Vector2D& vOther);
};

