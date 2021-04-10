#pragma once

#include <iostream>
#include <stdexcept>
#include "QueueLL.h"
#include "Nodes.h"


////
////QueueLL::QueueLL() {
////		head.next = NULL;
////		lastPos = &head;
////
////	}
//
//
//	bool QueueLL::isEmpty()
//	{
//
//		if (head.next)
//		{
//			return false;
//		}
//		else
//		{
//			return true;
//		}
//	}
//
//
//	//Se första elementet i listan
//	//int QueueLL::Peek()
//	//{
//	//	if (head.next)
//	//		return head.next->data;
//	//	else
//	//		std::cout << "Queue is empty" << std::endl;
//
//	//}
//
//	//Tar bort i början av listan
//	//void QueueLL::Pop()
//	//{
//	//	if (head.next)
//	//	{
//	//		Node* temp;
//	//		temp = head.next->next;
//
//	//		delete head.next;
//	//		head.next = temp;
//	//	}
//	//	else
//	//	{
//	//		std::cout << "Queue is empty" << std::endl;
//	//	}
//
//	//}
//
//
//
//	//Sätter in i slutet
//	void QueueLL::insertLast(Node &newNode)
//	{
//
//		if (head.next == NULL)
//		{
//			head.next = &newNode;
//			lastPos = &newNode;
//		}
//		else
//		{
//			lastPos->next = &newNode;
//			lastPos = &newNode;
//
//		}
//
//		//lastPos->next = &newNode
//		//lastPos = &newNode
//		//iteratorPos = &z;
//	}

	////Sätter in i slutet
	//void QueueLL::insertLast(int data)
	//{
	//	Node* newNode = new Node(data);
	//	if (head.next == NULL)
	//	{
	//		head.next = newNode;
	//		lastPos = newNode;
	//	}
	//	else
	//	{
	//		lastPos->next = newNode;
	//		lastPos = newNode;

	//	}

	//	//lastPos->next = &newNode
	//	//lastPos = &newNode
	//	//iteratorPos = &z;
	//}


//
//
//	//Write the data from the nodes in the list
	void QueueLL::Write()
	{
		for (Node *pointer = head.next; pointer; pointer = pointer->next)
			std::cout << pointer->data << ' ';
	}
//
//	int QueueLL::getSize()
//	//{
//	//	int i = 0;
//	//	for (Node *pointer = head.next; pointer; pointer = pointer->next)
//	//		i++;
//	//	return i;
//	//}
//
//
//
//	//Extra stuff found in the book 
//	//==========================================================================
//
//
//
//	//Search for node containing a certain data
//	//Node* QueueLL::search(Node *head, int sought)
//	//{
//	//	Node *pointer;
//	//	for (pointer = head; pointer && pointer->data != sought; pointer = pointer->next);
//	//	return pointer;
//	//}
//
//	//Add node to the start of the list
//	void QueueLL::addFirst(Node *& head, int d)
//	{
//		head = new Node(head, d);
//	}
//
//	//Add node to the back of the list
//	void QueueLL::addLast(Node *& head, int d)
//	{
//		if (!head)
//			head = new Node(0, d);
//		else
//		{
//			Node *pointer;
//			for (pointer = head; pointer->next; pointer = pointer->next);
//			pointer->next = new Node(0, d);
//		}
//
//	}
//
//	//Write the list backwards using recursion
//	void QueueLL::Write_backwards(Node *head)
//	{
//		if (head)
//		{
//			Write_backwards(head->next);
//			std::cout << head->data << ' ';
//		}
//	}
//
//	//Add node to the back of the list recursivly. 
//	void QueueLL::addLastRek(Node *& head, int d)
//	{
//		if (!head)
//			head = new Node(0, d);
//		else
//			addLastRek(head->next, d);
//
//	}
//
//
//
//
//
//
//