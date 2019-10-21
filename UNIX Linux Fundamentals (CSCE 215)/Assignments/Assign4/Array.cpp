



/* 
 * File:   Array.cpp
 * Author: Michael Miranda
 * 
 * Created on October 02, 2017, 1:22 PM
 */

#include "Array.h"

Array::Array() : size(10) {//creates an array of size 10 with 0-9
    //    size = 10;
    data = new double [size];
    for (int i = 0; i < size; i++) {
        data[i] = i;
    }
}

Array::Array(int _size) : size(_size) {//creates an array of input size with 0-size-1
    //size = _size;
    data = new double [size];
    for (int i = 0; i < size; i++) {
        data[i] = i;
    }
}

Array::Array(int _size, double value) : size(_size) {//creates an array of size and all variables of value
    //    size = _size;
    data = new double [size];
    for (int i = 0; i < size; i++) {
        data[i] = value;
    }
}

Array::Array(const Array& orig) {//creates an array of a copy of another array
    setSize(orig.getSize());
    data = new double[getSize()];
    for (int i = 0; i < getSize(); i++) {
        setData(i, orig.getData(i));
    }
}

Array::~Array() { //deletes the values of an array
    delete [] data;
}



int Array::getSize() const {// returns the size of the array
    return size;
}

void Array::setSize(int value) {//sets the size of the array to value
    if (value > 0) {
        size = value;
    }
}

void Array::setData(int index, double value) {// sets the value of index to value
    if ((index >= 0) && (index < size)) {
        data[index] = value;
    } else {
        cout << "NO!" << endl;
    }
}

double Array::getData(int index) const {//returns value at index
    if ((index >= 0) && (index < size)) {
        return data[index];
    } else {
        return data[size - 1];
    }
}

double Array::operator[](int index) const {//replaces getData() with [] operator
    if ((index >= 0) && (index < size)) {
        return data[index];
    } else {
        return data[size - 1];
    }
}

void Array::print() const {//prints array 
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

void Array::expand() {//increases the array of size+1
    double *localArray = new double[size + 1];

    for (int i = 0; i < size; i++) {
        localArray[i] = data[i];
    }
    localArray[size] = size;

    delete [] data;
    setSize(size + 1);
    data = localArray;
    //    myArray = new int[size];
    //    
    //    //Is this a deep-copy or a shallow-copy? 
    //    //Can you replace one with the other?
    //    //What are the advantages and disadvantages? 
    //    for(int i=0; i < size; i++) {
    //        myArray[i] = localArray[i];
    //    }
    //    delete [] localArray;
}

bool Array::equal(const Array& rhs) const {//returns bool value if the arrays are equal 
    bool result(true);

    if (getSize() != rhs.getSize()) {
        result = false;
    } else {
        for (int i = 0; i < getSize(); i++) {
            if (getData(i) != rhs.getData(i)) {
                result = false;
            }
        }
    }
    return result;
}
