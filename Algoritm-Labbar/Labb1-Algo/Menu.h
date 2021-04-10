#pragma once
#include "ArrayLinkedList.h"
#include "LinkedList.h"
#include "StackLL.h"
#include "QueueLL.h"
#include "Nodes.h"
#include <vector>


using namespace std;

class Menu {

private:
	
	StackLL   stacken;
	QueueLL*			quen; 
	LinkedList*      linklistan;
	ArrayLinkedList<int>* arrayListan;
	


public:
	
	
	char Choice;
	 
	Menu()
	{
		
		quen = new QueueLL();
		linklistan = new LinkedList();
		//Menu konstrukt

	}



	void run()
	{

	bool running = true;
	while (running)
	{
		cout << "Welcome to testing" << endl;
		cout << "Press 1 for linked list \nPrese 2 for Array Linked List \nPress 3 for Stack \nPress 4 for Queue \nPress 9 to exit" << endl;
		cin >> Choice;
		switch (Choice)
		{
		case '1':
		{
			cout << linklistan->pre->next << endl;
			cout << "You chose Linked list, Alternatives: \n1.Insert \n2.Step Forth \n3.Start of list \n4.Get item \n5.Write \n7.Remove at \n9.Return" << endl;

			while (Choice != '9')
			{



				cin >> Choice;
				switch (Choice)
				{
				case '1':


					cout << "Give an integer to be stored" << endl;
					int temp;
					cin >> temp;
					
					//linklistan.addFirst(linklistan.head.next, temp);
					(*linklistan).insertBefore(*(new Node(temp)));
					cout << (*linklistan).head.next << endl;
					cout << "node added" << endl;
					break;

				case '2':
				{
					cout << "Stepping forth" << endl;
					(*linklistan).forth();
					break;
				}

				case '3':
				{
					cout << "iterator returned to beginning" << endl;
					(*linklistan).start();
					break;
				}
				case '4':
				{
					cout << "The node you are currently at contains: " << (*linklistan).item() << endl;
					break;

				}
				case '5':
				{

					(*linklistan).Write();
					break;
				}
				case '6':
				{

					cout << "Give an integer to be stored" << endl;
					int temp;
					cin >> temp;
					linklistan->addFirst(linklistan->head.next, temp);
					cout << "node added" << endl;

				}
				case '7':
				{
					cout << "pop!" << endl;
					linklistan->removeAt();

				}



				}
			}
			break;
			
		}






		case '2':
		{
			cout << "You chose Array Linked List, set the size.." << endl;
			int temp;
			cin >> temp;
			arrayListan = new ArrayLinkedList<int>(temp);
			cout << "Your list has been created \nAlternatives: \n1.Insert \n2.Step Forth \n3.Start of list \n4.Get item \n5. \n9.Return" << endl;

			while (Choice != '9')
			{

			

			cin >> Choice;
			switch (Choice)
			{
			case '1':
				cout << "Give an integer to be stored" << endl;
				int temp;
				cin >> temp;
				(*arrayListan).insertAt(temp);
				cout << "number added" << endl;
				break;

			case '2':
			{
				cout << "Stepping forth" << endl;
				(*arrayListan).forth();
				break;
			}

			case '3':
			{
				cout << "iterator returned to beginning" << endl;
				arrayListan->start();
				break;
			}
			case '4':
			{
				cout << "The node you are currently at contains: " << (*arrayListan).item() << endl;
				break;

			}
			case '5':
			{

				arrayListan->write();
				break;
			}



			}
			}
			break;
		}



		case '3':
		{
			cout << "You chose Stack, Alternatives: \n1.Push \n2.Pop \n3.Write \n9.Return" << endl;
			while (Choice != '9')
			{

			

				cin >> Choice;
			switch (Choice)
			{
			case '1':
			{
				cout << "Give an integer to be stored" << endl;
				int temp;
				cin >> temp;
				stacken.Push(*(new Node(temp)));
				cout << "number added" << endl;
				break;
			}
			case '2':
			{
				cout << "Pop! " << endl;
				stacken.Pop();
				break;
			}

			case '3':
			{
				cout << "Stack values: " << endl;
				stacken.Display();
				Choice = 0;
				break;
			}			
			}		
			}
			break;
			
		}

		case '4':
		{
			cout << (*quen).lastPos->next << endl;
			cout << "You chose Queue, Alternatives: \n1.Insert Last \n2.Pop \n3.Write \n4.Peek \n9.Return" << endl;
			while (Choice != '9')
			{



				cin >> Choice;
				switch (Choice)
				{
				case '1':
				{
					cout << "Give an integer to be stored" << endl;
					int temp;
					cin >> temp;
					quen->insertLast(temp);
					cout << quen->head.next << endl;
					cout << "number added" << endl;
					break;
				}
				case '2':
				{
					cout << "Pop! " << endl;
					quen->Pop();
					break;
				}

				case '3':
				{
					cout << "Stack values: " << endl;
					quen->Write();
					Choice = 0;
					break;
				}

				case '4':
				{
					cout << (*quen).Peek() << " is the element at the front of the queue" << endl;

				}
				}
			}
			break;

		}




		case '9':
		{
			cout << "exit program" << endl;

			running = false;
			break;
		}

		}

	}





	}

};