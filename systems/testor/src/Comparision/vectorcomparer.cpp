#include"vectorcomparer.h"

#include<string>
#include<iostream>

using std::cout;
using std::endl;

namespace Testor::Comparision{
    VectorComparer::VectorComparer( bool allow2ShowMessage_WhenError ) : allow2ShowMessage_WhenError_(allow2ShowMessage_WhenError){

    }

    bool VectorComparer::Compare( const std::vector<std::string>& expected, const std::vector<std::string>& actuals ){
        // When the count of the their rows are different, returns false.
        if( actuals.size() != expected.size() ){
            if( allow2ShowMessage_WhenError_ ) cout << "The count of the rows are different." << endl;
            return false;
        }
        // When the row is different, return false.
        for( int i = 0; i < static_cast<int>(actuals.size()); i++ ){
            if( actuals[i].compare( expected[i] ) != 0 ){
                if( allow2ShowMessage_WhenError_ ) cout << "The line " << i << " are different." << endl;
                return false;
            }
        }
    return true;
    }
}