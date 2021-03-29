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

    while(head != NULL)
    {
        cout << "[" << head -> data << "]" << " --> alamat Ptr " << head << " --> Next Ptr " << head -> link
        << "\n";

        if(head != NULL)
        {
            head = head -> link;
        }
    }
}

void LocateAndInsertBefore(node *pointerToNode, char name[])
{
    node *anotherNode;

    while(strcmp(pointerToNode -> data, name) != 0)
    {
        anotherNode = pointerToNode;
        pointerToNode = pointerToNode -> link;
    }

    cout << "Data " << name << " ada pada alamat " << pointerToNode << "\n";
    cout << "Data yang disisipkan: ";
    fgets(name, 10, stdin);
    name[strlen(name) - 1] = '\0';

    CreateNewNode(anotherNode, name);
    anotherNode = anotherNode -> link;
    anotherNode -> link = pointerToNode;
}   

int main()
{
    char name[10];
    char userAnswer;
    int amountOfData = 1;
    node *head = (node *)malloc(sizeof(node));
    head -> link = NULL;

    cout << "Entry Serial Data\n\n";

    do
    {
        if(amountOfData == 1)
        {
            cout << "Data yang disisipkan: ";
            fgets(name, 10, stdin);
            name[strlen(name) - 1] = '\0';

            CreateNewNode(head, name);
            PrintLinkedList(head -> link);

        } else
        {
            cout << "\nData yang Anda cari: ";
            fgets(name, 10, stdin);
            name[strlen(name) - 1] = '\0';

            LocateAndInsertBefore(head, name);
            PrintLinkedList(head -> link);
        }

        amountOfData++;

        cout << "Lagi (Y/T): ";
        cin >> userAnswer;
        cin.get();

        if(userAnswer == 't' || userAnswer == 'T')
        {
            break;
        }

    } while (true);
}