// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#pragma once

#include <cstdlib>
#include <cstdio>

#include <string>
#include <vector>

#ifndef NON_POSIX
    #include <unistd.h>
#endif

using std::string;
using std::vector;

namespace Dungeoneerz
{

    namespace Library
    {

        namespace Util
        {

            bool CharIsNumber(char c);
            int GetNumberOfChar(char c);
            bool CharIsNumeric(char c);

            bool StrIsNumeric(string str);
            string StrAsNumber(string str);
            string StrAsNumeric(string str);
            int StrParseInt(string str);

            vector<char> StrToBytes(string str);
            string BytesToStr(vector<char> bytes);

            void MilliSleep(int ms);
            void Sleep(int s);

        }

    }

}
