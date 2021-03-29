#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct node
{
    char data[10];
    node *prevLink;
    node *nextLink;
};

void CreateNewNode(node *pointerTonode, char name[10])
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode -> prevLink = NULL;
    newNode -> nextLink = NULL;
    strcpy(newNode -> data, name);

    newNode -> prevLink = pointerTonode;
    pointerTonode -> nextLink = newNode;
}

void PrintDoubleLL(node *head)
{
    node *anotherHead = (node *)malloc(sizeof(node));

    cout << "List Data Cetak Maju: \n";

    while(head != NULL)
    {
        cout << "[" << head -> data << "]" << " --> alamat Ptr " << head << " --> Prev Ptr " 
        << head -> prevLink << " --> Next Ptr " << head -> nextLink << "\n";

        if(head -> nextLink == NULL)
        {
            anotherHead = head;
        }

        head = head -> nextLink;
    }

    head = anotherHead;

    cout << "\nList Data Cetak Mundur: \n";

    while(head -> prevLink != NULL)
    {
        cout << "[" << head -> data << "]" << " --> alamat Ptr " << head << " --> Prev Ptr " 
        << head -> prevLink << " --> Next Ptr " << head -> nextLink << "\n";
        
        head = head -> prevLink;
    }
}

int main()
{
    char name[10];
    int amountOfData = 1;
    node *head = (node *) malloc(sizeof(node));
    head -> prevLink = NULL;
    node *pointToNode = head;

    cout << "Entry Serial Data\n\n";

    do
    {
        cout << "Data ke-" << amountOfData << ": ";
        fgets(name, 10, stdin);
        name[strlen(name) - 1] = '\0';

        if(amountOfData == 1)
        {
            cout << "[==Membuat Head baru==]\n";
        }

        if(name[0] != '\0')
        {
            CreateNewNode(pointToNode, name);
            pointToNode = pointToNode -> nextLink;
        }

        amountOfData++;

    } while (name[0] != '\0');
    
    cout << "\nJumlah data " << amountOfData - 1 << "\n\n";

    PrintDoubleLL(head -> nextLink);
}