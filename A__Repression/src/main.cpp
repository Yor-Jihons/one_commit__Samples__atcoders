#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>

using namespace std;

int main( int argc, char** argv ){
    int a, b, c;

    cin >> a >> b >> c;

    int a_b = a + b;
    int a_c = a + c;
    int b_c = b + c;

    cout << std::max( b_c, std::max( a_b, a_c ) ) << endl;
return 0;
}
