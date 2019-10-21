

 #include <cstdlib>
#include <iostream>
#include "Array.h"
#include "Array.cpp"

using namespace std;



int main (int argc, char **argv)
{ 
	int *temp1 = new int[5];
	for(int i = 0; i < 5; i++) 
	{
		temp1[i] = i;
	}
	Array<int> intArray1, intArray2(5,1), intArray3(temp1,5);
	
	delete [] temp1;
	
	cout << "intArray1: " << endl;
	intArray1.print(); 
	cout << intArray1 << endl;
	
	cout << "intArray2: " << endl;
	intArray2.print(); 
	cout << intArray2;
	
	cout << "intArray3: " << endl;
	intArray3.print(); 
	cout << intArray3;
	
	cout << "Adding intArray2 and intArray3: " << endl;
	Array<int> intArray4;
	
	intArray4 = intArray2 + intArray3;
	
	cout << "intArray4: " << endl;
	intArray4.print(); 
	cout << intArray4;
	
    return 0;
}


