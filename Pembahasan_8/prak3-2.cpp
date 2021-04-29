#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

struct node
{
    int data;
    node *link = NULL;
};

class Stack
{
    public:

    node *stackHead = (node *)malloc(sizeof(node));

    void PushElement(int data)
    {
        node *newNode = (node *)malloc(sizeof(node));
        newNode -> data = data;
        newNode -> link = stackHead -> link;
        stackHead -> link = newNode;
    }   

    int Pop()
    {
        node *tempPointer = (node *)malloc(sizeof(node));
        tempPointer -> link = stackHead -> link -> link;
        int tempData = stackHead -> link -> data;
        free(stackHead -> link);
        stackHead -> link = tempPointer -> link;

        return tempData;
    }

    int TopStack()
    {
        return stackHead -> link -> data;
    }

    bool IsEmpty()
    {
        if(stackHead -> link == NULL)
        {
            return true;

        } else
        {
            return false;
        } 
    }
    
    void PrintStack()
    {
        node *stackPointer = (node *)malloc(sizeof(node));

        stackPointer -> link = stackHead -> link;

        cout << "||  Node Address  || " << "Node Data ||  " << "Next Node Address  ||\n";
        cout << "--------------------------------------------------------\n";

        while(stackPointer -> link != NULL)
        {
            cout << "||" << setw(15) << stackPointer -> link << " ||" << setw(8) << stackPointer -> link -> data;

            stackPointer -> link = stackPointer -> link -> link;

            cout << "   ||" << setw(18) << stackPointer -> link << "   ||" << "\n";
        }
    }
};

int main()
{
    int tempData;
    int poolSize = 10;

    Stack theStack;
    Stack tempStack;

    for(int i = 0; i < poolSize; i++)
    {
        tempData = rand() % 1000000;

        while(!(theStack.IsEmpty()) && (theStack.TopStack()) < tempData)
        {
            cout << i  << " " << tempData << "\n";
            tempStack.PushElement(theStack.Pop());
        }

        theStack.PushElement(tempData);

        while(!(tempStack.IsEmpty()))
        {
            theStack.PushElement(tempStack.Pop());
        }

        if(!(tempStack.IsEmpty()))
        {
            tempStack.PrintStack();
        }
        
    }

    cout << "First Node Address: " << theStack.stackHead -> link << "\n\n";

    theStack.PrintStack();

    cout << "\n";

    for(int i = 0; i < poolSize; i++)
    {
        cout << "Data popped out: " << theStack.Pop() << "\n";
    }

    cout << "All data have popped out!\n";
}