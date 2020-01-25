// creating and deleting a node in a linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
} Node;

struct Node *header_address;

void Insert(int user_number)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    (*temp).data = user_number;
    (*temp).link = header_address;
    header_address = temp;
}

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

void Delete(int position)
{
    struct Node *temp1 = header_address;

    if (position == 1)
    {
        header_address = (*temp1).link;
        free(temp1);
        return;
    }

    for (int i = 0; i < position - 2; i++)
    {
        temp1 = (*temp1).link;
    }
    struct Node *temp2 = (*temp1).link;
    (*temp1).link = (*temp2).link;
    free(temp2);
}

int main()
{
    header_address = NULL; // intially the list is empty

    int n, i, x;

    printf("How many numbers do you want to enter in the list?\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &x);
        Insert(x);
        Print();
    }

    char choice;
    int pos;
    printf("Would you like to delete a number?\n");
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y')
    {
        printf("Which position do you want to delete?\n");
        scanf("%d", &pos);
        Delete(pos);
        printf("The linked list is now:\n");
        Print();
    }
    return 0;
}