#ifndef LAB4_ENCODER_H
#define LAB4_ENCODER_H
#include <stdio.h>
#include <string.h>

const char NOT_A_CHAR = 0;

struct CharNum
{
    char c;
    int n;
    int path;
    CharNum(char c, int n) : c(c), n(n), path(-1)
    {
    }
};

struct Node
{
    int n;
    char c;
    Node *left;
    Node *right;
    Node(int n = 0, char c = 0) : n(n), c(c), left(nullptr), right(nullptr) {}
    Node(CharNum x) : n(x.n), c(x.c), left(nullptr), right(nullptr) {}
};

void swap(CharNum a, CharNum b)
{
    int tn = a.n;
    char tc = a.c;
    a.n = b.n;
    a.c = b.c;
    b.n = tn;
    b.c = tc;
}

class Encoder
{
    Node *root;
    CharNum Occurences[41];
    int charQuantity;
    void AddOccurence(char c);
    void SortOccurences();
    void CreateDict(const char *filename);
    const char *PathToCode(int path);
    const char *CharToCode(char c);
};

#endif //LAB4_ENCODER_H
