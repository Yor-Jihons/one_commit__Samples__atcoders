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
}


int main( void ){
    Test::CreateCmdArgsTest();
return 0;
}