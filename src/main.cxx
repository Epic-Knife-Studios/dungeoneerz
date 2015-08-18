// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#include "dungeoneerz/engine/core.hpp"
#include "dungeoneerz/engine/game.hpp"
#include "dungeoneerz/engine/dungeon.hpp"

using Dungeoneerz::Engine::EngineCore;
using Dungeoneerz::Engine::GameEngine;

#include "dungeoneerz/game/game.hpp"

using Dungeoneerz::Game::DungeonGame;

#include <cstdio>
#include <cstring>

#include <map>
#include <string>

using std::map;
using std::string;

int main(int argc, char* argv[])
{

    Dungeoneerz::SetEngine(
        new GameEngine()
    );

    ((GameEngine*)Dungeoneerz::GetEngine())->game = new DungeonGame(
        ((GameEngine*)Dungeoneerz::GetEngine())->logger,
        ((GameEngine*)Dungeoneerz::GetEngine())->emgr
    );

    ((GameEngine*)Dungeoneerz::GetEngine())->Start();

    ((GameEngine*)Dungeoneerz::GetEngine())->game->Run();

    ((GameEngine*)Dungeoneerz::GetEngine())->Stop();

    return 0;
}
