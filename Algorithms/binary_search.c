#include <stdio.h>
#include <stdlib.h>

//The median is the ((lower bound+upper bound + 1)/2)th item, when there are odd number of elements
// when there are even number of elements then: (lower bound+upper bound )/2

int main()
{

    int lower = 0, upper = 6, array[7], search, location = -1;

    printf("Enter the  numbers in array: \n");

    for (int i = 0; i < 7; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Which number do you want to locate?\n");
    scanf("%d", &search);

    while (lower <= upper)
    {
        int mid = (lower + upper) / 2;

        if (array[mid] < search)
        {
            lower = mid + 1;
        }

        else if (array[mid] > search)
        {
            upper = mid - 1;
        }
        else
        {
            location = mid + 1; // offsetting the starting of index with 0
            break;
        }
    }

    printf("The number %d is located at position %d.", search, location);
    return 0;
}