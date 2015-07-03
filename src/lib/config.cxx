// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#include "dungeoneerz/lib/config.hpp"

using std::string;

namespace Dungeoneerz
{

    namespace Library
    {
    
        CfgNode::CfgNode(string name, string value)
        {
            
            this->name = name;
            this->value = value;
            
        }
    
        Config::Config(string text)
        {
            
            this->text = text;
            
        }
    
    }

}
