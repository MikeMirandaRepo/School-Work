


   
#include <cstdlib>
#include "Array.h"
#include "Array.cpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Array <double> Array1;
    Array <double> Array2(10);
    Array <double> Array3(Array2);
    Array <double> Array4(10, -10);

    cout << "Test of printInfo for Array1" << endl;
    cout << &Array1 << endl;
    Array1.printMyInfo();
    
    cout << Array1 << endl;
    cin >> Array1;
    cout << Array1 << endl;
    cout << ++Array1 << endl;
    cout << Array1 << endl;

    cout << endl << "Test of print" << endl;
    Array1.print();
    Array2.print();
    Array3.print();
    Array4.print();
/*
    cout << endl << "Test of overloaded ==" << endl;
    if (Array2 == Array3) {
        cout << "Array2 and Array3 are equal" << endl;
    } else {
        cout << "Array2 and Array3 are NOT equal" << endl;
    }

    cout << endl << "Test of overloaded !=" << endl;
    if (Array2 != Array3) {
        cout << "Array2 and Array3 are Not equal" << endl;
    } else {
        cout << "Array2 and Array3 are equal" << endl;
    }

    cout << endl << "Test of overloaded [] operator on the lhs" << endl;
    cout << "Array1[2] = " << Array1[2] << endl;

    cout << endl << "Test of overloaded = operator" << endl;
    Array4 = Array1;
    Array1.print();
    Array4.print();

    cout << endl << "Test of the operator+" << endl;
    cout << "Array2 and Array 3 before +" << endl;
    cout << Array2;
    Array2.print();
    Array3.print();
    cout << "The sum of the two: " << endl;
    Array1 = Array2 + Array3 + Array4;
    cout << "Array2 and Array 3 after +" << endl;
    Array2.print();
    Array3.print();
*/
    return 0;
}

