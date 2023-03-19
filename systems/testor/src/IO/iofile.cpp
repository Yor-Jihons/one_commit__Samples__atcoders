#include"iofile.h"
#include<fstream>
#include<iostream>
#include"../Exceptions/fileopenexception.h"

namespace Testor::IO{
    std::vector<std::string> ReadAllFile( const std::string& filepath ){
        std::ifstream ifs( filepath.c_str() );

        if( ifs.fail() ) throw Exceptions::FileOpenException( "Cannot open the file \"" + filepath + "\"."  );

        std::vector<std::string> ret;

        std::string s;
        while( std::getline( ifs, s ) ) ret.push_back( s );
    return ret;
    }
}