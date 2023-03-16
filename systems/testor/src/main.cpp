#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<memory>
#include<limits>
#include"IO/iofile.h"

using namespace std;
using namespace Testor;


int main( int argc, char** argv ){
    // // 1. Parses the command-line arguments, then gains the file-paths as Input and Output.
    // 2. Reads the file as input.
    // 3. Reads the file as output.
    // 4. Compare the lines with (2) and (3).
        // 4.1. If the lines are diference, quit.

    if( argc < 3 ){
        cout << "[CMD]" << endl;
        cout << "$ testor <INPUTFILEPATH> <OUTPUTFILEPATH>" << endl;
        cout << endl;
        cout << "[ARGUEMNTS]" << endl;
        cout << "<INPUTFILE>:" << endl;
        cout << "    Pass the file path as input. (Required)" << endl;
        cout << "<OUTPUTFILE>:" << endl;
        cout << "    Pass the file path as output. (Required)" << endl;
        return -1;
    }

    std::string inputFilePath  = argv[1];
    std::string outputFilePath = argv[2];

    std::vector<std::string> input = IO::ReadAllFile( inputFilePath );

    for( int i = 0; i < input.size(); i++ ) cout << input[i] << endl;
return 0;
}
