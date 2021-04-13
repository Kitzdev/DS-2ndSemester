#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    char data[10];
    node *link = NULL;
};

//Print whole linked-list
void PrintLinkedList(node *head)
{
    bool isContinue = false;
    int counter = 1;
    node *pointer = head;

    cout << "\nShowing All Node: \n";

    do
    {
        cout << "Data-" << counter << ": " << pointer -> data << " --> Address: " << pointer << " --> Next node address: " << pointer -> link << "\n";

        if(pointer -> link == NULL)
        {
            break;
        } 

        counter++;
        pointer = pointer -> link;

    } while(true);
}

//Insert data to the end node (pointter point to last node)
void Insert(node *pointer, char newData[])
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode -> link = NULL;
    strcpy(newNode -> data, newData);

    pointer -> link = newNode;
}

//Insert new data after chosen data
int InsertAfter(node *head, char searchData[], char newData[])
{
    node *pointer = head;

    if(head != NULL)
    {
        while((strcmp(pointer -> data, searchData)) != 0)
        {
            if(pointer -> link == NULL)
            {
                return 0;   //Zero code means data searched not found in list
            }

            pointer = pointer -> link;
        }

        node *newNode = (node *)malloc(sizeof(node));
        strcpy(newNode -> data, newData);
        newNode -> link = pointer -> link;
        pointer -> link = newNode;

        cout << "Insert after has completed!\n";

    } else
    {
        cout << "Head is NULL!\n";
    }
    
    return 1;
}

//Insert before chosen data
int InsertBefore(node *head, char searchData[], char newData[])
{
    node *pointer = head;

    if(head != NULL)
    {
        while(strcmp(pointer -> link -> data, searchData) != 0)
        {
            if(pointer -> link == NULL)
            {
                return 0;   //Zero code means data searched not available in linked-list
            }

            pointer = pointer -> link;
        }

        node *newNode = (node *)malloc(sizeof(node));
        strcpy(newNode -> data, newData);
        newNode -> link = pointer -> link;
        pointer -> link = newNode;

        cout << "Insert before has completed\n";

    }   else
    {
        cout << "Head is NULL!\n";
    }

    return 1;
}

//Locate address of searched node
int LocateAddress(node *head, char searchData[])
{
    node *pointer = head;

    if(head != NULL)
    {
        while(strcmp(pointer -> data, searchData) != 0)
        {
            if(pointer -> link == NULL)
            {
                return 0; //Zero code means data searched not available
            }

            pointer = pointer -> link;
        }

        cout << "Data " << searchData << " founded in address: " << pointer << " --> Next node address: " << pointer -> link << "\n";

    } else
    {
        cout << "Head is NULL\n";
    }

    return 1;
}

//Delete selected node
int DeleteNode(node *head, char searchData[])
{
    node *prevNode;
    node *pointer = head;

    if(pointer != NULL)
    {
        while(strcmp(pointer -> data, searchData) != 0)
        {
            if(pointer -> link == NULL)
            {
                return 0;   //Zero code means data searched not available in linked-list
            }

            prevNode = pointer;
            pointer = pointer -> link;
        }

        prevNode -> link = pointer -> link;
        free(pointer);
        pointer = NULL;

        cout << "Delete node has completed!\n";

    } else
    {
        cout << "Head is NULL\n";
    }

    return 1;
}

//Reverse whole linked list
int ReverseList(node **head)
{
    node *pointerNode = *head;
    pointerNode -> link = NULL; //Set first node to NULL (after this process this node will become the last node)

    node *nextNode = *head;
    node *prevNode = *head;

    nextNode = nextNode -> link;
    prevNode = prevNode -> link;

    while(nextNode -> link != NULL)
    {
        pointerNode -> link = prevNode;
        pointerNode = nextNode;
        prevNode = pointerNode;
        pointerNode = nextNode;
        nextNode = nextNode -> link;
    }

    pointerNode = *head;
    pointerNode -> link = nextNode;

    return 1;
}

//Delete whole linked list
int DeleteList(node *head)
{
    return 1;
}

int main()
{
    bool isContinue = false;
    bool isCorrect = false;
    char userAnswerA;   //Save user's character type anser
    char newData[10];
    char searchData[10];
    int userAnswerI;    //Save user's integer type answer
    int counter = 1;
    node *head = (node *)malloc(sizeof(node));
    node *pointer = head;

    cout << "===================================\n";
    cout << "Welcome to SLL-AllOperationIncluded\n";
    cout << "===================================\n\n";

    cout << "===== Insert data section =====\n";

    isContinue = true;
    do
    {
        cout << "Data-" << counter << ": ";
        fgets(newData, 10, stdin);
        newData[strlen(newData) - 1] = '\0';

        if(newData[0] != '\0')
        {
            Insert(pointer, newData);
            pointer = pointer -> link;

        } else
        {
            isContinue = false;
        }

        counter++;

    } while (isContinue);
    
    do
    {
        cout << "\nChoose operation (1 - 7):\n1. Insert after\n2. Insert before\n3. Locate Address\n4. Print list\n5. Delete data\n6. Reverse list\n7. Delete list\nAnswer: ";
        cin >> userAnswerI;
        cin.get();

        if(userAnswerI == 1)
        {
            PrintLinkedList(head -> link);

            cout << "Input your target node (data): ";
            fgets(searchData, 10, stdin);
            searchData[strlen(searchData) - 1] = '\0';

            cout << "Input data for new node: ";
            fgets(newData, 10, stdin);
            newData[strlen(newData) - 1] = '\0';

            if(searchData[0] == '\0' || newData[0] == '\0')
            {
                cout << "Data inputed invalid!\n";

            } else
            {
                if(!InsertAfter(head, searchData, newData))
                {
                    cout << "Target data not found!\n";
                }
            }

        } else if(userAnswerI == 2)
        {
            PrintLinkedList(head -> link);

            cout << "Input your target node (data): ";
            fgets(searchData, 10, stdin);
            searchData[strlen(searchData) - 1] = '\0';

            cout << "Input data for new node: ";
            fgets(newData, 10, stdin);
            newData[strlen(newData) - 1] = '\0';

            if(searchData[0] != '\0' && newData[0] != '\0')
            {
                if(!InsertBefore(head, searchData, newData))
                {
                    cout << "\nTarget data not found!\n";
                }

            } else
            {
                cout << "Data inputed invalid!\n";
            }

        } else if(userAnswerI == 3)
        {
            PrintLinkedList(head -> link);

            cout << "Input your target node (data): ";
            fgets(searchData, 10, stdin);
            searchData[strlen(searchData) - 1] = '\0';

            if(searchData[0] != '\0')
            {
                if(!LocateAddress(head, searchData))
                {
                    cout << "Data searched is not available in linked-list\n";
                };

            } else
            {
                cout << "Input data is invalid\n";
            }

        } else if(userAnswerI == 4)
        {
            PrintLinkedList(head -> link);

        } else if(userAnswerI == 5)
        {
            PrintLinkedList(head -> link);

            cout << "Input your target node (data): ";
            fgets(searchData, 10, stdin);
            searchData[strlen(searchData) - 1] = '\0';

            if(searchData[0] != '\0')
            {
                if(!DeleteNode(head, searchData))
                {
                    cout << "Data searched is not available in linked-list\n";
                }

            } else
            {
                cout << "Input data is invalid!\n";
            }

        } else if(userAnswerI == 6)
        {
            ReverseList(&head);

            cout << "\nList after Reversed: ";
            
            PrintLinkedList(head -> link);

        } else if(userAnswerA == 7)
        {

        }

        cout << "\nDo you want to do operation again? ('Y' = yes / 'N' = no): ";
        cin >> userAnswerA;

        do
        {
            if(userAnswerA == 'Y' || userAnswerA == 'y')
            {
                isContinue = true;
                isCorrect = true;

            } else if(userAnswerA == 'N' || userAnswerA == 'n')
            {
                isContinue = false;
                isCorrect = true;

            } else
            {
                cout << "Your input was wrong!\n";
                cout << "\nDo you want to do operation again? ('Y' = yes / 'N' = no): ";
                cin >> userAnswerA;
            }

        } while (!isCorrect);
        
    } while(isContinue);

    cout << "Thank you !\nSee you next time!";
}