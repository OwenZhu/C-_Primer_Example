#include <cassert>
#include <iostream>

class IntArray {

public:
    IntArray(int sz = DefaultArraySize);
    IntArray(int *array, int sz);
    IntArray(const IntArray &rhs);

    ~IntArray() { delete [] ia; }

    // 等于和不等于操作
    bool operator == (const IntArray&) const;
    bool operator != (const IntArray&) const;
    IntArray& operator = (const IntArray&);
    int size() const {return _size;};

    void sort();
    int min() const; // #3a
    int max() const; // #3b
    int find(int value) const; // #3c
    int& operator[](int index) {return ia[index];}

protected:
    // 私有实现代码
    static const int DefaultArraySize = 12;
    void init( int sz, int *array );
    int _size;
    int *ia;
};