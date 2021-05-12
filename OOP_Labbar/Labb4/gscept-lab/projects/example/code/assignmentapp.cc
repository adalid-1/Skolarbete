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

//------------------------------------------------------------------------------
/**
*/
AssignmentApp::AssignmentApp()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
AssignmentApp::~AssignmentApp()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
void 
AssignmentApp::Setup()
{
	// create your own objects 
	Square* kvad = new Square(0.3f);
	kvad->setPos(0.2f, 0.2f);
	former.push_back(kvad);
	
	Triangle* tri = new Triangle(0.4f,0.6f);
	tri->setPos(0.5f, 0.2f);
	former.push_back(tri);

	Circle* cirkle = new Circle(0.2f);
	cirkle->setPos(0.2f, 0.2f);
	

	former.push_back(cirkle);

	
	window = this->getWindow();

	window->SetKeyPressFunction([this](int key, int, int action, int mod )
	{
		
		this->KeyEvent(key, action, mod);
	});

	srand(time(NULL));
}

//------------------------------------------------------------------------------
/**
*/
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

	cout << key << "," << action << endl; //DEBUG
	float a = 0.0f;
	if(action == 1 || action == 2)
	{
		float random = rand() % 100 / 100.0f;
		float random2 = rand() % 100 / 100.0f;
		switch (key)
		{
		case 49://1 adds square
			former.push_back(new Square(rand() % 100 / 100.0f));
			former[former.size() - 1]->rotate(rand() % 100 / 50.0f - 1);
			former[former.size() - 1]->setPos(rand() % 100 / 50.0f - 1, rand() % 100 / 50.0f - 1);
			former[former.size() - 1]->setColours(rand() % 100 / 100.0f, rand() % 100 / 100.0f, rand() % 100 / 100.0f);

			
			break;
		case 50://2 triangle
			former.push_back(new Triangle
			(rand() % 100 / 100.0f, rand() % 100 / 100.0f));
			former[former.size() - 1]->rotate(rand() % 100 / 50.0f - 1);
			former[former.size() - 1]->setPos(rand() % 100 / 50.0f - 1, rand() % 100 / 50.0f - 1);
			former[former.size() - 1]->setColours(rand() % 100 / 100.0f, rand() % 100 / 100.0f, rand() % 100 / 100.0f);



			break;
		case 51://3 Circle
			former.push_back(new Circle
			(rand() % 100 / 100.0f));
			former[former.size() - 1]->rotate(rand() % 100 / 50.0f - 1);
			former[former.size() - 1]->setPos(rand() % 100 / 50.0f - 1, rand() % 100 / 50.0f - 1);
			former[former.size() - 1]->setColours(rand() % 100 / 100.0f, rand() % 100 / 100.0f, rand() % 100 / 100.0f);


			break;
		case 81://q removes square

			cout << "Du tryckte q" << endl;
			for (int i = 0; i < former.size(); i++)
			{
				if (typeid((*former[i])) == typeid(Square))
				{
					former.erase(former.begin() + i);
					i--;
				}
			}
			break;
		case 87://w triangle 
			cout << "Du tryckte w" << endl;
			for (int i = 0; i < former.size(); i++)
			{
				if (typeid((*former[i])) == typeid(Triangle))
				{
					former.erase(former.begin() + i);
					i--;
				}
			}
			break;
		case 69://e circle
			cout << "Du tryckte e" << endl;
			for (int i = 0; i < former.size(); i++)
			{
				if (typeid((*former[i])) == typeid(Circle))
				{
					former.erase(former.begin() + i);
					i--;
				}
			}
			break;
		case 82://r
			break;
		case 263://left
			break;
		case 265://up
			break;
		case 262://right
			break;
		case 264://down
			break;

		case 256://esc
			this->window->Close();
			return;

		}
	}
}
} // namespace Example