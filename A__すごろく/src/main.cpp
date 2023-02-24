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
    int n, k;
    {
        std::string s1;
        std::getline( cin, s1 );
        auto sv1 = Util::split( s1 );
        n = std::atoi( sv1[0].c_str() );
        k = std::atoi( sv1[1].c_str() );
    }

    std::vector<int> nums( k );
    {
        std::string s2;
        std::getline( cin, s2 );
        auto sv2 = Util::split( s2 );
        for( int i = 0; i < k; i++ ){
            nums[i] = std::atoi( sv2[i].c_str() );
        }
    }

    const int POS_GOAL = n;

    int pos_user_exists_now = 0;

    for( int i = 0; i < k; i++ ){
        if( (pos_user_exists_now + nums[i]) > POS_GOAL ){
            // 残りのマスの数を計算
            int remainder_cells = POS_GOAL - pos_user_exists_now;

            // 進ませるマス数を計算
            int tmp1 = nums[i] - remainder_cells;
            int tmp2 = POS_GOAL - tmp1;

            pos_user_exists_now = tmp2;
        }else if( (pos_user_exists_now + nums[i]) == POS_GOAL ){
            pos_user_exists_now = POS_GOAL;
            break;
        }else{
            pos_user_exists_now += nums[i];
        }
    }

    cout << pos_user_exists_now << endl;
return 0;
}
