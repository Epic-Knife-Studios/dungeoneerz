// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#ifndef DUNGEON_HEADER_INCLUDED
#include "dungeoneerz/engine/dungeon.hpp"
#endif

using Dungeoneerz::Library::IEvent;
using Dungeoneerz::Library::IEventHandler;
using Dungeoneerz::Library::Logger;

#include <cstdio>

#include <string>

using std::string;

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

        PreStartEvent::PreStartEvent() : IEvent()
        {

            this->name = string("core/prestart");

        }

        PreStopEvent::PreStopEvent() : IEvent()
        {

            this->name = string("core/prestop");

        }

        ModuleSignalEvent::ModuleSignalEvent(string function, void* arguments) : IEvent()
        {

            this->name = string("core/modsignal");

            this->function = function;

            this->arguments = arguments;

        }

        string ModuleSignalEvent::GetFunction()
        {

            return this->function;

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

            if(
                name == string("core/start") ||
                name == string("core/stop")
            )
            {
                return true;
            }

            return false;

        }

    }

}
