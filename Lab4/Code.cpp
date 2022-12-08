#include <cstdio>
#include <cstdlib>
#include "Code.h"

void Code::InitializeDict(const char *filename)
{
    //Initialize dict array with english alphabet (space ' ' is a default for the last element
    for(int i = 0; i < 26; i++)
    {
        dict[i].c = 'a' + i;
    }
    FILE *f = fopen(filename, "r");
    char c = fgetc(f);
    //Count the number of occurrences of each letter
    while(c != EOF)
    {
        for(int i = 0; i < 27; i++)
        {
            if(dict[i].c == c)
            {
                dict[i].n++;
            }
        }
        c = fgetc(f);
    }
    //Sort dict array in descending order (bubble sort)
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26 - i; j++)
        {
            if(dict[j].n < dict[j+1].n)
            {
                swap(dict[j], dict[j+1]);
            }
        }
    }
    //Set proper path and codes for each letter
    for(int i = 0; i < 27; i++)
    {
        dict[i].AddPathAndCode(i);
    }
    //Sort dict array in alphabetical order
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26 - i; j++)
        {
            if(dict[j].c > dict[j+1].c || dict[j].c == ' ')
            {
                swap(dict[j], dict[j+1]);
            }
        }
    }
    //The code is ready to encode and decode messages
}

const char *Code::Encode()
{
    char *coded = (char*)calloc(sizeof(char), MAX_MESSAGE * 27 + 1);
    int index = 0;
    int path = -1;
    int ch;
    char c = getchar();
    while(c != EOF && c != '\n')
    {
        ch = c == ' ' ? 26 : c - 'a';
        if(ch >= 0 && ch <=26)
        {
            path = this->dict[ch].path;
            for(int i = 0; i < path; i++, index++)
            {
                coded[index] = 1;
            }
            if(path != 26)
            {
                index++;
            }
        }
        c = getchar();
    }
    coded[index] = '\0';
    return coded;
}

void swap(Letter a, Letter b)
{
    int tn = a.n;
    char tc = a.c;
    a.n = b.n;
    a.c = b.c;
    b.n = tn;
    b.c = tc;
}
