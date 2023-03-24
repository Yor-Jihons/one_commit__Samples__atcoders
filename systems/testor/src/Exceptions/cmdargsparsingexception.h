/**
* @file
* @brief The exception which means the command line arguments are something wrong.
* @license
* Copyright (c) 2023 Yor-Jihons
* Released under the MIT license.
* https://github.com/Yor-Jihons/one_commit__Samples__atcoders/blob/main/systems/testor/LICENSE
*/

#ifndef EXCEPTIONS_CMDARGSPARSINGEXCEPTION_H
#define EXCEPTIONS_CMDARGSPARSINGEXCEPTION_H

#include<exception>
#include<string>

namespace Testor::Exceptions{
    /// @brief The exception class which means the command line arguments are something wrong.
    class CmdArgsParsingException : public std::runtime_error{
        public:
            /**
            * @brief Constructor.
            * @param msg The message to show.
            */
            CmdArgsParsingException( const std::string& msg ) : std::runtime_error(msg.c_str()){}
    };
}

#endif
