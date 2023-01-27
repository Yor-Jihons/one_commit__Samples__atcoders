#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>

using namespace std;

namespace Original{
    int CalcRank( int n ){
        if( n >= 1800 && n <= 1999 ) return 1;
        if( n >= 1600 && n <= 1799 ) return 2;

        if( n >= 1400 && n <= 1599 ) return 3;
        if( n >= 1200 && n <= 1399 ) return 4;
        if( n >= 1000 && n <= 1199 ) return 5;
        if( n >=  800 && n <=  999 ) return 6;
        if( n >=  600 && n <=  799 ) return 7;
        if( n >=  400 && n <=  599 ) return 7;
    return -1;
    }
}

int main( int argc, char** argv ){
    int n;
    cin >> n;

    int rank = Original::CalcRank( n );
    cout << rank << endl;
return 0;
}
