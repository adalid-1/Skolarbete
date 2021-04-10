#pragma once
#include "Matrix2D.h"
#include "Vector2D.h"
#include "../Matrix2D_v2.h"
#include "../Vector2D_v2.h"
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
	Vector2D_v2 getPos();
	//virtual void MoveX(float speed);
	//virtual void MoveY(float speed);

	virtual void render();
	void update();
	float getColourR();
	float getColourG();
	float getColourB();
	void setColourR(float colour);
	void setColourG(float colour);
	void setColourB(float colour);
	void setColours(float colourR, float colourG, float colourB);

	void setVelocity(float x, float y);
	float getVelocityX();
	float getVelocityY();


	void rotate(float radian);
protected:

	//Punkterna när dom ligger runt origo
	vector <Vector2D_v2> punkter;

	//Punkterna när dom ligger där dom existerar i spelvärlden
	vector <Vector2D_v2> punkter2;

	Matrix2D_v2 _posRotMatrix;
	Vector2D_v2 _velocity;
	 
	float _colourR;
	float _colourG;
	float _colourB;
public:
	bool isPlayer;
	



};

