// stl based implementation of stack for reversal of string
#include <iostream>
#include <stack>

using namespace std;

void Reverse(char c[], int n)
{
    stack<char> S;

    // loop for pushing elements to the top of stack
    for (int i = 0; i < n; i++)
    {
        S.push(c[i]);
    }

    // loop for pop
    for (int i = 0; i < n; i++)
    {
        c[i] = S.top(); // overwrite the character at index i
        S.pop();        // perform pop
    }
}

int main()
{
    char c[10];
    cout << "Enter a string" << endl;
    gets(c);
    Reverse(c, sizeof(c));

    cout << "The string after reversal is: " << endl;
    for (int i = 0; i < sizeof(c); i++)
    {
        cout << c[i];
    }
}