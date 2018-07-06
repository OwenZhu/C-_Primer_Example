#ifndef IntArray_H
#define IntArray_H

#include <cassert>
#include <iostream>


class IntArray {

public:
    explicit IntArray(int sz = DefaultArraySize);
    IntArray(int *array, int sz);
    IntArray(const IntArray &rhs);

    virtual ~IntArray() { delete [] ia; }

    // 等于和不等于操作
    bool operator == (const IntArray&) const;
    bool operator != (const IntArray&) const;
    IntArray& operator = (const IntArray&);
    int size() const {return _size;};

    /*
    virtual void sort();
    virtual int min() const; // #3a
    virtual int max() const; // #3b
    virtual int find(int value) const; // #3c
    */
    virtual int& operator[](int index) {return ia[index];}
    
protected:
    // 私有实现代码
    static const int DefaultArraySize = 12;
    void init( int sz, int *array );
    int _size;
    int *ia;
};

#endif