// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#include "dungeoneerz/game/game.hpp"

using Dungeoneerz::Game::Game;

Game* game;

int main(int argc, char* argv[])
{
    game = new Game();
    return 0;
}
