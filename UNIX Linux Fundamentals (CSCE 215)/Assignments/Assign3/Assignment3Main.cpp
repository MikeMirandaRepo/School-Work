
#include <cstdlib>
#include <iostream>
#include "./Array.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int size(0);

    cout << "Enter a size" << endl;
    cin >> size;
    double *myArray;
    myArray = new double[size];
    init(myArray, size);

    print(myArray, size);

//   insert(0, 5, myArray, size); 
   
//   print(myArray, size);

   remove(2, myArray, size);

   print(myArray, size);
/*
   cout << "Found index 1" << endl;	
   get(1, myArray, size);

   cout << "find the first index that has number 2" << endl;
   find(2, myArray, size); 
//	cout << num << endl;

   clear(myArray,size);
   print(myArray,size);

*/
delete [] myArray;
return 0;

}
