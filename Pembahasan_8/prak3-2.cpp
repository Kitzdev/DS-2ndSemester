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

    //Push a new element to the stack.
    void Push(int data)
    {
        node *newNode = (node *)malloc(sizeof(node));
        newNode -> data = data;
        newNode -> link = stackHead -> link;
        stackHead -> link = newNode;
    }   

    //Pop the most top element from the stack.
    int Pop()
    {
        node *tempPointer = (node *)malloc(sizeof(node));
        tempPointer -> link = stackHead -> link -> link;
        int tempData = stackHead -> link -> data;
        free(stackHead -> link);
        stackHead -> link = tempPointer -> link;

        return tempData;
    }

    //Check the most top element from the stack.
    int TopStack()
    {
        return stackHead -> link -> data;
    }

    //Check whether the stack is empty or not.
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
    
    //Print the contents of the stack. 
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

    /*
        Push random numbers to the stacks.
        When the new data is bigger than the top of the stack, move the top element of the stack to the temporary stack. So the stack will be arranged in ascending way.
    */
    for(int i = 0; i < poolSize; i++)
    {
        tempData = rand() % 1000000;

        while(!(theStack.IsEmpty()) && (theStack.TopStack()) < tempData)
        {
            tempStack.Push(theStack.Pop());
        }

        theStack.Push(tempData);

        while(!(tempStack.IsEmpty()))
        {
            theStack.Push(tempStack.Pop());
        }
    }

    cout << "First Node Address: " << theStack.stackHead -> link << "\n\n";

    //Call a function to print the stack.
    theStack.PrintStack();

    cout << "\n";

    //Pop item from the stack.
    for(int i = 0; i < poolSize; i++)
    {
        cout << "Data popped out: " << theStack.Pop() << "\n";
    }

    cout << "All data have popped out!\n";
}