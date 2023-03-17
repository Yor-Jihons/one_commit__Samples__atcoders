#include"process.h"
#include<array>
#include<iostream>
#include<sstream>
#include<memory>

namespace Testor::Processes{
    Process::Process( const std::string& cmd, bool allowed2ThrowException ) : fp_(nullptr){
        this->fp_ = _popen( cmd.c_str(), "r");

        if( allowed2ThrowException && !this->fp_ ) throw std::exception();
    }

    Process::~Process(){
        _pclose( this->fp_ );
    }

    bool Process::IsAlive( void ) const{
        return ( !this->fp_ ? false : true);
    }

    bool Process::IsFeof( void ) const{
        return ( feof( this->fp_ ) ? true : false);
    }

    bool Process::FetchStdOutValue( std::string& result ){
        std::array<char, 256> buf;
        if( fgets( buf.data(), buf.size(), this->fp_ ) == nullptr ){
            result = "";
            return false;
        }
        result = buf.data();
        return true;
    }

    std::string Process::CreateCmd( const std::string& cmd, const std::string& inputfilepath ){
        std::stringstream ss;
        ss << cmd << " " << inputfilepath;
    return ss.str();
    }


    std::vector<std::string> RunProcess( const std::string& cmd ){
        std::vector<std::string> ret;
        auto process = std::make_unique<Process>( cmd, true );
        while( !process->IsFeof() ){
            std::string out;
            if( process->FetchStdOutValue( out ) ){
                ret.push_back( out );
            }
        }
    return ret;
    }
}