#pragma once
#include "Matrix2D.h"
#include "Vector2D.h"
#include "core/app.h"
#include "render/window.h"
#include "2d/2dapp.h"
#include <vector>

using namespace std;
class Shape
{
public:
	Shape(void);
	~Shape(void);

	virtual void setPos(float x, float y);
	virtual void MoveX(float speed);
	virtual void MoveY(float speed);

	virtual void render();
	float getColourR();
	float getColourG();
	float getColourB();
	void setColourR(float colour);
	void setColourG(float colour);
	void setColourB(float colour);
	void setColours(float colourR, float colourG, float colourB);
	Matrix2D _rotMatrix;

	virtual void rotate(float radian);
protected:
	vector <Vector2D> punkter;
	Vector2D _posVector;
	 
	float _colourR;
	float _colourG;
	float _colourB;

	



};

