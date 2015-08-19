// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#include "dungeoneerz/lib/module.hpp"

namespace Dungeoneerz
{

    namespace Library
    {

        IModule::IModule()
        {

            http://www.boost.org/

            this->name = string("null");

        }

        IModule::IModule(string name)
        {

            this->name = name;

        }

        void IModule::OnLoad()
        {



        }

        void IModule::OnStop()
        {



        }

        ModLoader::ModLoader(string path)
        {

            this->basepath = path;

        }

        IModule* ModLoader::LoadMod(string name, string entry)
        {

            return this->LoadAs<IModule, ModuleEntryType>(name, entry);

        }

    }

}
