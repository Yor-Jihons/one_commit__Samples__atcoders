#include<iostream>
#include<list>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>

using namespace std;

namespace Util{
    /** @brief The array of the strings. */
    using StrVec = std::vector<std::string>;

    /**
     * @brief Separate the strings.
     * @param text The string you want to separate.
     * @param delim The delim string. ( def: " " )
     * @return The object of the std::Vector for std::string, which was separated.
    */
    StrVec split( const std::string& text, const std::string& delim = std::string(" ") ){
        StrVec res;
        int end = 0, begin = 0, n = 0;
        while( true ){
            end   = text.find( delim, begin );
            if( end == std::string::npos ){
                res.push_back( text.substr( begin, (text.size() - begin) ) );
                break;
            }
            n = (end - begin);
            res.push_back( text.substr( begin, n ) );
            begin = end + 1;
        }
    return res;
    }

    /**
     * @brief Convert the data to the string.
     * @param val The data you want to convert.
     * @return The string which was converted from the data.
     */
    template<typename T> std::string ToString( T val ){
        std::stringstream ss;
        ss << val << flush;
    return ss.str();
    }
}


int main( int argc, char** argv ){
    int n, k;
    {
        std::string s1;
        std::getline( cin, s1 );
        Util::StrVec sv1 = Util::split( s1 );
        n = std::atoi( sv1[0].c_str() );
        k = std::atoi( sv1[1].c_str() );
    }

    std::string s2;
    std::getline( cin, s2 );
    Util::StrVec sv2 = Util::split( s2 );

    std::list<int> nums;
    for( int i = 0; i < n; i++ ){
        nums.push_back( std::atoi( sv2[i].c_str() ) );
    }

    const int MAX = std::min( k, n );

    for( int i = 0; i < MAX; i++ ){
        nums.pop_front();
        nums.push_back( 0 );
    }

    int counter = 0;
    for( auto it = nums.begin(); it != nums.end(); it++ ){
        counter++;
        cout << (*it) << flush;
        if( counter != n ) cout << " " << flush;
    }
    cout << endl;
return 0;
}
