#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>

using namespace std;



int main( int argc, char** argv ){
    std::string s;
    cin >> s;
    int w;
    cin >> w;

    for( int i = 0; i < static_cast<int>(s.size()); i++ ){
        if( i % w == 0 ) cout << s[i] << flush;
    }
    cout << endl;
return 0;
}
