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
