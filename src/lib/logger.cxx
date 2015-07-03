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
        
            fprintf(this->out, 
                "{%li} [%s] %s\n", 
                (long int)(time(NULL)-this->ltime),
                sender.c_str(),
                message.c_str()
            );
            
            fprintf(stdout,
                "{%li} [%s] %s\n",
                (long int)(time(NULL)-this->ltime),
                sender.c_str(),
                message.c_str()
            );
        
        }
    
    }

}
