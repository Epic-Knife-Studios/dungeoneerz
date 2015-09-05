// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#pragma once

// + Configuration

#include "dungeoneerz/config.h"

// + Dungeoneerz engine & library.

#include "dungeoneerz/lib/logger.hpp"

using Dungeoneerz::Library::Logger;

#include "dungeoneerz/engine/events.hpp"
#include "dungeoneerz/engine/core.hpp"

using Dungeoneerz::Engine::BaseHandler;
using Dungeoneerz::Engine::StartEvent;
using Dungeoneerz::Engine::StopEvent;
using Dungeoneerz::Engine::PreStartEvent;
using Dungeoneerz::Engine::PreStopEvent;
using Dungeoneerz::Engine::EngineCore;

// Define StopCode type

typedef int StopCode;

// Define StopCode constants

#define GAME_STOP_EVENTUALLY 1
#define GAME_STOP_SOON 2
#define GAME_STOP_NOW 3

namespace Dungeoneerz
{

    namespace Engine
    {

        class Game
        {

            public:

                Logger* logger;

                EventManager* emgr;

                Game(Logger* logger, EventManager* emgr);

                virtual void Start();

                virtual void Run();

                virtual void Stop(StopCode sc);

        };

        class GameEngine : public EngineCore
        {

            public:

                Game* game;

                GameEngine();

                virtual void Start();

                virtual void Stop();

                EngineCore* GetEngineCore();

        };

    }

}
