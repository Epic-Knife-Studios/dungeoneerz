// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#include "dungeoneerz/engine/core.hpp"

#include <cstdlib>

namespace Dungeoneerz
{

    namespace Engine
    {

        EngineCore::EngineCore()
        {

            // Initialize logging.
            this->logger = new Logger("engine.log");

            // Initialize Event Manager.
            this->emgr = new EventManager();

        }

        void EngineCore::Start()
        {



        }

        void EngineCore::Stop()
        {

            exit(0);

        }

    }

}
