#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>

using namespace std;


int main( int argc, char** argv ){
    char a;
    cin >> a;

    if( a >= 'A' && a <= 'Z' ){
        cout << "A" << endl;
    }else if( a >= 'a' && a <= 'z' ){
        cout << "a" << endl;
    }
return 0;
}
