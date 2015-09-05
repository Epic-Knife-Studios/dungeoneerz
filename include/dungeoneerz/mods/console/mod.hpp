// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#pragma once

#include "dungeoneerz/lib/module.hpp"
#include "dungeoneerz/lib/logger.hpp"
#include "dungeoneerz/lib/event.hpp"

#include "dungeoneerz/engine/events.hpp"

#include "dungeoneerz/mods/console/interface.hpp"

using Dungeoneerz::Library::IModule;
using Dungeoneerz::Library::Logger;
using Dungeoneerz::Library::IEvent;
using Dungeoneerz::Library::IEventHandler;

using Dungeoneerz::Engine::ModuleSignalEvent;

using Dungeoneerz::Mods::ConsoleMod;
using Dungeoneerz::Mods::ConsoleModInfo;

namespace Dungeoneerz
{

    namespace Mods
    {

        class ConsoleModHandler : public IEventHandler
        {

            private:

                ConsoleMod* mod;

            public:

                ConsoleModHandler(ConsoleMod* mod);

                virtual void Handle(IEvent* evt);

                virtual bool Responds(string name);

        };

        class ConsoleModule : public IModule
        {

            public:

                ConsoleModule();

                virtual void OnLoad();

                virtual void OnStop();

        };

    }

}
