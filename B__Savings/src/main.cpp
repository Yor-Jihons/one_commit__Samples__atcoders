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

    int sum = 0;
    int i   = 0;
    while( sum < n ){
        i++;
        sum += i;
    }

    cout << i << endl;
return 0;
}
