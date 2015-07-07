#include "dungeoneerz/lib/util.hpp"

namespace Dungeoneerz
{

    namespace Library
    {

        namespace Util
        {

            bool CharIsNumber(char c)
            {
                return (
                    c == '1' ||
                    c == '2' ||
                    c == '3' ||
                    c == '4' ||
                    c == '5' ||
                    c == '6' ||
                    c == '7' ||
                    c == '8' ||
                    c == '9' ||
                    c == '0'
                );
            }

            int GetNumberOfChar(char c)
            {
                switch(c)
                {
                    case '1':
                        return 1;
                    case '2':
                        return 2;
                    case '3':
                        return 3;
                    case '4':
                        return 4;
                    case '5':
                        return 5;
                    case '6':
                        return 6;
                    case '7':
                        return 7;
                    case '8':
                        return 8;
                    case '9':
                        return 9;
                    case '0':
                        return 0;
                    default:
                        return (int)c;
                }
            }

            bool CharIsNumeric(char c)
            {
                return (
                    CharIsNumber(c) ||
                    c == '.' ||
                    c == '-'
                );
            }

            string StrAsNumber(string str)
            {

                string tr = string("");

                for(int i = 0; i < str.length(); i++)
                {
                    if(CharIsNumber(str.c_str()[i]))
                    {
                        tr += str.c_str()[i];
                    }
                }

                return tr;

            }

            string StrAsNumeric(string str)
            {

                string tr = string("");

                for(int i = 0; i < str.length(); i++)
                {
                    if(CharIsNumeric(str.c_str()[i]))
                    {
                        tr += str.c_str()[i];
                    }
                }

                return tr;

            }

            int StrParseInt(string str)
            {

                int x = atoi(StrAsNumber(str).c_str());

                return x;

            }

            vector<char> StrToBytes(string str)
            {

                vector<char> tr = vector<char>();

                const char* c;

                for(int i = 0; i < str.length(); i++)
                {
                    tr[i] = c[i];
                }

                return tr;

            }

            string BytesToStr(vector<char> bytes)
            {

                string str = "";

                for(int i = 0; i < bytes.size(); i++)
                {
                    str += bytes[i];
                }

                return str;

            }

        }

    }

}
