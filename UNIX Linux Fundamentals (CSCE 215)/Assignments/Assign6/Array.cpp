/* 
 * Michael Miranda
 * Array.cpp
 * Created on October 18, 2017
 */


#include "Array.h"

template <class T>
Array<T>::Array() : size(10) {//default constructor with size of 10
    //    size = 10;
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = i;
    }
   
}

template <class T>
Array<T>::Array(int _size) : size(_size) {//constructor with an input size
    size = _size;
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = i;
    }
    
}

template <class T>
Array<T>::Array(int _size, T value) : size(_size) {//a constructor with an input size and all elements value
    //    size = _size;
    data = new T[size];
    for (int i = 0; i < size; i++) {
        data[i] = value;
    }
    
}


template <class T>
Array<T>::Array(T *orig, int _size) : size(_size) {//a constructor that converts an array of doubles to an array with given size
	setSize(size);
	data = new T[size];
	for(int i = 0; i < size; i++)
		setData(i, orig[i]);

	
}
template <class T>
Array<T>::Array(const Array& orig) {//a copy constructor with an input of another Array
    setSize(orig.getSize());
    data = new T[getSize()];
    for (int i = 0; i < getSize(); i++) {
        setData(i, orig.getData(i));
    }
}

template <class T>
Array<T>::~Array() {//a delete constructor
    delete [] data;
}


template <class T>
void Array<T>::init(){//initializes an Array with a size of 10 and all 0's
size = 10;
data = new T[size];
for(int i = 0; i < size; i++)
	data[i] = 0;

}

template <class T>
int Array<T>::getSize() const {//returns the size of requested Array
    return size;
}

template <class T>
void Array<T>::setSize(int value) {//sets the size of requested Array to inputed int 
    if (value > 0) {
        size = value;
    }
}

template <class T>
void Array<T>::setData(int index,T value) {//changes a valriable at index to value in an Array
    if ((index >= 0) && (index < size)) {
        data[index] = value;
    } else {
        cout << "Out of bounds regarding setData() at index " << index << endl;
    }
}

template <class T>
T Array<T>::getData(int index) const {//returns a value at index of as Array
    if ((index >= 0) && (index < size)) {
        return data[index];
    } else {
        return data[size - 1];
    }
}

template <class T>
T Array<T>::operator[](int index) const {//overrides the [] operator to return the value at [index]
    if ((index >= 0) && (index < size)) {
        return data[index];
    } else {
        return data[size - 1];
    }
}

template <class T>
int Array<T>::operator[](int index){//overrides the [] operator to assign the value at the index with a value

	return data[index];	
}

template <class T>
void Array<T>::print() const {// prints out all values in Array
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

template <class T>
bool Array<T>::equal(const Array& rhs) const {//returns true if size and values in array are equal, false otherwise 
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

template <class T>
bool Array<T>::operator==(const Array& rhs) const {// same as equal function above but overrides the == operator
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

template <class T>
bool Array<T>::operator!=(const Array& rhs) const {// overrides the != operator to check two Arrays for size and values and returns true if equal 
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

template <class T>
const Array<T> Array<T>::operator=(const Array& rhs) {// overrides the = operator to assign an inputted Array to the calling Array
    setSize(rhs.getSize());
    data = new T[getSize()];
    for (int i = 0; i < getSize(); i++) {
        setData(i, rhs.getData(i));
    }
	return *this;
	
}

template <class T>
const Array<T> Array<T>::operator-(){// changes all values in Array to a negative value

	Array negative(getSize());
	
        for(int i = 0; i < getSize(); i ++)
		negative.setData(i, -getData(i));
    
    return negative;
}

template <class T>
const Array<T> Array<T>::operator+(const Array& rhs) const {//takes two Arrays and concatinates for 
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

template <class T>
const Array<T> Array<T>::operator++() {// overrides the pre ++ to incriment all values in Array
    for(int i=0; i < getSize(); i++) {
      data[i]++;
    }
	cout << endl;
    return *this;
}

template <class T>
const Array<T> Array<T>::operator++(int dummy) {// updates all post ++ operator to increment all values after returning the calling Array
    Array temp(*this);
    
    for(int i=0; i < getSize(); i++) {
	data[i]++;
    }
    return temp;
}

template <class T>
void Array<T>::printMyInfo() const {
    cout << "I am at: " << this << endl;
    cout << "My data is at: " << &data << endl;
    cout << "My size is at: " << &size << " with a value of : " << size << endl;
    cout << "My data points to: " << data << endl;
    cout << "The first item in data is: " << *data << endl;
}

template <class U>
ostream & operator<<(ostream &lhs, const Array<U> &rhs) {// overrides the << operator 
    for (int i = 0; i < rhs.getSize(); i++) {
        lhs << rhs[i] << " ";
    }
    cout << endl;
    return lhs;
}

template <class U>
istream & operator>>(istream &lhs, Array<U> &rhs) {//overides the cin >> operator 
    double temp;
    for (int i = 0; i < rhs.getSize(); i++) {
        lhs >> temp;
        rhs.setData(i, temp);
    }
    return lhs;
}
