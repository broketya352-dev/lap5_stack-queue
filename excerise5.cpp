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

bool isOpening(char value)
{
    return value == '(' || value == '{' || value == '[';
}

bool isMatching(char opening, char closing)
{
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

bool isBalanced(string expression)
{
    ArrayStack stack;
    char opening;

    for (int i = 0; i < expression.length(); i++)
    {
        char value = expression[i];

        if (isOpening(value))
        {
            if (!stack.push(value))
            {
                cout << "Stack is full!" << endl;
                return false;
            }
        }
        else if (value == ')' || value == '}' || value == ']')
        {
            if (!stack.pop(opening))
            {
                return false;
            }

            if (!isMatching(opening, value))
            {
                return false;
            }
        }
    }

    return stack.isEmpty();
}

void testBalancedParentheses()
{
    string expression;

    cout << "Enter an expression: ";
    getline(cin >> ws, expression);

    if (isBalanced(expression))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Unbalanced" << endl;
    }
}

int main()
{
    testBalancedParentheses();

    return 0;
}