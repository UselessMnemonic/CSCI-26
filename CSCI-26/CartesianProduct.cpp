/*
Authored by Christoper J. Madrigal (0778098)
5 Feburary 2017
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+ CartesianProduct.cpp                                     +
+ Simple application to demonstrate cartesian set products +
+                                                          +
+ User specifies elements of set A and B,                  +
+  then used by the program to calculate                   +
+  the Cartesian product between them                      +
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/

#include <iostream>
using namespace std;

void calculateCartesian();

int main()
{
	char choice = 'y'; //store user's choice
	while (choice == 'y') //while the user wishes to continue
	{
		calculateCartesian(); //calculate a cartesian product
		cout << "Again? (y/n): "; //prompt user for another test
		cin >> choice; //store the user's responce
		choice = tolower(choice); //determine if loop should continue
	}
}

void calculateCartesian()
{
	int numIntegers = 0; //store the number of integers entered by the user
	int numCharacters = 0; //store the number of characters entered by the user

	int integerInput[30]; //store up to 30 integers
	char characterInput[30]; //store up to 30 characters

	int lastInt; //temporarily user's integer input
	char lastChar; //temporarily holds user's character input

	int pairs; //set to the number of pairs to be printed on screen

	cout << "Enter no more than 30 integers for set A. Use -1 to stop." << endl; //prompt user
	//finally, a place to use do-while loops!
	do
	{
		cout << numIntegers + 1 << ": "; //prompt user to integered entered
		cin >> lastInt; //holds the input for later discrimination
						//store the input into our array, with numIntegers acting as an index
		integerInput[numIntegers] = lastInt;
		numIntegers++; //increment the numer of integeres inputed by yser
	}
	/* continues processing input untill either limit has been reached,
	* or a -1 has been entered
	*/
	while (numIntegers <= 30 && lastInt != -1);
	//decrement our counter on account of storing our terminal integer
	numIntegers--;

	cout << "Enter no more than 30 characters for set B. Use '.' to stop." << endl; //prompt user
	do
	{	//behaves exactly as integer-input loop
		cout << numCharacters + 1 << ": ";
		cin >> lastChar;
		characterInput[numCharacters] = lastChar;
		numCharacters++;
	} while (numCharacters <= 30 && lastChar != '.');
	numCharacters--;

	//calculate the number of pairs to print, also acts as check for empty sets
	pairs = numCharacters * numIntegers;

	cout << "Set A = {";
	for (int i = 0; i < numIntegers; i++)//for all valid integers...
	{
		cout << ' ' << integerInput[i];  //output integers to screen
		if (i + 1 < numIntegers)		 //until the last one, where we don't want a leading comma
			cout << ",";
	}
	cout << " }" << endl;


	cout << "Set B = {";
	for (int j = 0; j < numCharacters; j++)//for all valid characters...
	{
		cout << ' ' << characterInput[j];  //output characters to screen
		if (j + 1 < numCharacters)		   //until the last one, where we don't want a leading comma
			cout << ",";
	}
	cout << " }" << endl;


	cout << "A X B = {";
	//If A and/or B are empty sets, an empty set is the result
	for (int x = 0; x < numIntegers; x++) //for all valid elements in A
	{
		for (int y = 0; y < numCharacters; y++) // and for valid all elements in B
		{
			cout << " (" << integerInput[x] << ", " << characterInput[y] << ")"; //print the pair
			pairs--; //decrement the number of pairs left to print
		}
		//if there are still more pairs to print
		if (pairs > 0)
		{
			cout << ","; //print a comma
			cout << endl << "         "; //and a newline followed by spacing
		}
		//continues until all pairs are printed up to the last, where leading commas are not printed
	}
	cout << " }\n\n";
}
