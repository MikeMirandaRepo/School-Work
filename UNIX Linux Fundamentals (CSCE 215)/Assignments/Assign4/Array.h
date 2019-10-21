




/* 
 * File:   Array.h
 * Author: Michael Miranda
 *
 * Created on October 2, 2017
 */

#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
using namespace std;

class Array {
public:
    Array();
    Array(int _size);
    Array(int _size, double value);
    Array(const Array& orig);
    ~Array();

    void print() const;

    void expand();
    int getSize() const;
    double getData(int index) const;
    double operator[](int index) const;

    void setData(int index, double value);
    bool equal(const Array& rhs) const;
    bool operator==(const Array& rhs) const;
    bool operator!=(const Array& rhs) const;
    void operator=(const Array& rhs);

private:
    double *data;
    int size;
    void setSize(int value);
};

#endif /* ARRAY_H */
