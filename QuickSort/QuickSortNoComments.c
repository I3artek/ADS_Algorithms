#include <printf.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void QuickSort(int A[], int size)
{
    if(size <= 1)
    {
        return;
    }
    int *pivot = A + size - 1;
    int *l = A;
    int *r = A + size - 2;
    while(r + 1 != l)
    {
        if(*r <= *pivot && *l > *pivot)
        {
            swap(r, l);
            l++;
            r--;
        }
        if(*r > *pivot)
        {
            r--;
        }
        if(*l <= *pivot)
        {
            l++;
        }
    }
    if(pivot != l)
    {
        swap(pivot, l);
    }
    QuickSort(A, r - A + 1);
    QuickSort(l + 1, size + A - r - 2);
}
