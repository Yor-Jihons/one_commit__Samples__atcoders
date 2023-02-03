#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>

using namespace std;

namespace Original{
    bool isPoor( int a, int b, int c ){
        if( a == b && a != c ) return true;
        if( a == c && a != b ) return true;
        if( b == c && a != b ) return true;
    return false;
    }
}

int main( int argc, char** argv ){
    int a, b, c;
    cin >> a >> b >> c;

    if( Original::isPoor( a, b, c ) ) cout << "Yes" << endl;
    else                              cout << "No" << endl;
return 0;
}
