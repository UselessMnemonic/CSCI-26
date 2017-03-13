/*
Authored by Christopher J. Madrigal (0778098)
20 February 2017
+++++++++++++++++++++++++++++++++++++++++++++++++++++++
+ BinarySearch.cpp                                    +
+ Simple application to demonstrate the binary search +
+  algorithm                                          +
+                                                     +
+ User specifies number of elements in array A, then  +
+  a number to search for.                            +
+++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

int binarySearch(vector<int> items, int numToFind); //locates numToFind in items, assuming items is sorted in ascending order

int main()
{
	srand(time(NULL)); //init random
	int numOfEntries; //user-specified array size
	vector<int> data; //vector that holds random numbers in ascending order
	int selection;	  //number user wishes to search for
	int ind;		  //result of binary search

					  //prompt user for size of data list
	cout << "How many numbers to use (-1 to stop): ";
	cin >> numOfEntries;

	if (numOfEntries == -1) //cease if input is -1
		return 0;

	//fill array with random numbers between 1 and 1000
	for (int s = 1; s <= numOfEntries; s++)
		data.push_back(rand() % 1000 + 1);
	sort(data.begin(), data.end()); //sort with predefined sorting algorithm

	int n = 0;
	//print array as 10-wide rows until there are no more numbers
	for (int d = 1; d <= numOfEntries; d++)
	{
		cout << setw(4) << data[d - 1] << "   ";
		n++;
		if (n == 10)
		{
			n = 0;
			cout << endl;
		}
	}
	cout << endl;

	do //continuously prompt user for a number to search
	{
		cout << "Enter a number you wish to search for (-1 to stop): ";
		cin >> selection;
		ind = binarySearch(data, selection);
		if (ind == -1)
			cout << "That number was not found in the array.";
		else
			cout << selection << " was found at A[" << ind << "].";
		cout << endl << endl;
	} while (selection != -1); //cease when user has inputted -1 for their selection

	return 0;
}

int binarySearch(vector<int> items, int numToFind)
{
	int i = 0; //starting index
	int j = items.size() - 1; //last index in items
	int m; //holds index right in the middle of i and j
	int location; //result of binary search

	while (i < j) //until we have crossed the first and last indices
	{
		m = (i + j) / 2; //find the middle between i and j
		if (numToFind > items[m]) //if our number to find is between m and j...
			i = m + 1; //look between m and j
		else
			j = m; //otherwise, look again between i and m
	}

	if (numToFind == items[i]) //if i is the index that gives us our desired number
		location = i; //return i
	else
		location = -1;//otherwise, return -1
	return location;
}