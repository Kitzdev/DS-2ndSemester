#include <iostream>
#include <math.h>
using namespace std;

/*
    This queue use circular array to act as a queue.
    front used to dequeue data, rear used to enqueue data.
*/
class Queue
{
    public:

    int size;
    int *queue;
    int front = -1;
    int rear = -1;

    Queue(int sizeOfQueue)
    {
        size = sizeOfQueue;
        queue = new int[sizeOfQueue];
    }

    bool IsEmpty()
    {
        if((front == -1) && (rear == -1))
        {
            return true;

        } else
        {
            return false;
        }
    }

    int FirstElement()
    {
        if(IsEmpty())
        {
            cout << "Queue is empty!\n";
            return -1;  //-1 means queue is empty.
        }

        return queue[rear];
    }

    void Enqueue(int data)
    {
        if(IsEmpty())
        {
            front = 0;
            rear = 0;

        } else if(front == rear && front != 0 && rear != 0)
        { 
            cout << "Queue is full!\n";
            front = -1;
            rear = -1;
            return;

        } else
        {
            rear = (size + rear + 1) % size;
        }

        queue[rear] = data;
    }

    int Dequeue()
    {
        int tempData;

        if(IsEmpty())
        {
            cout << "Queue is empty!\n";
            return -1;

        } else
        {
            tempData = queue[front];
            front = (size + front + 1) % size;
        }

        return tempData;
    }

    void DeleteQueue()
    {
        delete [] queue;
    }
};

int main()
{
    int tempData;
    int queueSize;

    cout << "Size of Queue: ";
    cin >> queueSize;

    Queue theQueue = Queue(queueSize);

    cout << "\nGenerating random number ...\n";

    for(int i = 0; i < queueSize; i++)
    {
        tempData = rand() % 1000000;
        theQueue.Enqueue(tempData);

        cout << "Random number generated: " << theQueue.FirstElement() << "\n";
    }

    cout << "\nDequeue process ...\n";
    
    for(int i = 0; i < queueSize; i++)
    {
        cout << "Number dequeued: " << theQueue.Dequeue() << "\n";
    }

    theQueue.DeleteQueue();
}