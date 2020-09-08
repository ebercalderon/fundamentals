#include <stdio.h>
#include <stdlib.h>

/**
 * printarray -- its a function that print the slice of array
 * 
 */

void printarray(int *array, int left, int rigth)
{
    char sep = '\0';

    printf("Searching in array: ");
    for (; left <= rigth; left++)
    {
        sep = left == rigth ? '\n' : ',';
        printf(" %d%c", array[left], sep);
    }
}

/**
 * binary_search - ---
 * Return -1 if value is not present in array or if array is NULL, otherwise
 * the first index where is located
 */

int binary_search(int *array, size_t size, int value)
{
    int left = 0;
    int rigth = size -1;
    int mid = 0;

    if (array == NULL)
        return (-1);
    while (left <= rigth)
    {
        printarray(array, left, rigth);
        mid = (left + rigth) / 2;
        if (array[mid] == value)
            return (mid);
        else if (array[mid] < value)
            left = mid + 1;
        else if (array[mid] > value)
            left = mid - 1;
    }
    return (-1);
}