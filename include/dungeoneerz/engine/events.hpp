// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#pragma once

#include "dungeoneerz/lib/event.hpp"

using Dungeoneerz::Library::IEvent;
using Dungeoneerz::Library::IEventHandler;
using Dungeoneerz::Library::Logger;

#include <string>

using std::string;

namespace Dungeoneerz
{

    namespace Engine
    {

        class StartEvent : public IEvent
        {

            public:

                StartEvent();

        };

        class StopEvent : public IEvent
        {

            public:

                StopEvent();

        };

        class PreStartEvent : public IEvent
        {

            public:

                PreStartEvent();

        };

        class PreStopEvent : public IEvent
        {

            public:

                PreStopEvent();

        };

        class BaseHandler : public IEventHandler
        {

            private:

                Logger* logger;

            public:

                BaseHandler(Logger* logger);

                void Handle(IEvent* evt);

                bool Responds(string name);

        };

    }

}
