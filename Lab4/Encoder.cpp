#include "Encoder.h"
/*
void Encoder::AddOccurence(char c)
{
    for(int i = 0; i <= 40; i++)
    {
        if(Occurences[i].c == c)
        {
            Occurences[i].n++;
            return;
        }
        if(Occurences[i].c == 0)
        {
            Occurences[i].c = c;
            Occurences[i].n = 1;
            return;
        }
    }
}

void Encoder::SortOccurences()//bubble sort
{
    for(int i = 0; i <= 39; i++)
    {
        for(int j = 0; j <= 39 - i; j++)
        {
            if(Occurences[j].n > Occurences[j+1].n)
            {
                swap(Occurences[j], Occurences[j+1]);
            }
        }
    }
}

void Encoder::CreateDict(const char *filename) {
    FILE *f = fopen(filename, "r+");
    char c = fgetc(f);
    while(c != EOF)
    {
        AddOccurence(c);
    }
    SortOccurences();
    int firstChar = 0;
    while(Occurences[firstChar].c == 0)//we omit all the leading empty structs
    {
        firstChar++;
    }

    root = new Node();
    root->right = new Node(Occurences[firstChar]);
    root->left = new Node(Occurences[firstChar + 1]);
    root->n = root->left->n + root->right->n;

    charQuantity = 41 - firstChar;

    for(int i = firstChar + 2; i <= 40; i++)//now we have created the tree
    {
        Node *tmp = new Node();
        tmp->right = root;
        tmp->left = new Node(Occurences[i]);
        tmp->n = tmp->left->n + tmp->right->n;
        root = tmp;
    }

    for(int i = 40, path = 0; i >= 0; i--, path++)
    {
        Occurences[i].path = path;
    }
}

const char *Encoder::PathToCode(CharNum x)
{
    char *ret;
    int path = x.path;
    while(path > 0)
    {
        strcat(ret, "1");
        path--;
    }
    if()
}

const char *Encoder::CharToCode(char c)
{
    for(int i = 0; i <= 40; i++)
    {
        if(Occurences[i].c == c)
        {
            return PathToCode(Occurences[i]);
        }
    }
}
 */