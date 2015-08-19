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
            this->cmd = cmd;

        }

        string ConsoleCommandEvent::GetCommand()
        {

            return this->cmd;

        }

        ConsoleCommandPrinter::ConsoleCommandPrinter(Logger* logger)
        {

            this->logger = logger;

            this->loader = new ModLoader(string("./"));

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

                    IModule* mod = this->loader->LoadAs<IModule, ModuleEntryType>(
                        string("graphicsmod"),
                        string("dungeon_graphics_entry")
                    );

                    if(mod == (IModule*)NULL)
                    {

                        this->logger->Log(
                            string("Console"),
                            string("Module load error!")
                        );

                        return;

                    }

                    this->logger->Log(
                        string("Console"),
                        string("Mod name : ") + mod->name
                    );

                    return;

                }

                this->logger->Log(
                    string("Console"),
                        string("Command '") +
                        event->GetCommand() +
                        string("' is undefined!")
                );

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
