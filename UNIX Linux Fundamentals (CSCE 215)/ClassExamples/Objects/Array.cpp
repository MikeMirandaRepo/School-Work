
/* 
 * File:   Array.cpp
 * Author: homayoun
 * 
 * Created on September 22, 2017, 1:22 PM
 */

#include "Array.h"

Array::Array() : size(10) {
    //size = 10;
    data = new double[size];
    for(int i=0; i < size; i++) {
        data[i] = i;
    }
}

Array::Array(int _size) : size(_size){
    //size = _size;
    data = new double[size];
    for(int i=0; i < size; i++) {
        data[i] = i;
    }
}

Array::Array(int _size, double value) : size(_size) {
    //size = _size;
    data = new double[size];
    for(int i=0; i < size; i++) {
        data[i] = value;
    }
}

Array::Array(const Array& orig) { 
    setSize(orig.getSize());
    data = new double[getSize()];

    for (int i = 0; i < getSize(); i++) {
        setData(i, orig[i]);
    }
}

Array::~Array() {
    delete [] data;
}

void Array::print() const{
    for(int i=0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

void Array::expand(){
	double *local = new double[size+1];
	for(int i = 0; i < size; i++)
	{	
		local[i] = data[i];
	}

	local[size] = size;

	delete [] data;
	size++;
	data = local;


}


int Array::getSize() const {
	return size;
} 

void Array::setSize(int value){
	size = value;
}

double Array::getData(int index) const{
if(index >= 0 && index < size)
	return data[index];
else
	return data[size-1];

}


double Array::operator[](int index) const{
	if(index >= 0 && index < size)
        	return data[index];
	else
       		return data[size-1];

}


void Array::setData(int index, double value){
if(index >=0 && index < size)
	data[index] = value;
else
	cout << "out of bounds" <<endl;


}

bool Array::equal(const Array& rhs) const{
    bool result(true);
    
    if(getSize() != rhs.getSize()) {
        result = false;
    } else {
        for(int i =0; i < getSize(); i++) {
            if(getData(i) != rhs.getData(i)){
                result = false;
            }
        }
    }
    return result;
}



bool Array::operator==(const Array& rhs) const{
    bool result(true);

    if(getSize() != rhs.getSize()) {
        result = false;
    } else {
        for(int i =0; i < getSize(); i++) {
            if(getData(i) != rhs.getData(i)){
                result = false;
            }
        }
    }
    return result;
}

bool Array::operator!=(const Array& rhs) const {
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
    //    return !(*this == rhs);
}






void Array::operator=(const Array& rhs){
	delete [] data;
	setSize(rhs.getSize());
	data = new double[getSize()];
	for(int i =0; i < getSize(); i++){
		data[i] = rhs[i];
	}

}


const Array Array::operator+(const Array & rhs) const{
    Array Cookies(rhs);
    if (getSize() != rhs.getSize()) {
        cout << "Exception" << endl;
    } else {
        for (int i = 0; i < getSize(); i++) {
            Cookies.setData(i, rhs[i] + data[i]);
        }
    }
    return Cookies;
}

void Array::printMyInfo() {
    cout << "I am at: " << this << endl;
    cout << "My data is at: " << &data << endl;
    cout << "My size is at: " << &size << " with a value of : " << size << endl;
    cout << "My data points to: " << data << endl;
    cout << "The first item in data is: " << *data << endl;
}

 const Array Array::operator++() {
    for(int i=0; i < getSize(); i++) {
        data[i]++;
    }
    return *this;
}

const Array Array::operator++(int dummy) {
    Array temp(*this);
    
    for(int i=0; i < getSize(); i++) {
        data[i]++;
    }
    return temp;
}

ostream & operator<<(ostream &lhs, const Array &rhs) {
    for (int i = 0; i < rhs.getSize(); i++) {
        lhs << rhs[i] << " ";
    }
    cout << endl;
    return lhs;
}

istream & operator>>(istream &lhs, Array &rhs) {
    double temp;
    for (int i = 0; i < rhs.getSize(); i++) {
        lhs >> temp;
        rhs.setData(i, temp);
    }
    return lhs;
}


