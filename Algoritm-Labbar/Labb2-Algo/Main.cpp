#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>
#include "Functions.h"
using namespace std;
using namespace std::chrono;

int main()
{
//Listorna skapas, slumpas och sätts till samma värden.
	int sizeOfList = 100;
	int* NumbersToSort = RandomArray(sizeOfList, 100, 1);
	vector<int> NumbersToSortVector(sizeOfList);
	copyArray(NumbersToSort, NumbersToSortVector, sizeOfList);

//Dynamic array implementation testing
//=============================================

	//Check time at start
	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	//Sorting methods
	InsertionSort(NumbersToSort, sizeOfList);
	//Quicksort(NumbersToSort, 0, sizeOfList-1);
	//heapSort(NumbersToSort, sizeOfList);
	//BucketSort(NumbersToSort, sizeOfList);
	printArray(NumbersToSort, sizeOfList);


	//Check time at end
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	//Räkna ut tid som passerat
	auto duration = duration_cast<microseconds>(t2 - t1).count();

	
	string currentOrder = "Sorted";
	ofstream myfile;
	myfile.open("example.txt", fstream::app);
	myfile << "Runtime: " << duration << endl;
	myfile << "Number of items sorted: " << sizeOfList << endl;
	myfile << "Current order: " << currentOrder <<endl;
	myfile.close();

	cout << "(array)You spent this amount of time in the program: " << duration << endl;

//Vector implementation testing
//=============================================

	//Check time at start
	t1 = high_resolution_clock::now();

	//sorting methods
	InsertionSort(NumbersToSortVector, sizeOfList);
	//Quicksort(NumbersToSortVector, 0, sizeOfList-1);
	//heapSort(NumbersToSortVector, sizeOfList);
	//BucketSort(NumbersToSortVector, sizeOfList);
	printArray(NumbersToSortVector);

	//Check time at end
	t2 = high_resolution_clock::now();
	//Räkna ut tid som passerat
	duration = duration_cast<microseconds>(t2 - t1).count();

	currentOrder = "Sorted";
	myfile.open("example.txt", fstream::app);
	myfile << "Runtime: " << duration << endl;
	myfile << "Number of items sorted: " << sizeOfList << endl;
	myfile << "Current order: " << currentOrder << endl;
	myfile.close();

	cout << "(vector)You spent this amount of time in the program: " << duration << endl; 
	//Wait for input before closing
	int a;
	cin >> a;
}


