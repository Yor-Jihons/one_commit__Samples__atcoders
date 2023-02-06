#include<iostream>
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
    int n, x;
    {
        std::string s;
        std::getline( cin, s );
        Util::StrVec sv = Util::split( s );
        n = std::atoi( sv[0].c_str() );
        x = std::atoi( sv[1].c_str() );
    }

    std::vector<int> a(n);
    {
        std::string s;
        std::getline( cin, s );
        Util::StrVec sv = Util::split( s );
        for( int i = 0; i < n; i++ ){
            a[i] = std::atoi( sv[i].c_str() );
        }
    }

    int sum = 0;
    for( int i = 0; i < n; i++ ){
        sum += ((i + 1) % 2 == 0 ? (a[i] - 1) : a[i] );
    }

    if( sum <= x ) cout << "Yes" << endl;
    else           cout << "No" << endl;
return 0;
}
