#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>


//Defining the node
struct Node {
public:
	Node *next;
	int data;

	Node(Node *n, int d) : next(n), data(d) {}

	Node(int d)
	{
		next = nullptr;
		data = d;
	}

	Node(void)
	{
		next = nullptr;
		data = 0;
	}

};





//==============================================

template<class T> 
struct Node2
{
public:
	T data;
	int next;

	Node2(int n, T d) : next(n), data(d) {}

	Node2( T d)
	{
		T data = d;
	}
	Node2()
	{
		T data = 1;
		next = 0;
	}
	
	

	
};




	
