#ifndef COMMANDLINES_CMDLINE_H
#define COMMANDLINES_CMDLINE_H

#include<vector>
#include<string>
#include<memory>

namespace Testor::CommandLines{
    class CmdLine{
        public:
            static std::unique_ptr<CmdLine> Create( int argc, char** argv );
            CmdLine( const std::string& cmd, const std::string& inputFilePath, const std::string& outputFilePath );
            ~CmdLine() = default;

            std::string Cmd( void ) const;
            std::string InputFilePath( void ) const;
            std::string OutputFilePath( void ) const;
        protected:
            static std::string CreateCmdMessage( void );
        private:
            std::string cmd_;
            std::string inputFilePath_;
            std::string outputFilePath_;
    };
}

#endif
