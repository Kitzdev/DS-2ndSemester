#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct node
{
    char data[10];
    node *link;
};

node *CreateNewNode(node *pointerToNode, char name[10])
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
        cout << "[" << head -> data << "]" << " --> alamat Ptr " << head -> link << " --> next Ptr ";

        head = head -> link;

        cout << head -> link << "\n";
    }
}

void LocateInsertAfter(node *head, char name[10])
{
    while(head -> link != NULL)
    {
        if(strcmp(head -> data, name) == 0)
        {
            cout << "Data " << name << " ada pada alamat " << head -> link << "\n";
            cout << "\nData yang disisipkan: ";
            fgets(name, 10, stdin);
            name[strlen(name) - 1] = '\0';

            if(name[0] != '\0')
            {
                node *savePointer = head -> link;
                CreateNewNode(head, name);
                head -> link -> link = savePointer;
                break;
            }
         
        } else if(head -> link -> link == NULL)
        {
            cout << "Data tidak ketemu!\n\n";
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
        cout << "Data ke-" << amountOfData << ": ";
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
    
    cout << "\nJumlah data: " << amountOfData - 2 << "\n";
    cout << "\nList Data: \n";

    pointerToNode = head;
    PrintLinkedList(head -> link);

    do
    {
        cout << "\nData yang Anda cari: ";
        fgets(name, 10, stdin);
        name[strlen(name) - 1] = '\0';

        if(name[0] != '\0')
        {
            LocateInsertAfter(head, name);
            PrintLinkedList(head -> link);
        }

    } while (name[0] != '\0');
    
}