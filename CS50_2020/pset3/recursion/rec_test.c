#include <stdio.h>
#include <cs50.h>

void mergeSort();

int main(void)
{
    int arr[] = {1, 3, 5, 7, 9};

    mergeSort(arr, 0, 4);
}

void mergeSort(int A[], int p, int r)
{
    
    if(p > r)
    {
        return;
    }
    
    int q = (p+r)/2;
    mergeSort(A, p, q);
    mergeSort(A, q + 1, r);

    for(int i = 0; i < sizeof(A); i++)
    {
        printf("%d", A[i]);
    }
    printf("\n");
}
