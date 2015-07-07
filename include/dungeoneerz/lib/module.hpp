#pragma once

#include <string>

#include <dlfcn.h>

using std::string;

namespace Dungeoneerz
{

    namespace Library
    {

        class IModule
        {

            public:

                IModule();

                int Version();

                string Name();

        };

    }

}
