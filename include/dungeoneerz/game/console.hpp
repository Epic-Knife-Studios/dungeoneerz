// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#pragma once

#include <cstdio>

#include <vector>
#include <string>

using std::vector;
using std::string;

#include "dungeoneerz/lib/event.hpp"
#include "dungeoneerz/engine/dungeon.hpp"
#include "dungeoneerz/engine/game.hpp"

using Dungeoneerz::Library::IEvent;
using Dungeoneerz::Library::IEventHandler;
using Dungeoneerz::Library::EventManager;
using Dungeoneerz::Library::Logger;
using Dungeoneerz::Engine::GameEngine;

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

                string cmd;

            public:

                ConsoleCommandEvent(string cmd);

                string GetCommand();

        };

        class ConsoleCommandPrinter : public IEventHandler
        {

            private:

                Logger* logger;

            public:

                ConsoleCommandPrinter(Logger* logger);

                void Handle(IEvent* evt);

                bool Responds(string name);

        };

    }

}
