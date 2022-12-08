#ifndef LAB4_CODE_H
#define LAB4_CODE_H
#define MAX_MESSAGE 100

struct Letter
{
    char c;
    int n = 0;
    int path = -1;
    char code[27] = { 0 };

    Letter(char c = ' ') : c(c)
    {
    }
    void AddPathAndCode(int n)
    {
        path = n;
        for(int i = 0; i < 27 && n > 0; i++, n--)
        {
            code[i] = 1;
        }
    }
};

void swap(Letter a, Letter b);

class Code {
    Letter dict[27] = { Letter() };//26 letters and space

public:
    Code(const char *filename)
    {
        InitializeDict(filename);
    }
    const char *Encode();
private:
    void InitializeDict(const char *filename);
};


#endif //LAB4_CODE_H
