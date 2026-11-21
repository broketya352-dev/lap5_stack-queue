#include <iostream>
#include <string>
using namespace std;

class ArrayStack
{
private:
    char arr[1000];
    int top;

public:
    ArrayStack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == 999;
    }

    bool push(char value)
    {
        if (isFull())
        {
            return false;
        }

        top++;
        arr[top] = value;
        return true;
    }

    bool pop(char &value)
    {
        if (isEmpty())
        {
            return false;
        }

        value = arr[top];
        top--;
        return true;
    }
};

void testStringReversal()
{
    ArrayStack stack;
    string input;
    char value;

    cout << "Enter a string: ";
    getline(cin >> ws, input);

    for (int i = 0; i < input.length(); i++)
    {
        if (!stack.push(input[i]))
        {
            cout << "Stack is full!" << endl;
            return;
        }
    }

    cout << "Reversed string: ";

    while (!stack.isEmpty())
    {
        stack.pop(value);
        cout << value;
    }

    cout << endl;
}

int main()
{
    testStringReversal();

    return 0;
}