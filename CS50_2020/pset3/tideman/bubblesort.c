#include <stdio.h>


int main(void)
{
    int temp;
    int arr_len = 10;
    
    int arr[] = {2, 9, 4, 5, 0, 3, 6, 8, 7, 1};

    for(int i = 0; i < arr_len; i++)
    {
        for(int j = i; j < arr_len; j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(int i = 0; i < arr_len; i++)
    {
        printf("%d, ", arr[i]);
    }

    printf("\n");

}