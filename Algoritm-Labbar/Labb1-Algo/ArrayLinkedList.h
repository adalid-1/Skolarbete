#pragma once


template<class anyType>
class ArrayLinkedList
{
public:
	int anchorIndex;
	int iteratorIndex;
	int pre;
	int _size;
	vector<Node2<anyType>>* cellSpace;

	ArrayLinkedList(int size_)
	{
		_size = size_;
		anchorIndex = 0;
		pre = -1;
		iteratorIndex = anchorIndex;
		//cellSpace(size_);
		cellSpace = new vector<Node2<anyType>>(size_);

		makeNOdes();



	}


	//Getters
	Node2<anyType> getNode(int index)
	{
		return *cellSpace[index];
	}

	anyType getData(int index)
	{

		return (*cellSpace)[index].data;
	}

	//Returns the index of the next node in the list if there is a next
	int NextNr()
	{
		if (!isOff())
		{
			if (!(isOff((*cellSpace)[iteratorIndex].next))  )
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
	anyType item()
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
	void makeNOdes()
	{
		for (int i = 0; i < _size; i++)
		{
			(*cellSpace)[i] = Node2<anyType>();
			(*cellSpace)[i].next = i + 1;
			(*cellSpace)[i].data = -1;

		}

	}

	void write()
	{

		for (int i = 0; i < _size; i++)
		{
			cout << (*cellSpace)[i].data << " ";

		}
		cout << endl;

	}


	//void removeAt()
	void insertAt(anyType newData)
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
	void forth()
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
	void start()
	{
		iteratorIndex = anchorIndex;


	}


	bool isOff()
	{
		if (iteratorIndex > (_size - 1) || iteratorIndex < 0)
		{
			return true;
		}
		else return false;
	}

	bool isOff(int index)
	{
		if (index > (_size - 1) || index < 0)
		{
			return true;
		}
		else return false;

	}




	//Osäkert om den här behövs
	void insertNodeAt(int index, Node2<anyType> nod)
	{

		(*cellSpace)[index] = nod;
		nod.next = index + 1;



	}
};