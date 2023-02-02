#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>

using namespace std;


int main( int argc, char** argv ){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int left  = a + b;
    int right = c + d;

    if( left > right ){
        cout << "Left" << endl;
    }else if( left < right ){
        cout << "Right" << endl;
    }else{
        cout << "Balanced" << endl;
    }
return 0;
}
