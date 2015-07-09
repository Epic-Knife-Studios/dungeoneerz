#pragma once

#include <string>

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
