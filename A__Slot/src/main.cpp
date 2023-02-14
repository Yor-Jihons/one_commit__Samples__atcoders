#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>

using namespace std;


int main( int argc, char** argv ){
    std::string c;
    cin >> c;

    bool isLost = false;
    for( int i = 0; i < 2; i++ ){
        if( c[i] != c[i + 1] ){
            isLost = true;
            break;
        }
    }

    cout << (isLost ? "Lost" : "Won") << endl;
return 0;
}
