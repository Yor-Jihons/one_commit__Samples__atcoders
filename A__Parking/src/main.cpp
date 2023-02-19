#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>

using namespace std;




int main( int argc, char** argv ){
    int n, a, b;
    cin >> n >> a >> b;

    int ans = std::min( (n * a), b );
    cout << ans << endl;
return 0;
}
