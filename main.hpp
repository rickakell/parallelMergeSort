/**
 * \author Richard A. Kell
 * \file main.hpp
 * \brief template function implementation for taking in command line arguments
 */

#include <typeinfo>

template <typename T>
void storeCommandLineArgument(const char* commandLineArgument, T & variableToStoreIn)
{
    istringstream argument(commandLineArgument);
    if(!(argument >> variableToStoreIn))
    {
        cerr << "Invalid Command Line Argument: " << commandLineArgument << endl;
    }
    else if(!argument.eof())
    {
        cerr << "Trailing characters after number: " << commandLineArgument << endl;
    }
}