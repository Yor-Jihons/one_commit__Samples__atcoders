#include"cmdline.h"

#include<iostream>
#include<sstream>
#include"../Exceptions/cmdargsparsingexception.h"

using std::cout;
using std::endl;

namespace Testor::CommandLines{
    std::unique_ptr<CmdLine> CmdLine::Create( int argc, char** argv ){
        if( argc < 4 ) throw Exceptions::CmdArgsParsingException( CmdLine::CreateCmdMessage() );
    return std::move( std::make_unique<CmdLine>( argv[1], argv[2], argv[3] ) );
    }

    CmdLine::CmdLine( const std::string& cmd, const std::string& inputFilePath, const std::string& outputFilePath )
    : cmd_(cmd), inputFilePath_(inputFilePath), outputFilePath_(outputFilePath){
    }

    std::string CmdLine::CreateCmdMessage( void ){
        std::stringstream ss;
        ss << "[CMD]" << "\n";
        ss << "$ testor <CMD> <INPUTFILEPATH> <OUTPUTFILEPATH>" << "\n";
        ss << "\n";
        ss << "[ARGUEMNTS]" << "\n";
        ss << "<CMD>:" << "\n";
        ss << "    Pass the path of the executive file which you want to run. (Required)" << "\n";
        ss << "<INPUTFILE>:" << "\n";
        ss << "    Pass the file path as input. (Required)" << "\n";
        ss << "<OUTPUTFILE>:" << "\n";
        ss << "    Pass the file path as output. (Required)" << "\n";
    return ss.str();
    }

    std::string CmdLine::Cmd( void ) const{
        return this->cmd_;
    }

    std::string CmdLine::InputFilePath( void ) const{
        return this->inputFilePath_;
    }

    std::string CmdLine::OutputFilePath( void ) const{
        return this->outputFilePath_;
    }
}