#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct node
{
    char data[10];
    node *prevLink = NULL;
    node *nextLink = NULL;
};

void CreateNewNode(node *pointerToNode, char name[])
{
    node *newNode = (node *)malloc(sizeof(node));
    strcpy(newNode -> data, name);
    newNode -> prevLink = pointerToNode;
    pointerToNode -> nextLink = newNode;
}

void PrintLinkedList(node *head, char name[])
{
    cout << "\nList Data: \n";

    do
    {
        cout << "[" << head -> data << "]" << " --> alamat Ptr " << head << " --> Previous Ptr " << 
        head -> prevLink << " --> Next Ptr " << head -> nextLink << "\n";

        if(strcmp(head -> nextLink -> data, name) == 0)
        {
            head = head;
        }

        head = head -> nextLink;

    } while(head != NULL && (strcmp(head -> data, name) != 0));
}

void PrintDoubleLinkedList(node *head, char name[])
{
    node *anotherHead = head;

    cout << "\nList Cetak Data Maju: \n";

    do
    {
        cout << "[" << head -> data << "]" << " --> alamat Ptr " << head << " --> Previous Ptr " << 
        head -> prevLink << " --> Next Ptr " << head -> nextLink << "\n";

        head = head -> nextLink;

    } while(head != NULL && (strcmp(head -> data, name) != 0));

    cout << "\nList Cetak Data Mundur: \n";

    do
    {
        cout << "[" << anotherHead -> data << "]" << " --> alamat Ptr " << anotherHead << " --> Previous Ptr " 
        << anotherHead -> prevLink << " --> Next Ptr " << anotherHead -> nextLink << "\n";

        anotherHead = anotherHead -> prevLink;

    } while(anotherHead != NULL && (strcmp(anotherHead -> data, name) != 0));
}

void LocateAndPrint(node *head, char name[])
{
    while(strcmp(head -> data, name) != 0)
    {
        head = head -> nextLink;
    }

    cout << "Data" << name << " ada pada alamat " << head << "\n";
    PrintDoubleLinkedList(head, name);
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
        cout << "Data ke-" << amountOfData << ": ";
        fgets(name, 10, stdin);
        name[strlen(name) - 1] = '\0';

        if(amountOfData == 1)
        {
            cout << "[==Membuat Head baru==]\n";
        }

        if(name[0] != '\0')
        {
            CreateNewNode(pointerToNode, name);
            pointerToNode = pointerToNode -> nextLink;
        }

        amountOfData++;

    } while (name[0] != '\0');

    pointerToNode -> nextLink = head -> nextLink;
    head -> nextLink -> prevLink = pointerToNode;

    cout << "\nJumlah data " << amountOfData - 2 << "\n";
    PrintLinkedList(head -> nextLink, head -> nextLink -> data);

    do
    {
        cout << "\nData yang dicari: ";
        fgets(name, 10, stdin);
        name[strlen(name) - 1] = '\0';

        if(name[0] != '\0')
        {
            LocateAndPrint(head, name);
        }
        
    } while(name[0] != '\0');
}