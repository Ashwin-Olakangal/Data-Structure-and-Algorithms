// Program to print linked list using recursion
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *header;

// print function
void Print_list(struct Node *head)
{
    if (head == NULL)
        return;
    else
    {
        printf("%d ", (*head).data); // swapping this line and the one below it will
        Print_list((*head).link);    // print the list in the reverse order

        /*
        // printing in the reverse order
        Print_list((*head).link);
        printf("%d ", (*head).data);
        */
    }
}

void Insert(int x) // function definition to insert a node in the linked_list
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node)); // making a block of memory for our node using malloc
    temp->data = x;
    temp->link = header;
    header = temp;
}

int main()
{
    header = NULL; // intializing the list as empty

    // driver Program to test the function
    // insertion of nodes will be at the beginning of the list
    // the list is 8,56,34,2
    Insert(2);
    Insert(34);
    Insert(56);
    Insert(8);

    // calling the print function
    printf("\nThe list is : ");
    Print_list(header);
    printf("\n");

    return 0;
}
