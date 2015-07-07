#include "dungeoneerz/lib/event.hpp"

using Dungeoneerz::Library::EventManager;

EventManager* emgr;

int main(int argc, char* argv[])
{

    // Initialize Event Manager.
    emgr = new EventManager();



    return 0;
}
