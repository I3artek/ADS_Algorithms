#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct villain
{
    int Strength;
    int Ego;
    char* Name;
}villain;

villain* choose_villain(villain *villains, int size);

int choose(villain *villains, int size, int ego);
//villain *choose(villain *villains, int size, int ego);

villain *chooseVillains(villain *villains, int size);

int size(villain* A)
{
    return 1;
}

int max(int a, int b)
{
    return a >= b ? a : b;
}

void printArray(villain* arr, int n)
{
    printf("Chosen villains:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%s\n", arr[i].Name);
    }
}

void swapVillains(villain *a, villain *b)
{
    //swap the names
    char *tmp = calloc(strlen(a->Name) + 1, sizeof (char));
    strcpy(tmp, a->Name);
    a->Name = calloc(strlen(b->Name) + 1, sizeof (char));;
    strcpy(a->Name, b->Name);
    b->Name = calloc(strlen(tmp) + 1, sizeof (char));
    strcpy(b->Name, tmp);
    free(tmp);
    //swap the strengts
    a->Strength += b->Strength;//a = a + b
    b->Strength = a->Strength - b->Strength;//b = a + b - b = a
    a->Strength -= b->Strength;//a = a + b - a = b
    //swap the egos
    a->Ego += b->Ego;//a = a + b
    b->Ego = a->Ego - b->Ego;//b = a + b - b = a
    a->Ego -= b->Ego;//a = a + b - a = b
}

//compareVillains <= 0 <=> a.Ego <= b.Ego
//compareVillains >= 0 <=> a.Ego >= b.Ego
//compareVillains < 0 <=> a.Ego < b.Ego
//compareVillains > 0 <=> a.Ego > b.Ego
int compareVillainsByEgo(villain a, villain b)
{
    if(a.Ego < b.Ego)
    {
        return -1;
    }
    if(a.Ego > b.Ego)
    {
        return 1;
    }
    //a.Ego == b.Ego
    return 0;
}

villain *solution;
int sn = 0;
void addToSolution(villain v)
{
    for(int i = 0; i < sn; i++)
    {
        if(strcmp(solution[i].Name, v.Name) == 0)
        {
            return;
        }
    }
    sn++;
    solution = realloc(solution, sizeof (villain) * sn);
    solution[sn - 1] = v;
}

void QuickSort(villain A[], int size, int (*cmp)(villain, villain));

int main() {
    villain test[] = {
            {
                2, 9, "XD"
            },
            {
                7, 3, "Dr Freeze"
            },
            {
                5, 4, "PYG"
            },
            {
                4, 1, "Firefly"
            },
            {
                8, 1, "Strongerfly"
            },
            {
                32, 32, "Doom"
            }
    };
    QuickSort(test, 6, compareVillainsByEgo);
    int res = choose(test, 6, 0);
    printf("Result: %d\n", res);
    printArray(solution, sn);
    return 0;
}

//villain* choose_villain(villain *villains, int size)
//{
//    //int takenVillains = calloc(size, sizeof (int));
//    villain **solutions = calloc(size, sizeof (villain*));
//    //check different solutions
//    for(int i = 0; i < size; i++)
//    {
//        solutions[i] = calloc(size, sizeof (villain));
//        //add the leader to the solution
//        solutions[i][i] = villains[i];
//        int highestEgo = villains[i].Ego;
//        //iterate through the remaining villains
//        for(int j = i; j < size; j++)
//        {
//            if(villains[j].Strength > highestEgo)
//            {
//                //add the villain if it won't be killed
//                solutions[i][j] = villains[j];
//                //update the highest ego of the team if necessary
//                highestEgo =  villains[j].Ego > highestEgo ? villains[j].Ego : highestEgo;
//            }
//        }
//        printArray(solutions[i], size);
//    }
//    return villains;
//}

//int _choose(villain *villains, int size, int ego)
//{
//    if(size == 1)
//    {
//        if(villains[0].Strength > ego)
//        {
//            //return villains[0].Strength;
//            return 1;
//        }
//        else
//        {
//            return 0;
//        }
//    }
//    int weTake = 0;
//    if(villains[0].Strength > ego)
//    {
//        //weTake = choose(villains + 1, size - 1, villains[0].Ego) + villains[0].Strength;// + 1;
//        weTake = choose(villains + 1, size - 1, villains[0].Ego) + 1;
//    }
//    int weNot = choose(villains + 1, size - 1, ego);
//    return max(weTake, weNot);
//}

int choose(villain *villains, int size, int ego)
{
    //printf("%s\n", villains[0].Name);
    if(size == 1)
    {
        if(villains[0].Strength > ego)
        {
            addToSolution(villains[0]);
            //return villains[0].Strength;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int weTake = 0;
    if(villains[0].Strength > ego)
    {
        //weTake = choose(villains + 1, size - 1, villains[0].Ego) + villains[0].Strength;
        weTake = choose(villains + 1, size - 1, max(villains[0].Ego, ego)) + 1;
    }
    int weNot = choose(villains + 1, size - 1, ego);
    if(weTake > weNot)
    {
        addToSolution(villains[0]);
        return weTake;
    }
    return weNot;
}



villain *chooseVillains(villain *villains, int size)
{
    villain *solution;
}

void QuickSort(villain A[], int size, int (*cmp)(villain, villain))
{
    if(size <= 1)
    {
        return;
    }
    //we choose the last element as the size
    villain *pivot = A + size - 1;
    //l is the element most to the left
    villain *l = A;
    //r is the element most to the right
    villain *r = A + size - 2;
    //we loop until l and r are like this: rl
    while(r + 1 != l)
    {
        //we swap the numbers on l and r if l <= p < r
        if( cmp(*r, *pivot) > 0 && cmp(*l, *pivot) <= 0)
        {
            swapVillains(r, l);
            l++;
            r--;
        }
        //if r < p we move r to the left
        if(cmp(*r, *pivot) < 0)
        {
            r--;
        }
        //if l >= p we move l to the right
        if(cmp(*l, *pivot) >= 0)
        {
            l++;
        }
    }
    //we swap pivot and l (because l is on the right now)
    if(pivot != l)
    {
        swapVillains(pivot, l);
    }
    //sort the part to the left of pivot point
    QuickSort(A, r - A + 1, cmp);
    //sort the part to the right of pivot point
    QuickSort(l + 1, size + A - r - 2, cmp);
}
