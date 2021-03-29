#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct node
{
    char data[10];
    node *link;
};

void CreateNewNode(node *pointerToNode, char name[])
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode -> link = NULL;
    strcpy(newNode -> data, name);

    pointerToNode -> link = newNode;
}

void PrintLinkedList(node *head)
{
    cout << "\nList Data: \n";

    while(head -> link -> link != NULL)
    {
        cout << "[" << head -> data << "]" << " --> alamat Ptr " << head -> link;

        head = head -> link;

        cout << " --> Next Ptr " << head -> link << "\n";
    }
}

void LocateAndDelete(node *head, char name[])
{
    while(head -> link != NULL)
    {
        if(strcmp(head -> link -> data, name) == 0 && name[0] != '\0')
        {
            cout << "Data " << head -> link -> data << " ada pada alamat " << head -> link -> link << "\n";

            //DeleteProcess
            node *deleteNode = head -> link;
            head -> link = deleteNode -> link;
            free(deleteNode);
            deleteNode = NULL;
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

        CreateNewNode(pointerToNode, name);
        pointerToNode = pointerToNode -> link;
        amountOfData++;

    } while(name[0] != '\0');
    amountOfData -= 2;

    CreateNewNode(pointerToNode, name);

    cout << "\nJumlah data " << amountOfData << "\n";
    PrintLinkedList(head -> link);

    do
    {
        cout << "\nData yang akan dihapus: ";
        fgets(name, 10, stdin);
        name[strlen(name) - 1] = '\0';

        LocateAndDelete(head, name);
        amountOfData--;

        if(amountOfData <= 0)
        {
            cout << "\n--= Data Kosong (!) =--" << "\n";
            
        } else
        {
            PrintLinkedList(head -> link);
        }

    } while(name[0] != '\0');
}