using namespace std;
#include <string>
#include <iostream>
#include "Nodes.h"
#include <vector>
#include "ArrayLinkedList.h"
#include "LinkedList.h"
#include "Menu.h"
#include "StackLL.h"

int main()
{
	cout << "Hello World \n";
	
	Node *hej = new Node(1);
	Node *da = new Node(3);

	string haaaa = "hej";

	LinkedList listan;
	listan.addFirst(listan.head.next, 3);
	listan.addFirst(listan.head.next, 5);
	listan.addFirst(listan.head.next, 4);
	listan.addLast(listan.head.next, 8);
	listan.addLastRek(listan.head.next, 7);
	listan.start();
	listan.insertBefore(*hej);
	listan.forth();
	listan.forth();
	listan.insertBefore(*da);
	listan.start();
	listan.forth();
	listan.removeAt();
	
	listan.Write();
	listan.addLastRek(listan.head.next, 13);
	listan.Write_backwards(listan.head.next);
	cout << endl;
	listan.forth();
	listan.forth();
	cout << listan.item() << endl;
	//Object *p = listan.search(listan.head, 4);
	///cout << p->data;
	/*

	Node fa(4);


	listan.insertBefore(hej);

	listan.insertBefore(da);

	listan.insertBefore(fa);

	listan.Write();*/


	/*
	listan.forth();
	cout << listan.iteratorPos->data << ' ';
	listan.forth();
	cout << listan.iteratorPos->data << ' ';*/

	//ArrayLinkedList<int> lista2(4);
	//specialList<int> lista2(4);
	//Node2<int> vbvb(1, 13);



	//bgbgb.insertNodeAt(1, vbvb);

	//cout << bgbgb.getData(1) << endl;
	
	//cout << bgbgb.getData(1) << endl;


	
	ArrayLinkedList<int> bgbgb(3);
	bgbgb.start();
	for (int i = 0; i < 3; i++)
	{


		bgbgb.insertAt(i);
		cout << bgbgb.item() << endl;
		cout << bgbgb.NextNr() << endl;
		bgbgb.forth();



	}
	bgbgb.start();
	bgbgb.iteratorIndex = 0;
	//bgbgb.forth();
	//bgbgb.forth();


	StackLL testSTack;
	
	testSTack.Push(Node(3));
	
	testSTack.Push(*(new Node(1)));
	testSTack.Push(*(new Node(5)));
	testSTack.Push(*(new Node(6)));
	testSTack.Display();
	cout << endl;
	testSTack.Push(*(new Node(5)));
	testSTack.Push(*(new Node(6)));
	testSTack.Push(*(new Node(5)));
	testSTack.Push(*(new Node(6)));
	testSTack.Display();
	cout << " " << endl;



	//POP FUNKAR INTE
	

	testSTack.Pop();

	Menu menyn;
	menyn.run();




	return 0;
}