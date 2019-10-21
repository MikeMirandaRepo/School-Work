  /* 
 * File:   main.cpp
 * 
 *
 * Created on September 22, 2017, 1:20 PM
 */

#include <cstdlib>
#include "Array.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Array Array1;
    Array Array2(10);
    Array copyOfArray2(Array2);
    Array Array3(10, -10);

    cout << "Test of printInfo for Array1" << endl;
    Array1.printMyInfo();

    cout << endl << "Test of print" << endl;
    Array1.print();
    Array2.print();
    copyOfArray2.print();
    Array3.print();

    cout << endl << "Test of overloaded ==" << endl;
    if (Array2 == copyOfArray2) {
        cout << "Array2 and copyOfArray2 are equal" << endl;
    } else {
        cout << "Array2 and copyOfArray2 are NOT equal" << endl;
    }

    cout << endl << "Test of overloaded !=" << endl;
    if (Array2 != copyOfArray2) {
        cout << "Array2 and copyOfArray2 are Not equal" << endl;
    } else {
        cout << "Array2 and copyOfArray2 are equal" << endl;
    }

    cout << endl << "Test of overloaded [] operator on the lhs" << endl;
    cout << "Array1[2] = " << Array1[2] << endl;

    cout << endl << "Test of overloaded = operator" << endl;
    Array3 = Array1;
    Array2.print();
    Array3.print();

    cout << endl << "Test of the operator+" << endl;
    cout << "Array2 and Array 3 before +" << endl;
    Array2.print();
    Array3.print();
    cout << "The sum of the two: " << endl;
    Array Array4(Array3 + Array2);
    Array4.print();
    cout << "Array2 and Array 3 after +" << endl;
    Array2.print();
    Array3.print();

    return 0;
}
