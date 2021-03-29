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

void CreateNewNode(node *pointerToNode, char name[])
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode -> prevLink = pointerToNode;
    newNode -> nextLink = NULL;
    strcpy(newNode -> data, name);
    pointerToNode -> nextLink = newNode;
}

void PrintDoubleLL(node *head)
{
    node *anotherHead;

    cout << "\nList Cetak Data Maju: \n";

    while(head != NULL)
    {
        cout << "[" << head -> data << "]" << " --> alamat Ptr " << head << " --> Prev Ptr " << head 
        -> prevLink << " --> Next Ptr " << head -> nextLink << "\n";

        if(head -> nextLink == NULL)
        {
            anotherHead = head;
        }

        head = head -> nextLink;
    }

    head = anotherHead;

    cout << "\nList Cetak Data Mundur: \n";

    while(head -> prevLink != NULL)
    {
        cout << "[" << head -> data << "]" << " --> alamat Ptr " << head << " --> Prev Ptr " << head 
        -> prevLink << " --> Next Ptr " << head -> nextLink << "\n";

        head = head -> prevLink;
    }
}

void LocateAndInsert(node *head, char name[])
{
    while(head != NULL)
    {
        if(strcmp(head -> data, name) == 0)
        {
            cout << "Data " << head -> data << " ada pada alamat: " << head << "\n";
            cout << "Data yang disisipkan: ";
            fgets(name, 10, stdin);
            name[strlen(name) - 1] = '\0';

            node *newNode = (node *)malloc(sizeof(node));
            newNode -> prevLink = head;
            newNode -> nextLink = head -> nextLink;
            head -> nextLink = newNode;
            head -> nextLink -> nextLink -> prevLink = newNode;
            strcpy(newNode -> data, name);
    
            break;
        }

        head = head -> nextLink;
    }
}

int main()
{
    char name[10];
    int amountofData = 1;
    node *head = (node *)malloc(sizeof(node));
    head -> nextLink = NULL;
    head -> prevLink = NULL;
    node *pointerToNode = head;

    cout << "Entry Serial Data\n\n";

    do
    {
        cout << "Data ke-" << amountofData << ": ";
        fgets(name, 10, stdin);
        name[strlen(name) - 1] = '\0';

        if(amountofData == 1)
        {
            cout << "[==Membuat Head baru==]\n";
        }
        
        if(name[0] != '\0')
        {
            CreateNewNode(pointerToNode, name);
            pointerToNode = pointerToNode -> nextLink;
            amountofData++;
        }

    } while(name[0] != '\0');

    cout << "\nJumlah Data " << amountofData - 1 << "\n";
    PrintDoubleLL(head -> nextLink);

    do
    {
        cout << "\nData yang Anda cari: ";
        fgets(name, 10, stdin);
        name[strlen(name) - 1] = '\0';

        if(name[0] != '\0')
        {
            LocateAndInsert(head, name);
            PrintDoubleLL(head -> nextLink);
        }

    } while (name[0] != '\0');
    
}