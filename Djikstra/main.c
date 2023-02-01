#include <stdio.h>

//size of the graph - number of vertices
//must agree with data provided in main()
#define SIZE 4
//the index of the root of the graph
//Dijkstra algorithm will calculate distance to every node
//from the root node
#define ROOT 0
//the following is a bool indicating if there are negative edges
//setting it to 0 will improve performance
//but will fail in most cases that have negative edges
#define NEGATIVE_EDGES 1
//I assume that there are no negative cycles in the graph and ommit checking for them
//But I'm aware that in full implementation this should be checked
//I was absent on this lab and wasn't able to get the info if this was neccessary
//Also I am aware that this implemention could have been written better
//in many ways, but it works, and so I think is good enough for the task

//a directed edge
typedef struct {
    int exists;
    int cost;
}edge;

typedef struct {
    int visited;
    int reached;
    int distance;
}node;

typedef struct {
    edge edges[SIZE][SIZE];
}graph;

graph create_graph(int cost[SIZE][SIZE], int exists[SIZE][SIZE]);

void Djikstra(graph G, node out_distances[SIZE]);

void Print_Distances(node v[SIZE]);

int connections_left(node v[SIZE]);

void calculate_distances(graph G, int has_negative_edges);

void helper(edge edges[SIZE + 1][SIZE + 1], node out_distances[SIZE]);

int main() {
    //costs of all the edges
    //can be negative
    //as the graph can be directed, cost[i][j] is the cost of edge from i to j
    //thus, cost[i][j] can be different from cost[j][i]
    //also the existence of edge i->j does not imply the existence of edge j->i
    int cost[SIZE][SIZE] =
            {{0, -10, 15, 20},
             {10, 0, 35, 25},
             {15, 35, 0, 30},
             {20, 25, 30, 0}};
    //the following matrix indicates which edges are really present in the graph
    //it has to be done that way, as there is no possibility to encode the information
    //about edge existing or not in its cost when we consider also negtive costs
    //(at least not in a simple way)
    //if existing_edges[i][j] == 0
    //then there is no such edge in the graph
    int existing_edges[SIZE][SIZE] =
            {{0, 1, 0, 0},
             {1, 1, 1, 0},
             {1, 1, 1, 1},
             {0, 0, 0, 1}};

    graph Graph = create_graph(cost, existing_edges);

    calculate_distances(Graph, NEGATIVE_EDGES);

    return 0;
}

graph create_graph(int cost[SIZE][SIZE], int exists[SIZE][SIZE])
{
    graph G;// = calloc(1, sizeof(graph));
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            //edge[i][i] from i to i never exists in this case
            if(i == j)
            {
                G.edges[i][j].exists = 0;
                continue;
            }
            if((G.edges[i][j].exists = exists[i][j]))
            {
                G.edges[i][j].cost = cost[i][j];
            }
        }
    }
    return G;
}

int unvisited_reached_with_smallest_distance(node v[SIZE]);

void Djikstra(graph G, node out_distances[SIZE])
{
    node vertices[SIZE] = {};
    int unvisited = SIZE;
    //id of the current node, starts from root
    int current = ROOT;
    vertices[current].reached = 1;
    int temp_d;
    while(unvisited)
    {
        //For the current node, consider all of its unvisited neighbors
        for(int i = 0; i < SIZE; i++)
        {
            //if there is no edge or the node i was already visited, we skip
            if(!G.edges[current][i].exists || vertices[i].visited)
                continue;
            //we calculate the distance through current node
            temp_d = vertices[current].distance + G.edges[current][i].cost;
            //and assign it if it is smaller
            //or was not calculated before
            if(!vertices[i].reached || temp_d < vertices[i].distance)
                vertices[i].distance = temp_d;
            vertices[i].reached = 1;
        }
        vertices[current].visited = 1;
        unvisited--;
        //if there is no more unvisited nodes that can be accesed
        if(!connections_left(vertices))
            break;
        current = unvisited_reached_with_smallest_distance(vertices);
    }
    if(NULL == out_distances)
        return;
    for(int i = 0; i < SIZE; i++)
    {
        out_distances[i] = vertices[i];
    }
}

//returns id of the node
int unvisited_reached_with_smallest_distance(node v[SIZE])
{
    int smallest;
    int j;
    for(j = 0; j < SIZE && (v[j].visited || !v[j].reached); j++);
    smallest = j;
    for(int i = j; i < SIZE; i++)
    {
        if(v[i].visited || !v[i].reached)
            continue;
        if(v[i].distance < v[smallest].distance)
        {
            smallest = i;
        }
    }
    return smallest;
}

void Print_Distances(node v[SIZE])
{
    printf("The distance from root (%d) to every other node\n", ROOT);
    printf("Node id | Distance\n");
    for(int i = 0; i < SIZE; i++)
    {
        if(v[i].visited)
            printf("%d: %d\n", i, v[i].distance);
        else
            printf("%d: unreachable from root\n", i);
    }
}

int connections_left(node v[SIZE])
{
    int c = 0;
    for(int i = 0; i < SIZE; i++)
    {
        if(!v[i].visited && v[i].reached)
            c++;
    }
    return c;
}

void calculate_distances(graph G, int has_negative_edges)
{
    node final_distances[SIZE];
    if(!has_negative_edges)
    {
        Djikstra(G, final_distances);
        Print_Distances(final_distances);
        return;
    }
    edge new_graph[SIZE + 1][SIZE + 1] = {};
    for(int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            new_graph[i][j] = G.edges[i][j];
        }
    }
    for(int i = 0; i < SIZE + 1; i++)
    {
        new_graph[SIZE][i].exists = 1;
    }

    node h[SIZE];

    helper(new_graph, h);

    for(int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            G.edges[i][j].cost += h[i].distance - h[j].distance;
        }
    }

    Djikstra(G, final_distances);

    for(int i = 0; i < SIZE; i++)
    {
        final_distances[i].distance += h[i].distance - h[0].distance;
    }

    Print_Distances(final_distances);

}

void helper(edge edges[SIZE + 1][SIZE + 1], node out_distances[SIZE + 1])
{
    node vertices[SIZE + 1] = {};
    int unvisited = SIZE + 1;
    int current = SIZE;
    vertices[current].reached = 1;
    int temp_d;
    while(unvisited)
    {
        for(int i = 0; i < SIZE; i++)
        {
            if(!edges[current][i].exists || vertices[i].visited)
                continue;
            temp_d = vertices[current].distance + edges[current][i].cost;
            if(!vertices[i].reached || temp_d < vertices[i].distance)
                vertices[i].distance = temp_d;
            vertices[i].reached = 1;
        }
        vertices[current].visited = 1;
        unvisited--;
        if(!connections_left(vertices))
            break;
        current = unvisited_reached_with_smallest_distance(vertices);
    }
    if(NULL == out_distances)
        return;
    for(int i = 0; i < SIZE + 1; i++)
    {
        out_distances[i] = vertices[i];
    }
}


