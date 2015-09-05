// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#pragma once

#include <cstdio>

#include <vector>
#include <string>

using std::vector;
using std::string;
using std::to_string;

#include "dungeoneerz/lib/event.hpp"
#include "dungeoneerz/lib/logger.hpp"
#include "dungeoneerz/lib/module.hpp"
#include "dungeoneerz/lib/util.hpp"
#include "dungeoneerz/engine/dungeon.hpp"
#include "dungeoneerz/engine/game.hpp"
#include "dungeoneerz/game/modlist.hpp"

using Dungeoneerz::Library::IEvent;
using Dungeoneerz::Library::IEventHandler;
using Dungeoneerz::Library::EventManager;
using Dungeoneerz::Library::Logger;
using Dungeoneerz::Library::IModule;
using Dungeoneerz::Library::ModLoader;
using Dungeoneerz::Library::ModuleEntryType;
using Dungeoneerz::Library::Util::CharIsWhitespace;

using Dungeoneerz::Engine::GameEngine;

using Dungeoneerz::Game::ModList;

typedef int ReadCode;

#define CONSOLE_CODE_OK 1
#define CONSOLE_CODE_ERR 2
#define CONSOLE_CODE_DIE 3

namespace Dungeoneerz
{

    namespace Game
    {

        class Console
        {

            private:

                Logger* logger;

                EventManager* emgr;

            public:

                Console(Logger* logger, EventManager* emgr);

                ReadCode Read();

        };

        class ConsoleCommandEvent : public IEvent
        {

            private:

                string rawcmd;

                string cmd;

                vector<string> arguments;

            public:

                ConsoleCommandEvent(string cmd);

                string GetRawCommand();

                string GetCommand();

                vector<string> GetArguments();

        };

        class ConsoleCommandPrinter : public IEventHandler
        {

            private:

                Logger* logger;

                ModLoader* loader;

                ModList* mods;

            public:

                ConsoleCommandPrinter(Logger* logger);

                void Handle(IEvent* evt);

                bool Responds(string name);

        };

    }

}
