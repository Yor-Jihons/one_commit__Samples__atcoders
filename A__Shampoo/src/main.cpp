#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>

using namespace std;


namespace Original{
    class Shampoo{
        public:
            Shampoo( int v ) : v_(v){}

            bool Use( int n ){
                if( v_ < n ) return false;
                v_ -= n;
            return true;
            }

            bool IsEmpty( void ) const{
                return (v_ <= 0 ? true : false);
            }
        private:
            int v_;
    };
}


int main( int argc, char** argv ){
    int v, a, b, c;
    cin >> v >> a >> b >> c;

    int counter = 0;

    Original::Shampoo shampoo( v );
    while( true ){
        if( !shampoo.Use( a ) ){
            cout << "F" << endl;
            break;
        }

        if( !shampoo.Use( b ) ){
            cout << "M" << endl;
            break;
        }

        if( !shampoo.Use( c ) ){
            cout << "T" << endl;
            break;
        }
    }
return 0;
}
