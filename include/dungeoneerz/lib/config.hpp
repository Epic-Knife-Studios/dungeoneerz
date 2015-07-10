// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#pragma once

#define ETYPE_NONE 0
#define ETYPE_INT 1
#define ETYPE_STRING 2
#define ETYPE_LIST 3
#define ETYPE_MAP 4

#include <string>
#include <vector>
#include <map>

#include <cstdio>

using std::string;
using std::vector;

namespace Dungeoneerz
{
    
    namespace Library
    {

        class IElement
        {

            protected:

                int type;

                string name;

                IElement(int type);

            public:

                IElement(string name);

                int GetType();

        };

        class ElementInt : public IElement
        {

            public:

                int Value;

                ElementInt(string name, int i);

        };

        class ElementString : public IElement
        {

            public:

                string Value;

                ElementString(string name, string str);

        };

        class ElementList : public IElement
        {

            public:

                vector<IElement*> Elements;

                ElementList(string name);

        };

        class ConfigParser
        {

            public:

                ConfigParser();

        };

        class Configuration
        {

            public:

                ElementMap* root;

                Configuration();

                bool Parse(string str);

        };
        
    }
    
}

