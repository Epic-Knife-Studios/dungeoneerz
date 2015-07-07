#include "dungeoneerz/lib/event.hpp"

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

        int IEventHandler::Handle(IEvent evt)
        {

        }

        bool IEventHandler::Responds(string name)
        {
            return true;
        }

        EventManager::EventManager()
        {
            this->handlers = vector<IEventHandler>();
        }

        bool EventManager::AddHandler(IEventHandler handler)
        {
            this->handlers[this->handlers.size()] = handler;
        }

        void EventManager::Raise(IEvent evt)
        {
            for(int i = 0; i < this->handlers.size(); i++)
            {
                if(this->handlers[i].Responds(evt.GetName()))
                {
                    this->handlers[i].Handle(evt);
                }
            }
        }

    }

}
