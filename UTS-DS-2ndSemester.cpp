#include <iostream>
using namespace std;

struct node
{
    int data;
    node *link = NULL;
};

struct nodeDouble
{
    int data;
    nodeDouble *prevLink = NULL;
    nodeDouble *nextLink = NULL;
};

void NumberTwoProcess(int a[4][5])
{
    int b[2][10];
    int l = 0;  //Represent row of b matriks
    int k = 0;  //Represent column of b matriks

    //Copy matriks a to matriks b
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(k == 10)
            {
                k = 0;
                l++;
            }

            b[l][k] = a[i][j];

            k++;
        }
    }

    //Print matriks b
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout << b[i][j] << " ";
        }

        cout << "\n";
    }

    cout << "\n";
}

void PrintLinkedList(node *head)
{
    int counter = 1;
    node *pointer = head -> link;

    cout << "Print linked-list: \n";

    while(pointer != NULL)
    {
        cout << "Data-" << counter << ": Address: " << pointer << " --> Data: " << pointer -> data << " --> Next Address: " << pointer -> link << "\n";

        pointer = pointer -> link;
        counter++;
    }
}


void DeleteNode(node *head, int data)
{
    node *prevNode;
    node *pointer = head -> link;

    if(head != NULL)
    {
        while(pointer -> link != NULL)
        {
            if(pointer -> data == data)
            {
                break;
            }
            
            prevNode = pointer;
            pointer = pointer -> link;
        }

        prevNode -> link = pointer -> link;
        free(pointer);
        pointer = NULL;
    }
}

void NumberThreeProcess(int a[4][5])
{
    int userAnswerI;
    node *head = (node *)malloc(sizeof(node));
    head -> link = NULL;
    node *pointer = head;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            node *newNode = (node *)malloc(sizeof(node));
            newNode -> data = a[i][j];
            newNode -> link = NULL;
            pointer -> link = newNode;
            pointer = pointer -> link;
        }
    }

    PrintLinkedList(head);

    cout << "Data yang dihapus: ";
    cin >> userAnswerI;
    cout << "\n";

    DeleteNode(head, userAnswerI);
    PrintLinkedList(head);
}

void PrintDoubleLinkedList(nodeDouble *head)
{
    int counter = 1;
    nodeDouble *pointer = head -> nextLink;

    cout << "Print Double Linked List: \n";

    while(pointer != NULL)
    {
        cout << "Data-" << counter << " --> Address " << pointer << " --> Prev Address " << pointer -> prevLink << " --> Data " << pointer -> data << " --> Next Address " << pointer -> nextLink << "\n"; 

        counter++;
        pointer = pointer -> nextLink;
    }

}

void InsertBeforeDoubleLinkedList(nodeDouble *head, int searchData, int newData)
{
    nodeDouble *prevPointer;
    nodeDouble *pointer = head -> nextLink;

    if(head != NULL)
    {
        while(pointer != NULL)
        {
            if(pointer -> data == searchData)
            {
                break;
            }

            prevPointer = pointer;
            pointer = pointer -> nextLink;
        }

        nodeDouble *newNode = (nodeDouble *)malloc(sizeof(nodeDouble));
        newNode -> data = newData;
        newNode -> prevLink = prevPointer;
        newNode -> nextLink = pointer;

        prevPointer -> nextLink = newNode;
        pointer -> prevLink = newNode;
    }
}

void NumberFourProcess(int a[4][5])
{
    int userAnswerI;
    int userAnswerNewData;
    nodeDouble *head = (nodeDouble *)malloc(sizeof(nodeDouble));
    head -> prevLink = NULL;
    head -> nextLink = NULL;
    nodeDouble *pointer = head;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            nodeDouble *newNode = (nodeDouble *)malloc(sizeof(nodeDouble));
            newNode -> data = a[i][j];
            newNode -> prevLink = pointer;
            newNode -> nextLink = NULL;
            pointer -> nextLink = newNode;

            pointer = pointer -> nextLink;
        }
    }

    PrintDoubleLinkedList(head);

    cout << "Data yang ditambah: ";
    cin >> userAnswerNewData;
    
    cout << "Ditambah sebelum data: ";
    cin >> userAnswerI;
    cout << "\n";

    InsertBeforeDoubleLinkedList(head, userAnswerI, userAnswerNewData);
    PrintDoubleLinkedList(head);
    cout << "\n";
}

/* program utama */
//Change main function data type because my IDE said that main must return an integer
int main()
{
    bool isLoop = false;
    char userAnswerC;
    int userAnswerI;
    int a[4][5] = {{39, 48, 24, 11, 66}, {51, 55, 44, 33, 22}, {12, 35, 41, 23, 22}, {10, 99, 21, 50, 40}};

    do
    {
        cout << "Print matriks: \n";

        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                cout << a[i][j] << " ";
            }

            cout << "\n";
        }

        cout << "\nInsert your choice (1 - 3) or '0' to end program: \n1. Number 2 process\n2. Number 3 process\n3. Number 4 process\nAnswer: ";
        cin >> userAnswerI;
        cout << "\n";

        if(userAnswerI > 0 && userAnswerI <= 3)
        {
            isLoop = true;

        } else if(userAnswerI == 0)
        {
            isLoop = false;
            continue;

        } else
        {
            isLoop = true;
            cout << "Your answer was wrong!\n";
            continue;
        }

        if(userAnswerI == 1)
        {
            NumberTwoProcess(a);

        } else if(userAnswerI == 2)
        {
            NumberThreeProcess(a);

        } else if(userAnswerI == 3)
        {
            NumberFourProcess(a);
        }

    } while(isLoop);
}
