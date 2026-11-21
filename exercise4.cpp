#include <iostream>
using namespace std;

class Node
{
public:
    int customerID;
    Node *next;

    Node(int customerID)
    {
        this->customerID = customerID;
        next = nullptr;
    }
};

class LinkedQueue
{
private:
    Node *front;
    Node *rear;
    int count;

public:
    LinkedQueue()
    {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    ~LinkedQueue()
    {
        while (front != nullptr)
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }

        rear = nullptr;
        count = 0;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void displayQueue()
    {
        Node *current = front;

        cout << "Queue: [";

        while (current != nullptr)
        {
            cout << current->customerID;

            if (current->next != nullptr)
            {
                cout << ", ";
            }

            current = current->next;
        }

        cout << "]" << endl;
        cout << "Customers waiting: " << count << endl;
    }

    void enqueue(int customerID)
    {
        Node *newNode = new Node(customerID);

        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        count++;

        cout << "Enqueue(" << customerID << ") -> ";
        displayQueue();
    }

    bool dequeue(int &customerID)
    {
        if (isEmpty())
        {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return false;
        }

        Node *temp = front;
        customerID = front->customerID;

        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;
        count--;

        cout << "Dequeue() -> Served: " << customerID << " / ";
        displayQueue();

        return true;
    }
};

void testBankCounterQueue()
{
    LinkedQueue queue;
    int customerID;

    queue.enqueue(101);
    queue.enqueue(102);

    queue.dequeue(customerID);
    queue.dequeue(customerID);
    queue.dequeue(customerID);
}

int main()
{
    testBankCounterQueue();

    return 0;
}