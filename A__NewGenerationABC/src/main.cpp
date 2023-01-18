#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>

using std::cout;
using std::cin;
using std::endl;

int main( int argc, char** argv ){
    int n;
    cin >> n;

    if( n >= 212 && n <= 214 ){
        cout << 8 << endl;
    }else if( n >= 126 && n <= 211 ){
        cout << 6 << endl;
    }else{
        cout << 4 << endl;
    }
return 0;
}
