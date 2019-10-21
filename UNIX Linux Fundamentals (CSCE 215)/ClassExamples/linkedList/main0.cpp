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
	cout<< endl << "LinkList creation" << endl;

    	int startTime, stopTime;

	startTime=clock();
	
	linkList<int> intArray1K(1000, 0);
	intArray1K.init();
	
	stopTime=clock();
        cout << "1K time: " << (stopTime - startTime)/double(CLOCKS_PER_SEC)*1000 << endl;

	
        startTime=clock();

        linkList<int> intArray10K(10000, 0);
        intArray10K.init();

        stopTime=clock();
        cout << "10K time: " << (stopTime - startTime)/double(CLOCKS_PER_SEC)*1000 << endl;
	
	srand(time(0));
        startTime=clock();

         linkList<int> intArray100K(100000, 0);
        intArray100K.init();

	stopTime=clock();
        cout << "100K time: " << (stopTime - startTime)/double(CLOCKS_PER_SEC)*1000 << endl;

	srand(time(0));
        startTime=clock();

        linkList<int> intArray1M(1000000, 0);
        intArray1M.init();

	stopTime=clock();
        cout << "1M time: " << (stopTime - startTime)/double(CLOCKS_PER_SEC)*1000 << endl;      


/*

//	intArray1.printList();
//	*******************Insertion using linkList************************
	int tenPercent1K = intArray1K.getSize()*0.1; 
	int random(0); 
	int size1K = intArray1K.getSize();
	cout << "1K Inserting " << tenPercent1K << " items." << endl;
	
	srand(time(0)); 
	time(&begin);

	
	for(int i = 0; i < tenPercent1K; i++)
	{
		random = rand() % size1K;
		//cout << random << endl;
		intArray1K.insert(random, 0);
	}
	
	time(&end);
	
	sec_elapsed = difftime(end, begin);
	cout.precision(10);
	cout << "1K Time elapsed: " << sec_elapsed << endl;



	int tenPercent100K = intArray100K.getSize()*0.1;
        int size100K = intArray100K.getSize();
        cout << "100K Inserting " << tenPercent100K << " items." << endl;

        srand(time(0));
        time(&begin);


        for(int i = 0; i < tenPercent100K; i++)
        {
                random = rand() % size100K;
                //cout << random << endl;
                intArray100K.insert(random, 0);
        }

        time(&end);

        sec_elapsed = difftime(end, begin);
        cout.precision(10);
        cout << "100K Time elapsed: " << sec_elapsed << endl;

	int tenPercent1M = intArray1M.getSize()*0.1;
        int size1M = intArray1M.getSize();
        cout << "1M Inserting " << tenPercent1M << " items." << endl;

        srand(time(0));
        time(&begin);


        for(int i = 0; i < tenPercent1M; i++)
        {
                random = rand() % size1M;
                //cout << random << endl;
 //               intArray1M.insert(random, 0);
        }

        time(&end);

        sec_elapsed = difftime(end, begin);
        cout.precision(10);
        cout << "Time elapsed: " << sec_elapsed << endl<< endl;
        

//	*******************Reading using linkList************************
	cout << "1K Reading " << tenPercent1K << " items." << endl;
	time(&begin);
	
	int num(0);
	for(int i = 0; i < tenPercent1K; i++)
	{
		random = rand() % size1K;
		//cout << random << endl;
		num = intArray1K[random];
	}
	
	time(&end);
	sec_elapsed = difftime(end, begin);
	cout.precision(10);
	cout << "1KTime elapsed: " << sec_elapsed << endl;


	cout << "100K Reading " << tenPercent100K << " items." << endl;
        time(&begin);

       
        for(int i = 0; i < tenPercent100K; i++)
        {
                random = rand() % size100K;
                //cout << random << endl;
                num = intArray100K[random];
        }

        time(&end);
        sec_elapsed = difftime(end, begin);
        cout.precision(10);
        cout << "100KTime elapsed: " << sec_elapsed << endl;




	cout << "1M Reading " << tenPercent1M << " items." << endl;
        time(&begin);

        
        for(int i = 0; i < tenPercent1M; i++)
        {
                random = rand() % size1M;
                //cout << random << endl;
   //             num = intArray1M[random];
        }

        time(&end);
        sec_elapsed = difftime(end, begin);
        cout.precision(10);
        cout << "1MTime elapsed: " << sec_elapsed << endl << endl;



	
//	******************Searching using linkList************************
	cout << "1K Searching " << tenPercent1K << " items." << endl;
	time(&begin);
	
	int index(0);
	for(int i = 0; i < tenPercent1K; i++)
	{
		random = rand() % size1K;
		//cout << random << endl;
		index = intArray1K.find(random);
	}
	
	time(&end);
	sec_elapsed = difftime(end, begin);
	cout.precision(10);
	cout << "1K Time elapsed: " << sec_elapsed << endl;



	   cout << "100K Searching " << tenPercent100K << " items." << endl;
        time(&begin);

   
        for(int i = 0; i < tenPercent100K; i++)
        {
                random = rand() % size100K;
                //cout << random << endl;
                index = intArray100K.find(random);
        }

        time(&end);
        sec_elapsed = difftime(end, begin);
        cout.precision(10);
        cout << "100K Time elapsed: " << sec_elapsed << endl;

	
	cout << "1M Searching " << tenPercent1M << " items." << endl;
        time(&begin);

   
        for(int i = 0; i < tenPercent1M; i++)
        {
                random = rand() % size1M;
                //cout << random << endl;
   //             index = intArray1M.find(random);
        }

        time(&end);
        sec_elapsed = difftime(end, begin);
        cout.precision(10);
        cout << "1M Time elapsed: " << sec_elapsed << endl;

*/

  	  return 0;
}


