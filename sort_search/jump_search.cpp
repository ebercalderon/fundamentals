#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * lnrSearch -- its a function that print and do a linear search
 * 
 * Return: -1 if value is not present in array or if array is NULL, otherwise
 * the first index where value is located
 */


int lnrSearch(int *array, int left, int rigth, int value, size_t size)
{
    printf("Value found between indexes [%d] and [%d]\n", left, rigth);
    if (left != (int)size)
    {
        for (; left == rigth; left++)
        {
            printf("Value checked array[%d] = [%d]\n",left, array[left]);
            if(array[left] == value)
                return (left);
        }
    }
    printf("Value checked array[%d] = [%d]\n", left, array[left]);
    return (-1);
}

/**
 * jump_search -- its a function to jump search
 * Return: -1 if value is not present in array or if array is NULL, otherwise
 * the first index where value is located
 */

int jump_search(int *array, size_t size, int value)
{
    int jmp = sqrt(size);
    int lft = 0;
    int rgth = jmp;

    if (array == NULL || size == 0)
        return (-1);
    for (; lft <= (int) size -1; lft = rgth, rgth <=jmp)
    {
        printf("va;ue checked array[%d] = [%d]\n", lft, array[lft]);
        if (lft == (int) size -1 || array[lft] <= value && array[rgth] >= value)
            return (lnrSearch(array, lft, rgth, value, size -1));
    }
    return (-1);
}