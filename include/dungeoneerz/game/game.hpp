// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#pragma once

// + Standard Library.

#include <vector>
#include <string>

using std::vector;
using std::string;

// + Dungeoneerz engine & library.

#include "dungeoneerz/lib/event.hpp"

using Dungeoneerz::Library::IEvent;
using Dungeoneerz::Library::IEventHandler;

#include "dungeoneerz/engine/game.hpp"

using Dungeoneerz::Engine::Game;

// + Internal Game

#include "dungeoneerz/game/console.hpp"

using Dungeoneerz::Game::Console;

namespace Dungeoneerz
{

    namespace Game
    {

        // Define the GameHandler class.

        class GameHandler : public IEventHandler
        {

            private:

                Logger* logger;

            public:

                GameHandler(Logger* logger);

                void Handle(IEvent* evt);

                bool Responds(string name);

        };

        // Define the Game class.
        class DungeonGame : public Dungeoneerz::Engine::Game
        {

            public:

                Console* console;

                DungeonGame(Logger* logger, EventManager* emgr);

                virtual void Start();

                virtual void Run();

                virtual void Stop(StopCode sc);

                Dungeoneerz::Engine::Game* GetGame();

        };

    }

}
