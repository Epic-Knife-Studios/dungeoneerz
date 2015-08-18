// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#include "dungeoneerz/game/game.hpp"

namespace Dungeoneerz
{

    namespace Game
    {

        GameHandler::GameHandler(Logger* logger)
        {

            this->logger = logger;

        }

        void GameHandler::Handle(IEvent* evt)
        {

            if(evt->GetName() == string("core/start"))
            {
                this->logger->Log(
                    string("Events"),
                    string("Event manager started!")
                );
            }

            if(evt->GetName() == string("core/stop"))
            {
                this->logger->Log(
                    string("Events"),
                    string("Event manager stopped!")
                );
            }

        }

        bool GameHandler::Responds(string name)
        {

            return (
                name == string("core/start") ||
                name == string("core/stop")
            );

        }

        DungeonGame::DungeonGame(Logger* logger, EventManager* emgr) : Dungeoneerz::Engine::Game(logger, emgr)
        {

            this->logger = logger;

            this->emgr = emgr;

            this->console = new Console(logger, emgr);

        }

        void DungeonGame::Start()
        {

            this->logger->Log(string("Game"), string("Starting..."));

            this->emgr->AddHandler(new GameHandler(this->logger));

        }

        void DungeonGame::Run()
        {

            this->logger->Log(string("Game"), string("Running!"));

            ReadCode rc;

            this->logger->Log(string("Game"), string("Loading Console..."));

            do {
                rc = this->console->Read();
            } while(rc != CONSOLE_CODE_DIE);

        }

        void DungeonGame::Stop(StopCode sc)
        {

            switch((int)sc)
            {

                case GAME_STOP_EVENTUALLY:
                    //this->logger->Log(string("Game"), string("Stopping eventually..."));
                    break;
                case GAME_STOP_SOON:
                    //this->logger->Log(string("Game"), string("Stopping soon.."));
                    break;
                case GAME_STOP_NOW:
                    this->logger->Log(string("Game"), string("Stopping now!"));
                    break;
                default:
                    //this->logger->Log(string("Game"), string("Stopping"));
                    break;

            }

        }

        Dungeoneerz::Engine::Game* DungeonGame::GetGame()
        {

            return ((Dungeoneerz::Engine::Game*)this);

        }

    }

}
