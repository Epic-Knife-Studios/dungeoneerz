// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#pragma once

#include "dungeoneerz/lib/event.hpp"
#include "dungeoneerz/lib/logger.hpp"
#include "dungeoneerz/engine/events.hpp"

using Dungeoneerz::Engine::BaseHandler;
using Dungeoneerz::Engine::StartEvent;
using Dungeoneerz::Engine::StopEvent;

using Dungeoneerz::Library::EventManager;
using Dungeoneerz::Library::Logger;

namespace Dungeoneerz
{

    namespace Engine
    {

        class EngineCore
        {

            public:

                Logger* logger;

                EventManager* emgr;

                EngineCore();

                virtual void Start();

                virtual void Stop();

        };

    }

}
