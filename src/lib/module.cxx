#include "dungeoneerz/lib/module.hpp"

namespace Dungeoneerz
{

    namespace Library
    {

        IModule::IModule()
        {

        }

        int IModule::Version()
        {
            return 1;
        }

        string IModule::Name()
        {
            return "null";
        }

    }

}
