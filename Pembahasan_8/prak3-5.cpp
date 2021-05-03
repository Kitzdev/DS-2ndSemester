#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

class Stack
{
    public: 

    int size;
    int *stack;
    int headPosition = -1;

    Stack(int sizeOfStack)
    {
        size = sizeOfStack;
        stack = new int[sizeOfStack];
    }

    bool IsEmpty()
    {
        if(headPosition == -1)
        {
            return true;

        } else
        {
            return false;
        }
    }

    int TopStack()
    {
        if(!(IsEmpty()))
        {
            return stack[headPosition];

        } else
        {
            return -1;
        }
    }

    void Push(int data)
    {
        if(IsEmpty())
        {
            headPosition = 0;
            stack[headPosition] = data;

        } else
        {
            stack[++headPosition]= data;
        }
    }

    int Pop()
    {
        if(IsEmpty())
        {
            cout << "Stack is empty!\n";
            return -1;

        } else
        {
            int tempPosition = headPosition;
            headPosition--;
            return stack[tempPosition];
        }
    }
};

int main()
{
    int sizeOfStack;
    int tempData;

    cout << "Size of stack: ";
    cin >> sizeOfStack;

    Stack theStack(sizeOfStack);
    Stack tempStack(sizeOfStack);

    cout << "\n----- Push Process -----\n";

    for(int i = 0; i < sizeOfStack; i++)
    {
        tempData = rand() % 1000000;
        
        cout << "Random number generated: " << tempData << "\n";

        while(!theStack.IsEmpty() &&  theStack.TopStack() < tempData)
        {
            tempStack.Push(theStack.Pop());
        }

        theStack.Push(tempData);

        while(!tempStack.IsEmpty())
        {
            theStack.Push(tempStack.Pop());
        }
        
        cout << "Stack top " << theStack.TopStack() << "\n";
    }

    cout << "\n----- Pop Process -----\n";

    for(int i = 0; i < sizeOfStack; i++)
    {
        cout << theStack.Pop() << "\n";
    } 
}