#include <stdio.h>
#include <stdlib.h>

void debug_array(int *a, int n)
{
    fprintf(stderr, "[ ");
    for(int i = 0; i < n; i++)
        fprintf(stderr, "%d ", a[i]);
    fprintf(stderr, "]\n");
}

void get_shortest_cycle(int *cost, int size);

int calculate_cost(int *path, int *cost, int size)
{
    int cost_ = 0;
    for(int i = 0; i < size - 1; i++)
    {
        cost_ += cost[path[i] * size + path[i+1]];
    }
    cost_ += cost[path[size - 1] * size + path[0]];
    return cost_;
}

int *shortest_path;
int shortest_path_cost = 0;
int *visited;

int *path;
int path_cost;

void set_current_path_as_shortest(int size)
{
    for(int i = 0; i < size; i++)
        shortest_path[i] = path[i];
    shortest_path_cost = path_cost;
}

void create_path(int *cost, int size, int current_row)
{
    if(current_row + 1 == size)
    {
        path_cost = calculate_cost(path, cost, size);
        //for the first iteration
        if(shortest_path_cost == -1 || path_cost < shortest_path_cost)
        {
            set_current_path_as_shortest(size);
        }

        return;
    }
    //we start from i = 1 as 0 will always be the last node to visit
    for(int i = 1; i < size; i++)
    {
        if(i == path[current_row - 1])
            continue;
        if(!visited[i])
        {
            //mark this node as visited
            visited[i] = 1;
            //if there was already a node at this place in the path
            //it means it has to be marked as unvisited
            visited[path[current_row]] = 0;
            //add current node to path
            path[current_row] = i;
            //create the rest of the path
            create_path(cost, size, current_row + 1);
        }
    }
    visited[path[current_row]] = 0;
}

int main() {
    int cost[4][4] =
            {{0, 10, 15, 20},
             {10, 0, 35, 25},
             {15, 35, 0, 30},
             {20, 25, 30, 0}};
    get_shortest_cycle(cost, 4);
    printf("Cost = %d\n", shortest_path_cost);
    debug_array(shortest_path, 4);
    return 0;
}

void get_shortest_cycle(int *cost, int size)
{
    //visited nodes
    //1 - yes, 0 - no
    //allocate the memory
    visited = (int*)calloc(size, sizeof (int));
    shortest_path = (int*)calloc(size, sizeof (int));
    shortest_path_cost = -1;
    path = (int*)calloc(size, sizeof (int));
    path_cost = 0;
    //path is initialized with 0 as every element
    //we start at node 0 and thus in our path
    //0 will be only the last element
    //therefore for all other elements we can treat 0
    //as a value not previously set and ignore it
    create_path(cost, size, 0);
}
