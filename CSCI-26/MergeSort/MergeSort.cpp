/* MergeSort.cpp
* Implementatoin and demonstration of the merge sort
*  algortithm.
* Christopher Madrigal
* 12 March 2017 */

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

typedef vector<int> List;
List mergeSort(List list);
List merge(List list1, List list2);

int main()
{
	srand(time(NULL)); //init random
	int numOfEntries; //user-specified array size
	List unsorted;		  //vector that holds random numbers in ascending order
	List sorted;		  //result of mergesorts

	//prompt user for size of data list
	while (true)
	{
		cout << "How many numbers to use (-1 to stop): ";
		cin >> numOfEntries;

		if (numOfEntries < 0) //cease if input is < 0
			return 0;

		//fill array with random numbers between 1 and 1000
		for (int s = 1; s <= numOfEntries; s++)
			unsorted.push_back(rand() % 1000 + 1);

		//sort list
		sorted = mergeSort(unsorted);

		//print array as 10-wide rows until there are no more numbers (unsorted list)
		for (int d = 1, n = 0; d <= numOfEntries; d++)
		{
			cout << setw(4) << unsorted[d - 1] << "   ";
			n++;
			if (n == 10)
			{
				n = 0;
				cout << endl;
			}
		}

		cout << endl << endl << "Merge sorted: " << endl << endl;

		//print array as 10-wide rows until there are no more numbers (sorted list)
		for (int d = 1, n = 0; d <= numOfEntries; d++)
		{
			cout << setw(4) << sorted[d - 1] << "   ";
			n++;
			if (n == 10)
			{
				n = 0;
				cout << endl;
			}
		}
		cout << endl << endl;

		unsorted.clear();
		sorted.clear();
	}

	return 0;
}

List mergeSort(List list)
{
	int n = list.size(); //size of list
	int m; //index to middle of list
	List firstHalf, secondHalf; //used to split the argument in two

	if (n > 1) //if the list size is greater than one
	{
		m = n / 2; //find the center of the list
		//split the list using the intervals [0, m) and [m, n-1]
		firstHalf = List(list.begin(), list.begin() + m);
		secondHalf = List(list.begin() + m, list.end());

		//merge the sorted halves
		list = merge(mergeSort(firstHalf), mergeSort(secondHalf));
	}
	return list;
}

List merge(List listOne, List listTwo)
{
	List result; //result of merge
	int e1, e2; //elements of listOne and listTwo

	while (listOne.size() > 0 && listTwo.size() > 0) //while either list is not empty
	{
		//get the front of both lists
		e1 = listOne.at(0);
		e2 = listTwo.at(0);

		//compare elements; remove the smaller of the two from its list and append to result
		if (e1 > e2)
		{
			listTwo.erase(listTwo.begin());
			result.push_back(e2);
		}
		else
		{
			listOne.erase(listOne.begin());
			result.push_back(e1);
		}
	}

	//finally, append the reaminder list to the result
	if (listOne.size() == 0)
		result.insert(result.end(), listTwo.begin(), listTwo.end());
	else
		result.insert(result.end(), listOne.begin(), listOne.end());;

	return result;
}