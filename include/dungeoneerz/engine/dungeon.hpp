// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#pragma once

#include "dungeoneerz/engine/core.hpp"

using Dungeoneerz::Engine::EngineCore;

namespace Dungeoneerz
{

    void SetEngine(EngineCore* core);

    EngineCore* GetEngine();

    template<typename T> T* CastEngine()
    {

        return (T*)GetEngine();

    }

    Logger* GetLogger();

    EventManager* GetEventManager();

}
