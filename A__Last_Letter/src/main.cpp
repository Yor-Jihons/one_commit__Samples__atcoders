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
    std::string s;
    cin >> s;

    cout << s.at( s.size() - 1 ) << endl;
return 0;
}
