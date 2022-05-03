#include <stdio.h>
#include <string.h>
#include <math.h>

#include "helper.h"

#define text1 "random5000.txt"
#define text2 "random10000.txt"
#define text3 "random50000.txt"
#define text4 "reversed5000.txt"
#define text5 "reversed10000.txt"
#define text6 "reversed50000.txt"
#define text7 "sorted5000.txt"
#define text8 "sorted10000.txt"
#define text9 "sorted50000.txt"

#define TOTAL 9


int main(int argc, char *argv[])
{
    char *list[] = {text1, text2, text3, text4, text5, text6, text7, text8, text9};

    if (argc != 2)
    {
        printf("Usage: ./sort filename\n");
        return 1;
    }

    int count = 0;
    for (int i = 0; i < TOTAL; i++)
    {
        if (strcmp(argv[1], list[i]) == 0)
        {
            count++;
        }
    }
    if (count != 1)
    {
        printf("Could not open file.sort/\n");
        return 1;
    }

    char *text = argv[1];

    FILE *open = fopen(text, "r");
    if (open == NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    }

    char word[100];
    count = 0;
    while (fscanf(open, "%s", word) != EOF)
    {
        count++;
    }
    fclose(open);

    // determine size of int array
    int array[count];

    // put every number from file into array
    open = fopen(text, "r");
    if (open == NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    }

    char s[100];
    int index = 0;
    while (fscanf(open, "%s", s) != EOF)
    {
        int number = turn_to_number(s);
        array[index] = number;
        index++;
    }
/*
    for (int i = 0; i < count; i++)
    {
        printf("%i\n", array[i]);
    }
*/
    fclose(open);

    const int LENGTH = count;
    sort(array, LENGTH);
    for (int i = 0; i < LENGTH; i++)
    {
        printf("%i\n", array[i]);
    }
    return 0;
}
