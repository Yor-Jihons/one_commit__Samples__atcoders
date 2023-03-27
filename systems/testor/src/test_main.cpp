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
    void AssertionTest(void){
        std::string s1 = "xo";
        std::string s2 = "o";
        Assertion::Assert<const std::string&>(s1, s2);

        Assertion::Assert( 1, 2 );
    return;
    }
}

namespace Test{
    
}


int main( void ){
    //
return 0;
}