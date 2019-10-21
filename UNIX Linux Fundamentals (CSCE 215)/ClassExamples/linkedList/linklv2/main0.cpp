#include <cstdio>
#include <iostream>
#include "linkList.h"
#include "linkList.cpp"
#include <ctime>
#include <stdlib.h>

using namespace std;



int main (int argc, char **argv)
{ 
	/*******************Creation using linkList*************************/
	//1K size
	time_t begin,end;
	time(&begin);
	
	linkList<int> intArray1(1000000, 0);
	intArray1.init();
	
	time(&end);
	
	double sec_elapsed = difftime(end, begin);
	cout.precision(10);
	cout << "Time elapsed: " << sec_elapsed << endl;
	
	/*******************Insertion using linkList************************/
	int tenPercent = intArray1.getSize()*0.1; 
	int random(0); 
	int size = intArray1.getSize();
	/*cout << "Inserting " << tenPercent << " items." << endl;
	
	srand(time(0)); 
	time(&begin);


	for(int i = 0; i < tenPercent; i++)
	{
		random = rand() % size;
		//cout << random << endl;
		intArray1.insert(random, 0);
	}
	
	time(&end);
	
	sec_elapsed = difftime(end, begin);
	cout.precision(10);
	cout << "Time elapsed: " << sec_elapsed << endl;*/
	
	/*******************Reads using linkList************************/
	/*cout << "Reading " << tenPercent << " items." << endl;
	time(&begin);
	
	int num(0);
	for(int i = 0; i < tenPercent; i++)
	{
		random = rand() % size;
		//cout << random << endl;
		num = intArray1[random];
	}
	
	time(&end);
	sec_elapsed = difftime(end, begin);
	cout.precision(10);
	cout << "Time elapsed: " << sec_elapsed << endl;*/
	
	/*******************Searching using linkList************************/
	cout << "Searching " << tenPercent << " items." << endl;
	time(&begin);
	
	int index(0);
	for(int i = 0; i < tenPercent; i++)
	{
		random = rand() % size;
		//cout << random << endl;
		index = intArray1.find(random);
	}
	
	time(&end);
	sec_elapsed = difftime(end, begin);
	cout.precision(10);
	cout << "Time elapsed: " << sec_elapsed << endl;
    return 0;
}


