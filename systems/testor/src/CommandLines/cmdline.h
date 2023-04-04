/**
* @file
* @brief To parse the command-line arguments.
* @license
* Copyright (c) 2023 Yor-Jihons
* Released under the MIT license.
* https://github.com/Yor-Jihons/one_commit__Samples__atcoders/blob/main/systems/testor/LICENSE
*/

#ifndef COMMANDLINES_CMDLINE_H
#define COMMANDLINES_CMDLINE_H

#include<vector>
#include<string>
#include<memory>

namespace Testor::CommandLines{
    /** @brief The class in order to parse the command-line arguments. */
    class CmdLine{
        public:
            /**
            * @brief Creates the vector of std::string, in order to parse easily.
            * @param argc The number of the arguments.
            * @param argv The command-line arguments.
            * @return The vector of std::string (for the command-line) without the this app path.
            * @exception Testor::Exceptions::CmdArgsParsingException The cmd-line arguments are wrong.
            */
            static std::vector<std::string> CreateCmdArgs( int argc, char** argv );

            /**
            * @brief Creates the object of this class, which was parsed.
            * @param args The vector of std::string (for the command-line) without the this app path.
            * @return The unique ptr of this class.
            */
            static std::unique_ptr<CmdLine> Create( const std::vector<std::string>& args );

            /**
            * @brief Constructor.
            * @param cmd The exe-file the user wants to invoke.
            * @param inputFilePath The file path the user wants to pass to the exe-file.
            * @param outputFilePath The file path the answer.
            */
            CmdLine( const std::string& cmd, const std::string& inputFilePath, const std::string& outputFilePath );

            /**
            * @brief Destructor.
            */
            ~CmdLine() = default;

            /**
            * @brief Gets the path of exe-file as a target.
            * @return The path of exe-file as a target.
            */
            std::string Cmd( void ) const;

            /**
            * @brief Gets the file path as input.
            * @return The file path as input.
            */
            std::string InputFilePath( void ) const;

            /**
            * @brief Gets the file path as output.
            * @return the file path as output.
            */
            std::string OutputFilePath( void ) const;
        protected:
            /**
            * @brief Creates the cmdline message to show when the user inputs wrong arguments.
            * @return The message to show when the user inputs wrong arguments.
            */
            static std::string CreateCmdMessage( void );
        private:
            /// @brief The path of exe-file as a target.
            std::string cmd_;

            /// @brief The file path as input
            std::string inputFilePath_;

            /// @brief The file path as output.
            std::string outputFilePath_;
    };
}

#endif
