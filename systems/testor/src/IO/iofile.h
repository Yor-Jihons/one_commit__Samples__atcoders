/**
* @file
* @brief The functions for I/O.
*/

#ifndef IO_IOFILE_H
#define IO_IOFILE_H

#include<vector>
#include<string>

namespace Testor::IO{
    /**
    * @brief Reads file and returns the vector of the strings.
    * @param filepath The file path you want to read.
    * @return The texts in the file contains.
    */
    std::vector<std::string> ReadAllFile( const std::string& filepath );
}

#endif
