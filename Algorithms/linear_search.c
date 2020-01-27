
#include <stdio.h>

int main()
{
    int size, x, j = -1, i = 0;
    printf("Enter the size of array:\n");
    scanf("%d", &size);

    int array[size];

    printf("Enter the numbers of array:\n");

    for (i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Which number do you want to search for?\n");
    scanf("%d", &x);

    for (i = 0; i < size; i++)
    {
        if (array[i] == x)
        {
            j = i + 1;
        }
    }

    printf("The position of %d in the array is %d", x, j);
    return 0;
}