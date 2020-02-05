// Implementation of stack ADT using arrays
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];
int top = -1; // used to keep track of the top of the stack

// Function for pushing a number to the top of stack
void Push(int x)
{
    if (top == MAX_SIZE - 1) // condition for stack overflow
    {
        printf("ERROR: Stack Overflow");
        return;
    }

    arr[++top] = x; // increments the top of stack, and inserts x
}

// Function to pop(remove) element from top of stack
void Pop()
{
    if (top == -1)
    {
        printf("ERROR: The stack is empty. Cannot pop elements");
        return;
    }
    // we don't care about the value that is now there in the memory location
    // it is equivalent to garbage for us, as it is not part of our stack anymore
    top--;
}

void Top()
{
    return arr[top];
}

void Print()
{
    printf("The stack is: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    // Driver program for testing
    Push(2);
    Push(67);
    Push(673);
    Print();
    Push(89898);
    Push(007);
    Print();
    Pop();
    Print();
    Pop();
    Print();

    return 0;
}