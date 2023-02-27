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
    int a, b;
    cin >> a >> b;

    char work = static_cast<char>(s[a - 1]);
    s[a - 1] = static_cast<char>(s[b - 1]);
    s[b - 1] = static_cast<char>(work);

    cout << s << endl;
return 0;
}
