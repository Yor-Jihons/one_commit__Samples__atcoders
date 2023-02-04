#include<iostream>

using std::endl;
using std::flush;
using std::cin;
using std::cout;

namespace Origignal{
    using TYPE = long double;
    TYPE CalcMeanBloodPressure( int a, int b ){
        TYPE tmp1 = static_cast<TYPE>(a) - static_cast<TYPE>(b);
        TYPE tmp2 = static_cast<TYPE>(tmp1) / static_cast<TYPE>(3);
        TYPE tmp3 = static_cast<TYPE>(tmp2) + b;
    return tmp3;
    }
}


int main( int argc, char** argv ){
    int a, b;
    cin >> a >> b;
    Origignal::TYPE ret = Origignal::CalcMeanBloodPressure( a, b );
    cout << ret << endl;
return 0;
}
