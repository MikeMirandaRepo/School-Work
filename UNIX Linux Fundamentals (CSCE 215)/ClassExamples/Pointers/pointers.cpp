
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: homayoun
 *
 * Created on September 18, 2017, 12:11 PM
 */

#include <cstdlib>
#include <iostream>
#include "./Array.h"

using namespace std;



/*
 * 
 */
int main(int argc, char** argv) {

	int size,num;
	cout << "Please enter the size of the array" << endl;
	cin >> size;
	double myArray[size];
    	cout << "Please enter the values of the array" << endl;
	init(myArray, size);
	print(myArray, size);	

	cout << "Add 5 after this index" << endl;
	cin >> num;
	insert(num, 5, &myArray, &size);

	print(myArray, size);

	return 0;
}
