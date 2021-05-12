#include "Shape.h"
#include "2d\2dapp.h"
#include "assignmentapp.h"


Shape::Shape(void)
{}

Shape::~Shape(void)
{}

void Shape::setPos(float x, float y)
{
_posVector.setXY(x,y);
}

float Shape::getColourR()
{return _colourR;}
float Shape::getColourG()
{return _colourG;}
float Shape::getColourB()
{return _colourB;}

void Shape::setColourR(float colour)
{_colourR = colour;}
void Shape::setColourG(float colour)
{_colourG = colour;}
void Shape::setColourB(float colour)
{_colourB = colour;}
void Shape::setColours(float colourR, float colourG, float colourB)
{
_colourR = colourR;
_colourG = colourG;
_colourB = colourB;
}

void Shape::render()
{}

	