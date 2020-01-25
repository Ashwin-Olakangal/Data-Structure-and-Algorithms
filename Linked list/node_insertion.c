// Inserting Node in a linked list

#include <stdio.h>
#include <stdlib.h>

struct Node // creating a Node struct for data and link information
{
    int data;
    struct Node *link;
} Node;

struct Node *head; // global variable, can be accessed from anywhere

void Insert(int x) // function definition to insert a node in the linked_list
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node)); // making a block of memory for our node using malloc
    temp->data = x;
    temp->link = head;
    head = temp;
}

void Print() // function to print out the linked list
{
    struct Node *temp = head; // temp is used, so that our original head pointer is not modified
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
    head = NULL; // empty list

    // Taking User input
    printf("How many numbers?: ");
    int n, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        // Taking in the numbers
        printf("Enter the number: \n");
        scanf("%d", &x);
        Insert(x); // inserting in the linked_list
        Print();   // Printing out the linked_list
    }
}
