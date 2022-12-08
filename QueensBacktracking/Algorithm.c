#include <stdlib.h>
#include <math.h>
#include <printf.h>

#define GREEN "\x1B[32m"
#define RESET "\033[0m"

typedef struct field
{
    int queen;
    int attacked;
}field;

//queen_n == -n means that queen n stopped attacking
void update_attacked_fields(int i, int j, field **table, int size, int queen_n)
{
    //int attack_id = queen_n > 0 ? pow(2, queen_n) : 0 - pow(2, abs(queen_n));
    int attack_id = queen_n;
    for(int offset = 1; offset < size; offset++)
    {
        //diagonals
        if(i + offset < size && j + offset < size)
        {
            table[i+offset][j+offset].attacked += attack_id;
        }
        if(i + offset < size && j - offset >= 0)
        {
            table[i+offset][j-offset].attacked += attack_id;
        }
        if(i - offset >= 0 && j - offset >= 0)
        {
            table[i-offset][j-offset].attacked += attack_id;
        }
        if(i - offset >= 0 && j + offset < size)
        {
            table[i-offset][j+offset].attacked += attack_id;
        }
        //lanes
        if(i + offset < size)
        {
            table[i+offset][j].attacked += attack_id;
        }
        if(i - offset >= 0)
        {
            table[i-offset][j].attacked += attack_id;
        }
        if(j - offset >= 0)
        {
            table[i][j-offset].attacked += attack_id;
        }
        if(j + offset < size)
        {
            table[i][j+offset].attacked += attack_id;
        }
    }
}

//return queen_n if it succeeded or 0 if it failed
int place_queen(field *f, int queen_n)
{
    if(f->queen || f->attacked)
    {
        return 0;
    }
    else
    {
        f->queen = queen_n;
        return queen_n;
    }
}

//returns the number of row where the queen was
int remove_queen_from_column(field *f, int queen_n)
{
    int row = 0;
    while (1)
    {
        if(f[row].queen == queen_n)
        {
            f[row].queen = 0;
            return row;
        }
        row++;
    }
    if(f->queen == queen_n)
    {
        f->queen = 0;
    }
}

int queen_id(int n)
{
    return pow(2, n);
}

field **calculate(int n)
{
    //allocate the needed memory
    field **table = (field **)calloc(n, sizeof (field *));
    for(int i = 0; i < n; i++)
    {
        table[i] = (field *)calloc(n, sizeof (field));
    }
    //table[i][j].queen == n means there is a queen number n there
    //(table[i][j].attacked & pow(2,n)) == pow(2,n) means that table[i][j] is attacked by queen n


    int *offset_in_each_column = (int *)calloc(n, sizeof (int));
    //iterate through columns
    for(int i = 0; i < n; i++)
    {
        if(offset_in_each_column[i] == n)
        {
            //reset the offset for this column and all the next ones
            for(int k = i; k < n; k++)
            {
                offset_in_each_column[k] = 0;
            }
            //and do the same as for !found
            //we change previous column
            i--;
            //we remove the previous queen
            int row = remove_queen_from_column(table[i], queen_id(i));
            update_attacked_fields(i, row, table, n, 0 - queen_id(i));
            //update the offset in previous column
            offset_in_each_column[i]++;
            //decrese i again, so after i++ the loop will consider the previous column again
            i -= 1;
            continue;
        };
        //search for the first available spot in the column
        int found = 0;
        for(int j = offset_in_each_column[i]; j < n; j++)
        {
            if(place_queen(table[i] + j, queen_id(i)))
            {
                found = 1;
                update_attacked_fields(i, j, table, n, queen_id(i));
                break;
            }
        }
        if(!found)
        {
            //we change previous column
            i--;
            //we remove the previous queen
            int row = remove_queen_from_column(table[i], queen_id(i));
            update_attacked_fields(i, row, table, n, 0 - queen_id(i));
            //update the offset in previous column
            offset_in_each_column[i]++;
            //decrese i again, so after i++ the loop will consider the previous column again
            i -= 1;
        }
    }
    return table;
}

void print_solution(field **table, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(table[i][j].queen)
            {
                printf(GREEN "Q " RESET);
            }
            else
            {
                printf("X ");
            }
        }
        printf("\n");
    }
}
