#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct node 
{
    char data[10];
    node *link;
};

//Create new node
node *CreateNewnode(node *pointToNode, char name[])
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode -> link = NULL;
    strcpy(newNode -> data, name);

    pointToNode -> link = newNode;
    return newNode;
}

//Print linked list
void PrintLinkedList(node *head)
{
    while(head -> link -> link!= NULL)
    {
        cout << "[" << head -> data << "]" << " --> alamat Ptr " << head -> link << " --> next Ptr ";

        head = head -> link;
        
        cout << head -> link << "\n";
    }
}

//Locate name inputed by user
void LocateByName(node *head, char name[10])
{
    while(strcmp(head -> data, name) != 0)
    {
        head = head -> link;
    }

    cout << "Data " << name << " ada pada alamat " << head -> link << "\n";
}

int main()
{
    char name[10];
    int i = 1;

    //Create first Node
    node *head = (node *)malloc(sizeof(node));
    node *pointerToNode = head ;

    cout << "Entry Serial Data \n\n";

    do
    {
        cout << "Data ke-" << i << " : ";
        fgets(name, 10, stdin);
        name[strlen(name) - 1] = '\0';

        pointerToNode = CreateNewnode(pointerToNode, name);

        i++;

    } while(name[0] != '\0');
    
    CreateNewnode(pointerToNode, name);

    cout << "\nJumlah data : " << i - 1 << "\n\n";
    cout << "Hasil Entry Data :\n";

    PrintLinkedList(head -> link);

    do
    {
        cout << "\nData yang anda cari: ";
        fgets(name, 10, stdin);
        name[strlen(name) - 1] = '\0';

        if(name[0] != '\0')
        {
            LocateByName(head -> link, name);
        }
    
    } while(name[0] != '\0');
}
