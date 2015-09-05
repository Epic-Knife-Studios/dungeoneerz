// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#include "dungeoneerz/game/console.hpp"

namespace Dungeoneerz
{

    namespace Game
    {

        Console::Console(Logger* logger, EventManager* emgr)
        {

            this->logger = logger;
            this->emgr = emgr;

            this->emgr->AddHandler(
                new ConsoleCommandPrinter(this->logger)
            );

        }

        ReadCode Console::Read()
        {

            fprintf(stdout, ">");

            char c = '\r';
            vector<char> cs = vector<char>();

            do
            {

                c = fgetc(stdin);

                if(c != EOF && c != '\n')
                {
                    cs.push_back(c);
                }

                if(c == EOF)
                {

                    this->logger->Log(
                        string("Console"),
                        string("Quitting...")
                    );

                    Dungeoneerz::CastEngine<GameEngine>()->Stop();

                    return CONSOLE_CODE_DIE;

                }

            }
            while(c != '\n');

            string cmd = string("");

            for(int i = 0; i < cs.size(); i++)
            {
                cmd += cs[i];
            }

            this->emgr->Raise(
                new ConsoleCommandEvent(cmd)
            );

            return CONSOLE_CODE_OK;

        }

        ConsoleCommandEvent::ConsoleCommandEvent(string cmd)
        {

            this->name = string("console/command");

            this->rawcmd = cmd + (char)EOF;

            this->cmd = string("");

            this->arguments = vector<string>();

            char c;

            string argument = string("");

            bool cmdset = false;

            for(int i = 0; i < this->rawcmd.length(); i++)
            {

                c = this->rawcmd.c_str()[i];

                if(c == ':' && !cmdset)
                {

                    cmdset = true;

                    continue;

                }

                if(c != (char)EOF && !cmdset)
                {

                    this->cmd = this->cmd + c;

                }

                if(c != (char)EOF && cmdset)
                {

                    if(c == '\\')
                    {

                        argument = argument + ' ';

                        i++;

                        continue;

                    }

                    if(CharIsWhitespace(c) && argument != string(""))
                    {

                        this->arguments.push_back(argument);

                        argument = string("");

                    }
                    else if(CharIsWhitespace(c) && argument == string(""))
                    {

                        continue;

                    }
                    else
                    {

                        argument = argument + c;

                    }


                }

            }

            if(argument != string(""))
            {

                this->arguments.push_back(argument);

            }

        }

        string ConsoleCommandEvent::GetRawCommand()
        {

            return this->rawcmd;

        }

        string ConsoleCommandEvent::GetCommand()
        {

            return this->cmd;

        }

        vector<string> ConsoleCommandEvent::GetArguments()
        {

            return this->arguments;

        }

        ConsoleCommandPrinter::ConsoleCommandPrinter(Logger* logger)
        {

            this->logger = logger;

            this->loader = new ModLoader(string("./"));

            this->mods = new ModList();

        }

        void ConsoleCommandPrinter::Handle(IEvent* evt)
        {

            if(evt->GetName() == string("console/command"))
            {

                ConsoleCommandEvent* event = (ConsoleCommandEvent*)evt;

                if(event->GetCommand() == string("quit"))
                {

                    this->logger->Log(
                        string("Console"),
                        string("Quitting...")
                    );

                    Dungeoneerz::CastEngine<GameEngine>()->Stop();

                    return;
                }

                if(event->GetCommand() == string("lmod"))
                {

                    vector<string> args = event->GetArguments();

                    if(args.size() < 1)
                    {

                        this->logger->Log(
                            string("Console"),
                            string("Usage: lmod: <library_name> [entry_point]")
                        );

                        return;

                    }

                    string lname = args[0];
                    string lfunc = string("dungeon_module_entry");

                    if(args.size() > 1)
                    {
                        lfunc = args[1];

                    }

                    IModule* mod = this->loader->LoadAs<IModule, ModuleEntryType>(
                        lname,
                        lfunc
                    );

                    if(mod == (IModule*)NULL)
                    {

                        this->logger->Log(
                            string("Console"),
                            string("Mod load error!")
                        );

                        return;

                    }

                    mod->OnLoad();

                    this->mods->Add(mod);

                    return;

                }

            }

        }

        bool ConsoleCommandPrinter::Responds(string name)
        {

            return (
                name == string("console/command")
            );

        }

    }

}
