#include<iostream>
#include<string>
#include"IO/iofile.h"
#include"Processes/process.h"
#include"Exceptions/cmdargsparsingexception.h"
#include"CommandLines/cmdline.h"
#include"Comparision/vectorcomparer.h"
#include"Exceptions/fileopenexception.h"
#include"Exceptions/cmdargsparsingexception.h"


namespace Assertion{
    /**
    * @brief Asserts the data.
    * @param expected The value you expect.
    * @param actual The value actually you got.
    * @param line The number (of the row) which this function called on.
    */
    template<typename T>
    void Assert( T expected, T actual, int line ){
        if( expected == actual ) return;

        std::cout << "Error: " << line << ": Assertion error occured." << std::endl;
        std::cout << "  Expected: " << expected << std::endl;
        std::cout << "  Actual  : " << actual << std::endl;

        std::exit( -1 );
    return;
    }

    /**
    * @brief Asserts the data.
    * @param expected The value you expect.
    * @param actual The value actually you got.
    * @param line The number (of the row) which this function called on.
    */
    template<>
    void Assert<const std::string&>( const std::string& expected, const std::string& actual, int line ){
        if( expected.compare( actual ) == 0 ) return;

        std::cout << "Error: " << line << ": Assertion error occured." << std::endl;
        std::cout << "  Expected: " << expected << std::endl;
        std::cout << "  Actual  : " << actual << std::endl;
        std::exit( -1 );
    return;
    }

    /**
    * @brief Asserts the data.
    * @param expected The value you expect.
    * @param actual The value actually you got.
    * @param line The number (of the row) which this function called on.
    */
    template<>
    void Assert<bool>( bool expected, bool actual, int line ){
        if( expected == actual ) return;

        std::cout << "Error: " << line << ": Assertion error occured." << std::endl;
        std::cout << "  Expected: " << std::boolalpha << expected << std::endl;
        std::cout << "  Actual  : " << std::boolalpha << actual << std::endl;
        std::exit( -1 );
    return;
    }

    /**
    * @brief Asserts whether the actual value is true or not.
    * @param actual The value actually you got.
    * @param line The number (of the row) which this function called on.
    */
    void IsTrue( bool actual, int line ){
        if( actual ) return;

        std::cout << "Error: " << line << ": Assertion error occured." << std::endl;
        std::cout << "  Expected: " << std::boolalpha << true << std::endl;
        std::cout << "  Actual  : " << std::boolalpha << actual << std::endl;
        std::exit( -1 );
    return;
    }

    /**
    * @brief Asserts whether the actual value is false or not.
    * @param actual The value actually you got.
    * @param line The number (of the row) which this function called on.
    */
    void IsFalse( bool actual, int line ){
        if( !actual ) return;

        std::cout << "Error: " << line << ": Assertion error occured." << std::endl;
        std::cout << "  Expected: " << std::boolalpha << false << std::endl;
        std::cout << "  Actual  : " << std::boolalpha << actual << std::endl;
        std::exit( -1 );
    return;
    }
}

namespace SimpleTest{
    void AssertionTest( void ){
        std::string s1 = "xo";
        std::string s2 = "xo";
        Assertion::Assert<const std::string&>( s1, s2, __LINE__ );

        Assertion::Assert( 2, 2, __LINE__ );

        Assertion::Assert<bool>( true, true, __LINE__ );

        Assertion::IsTrue( true, __LINE__ );

        Assertion::IsFalse( false, __LINE__ );
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
        Assertion::Assert<int>( 3, cmdline1.size(), __LINE__ );

        const char* argv2[] = { "main.exe", "english", "japanese", "spanish", "french" };
        auto cmdline2 = Testor::CommandLines::CmdLine::CreateCmdArgs( sizeof(argv2) / sizeof(argv2[0]), const_cast<char**>(argv2) );
        Assertion::Assert<int>( 5, cmdline2.size(), __LINE__ );
    }

    void CreateCmdLineObjectTest( void ){

        const std::string errorMsg = "[CMD]\n$ testor <CMD> <INPUTFILEPATH> <OUTPUTFILEPATH>\n\n[ARGUEMNTS]\n<CMD>:\n    Pass the path of the executive file which you want to run. (Required)\n<INPUTFILE>:\n    Pass the file path as input. (Required)\n<OUTPUTFILE>:\n    Pass the file path as output. (Required)\n";

        // 要素数 4 未満だと例外を投げる
        try{
            // 要素数: 0
            std::vector<std::string> args1;
            std::unique_ptr<Testor::CommandLines::CmdLine> cmdline1 = Testor::CommandLines::CmdLine::Create( args1 );

            Assertion::Assert<const std::string&>( "Somthing Wrong", "", __LINE__ );
        }catch( Testor::Exceptions::CmdArgsParsingException& e ){
            Assertion::Assert<const std::string&>( errorMsg, e.what(), __LINE__ );
        }

        try{
            // 要素数: 2
            std::vector<std::string> args2 = { "test_main.exe", "TargetCmd.exe" };
            std::unique_ptr<Testor::CommandLines::CmdLine> cmdline2 = Testor::CommandLines::CmdLine::Create( args2 );

            Assertion::Assert<const std::string&>( "Somthing Wrong", "", __LINE__ );
        }catch( Testor::Exceptions::CmdArgsParsingException& e ){
            Assertion::Assert<const std::string&>( errorMsg, e.what(), __LINE__ );
        }

        try{
            // 要素数: 3
            std::vector<std::string> args3 = { "test_main.exe", "TargetCmd.exe", "file1.txt"};
            std::unique_ptr<Testor::CommandLines::CmdLine> cmdline3 = Testor::CommandLines::CmdLine::Create( args3 );

            Assertion::Assert<const std::string&>( "Somthing Wrong", "", __LINE__ );
        }catch( Testor::Exceptions::CmdArgsParsingException& e ){
            Assertion::Assert<const std::string&>( errorMsg, e.what(), __LINE__ );
        }

        try{
            // 要素数: 4
            std::vector<std::string> args4 = { "test_main.exe", "TargetCmd.exe", "file1.txt", ".\\bin\\test\\file2.txt" };
            std::unique_ptr<Testor::CommandLines::CmdLine> cmdline4 = Testor::CommandLines::CmdLine::Create( args4 );

            Assertion::Assert<const std::string&>( "TargetCmd.exe", cmdline4->Cmd(), __LINE__ );
            Assertion::Assert<const std::string&>( "file1.txt", cmdline4->InputFilePath(), __LINE__ );
            Assertion::Assert<const std::string&>( ".\\bin\\test\\file2.txt", cmdline4->OutputFilePath(), __LINE__ );
        }catch( Testor::Exceptions::CmdArgsParsingException& e ){
            Assertion::Assert<const std::string&>( "Somthing Wrong", "", __LINE__ );
        }

        try{
            // 要素数: 5
            std::vector<std::string> args5 = { "test_main.exe", "TargetCmd.exe", "file1.txt", ".\\bin\\test\\file2.txt", "dummy" };
            std::unique_ptr<Testor::CommandLines::CmdLine> cmdline5 = Testor::CommandLines::CmdLine::Create( args5 );

            Assertion::Assert<const std::string&>( "TargetCmd.exe", cmdline5->Cmd(), __LINE__ );
            Assertion::Assert<const std::string&>( "file1.txt", cmdline5->InputFilePath(), __LINE__ );
            Assertion::Assert<const std::string&>( ".\\bin\\test\\file2.txt", cmdline5->OutputFilePath(), __LINE__ );
        }catch( Testor::Exceptions::CmdArgsParsingException& e ){
            Assertion::Assert<const std::string&>( "Somthing Wrong", "", __LINE__ );
        }
    }

    void ReadingAllFileTest( void ){
        // ファイルパスが空の場合はExceptions::FileOpenExceptionが投げられる
        try{
            std::string filepath1 = "";
            std::vector<std::string> file1 = Testor::IO::ReadAllFile( filepath1 );

            Assertion::Assert<const std::string&>( "Somthing Wrong", "", __LINE__ );
        }catch( Testor::Exceptions::FileOpenException& e ){
            Assertion::Assert<const std::string&>( "Cannot open the file \"\".", e.what(), __LINE__ );
        }

        // ファイルが開けなかった場合もExceptions::FileOpenExceptionが投げられる
        try{
            std::string filepath2 = "hello.pjx";
            std::vector<std::string> file2 = Testor::IO::ReadAllFile( filepath2 );

            Assertion::Assert<const std::string&>( "Somthing Wrong", "", __LINE__ );
        }catch( Testor::Exceptions::FileOpenException& e ){
            Assertion::Assert<const std::string&>( "Cannot open the file \"hello.pjx\".", e.what(), __LINE__ );
        }

        // ファイルが開けて読み込めた場合は行レベルのvectorが返される
        try{
            std::string filepath3 = ".\\test\\A__Many_A_Plus_B_Problems__input1.txt";
            std::vector<std::string> file3 = Testor::IO::ReadAllFile( filepath3 );

            Assertion::Assert<int>( 5, file3.size(), __LINE__ );

            Assertion::Assert<const std::string&>( "3 5", file3[2 - 1], __LINE__ );
            Assertion::Assert<const std::string&>( "314159265 123456789", file3[5 - 1], __LINE__ );
        }catch( Testor::Exceptions::FileOpenException& e ){
            Assertion::Assert<const std::string&>( "Somthing Wrong", e.what(), __LINE__ );
        }

        // ファイルが開けて読み込めた場合は行レベルのvectorが返される
        try{
            std::string filepath4 = ".\\test\\empty.txt";
            std::vector<std::string> file4 = Testor::IO::ReadAllFile( filepath4 );

            Assertion::Assert<int>( 0, file4.size(), __LINE__ );
        }catch( Testor::Exceptions::FileOpenException& e ){
            Assertion::Assert<const std::string&>( "Somthing Wrong", e.what(), __LINE__ );
        }
    }

    void VectorComparerTest( void ){

        std::vector< std::vector<std::string> > vectors = {
            { "row1", "row2", "row3" }, // ベース
            { "row1", "row2" }, // 末尾が削られている
            { "row1", "row3" }, // 中間値が削られている
            { "x", "row2", "row3" }, // 0番目の値が間違っている
            { "row1", "xp", "row3" }, // 1番目の値が間違っている
            { "row1", "row2\n", "row3" }, // 1番目の値の末尾に改行を示す文字が付いている
            {}, // 空の状態
            { "row1", "row2", "row3\n" }, // 2番目の値の末尾に改行を示す文字が付いている
            { "row1", "row2", "row3" } // 完全一致
        };

        auto vectorComparer1 = std::make_unique<Testor::Comparision::VectorComparer>( false );

        // vectors[0] := { "row1", "row2", "row3" }
        // vectors[6] := {}
        //     => false
        Assertion::IsFalse( vectorComparer1->Compare( vectors[0], vectors[6] ), __LINE__ );
        Assertion::IsFalse( vectorComparer1->Compare( vectors[6], vectors[0] ), __LINE__ );

        // vectors[0] := { "row1", "row2", "row3" }
        // vectors[1] := { "row1", "row2" }
        //     => false
        Assertion::IsFalse( vectorComparer1->Compare( vectors[0], vectors[1] ), __LINE__ );
        Assertion::IsFalse( vectorComparer1->Compare( vectors[1], vectors[0] ), __LINE__ );

        // vectors[0] := { "row1", "row2", "row3" }
        // vectors[2] := { "row1", "row3" }
        //     => false
        Assertion::IsFalse( vectorComparer1->Compare( vectors[0], vectors[2] ), __LINE__ );
        Assertion::IsFalse( vectorComparer1->Compare( vectors[2], vectors[0] ), __LINE__ );

        // vectors[0] := { "row1", "row2", "row3" }
        // vectors[3] := {    "x", "row2", "row3" }
        //     => false
        Assertion::IsFalse( vectorComparer1->Compare( vectors[0], vectors[3] ), __LINE__ );
        Assertion::IsFalse( vectorComparer1->Compare( vectors[3], vectors[0] ), __LINE__ );

        // vectors[0] := { "row1", "row2", "row3" }
        // vectors[4] := { "row1",   "xp", "row3" }
        //     => false
        Assertion::IsFalse( vectorComparer1->Compare( vectors[0], vectors[4] ), __LINE__ );
        Assertion::IsFalse( vectorComparer1->Compare( vectors[4], vectors[0] ), __LINE__ );

        // vectors[0] := { "row1", "row2", "row3" }
        // vectors[5] := { "row1", "row2\n", "row3" }
        //     => false
        Assertion::IsFalse( vectorComparer1->Compare( vectors[0], vectors[5] ), __LINE__ );
        Assertion::IsFalse( vectorComparer1->Compare( vectors[5], vectors[0] ), __LINE__ );

        // vectors[0] := { "row1", "row2", "row3" }
        // vectors[7] := { "row1", "row2", "row3\n" }
        //     => false
        Assertion::IsFalse( vectorComparer1->Compare( vectors[0], vectors[7] ), __LINE__ );
        Assertion::IsFalse( vectorComparer1->Compare( vectors[7], vectors[0] ), __LINE__ );

        // vectors[0] := { "row1", "row2", "row3" }
        // vectors[8] := { "row1", "row2", "row3" }
        //     => true
        Assertion::IsTrue( vectorComparer1->Compare( vectors[0], vectors[8] ), __LINE__ );
        Assertion::IsTrue( vectorComparer1->Compare( vectors[8], vectors[0] ), __LINE__ );
    }

    void CmdArgsParsingExceptionTest( void ){
        try{
            throw Testor::Exceptions::CmdArgsParsingException("Thrown the exception CmdArgsParsingException.");

            Assertion::Assert<const std::string&>( "Somthing Wrong", "", __LINE__ );
        }catch( std::runtime_error& e ){
            Assertion::Assert<const std::string&>( "Thrown the exception CmdArgsParsingException.", e.what(), __LINE__ );
        }catch( ... ){
            Assertion::Assert<const std::string&>( "Somthing Wrong", "", __LINE__ );
        }
    }

    void FileOpenExceptionTest( void ){
        try{
            throw Testor::Exceptions::FileOpenException("Thrown the exception FileOpenException.");

            Assertion::Assert<const std::string&>( "Somthing Wrong", "", __LINE__ );
        }catch( std::runtime_error& e ){
            Assertion::Assert<const std::string&>( "Thrown the exception FileOpenException.", e.what(), __LINE__ );
        }catch( ... ){
            Assertion::Assert<const std::string&>( "Somthing Wrong", "", __LINE__ );
        }
    }
}


int main( void ){
    SimpleTest::AssertionTest();

    Test::CreateCmdArgsTest();
    Test::CreateCmdLineObjectTest();
    Test::ReadingAllFileTest();

    Test::VectorComparerTest();

    Test::CmdArgsParsingExceptionTest();

    Test::FileOpenExceptionTest();
return 0;
}