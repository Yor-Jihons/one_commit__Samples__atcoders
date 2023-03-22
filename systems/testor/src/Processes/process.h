/**
* @file
* @brief To run the command, to gain the standard output of it.
*/

#ifndef PROCESSES_PROCESS_H
#define PROCESSES_PROCESS_H

#include<string>
#include<vector>

namespace Testor::Processes{
    /// @brief The class in order to run the command, and to gain the standard output of it.
    class Process{
        public:
            /**
            * @brief Constructor.
            * @param cmd The commnd you want to run.
            * @param allowed2ThrowException Whether this object shows the message when the error occured or not. (def: false)
            */
            Process( const std::string& cmd, bool allowed2ThrowException = false );

            /**
            * @brief Destructor.
            */
            ~Process();

            /**
            * @brief Gets whether this object is alive or not.
            * @return Returns true if you can use this object, otherwise returns false.
            */
            bool IsAlive( void ) const;

            /**
            * @brief Gets whether now is EOF or not.
            * @return Returns true if now is EOF, otherwise returns false.
            */
            bool IsFeof( void ) const;

            /**
            * @brief Fetches the standard output value.
            * @param result As return values, as standard output values.
            * @return Returns true if this can invoke the cmd normaly, otherwise false.
            */
            bool FetchStdOutValue( std::string& result );

            /**
            * @brief Creates the string cmd.
            * @param cmd The cmd you want to invoke.
            * @param inputFilepath The input file path you want to pass to the cmd.(as an standard input)
            * @return The string cmd.
            * e.g. "main.exe" + "input1.txt" => "main.exe input1.txt"
            */
            static std::string CreateCmd( const std::string& cmd, const std::string& inputfilepath );
        private:
            /// @brief The pointer of the file.
            FILE* fp_;
    };

    /**
    * @brief Runs the cmd and gets the starndard output values.
    */
    std::vector<std::string> RunProcess( const std::string& cmd );
}

#endif
