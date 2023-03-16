#include"iofile.h"
#include<fstream>
#include<iostream>

namespace Testor::IO{
    std::vector<std::string> ReadAllFile( const std::string& filepath ){
        std::ifstream ifs( filepath.c_str() );

        // TODO: ファイルが開けなかった系例外
        if( ifs.fail() ) throw std::exception("X");

        std::vector<std::string> ret;

        std::string s;
        while( std::getline( ifs, s ) ) ret.push_back( s );
    return ret;
    }
}