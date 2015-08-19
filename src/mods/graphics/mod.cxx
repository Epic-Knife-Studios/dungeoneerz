#include "dungeoneerz/mods/graphics/mod.hpp"

namespace Dungeoneerz
{

    namespace Mods
    {

        GraphicsMod::GraphicsMod()
        {

            this->name = string("graphicsmod");

        }

    }

}

extern "C"
{

    IModule* dungeon_graphics_entry()
    {

        return new Dungeoneerz::Mods::GraphicsMod();

    }

}
