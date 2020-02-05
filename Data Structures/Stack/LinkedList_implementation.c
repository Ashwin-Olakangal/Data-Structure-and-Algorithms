// implementation of stack ADT using linked list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
} Node;

struct Node *header;

// function to push element at the top of the stack
void Push(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    (*temp).data = x;
    (*temp).link = header;

    header = temp;
}

void Pop()
{
    struct Node *temp = header;
    header = (*temp).link;
    free(temp);
    return;
}

// returns the element at the top of the stack
void Top()
{
    return (*header).data;
}

void Print()
{
    struct Node *temp1 = header;
    printf("The linked list is: ");
    while (temp1 != NULL)
    {
        printf("%d ", (*temp1).data);
        temp1 = (*temp1).link;
    }
    printf("\n");
}

int main()
{
    Push(23);
    Print();
    Push(67);
    Print();
    Pop();
    Print();
    return 0;
}