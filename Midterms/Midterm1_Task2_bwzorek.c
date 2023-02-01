/*
 * In this algorithm we create a queue and start by adding 1 to it
 * then we pop the first element (1) from the queue and push to it two more
 * elements that are the one popped with 0 and 1 added at the end
 * (in this case 10 and 11)
 * We follow that pattern and for every number int the form x...x we remove from the queue
 * We add x...x0 and x...x1 to the queue
 *
 * The algorithm has time complexity T(n) = O(n)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BINARY_DIGITS 32
//we define it to be standart int size
//could be also replaced by 8 * sizeof(int)

typedef struct Node node;

struct Node {
    char bin[MAX_BINARY_DIGITS + 1];
    int len;
    node* next;
};

node *new_node(node n);

//O(1)
node *next_with_0(node n)
{
    n.bin[n.len] = '0';
    n.bin[++n.len] = '\0';
    node *n_ret = new_node(n);
    return n_ret;
}
//O(1)
node *next_with_1(node n)
{
    n.bin[n.len] = '1';
    n.bin[++n.len] = '\0';
    node *n_ret = new_node(n);
    return n_ret;
}

typedef struct {
    node *head;
    node *tail;
}queue;

//O(1)
node *new_node(node n)
{
    node *new_n = calloc(1, sizeof(node));
    new_n->len = n.len;
    strcpy(new_n->bin, n.bin);
    return new_n;
}

//O(1)
void put(queue *q, node *n)
{
    if(q->head == NULL)
    {
        //n.next = NULL;
        q->head = n;
        q->tail = q->head;
        return;
    }
    q->tail->next = n;
    q->tail = q->tail->next;
}

//O(1)
node *get(queue *q)
{
    node *ret = q->head;
    if(q->head == NULL)
    {
        //error checking coud be added
    }
    if(q->head == q->tail)
    {
        q->head = NULL;
        q->tail = NULL;
    }
    else
    {
        q->head = q->head->next;
    }
    return ret;
}

int main() {
    int n;
    printf("Input N:\n");
    while(scanf("%d", &n) != 1);
    queue Q = {};
    node *first = calloc(1, sizeof(node));
    first->bin[0] = '1';
    first->bin[1] = '\0';
    first->len = 1;
    //we add the first element
    put(&Q, first);
    //then we add 2n elements and remove n (in special order)
    for(int i = 0; i < n; i++)
    {
        node *tmp = get(&Q);
        put(&Q, next_with_0(*tmp));
        put(&Q, next_with_1(*tmp));
        printf("%s ", tmp->bin);
        free(tmp);
    }
    //free the memory - it does not increase the complexity
    //as it also will run n times
    node *tmp;
    while((tmp = get(&Q)) != NULL)
    {
        free(tmp);
    }
//    for(int i = 0; i < n; i++)
//    {
//        node *tmp = get(&Q);
//        free(tmp);
//    }
    printf("\n");
    return 0;
}
