#ifndef IO_IOFILE_H
#define IO_IOFILE_H

#include<vector>
#include<string>

namespace Testor::IO{
    std::vector<std::string> ReadAllFile( const std::string& filepath );
}

#endif
