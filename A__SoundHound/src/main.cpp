#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>

using namespace std;


int main( int argc, char** argv ){
    string s1, s2;
    cin >> s1 >> s2;

    if( s1[0] == 'S' && s2[0] == 'H' ){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
return 0;
}
