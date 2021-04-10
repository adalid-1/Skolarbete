#pragma once

#include <iostream>
#include <stdexcept>

#include "Nodes.h"
class QueueLL {






public:


	Node head; //Dummynode

	Node *lastPos;


	QueueLL()
	{
		head.next = NULL;
		lastPos = &head;

	}

	//Kollar head-noden pekar på något
	bool isEmpty();


	
	//Se första elementet i listan
	int Peek()

	{
		if (head.next)
			return head.next->data;
		else
			std::cout << "Queue is empty" << std::endl;
		return -1000;
	}


	//Tar bort i början av listan
	void Pop()
	{
		if (head.next)
		{
			Node* temp;
			temp = head.next->next;

			delete head.next;
			head.next = temp;
		}
		else
		{
			std::cout << "Queue is empty" << std::endl;
		}

	}




	//Sätter in i slutet



	//Sätter in i slutet
	void insertLast(int data)
		
	{
		Node* newNode = new Node(data);
		if (head.next == NULL)
		{
			head.next = newNode;
			lastPos = newNode;
		}
		else
		{
			lastPos->next = newNode;
			lastPos = newNode;

		}

		//lastPos->next = &newNode
		//lastPos = &newNode
		//iteratorPos = &z;
	}




	//Write the data from the nodes in the list
	void Write();

	//Loops through list to find the size 
	int getSize()
	{
		int i = 0;
		for (Node *pointer = head.next; pointer; pointer = pointer->next)
			i++;
		return i;
	}
	

	//Extra stuff found in the book 
	//==========================================================================



	//Search for node containing a certain data
	Node *search(Node *head, int sought);


	//Add node to the start of the list
	void addFirst(Node *& head, int d);

	//Add node to the back of the list
	void addLast(Node *& head, int d);
	


	//Write the list backwards using recursion
	void Write_backwards(Node *head);

	//Add node to the back of the list recursivly. 
	void addLastRek(Node *& head, int d);
	
};