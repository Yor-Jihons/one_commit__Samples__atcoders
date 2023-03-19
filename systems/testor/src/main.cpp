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
        auto cmdline = CommandLines::CmdLine::Create( argc, argv );

        // 2. Reads the file as input.
        auto actuals = Processes::RunProcess( Processes::Process::CreateCmd( cmdline->Cmd(), cmdline->InputFilePath() ) );

        // 3. Reads the file as input.
        auto expected = IO::ReadAllFile( cmdline->OutputFilePath() );

        // 4. Compare (2) and (3).
        // TODO: 関数かクラスとして切り出す
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
