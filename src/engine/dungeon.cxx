#include "dungeoneerz/engine/dungeon.hpp"

EngineCore* MainEngineCore;

namespace Dungeoneerz
{

    void SetEngine(EngineCore* core)
    {

        MainEngineCore = core;

    }

    EngineCore* GetEngine()
    {

        return MainEngineCore;

    }

    Logger* GetLogger()
    {

        return GetEngine()->logger;

    }

    EventManager* GetEventManager()
    {

        return GetEngine()->emgr;

    }


}
