// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#include "dungeoneerz/lib/module.hpp"

namespace Dungeoneerz
{

    namespace Library
    {

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

        template<typename T, typename F> T ModLoader::LoadAs(string name, string entry)
        {

            char* error;

            T mod = (T)NULL;

            void* handle = dlopen(
                (this->basepath + string("/") + name + string(".so")).c_str(),
                RTLD_LAZY | RTLD_GLOBAL
            );

            if((error = dlerror()) != NULL)
            {

                return mod;

            }

            F runme = (F)dlsym(handle, entry.c_str());

            if((error = dlerror()) != NULL)
            {

                mod = runme();

            }

            return mod;

        }

        IModule* ModLoader::LoadMod(string name, string entry)
        {

            return this->LoadAs<IModule*, ModuleEntryType>(name, entry);

        }

    }

}
