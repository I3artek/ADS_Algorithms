#include <stdio.h>
#include "queue.h"

int main() {
    int n;
    printf("Input N:\n");
    while(scanf("%d", &n) != 1);
    queue Q = {};
    node first = {};
    first.bin[0] = '1';
    first.bin[1] = '\0';
    first.len = 1;
    put(&Q, first);
    for(int i = 0; i < n; i++)
    {
        node *tmp = get(&Q);
        put(&Q, next_with_0(*tmp));
        put(&Q, next_with_1(*tmp));
        printf("%s ", tmp->bin);
        free(tmp);
    }
    //free the memory - it does not increase the complexity
    for(int i = 0; i < n; i++)
    {
        node *tmp = get(&Q);
        free(tmp);
    }
    printf("\n");
    return 0;
}
