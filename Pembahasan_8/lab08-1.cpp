#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

struct node
{
    int data;
    node *link = NULL;
};

//Create new node
node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode -> data = data;
    newNode -> link = NULL;

    return newNode;
}

//Function to display information about stack pool
void displayStack(node *head)
{
    node *pointNode = (node *)malloc(sizeof(node));
    pointNode = head -> link;

    cout << "||  Node Address  || " << "Node Data ||  " << "Next Node Address  ||\n";
    cout << "--------------------------------------------------------\n";

    while(pointNode != NULL)
    {
        cout << "||" << setw(15) << pointNode << " ||" << setw(8) << pointNode -> data;

        pointNode = pointNode -> link;

        cout << "   ||" << setw(18) << pointNode << "   ||" << "\n";
    }
}

node *popStack(node *head)
{
    node *pointNode = (node *)malloc(sizeof(node));
    pointNode = head -> link;
    node *tempNode = pointNode -> link;
    
    int tempInt = pointNode -> data;
    
    cout << "Data popped out: " << tempInt << "\n";

    //Free    
    free(pointNode);
    pointNode = NULL;

    return tempNode;
}

int main()
{
    node *head = (node *)malloc(sizeof(node));
    head -> link = NULL;

    node *pointNode = (node *)malloc(sizeof(node));
    pointNode = head;

    int poolSize = 10;

    for(int i = 0; i < poolSize; i++)
    {
        pointNode -> link = createNode(rand() % 1000000);
        pointNode = pointNode -> link;
    }

    cout << "First Node Address: " << head -> link << "\n\n";

    displayStack(head);

    cout << "\n";

    for(int i = 0; i < poolSize; i++)
    {
        head -> link = popStack(head);
    }

    cout << "All data have popped out!\n";
}