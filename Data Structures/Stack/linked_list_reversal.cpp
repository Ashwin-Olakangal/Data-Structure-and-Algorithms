// Author: amm0
#include <bits/stdc++.h>
#include <stack>
using namespace std;

stack<struct Node *> S;

struct Node
{
    int data;
    Node *next;
};

struct Node *header;

void Reverse()
{
    Node *temp = header;

    // pushing the addresses of nodes to stack
    while (temp != NULL)
    {
        S.push(temp);
        temp = temp->next;
    }

    temp = S.top(); // pointing the temp pointer to the address at the top of the stack
    header = temp;
    S.pop();
    // popping out addresses in reverse order
    while (!S.empty())
    {
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = NULL; // making the final node point to NULL
}

void Insert(int x) // function definition to insert a node in the linked_list
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node)); // making a block of memory for our node using malloc
    temp->data = x;
    temp->next = header;
    header = temp;
}

void Print() // function to print out the linked list
{
    struct Node *temp = header; // temp is used, so that our original head pointer is not modified
    cout << "The list is: ";
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }

    cout << endl;
}

int main()
{

    // Driver program for testing
    Insert(34);
    Insert(9898);
    Insert(70);

    Print();

    Reverse();
    cout << "After reversal ";

    Print();

    return 0;
}