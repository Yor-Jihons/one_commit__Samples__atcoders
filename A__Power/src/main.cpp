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

    // a^b
    long power = 1;
    for( int i = 0; i < b; i++ ){
        power *= a;
    }

    cout << power << endl;
return 0;
}
