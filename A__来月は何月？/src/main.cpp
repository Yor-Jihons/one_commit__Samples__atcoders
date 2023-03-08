#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>

using namespace std;

int main( int argc, char** argv ){
    int n;
    cin >> n;

    int nextMonth = n;
    if( n == 12 ) nextMonth = 1;
    else          nextMonth++;

    cout << nextMonth << endl;
return 0;
}
