#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct node
{
    char data[10];
    node *link;
};

node *CreateNewNode(node *pointerToNode, char name[])
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode -> link = NULL;
    strcpy(newNode -> data, name);

    pointerToNode -> link = newNode;
    return newNode;
}

void PrintLinkedList(node *head)
{
    while(head -> link -> link != NULL)
    {
        cout << "[" << head -> data << "]" << " --> alamat Ptr " << head -> link;

        head = head ->link;

        cout << " --> next Ptr " << head -> link << "\n"; 
    }
}

//Print Circular Linked List
void PrintLinkedList(node *head, char name[])
{
    do
    {
        cout << "[" << head -> data << "]" << " --> alamat Ptr " << head -> link;

        head = head -> link;

        cout << " --> next Ptr " << head -> link << "\n";

    } while(strcmp(head -> data, name) != 0);
}

void LocateByName(node *head, char name[])
{
    while(head -> link != NULL)
    {
        if(strcmp(head -> data, name) == 0)
        {
            cout << "\nData " << name << " ada pada alamat " << head -> link << "\n";
            PrintLinkedList(head, name);
            break;

        } else if(head -> link -> link == NULL)
        {
            cout << "Data tidak ketemu\n";
        }

        head = head -> link;
    }
}

int main()
{
    char name[10];
    int amountOfData = 1;
    node *head = (node *)malloc(sizeof(node));
    node *pointerToNode = head;

    cout << "Entry Serial Data\n\n";

    do
    {
        cout << "Data ke-" << amountOfData << " : ";
        fgets(name, 10, stdin);
        name[strlen(name) - 1] = '\0';

        if(amountOfData == 1)
        {
            cout << "[==Membuat Head baru==]\n"; 
        }
        
        pointerToNode = CreateNewNode(pointerToNode, name);
        amountOfData++;

    } while(name[0] != '\0');

    CreateNewNode(pointerToNode, name);

    cout << "\nJumlah data " << amountOfData - 1;
    cout << "\n\nList Data Cetak Maju\n";

    PrintLinkedList(head -> link);

    pointerToNode = head;

    //Connect last node to first node
    while(pointerToNode -> link -> link -> link != NULL)
    {
        pointerToNode = pointerToNode -> link;
    }
    pointerToNode -> link = head -> link;

    do
    {
        cout << "\nData yang dicari: ";
        fgets(name, 10, stdin);
        name[strlen(name) - 1] = '\0';

        if(name[0] != '\0')
        {
            LocateByName(head, name);
        }

    } while(name[0] != '\0');
}