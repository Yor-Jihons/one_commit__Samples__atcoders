#include<iostream>
#include<string>
#include"IO/iofile.h"
#include"Processes/process.h"
#include"Exceptions/cmdargsparsingexception.h"
#include"CommandLines/cmdline.h"
#include"Comparision/vectorcomparer.h"


namespace Assertion{
    /**
    * @brief Asserts the data.
    * @param expected The value you expect.
    * @param actual The value actually you got.
    */
    template<typename T>
    void Assert( T expected, T actual ){
        if( expected == actual ) return;

        std::cout << "Error: Assertion error occured." << std::endl;
        std::cout << "  Expected:" << expected << std::endl;
        std::cout << "  Actual  :" << actual << std::endl;
    return;
    }

    /**
    * @brief Asserts the data.
    * @param expected The value you expect.
    * @param actual The value actually you got.
    */
    template<>
    void Assert<const std::string&>( const std::string& expected, const std::string& actual ){
        if( expected.compare( actual ) == 0 ) return;

        std::cout << "Error: Assertion error occured." << std::endl;
        std::cout << "  Expected:" << expected << std::endl;
        std::cout << "  Actual  :" << actual << std::endl;
    return;
    }
}

namespace Test{
    void AssertionTest( void ){
        std::string s1 = "xo";
        std::string s2 = "o";
        Assertion::Assert<const std::string&>(s1, s2);

        Assertion::Assert( 1, 2 );
    return;
    }
}

// --------------------------------------------------------------------------------------------------------------- //

using std::cout;
using std::endl;
using std::flush;

namespace Test{
    void CreateCmdArgsTest( void ){
        const char* argv1[] = { "main.exe", "test1", "test2" };
        auto cmdline1 = Testor::CommandLines::CmdLine::CreateCmdArgs( sizeof(argv1) / sizeof(argv1[0]), const_cast<char**>(argv1) );
        Assertion::Assert<int>( 3, cmdline1.size() );

        const char* argv2[] = { "main.exe", "english", "japanese", "spanish", "french" };
        auto cmdline2 = Testor::CommandLines::CmdLine::CreateCmdArgs( sizeof(argv2) / sizeof(argv2[0]), const_cast<char**>(argv2) );
        Assertion::Assert<int>( 5, cmdline2.size() );
    }

    void CreateCmdLineObjectTest( void ){

        const std::string errorMsg = "[CMD]\n$ testor <CMD> <INPUTFILEPATH> <OUTPUTFILEPATH>\n\n[ARGUEMNTS]\n<CMD>:\n    Pass the path of the executive file which you want to run. (Required)\n<INPUTFILE>:\n    Pass the file path as input. (Required)\n<OUTPUTFILE>:\n    Pass the file path as output. (Required)\n";

        // 要素数 4 未満だと例外を投げる
        try{
            // 要素数: 0
            std::vector<std::string> args1;
            std::unique_ptr<Testor::CommandLines::CmdLine> cmdline1 = Testor::CommandLines::CmdLine::Create( args1 );
        }catch( std::exception& e ){
            Assertion::Assert<const std::string&>( errorMsg, e.what() );
        }

        try{
            // 要素数: 2
            std::vector<std::string> args2 = { "test_main.exe", "TargetCmd.exe" };
            std::unique_ptr<Testor::CommandLines::CmdLine> cmdline2 = Testor::CommandLines::CmdLine::Create( args2 );
        }catch( std::exception& e ){
            Assertion::Assert<const std::string&>( errorMsg, e.what() );
        }

        try{
            // 要素数: 3
            std::vector<std::string> args3 = { "test_main.exe", "TargetCmd.exe", "file1.txt"};
            std::unique_ptr<Testor::CommandLines::CmdLine> cmdline3 = Testor::CommandLines::CmdLine::Create( args3 );
        }catch( std::exception& e ){
            Assertion::Assert<const std::string&>( errorMsg, e.what() );
        }

        try{
            // 要素数: 4
            std::vector<std::string> args4 = { "test_main.exe", "TargetCmd.exe", "file1.txt", ".\\bin\\test\\file2.txt" };
            std::unique_ptr<Testor::CommandLines::CmdLine> cmdline4 = Testor::CommandLines::CmdLine::Create( args4 );

            Assertion::Assert<const std::string&>( "TargetCmd.exe", cmdline4->Cmd() );
            Assertion::Assert<const std::string&>( "file1.txt", cmdline4->InputFilePath() );
            Assertion::Assert<const std::string&>( ".\\bin\\test\\file2.txt", cmdline4->OutputFilePath() );
        }catch( std::exception& e ){
            Assertion::Assert<const std::string&>( "Somthing Wrong", "" );
        }

        try{
            // 要素数: 5
            std::vector<std::string> args5 = { "test_main.exe", "TargetCmd.exe", "file1.txt", ".\\bin\\test\\file2.txt", "dummy" };
            std::unique_ptr<Testor::CommandLines::CmdLine> cmdline5 = Testor::CommandLines::CmdLine::Create( args5 );

            Assertion::Assert<const std::string&>( "TargetCmd.exe", cmdline5->Cmd() );
            Assertion::Assert<const std::string&>( "file1.txt", cmdline5->InputFilePath() );
            Assertion::Assert<const std::string&>( ".\\bin\\test\\file2.txt", cmdline5->OutputFilePath() );
        }catch( std::exception& e ){
            Assertion::Assert<const std::string&>( "Somthing Wrong", "" );
        }
    }
}


int main( void ){
    Test::CreateCmdArgsTest();
    Test::CreateCmdLineObjectTest();
return 0;
}