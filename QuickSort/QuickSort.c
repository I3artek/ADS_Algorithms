#include <printf.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void printArray(int *A, int n)
{
    printf("[ ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("]\n");
}

void QuickSortWithComments(int A[], int size)
{
    if(size <= 1)
    {
        return;
    }

    printf("Now sorting:\n");
    printArray(A, size);

    //we choose the last element as the size
    int *pivot = A + size - 1;
    //l is the element most to the left
    int *l = A;
    //r is the element most to the right
    int *r = A + size - 2;
    //we loop until l and r are like this: rl
    while(r + 1 != l)
    {
        //we swap the numbers on l and r if r <= p < l
        if(*r <= *pivot && *l > *pivot)
        {
            swap(r, l);
            l++;
            r--;
        }
        //if r > p we move r to the left
        if(*r > *pivot)
        {
            r--;
        }
        //if l <= p we move l to the right
        if(*l <= *pivot)
        {
            l++;
        }
    }
    //we swap pivot and l (because l is on the right now)
    //the if is needed because swapping often breaks when pass the same pointer twice
    if(pivot != l)
    {
        swap(pivot, l);
    }
    //pivot point is now in the correct place
    //all the numbers to the left are smaller
    //all the numbers to the right are bigger
    /*
     * [ X X X X X X X p X X X X X ]
     *               ^ ^         ^
     *               r l         p
    */

    printf("Sorted:\n");
    printArray(A, size);
    printf("The left:\n");
    printArray(A, r - A + 1);
    printf("Pivot: %d\n", *l);
    printf("The right:\n");
    printArray(l + 1, size + A - r - 2);

    //sort the part to the left of pivot point
    QuickSortWithComments(A, r - A + 1);
    //sort the part to the right of pivot point
    QuickSortWithComments(l + 1, size + A - r - 2);
}

void QuickSort(int A[], int size)
{
    if(size <= 1)
    {
        return;
    }
    //we choose the last element as the size
    int *pivot = A + size - 1;
    //l is the element most to the left
    int *l = A;
    //r is the element most to the right
    int *r = A + size - 2;
    //we loop until l and r are like this: rl
    while(r + 1 != l)
    {
        //we swap the numbers on l and r if r <= p < l
        if(*r <= *pivot && *l > *pivot)
        {
            swap(r, l);
            l++;
            r--;
        }
        //if r > p we move r to the left
        if(*r > *pivot)
        {
            r--;
        }
        //if l <= p we move l to the right
        if(*l <= *pivot)
        {
            l++;
        }
    }
    //we swap pivot and l (because l is on the right now)
    //the if is needed because swapping often breaks when pass the same pointer twice
    if(pivot != l)
    {
        swap(pivot, l);
    }
    //pivot point is now in the correct place
    //all the numbers to the left are smaller
    //all the numbers to the right are bigger
    /*
     * [ X X X X X X X p X X X X X ]
     *               ^ ^         ^
     *               r l         p
    */
    //sort the part to the left of pivot point
    QuickSort(A, r - A + 1);
    //sort the part to the right of pivot point
    QuickSort(l + 1, size + A - r - 2);
}
