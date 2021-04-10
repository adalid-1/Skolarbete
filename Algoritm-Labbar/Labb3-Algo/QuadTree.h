#pragma once

#include <iostream>
#include <vector>
using namespace std;


//Värden för en punkt

struct Point
{
	int x;
	int y;
	
	Point(int x_, int y_)
	{
		x = x_;
		y = y_;
	}

	Point()
	{
		x = 0;
		y = 0;
	}
};

template<class T>
struct Node
{
	T data;
	Point pos;

	Node(Point pos_, T data_)
	{
		pos = pos_;
		data = data_;
	}

	Node()
	{
	}
};

//=================================================================================================================================
template <class T>
class QuadCell
{
	Point pos;
	Point topRight;
	Point bottomLeft;
	
	//Half Height and Half W
	int halfH;
	int halfW;

	int nrOfElements =0;
	int cellCapacity = 1;

	bool isDivided;

	Node<T>* elements;
	
	//Childrens 
	QuadCell* topLeftTree;
	QuadCell* topRightTree;
	QuadCell* bottomLeftTree;
	QuadCell* bottomRightTree;

public:
	QuadCell(int width_, int height_)
	{
		pos = Point(0, 0);
		Setup(width_, height_);
	}

	QuadCell(int width_, int height_, Point pos_)
	{
		pos = pos_;
		Setup(width_, height_);
	}

	void Setup(int width_, int height_)
	{
		isDivided = false;
		halfH = int(height_ / 2.0f);
		halfW = int(width_ / 2.0f);
		topRight = Point((pos.x + halfW), (pos.y + halfH));
		bottomLeft = Point((pos.x - halfW), (pos.y - halfH));

		topLeftTree = NULL;
		topRightTree = NULL;
		bottomLeftTree = NULL;
		bottomRightTree = NULL;

		elements = NULL;
	}


	bool inBoundary(Point pt)
	{
		return(pt.x <= topRight.x &&
			pt.y <=topRight.y &&
			pt.x >= bottomLeft.x &&
			pt.y >= bottomLeft.y);
	}


	bool  InsertElement(const Node<T>& element_)
	{
		//Är elementets position innom trädets gränser?
		if (!inBoundary(element_.pos))
		{
			return false;
		}
		if (nrOfElements < cellCapacity)
		{
			if (elements == NULL)
			{
				elements = new Node<T>[(cellCapacity + 1)];
			}
			
			elements[nrOfElements] = element_;
			nrOfElements++;
			return true;
		}
		//Om vi har en kvadrat som är så liten att det inte går att dela den något mer 
		else if ((topRight.x - bottomLeft.x) <= 1 && (topRight.y - bottomLeft.y) <= 1)
		{
			return false;
		}
		else if(!isDivided)
		{
			//Subdivide
			subdivide(halfW, halfH, pos);
			elements[nrOfElements] = element_;
			for (int i = 0; i < (cellCapacity + 1); i++)
			{		
				bottomLeftTree->InsertElement(elements[i]);
				bottomRightTree->InsertElement(elements[i]);
				topLeftTree->InsertElement(elements[i]);
				topRightTree->InsertElement(elements[i]);
			}
			elements = NULL;
		}
		else
		{
			bottomLeftTree->InsertElement(element_);
			bottomRightTree->InsertElement(element_);
			topLeftTree->InsertElement(element_);
			topRightTree->InsertElement(element_);
		}
		return true;
	}

	void subdivide(int halfW_, int halfH_, Point pos_)
	{
		this->bottomLeftTree =  new QuadCell(halfW_, halfH_, Point(pos.x - int(halfW_ / 2.0f), pos.y - int(halfH_ / 2.0f)));

		this->topLeftTree =  new QuadCell(halfW_, halfH_, Point(pos.x - int(halfW_ / 2.0f), pos.y + int(halfH_ / 2.0f)));

		this->bottomRightTree =  new QuadCell(halfW_, halfH_, Point(pos.x + int(halfW_ / 2.0f), pos.y - int(halfH_ / 2.0f)));

		this->topRightTree = new QuadCell(halfW_, halfH_, Point(pos.x + int(halfW_ / 2.0f), pos.y + int(halfH_ / 2.0f)));
		
		this->isDivided = true;
	}

	//Hitta alla element inom det givna spannet
	void FindElements(int x, int y, int width, int height, vector<Node<T>>& output)
	{	
		//Return om inga av den givna rektangelns hörnpunkter finns i den här cellen
		int _hwidth = int(width / 2.0f);
		int _hheight = int(height / 2.0f);

		//Om den här quadden inte intersektar med det givna spannet return;
		if(!inBoundary(Point(x + _hwidth, y + _hheight)) &&
			!inBoundary(Point(x - _hwidth, y + _hheight)) &&
				!inBoundary(Point(x + _hwidth, y - _hheight)) &&
					!inBoundary(Point(x - _hwidth, y - _hheight)))
		{
			return;
		}

		//Om den är divided kör find på children
		if (isDivided)
		{
			bottomLeftTree->FindElements(x, y, width, height, output);
			bottomRightTree->FindElements(x, y, width, height, output);
			topLeftTree->FindElements(x, y, width, height, output);
			topRightTree->FindElements(x, y, width, height, output);

		}
		else
		{

			for (int i = 0; i < nrOfElements; i++)
			{
				if (inBoundary(elements[i].pos))
				{ 
				output.push_back(elements[i]);
				}
			}
			return;
		}	
	}
};
