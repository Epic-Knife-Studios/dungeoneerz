// Dungeoneerz
// Copyright(c) 2015 Samuel "MrOverkill" Meyers

#include "dungeoneerz/lib/fs.hpp"

namespace Dungeoneerz
{

    namespace Library
    {

        namespace FileSystem
        {

            bool ExistsFile(string path)
            {

                FILE* f = fopen(path.c_str(), "r");

                if(f)
                {
                    fclose(f);
                    return true;
                }

                return false;

            }

        }

    }

}
