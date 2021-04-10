#pragma once
#include <iostream>
#include "../Labb1-Algo/QueueLL.h"
#include <vector>
using namespace std;

void InsertionSort(int* UnsortedNumbers, int size_)
{

	int key, previousIndex;
	for (int i = 1; i < size_; i++)
	{
		key = UnsortedNumbers[i];
		previousIndex = i - 1;
		//Flyttar fram alla element i arrayen som är större än key
		while (previousIndex >= 0 && UnsortedNumbers[previousIndex] > key)
		{
			UnsortedNumbers[previousIndex + 1] = UnsortedNumbers[previousIndex];
			previousIndex--;
		}
		//Sätter in elementet key framför när man hittat ett element som är mindre 
		UnsortedNumbers[previousIndex + 1] = key;
	}
}

//Fungerar som när man sorterar en korthand
void InsertionSort(vector<int>& UnsortedNumbers, int size_)
{

	int key, previousIndex;
	for (int i = 1; i < size_; i++)
	{
		key = UnsortedNumbers[i];
		previousIndex = i - 1;

		//Flyttar fram alla element i arrayen som är större än key
		while (previousIndex >= 0 && UnsortedNumbers[previousIndex] > key)
		{

			UnsortedNumbers[previousIndex + 1] = UnsortedNumbers[previousIndex];
			previousIndex--;
		}
		//Sätter in elementet key framför när man hittat ett element som är mindre 
		UnsortedNumbers[previousIndex + 1] = key;
	}
	return;
}

//Prints your array
void printArray(int* Array, int lenght)
{
	int i=0;
	int charCount=0;
	int lineLen = 10;
	while (i < lenght)
	{
		printf("%d ", Array[i]);
		if (charCount >= lineLen)
		{
			printf("\n");
			charCount = 0;

		}
		charCount++;
		i++;
	}
	printf("\n");
}

//Prints your array
void printArray(vector<int>& Vector)
{
	int i = 0;
	int charCount = 0;
	int lineLen = 10;
	while (i < Vector.size())
	{

		printf("%d ", Vector[i]);
		if (charCount >= lineLen)
		{
			printf("\n");
			charCount = 0;

		}
		charCount++;
		i++;
	}
	printf("\n");
}

//Creates max-heap
void heapify(int* NumbersToHeapify, int size_, int rootIndex)
{
	int root = rootIndex;
	int leftChild = 2 * rootIndex + 1;
	int rightChild = 2 * rootIndex + 2;

	if (leftChild < size_ && NumbersToHeapify[leftChild] > NumbersToHeapify[root])
	{
		root = leftChild;
	}

	if (rightChild < size_ && NumbersToHeapify[rightChild] > NumbersToHeapify[root])
	{
		root = rightChild;

	}

	if (root != rootIndex)
	{
		swap(NumbersToHeapify[rootIndex], NumbersToHeapify[root]);

		//Heapify subtree recursively
		heapify(NumbersToHeapify, size_, root);
	}
}

//max-heapifierar ett subtree, sätter det största värdet i roten
void heapify(vector<int>& NumbersToHeapify, int size_, int rootIndex)
{
	int root = rootIndex;
	int leftChild = 2 * rootIndex + 1;
	int rightChild = 2 * rootIndex + 2;

	if (leftChild < size_ && NumbersToHeapify[leftChild] > NumbersToHeapify[root])
	{
		root = leftChild;
	}

	if (rightChild < size_ && NumbersToHeapify[rightChild] > NumbersToHeapify[root])
	{
		root = rightChild;

	}

	if (root != rootIndex)
	{
		swap(NumbersToHeapify[rootIndex], NumbersToHeapify[root]);

		//Heapify subtree recursively
		heapify(NumbersToHeapify, size_, root);
	}
}

void heapSort(int* UnsortedNumbers, int size_)
{
	//maxheapifierar varje subtree ända upp till roten, detta måste göras från löven till roten 
	for (int i = size_ / 2 - 1; i >= 0; i--)
	{
		heapify(UnsortedNumbers, size_, i);
	}

	for (int i = size_ - 1; i >= 0; i--)
	{
		//Send root to end of array
		swap(UnsortedNumbers[0], UnsortedNumbers[i]);

		heapify(UnsortedNumbers, i, 0);
	}
}

void heapSort(vector<int>& UnsortedNumbers, int size_)
{
	for (int i = size_ / 2 - 1; i >= 0; i--)
	{
		heapify(UnsortedNumbers, size_, i);
	}

	for (int i = size_ - 1; i >= 0; i--)
	{
		//Send root to end of array
		swap(UnsortedNumbers[0], UnsortedNumbers[i]);

		heapify(UnsortedNumbers, i, 0);
	}
}
//Takes three numbers from the range and returns the median
int betterPivot(int low, int high)
{
	int mid = int((low + high) / 2.0f);
	int toBeSorted[3] = { low, mid, high };
	InsertionSort(toBeSorted, 3);

	
	if(mid == toBeSorted[1])
	{

		return mid;
	}
	else if (low == toBeSorted[1])
	{
		return low;
	}
	else
	{
		return high;
	}

	return toBeSorted[1];
}

int partition(int* dynArray, int low, int high)
{
	//item From Left, item From Right
	int iFL = low;
	int iFR = high - 1;

	//Väljer sissta elementet som pivot. (Dåligt om listan är det minsta sorterad)

	int pivot = high;           //betterPivot(low, high);  <- Möjlighet att välja en bättre pivot
								//Swappa med sissta elementet
								//swap(dynArray[pivot], dynArray[high]);


	//Så länge som indexet från vänster inte är större än index från höger så
	//söker vi efter ett element från vänster som är större än pivot och ett element från
	//höger som är mindre än pivot. Om vi hittar detta så byter vi plats på dom.
	while (iFL <= iFR)
	{
		if (dynArray[iFL] < dynArray[pivot] && dynArray[iFR] > dynArray[pivot])
		{
			iFL++;
			iFR--;
		}
		else if (dynArray[iFL] < dynArray[pivot])
		{
			iFL++;
		}
		else if (dynArray[iFR] > dynArray[pivot])
		{
			iFR--;
		}	
		else
		{	
			swap(dynArray[iFL], dynArray[iFR]);
			iFL++;
			iFR--;
		}
	}
	swap(dynArray[iFL], dynArray[pivot]);

	return iFL;
}

int partition(vector<int>& vec, int low, int high)
{
	//item From Left, item From Right
	int iFL = low;
	int iFR = high - 1;

	//Väljer sissta elementet som pivot. (Dåligt om listan är det minsta sorterad)

	int pivot = high;           //betterPivot(low, high);  <- Möjlighet att välja en bättre pivot
								//Swappa med sissta elementet
								//swap(dynArray[pivot], dynArray[high]);

	//Så länge som indexet från vänster inte är större än index från höger så
	//söker vi efter ett element från vänster som är större än pivot och ett element från
	//höger som är mindre än pivot. Om vi hittar detta så byter vi plats på dom.
	while (iFL <= iFR)
	{
		if (vec[iFL] < vec[pivot] && vec[iFR] > vec[pivot])
		{
			iFL++;
			iFR--;
		}
		else if (vec[iFL] < vec[pivot])
		{
			iFL++;
		}
		else if (vec[iFR] > vec[pivot])
		{
			iFR--;
		}
		else
		{
			swap(vec[iFL], vec[iFR]);
			iFL++;
			iFR--;
		}
	}
	swap(vec[iFL], vec[pivot]);

	return iFL;
}

void BucketSort(int* UnsortedNumbers, int size_)
{
	//Den här måste ändras om vi ska köra ett annat spann
	int highestNr = 100; 

	//More buckets is faster but requires more memory
	int numberOfBuckets = int(sqrt(size_));


	//Queue data structure for buckets
	QueueLL* buckets = new QueueLL[numberOfBuckets];

	//Divide elements with this to know what bucket to put them in
	int divider = int((highestNr + 1) / float(numberOfBuckets)) + 1;

	//Put elements in buckets
	for (int i = 0; i < size_; i++)
	{
		int index = int(UnsortedNumbers[i] / float(divider));
		buckets[index].insertLast(UnsortedNumbers[i]);		
	}

	//Sort buckets and put back into array sorted
	int a = 0;
	for (int i = 0; i < numberOfBuckets; i++)
	{
		int bucketsize = buckets[i].getSize();
		int* oneBucket = new int[bucketsize];

		for (int c = 0; c < bucketsize; c++)
		{
			oneBucket[c] = buckets[i].Peek();
			buckets[i].Pop();
		}
		InsertionSort(oneBucket, bucketsize);
		for (int b = 0; b < bucketsize; b++)
		{
			UnsortedNumbers[a] = oneBucket[b];
			a++;
		}
	}
}


void BucketSort(vector<int>& UnsortedNumbers, int size_)
{
	int highestNr = 100;
	//More buckets is faster but requires more memory
	int numberOfBuckets = int(sqrt(size_));
	//Queue data structure for buckets
	QueueLL* buckets = new QueueLL[numberOfBuckets];

	//Divide elements with this to know what bucket to put them in
	int divider = int((highestNr + 1) / float(numberOfBuckets)) + 1;

	//Put elements in buckets
	for (int i = 0; i < size_; i++)
	{
		int index = int(UnsortedNumbers[i] / float(divider));
		buckets[index].insertLast(UnsortedNumbers[i]);
	}
	//Sort buckets and put back into array sorted
	int a = 0;
	for (int i = 0; i < numberOfBuckets; i++)
	{
		int bucketsize = buckets[i].getSize();
		int* oneBucket = new int[bucketsize];

		for (int c = 0; c < bucketsize; c++)
		{
			oneBucket[c] = buckets[i].Peek();
			buckets[i].Pop();
		}

		InsertionSort(oneBucket, bucketsize);
		for (int b = 0; b < bucketsize; b++)
		{
			UnsortedNumbers[a] = oneBucket[b];
			a++;
		}
	}
}

void Quicksort(int* UnsortedNumbers, int low, int high)
{

	if (low < high)
	{

		int partitionIndex = partition(UnsortedNumbers, low, high);

		Quicksort(UnsortedNumbers, low, partitionIndex - 1);
		Quicksort(UnsortedNumbers, partitionIndex+1, high);
	}

}

void Quicksort(vector<int>& UnsortedNumbers, int low, int high)
{

	if (low < high)
	{

		int partitionIndex = partition(UnsortedNumbers, low, high);

		Quicksort(UnsortedNumbers, low, partitionIndex - 1);
		Quicksort(UnsortedNumbers, partitionIndex + 1, high);
	}
}


int* RandomArray(int size_, int upTo, int startingAt)
{
	int* numberArray = new int[size_];
	
	for (int i = 0; i < size_ ; i++)
	{

		numberArray[i] = rand() % upTo + startingAt;
	}

	return numberArray;

}

void copyArray(int* dynArray, vector<int>& vec, int size_)
{
	for (int i = 0; i < size_; i++)
	{
		vec[i] = dynArray[i];
	}

}


