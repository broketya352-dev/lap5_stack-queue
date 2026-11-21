#include <iostream>
using namespace std;

class ArrayQueue
{
private:
    int arr[100];
    int front;
    int rear;
    int count;

public:
    ArrayQueue()
    {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == 100;
    }

    void displayQueue()
    {
        cout << "Queue: [";

        for (int i = 0; i < count; i++)
        {
            cout << arr[front + i];

            if (i < count - 1)
            {
                cout << ", ";
            }
        }

        cout << "]" << endl;
    }

    void enqueue(int customerID)
    {
        if (isFull())
        {
            cout << "Queue is full!" << endl;
            return;
        }

        rear++;
        arr[rear] = customerID;
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

        customerID = arr[front];
        front++;
        count--;

        cout << "Dequeue() -> Served: " << customerID << " / ";
        displayQueue();

        return true;
    }
};

void testTicketLine()
{
    ArrayQueue queue;
    int customerID;

    queue.enqueue(101);
    queue.enqueue(102);

    queue.dequeue(customerID);

    queue.dequeue(customerID);
    queue.dequeue(customerID);
}

int main()
{
    testTicketLine();

    return 0;
}