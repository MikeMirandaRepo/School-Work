
#include <cstdlib>
#include <iostream>
#include "Array.h"

using namespace std;



int main (int argc, char **argv)
{ 
	cout << "**************Testing Default Constructor*****************" << endl;   
	Array A1;
	cout << "10 0-9 A1: ";
	A1.print();

	cout << "**************Testing Alt Constructor 1*****************" << endl;	
	Array A2(5,0);
	cout << "5 0's A2: "; 
	A2.print();
		
	Array temp(5);
	cout << "**************Testing Alt Constructor 2*****************" << endl;	
	Array A3(A1); 
	cout << "A3 is the same as A1: "; 
	A3.print();
/*	
	cout << "**************Testing get*****************" << endl;
	cout << "The element at index 0 is : " << A3.get(0) << endl;
	cout << "The element at index 10 is : " << A3.get(10) << endl;

	cout << "**************Testing insert*****************" << endl; 
	A3.insert(5,7.5);
	cout << "A3 after insert: " << endl;
	A3.print();
	
	cout << "**************Testing remove*****************" << endl; 
	A3.remove(1);
	cout << "A3 after remove: " << endl;
	A3.print();
	
	cout << "**************Testing find*****************" << endl; 
	cout << "7.5 was found at index " << A3.find(7.5) << endl;
	
	cout << "**************Testing equals*****************" << endl; 
	bool ans = A2.equals(A3);
	if(ans)
	{
		cout << "A2 equals A3." << endl;
	}
	else
	{
		cout << "A2 does not equal A3." << endl;
	}
	
	ans = A2.equals(A2); 
	if(ans)
	{
		cout << "A2 equals A2." << endl;
	}
	else
	{
		cout << "A2 does not equal A2." << endl;
	}
	
	cout << "**************Testing clear*****************" << endl; 
	A3.clear();
	cout << "A3 after clear: " << endl;
	A3.print();
	
	A2.clear();
	cout << "A2 after clear: " << endl;
	A2.print();
	*/	
//	delete [] temp;
	
    return 0;
}


