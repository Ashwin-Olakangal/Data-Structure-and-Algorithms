// doubly linked list and some useful operations
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *header;

struct Node *GetNewNode(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    (*newNode).data = x;
    (*newNode).prev = NULL;
    (*newNode).next = NULL;
    return newNode;
}

void InsertAtHead(int x)
{
    struct Node *temp = GetNewNode(x);
    if (header == NULL)
    {
        header = temp; // header is now pointing to the new node instead of NULL
        return;
    }
    (*header).prev = temp;
    (*temp).next = header;
    header = temp;
}

void ReversePrint()
{
    struct Node *temp = header;
    if (temp == NULL)
        return;

    while (temp != NULL)
    {
        printf("%d ", (*temp).data);
        temp = (*temp).prev; // will change to (*temp).next for forward printing
    }
    printf("\n");
}

void Print()
{
    struct Node *temp = header;
    if (temp == NULL)
        return;

    while (temp != NULL)
    {
        printf("%d ", (*temp).data);
        temp = (*temp).next; // will change to (*temp).next for forward printing
    }
    printf("\n");
}

int main()
{
    header = NULL;

    // driver program for testing
    InsertAtHead(2);
    InsertAtHead(89);
    InsertAtHead(6969);

    printf("The list is: ");
    Print();

    printf("The list in reverse order is: ");
    ReversePrint();

    return 0;
}