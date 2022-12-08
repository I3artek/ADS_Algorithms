#include <stdio.h>


typedef struct field
{
    int queen;
    int attacked;
}field;
field **calculate(int n);
void print_solution(field **table, int size);

int main() {
    int size = 17;
    field **solution = calculate(size);
    print_solution(solution, size);
    return 0;
}
