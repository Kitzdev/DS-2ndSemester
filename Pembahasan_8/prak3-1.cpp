#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

struct node
{
    int data;
    node *link = NULL;
};

//Create a new node.
node *CreateNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode -> data = data;
    newNode -> link = NULL;

    return newNode;
}

//Function to display information about stack pool.
void DisplayStack(node *head)
{
    node *pointNode = (node *)malloc(sizeof(node));
    pointNode -> link = head -> link;

    cout << "||  Node Address  || " << "Node Data ||  " << "Next Node Address  ||\n";
    cout << "--------------------------------------------------------\n";

    while(pointNode -> link != NULL)
    {
        cout << "||" << setw(15) << pointNode -> link << " ||" << setw(8) << pointNode -> link -> data;

        pointNode -> link = pointNode -> link -> link;

        cout << "   ||" << setw(18) << pointNode -> link << "   ||" << "\n";
    }
}

//Function to store items to the stack.
node *PushElement(node *head, int data)
{
    //pointerNode is used to store the new node.
    node *pointerNode = (node *)malloc(sizeof(node));

    //New node pointing to the item pointed by the head pointer.
    pointerNode -> link = CreateNode(data);
    pointerNode -> link -> link = head -> link;
    
    //Return the address of the new node.
    return pointerNode -> link;
}

//Create a new stack.
node *CreateStack()
{
    int poolSize = 10;
    node *head = (node *)malloc(sizeof(node));

    for(int i = 0; i < poolSize; i++)
    {
        //Update the linked part of the head to the top item of the stack.
        head -> link = PushElement(head, rand() % 1000000);
    }

    //Return the address of the top item of the new stack.
    return head -> link;
}

//Take the top item of the stack.
node *PopStack(node *head)
{
    node *pointerNode = (node *)malloc(sizeof(node));
    pointerNode -> link = head -> link;
    node *tempNode = pointerNode -> link -> link;   //Store the second item from the top stack.
    int tempInt = pointerNode -> link -> data;
    
    cout << "Data popped out: " << tempInt << "\n";

    //Free the node from memory and update the linked part of pointerNode.  
    free(pointerNode -> link);
    pointerNode -> link = NULL;

    //Return the new node that acts as the top stack.
    return tempNode;
}

int main()
{
    int poolSize = 10;

    node *head = (node *)malloc(sizeof(node));
    head -> link = NULL;

    //Linked part of the head pointing to the first item of the stack.
    head -> link = CreateStack();

    cout << "First Node Address: " << head -> link << "\n\n";

    DisplayStack(head);

    cout << "\n";

    for(int i = 0; i < poolSize; i++)
    {
        //Update link part of the head, so now it points to the most top item of the stack.
        head -> link = PopStack(head);
    }

    cout << "All data have popped out!\n";
}