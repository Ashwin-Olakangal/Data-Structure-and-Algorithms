#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
} Node;

struct Node *header_address; // pointer to store address to the first node

// Insert an integer at the END of the list
void Insert(int user_number)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    (*temp).data = user_number;
    (*temp).link = header_address;
    header_address = temp;
}

// print all the elements in the list
void Print()
{
    struct Node *temp1 = header_address;
    printf("The linked list is: ");
    while (temp1 != NULL)
    {
        printf("%d ", (*temp1).data);
        temp1 = (*temp1).link;
    }
    printf("\n");
}

// Delete node at position n
void Delete(int n)
{
    struct Node *temp1 = header_address; // creating a copy of head pointer

    if (n == 1)
    {
        header_address = temp1->link; // head now points to second node
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
    header_address = NULL; // the list is empty

    // driver program for testing
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