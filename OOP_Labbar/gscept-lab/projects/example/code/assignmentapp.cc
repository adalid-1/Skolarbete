//------------------------------------------------------------------------------
// exampleapp.cc
// (C) 2015 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "assignmentapp.h"
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"
#include "Cirkel.h"

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
	TestMatrix2D.setAll(1, 2, 3, 4, 5, 6, 7, 8, 9);

	TestMatrix2D = TestMatrix2D * TestMatrix2D;

	// create your own objects 
	Square* kvad = new Square(0.3f);
	//Test quad
	kvad->setPos(0.2f, 0.2f);
	kvad->rotate(1.5f);
	former.push_back(kvad);
	//test triangle
	Triangle* tri = new Triangle(0.4f,0.6f);
	tri->setPos(0.5f, 0.2f);
	former.push_back(tri);
	//test circle
	Cirkel* cirkle = new Cirkel(0.2f);
	cirkle->setPos(0.2f, 0.2f);
	former.push_back(cirkle);
	formerSize = 3;

	//Breakoutball setup
	breakball = new BreakoutBall(0.2f);
	breakball->setPos(0.0f, 0.9f);
	breakball->setVelocity(0.007f, 0.007f);
	breakball->isPlayer = true;
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
	/*
	// demo line drawing code
	LineData line;
	line.x1 = -0.3f;
	line.y1 = -0.3f;
	line.x2 = 0.0f;
	line.y2 = 0.5f;
	line.c1.r = 1.0f;
	AssignmentApp::DrawLine(line);	
	line.x1 = 0.0f;
	line.y1 = 0.5f;
	line.x2 = 0.3f;
	line.y2 = -0.3f;	
	AssignmentApp::DrawLine(line);	
	line.x1 = 0.3f;
	line.y1 = -0.3f;
	line.x2 = -0.3f;
	line.y2 = -0.3f;
	AssignmentApp::DrawLine(line);	
	*/
	//former[0]->render();
	
	//former[1]->render();
	//former[2]->render();
	///former[2]->rotate(0.0005);
	//former[0]->render();
	//former[0]->rotate(0.0005f); 
	//former[1]->render();


	for(int i = 0; i <= formerSize; i ++)
	{
		
		


		
		former[i]->render();
		former[i]->update();

		//Checks distance between breakball and object
		tempVector = former[i]->getPos() - breakball->getPos();

		//Compares distance to breakball radius and makes sure it´s not about to destroy itself
		if (tempVector.lenVector(tempVector) < breakball->getRadie() && !former[i]->isPlayer)
		{
			//Bounce if 
			if(abs(tempVector.getX())< abs(tempVector.getY()))
			{
				breakball->setVelocity(breakball->getVelocityX(), breakball->getVelocityY() * -1.0f);
			}
			else
			{
				breakball->setVelocity(breakball->getVelocityX() * -1.0f, breakball->getVelocityY());
			}
			former.erase(former.begin() + i);
			formerSize--;
			i--;
		}

	}
	//former[1]->rotate(0.0005);
	
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
			formerSize++;
			
			break;
		case 50://2
			former.push_back(new Triangle
			(rand() % 100 / 100.0f, rand() % 100 / 100.0f));
			former[former.size() - 1]->rotate(rand() % 100 / 50.0f - 1);
			former[former.size() - 1]->setPos(rand() % 100 / 50.0f - 1, rand() % 100 / 50.0f - 1);
			former[former.size() - 1]->setColours(rand() % 100 / 100.0f, rand() % 100 / 100.0f, rand() % 100 / 100.0f);
			former[former.size() - 1]->setVelocity(0.0003f, 0.0002f);
			formerSize++;

			
				
			break;
		case 51://3
			former.push_back(new Cirkel
			(rand() % 100 / 100.0f));
			former[former.size() - 1]->rotate(rand() % 100 / 50.0f - 1);
			former[former.size() - 1]->setPos(rand() % 100 / 50.0f - 1, rand() % 100 / 50.0f - 1);
			former[former.size() - 1]->setColours(rand() % 100 / 100.0f, rand() % 100 / 100.0f, rand() % 100 / 100.0f);
			former[former.size() - 1]->setVelocity(0.0003f, 0.0002f);

			formerSize++;

			break;
		case 81://q

			cout << "Du tryckte q" << endl;
			for (int i = 0; i <= formerSize; i++)
			{	
				if(typeid((*former[i])) == typeid(Square))
				{
				former.erase(former.begin()+i);
				formerSize--;
				i--;
				}
			}
			break;
		case 87://w
			cout << "Du tryckte w" << endl;
			for (int i = 0; i <= formerSize; i++)
			{


				if (typeid((*former[i])) == typeid(Triangle))
				{

					former.erase(former.begin() + i);
					formerSize--;
					i--;
				}
			}
			break;
		case 69://e
			cout << "Du tryckte e" << endl;
			for (int i = 0; i <= formerSize; i++)
			{
				if (typeid((*former[i])) == typeid(Cirkel))
				{

					former.erase(former.begin() + i);
					formerSize--;
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


			for (int i = 0; i < 3; i++)
			{
				for (int a = 0; a < 3; a++)
				{
					std::cout << TestMatrix2D.get(i, a) << " ";
				}
				std::cout << std::endl;
			}
			//Matrix2D_v2 bulle(1,2)
			break;
		case 262://right
			//former[4]->MoveX(0.02f);

			
			
			break;
		case 264://down
			//former[4]->MoveY(-0.02f);
			break;

		case 256:
			this->window->Close();
			return;
			
		}
		
		//if (former.size() > 0)former[former.size() - 1]->setPos(rand() % 100 / 50.0f - 1, rand() % 100 / 50.0f - 1);

	}

}



} // namespace Example