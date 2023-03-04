#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>

using namespace std;

int main( int argc, char** argv ){
    int a, d;
    cin >> a >> d;

    long attackPowerIncreased  = (a + 1) * d;
    long defencePowerIncreased = a * (d + 1);

    cout << std::max( attackPowerIncreased, defencePowerIncreased ) << endl;
return 0;
}
