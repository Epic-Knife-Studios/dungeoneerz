#include "dungeoneerz/engine/events.hpp"

#include "dungeoneerz/lib/event.hpp"
#include "dungeoneerz/lib/logger.hpp"

#include <cstdio>

using Dungeoneerz::Engine::BaseHandler;
using Dungeoneerz::Engine::StartEvent;

using Dungeoneerz::Library::EventManager;
using Dungeoneerz::Library::Logger;

Logger* logger;

EventManager* emgr;

int main(int argc, char* argv[])
{

    // Initialize logging.
    logger = new Logger("engine.log");

    // Initialize Event Manager.
    emgr = new EventManager();

    // Setup base event handler.
    emgr->AddHandler(new BaseHandler(logger));

    // Start.
    emgr->Raise(new StartEvent());

    return 0;
}
