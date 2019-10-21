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

double add(double &, double &);
double subtract(double, double);
double multiply(double, double); 
double divide(double, double);

int main(int argc, char** argv)
{
	bool j(true);

	while(j)
    {
	 
	char sign(' '), answer(' ');
        double Num1(0.0), Num2(0.0), Num3(0.0);
	cout << "Please enter two numbers and a sign" << endl;
	cin >> Num1 >> sign >> Num2;
	cout << "The numbers were " << Num1 << " " << sign  << " " << Num2 << endl;

	if(sign == '+')
	{	
		Num3 = add(Num1,Num2);
		cout << "The addition of these numbers would be " << Num3 << endl;
	}
	else if(sign == '-')
	{		
		Num3 = subtract(Num1,Num2);
		cout << "The subtraction of these two numbers would be " << Num3 << endl;
	}  
	else if(sign == '*')
	{
		Num3 = multiply(Num1,Num2);
		cout << "The multiplication of these two numbers would be " << Num3 << endl;
	}  
	else if(sign == '/')
	{
		Num3 = divide(Num1,Num2);
		cout << "The Division of these two numbers would be " << Num3 << endl;
	}
	else
	{
		cout << "This was either an incorrect sign or an error has occurred" << endl;
	}
	cout << "Would you like to do another calculation Y/N?" << endl; 
	cin >> answer;
	if(answer == 'N')
		j = false;

   }
	
	return 0;
}

double add(double &Num1,double &Num2)
{
 double Num3 = Num1+ Num2;
Num1= 100; // allows the Num1 in main to be changed and both point to the same memory location rather than different ones 
return Num3;
}

double subtract(double Num1, double Num2)
{
 double Num3 = Num1 - Num2; 
return Num3;
}

double multiply(double Num1, double Num2)
{
double Num3 = Num1 * Num2;
return Num3;
}

double divide(double Num1, double Num2)
{
double Num3 = Num1/Num2;
return Num3;

}







