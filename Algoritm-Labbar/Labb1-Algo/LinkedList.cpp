#pragma once

#include <iostream>
#include <stdexcept>
#include "LinkedList.h"
#include "Nodes.h"

using namespace std;


LinkedList::LinkedList() {
		head.next = NULL;
		head.data = -100;
		pre = &head;
		iteratorPos = head.next;

	}


	bool LinkedList::isOff()
	{
		return (iteratorPos == nullptr);
	}

	bool LinkedList::isOff(Node* ptr)
	{
		return(!ptr);

	}

	int LinkedList::item()
	{
		if (!isOff())
		{
			return iteratorPos->data;
		}
		else
		{
			cout << "The iterator is off the list" << endl;
			return -1000;
		}
	}



	void LinkedList::insertBefore(Node &z)
	{
		if (!isOff())
		{
			pre->next = &z;
			pre = &z;
			z.next = iteratorPos;
		}
		else if (isOff())
		{
			pre->next = &z;
			pre = pre->next;
			iteratorPos = z.next;
		}
	}



	void LinkedList::start()
	{
		pre = &head;
		iteratorPos = head.next;
	}
	void LinkedList::forth()
	{
		if (!isOff())
		{

			pre = iteratorPos;
			iteratorPos = iteratorPos->next;

		}
		else
			cout << "Doing nothing" << endl;
	}

	void LinkedList::removeAt()
	{
		if (!isOff() && iteratorPos->next)
		{
			iteratorPos = iteratorPos->next;
			delete pre->next;
			pre->next = iteratorPos;
		}
		else if (!isOff())
		{
			delete pre->next;

		}




	}

	//Write the data from the nodes in the list
	void LinkedList::Write()
	{
		for (Node *pointer = head.next; pointer; pointer = pointer->next)
			std::cout << pointer->data << ' ';
	}



	//Extra stuff found in the book 
	//==========================================================================



	//Search for node containing a certain data
	Node* LinkedList::search(Node *head, int sought)
	{
		Node *pointer;
		for (pointer = head; pointer && pointer->data != sought; pointer = pointer->next);
		return pointer;
	}

	//Add node to the start of the list
	void LinkedList::addFirst(Node *& headNext, int d)
	{
		headNext = new Node(headNext, d);
	}

	//Add node to the back of the list
	void LinkedList::addLast(Node *& head, int d)
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
	void LinkedList::Write_backwards(Node *head)
	{
		if (head)
		{
			Write_backwards(head->next);
			std::cout << head->data << ' ';
		}
	}

	//Add node to the back of the list recursivly. 
	void LinkedList::addLastRek(Node *& head, int d)
	{
		if (!head)
			head = new Node(0, d);
		else
			addLastRek(head->next, d);

	}






	////testing search for value
	//Object *aba = hopp.search(head, 8);

	////skriver ut värdet om det finns i listan
	//if (aba != 0) {
	//	cout << aba->data << ' ';
	//}

