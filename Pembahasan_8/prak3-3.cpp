#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

/*
    I use the single linked list to create this queue.

    The tail was used to push data to the queue and the head used to pop data from the queue.

    En queue from the tail makes the queue has O(1) time complexity when enqueueing data.
    Dequeue from the tail also makes the queue has O(1) time complexity when dequeuing data.
*/
class Queue
{
    struct node
    {
        int data;
        node *link = NULL;
    };
    
    public:

    node *queueHead = (node *)malloc(sizeof(node));
    node *queueTail = (node *)malloc(sizeof(node));   

    //Check wether the queue is empty or not.
    bool IsEmpty()
    {
        if(queueHead -> link == NULL)
        {
            return true;

        } else
        {
            return false;
        }
    }

    //Check the first element of the queue.
    int FirstElement()
    {
        if(!IsEmpty())
        {
            return queueTail -> link -> data;

        } else
        {
            return -1;  //-1 code means the queue is already empty.
        }
    }

    /*
        En queue new data to the queue.

        If the queue is empty, we set the head and the tail pointing into the first node.

        If the queue is not empty, we only need to move the tail.
    */
    void Enqueue(int data)
    {
        node *newNode =  (node * )malloc(sizeof(node));
        newNode -> data = data;
        newNode -> link = NULL;

        if(IsEmpty())
        {
            queueHead -> link = newNode;
            queueTail -> link = newNode;

        } else
        {
            queueTail -> link -> link = newNode;
            queueTail -> link = newNode;
        }
    }

    //Dequeue data from the queue. 
    int Dequeue()
    {
        if(!IsEmpty())
        {
            int tempData;
            node *tempNode = (node *)malloc(sizeof(node));

            tempNode -> link = queueHead -> link;
            tempData = tempNode -> link -> data;
            queueHead -> link = queueHead -> link -> link;
            free(tempNode -> link);
            tempNode -> link = NULL;

            return tempData;
            
        } else
        {
            return -1; //-1 code means the queue is already empty.
        }
    }
};

int main()
{
    Queue theQueue;
    int poolSize = 10;
    int tempData = 0;

    cout << "-----Enqueque process-----\n";

    //En queue data to the queue.
    for(int i = 0; i < poolSize; i++)
    {
        tempData = rand() % 1000000;

        cout << "Number generated: " << tempData << "\n";

        theQueue.Enqueue(tempData);
    }
    
    cout << "\n-----Dequeue Process-----\n";
    
    //Dequeue data from the queue.
    for(int i = 0; i < poolSize; i++)
    {
        cout << "Data Dequeued: " << theQueue.Dequeue() << "\n";
    }
}