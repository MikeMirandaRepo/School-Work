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

    int startTime, stopTime;
	double total(0), avg(0);

	startTime=clock();
	
	linkList<int> intArray1(1000000, 0);
	intArray1.init();
	
	stopTime=clock();
	//total += ((stopTime - startTime)/double(CLOCKS_PER_SEC))*1000;
	//cout << "time: " << (stopTime - startTime)/double(CLOCKS_PER_SEC)*1000 << endl;	

//	*******************Insertion using linkList************************
	int tenPercent = intArray1.getSize()*0.1; 
	int random(0); 
	int size = intArray1.getSize();
//	cout << "Inserting " << tenPercent << " items." << endl;
	

	srand(time(0)); 
	startTime=clock();

	for(int i = 0; i < tenPercent; i++)
	{
		random = rand() % size;
		//cout << random << endl;
	//	intArray1.insert(random, 0);
	}

	stopTime=clock();
	//cout << " insert time: " << (stopTime - startTime)/double(CLOCKS_PER_SEC)*1000 << endl;


	/*******************Reads using linkList************************/
	cout << "Reading " << tenPercent << " items." << endl;

	startTime=clock();
	
	int num(0);
	for(int i = 0; i < tenPercent; i++)
	{
		random = rand() % size;
		//cout << random << endl;
//		num = intArray1[random];
	}
	
	stopTime=clock();
//	cout << "time: " << (stopTime - startTime)/double(CLOCKS_PER_SEC)*1000 << endl;
	
	

	/*******************Searching using linkList************************/
	cout << "Searching " << tenPercent << " items." << endl;
	startTime=clock();
	
	int index(0);
	for(int i = 0; i < tenPercent; i++)
	{
		random = rand() % size;
		//cout << random << endl;
		index = intArray1.find(random);
	}
	
	stopTime=clock();
	cout << "time: " << (stopTime - startTime)/double(CLOCKS_PER_SEC)*1000 << endl;
	


//*/

return 0;
}	

