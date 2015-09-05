// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace Dungeoneerz
{

    namespace Library
    {

        class DChunk
        {

            private:

                string name;

                string value;

            public:

                DChunk(string name);

                DChunk(string name, string value);

                string Value();

                string Name();

                void Set(string value);

        };

        class DNode
        {

            private:

                vector<DNode*>* children;

                DChunk* value;

            public:

                DNode(DChunk* value);

                DChunk* Get();

                void Set(DChunk* chk);

                int ChildLength();

                DNode* GetChild(int index);

                void AddChild(DNode* node);

                void SetChild(int index, DNode* node);

                void Pop(int amt);

        };

    }

}
