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

    template<typename T> T CastEngine()
    {

        return (T)GetEngine();

    }


}
