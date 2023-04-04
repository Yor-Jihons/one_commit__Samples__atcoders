/**
* @file
* @brief The functions for I/O.
* @license
* Copyright (c) 2023 Yor-Jihons
* Released under the MIT license.
* https://github.com/Yor-Jihons/one_commit__Samples__atcoders/blob/main/systems/testor/LICENSE
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
    * @exception Testor::Exceptions::FileOpenException Cannot open the file.
    */
    std::vector<std::string> ReadAllFile( const std::string& filepath );
}

#endif
