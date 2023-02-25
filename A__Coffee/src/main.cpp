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

    if( s[2] == s[3] && s[4] == s[5] ){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
return 0;
}
