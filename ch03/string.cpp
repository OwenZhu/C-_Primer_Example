# include "String.h"

inline bool
String::operator==(const String &rhs) {
    if (_size != rhs._size)
        return false;
    return strcmp(_string, rhs._string) ? false : true;
}

inline bool
String::operator==(const char *s)
{
    return strcmp( _string, s ) ? false : true;
}

inline String::String() {
    _size = 0;
    _string = 0;
}

inline String::String( const char *str )
{
    if ( ! str ) {
        _size = 0; _string = 0;
    } else {
        _size = strlen( str );
        _string = new char[ _size + 1 ];
        strcpy( _string, str );
    }
}

// 拷贝构造函数
inline String::String( const String &rhs ) {
    _size = rhs._size;
    if ( ! rhs._string )
        _string = 0;
    else {
        _string = new char[ _size + 1 ];
        strcpy( _string, rhs._string );
    }
}

inline String::~String() { delete [] _string; }

inline String&
String::operator=( const String &rhs )
{
    if ( this != &rhs )
    {
        delete [] _string;
        _size = rhs._size;
        if ( ! rhs._string )
            _string = 0;
        else {
            _string = new char[ _size + 1 ];
            strcpy( _string, rhs._string );
        }
    }
    return *this;
}

inline String&
String::operator=( const char *s )
{
    if ( !s ) {
        _size = 0;
        delete [] _string;
        _string = 0;
    } else {
        _size = strlen( s );
        delete [] _string;
        _string = new char[ _size + 1 ];
        strcpy( _string, s );
    }
    return *this;
}

inline char&
String::operator[]( int elem )
{
    assert( elem >= 0 && elem < _size );
    return _string[ elem ];
}

inline istream&
operator>>( istream &io, String &s )
{
    // 人工限制最多 4096 个字符
    const int limit_string_size = 4096;
    char inBuf[ limit_string_size ];
    // setw()是 iostream 库的一部分
    // 限制被读取的字符个数为 limit_string_size-1
    io >> setw( limit_string_size ) >> inBuf;
    s = inBuf; // String::operator=( const char* );

    return io;
}

inline ostream&
operator<<( ostream& os, String &s )
{
    return os << s.c_str();
}

int main() {
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0,
        theCnt = 0, itCnt = 0, wdCnt = 0, notVowel = 0;
    // 为了使用 operator==( const char* )
    // 我们并不定义 The( "The" )和 It( "It" )
    String buf, the( "the" ), it( "it" );

    // 调用 operator>>( istream&, String& )
    while ( cin >> buf ) {
        ++wdCnt;
        // 调用 operator<<( ostream&, const String& )
        cout << buf << ' ';
        if ( wdCnt % 12 == 0 )
            cout << endl;
        // 调用 String::operator==(const String&) and
        // String::operator==( const char* );
        if ( buf == the || buf == "The" )
            ++theCnt;
        else if ( buf == it || buf == "It" )
            ++itCnt;
        // 调用 String::size()
        for ( int ix = 0; ix < buf.size(); ++ix ) {
            // 调用 String::operator[](int)
            switch ( buf[ ix ] )
            {
            case 'a': case 'A': ++aCnt; break;
            case 'e': case 'E': ++eCnt; break;
            case 'i': case 'I': ++iCnt; break;
            case 'o': case 'O': ++oCnt; break;
            case 'u': case 'U': ++uCnt; break;
            default: ++notVowel; break;
            }
        }
    }

    // 调用 operator<<( ostream&, const String& )
    cout << "\n\n"
         << "Words read: " << wdCnt << "\n\n"
         << "the/The: " << theCnt << '\n'
         << "it/It: " << itCnt << "\n\n"
         << "non-vowels read: " << notVowel << "\n\n" << "a: " << aCnt << '\n'
         << "e: " << eCnt << '\n'
         << "i: " << iCnt << '\n'
         << "o: " << oCnt << '\n'
         << "u: " << uCnt << endl;
}

