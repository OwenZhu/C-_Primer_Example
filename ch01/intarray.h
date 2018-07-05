#include <cassert>
#include <iostream>

class IntArray {

public:
    IntArray(int sz = DefaultArraySize);
    IntArray(int *array, int array_size);
    IntArray(const IntArray &rhs);
    // 相等与不相等操作 #2b
    bool operator == ( const IntArray& ) const;
    bool operator != ( const IntArray& ) const;
    // 赋值操作符   #2a
    IntArray& operator = (const IntArray&);
    int size() const {return _size;}; // #1 void sort(); // #4
    int min() const; // #3a int max() const; // #3b
    // 如值在数组中找到
    // 返回第一次出现的索引
    // 否则返回-1
    int find( int value ) const; // #3c
    int& operator[] ( int index );
private:
    // 私有实现代码
    static const int DefaultArraySize = 12;
    int _size;
    int *ia;
};