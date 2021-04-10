#include <iostream>
#include <stdexcept>


struct node{  //Nod struct
int _data;	  //Heltal i noden
node* _next;   //Pekar till nästa nod

//constructormetoder
node(void)
{
_data = 0;
_next = 0;

}

node(int data)
{
_data = data;
_next = 0;


}

node(int data, node* next)
{

	
	_data = data;
	_next = next;

}



};

//=============================================================


class LinkedList{

node* _current;   // (ITERATOR POS) 

node* _previous;   //

node* _head;  //Denna pekar på första noden



LinkedList(void)
{
	node *_head; //Huvudnod, Dummynode

 _current = _head;

 _previous = _head; 


}

bool isOff()
{
	return(!_current);

}


void start()
{
_current = _head->_next;
_previous = _head;
}


void forth()
{
if(isOff())
{
	throw std::range_error("Out of bounds");

}
_previous = _current;
_current = _current->_next;

}



// Sissta nodens pekare bör vara NULL 

//n = new node();
//n->_data = 1;
//t = n; 
//h = n;

};


//===============================================
//
//
//template<class T>
//class singleListArray
//{
//public:
//
//	singleListArray(int size = 11)
//	{
//		Array = new node[size]; // Gör array med celler
//
//								// Fyll stack med tomma cellindexes
//		for (int i = 0; i < size; i++)
//		{
//			emptyCellindexes.push(i);
//		}
//		this->size = emptyCellindexes.size() - 1;
//
//		preIndex = -1;
//		anchorIndex = -1;
//		iteratorIndex = -1;
//	}
//
//	void start()
//	{
//		preIndex = -1;
//		iteratorIndex = anchorIndex;
//	}
//
//
//	struct node
//	{
//		T data;
//		int next;
//
//		node()
//		{
//			data = 0;
//			next = -1;
//		};
//	};
//
//	int iteratorIndex;
//
//private:
//	int anchorIndex;
//	int preIndex;
//	int size;
//	Stack emptyCellindexes;
//
//	node *Array;
//
//};