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

vector<int> ofSort(int times, int length, string sort){


vector<int> rando;
vector<int> selecRando;
for(int h = 0; h < times; h++){
	
	for(int i = 0; i < length; i++){
		rando.push_back((rand()%100000)+1);
		}

	if(sort == "selection"){
		selecRando = selectionSort(rando, rando.size());
		selecRando.clear();
		}
	else if(sort == "qsort"){
		qsort(&(rando[0]), rando.size(), sizeof(int), qsortCompare);
		}
	else if(sort == "stl"){
		//sort(rando.begin(), rando.end(), stlC);
	}
 	//printVector(selecRando, selecRando.size());	
	comparisonz.push_back(comparisons);
	comparisons = 0;
	rando.clear();
	length += 200;
	}
return comparisonz;
}

int main(int argc, char *argv[])
{
	vector<int> number;
	string sortType = "";

	int entered = -1;
	//cin >> sortType;

	//while(entered != 0)
		{
		//cin >> entered;
		if(entered != 0){
		number.push_back(entered);
		}
	}
	//printVector(number, number.size());

	if(sortType == "selection"){
		vector<int> selected = selectionSort(number, number.size());	
		//printVector(selected, selected.size());
	} else 
	if(sortType == "qsort"){
		qsort(&(number[0]), number.size(), sizeof(int), qsortCompare);
		printVector(number, number.size());
	} else 
	if(sortType == "stl"){
		sort(number.begin(), number.end(), stlC);
		printVector(number, number.size());
	}

	//vector<int> total = ofSort(30,200, "qsort");
	


vector<int> rando;
int length = 200;
for(int h = 0; h < 30; h++){
	
	for(int i = 0; i < length; i++){
		rando.push_back((rand()%100000)+1);
	}

	sort(rando.begin(), rando.end(), stlC);
	//qsort(&(rando[0]), rando.size(), sizeof(int), qsortCompare);
 		
	comparisonz.push_back(comparisons);
	comparisons = 0;
	rando.clear();
	length += 200;
	}

printVector(comparisonz, comparisonz.size());















}



	




