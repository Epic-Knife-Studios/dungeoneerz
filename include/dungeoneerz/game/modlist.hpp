// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

#include "dungeoneerz/lib/logger.hpp"
#include "dungeoneerz/lib/module.hpp"

#include "dungeoneerz/engine/dungeon.hpp"

using Dungeoneerz::Library::Logger;
using Dungeoneerz::Library::IModule;

namespace Dungeoneerz
{

    namespace Game
    {

        class ModList
        {

            private:

                vector<IModule*> mods;

            public:

                ModList();

                void Add(IModule* mod);

                bool Contains(string name);

                IModule* Get(string name);

                bool Start(string name);

                void StartAll();

                bool Stop(string name);

                void StopAll();

                bool Reload(string name);

                void ReloadAll();

        };

    }

}
