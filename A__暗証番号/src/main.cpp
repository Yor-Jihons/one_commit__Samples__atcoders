#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>

using namespace std;

namespace Original{
    bool isSame( const std::string& str ){
        for( int i = 0; i < static_cast<int>(str.size()) - 1; i++ ){
            if( str[i] != str[i + 1] ) return false;
        }
    return true;
    }
}

int main( int argc, char** argv ){

    std::string s;
    cin >> s;

    cout << (Original::isSame( s ) ? "SAME" : "DIFFERENT" ) << endl;
return 0;
}
