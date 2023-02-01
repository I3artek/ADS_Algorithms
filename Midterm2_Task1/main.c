/*
 * In this algorithm we search for all the substrings of X that contain every character from S
 * We iterate through all the substring using two indexes:
 * start - starting index of ubstring in X
 * end - ending index of substring in X
 *
 * n - length of the string X
 *
 * At first start = 0 and end = n - 1
 * Then we decrease end by 1 in each iteration effectively checking all substrings that start at 0
 * Then we increase start by 1 and do the same, checking all subtrings starting at 1
 * We do that until we have checked all the substrings
 *
 * The number of substrings grows like n^2
 * And the time needed to check one substring depends on its length which can be at max n
 * Therefore, the whole algorithm has complexity O(n^3)
 *
 * The checking funtion could be optimized to check hashes after each character,
 * but it would make the algorithm time complexity more dependent on its input
 *
 * Nevertheless, the complexity is still O(n^3)
 *
 * To change the input, just change the string X and/or string S_string
 * You can also comment/uncomment PRINT_SUBSTRINGS in #define
 * which essentialy controls if the substrings are printed
 *
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

//#define PRINT_SUBSTRINGS

typedef struct{
    int is_in_set[10];
    int hash;
}char_set;

void initialize_set(char_set *S, const char *string);

void add_to_set(char_set *set, int n);

int contains_all_from_set(const char *string, int start, int end, char_set set);

int count_substrings(const char *string, char_set set);

void print_substring(const char *string, int start, int end);

int main() {

    char *X = "1020194192480135702362418677777826102412384612023";
    char *S_string = "17";

    char_set S = { 0 };
    initialize_set(&S, S_string);

    printf("The string X:\n%s\n", X);

    printf("The set S contains: %s\n", S_string);

    printf("All the substrings in X that contain all the numbers from S:\n");

    int count = count_substrings(X, S);

    printf("There are %d substrings in X that contain all characters from S\n", count);

    return 0;
}

void add_to_set(char_set *set, int n)
{
    if(set->is_in_set[n] == 0)
    {
        set->is_in_set[n] = 1;
        set->hash += (int)pow(2, n);
    }
}

//O(n)
int contains_all_from_set(const char *string, int start, int end, char_set set)
{
    char_set temp = { 0 };
    for(int i = start; i <= end; i++)
    {
        int val = string[i] - '0';
        add_to_set(&temp, val);
    }

    return (temp.hash & set.hash) == set.hash;
}

//n^2 * O(n) = O(n^3)
int count_substrings(const char *string, char_set set)
{
    int len = (int)strlen(string);
    int count = 0;

    for(int start = 0; start < len; start++)
    {
        for(int end = len - 1; end >= start; end--)
        {
            //O(n)
            if(contains_all_from_set(string, start, end, set))
            {
                count++;
#ifdef PRINT_SUBSTRINGS
                print_substring(string, start, end);
#endif
            }
        }
    }
    return count;
}

//O(1) - max 10 iterations
void initialize_set(char_set *S, const char *string)
{
    S->hash = 0;
    int i = 0;
    while(string[i] != '\0')
    {
        int val = string[i++] - '0';
        S->is_in_set[val] = 1;
        S->hash += (int)pow(2, val);
    }
}

void print_substring(const char *string, int start, int end)
{
    printf("Substring from %d to %d: ", start, end);
    for(int i = start; i <= end; i++)
    {
        printf("%c", string[i]);
    }
    printf("\n");
}
