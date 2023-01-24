#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>


using std::cout;
using std::endl;
using std::flush;
using std::cin;

namespace Original{
    int CalcCentury( int year ){
        const int delimiter = 100;
        int r = year % delimiter;
        int ret = year / delimiter;
    return (year % delimiter == 0 ? ret : (ret + 1));
    }
}


int main( int argc, char** argv ){
    int n;
    cin >> n;

    cout << Original::CalcCentury( n ) << endl;
return 0;
}
