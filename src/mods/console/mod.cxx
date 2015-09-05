// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#include "dungeoneerz/mods/console/mod.hpp"

namespace Dungeoneerz
{

    namespace Mods
    {

        ConsoleModHandler::ConsoleModHandler(ConsoleMod* mod)
        {

            this->mod = mod;

        }

        void ConsoleModHandler::Handle(IEvent* evt)
        {

            if(evt->GetName() == string("core/modsignal"))
            {

                ModuleSignalEvent* event = (ModuleSignalEvent*)evt;

                if(event->GetFunction() == string("builtin/console/getmod"))
                {

                    this->mod->info->emgr->Raise(
                        new ModuleSignalEvent(
                            string("builtin/console/sendmod"),
                            (void*)NULL
                        )
                    );

                }

            }

        }

        bool ConsoleModHandler::Responds(string name)
        {

            return (
                name == string("core/modsignal")
            );

        }

        ConsoleModule::ConsoleModule() : IModule()
        {

            this->name = string("epicknife.console");

        }

        void ConsoleModule::OnLoad()
        {



        }

        void ConsoleModule::OnStop()
        {

        }

    }

}

extern "C"
{

    Dungeoneerz::Library::IModule* dungeon_module_entry()
    {
        return new Dungeoneerz::Mods::ConsoleModule();
    }

}
