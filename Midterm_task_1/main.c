/*
 * In this algorithm I assume that:
 * -> Professor is able to instantly calculate the shortest path to
 *    safehouse from any location (assuming there is no police)
 * -> The Police arrive at junction V[i] after t_i time passed and stay there
 * -> The time is in minutes to get some storytelling
 *
 * Thus, the algorithm goes as follows:
 * 1. Bank of Spain location is set as current location and time = 0
 * 2. Professor calculates the shortest path to the safehouse from current location
 * 3. He goes to the next junction in the calculated path
 * 4. After traversing edge from i to j, time+=edges[i][j]
 *    and Professor checks if police is on the junction j at that time
 *    If yes, then he goes back to junction i, adds the time again,
 *    removes junction j from his map and continues from step 2.
 *    If no, then he continues from step 3.
 * 5. This repeats until he arrives at the safehouse or is cornered by the police
 *
 * Considering the function for finding the shortest path, it is esentially a Dijkstra implementation
 * It iterates through all the nodes always picking unvisited one with the shortest path to destination
 * Then it iterates through its neighbors and updates their paths if necessary
 *
 * The complexity of finding the shortest path is O(n^2) and so the complexity
 * of the whole algorithm is O(n^2) in the best case and O(n^3) in the worst
 *
 *
 * I prepared some different scenarios to check the algorithm
 * You can view different results by commenting/uncommneting
 * lines which define SCENARIO_1 and SCENARIO_2 (you have 4 possible outcomes)
 *
 * To change the number of juntions, modify the "#define N x" line to desirable x
 * Then add/remove/modify edges in the initialize_edges funtion
 * Remember the graph has to be connected for the algorithm to work
 *
 * To change the time when police arrives at a certain junction,
 * modify code inside initialize_police_time function
 * */


#include <stdio.h>

//N is the number of junctions (vertices)
#define N 11
//index of vertex where the safehouse is located
#define SAFEHOUSE 7
//index of vertex where the bank of spain is located
#define BANK_LOCATION 3


//CHECK THE DIFFERENT SCENARIOS! :)
#define SCENARIO_1
#define SCENARIO_2

typedef struct{
    //index of next node in the shortest path to destination
    int next;
    //cost of the shortest path to destination
    int cost_to_end;
    //bool to check if the node was visited
    int visited;
}node;

void add_edge(int edges[N][N], int i, int j, int cost);

void initialize_edges(int edges[N][N]);

int get_index_of_min_dist_to_destination(node path[N]);

void shortest(int destination, int edges[N][N], node path[N]);

void print_path(node path[N], int start);

void initialize_police_time(int police_time[N]);

void arrive_at_junction(int index, int time, int arr[N]);

void delete_from_map(int junction, int edges[N][N]);

int main() {

    //roads are bidirectional, so edges[i][j] == edges[j][i]
    //edges[i][j] <= 0 means there is no such edge
    int edges[N][N] = {0};
    initialize_edges(edges);

    int police_time[N] = {0};
    initialize_police_time(police_time);

    int current_location = BANK_LOCATION;
    int destination = SAFEHOUSE;
    int time = 0;
    node path[N] = {0};
    int police_were_at_the_previous = 0;
    int previous_location = current_location;
    shortest(destination, edges, path);

    printf("Professor starts at node %d\n", current_location);

    //n^2 at worst for the whole loop
    while(current_location != destination)
    {
        printf("\nProfessor is at junction %d and %d minutes have passed\n", current_location, time);
        //check if police are there
        if(police_time[current_location] > 0 && police_time[current_location] < time)
        {
            printf("The police were already at the junction, so he has to go back to junction %d\n", previous_location);
            if(police_were_at_the_previous)
            {
                printf("But he is unable as the police are also there\n");
                printf("He is surrounded between junctions %d and %d\n", current_location, previous_location);
                printf("He was able to run from them for %d minutes\n", time);
                return 0;
            }
            police_were_at_the_previous = 1;
            time += edges[current_location][previous_location];
            delete_from_map(current_location, edges);
            int tmp = previous_location;
            previous_location = current_location;
            current_location = tmp;
            continue;
        }
        //if police were at the previous
        if(police_were_at_the_previous)
        {
            printf("The police were at previous junction (%d) so Professor finds a new shortest route\n", previous_location);
            //this is invoked at most n times and has O(n^2) complexity
            shortest(destination, edges, path);
            police_were_at_the_previous = 0;
        }

        if(path[current_location].cost_to_end == -1)
        {
            printf("Professor was cornered by police and is unable to get to the safehouse\n");
            printf("He was able to run from them for %d minutes\n", time);
            return 0;
        }

        printf("Proffesor has to follow the path:\n");
        print_path(path, current_location);
        //add the time and traverse the edge
        time += edges[current_location][path[current_location].next];
        previous_location = current_location;
        current_location = path[current_location].next;
    }

    printf("The professor arrived at the safehouse in %d minutes\n", time);
    if(police_time[destination] > 0 && police_time[destination] < time)
    {
        printf("But the police were already there and caught him\n");
    }
    else
    {
        printf("And was able to hide from the police\n");
    }

    return 0;
}

void add_edge(int edges[N][N], int i, int j, int cost)
{
    if(i >= N || j >= N)
        return;
    edges[i][j] = cost;
    edges[j][i] = cost; 
}

void initialize_edges(int edges[N][N])
{
    add_edge(edges, 3, 1, 2);
    add_edge(edges, 3, 4, 6);
    add_edge(edges, 3, 6, 4);
    add_edge(edges, 8, 5, 1);
    add_edge(edges, 8, 4, 3);
    add_edge(edges, 10, 7, 1);
    add_edge(edges, 10, 5, 1);
    add_edge(edges, 10, 2, 2);
    add_edge(edges, 4, 0, 1);
    add_edge(edges, 5, 9, 3);
    add_edge(edges, 6, 9, 1);
    add_edge(edges, 2, 0, 1);
    add_edge(edges, 1, 7, 1);
#ifdef SCENARIO_2
    add_edge(edges, 1, 7, 10);
#endif
}

//T(n) = O(n) + O(n^2) = O(n^2)
void shortest(int destination, int edges[N][N], node path[N])
{

    //O(n)
    for(int i = 0; i < N; i++)
    {
        path[i].cost_to_end = -1;
        path[i].next = -1;
        path[i].visited = 0;
    }
    path[destination].cost_to_end = 0;
    path[destination].next = destination;

    //n * (n + n) = O(n^2)
    for(int i = 0; i < N; i++)
    {
        //O(n)
        int current = get_index_of_min_dist_to_destination(path);
        if(current < 0)
        {
            continue;
        }
        path[current].visited = 1;
        //iterate through neighbors
        for(int j = 0; j < N; j++)
        {
            if(edges[current][j] > 0)
            {
                int temp = path[current].cost_to_end + edges[current][j];
                if(path[j].cost_to_end == -1 || path[j].cost_to_end > temp)
                {
                    path[j].cost_to_end = temp;
                    path[j].next = current;
                }
            }
        }
    }
}

//T(n) = O(n)
int get_index_of_min_dist_to_destination(node path[N])
{
    //sets min_dist_index to the first not visited
    int min_dist_index = -1;
    while(path[++min_dist_index].visited);
    for(int i = min_dist_index; i < N; i++)
    {
        if(path[i].visited || path[i].cost_to_end == -1)
        {
            continue;
        }
        if(path[i].cost_to_end < path[min_dist_index].cost_to_end || path[min_dist_index].cost_to_end == -1)
        {
            min_dist_index = i;
        }
    }
    if(path[min_dist_index].cost_to_end == -1)
    {
        return -1;
    }
    return min_dist_index;
}

void print_path(node path[N], int start)
{
    int i = start;
    do {
        printf("%d -> ", i);
        if(path[i].cost_to_end == -1)
        {
            printf("|| This vertex is not connected to the destination!\n");
            return;
        }
        i = path[i].next;
    } while (path[i].next != i);
    printf("%d \n", path[i].next);
}

void initialize_police_time(int police_time[N])
{
    for(int i = 0; i < N; i++)
    {
        police_time[i] = -1;
    }
    //add your code here:
    //Remember that police cannot aarive at the
    arrive_at_junction(9, 4, police_time);
    arrive_at_junction(1, 1, police_time);
#ifdef SCENARIO_1
    arrive_at_junction(3, 3, police_time);
#endif
}

void arrive_at_junction(int index, int time, int arr[N])
{
    arr[index] = time;
}

//T(n) = O(n)
void delete_from_map(int junction, int edges[N][N])
{
    for(int i = 0; i < N; i++)
    {
        //this deletes an edge
        add_edge(edges, i, junction, -1);
    }
}
