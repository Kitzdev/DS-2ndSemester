#include <iostream>
#include <math.h>
#include <stdlib.h>
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

    //Constructor
    Queue(int sizeOfQueue)
    {
        size = sizeOfQueue;
        queue = new int[sizeOfQueue];
    }

    //Check wether the queue is empty or not.
    bool IsEmpty()
    {
        if ((front == -1) && (rear == -1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //Check the first element of the queue.
    int FirstElement()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty!\n";

            return -1; //-1 means queue is empty.
        }

        return queue[rear];
    }

    /*
        Enqueue new data to the queue.

        If the queue was empty, we set the front and rear to 0, so we can mark the queue as a non-empty queue.

        If the front was equal to rear + 1 (in case this is a circular array), then it means the queue is already full.
    */
    void Enqueue(int data)
    {
        if (IsEmpty())
        {
            front = 0;
            rear = 0;
        }
        else if (front == ((rear + 1) % size))
        {
            cout << "Queue is full!\n";
            front = -1;
            rear = -1;
            return;
        }
        else
        {
            rear = (size + rear + 1) % size;
        }

        queue[rear] = data;
    }

    //Dequeue data from the queue.
    int Dequeue()
    {
        int tempData;

        if(IsEmpty())
        {
            cout << "Queue is empty!\n";
            return -1;
        }
        else
        {
            tempData = queue[front];
            front = (size + front + 1) % size;
        }

        return tempData;
    }

    //Delete the unused array.
    void DeleteQueue()
    {
        delete[] queue;
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

    //En queue data to the queue.
    for (int i = 0; i < queueSize; i++)
    {
        tempData = rand() % 1000000;
        theQueue.Enqueue(tempData);

        cout << "Random number generated: " << theQueue.FirstElement() << "\n";
    }

    cout << "\nDequeue process ...\n";

    //Dequeue data from the queue.
    for (int i = 0; i < queueSize; i++)
    {
        cout << "Number dequeued: " << theQueue.Dequeue() << "\n";
    }

    theQueue.DeleteQueue();
}