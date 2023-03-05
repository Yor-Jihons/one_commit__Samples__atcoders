#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>

using namespace std;

namespace Original{
    int calc( int n, int r ){
        if( n >= 10 ) return r;

        int tmp1 = (100 * (10 - n));
    return r + tmp1;
    }
}

int main( int argc, char** argv ){
    int n, r;
    cin >> n >> r;

    int ans = Original::calc( n, r );
    cout << ans << endl;
return 0;
}
