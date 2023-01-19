#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>

using namespace std;

namespace Original{
    class Power{
        public:
            Power( int a ){
                int tmp = 1;
                for( int i = 0; i < 3; i++ ){
                    tmp *= a;
                    power_.push_back( tmp );
                }
            }
            ~Power() = default;

            int At( int index ){
                return power_.at( index );
            }
        private:
            std::vector<int> power_;
    };
}

int main( int argc, char** argv ){
    int a;
    cin >> a;

    int sum = 0;

    Original::Power power( a );
    for( int i = 0; i < 3; i++ ){
        sum += power.At( i );
    }

    cout << sum << endl;
return 0;
}
