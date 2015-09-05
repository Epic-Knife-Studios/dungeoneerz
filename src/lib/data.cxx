// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#include "dungeoneerz/lib/data.hpp"

namespace Dungeoneerz
{

    namespace Library
    {

        DChunk::DChunk(string name)
        {

            this->name = name;
            this->value = string("null");

        }

        DChunk::DChunk(string name, string value)
        {

            this->name = name;
            this->value = value;

        }

        string DChunk::Name()
        {

            return this->name;

        }

        string DChunk::Value()
        {

            return this->value;

        }

        void DChunk::Set(string value)
        {

            this->value = value;

        }

        DNode::DNode(DChunk* chk)
        {

            this->value = chk;
            this->children = new vector<DNode*>();

        }

        DChunk* DNode::Get()
        {

            return this->value;

        }

        void DNode::Set(DChunk* chk)
        {

            this->value = chk;

        }

        int DNode::ChildLength()
        {

            return this->children->size();

        }

        DNode* DNode::GetChild(int index)
        {

            if(index > this->children->size() || index < 0)
            {

                return new DNode(new DChunk(string("null")));

            }

            return new DNode(new DChunk(string("null")));

        }

    }

}
