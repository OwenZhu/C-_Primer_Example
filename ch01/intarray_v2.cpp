class IntArray_v2 {

public:
    explicit IntArray_v2(int sz = DefaultArraySize);
    IntArray_v2(int *array, int array_size);
    IntArray_v2(const IntArray_v2 &rhs);
    // 相等与不相等操作 #2b
    bool operator == ( const IntArray_v2& ) const;
    bool operator != ( const IntArray_v2& ) const;
    // 赋值操作符   #2a
    IntArray_v2& operator = (const IntArray_v2&);
    int size() const {return _size;}; // #1 void sort(); // #4
    int min() const; // #3a int max() const; // #3b
    // 如值在数组中找到
    // 返回第一次出现的索引
    // 否则返回-1
    int find( int value ) const; // #3c
    ~IntArray_v2() { delete [] ia; }

private:
    // 私有实现代码
    void init( int sz, int *array );
    static const int DefaultArraySize = 12;
    int _size;
    int *ia;
};

void IntArray_v2::init( int sz, int *array )
{
    _size = sz;
    ia = new int[ _size ];
    for ( int ix = 0; ix < _size; ++ix )
    {
        if ( ! array )
            ia[ ix ] = 0;
        else ia[ ix ] = array[ ix ];
    }
}

IntArray_v2::IntArray_v2( int sz )
{init( sz, 0 );}

IntArray_v2::IntArray_v2( int *array, int sz )
{ init( sz, array ); }

IntArray_v2::IntArray_v2( const IntArray_v2 &rhs )
{ init( rhs.size, rhs.ia ); }
