/*
File: HW4.cpp
Author: Michael Miranda
*/ 
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

string alph = "abcdefghijklmnopqrstuvwxyz";

string decode(string number){ // Couldnt find a better way to convert. It is very inefficient
	string letter;
	int numberz = 0;
	
if(number.length() == 2){
	if(number[0] == '1')
		numberz += 10;

	else if(number[0] == '2')
		numberz += 20;

	if(number[1] == '1')
		numberz += 1;
	else if(number[1] == '2')
		numberz += 2;
	else if(number[1] == '3')
		numberz += 3;
	else if(number[1] == '4')
		numberz += 5;
	else if(number[1] == '5')
		numberz += 5;
	else if(number[1] == '6')
		numberz += 6;
	else 
		cout << "Thats not right! " << number[0] << endl;

	}
else if(number.length() == 1){
	if(number[0] == '0')
		{}
	else if(number[0] == '1')
		numberz += 1;
	else if(number[0] == '2')
		numberz += 2;
	else if(number[0] == '3')
		numberz += 3;
	else if(number[0] == '4')
		numberz += 5;
	else if(number[0] == '5')
		numberz += 5;
	else if(number[0] == '6')
		numberz += 6;
	else if(number[0] == '7')
		numberz += 7;
	else if(number[0] == '8')
		numberz += 8;
	else if(number[0] == '9')
		numberz += 9;


	}
	letter = alph[numberz-1];
	return letter;

}



void printDecode(string coded, string decoded){// didnt finish :( other class exams more important
	string code;
	if(coded.length() >= 0){
		if(coded[0] == '1' || (coded[0] == '2' && coded[1] < '6')) {
		//	decode += coded[0] + coded[1];
		//	code = decode(decode);
		//	printDecode(coded.str(2,coded.length()-1), decoded);
		}
	}
		

}


int countCodes(string numberz) 
{ 
    int size = numberz.length();
    int count[size+1]; // A table to store results of subproblems 
    count[0] = 1; 
    count[1] = 1; 
  
    for (int i = 2; i <= size; i++) 
    {
        count[i] = 0; 
        count[i] = count[i-1]; 
  
        if (numberz[i-2] == '1' || (numberz[i-2] == '2' && numberz[i-1] < '6') ) 
            count[i] += count[i-2]; 
    } 
    return count[size]; 
} 
int main(int argc, char *argv[])
{
	string number;
	cin >> number;
	int decodeNum = countCodes(number);
	cout << decodeNum << endl;
}

/*
recurrance: The number of variations of a string of numbers to letters w code

V[i] = 
	a) V[i] += V[i-2]  if(i < 26) 
	
Basically with this dynamic algorithm we want to continually build off of the previous nuber of 
permutations and exponentially find more variations. If the two digits for a character then add the 
the result to the total count.

The base case would be and empty string " ", resulting in a single variation.
The other base case would be when all numbers in two digits are larger than 26, as 
there could only be one permutation of all the numbers eg 34567
	

*/

