#pragma once

#include <string>

#include <dlfcn.h>

using std::string;

namespace Dungeoneerz
{

    namespace Library
    {

        class Library
        {

            public:

                Library();

                bool Load(string path);

        };

    }

}
