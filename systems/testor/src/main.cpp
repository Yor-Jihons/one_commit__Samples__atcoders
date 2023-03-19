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

using namespace std;
using namespace Testor;


int main( int argc, char** argv ){
    try{
        // 1. Parses the command-line arguments, then gains the file path as input and output.
        if( argc < 4 ){
            cout << "[CMD]" << endl;
            cout << "$ testor <CMD> <INPUTFILEPATH> <OUTPUTFILEPATH>" << endl;
            cout << endl;
            cout << "[ARGUEMNTS]" << endl;
            cout << "<CMD>:" << endl;
            cout << "    Pass the path of the executive file which you want to run. (Required)" << endl;
            cout << "<INPUTFILE>:" << endl;
            cout << "    Pass the file path as input. (Required)" << endl;
            cout << "<OUTPUTFILE>:" << endl;
            cout << "    Pass the file path as output. (Required)" << endl;
            return -1;
        }
        std::string cmd            = argv[1];
        std::string inputFilePath  = argv[2];
        std::string outputFilePath = argv[3];

        auto cmdline = CommandLines::CmdLine::Create( argc, argv );

        cout << "CMD    : " << cmdline->Cmd() << endl;
        cout << "INPUT  : " << cmdline->InputFilePath() << endl;
        cout << "OUTPUT : " << cmdline->OutputFilePath() << endl;

        // 2. Reads the file as input.
        //auto input = IO::ReadAllFile( inputFilePath );
        auto actuals = Processes::RunProcess( Processes::Process::CreateCmd( cmd, inputFilePath ) );

        // 3. Reads the file as input.
        auto expected = IO::ReadAllFile( outputFilePath );

        // 4. Compare (2) and (3).
        if( actuals.size() != expected.size() ){
            cout << "Error" << endl;
            return -1;
        }
        for( int i = 0; i < static_cast<int>(actuals.size()); i++ ){
            if( actuals[i].compare( expected[i] ) != 0 ){
                cout << actuals[i] << "," << expected[i] << "," << endl;
                return -1;
            }
        }

        cout << "OK" << endl;

    }catch( std::exception& e ){
        cout << e.what() << endl;
    }
return 0;
}
