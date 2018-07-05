#include "intarray.h"

IntArray::IntArray(int sz)
{
    // 设置数据成员
    _size = sz;
    ia = new int[ _size ];
    // 初始化内存
    for (int ix = 0; ix < _size; ++ix )
        ia[ ix ] = 0;
}

IntArray::IntArray(int *array, int sz)
{
    // 设置数据成员
    _size = sz;
    ia = new int[ _size ];
    // 拷贝数据成员
    for (int ix = 0; ix < _size; ++ix)
        ia[ix] = array[ix];
}

IntArray::IntArray( const IntArray &rhs )
{
    // 拷贝构造函数
    _size = rhs._size;
    ia = new int[ _size ];
    for (int ix = 0; ix < _size; ix++ )
        ia[ ix ] = rhs.ia[ ix ];
}

int& IntArray::operator[]( int index )
{
    assert( index >= 0 && index < _size );
    return ia[index];
}

int main() {
    IntArray myArray = IntArray();
    myArray[0] = 250;
    std::cout << myArray[0];
}