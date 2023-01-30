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

    const int currency = 1000;

    int reminder = n % currency;
    if( reminder > 1 ) reminder = currency - reminder;

    cout << reminder << endl;
return 0;
}
