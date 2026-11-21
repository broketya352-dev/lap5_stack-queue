#include <iostream>
using namespace std;

class PrintJob
{
public:
    int jobID;
    int pageCount;
    PrintJob *next;

    PrintJob(int jobID, int pageCount)
    {
        this->jobID = jobID;
        this->pageCount = pageCount;
        next = nullptr;
    }
};

class PrinterQueue
{
private:
    PrintJob *front;
    PrintJob *rear;
    int totalPages;

public:
    PrinterQueue()
    {
        front = nullptr;
        rear = nullptr;
        totalPages = 0;
    }

    ~PrinterQueue()
    {
        while (front != nullptr)
        {
            PrintJob *temp = front;
            front = front->next;
            delete temp;
        }

        rear = nullptr;
        totalPages = 0;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void addJob(int jobID, int pageCount)
    {
        if (pageCount <= 0)
        {
            cout << "Page count must be greater than 0!" << endl;
            return;
        }

        PrintJob *newJob = new PrintJob(jobID, pageCount);

        if (isEmpty())
        {
            front = newJob;
            rear = newJob;
        }
        else
        {
            rear->next = newJob;
            rear = newJob;
        }

        totalPages += pageCount;

        cout << "Added Job " << jobID << " (" << pageCount << " pages)" << endl;
        cout << "Total pages waiting: " << totalPages << endl;
    }

    bool printNext()
    {
        if (isEmpty())
        {
            cout << "No print jobs waiting!" << endl;
            return false;
        }

        PrintJob *temp = front;

        cout << "Printing Job " << temp->jobID;
        cout << " (" << temp->pageCount << " pages)" << endl;

        totalPages -= temp->pageCount;
        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;

        cout << "Total pages waiting: " << totalPages << endl;

        return true;
    }
};

void testPrinterQueue()
{
    PrinterQueue printer;

    printer.addJob(12, 15);
    printer.addJob(13, 20);
    printer.addJob(14, 10);

    printer.printNext();
    printer.printNext();
    printer.printNext();
    printer.printNext();
}

int main()
{
    testPrinterQueue();

    return 0;
}