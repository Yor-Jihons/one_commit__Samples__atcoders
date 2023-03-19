#ifndef EXCEPTIONS_FileOpenException_H
#define EXCEPTIONS_FileOpenException_H

#include<exception>
#include<string>

namespace Testor::Exceptions{
    class FileOpenException : public std::runtime_error{
        public:
            FileOpenException( const std::string& msg ) : std::runtime_error(msg.c_str()){}
    };
}

#endif
