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

	//Virtual movement functions
	virtual void setPos(float x, float y);

	//Virtual  render
	virtual void render();

	//Operating on colours 
	float getColourR();
	float getColourG();
	float getColourB();
	void setColourR(float colour);
	void setColourG(float colour);
	void setColourB(float colour);
	void setColours(float colourR, float colourG, float colourB);

	//Rotation matrix
	Matrix2D _rotMatrix;

protected:
	//For drawing
	vector <Vector2D> punkter;
	//Position
	Vector2D _posVector;
	 //Color values
	float _colourR;
	float _colourG;
	float _colourB;

	



};

