// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#pragma once

#include "dungeoneerz/lib/logger.hpp"
#include "dungeoneerz/lib/event.hpp"

using Dungeoneerz::Library::Logger;
using Dungeoneerz::Library::IEvent;
using Dungeoneerz::Library::EventManager;

namespace Dungeoneerz
{

    namespace Mods
    {

        struct ConsoleModInfo
        {

            Logger* logger;
            EventManager* emgr;

        };

        struct ConsoleMod
        {

            ConsoleModInfo* info;

            void (*construct) (ConsoleModInfo* info);

        };

    }

}
