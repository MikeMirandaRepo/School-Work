
/* 
 * File:   Array.h
 * Author: Michael Miranda
 * input: Numbers from the user
   output: different Arrays depending on method called
 * Description: defines multiple methods to be used in the main method
   Created on September 18, 2017
 */

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

void init(double *myArray, int size) {//gives all variables values based on user input
    for (int i = 0; i < size; i++) {
      cin >> myArray[i];
    }
}

void print(double *myArray, int size) {// prints all variables and their values
    for (int i = 0; i < size; i++) {
        cout << myArray[i] << " ";
    }
    cout << endl;
}


void insert(int index, double num, double *&myArray, int &size)// takes an index and value to be entered at the specified position
{
	if(index > size+2){
	cout << "Error. Out of bounds with respect to insert() " << endl;
	}
	else {
	double *tempArray = new double[size +1];
	
	for(int i = 0; i < index; i++)
		*(tempArray+i) = *(myArray+i);

	*(tempArray+index) = num;//assignes the new double in the spot given by the user	
	
	for(int i = index+1; i < size+1; i++)//start off where the new double was added to complete the array
		*(tempArray+i) = *(myArray+(i-1));//takes one away from the current index due to the temp array being ahead by 1
	
	delete myArray;
	myArray = new double[size+1];
	
	for(int i = 0; i < size+1; i++)	{	
		*(myArray+i) = *(tempArray+i);	
	}

	delete [] tempArray;
	size++;

	}

}

void remove(int index, double *&myArray, int &size)// removes a particular value based on the index provided and reduces the size from the main
{
	if(index >= size){
		cout << "Error. out of bounds with respect to remove()" << endl;
	}
	else
	{
	double *tempArray = new double[size-1];

	for(int i = 0; i < index; i++)
		*(tempArray+i) = *(myArray+i);
	
	for(int i = index +1; i < size-1; i ++)
		*(tempArray+i) = *(myArray+i);

	delete myArray;
	myArray = new double[size -1];

	for(int i = 0; i < size-1; i++)
		*(myArray+i) = *(tempArray+i);

	delete [] tempArray;
	size--;

	}

}

int get(int index, double *myArray, int size)//returns a double from a specified index
{
	double temp(-1);
	if(index > size || index < 0) {
		cout << "Error. out of bounds with respect to get()" << endl;
	}
	else
	{	
	temp = *(myArray+index);
	}
	return temp;
}


void clear(double *&myArray, int &size)//clears/deletes all values in the array and makes size in the main 0
{
	size = 0;
	delete myArray;
}

int find(double num, double *myArray, int size)//searches for a specific value in the array and returns the index from which it resides. otherwise returns -1
{
	for(int i = 0; i < size; i++)
	{
		if((*myArray+i) == num)
			return i;
	}
	return -1;
}

bool equals(double *myArray1, int size1, double *myArray2, int size2)//takes in two arrays and sizes and compares them. false if any value or size of array is diff
{
	if(size1 != size2)
	{
		return false;
	}
	else
	{
		for(int i = 0; i < size1; i ++)
		{
			if(*(myArray1+i) != *(myArray2+i))
				return false;
		}
	}
	return true;
}



#endif /* ARRAY_H */

