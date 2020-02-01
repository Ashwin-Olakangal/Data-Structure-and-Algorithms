// reversing a linked list using recursion
#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *header;

void Reverse(struct Node *p)
{
    if ((*p).link == NULL)
    {
        header = p;
        return;
    }
    Reverse((*p).link);
    struct Node *q = (*p).link;
    (*q).link = p;
    p->link = NULL;
}

void Insert(int x) // function definition to insert a node in the linked_list
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node)); // making a block of memory for our node using malloc
    temp->data = x;
    temp->link = header;
    header = temp;
}

void Print() // function to print out the linked list
{
    struct Node *temp = header; // temp is used, so that our original head pointer is not modified
    printf("list is: ");
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    header = NULL;
    Insert(2);
    Insert(6969);
    Insert(010);
    Insert(007);

    printf("List before reversing: ");
    Print();

    Reverse(header);
    printf("List after reversing: ");
    Print();

    return 0;
}