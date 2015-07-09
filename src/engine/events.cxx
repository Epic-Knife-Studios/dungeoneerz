#include "dungeoneerz/engine/events.hpp"

#include <string>

#include <cstdio>

#include "dungeoneerz/lib/event.hpp"
#include "dungeoneerz/lib/logger.hpp"

using std::string;

using Dungeoneerz::Library::IEvent;
using Dungeoneerz::Library::IEventHandler;
using Dungeoneerz::Library::Logger;

namespace Dungeoneerz
{

    namespace Engine
    {

        StartEvent::StartEvent() : IEvent()
        {

            this->name = string("core/start");

        }

        StopEvent::StopEvent() : IEvent()
        {

            this->name = string("core/stop");

        }

        BaseHandler::BaseHandler(Logger* logger) : IEventHandler()
        {

            this->logger = logger;

        }

        void BaseHandler::Handle(IEvent* evt)
        {

            if(!this->Responds(evt->GetName()))
            {
                return;
            }

            if(evt->GetName() == string("core/start"))
            {
                this->logger->Log("engine", "Starting...");
            }

            if(evt->GetName() == string("core/stop"))
            {
                this->logger->Log("engine", "Stopping...");
            }

        }

        bool BaseHandler::Responds(string name)
        {

            if(name == string("core/start"))
            {
                return true;
            }
            else if (name.compare("core/stop"))
            {
                return true;
            }
            else
            {
                return false;
            }

        }

    }

}
