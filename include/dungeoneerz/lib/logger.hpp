// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#pragma once

#include <string>

#include <cstdio>

#include <ctime>

using std::string;

namespace Dungeoneerz
{

    namespace Library
    {

        class Logger
        {

            private:
                long int ltime;
                FILE* out;

            public:
                Logger(string location);

                void Log(string sender, string message);

        };

    }

}
