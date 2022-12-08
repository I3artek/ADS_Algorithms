#include <stdio.h>

void printArray(int *A, int n);

void QuickSort(int A[], int size);

int main() {
    int A[] = {2,4,6,7,4,3,5,8,8,9,1,2,3,4,6};
    int size = 15;
    printArray(A, size);
    QuickSort(A, size);
    printArray(A, size);
    return 0;
}
