#include <iostream>
#include "QuadTree.h"

using namespace std;

int main()
{
	
	cout << "Hello World" << endl;

	Node<int>* arr = new Node<int>[5];


	
	//Testnoder
	Node<int> aguest(Point(1, 1), 1);
	Node<int> aguest1(Point(1, 3), 2);
	Node<int> aguest2(Point(1, 5), 3);
	Node<int> aguest3(Point(-1, 1), -3);
	Node<int> aguest4(Point(-1, -3), -2);
	Node<int> aguest5(Point(-3, -2), -2);
	Node<int> aguest6(Point(4, -5), -2);
	Node<int> aguest7(Point(-7, 2), -2);


	arr[0] = aguest;
	arr[1] = aguest1;
	arr[2] = aguest2;
	arr[3] = aguest3;
	arr[4] = aguest4;

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i].data << endl;

	}

	vector<Node<int>> hopp;

	//hopp.push_back( Node<int>(Point(1, 1), 2));
	//cout << hopp[0].data << endl;

	QuadCell<int> QuadTree(16, 16);
	QuadTree.InsertElement(aguest);
	QuadTree.InsertElement(aguest1);
	QuadTree.InsertElement(aguest2);
	QuadTree.InsertElement(aguest3);
	QuadTree.InsertElement(aguest4);
	//hej.InsertElement(aguest5);
	//hej.InsertElement(aguest6);
	//hej.InsertElement(aguest7);
	
	QuadTree.FindElements(2,4, 1,1 , hopp);

	cout <<"\n" << hopp.size() << endl;

	for (unsigned int i = 0; i < hopp.size(); i++)
	{
		cout << hopp[i].data << endl;
	}
	//hej.InsertElement(aguest3);
	//hej.InsertElement(aguest4);
	int a;
	cin >> a;
	return 0;
}