#include <stdio.h>
#include <math.h>

int allocate(int length, int side);
void divide(int array[], int left[], int right[], int length);
void rearrange(int subs_array[], int left[], int right[], int length);
void sort(int array[], int length);
void swap(int *ptr1, int *ptr2);

int turn_to_number(char *word);



/*
int main(void)
{
    int array[] = {5, -1, 2, 7, 9, 8, 8, -1, 3, 4, 1, 6, 3, 0};
    int length = 14;
    sort(array, length);
    for (int i = 0; i < length; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
}
*/

int allocate(int length, int side)
{
    int left_count = 0;
    int right_count = 0;

    if (length % 2 == 0)
    {
        left_count = length / 2;
    }
    else
    {
        left_count = (length + 1) / 2;
    }
    right_count = length - left_count;

    if (side < 0)
    {
        return left_count;
    }
    else
    {
        return right_count;
    }
}



void divide(int array[], int left[], int right[], int length)
{
    int left_count = allocate(length, -1);
    int right_count = allocate(length, 1);

    int half = right_count;

    // 1 5 3 2 4 6
    // 1 5 3
    // 2 4 6

    for (int i = 0; i < half; i++)
    {
        left[i] = array[i];
        if (right_count < left_count)
        {
            right[i] = array[i + half + 1];
        }
        else
        {
            right[i] = array[i + half];
        }
    }
    if (right_count < left_count)
    {
        left[left_count - 1] = array[left_count - 1];
    }
    return;
}


void rearrange(int subs_array[], int left[], int right[], int length)
{
    int left_count = allocate(length, -1);
    int right_count = allocate(length, 1);

    // 2 4 5 7 | 0 1 3 6
    int cursor1 = 0;
    int cursor2 = 0;

    for (int i = 0; i < length; i++)
    {
        if (cursor1 >= left_count || cursor2 >= right_count)
        {
            if (cursor2 >= right_count && cursor1 < left_count)
            {
                subs_array[i] = left[cursor1];
                cursor1++;
            }
            else if (cursor1 >= left_count && cursor2 < right_count)
            {
                subs_array[i] = right[cursor2];
                cursor2++;
            }
        }

        else
        {
            if (left[cursor1] <= right[cursor2])
            {
                subs_array[i] = left[cursor1];
                cursor1++;
            }
            else
            {
                subs_array[i] = right[cursor2];
                cursor2++;
            }
        }
    }
    return;
}



void sort(int array[], int length)
{
    int left_count = allocate(length, -1);
    int right_count = allocate(length, 1);

    int left[left_count];
    int right[right_count];

    // base case
    if (length == 1)
    {
        return;
    }
    else if (length == 2)
    {
        if (array[0] <= array[1])
        {
            return;
        }
        else
        {
            swap(&array[0], &array[1]);
            return;
        }
    }

    // divide array into 2 halves
    divide(array, left, right, length);

    // sort each half in order
    sort(left, left_count);
    sort(right, right_count);

    // merge those 2 halves
    rearrange(array, left, right, length);
    return;
}


void swap(int *ptr1, int *ptr2)
{
    int a = *ptr1;
    int b = *ptr2;

    int *tmp = &a;
    *ptr1 = b;
    *ptr2 = *tmp;
    return;
}



int turn_to_number(char *word)
{
    int number = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (word[i] != '-')
        {
            int m = ((int) word[i] - 48) * pow(10, (n - 1 - i));
            number += m;
        }
    }
    if (word[0] == '-')
    {
        number *= -1;
    }
    return number;
}







/*
int main(void)
{
    //int array[] = {2, 4, 5, 7, 8, 10, 0, 1, 3, 6, 9};
    //int length = 11;

    //int array[] = {2};
    //int length = 1;

    int array[] = {5, 2, 7, 9, 8, 8, 3, 4, 1, 6, 3, 0};
    int length = 12;

    int left_count = allocate(length, -1);
    int right_count = allocate(length, 1);

    //printf("%i %i\n", left_count, right_count);

    int left[left_count];
    int right[right_count];


    divide(array, left, right, length);

    printf("left: ");
    for (int i = 0; i < left_count; i++)
    {
        printf("%i ", left[i]);
    }
    printf("\n");
    printf("right: ");
    for (int i = 0; i < right_count; i++)
    {
        printf("%i ", right[i]);
    }
    printf("\n");

    int subs_array[length];
    rearrange(subs_array, left, right, length);

    printf("subs_array: ");
    for (int i = 0; i < length; i++)
    {
        printf("%i ", subs_array[i]);
    }
    printf("\n");
    printf("left_count: %i\n", left_count);
    printf("right_count: %i\n", right_count);
    printf("\n");

    sort(array, length);
    printf("array: ");
    for (int i = 0; i < length; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
    printf("\n");

    return 0;
}
*/
