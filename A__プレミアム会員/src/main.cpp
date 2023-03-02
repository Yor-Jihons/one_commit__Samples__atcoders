#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>

using namespace std;

int main( int argc, char** argv ){
    int n, x;
    cin >> n;
    cin >> x;

    int monthBeforeIncreased = n - x;
    int monthAfterIncreased  = n - monthBeforeIncreased;

    const int FeeMonthBeforeIncreased = 525;
    const int FeeMonthAfterIncreased  = 540;

    long feeMonthsBeforeIncreased = monthBeforeIncreased * FeeMonthBeforeIncreased;
    long feeMothsAfterIncreased   = monthAfterIncreased * FeeMonthAfterIncreased;

    long allFee = feeMonthsBeforeIncreased + feeMothsAfterIncreased;

    cout << allFee << endl;
return 0;
}
