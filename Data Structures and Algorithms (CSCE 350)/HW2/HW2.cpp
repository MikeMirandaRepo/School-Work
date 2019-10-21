/*
File: HW2.cpp
Author: Michael Miranda
*/ 
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;
long long comparisons;
vector<int> comparisonz;


vector<int> selectionSort(vector<int> arr, int n) 
{ 
    int i, j, mini; 
    vector<int> returned;
    for (i = 0; i < n-1; i++) 
    {  
        mini = i; 
        for (j = i+1; j < n; j++) {
          if (arr[j] < arr[mini]) 
            mini = j;
	    comparisons++;	 
   	}

	swap(arr[mini], arr[i]); 
    } 
	for(int i = 0; i < n; i++)
		returned.push_back(arr[i]);

	return returned;
}

bool stlC(int i, int j) {
	comparisons++;
	return i<j;
}

int qsortCompare(const void *a, const void *b) {
	comparisons++;
	if (*(int*)a < *(int*)b) 
		return -1;
	if (*(int*)a == *(int*)b) 
		return 0;
	
	return 1;
}



void  printVector(vector<int> a, int size){
	cout << "The printed list is: " << endl;
	for(int i = 0; i < size; i++)
		cout << a[i] << " " << endl;

	if(comparisons != 0)
		cout << "Comparisons: " << comparisons << endl;


}

int main(int argc, char *argv[])
{
	vector<int> number;
	string sortType;

	int entered = -1;
	cin >> sortType;

	while(entered != 0)
		{
		cin >> entered;
		if(entered != 0){
		number.push_back(entered);
		}
	}
	printVector(number, number.size());

	if(sortType == "selection"){
		vector<int> selected = selectionSort(number, number.size());	
		printVector(selected, selected.size());
	} else 
	if(sortType == "qsort"){
		qsort(&(number[0]), number.size(), sizeof(int), qsortCompare);
		printVector(number, number.size());
	} else 
	if(sortType == "stl"){
		sort(number.begin(), number.end(), stlC);
		printVector(number, number.size());
	}


}



	




