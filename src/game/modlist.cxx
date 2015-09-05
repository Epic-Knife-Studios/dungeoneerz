// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#include "dungeoneerz/game/modlist.hpp"

namespace Dungeoneerz
{

    namespace Game
    {

        ModList::ModList()
        {

            this->mods = vector<IModule*>();

        }

        void ModList::Add(IModule* mod)
        {

            // Fake mods are bad.  </3
            if(mod == (IModule*)NULL)
            {
                return;
            }

            bool overwrite = false;

            for(int i = 0; i < this->mods.size(); i++)
            {

                if(this->mods[i]->name == mod->name)
                {

                    Dungeoneerz::GetLogger()->Log(
                        string("Mod"),
                        string("Reloading \"") + mod->name + string("\"!")
                    );

                    this->Stop(mod->name);

                    this->mods[i] = mod;

                    this->Start(mod->name);

                    overwrite = true;

                }

            }

            if(!overwrite)
            {

                Dungeoneerz::GetLogger()->Log(
                    string("Mod"),
                    string("Loading \"") + mod->name + string("\"...")
                );

                this->mods.push_back(mod);

                this->Start(mod->name);

            }

        }

        bool ModList::Contains(string name)
        {

            for(int i = 0; i < this->mods.size(); i++)
            {

                if(this->mods[i]->name == name)
                {

                    return true;

                }

            }

            return false;

        }

        IModule* ModList::Get(string name)
        {

            for(int i = 0; i < this->mods.size(); i++)
            {

                if(this->mods[i]->name == name)
                {

                    return this->mods[i];

                }

            }

            return (IModule*)NULL;

        }

        bool ModList::Start(string name)
        {

            IModule* mod = this->Get(name);

            if(mod != (IModule*)NULL)
            {

                mod->OnStart();

                Dungeoneerz::GetLogger()->Log(
                    string("Mod"),
                    string("Started \"") + mod->name + string("\"!")
                );

                return true;

            }

            return false;

        }

        void ModList::StartAll()
        {

            for(int i = 0; i < this->mods.size(); i++)
            {

                this->Start(this->mods[i]->name);

            }

        }

        bool ModList::Stop(string name)
        {

            IModule* mod = this->Get(name);

            if(mod != (IModule*)NULL)
            {

                mod->OnStop();

                Dungeoneerz::GetLogger()->Log(
                    string("Mod"),
                    string("Stopped \"") + mod->name + string("\"!")
                );

                return true;

            }

            return false;

        }

        void ModList::StopAll()
        {

            for(int i = 0; i < this->mods.size(); i++)
            {

                this->Stop(this->mods[i]->name);

            }

        }

        bool ModList::Reload(string name)
        {

            IModule* mod = this->Get(name);

            if(mod != (IModule*)NULL)
            {

                this->Stop(mod->name);

                this->Start(mod->name);

                return true;

            }

            return false;

        }

        void ModList::ReloadAll()
        {

            Dungeoneerz::GetLogger()->Log(
                string("Mod"),
                string("Reloading...")
            );

            for(int i = 0; i < this->mods.size(); i++)
            {

                this->Start(this->mods[i]->name);
                this->Stop(this->mods[i]->name);

            }

            Dungeoneerz::GetLogger()->Log(
                string("Mod"),
                string("Reload complete!")
            );

        }


    }

}
