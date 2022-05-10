#include <stdio.h>
#include <stdbool.h>

#include "helper.h"


void test_sort(int array[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        if (array[i + 1] < array[i])
        {
            printf("Array is not sorted correctly!\n");
            return;
        }
    }
    printf("Good (y)!.\n");
    return;
}


int main(void)
{
    int array[] = {5, -1, 2, 7, 9, 8, 8, -1, 3, 4, 1, 6, 3, 0};
    int length = sizeof(array) / sizeof(int);
    sort(array, length);
    test_sort(array, length);

    int sample[] = {5, -1, 2, 7, 9, 8, 8, -1, 3, 4, 1, 6, 3, 0};
    test_sort(sample, length);

    sort(sample, length);
    test_sort(sample, length);
}