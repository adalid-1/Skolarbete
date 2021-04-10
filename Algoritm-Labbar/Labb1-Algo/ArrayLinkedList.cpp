
#include "ArrayLinkedList.h"
#include "Nodes.h"


template<class anyType>
ArrayLinkedList<anyType>::ArrayLinkedList(int size_)
{
	_size = size_;
	anchorIndex = 0;
	pre = -1;
	iteratorIndex = anchorIndex;
	//cellSpace(size_);
	cellSpace = new vector<Node2<anyType>>(size_);

	makeNOdes();



}


template<class anyType>
anyType ArrayLinkedList<anyType>::getData(int index)
{
	return cellspace[iteratorIndex].data;
}




//Returns the index of the next node in the list if there is a next
template<class anyType>
int ArrayLinkedList<anyType>::NextNr()
{
	if (!isOff())
	{
		if (!(isOff((*cellSpace)[iteratorIndex].next)))
			return (*cellSpace)[iteratorIndex].next;
		else
		{
			cout << "Next index is off the list" << endl;
		}

	}
	else
	{
		cout << "iterator is off" << endl;
	}
}

//Get item from current iterator position
template<class anyType>
anyType ArrayLinkedList<anyType>::item()
{
	if (!isOff())
	{
		return (*cellSpace)[iteratorIndex].data;
	}
	else
	{
		cout << "iterator is off" << endl;
	}
}

//Används för initiering
template<class anyType>
void ArrayLinkedList<anyType>::makeNOdes()
{
	for (int i = 0; i < _size; i++)
	{
		(*cellSpace)[i] = Node2<anyType>();
		(*cellSpace)[i].next = i + 1;
		(*cellSpace)[i].data = -1;

	}

}

template<class anyType>
void ArrayLinkedList<anyType>::write()
{

	for (int i = 0; i < _size; i++)
	{
		cout << (*cellSpace)[i].data << " ";

	}
	cout << endl;

}


//void removeAt()
template<class anyType>
void ArrayLinkedList<anyType>::insertAt(anyType newData)
{
	if (!isOff())
	{
		(*cellSpace)[iteratorIndex].data = newData;
	}
	else
	{
		cout << "cant insert here" << endl;
	}

}

//Förflytta pekaren framåt 
template<class anyType>
void ArrayLinkedList<anyType>::forth()
{
	if (isOff((*cellSpace)[iteratorIndex].next))
	{

		cout << "Iterator is at the end of the list" << endl;
	}
	else
	{
		pre = iteratorIndex;
		iteratorIndex = (*cellSpace)[iteratorIndex].next;
	}

}

template<class anyType>
void ArrayLinkedList<anyType>::start()
{
	iteratorIndex = anchorIndex;


}

template<class anyType>
bool ArrayLinkedList<anyType>::isOff()
{
	if (iteratorIndex > (_size - 1) || iteratorIndex < 0)
	{
		return true;
	}
	else return false;
}


template<class anyType>
bool ArrayLinkedList<anyType>::isOff(int index)
{
	if (index > (_size - 1) || index < 0)
	{
		return true;
	}
	else return false;

}


//Funkar inte, vet inte varför
//template<class anyType>
//Node2<anyType> ArrayLinkedList<anyType>::getNode(int index)
//{
//	return cellspace[iteratorIndex].data;
//}





//Osäkert om den här behövs
template<class anyType>
void ArrayLinkedList<anyType>::insertNodeAt(int index, Node2<anyType> nod)
{

	(*cellSpace)[index] = nod;
	nod.next = index + 1;



}