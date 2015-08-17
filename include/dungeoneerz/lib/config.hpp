// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#pragma once

#include <string>

#include <cstdio>

using std::string;

namespace Dungeoneerz
{
    
    namespace Library
    {

        class IConfigNode
        {

        protected:

            string name;
            string value;

        public:

            IConfigNode();
            IConfigNode(string name);
            IConfigNode(string name, string value);

            string GetName();
            string GetValue();

        };

        class IConfigParser
        {

        protected:



        public:
            IConfigParser();

            bool Parse(string text);

        };

        class CfgNode
        {
            
            public:
                string name;
                string value;
                
                CfgNode(string name, string value);
                
                
            
        };
    
        class Config
        {
            
            private:
                string text;
            
            public:
                Config(string text);
                
                
            
        };
        
    }
    
}

