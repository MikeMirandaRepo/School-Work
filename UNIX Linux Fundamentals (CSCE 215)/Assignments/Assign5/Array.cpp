/* 
 * Michael Miranda
 * Array.cpp
 * Created on October 18, 2017
 */


#include "Array.h"

Array::Array() : size(10) {//default constructor with size of 10
    //    size = 10;
    data = new double [size];
    for (int i = 0; i < size; i++) {
        data[i] = i;
    }
   
}

Array::Array(int _size) : size(_size) {//constructor with an input size
    size = _size;
    data = new double [size];
    for (int i = 0; i < size; i++) {
        data[i] = i;
    }
    
}

Array::Array(int _size, double value) : size(_size) {//a constructor with an input size and all elements value
    //    size = _size;
    data = new double [size];
    for (int i = 0; i < size; i++) {
        data[i] = value;
    }
    
}

Array::Array(double *orig, int _size) : size(_size) {//a constructor that converts an array of doubles to an array with given size
	setSize(size);
	data = new double[size];
	for(int i = 0; i < size; i++)
		setData(i, orig[i]);

	
}

Array::Array(const Array& orig) {//a copy constructor with an input of another Array
    setSize(orig.getSize());
    data = new double [getSize()];
    for (int i = 0; i < getSize(); i++) {
        setData(i, orig.getData(i));
    }

	
}

Array::~Array() {//a delete constructor
    delete [] data;
}

void Array::init(){//initializes an Array with a size of 10 and all 0's
size = 10;
data = new double[size];
for(int i = 0; i < size; i++)
	data[i] = 0;


}

int Array::getSize() const {//returns the size of requested Array
    return size;
}

void Array::setSize(int value) {//sets the size of requested Array to inputed int 
    if (value > 0) {
        size = value;
    }
}

void Array::setData(int index, double value) {//changes a valriable at index to value in an Array
    if ((index >= 0) && (index < size)) {
        data[index] = value;
    } else {
        cout << "NO!" << endl;
    }
}

double Array::getData(int index) const {//returns a value at index of as Array
    if ((index >= 0) && (index < size)) {
        return data[index];
    } else {
        return data[size - 1];
    }
}

double Array::operator[](int index) const {//overrides the [] operator to return the value at [index]
    if ((index >= 0) && (index < size)) {
        return data[index];
    } else {
        return data[size - 1];
    }
}

int Array::operator[](int index){//overrides the [] operator to assign the value at the index with a value

	return data[index];	
}

void Array::print() const {// prints out all values in Array
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

bool Array::equal(const Array& rhs) const {//returns true if size and values in array are equal, false otherwise 
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

bool Array::operator==(const Array& rhs) const {// same as equal function above but overrides the == operator
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

bool Array::operator!=(const Array& rhs) const {// overrides the != operator to check two Arrays for size and values and returns true if equal 
    bool result(false);

    if (getSize() != rhs.getSize()) {
        result = true;
    } else {

        for (int i = 0; i < getSize(); i++) {
            if (data[i] != rhs[i]) {
                result = true;
            }
        }
    }
    return result;
}

const Array Array::operator=(const Array& rhs) {// overrides the = operator to assign an inputted Array to the calling Array
    setSize(rhs.getSize());
    data = new double[getSize()];
    for (int i = 0; i < getSize(); i++) {
        setData(i, rhs.getData(i));
    }
	return *this;
	
}

const Array Array::operator-(){// changes all values in Array to a negative value

	Array negative(getSize());
	
        for(int i = 0; i < getSize(); i ++)
		negative.setData(i, -getData(i));
        return negative;
}


const Array Array::operator+(const Array& rhs) const {//takes two Arrays and concatinates for 
       int totSize = getSize() + rhs.getSize();
       Array Cake(totSize);
        for (int i = 0; i < getSize(); i++) {
            Cake.setData(i,data[i]);
        }

 	for(int i = getSize(); i < totSize; i++){
	    Cake.setData(i, rhs[i-getSize()]);
	}

    return Cake;
}

const Array Array::operator++() {// overrides the pre ++ to incriment all values in Array
    for(int i=0; i < getSize(); i++) {
      data[i]++;
      cout << data[i] << "-";
    }
	cout << endl;
    return *this;
}

const Array Array::operator++(int dummy) {// updates all post ++ operator to increment all values after returning the calling Array
    Array temp(*this);
    
    for(int i=0; i < getSize(); i++) {
	data[i]++;
    }
    return temp;
}

void Array::printMyInfo() const {
    cout << "I am at: " << this << endl;
    cout << "My data is at: " << &data << endl;
    cout << "My size is at: " << &size << " with a value of : " << size << endl;
    cout << "My data points to: " << data << endl;
    cout << "The first item in data is: " << *data << endl;
}

ostream & operator<<(ostream &lhs, const Array &rhs) {// overrides the << operator 
    for (int i = 0; i < rhs.getSize(); i++) {
        lhs << rhs[i] << " ";
    }
    cout << endl;
    return lhs;
}

istream & operator>>(istream &lhs, Array &rhs) {//overides the cin >> operator 
    double temp;
    for (int i = 0; i < rhs.getSize(); i++) {
        lhs >> temp;
        rhs.setData(i, temp);
    }
    return lhs;
}
