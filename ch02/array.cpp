template < class elemType >
class Array {

public:
// 把元素类型参数化
    explicit Array( int size = DefaultArraySize ); Array( elemType *array, int array_size );
    Array( const Array &rhs );
    virtual ~Array() { delete [] ia; }
    bool operator==( const Array& ) const;
    bool operator!=( const Array& ) const;
    Array& operator=( const Array& );
    int size() const { return _size; }
    virtual elemType& operator[](int index) { return ia[index]; }
    virtual void sort();
    virtual elemType min() const;
    virtual elemType max() const;
    virtual int find( const elemType &value ) const;
    
protected:
    static const int DefaultArraySize = 12;
    int _size;
    elemType *ia;
};
