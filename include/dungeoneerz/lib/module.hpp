// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

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

                string name;

                IModule();

                IModule(string name);

                virtual void OnLoad();

                virtual void OnStop();

        };

        typedef IModule* (*ModuleEntryType)();

        class ModLoader
        {

            private:

                string basepath;

            public:

                ModLoader(string path);

                template<class T, class F> T* LoadAs(string name, string entry);

                IModule* LoadMod(string name, string entry);

        };

        template<class T, class F> T* ModLoader::LoadAs(string name, string entry)
        {

            char* error;

            T* mod = (T*)NULL;

            void* handle = dlopen(
                (this->basepath + string("/lib") + name + string(".dylib")).c_str(),
                RTLD_LAZY | RTLD_GLOBAL
            );

            if((error = dlerror()) != NULL)
            {

                dlerror();

                handle = dlopen(
                    (this->basepath + string("/lib") + name + string(".so")).c_str(),
                    RTLD_LAZY | RTLD_GLOBAL
                );

                if((error = dlerror()) != NULL)
                {

                    dlerror();

                    handle = dlopen(
                        (this->basepath + string("/") + name + string(".dll")).c_str(),
                        RTLD_LAZY | RTLD_GLOBAL
                    );

                    if((error = dlerror()) != NULL)
                    {

                        return (T*)mod;

                    }

                }

            }

            F runme = (F)dlsym(handle, entry.c_str());

            mod = runme();

            return mod;

        }

    }

}
