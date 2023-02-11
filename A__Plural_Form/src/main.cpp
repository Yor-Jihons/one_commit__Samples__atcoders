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

    if( s[ s.length() - 1 ] == 's' ){
        s += "es";
    }else{
        s += "s";
    }

    cout << s << endl;
return 0;
}
