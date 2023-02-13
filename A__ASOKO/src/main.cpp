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

    for( int i = 0; i < static_cast<int>(s.size()); i++ ){
        if( s[i] == 'A' ){
            s[i] = 'O';
        }else if( s[i] == 'O' ){
            s[i] = 'A';
        }
    }

    cout << s << endl;
return 0;
}
