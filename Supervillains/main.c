#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME 20
#define NUMBER_OF_TRIALS 2
#define NUMBER_OF_VILLAINS 5

typedef struct villain
{
    int Strength;
    int Ego;
    char Name[MAX_NAME];
}villain;

typedef struct {
    villain villains[99];
    int size;
    int sum_strength;
}solution;

void addToSolution(solution *s, villain v)
{
    s->villains[s->size++] = v;
    s->sum_strength += v.Strength;
}

void printVillains(villain* arr, int n);

solution assembleTeam(villain *villains, int size);

int main() {

    villain **trials_with_villains;
    trials_with_villains = calloc(NUMBER_OF_TRIALS, sizeof(villain*));

    villain trial1[] = {
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
    villain trial2[] = {
            {
                    6, 1, "Dr Freeze"
            },
            {
                    5, 1, "PYG"
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

    trials_with_villains[0] = trial1;
    trials_with_villains[1] = trial2;

    for(int i = 0; i < NUMBER_OF_TRIALS; i++)
    {
        printf("\nTrial %d.\n", i + 1);
        printf("Available villains:\n");
        printVillains(trials_with_villains[i], NUMBER_OF_VILLAINS);
        solution s = assembleTeam(trials_with_villains[i], NUMBER_OF_VILLAINS);
        printf("\nSolution:\n");
        printf("Number of villains: %d\n", s.size);
        printf("Chosen villains:\n");
        printVillains(s.villains, s.size);
    }
    return 0;
}

int compareVillainsByStrength(villain a, villain b)
{
    if(a.Strength < b.Strength)
    {
        return -1;
    }
    if(a.Strength > b.Strength)
    {
        return 1;
    }
    //a.Ego == b.Ego
    return 0;
}

solution assembleTeam(villain *villains, int size)
{
    //create an array with just egos
    int Egos[size];
    for(int i = 0; i < size; i++)
    {
        Egos[i] = villains[i].Ego;
    }
    solution best = {};
    //check solution with each ego as the max one
    //max ego + 1 = min strength
    for(int i = 0; i < size; i++)
    {
        //iterate through villains and add them if:
        //their ego is smaller/equal
        //and their strength is greater
        solution current = {};
        for(int j = 0; j < size; j++)
        {
            if(villains[j].Ego <= Egos[i] && villains[j].Strength > Egos[i])
            {
                addToSolution(&current, villains[j]);
            }
        }
        if(current.size > best.size)
            best = current;
        else if(current.size == best.size && current.sum_strength > best.sum_strength)
            best = current;
    }
    return best;
}

void printVillains(villain* arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%s %d %d\n", arr[i].Name, arr[i].Strength, arr[i].Ego);
    }
}
