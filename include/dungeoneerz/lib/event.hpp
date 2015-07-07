#pragma once

#include <vector>
#include <string>

using std::vector;
using std::string;

namespace Dungeoneerz
{

    namespace Library
    {

        class IEvent
        {

            protected:

                string name;

                IEvent(string name);

            public:

                IEvent();

                string GetName();

        };

        class IEventHandler
        {

            public:

                int Handle(IEvent evt);

                bool Responds(string name);

        };

        class EventManager
        {

            private:

                vector<IEventHandler> handlers;

            public:

                EventManager();

                bool AddHandler(IEventHandler handler);

                void Raise(IEvent evt);

        };

    }

}
