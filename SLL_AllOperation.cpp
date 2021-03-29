#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct node
{
    char data[10];
    node *link = NULL;
};

void PrintLinkedList(node *head)
{
    bool isContinue = false;
    int counter = 1;
    node *pointer = head;

    do
    {
        cout << "\nShowing All Node: \n";
        cout << "Data-" << counter << ": " << " --> Address: " << pointer << " --> Next Node Address: " << pointer -> link;

        if(pointer -> link == NULL)
        {
            break;
        } 

        counter++;
        pointer = pointer -> link;

    } while(true);
}

//Insert data to the end node (pointter point to last node)
node *Insert(node *pointer, char data[])
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode -> link = NULL;
    strcpy(newNode -> data, data);

    return newNode;
}

//Insert new data after chosen data
int *InsertAfter(node *head, char searchData[], char newData[])
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
    }


}

int main()
{
    bool isContinue = false;
    bool isCorrect = false;
    char userAnswerA;   //Save user's character type anser
    char dataContainer[10];
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
        gets(dataContainer);

        if(strlen(dataContainer) != 0)
        {
            pointer -> link = Insert(pointer, dataContainer);

        } else
        {
            isContinue = false;
        }

        counter++;

    } while (isContinue);
    

    do
    {
        cout << "\nChoose operation (input number only):\n1. Insert after\n2. Insert before\n3. Locate Address\n4. Delete\nAnswer: ";
        cin >> userAnswerI;

        switch (userAnswerI)
        case 1 : InsertAfter;

        cout << "Do you want to do operation again? ('Y' = yes / 'N' = no): ";
        cin >> userAnswerA;

        do
        {
            if(userAnswerA == 'Y' || userAnswerA == 'y')
            {
                isContinue = true;
                isCorrect = true;

            } else if(userAnswerA == 'N' || userAnswerA == 'a')
            {
                isContinue = false;
                isCorrect = false;

            } else
            {
                cout << "Your input was wrong!\n";
                cout << "Do you want to do operation again? ('Y' = yes / 'N' = no): ";
                cin >> userAnswerA;
            }

        } while (isCorrect);
        
    } while(isContinue);

    cout << "\nThankyou !\nSee you next time!";
}