#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>

using namespace std;

int main( int argc, char** argv ){
    int a, b;
    cin >> a >> b;

    if( a > 9 || b > 9 ){
        cout << "-1" << endl;
    }else{
        cout << a * b << endl;
    }
return 0;
}
