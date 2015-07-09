#include "dungeoneerz/lib/event.hpp"

#include <cstdio>
#include <string.h>

namespace Dungeoneerz
{

    namespace Library
    {

        IEvent::IEvent(string name)
        {
            this->name = name;
        }

        IEvent::IEvent()
        {
            this->name = "default";
        }

        string IEvent::GetName()
        {
            return this->name;
        }

        void IEventHandler::Handle(IEvent* evt)
        {

        }

        bool IEventHandler::Responds(string name)
        {
            return false;
        }

        EventManager::EventManager()
        {
            this->handlers = vector<IEventHandler*>();
        }

        void EventManager::AddHandler(IEventHandler* handler)
        {
            this->handlers.push_back(handler);
        }

        void EventManager::Raise(IEvent* evt)
        {
            for(int i = 0; i < this->handlers.size(); i++)
            {
                this->handlers[i]->Handle(evt);
            }
        }

    }

}
