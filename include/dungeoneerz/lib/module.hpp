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

                template<typename T, typename F> T LoadAs(string name, string entry);

                IModule* LoadMod(string name, string entry);

        };

    }

}
