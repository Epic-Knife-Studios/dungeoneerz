// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#include "dungeoneerz/game/game.hpp"

#include <string>

#include <unistd.h>

using Dungeoneerz::Library::Window;

namespace Dungeoneerz
{

    namespace Game
    {
    
        Game::Game()
        {
            
            this->window = new Window();
            this->logger = new Logger(std::string("dungeon.log"));
            
        }
        
        void Game::Start()
        {
        
            this->logger->Log("dungeoneerz", "Dungeoneerz starting...");
        
        }
        
        void Game::Run()
        {
        
            sleep(1);
            
            this->logger->Log("dungeoneerz", "Dungeoneerz running...");
            
            sleep(2);
        
        }
        
        void Game::Stop()
        {
        
            this->logger->Log("dungeoneerz", "Dungeoneerz stopping...");
        
        }
    
    }

}
