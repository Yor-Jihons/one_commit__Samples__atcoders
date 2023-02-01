#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>

using namespace std;

int main( int argc, char** argv ){
    int x;
    cin >> x;

    const int delim = 100;
    int reminder = x % delim;

    if( x == 0 ) reminder  = 100;
    else         reminder = delim - reminder;

    cout << reminder << endl;
return 0;
}
