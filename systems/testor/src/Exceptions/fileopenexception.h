/**
* @file
* @brief The exception which means opening file was failed.
* @license
* Copyright (c) 2023 Yor-Jihons
* Released under the MIT license.
* https://github.com/Yor-Jihons/one_commit__Samples__atcoders/blob/main/systems/testor/LICENSE
*/

#ifndef EXCEPTIONS_FILEOPENEXCEPTION_H
#define EXCEPTIONS_FILEOPENEXCEPTION_H

#include<exception>
#include<string>

namespace Testor::Exceptions{
    /// @brief The exception class which means opening file was failed.
    class FileOpenException : public std::runtime_error{
        public:
            /**
            * @brief Constructor.
            * @param msg The message to show.
            */
            FileOpenException( const std::string& msg ) : std::runtime_error(msg.c_str()){}
    };
}

#endif
