// implementation of reversal of linked list
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
} Node;

struct Node *header; // points to the header Node

// function to insert a node at the beginning of a linked list
void Insert(int number)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    (*temp).data = number;
    (*temp).link = header;
    header = temp;
}

// function to print out the linked list
void Print()
{
    struct Node *temp2;
    temp2 = header;

    printf("The list is: ");
    while (temp2 != NULL)
    {
        printf("%d", (*temp2).data); // printing out the value of the currrent node
        temp2 = (*temp2).link;       // moving to the next node
    }
    printf("\n");
}

// function to reverse a linked list
void Reverse()
{
    struct Node *current, *prev, *next;
    current = header;
    prev = NULL;
    while (current != NULL)
    {
        next = (*current).link; // pointing to the next Node
        (*current).link = prev; // changing the address of the current node to previous node
        prev = current;         // making the previous same as current
        current = next;         // moving current to next
    }
    header = prev;
}

int main()
{
    header = NULL; // initiaing the list as empty

    // creating a list: 8732
    // remember that the insert function will insert a node at the beginning
    // Hence, the last entry will be first in the list
    Insert(2);
    Insert(3);
    Insert(7);
    Insert(8);
    Print();

    printf("After reversal ");
    Reverse();
    Print();

    return 0;
}
