#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

struct node 
{
    int data;
    node *link = NULL;
};

class Queue
{
    public:

    node *queueHead = (node *)malloc(sizeof(node));
    node *queueTail = (node *)malloc(sizeof(node));   

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

    int FirstElement()
    {
        return queueTail -> link -> data;
    }

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
     
    int Dequeue()
    {
        int tempData;
        node *tempNode = (node *)malloc(sizeof(node));

        tempNode -> link = queueHead -> link;
        tempData = tempNode -> link -> data;
        queueHead -> link = queueHead -> link -> link;
        free(tempNode -> link);
        tempNode -> link = NULL;

        return tempData;
    }
};

int main()
{
    Queue theQueue;
    int poolSize = 10;
    int tempData = 0;

    for(int i = 0; i < poolSize; i++)
    {
        tempData = rand() % 1000000;

        cout << "Number generated: " << tempData << "\n";

        theQueue.Enqueue(tempData);
    }
    
    cout << "\n";
    
    for(int i = 0; i < poolSize; i++)
    {
        cout << "Data Dequeued: " << theQueue.Dequeue() << "\n";
    }
}