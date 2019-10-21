/*
File: Assignment0_Miranda.cpp
Author: Michael Miranda
Function: print some information
Input: none
Output: Hello World
Created August 28, 2017
*/ 

#include <cstdlib>
#include <iostream>

using namespace std;
int add(int number1, number2); 

int main(int argc, char** argv)
{
	int Number1(0), Number2(0), result(0);
	cout << "Enter two numbers." << endl;
	cin >> Number1 >> Number2;
	result = add(Number1, Number2);
	cout << result;  << endl;

	return 0;


}

int add(int Num1, Num2)
{
	int something;
	something = Num1 + Num2;
	return something;
}
