#ifndef EXCEPTIONS_CMDARGSPARSINGEXCEPTION_H
#define EXCEPTIONS_CMDARGSPARSINGEXCEPTION_H

#include<exception>
#include<string>

namespace Testor::Exceptions{
    class CmdArgsParsingException : public std::runtime_error{
        public:
            CmdArgsParsingException( const std::string& msg ) : std::runtime_error(msg.c_str()){}
    };
}

#endif
