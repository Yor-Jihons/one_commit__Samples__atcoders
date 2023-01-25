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

    long long power = 1;
    for( int i = 0; i < n; i++ ){
        power *= 2;
    }

    cout << power << endl;
return 0;
}
