#pragma once

#include <iostream>
#include <stdexcept>
#include "StackLL.h"
#include "Nodes.h"
using namespace std;




StackLL::StackLL() {

		ptr = &head;
	}



	int StackLL::item()
	{
		return head.next->data;

	}




	void StackLL::Push(Node  &newNode)
	{
		if (head.next)
		{
			newNode.next = head.next;
			head.next = &newNode;
		}
		else
		{
			head.next = &newNode;
		}

	}


	void StackLL::Pop()
	{
		if (head.next)
		{
			Node *temp;

			temp = head.next->next;


			delete head.next;
			head.next = temp;

		}
		else
		{
			std::cout << "Stack is empty" << std::endl;
		}

	}

	//Write the data from the nodes in the list
	void StackLL::Display()
	{
		for (Node *pointer = head.next; pointer; pointer = pointer->next)
			std::cout << pointer->data << ' ';
		cout << endl;
	}




	//==========================================================================



	//Search for node containing a certain data
	Node* StackLL::search(Node *head, int sought)
	{
		Node *pointer;
		for (pointer = head; pointer && pointer->data != sought; pointer = pointer->next);
		return pointer;
	}

	//Add node to the start of the list
	void StackLL::addFirst(Node *& head, int d)
	{
		head = new Node(head, d);
	}

	//Add Node2 to the back of the list without need for a last pointer
	void StackLL::addLast(Node *& head, int d)
	{
		if (!head)
			head = new Node(0, d);
		else
		{
			Node *pointer;
			for (pointer = head; pointer->next; pointer = pointer->next);
			pointer->next = new Node(0, d);
		}

	}

	//Write the list backwards using recursion
	void StackLL::Write_backwards(Node *head)
	{
		if (head)
		{
			Write_backwards(head->next);
			std::cout << head->data << ' ';
		}
	}

	//Add Node2 to the back of the list recursivly. 
	void StackLL::addLastRek(Node *& head, int d)
	{
		if (!head)
			head = new Node(0, d);
		else
			addLastRek(head->next, d);

	}





