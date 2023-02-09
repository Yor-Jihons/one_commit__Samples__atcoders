#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>

using namespace std;


namespace Original{
    class Pair{
        public:
            Pair( int x, int y ) : x_(x),y_(y){}
            ~Pair() = default;

            int X( void ) const{ return x_; }
            int Y( void ) const{ return y_; }
        private:
            int x_;
            int y_;
    };

    Pair* Calc( int a, int b ){
        for( int i = -100; i < 100; i++ ){
            for( int j = -100; j < 100; j++ ){
                if( (i + j) == a && (i - j) == b ) return new Pair( i, j );
            }
        }
    return nullptr;
    }
}


int main( int argc, char** argv ){
    int a, b;
    cin >> a >> b;

    Original::Pair* pair = Original::Calc( a, b );
    cout << pair->X() << " " << pair->Y() << endl;
    delete pair;
return 0;
}
