/*
File: Assignment2_Miranda.cpp
Author: Michael Miranda
Function: The user enters the size and contents of the array for info
Input: size of array and numbers inside
Output: the max, min, avg, median, and reorderd array
Created September 11, 2017
*/ 

#include <cstdlib>
#include <iostream>

using namespace std;
int size(0);
void readArray(double[], int);
void printArray(double[], int);

void sort(double[], int);

double max(double[], int);
double min(double[], int);
double mean(double[], int);
double median(double[], int);


int main(int argc, char** argv)
{
	cout << "Please enter the size of the Array" << endl;
	cin >> size;
	double myArray[size];	

	cout << "Please enter the " << size << " numbers" << endl;
	readArray(myArray, size);
	
	cout << "The max number in the array is: " << max(myArray, size) << endl;
	cout << "The min number in the array is: " << min(myArray, size) << endl;
	cout << "The average of the array is: " << mean(myArray, size) << endl;

	sort(myArray, size);

	cout << "The median of the array is: " << median(myArray, size) << endl;
	cout << "The sorted version of the array is: ";
	printArray(myArray, size);


	return 0;
}

void printArray(double myArray[], int size)//gives an array and int and prints the values of the array
{
for(int i =0; i<size; i++)
	cout << myArray[i] << " ";
	cout << endl;
}


void readArray(double myArray[], int size)//gives an array and int and gives them values from the user
{
	for(int i=0; i<size; i++)
	{
		cin >> myArray[i];
	}

}

double max(double myArray[], int size)// gives an array and int to return the largest double in the array
{
	double maxNum(myArray[0]);

	for(int i=1; i<size; i++)
	{
		if(myArray[i] > maxNum)
			maxNum = myArray[i];
	}

	return maxNum;
}

double min(double myArray[], int size)//gives an array and int to return the smallest double in the array
{
	double minNum(myArray[0]);
	
	for(int i=1; i<size; i++)
        {
                if(myArray[i] < minNum)
                        minNum = myArray[i];
        }

        return minNum;
}

double mean(double myArray[], int size)//gives an array and int to return a double of the average
{
	double total(0);
	for(int i=0; i<size; i++)
		total += myArray[i];	

	return total/size;

}

double median(double myArray[], int size)//gives an array and int to return the middle value od the array and splits the two middle ones if size is even to split
{
	double middleNum;
	if(size%2 == 0)
	{
		middleNum = ( myArray[size/2] + myArray[(size-1)/2] )/2 ;
		//cout << "A occured" << endl;
	}
	else if(size%2 == 1)
	{
		middleNum = myArray[(size-1)/2];
		//cout << "B occured" << endl;
	}
	else 
		//cout << "C occurred" << endl; for error checking

	return middleNum;
}

void sort(double myArray[], int size)//gives an array and int and reorders the array
{
	for(int i = 1; i<size; i++)
	{
	   for(int j = i; j>0 && myArray[j-1] > myArray[j]; j--)
		{
		   double temp = myArray[j];
		   myArray[j] = myArray[j-1];
		   myArray[j-1] = temp;
		}
	}
}






