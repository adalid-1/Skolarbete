#pragma once

#include <iostream>
#include <stdexcept>

#include "Nodes.h"
class LinkedList {






public:


	Node head; //Dummynode
	Node *pre;
	Node *iteratorPos;
	


	LinkedList();


	bool isOff();
	

	bool isOff(Node* ptr);

	int item();


	void insertBefore(Node &z);



	void start();


	void forth();

	void removeAt();
	

	//Write the data from the nodes in the list
	void Write();




	//Extra stuff found in the book 
	//==========================================================================



	//Search for node containing a certain data
	Node *search(Node *head, int sought);


	//Add node to the start of the list
	void addFirst(Node *& headNext, int d);

	//Add node to the back of the list
	void addLast(Node *& head, int d);
	

	//Write the list backwards using recursion
	void Write_backwards(Node *head);

	//Add node to the back of the list recursivly. 
	void addLastRek(Node *& head, int d);






};