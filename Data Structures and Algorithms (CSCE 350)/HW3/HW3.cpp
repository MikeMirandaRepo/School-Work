/*
File: HW2.cpp
Author: Michael Miranda
*/ 
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <cmath>


using namespace std;
string num1, num2, sum;
vector<int> vecNum1, vecNum2, vecBrute, mult, finalV, vecKara, vecAdd, vecSubtr;

vector<int> initVec(vector<int> newVec, int limit){	//fills a vector with a size of limit
	vector<int> returned;

	for(int i = 0; i < limit; i++)
		returned.push_back(0);
		
	return returned;
}

vector<int> trimmed(vector<int> orig){			//takes a vector and returns one without the leading 0's
	vector<int> smaller;
	int start = 0;
	while(orig[start] == 0){
		start++;
	}
	for(int i = start; i < orig.size(); i++)
		smaller.push_back(orig[i]);

	if(smaller.size() == 0)
		smaller.push_back(0);

	return smaller;
}
vector<int> pad(vector<int> smaller, int needed){	//adds needed 0's to the front of the vector 
	for(int i = 0; i < needed; i++)
		smaller.insert(smaller.begin(), 0);

	return smaller;
	
}

void printVector(vector<int> a){			//prints out a vector
	//a = trimmed(a);
	for(int i = 0; i < a.size(); i++)
		cout << a[i];
	
	cout << endl;

}

vector<int> convert(string A){				//converts a string to a vector
	vector<int> vect;
	for(int i = 0; i < A.size(); i++)
		vect.push_back(A[i] - '0');
	
	//vect = trimmed(vect);
	return vect;
}

vector<int> addVec(vector<int> v1, vector<int> v2){		// adds two vectors together and returns the addition
	vector<int> total;
	int carry = 0, added = 0;
	if(v1.size() != v2.size()){
		if(v1.size() > v2.size())
			v2 = pad(v2, v1.size() - v2.size());

		else
			v1 = pad(v1, v2.size() - v1.size());
	}

	int smallerSize = v1.size();    
	for(int i = smallerSize-1; i >= 0; i--)
	{
		added = v1[i]+v2[i] + carry;
		carry = added/10;
		total.insert(total.begin(), added%10);
	}
	
	if(carry > 0)                                           
		total.insert(total.begin(), carry);

	return total;
}


vector<int> subVec(vector<int> v1, vector<int> v2){		//subtracts two vectors and returns the subtraction
	vector<int> total;
	int subtr = 0, j = 1, size = v1.size();
	for(int i = size-1; i >=0; i--){
		if(v1[i] >= v2[i]){
			subtr = v1[i] - v2[i];
		} else {
			while(v1[i-j] == 0){
				v1[i-j] += 9;
				j++;
			}
			v1[i-j] -= 1;
			subtr = (v1[i] + 10) - v2[i];
		}
		total.insert(total.begin(), subtr);
	}

	if(total.size() == 0)
		total.insert(total.begin(), 0);

	return total;
}

vector<int> powe(int times){					//creates a vector of 10^times 
	vector<int> larger;
	for(int i = 0; i < times; i++){
		larger.insert(larger.begin(), 0);
	}
	larger.insert(larger.begin(), 1);

	return larger;
}


vector<int> bruteMult(vector<int> num1, vector<int> num2){	//multiplies two vectors and returns the result
	vector<int> result;
	int carry;
	if(num1.size() != num2.size()) {
		if(num1.size() > num2.size())
			num2 = pad(num2, num1.size() - num2.size());
		else
			num1 = pad(num1, num2.size() - num1.size());
	} 

	result = initVec(result, max(num1.size(), num2.size())*2);
	
	for(int i = num2.size()-1; i >= 0; i--){
		carry = 0;
		for(int j = num1.size()-1; j >= 0; j--){
			result[i+j+1] += carry + num1[j]*num2[i];
			carry = result[i+j+1]/10;
			result[i+j+1] = result[i+j+1]%10;
		}
		result[i] += carry;
	}
	//result = trimmed(result);
	return result;
	
} 


vector<int> Karatsuba(vector<int> num1, vector<int> num2){ 	//multiplies two vectors using Karatsuba !!!DOES NOT WORK!!!
	
	int n, half;
	vector<int> aL, aR, bL, bR, x1, x2, x3, temp1, temp2;
	
	if(num1.size() == 1 || num2.size() == 1){
		mult = bruteMult(num1, num2);
		return mult;
	} else { 
	
	n = max(num1.size(), num2.size());
	if(n%2 == 1)
		half = (n)/2;
	else 
		half = n/2;
	
	for(int i = 0; i < half; i++)
		aL.push_back(num1[i]);

	for(int i = half; i < num1.size(); i++)
		aR.push_back(num1[i]);

	for(int i = 0; i < half; i++)
		bL.push_back(num2[i]);

	for(int i = half; i < num2.size(); i++)
		bR.push_back(num2[i]);

	x1 = Karatsuba(aR, bR);
/*	printVector(aR);
	cout  << " * " << endl;
	printVector(bR);
	cout << " = " << endl << "X1: ";
	//x1 = bruteMult(aR,bR);
*/	x3 = Karatsuba(aL, bL);
	//printVector(x1);
/*	
	printVector(aL);
	cout<< " * " << endl;
	printVector(bL);
	cout << " = " << endl << "X3: ";
	//x3 = bruteMult(aL,bL);
	//printVector(x3);

*/	x2 = Karatsuba(addVec(aL,aR),addVec(bL,bR));
/*	printVector(x2);
	//x2 = bruteMult(addVec(aL, aR), addVec(bL, bR));
	printVector(addVec(aL, aR));
	cout << " * " << endl;
	printVector(addVec(bL, bR));
	cout << " = "  << endl << "X2: ";
	printVector(x2);

*/	/*
	(x1 +((x3 * power(half*2)) + ((x2 - x3 - x1) * power(half))))
	*/
	vector<int> A = subVec(x2, x3);
	//cout << "A = x2-x3 " ;
	A = trimmed(A);
	//printVector(A);
	vector<int> B = subVec(A, x1);
	//cout << "B = A - x1 ";
	B = trimmed(B);
	//printVector(B);
	vector<int> C = bruteMult(B, powe(half));
	//cout << "C = B * 10^" << half << " ";
	C = trimmed(C);
	//printVector(C);
	vector<int> D = bruteMult(x3, powe(half*2));
	//cout << "D = x3 * 10^" << half*2 << " ";
	D = trimmed(D);
	//printVector(D);
	vector<int> E = addVec(C, D);
	//cout << "E = C + D ";	
	E = trimmed(E);
	//printVector(E); 
	//cout << "F = E + x1 ";
	//cout << endl;
	vector<int> F = addVec(E, x1); //!!Final!!
	F = trimmed(F);
	return F;
	}	 

}

int main(int argc, char *argv[])
{
	cin >> num1 >> num2;

	vecNum1 = convert(num1);	
	vecNum2 = convert(num2);
	

	if(vecNum1.size() > vecNum2.size()) {
		while(vecNum2.size() < vecNum1.size()){
			vecNum2.insert(vecNum2.begin(), 0);
		}
	}
	else if(vecNum2.size() > vecNum1.size()){
		while(vecNum1.size() < vecNum2.size()){
			vecNum1.insert(vecNum1.begin(), 0);
		}
	}
	
	vecBrute = bruteMult(vecNum1, vecNum2);
	vecBrute = trimmed(vecBrute);
	cout << "the resulting brute Force Vector: ";
	printVector(vecBrute);

	//vecSubtr = subVec(vecNum1, vecNum2);
	//cout << "The resulting subtraction of the Vectors: " ;
	//vecSubtr = trimmed(vecSubtr);
	//printVector(vecSubtr);
/*
	vecAdd = addVec(vecNum1, vecNum2);
	cout << "The resulting addition of the Vector: ";
	vecAdd = trimmed(vecAdd);
	printVector(vecAdd);
*/
	vecKara = Karatsuba(vecNum1, vecNum2);
	cout << endl << "The resulting Karatsuba Vector: (DOES NOT WORK)" << endl;
	printVector(vecKara);
	
}



	




