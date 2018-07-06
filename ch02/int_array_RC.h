#ifndef IntArrayRC_H
#define IntArrayRC_H

#include <cassert>
#include "int_array.h"


class IntArrayRC : public IntArray {

public:
    IntArrayRC( int sz = DefaultArraySize );
    IntArrayRC( int *array, int array_size );
    IntArrayRC( const IntArrayRC &rhs );
    virtual int& operator[](int);

private:
    void check_range( int );
};

inline int& IntArrayRC::operator[](int index)
{
    check_range( index );
    return ia[ index ];
}

inline void IntArrayRC::check_range(int index)
{
    assert( index >= 0 && index < _size );
}

inline IntArrayRC::IntArrayRC(int sz)
    : IntArray( sz ) {}

inline IntArrayRC::IntArrayRC(int *iar, int sz)
    : IntArray( iar, sz ) {}

#endif