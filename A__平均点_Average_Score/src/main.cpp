#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>

using namespace std;



int main( int argc, char** argv ){
    const int MAX = 5;
    std::vector<int> points( MAX );

    for( int i = 0; i < MAX; i++ ){
        cin >> points[i];
    }

    int sum = 0;
    for( int i = 0; i < MAX; i++ ){
        int point = points[i];
        if( point < 40 ) point = 40;
        sum += point;
    }

    cout << (sum / MAX) << endl;

return 0;
}
