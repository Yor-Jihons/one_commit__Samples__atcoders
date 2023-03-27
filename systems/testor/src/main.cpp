#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>
#include"IO/iofile.h"
#include"Processes/process.h"
#include"Exceptions/cmdargsparsingexception.h"
#include"CommandLines/cmdline.h"
#include"Comparision/vectorcomparer.h"

using namespace std;
using namespace Testor;


int main( int argc, char** argv ){
    try{
        // 1. Parses the command-line arguments, then gains the file path as input and output.
        auto cmdArgs = CommandLines::CmdLine::CreateCmdArgs( argc, argv );
        auto cmdline = CommandLines::CmdLine::Create( cmdArgs );

        // 2. Reads the file as input.
        auto actuals = Processes::RunProcess( Processes::Process::CreateCmd( cmdline->Cmd(), cmdline->InputFilePath() ) );

        // 3. Reads the file as input.
        auto expected = IO::ReadAllFile( cmdline->OutputFilePath() );

        // 4. Compare (2) and (3).
        auto comparer = std::make_unique<Comparision::VectorComparer>( true );
        if( !comparer->Compare( expected, actuals ) ){
            cout << "Error" << endl;
            return -2;
        }

        cout << "OK" << endl;

    }catch( std::exception& e ){
        cout << e.what() << endl;
        return -1;
    }
return 0;
}
