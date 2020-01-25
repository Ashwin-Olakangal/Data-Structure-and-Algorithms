#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
} Node;

struct Node *head; // pointer to store address to the first node

// Insert an integer at the END of the list
void Insert(int data)
{
}

// print all the elements in the list
void Print()
{
}

// Delete node at position n
void Delete(int n)
{
    struct Node *temp1 = head; // creating a copy of head pointer

    if (n == 1)
    {
        head = temp1->link; // head now points to second node
        free(temp1);
        return;
    }
    // going to n-1th node
    for (int i = 0; i < n - 2; i++)
    {
        temp1 = temp1->link; // temp1 points to n-1th node
    }

    struct Node *temp2 = temp1->link; // nth node
    temp1->link = temp2->link;        // (n+1)th node
    free(temp2);                      // deleting the nth node
}

int main()
{
    head = NULL; // the list is empty
    Insert(2);
    Insert(89);
    Insert(4);
    Insert(6);
    Print();
    int n;
    printf("Enter a position to delete: ");
    scanf("%d", &n);
    Delete(n);
    Print();
}