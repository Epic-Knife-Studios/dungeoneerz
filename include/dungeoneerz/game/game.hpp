// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#pragma once

#include "dungeoneerz/lib/window.hpp"
#include "dungeoneerz/lib/logger.hpp"

using Dungeoneerz::Library::Window;
using Dungeoneerz::Library::Logger;
    
namespace Dungeoneerz
{
    
    namespace Game
    {
    
        class Game
        {
            
            private:
                Window* window;
                Logger* logger;

            public:
                Game();
                
                void Start();
                void Run();
                void Stop();
        };
    
    }
    
}
