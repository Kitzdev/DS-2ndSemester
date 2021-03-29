#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct node
{
    char data[10];
    node *link;
};

void CreateNewNode(node *pointerToNode, char nameSearch[], char nameNew[])
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode -> link = NULL;
    strcpy(newNode -> data, nameNew);

    while(pointerToNode != NULL)
    {
        if(strcmp(pointerToNode -> data, nameSearch) == 0)
        {
            newNode -> link = pointerToNode -> link;
            pointerToNode -> link = newNode;
        }
        
        pointerToNode = pointerToNode -> link;
    }
}

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
        cout << "[" << head -> data << "]" << " --> alamat Ptr " << head << 
                " --> Next Ptr " << head -> link << "\n";

        head = head -> link;
    }
}

void LocateNode(node *head, char name[])
{
    while(head != NULL)
    {
        if(strcmp(head -> data, name) == 0)
        {
            cout << "Data " << name << " ada pada alamat: " << head << "\n";
        }

        head = head -> link;
    }
}

int main()
{
    char nameSearch[10], nameNew[10];
    char userAnswer;
    int amountOfData = 1;
    node *head = (node *) malloc(sizeof(node));
    node *pointerToNode = head;

    cout << "Entry Serial Data\n";

    do
    {
        if(amountOfData == 1)
        {
            cout << "\nData yang Anda sisipkan: ";
            fgets(nameNew, 10, stdin);
            nameNew[strlen(nameNew) - 1] = '\0';

            CreateNewNode(pointerToNode, nameNew);
            pointerToNode = pointerToNode -> link;
            PrintLinkedList(head -> link);

        } else
        {
            cout << "\nData yang Anda cari: ";
            fgets(nameSearch, 10, stdin);
            nameSearch[strlen(nameSearch) - 1] = '\0';

            LocateNode(head, nameSearch);

            cout << "Data yang Anda sisipkan: ";
            fgets(nameNew, 10, stdin);
            nameNew[strlen(nameNew) - 1] = '\0';

            CreateNewNode(head, nameSearch, nameNew);
            PrintLinkedList(head -> link);
        }

        cout << "Lagi (Y/T): ";
        cin >> userAnswer;
        cin.get();

        if(userAnswer == 'T' || userAnswer == 't')
        {
            break;
        }

        amountOfData++;

    } while(true);
}