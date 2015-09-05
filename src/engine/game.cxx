// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#include "dungeoneerz/engine/game.hpp"

#include <cstdlib>

namespace Dungeoneerz
{

    namespace Engine
    {

        Game::Game(Logger* logger, EventManager* emgr)
        {

            this->logger = logger;

            this->emgr = emgr;

        }

        void Game::Start()
        {

            this->logger->Log(
                string("Game"),
                string("Starting Dungeoneerz ") +
                DUNGEON_VERSION_S +
                string(".") +
                DUNGEON_REVISION_S +
                string("...")
            );

        }

        void Game::Run()
        {

            this->logger->Log(string("Game"), string("Running!"));

        }

        void Game::Stop(StopCode sc)
        {

            switch((int)sc)
            {

                case GAME_STOP_EVENTUALLY:
                    this->logger->Log(string("Game"), string("Stopping eventually..."));
                    break;
                case GAME_STOP_SOON:
                    this->logger->Log(string("Game"), string("Stopping soon.."));
                    break;
                case GAME_STOP_NOW:
                    this->logger->Log(string("Game"), string("Stopping now!"));
                    break;
                default:
                    this->logger->Log(string("Game"), string("Stopping"));
                    break;

            }

        }

        GameEngine::GameEngine()
        {

            // Initialize logging.
            this->logger = new Logger("engine.log");

            // Initialize Event Manager.
            this->emgr = new EventManager();

            this->game = new Game(this->logger, this->emgr);

        }

        void GameEngine::Start()
        {

            this->game->Start();

            this->emgr->Raise(new PreStartEvent());

            this->emgr->Raise(new StartEvent());

        }

        void GameEngine::Stop()
        {

            this->game->Stop(GAME_STOP_EVENTUALLY);

            this->emgr->Raise(new PreStopEvent());

            this->game->Stop(GAME_STOP_SOON);

            this->emgr->Raise(new StopEvent());

            this->game->Stop(GAME_STOP_NOW);

            exit(0);

        }

        EngineCore* GameEngine::GetEngineCore()
        {

            return ((EngineCore*)this);

        }

    }

}
