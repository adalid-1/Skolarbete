#pragma once

#include <iostream>
#include <stdexcept>

#include "Nodes.h"
//template <class anyType>
class StackLL {






public:


	Node head; //Dummynode
	Node *ptr;



	StackLL();



	int item();
	




	void Push(Node  &newNode);



	void Pop();


	//Write the data from the nodes in the list
	void Display();




	//==========================================================================



	//Search for node containing a certain data
	Node *search(Node *head, int sought);

	//Add node to the start of the list
	void addFirst(Node *& head, int d);
	

	//Add Node2 to the back of the list without need for a last pointer
	void addLast(Node *& head, int d);


	//Write the list backwards using recursion
	void Write_backwards(Node *head);


	//Add Node2 to the back of the list recursivly. 
	void addLastRek(Node *& head, int d);



};