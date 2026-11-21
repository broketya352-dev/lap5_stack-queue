#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string url;
    Node *next;

    Node(string url)
    {
        this->url = url;
        next = nullptr;
    }
};

class LinkedStack
{
private:
    Node *top;

public:
    LinkedStack()
    {
        top = nullptr;
    }

    ~LinkedStack()
    {
        clear();
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void push(string url)
    {
        Node *newNode = new Node(url);

        newNode->next = top;
        top = newNode;
    }

    bool pop(string &url)
    {
        if (isEmpty())
        {
            return false;
        }

        Node *temp = top;
        url = top->url;
        top = top->next;

        delete temp;
        return true;
    }

    void clear()
    {
        string url;

        while (!isEmpty())
        {
            pop(url);
        }
    }
};

class BrowserHistory
{
private:
    LinkedStack backStack;
    LinkedStack forwardStack;
    string currentPage;

public:
    BrowserHistory()
    {
        currentPage = "";
    }

    void visit(string url)
    {
        if (currentPage != "")
        {
            backStack.push(currentPage);
        }

        currentPage = url;
        forwardStack.clear();

        cout << "Visit: " << url;
        cout << " -> Current: " << currentPage << endl;
    }

    void back()
    {
        if (backStack.isEmpty())
        {
            cout << "Cannot go back! No previous page." << endl;
            return;
        }

        forwardStack.push(currentPage);
        backStack.pop(currentPage);

        cout << "Back() -> Current: " << currentPage << endl;
    }

    void forward()
    {
        if (forwardStack.isEmpty())
        {
            cout << "Cannot go forward! No next page." << endl;
            return;
        }

        backStack.push(currentPage);
        forwardStack.pop(currentPage);

        cout << "Forward() -> Current: " << currentPage << endl;
    }
};

void testBrowserHistory()
{
    BrowserHistory browser;

    browser.visit("google.com");
    browser.visit("github.com");

    browser.back();
    browser.forward();

    browser.back();
    browser.back();
    browser.back();
}

int main()
{
    testBrowserHistory();

    return 0;
}