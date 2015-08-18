// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#include "dungeoneerz/lib/logger.hpp"

using std::string;

namespace Dungeoneerz
{

    namespace Library
    {

        Logger::Logger(string location)
        {

            this->ltime = time(NULL);

            this->out = fopen(location.c_str(), "w");

        }

        void Logger::Log(string sender, string message)
        {

            long int l1_1 = 0;
            long int l2_1 = 0;
            long int l2_2 = 0;
            long int l3_1 = 0;
            long int l3_2 = 0;

            l3_1 = (long int)(time(NULL)-this->ltime);

            if(l3_1 - 10 >= 0)
            {

                l3_2 = l3_1 / 10;

                l2_1 = l3_2;

                l3_1 = l3_1 - (l3_2 * 10);

                if(l2_1 - 20 >= 0)
                {

                    l2_2 = l2_1 / 20;

                    l1_1 = l2_2;

                    l2_1 = l2_1 - (l2_2 * 20);

                }
                else
                {
                    l2_2 = l2_1;
                }

            }
            else
            {
                l3_2 = l3_1;
            }

            fprintf(this->out,
                "{%li:%li:%li} [%s] %s\n",
                l1_1,
                l2_1,
                l3_1,
                sender.c_str(),
                message.c_str()
            );

            fprintf(stdout,
                "{%li:%li:%li} [%s] %s\n",
                l1_1,
                l2_1,
                l3_1,
                sender.c_str(),
                message.c_str()
            );

        }

    }

}
