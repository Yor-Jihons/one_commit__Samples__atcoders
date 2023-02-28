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

    int work = a;
    a = b;
    b = work;

    cout << a << " " << b << endl;
return 0;
}
