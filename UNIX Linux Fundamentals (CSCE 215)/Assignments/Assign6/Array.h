/*
  * Author: Michael Miranda
 *
 * Created on September 22, 2017, 1:22 PM
 */

#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
using namespace std;


template <class T>
class Array {
	template <class U>
    friend ostream & operator<<(ostream &lhs, const Array &rhs);
	template <class U>
    friend istream & operator>>(istream &lhs, Array &rhs);


public:
    Array();
    Array(int _size);
    Array(int _size, T value);
    Array(T *orig,int _size);
    Array(const Array& orig);
    ~Array();

    void print() const;
    void expand();
    void init();    

    int getSize() const;
    void setSize(int value);
    T getData(int index) const;
    T operator[](int index) const;

    int operator[](int index);//a variation of setData
    const Array operator-();//makes all elements -

    void setData(int index, T value);
    bool equal(const Array& rhs) const;
    bool operator==(const Array& rhs) const;
    bool operator!=(const Array& rhs) const;
    const Array operator=(const Array& rhs);
  
    const Array operator+(const Array& rhs) const;

    const Array operator++(); //prefix ++Array
    const Array operator++(int dummy); //postfix Array++
    void printMyInfo() const;
private:
    T *data;
    int size;
};

#endif /* ARRAY_H */

