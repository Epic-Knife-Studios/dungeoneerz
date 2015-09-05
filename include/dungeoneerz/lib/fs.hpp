// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#pragma once

#include <cstdio>

#include <sys/stat.h>

#include <string>

using std::string;

namespace Dungeoneerz
{

    namespace Library
    {

        namespace FileSystem
        {

            bool ExistsFile(string path);

        }

    }

}
