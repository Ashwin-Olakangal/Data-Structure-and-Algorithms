// stack can be used to traverse/reverse a list
// Author: amm0
#include <bits/stdc++.h>
using namespace std;

class Stack // creating a class called Stack
{
private:
    char arr[10]; // Stack memory in form of array
    int top = -1; // used to point to the top of the stack
public:
    void Push(char x);
    void Pop();
    void Print();
    void Reverse(Stack S);
    int Top();
    bool IsEmpty();
};

void Stack::Push(char x)
{
    if (top == 9) // condition for overflow ( top == MAX_SIZE-1 )
    {
        printf("ERROR: Stack overflow!");
        return;
    }
    arr[++top] = x; // increment the top value and store x
}

void Stack::Pop()
{
    if (top == -1) // condition for stack to be empty
    {
        printf("ERROR: The stack is empty!");
        return;
    }
    // decrement the top value,
    //we know don't care about what that memory location holds
    top--;
}

int Stack::Top()
{
    return arr[top];
}

bool Stack::IsEmpty()
{
    return (top == -1);
}
void Stack::Reverse(Stack S)
{
    // loop to reverse and pop elements from top of the stack
    for (int i = 0; i < 10; i++)
    {
        arr[i] = S.Top(); // saving numbers in rverse order
        S.Pop();
    }
}

// function to print out aur array implementation of stack
void Stack::Print()
{
    cout << "The stack is: ";
    for (int i = 0; i <= top; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}

int main()
{
    cout << "Enter a string of length 10: " << endl;

    Stack S;
    // this array declaration is different from the one used in above method definitions
    // This is used ONLY for taking in inputs
    char c_array[10];
    gets(c_array);

    // performing relevent operations
    for (int i = 0; i < sizeof(c_array); i++)
    {
        S.Push(c_array[i]);
    }
    S.Print();

    S.Reverse(S);

    cout << "After reversal " << endl;
    S.Print();

    return 0;
}