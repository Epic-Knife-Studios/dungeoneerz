// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#pragma once

#include <dlfcn.h>

#include <string>

using std::string;

#include "dungeoneerz/lib/fs.hpp"

using Dungeoneerz::Library::FileSystem::ExistsFile;

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

                virtual void OnStart();

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

            // Mac OS X library naming convention.



            void* handle = dlopen(
                (this->basepath + string("/lib") + name + string(".dylib")).c_str(),
                RTLD_LAZY | RTLD_GLOBAL
            );

            if((error = dlerror()) != NULL)
            {

                dlerror();

                // Linux library naming convention.

                handle = dlopen(
                    (this->basepath + string("/lib") + name + string(".so")).c_str(),
                    RTLD_LAZY | RTLD_GLOBAL
                );

                if((error = dlerror()) != NULL)
                {

                    dlerror();

                    // Windows library naming convention.

                    handle = dlopen(
                        (this->basepath + string("/") + name + string(".dll")).c_str(),
                        RTLD_LAZY | RTLD_GLOBAL
                    );

                    if((error = dlerror()) != NULL)
                    {

                        dlerror();

                        // Cygwin library naming convention.

                        handle = dlopen(
                            (this->basepath + string("/cy") + name + string(".dll")).c_str(),
                            RTLD_LAZY | RTLD_GLOBAL
                        );

                        if((error = dlerror()) != NULL)
                        {

                            dlerror();

                            // Dungeoneerz library naming convention.

                            handle = dlopen(
                                (this->basepath + string("/") + name + string(".dmod")).c_str(),
                                RTLD_LAZY | RTLD_GLOBAL
                            );

                            if((error = dlerror()) != NULL)
                            {

                                return (T*)mod;

                            }

                        }

                    }

                }

            }

            F runme = (F)NULL;

            runme = (F)dlsym(handle, entry.c_str());

            if(runme == (F)NULL)
            {

                return (T*)NULL;

            }

            mod = runme();

            return mod;

        }


    }

}
