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
#include <typeinfo>
namespace Example
{
//------------------------------------------------------------------------------
AssignmentApp::AssignmentApp()
{
	// empty
}
//------------------------------------------------------------------------------
AssignmentApp::~AssignmentApp()
{
	// empty
}
//------------------------------------------------------------------------------
void 
AssignmentApp::Setup()
{
	TestMatrix2D.setAll(1, 2, 3, 4, 5, 6, 7, 8, 9);

	TestMatrix2D = TestMatrix2D * TestMatrix2D;

	setupShapes(40);
	//Breakoutball setup
	breakball = new Circle(0.2f);
	breakball->setPos(0.0f, 0.9f);
	breakball->setVelocity(0.0002f, 0.0002f);
	breakball->isNotBreakable = true;
	former.push_back(breakball);

	window = this->getWindow();
	window->SetKeyPressFunction([this](int key, int, int action, int mod )
	{
		this->KeyEvent(key, action, mod);
	});
	
	srand(time(NULL));
}

//------------------------------------------------------------------------------
void 
AssignmentApp::Update()
{

	for(int i = 0; i < former.size(); i ++)
	{
		former[i]->render();
		former[i]->update();

		//Checks distance between breakball and object
		tempVector = former[i]->getPos() - breakball->getPos();

		//Compares distance to breakball radius and makes sure it´s not about to destroy itself
		if (tempVector.lenVector(tempVector) < breakball->getRadie() && !former[i]->isNotBreakable)
		{
			//Bounce horizontally if 
			if(abs(tempVector.getX())< abs(tempVector.getY()))
			{
				breakball->setVelocity(breakball->getVelocityX(), breakball->getVelocityY() * -1.0f);
			}
			else //Bounce vertically
			{
				breakball->setVelocity(breakball->getVelocityX() * -1.0f, breakball->getVelocityY());
			}
			former.erase(former.begin() + i);

			i--;
		}
	}
}

void AssignmentApp::KeyEvent(int key, int action, int modifier)
{
	//Finding out what values diffrent keys are
	cout << key << "," << action << endl; //DEBUG

	if(action == 1 || action == 2)
	{
		switch (key) 
		{
		case 49://1
			former.push_back(new Square(rand() % 100 / 100.0f));
			former[former.size() - 1]->rotate(rand() % 100 / 50.0f - 1);
			former[former.size() - 1]->setPos(rand() % 100 / 50.0f - 1, rand() % 100 / 50.0f - 1);
			former[former.size() - 1]->setColours(rand() % 100 / 100.0f, rand() % 100 / 100.0f, rand() % 100 / 100.0f);
			former[former.size() - 1]->setVelocity(0.0003f, 0.0002f);

			
			break;
		case 50://2
			former.push_back(new Triangle
			(rand() % 100 / 100.0f, rand() % 100 / 100.0f));
			former[former.size() - 1]->rotate(rand() % 100 / 50.0f - 1);
			former[former.size() - 1]->setPos(rand() % 100 / 50.0f - 1, rand() % 100 / 50.0f - 1);
			former[former.size() - 1]->setColours(rand() % 100 / 100.0f, rand() % 100 / 100.0f, rand() % 100 / 100.0f);
			former[former.size() - 1]->setVelocity(0.0003f, 0.0002f);


			
				
			break;
		case 51://3
			former.push_back(new Circle
			(rand() % 100 / 100.0f));
			former[former.size() - 1]->rotate(rand() % 100 / 50.0f - 1);
			former[former.size() - 1]->setPos(rand() % 100 / 50.0f - 1, rand() % 100 / 50.0f - 1);
			former[former.size() - 1]->setColours(rand() % 100 / 100.0f, rand() % 100 / 100.0f, rand() % 100 / 100.0f);
			former[former.size() - 1]->setVelocity(0.0003f, 0.0002f);



			break;
		case 81://q

			cout << "Du tryckte q" << endl;
			for (int i = 0; i < former.size(); i++)
			{	
				if(typeid((*former[i])) == typeid(Square))
				{
				former.erase(former.begin()+i);
				i--;
				}
			}
			break;
		case 87://w
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
		case 69://e
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
			//former[4]->MoveX(-0.02f);
			break;
		case 265://up
			//former[4]->MoveY(0.02f);
			break;
		case 262://right
			//former[4]->MoveX(0.02f);
			break;
		case 264://down
			//former[4]->MoveY(-0.02f);
			break;

		case 256://esc
			this->window->Close();
			return;
			
		}
	}
}


void AssignmentApp::setupShapes(int nr) {



	int key;
	for(int i = 0; i < nr; i++){
		key = i % 3;
		switch (key)
		{
		case 1://1
			former.push_back(new Square(rand() % 100 / 100.0f));
			former[former.size() - 1]->rotate(rand() % 100 / 50.0f - 1);
			former[former.size() - 1]->setPos(rand() % 100 / 50.0f - 1, rand() % 100 / 50.0f - 1);
			former[former.size() - 1]->setColours(rand() % 100 / 100.0f, rand() % 100 / 100.0f, rand() % 100 / 100.0f);
			break;
		case 2://2
			former.push_back(new Triangle
			(rand() % 100 / 100.0f, rand() % 100 / 100.0f));
			former[former.size() - 1]->rotate(rand() % 100 / 50.0f - 1);
			former[former.size() - 1]->setPos(rand() % 100 / 50.0f - 1, rand() % 100 / 50.0f - 1);
			former[former.size() - 1]->setColours(rand() % 100 / 100.0f, rand() % 100 / 100.0f, rand() % 100 / 100.0f);
			break;
		case 3://3
			former.push_back(new Circle
			(rand() % 100 / 100.0f));
			former[former.size() - 1]->rotate(rand() % 100 / 50.0f - 1);
			former[former.size() - 1]->setPos(rand() % 100 / 50.0f - 1, rand() % 100 / 50.0f - 1);
			former[former.size() - 1]->setColours(rand() % 100 / 100.0f, rand() % 100 / 100.0f, rand() % 100 / 100.0f);
		}
	}
}


} // namespace Example