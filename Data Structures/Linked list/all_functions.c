#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *header;

void Insert(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = x;
    temp->link = header;
    header = temp;
}

void InsertAtN(int pos, int num)
{
    struct Node *temp = header;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->link; // temp at the end points to n-1th node
    }

    struct Node *temp2 = (struct Node *)malloc(sizeof(struct Node));
    temp2->data = num;
    temp2->link = temp->link; // points to nth node;
    temp->link = temp2;
}

void Print()
{
    struct Node *temp3 = header;

    printf("The list is: ");
    while (temp3 != NULL)
    {
        temp3 = temp3->link;
    }
    printf("\n");
}

void Print_recrusion(struct Node *head)
{
    struct Node *temp = header;
    if (head == NULL)
        return;

    pritnf("%d ", temp->data);
    Print_recrusion(temp->link); // prints the list in reverse order
}

void Reverse()
{
    struct Node *current, *prev, *next;
    current = header;
    prev = NULL;

    while (current != NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    header = prev;
}

void Delete(int pos)
{
    struct Node *temp5 = header;
    for (int i = 0; i < pos - 2; i++)
    {
        temp5 = temp5->link; // points to n-1th node
    }
    struct Node *temp6 = temp5->link; //nth node
    temp5->link = temp6->link;        // n+!th node
    free(temp6);                      // deleting the nth node
}

int main()
{
    //driver program for testing

    return 0;
}