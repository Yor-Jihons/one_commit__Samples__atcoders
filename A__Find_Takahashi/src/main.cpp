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


namespace Original{
    std::vector<int> CreateArithmeticProgression( int a1, int n, int d ){
        std::vector<int> progression( n );
        progression[0] = a1;
        for( int i = 1; i < n; i++ ){
            progression[i] = progression[0] + (((i+1) - 1) * d);
        }
    return progression;
    }
}

namespace Original{
    class Power{
        public:
            Power( int r ) : nums_(Power::CreatePowerSequence(r)){}
            ~Power() = default;

            int At( int n ){
                if( n < 0 || n >= static_cast<int>(nums_.size()) ) return -1;
            return nums_[n];
            }
        public:
            static std::vector<int> CreatePowerSequence( int r ){
                std::vector<int> nums;
                int tmp = 1;
                for( int i = 0; i <= r; i++ ){
                    nums.push_back( tmp );
                    tmp *= r;
                }
            return nums;
            }
        private:
            std::vector<int> nums_;
    };
}


int main( int argc, char** argv ){
    int n;
    {
        std::string s1;
        std::getline( cin, s1 );
        n = std::atoi( s1.c_str() );
    }

    std::vector<int> nums( n );
    {
        std::string s2;
        std::getline( cin, s2 );
        Util::StrVec sv = Util::split( s2 );
        for( int i = 0; i < n; i++ ){
            nums[i] = std::atoi( sv[i].c_str() );
        }
    }

    int pos_where_max_value_exists = 0;
    for( int i = 1; i < n; i++ ){
        if( nums[i] > nums[pos_where_max_value_exists] ) pos_where_max_value_exists = i;
    }

    cout << (pos_where_max_value_exists + 1) << endl;
return 0;
}
