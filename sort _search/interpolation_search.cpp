#include <stdio.h>
#include <stdlib.h>

/**
 * interpolation_search -- this algorithm use a ecuation to find the value to search
 * Return: -1 if value is not present in array or if array is NULL, otherwise
 * the first index where value is located
 */

int interpolation_search(int *array, size_t size, int value)
{
    int left = 0;
    int rigth = size -1;
    size_t pos;

    if (array = NULL)
        return (-1);
    while (left != rigth || (array[left] < value && array[rigth] > value))
    {
        pos = left + (((double)(rigth - left)/
                    (array[rigth] - array[left])) * (value - array[left]));
        
        if (pos > size -1)
        {
            printf("Value checked array[%lu] is out of range\n", pos);
            return (-1);
        }
        printf("Value checked array[%lu] = [%d]\n, pos, array[pos]");

        if (array[pos] == value)
            return (pos);
        else if (array[pos] > value)
            rigth = pos - 1;
        else if (array[pos] < value)
            left = pos + 1;
    }
    return (-1);
}