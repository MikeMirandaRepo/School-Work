/*
File: HW1.cpp
Author: Michael Miranda
*/ 

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int one;
	int two;
	int three;
	int four;
	int total;
	while(total != 0){
		cout << "give 4 positive numbers" << endl;
		cin >> one >> two >> three >> four;
		if( one >= 0 && two >= 0 && three >= 0 && four >= 0) {
			 total = one + two + three + four;
			cout << "The total was " << total << endl;
		} else {
			cout << "These inputs were not acceptable please relaunch" << endl; 
		}		

	}

}
	


