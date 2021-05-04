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

    //Constructor
    Stack(int sizeOfStack)
    {
        size = sizeOfStack;
        stack = new int[sizeOfStack];
    }

    //Check whether the stack is empty or not.
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

    //Check the most top element from the stack.
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

    //Push a new element to the stack.
    void Push(int data)
    {
        if(IsEmpty())
        {
            headPosition = 0;
            stack[headPosition] = data;

        } else if((headPosition - 1) == size)
        {
            cout << "Stack is full!\n";

        } else
        {
            stack[++headPosition]= data;
        }
    }

    //Pop the most top element from the stack.
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

    /*
        Push random numbers to the stacks.
        When the new data is bigger than the top of the stack, move the top element of the stack to the temporary stack. So the stack will be arranged in ascending way.
    */
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

    //Pop and display the popped data to the screen.
    for(int i = 0; i < sizeOfStack; i++)
    {
        cout << theStack.Pop() << "\n";
    } 
}