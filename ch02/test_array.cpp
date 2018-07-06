#include <iostream>
#include "int_array.h"
#include "int_array_RC.h"
using namespace std;

extern void swap(IntArray&, int, int);

int main() {
    int array[ 4 ] = { 0, 1, 2, 3 };
    IntArray ia1( array, 4 );
    IntArrayRC ia2( array, 4 );

    // Error, IntArray 对象捕捉不到这个错误
    cout << "swap() with IntArray ia1\n";
    swap( ia1, 1, ia1.size() );

    // ok: IntArrayRC 对象可以捕捉到这样的错误
    cout << "swap() with IntArrayRC ia2\n";
    swap( ia2, 1, ia2.size() );
    
    return 0;
}
