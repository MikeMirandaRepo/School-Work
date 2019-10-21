

   

#include "Array.h"
template <class T>
Array<T>::Array() : size(10) {
    //    size = 10;
    data = new T [size];
    for (int i = 0; i < size; i++) {
        data[i] = i;
    }
}

template <class T>
Array<T>::Array(int _size) : size(_size) {
    size = _size;
    data = new T [size];
    for (int i = 0; i < size; i++) {
        data[i] = i;
    }
}

template <class T>
Array<T>::Array(int _size, T value) : size(_size) {
    //    size = _size;
    data = new T [size];
    for (int i = 0; i < size; i++) {
        data[i] = value;
    }
}

template <class T>
Array<T>::Array(const Array& orig) {
    setSize(orig.getSize());
    data = new T [getSize()];
    for (int i = 0; i < getSize(); i++) {
        setData(i, orig.getData(i));
    }
}

template <class T>
Array<T>::~Array() {
    delete [] data;
}

template <class T>
int Array<T>::getSize() const {
    return size;
}

template <class T>
void Array<T>::setSize(int value) {
    if (value > 0) {
        size = value;
    }
}

template <class T>
void Array<T>::setData(int index, T value) {
    if ((index >= 0) && (index < size)) {
        data[index] = value;
    } else {
        cout << "NO!" << endl;
    }
}

template <class T>
T Array<T>::getData(int index) const {
    if ((index >= 0) && (index < size)) {
        return data[index];
    } else {
        return data[size - 1];
    }
}

template <class T>
T Array<T>::operator[](int index) const {
    if ((index >= 0) && (index < size)) {
        return data[index];
    } else {
        return data[size - 1];
    }
}

template <class T>
void Array<T>::print() const {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

template <class T>
void Array<T>::expand() {
    double *localArray = new T [size + 1];

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

template <class T>
bool Array<T>::equal(const Array& rhs) const {
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
bool Array<T>::operator==(const Array& rhs) const {
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
bool Array<T>::operator!=(const Array& rhs) const {
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

template <class T>
void Array<T>::operator=(const Array& rhs) {
    delete [] data;
    setSize(rhs.getSize());
    data = new T [getSize()];
    for (int i = 0; i < size; i++) {
        data[i] = rhs[i];
    }
}

template <class T>
const Array<T> Array<T>::operator+(const Array & rhs) const {
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

template <class T>
const Array<T> Array<T>::operator++() {
    for(int i=0; i < getSize(); i++) {
        data[i]++;
    }
    return *this;
}

template <class T>
const Array<T> Array<T>::operator++(int dummy) {
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
ostream & operator<<(ostream &lhs, const Array<U> &rhs) {
    for (int i = 0; i < rhs.getSize(); i++) {
        lhs << rhs[i] << " ";
    }
    cout << endl;
    return lhs;
}

template <class U>
istream & operator>>(istream &lhs, Array<U> &rhs) {
    double temp;
    for (int i = 0; i < rhs.getSize(); i++) {
        lhs >> temp;
        rhs.setData(i, temp);
    }
    return lhs;
}

