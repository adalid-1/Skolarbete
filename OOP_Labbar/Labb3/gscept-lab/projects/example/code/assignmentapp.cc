//------------------------------------------------------------------------------
// exampleapp.cc
// (C) 2015 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "assignmentapp.h"
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"
#include "Circle.h"
#include "iostream"
#include <time.h>
namespace Example
{
AssignmentApp::AssignmentApp()
{
	// empty
}
AssignmentApp::~AssignmentApp()
{
	// empty
}

void 
AssignmentApp::Setup()
{
	// create quad
	Square* quad = new Square(0.3f);
	quad->setPos(0.2f, 0.2f);
	quad->setColourB(0.5);
	former.push_back(quad);
	//create triangle
	Triangle* tri = new Triangle(0.4f,0.6f);
	tri->setPos(0.5f, 0.2f);
	tri->setColourR(0.5);
	former.push_back(tri);
	//creat circle
	Circle* circle = new Circle(0.2f);
	circle->setPos(0.2f, 0.2f);
	former.push_back(circle);

	window = this->getWindow();
	window->SetKeyPressFunction([this](int key, int, int action, int mod )
	{
		this->KeyEvent(key, action, mod);
	});
}

void
AssignmentApp::Update()
{
	for(int i = 0, iLen = former.size(); i < iLen; i ++)
	{
		former[i]->render();
	}
}

void
AssignmentApp::KeyEvent(int key, int action, int modifier)
{
}

} // namespace Example