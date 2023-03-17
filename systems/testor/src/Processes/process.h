#ifndef PROCESSES_PROCESS_H
#define PROCESSES_PROCESS_H

#include<string>
#include<vector>

namespace Testor::Processes{
    class Process{
        public:
            Process( const std::string& cmd, bool allowed2ThrowException = false );
            ~Process();
            bool IsAlive( void ) const;
            bool IsFeof( void ) const;
            bool FetchStdOutValue( std::string& result );

            static std::string CreateCmd( const std::string& cmd, const std::string& inputfilepath );
        private:
            FILE* fp_;
    };

    std::vector<std::string> RunProcess( const std::string& cmd );
}

#endif
