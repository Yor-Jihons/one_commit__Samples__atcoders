#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>
#include"IO/iofile.h"
#include"Processes/process.h"

using namespace std;
using namespace Testor;


int main( int argc, char** argv ){
    // // 1. Parses the command-line arguments, then gains the file-paths as Input and Output.
    // 2. Reads the file as input.
    // 3. Reads the file as output.
    // 4. Compare the lines with (2) and (3).
        // 4.1. If the lines are diference, quit.
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

        // 2. Reads the file as input.
        //auto input = IO::ReadAllFile( inputFilePath );
        auto actuals = Processes::RunProcess( Processes::Process::CreateCmd( cmd, inputFilePath ) );

        for( int i = 0; i < actuals.size(); i++ ){
            cout <<  i << ":" << actuals[i] << endl;
        }

        // 3. Reads the file as input.
        auto expected = IO::ReadAllFile( outputFilePath );


    }catch( std::exception& e ){
        cout << e.what() << endl;
    }
return 0;
}
