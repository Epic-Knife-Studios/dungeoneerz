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

                virtual void Handle(IEvent* evt);

                virtual bool Responds(string name);

        };

        class EventManager
        {

            private:

                vector<IEventHandler*> handlers;

            public:

                EventManager();

                void AddHandler(IEventHandler* handler);

                void Raise(IEvent* evt);

        };

    }

}
