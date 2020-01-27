// inserting a node at nth position in a list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
} Node;

struct Node *header;

void Insert(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node)); // creating the memory block for a node
    (*temp).data = data;
    (*temp).link = header;
    header = temp;
}

void Print()
{
    struct Node *temp2 = header;
    printf("The linked list is: ");
    while (temp2 != NULL)
    {
        printf("%d ", (*temp2).data);
        temp2 = (*temp2).link;
    }
    printf("\n");
}

void InsertAtN(int pos, int num)
{
    struct Node *temp3 = header;

    for (int i = 0; i < pos - 2; i++)
    {
        temp3 = (*temp3).link;
    }
    // temp3 now points to n-1th node

    struct Node *temp4 = (struct Node *)malloc(sizeof(struct Node));
    (*temp4).data = num;
    (*temp4).link = (*temp3).link;
    (*temp3).link = temp4;
}

int main()
{
    header = NULL; // initially the list is empty

    // creating a linked list
    Insert(2);
    Insert(6);
    Insert(89);
    Insert(1999);

    Print();
    // Asking user the position at which he wants to enter a number
    int n, x;

    printf("At which position do you want to enter a number?\n");
    scanf("%d", &n);

    printf("Enter the number: ");
    scanf("%d", &x);

    InsertAtN(n, x);
    Print();
    return 0;
}