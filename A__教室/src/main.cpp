#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>

using namespace std;

int main( int argc, char** argv ){
    int a, b;
    cin >> a >> b;

    int one_room = b * b;
    int all_rooms = a * one_room;
    cout << all_rooms << endl;
return 0;
}
