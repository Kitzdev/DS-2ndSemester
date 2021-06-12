#include <iostream>
using namespace std;

class Stack
{
    public:

    struct node
    {
        int data;
        node *link = NULL;
    };

    node *head = (node*)malloc(sizeof(node));

    bool IsEmpty()
    {
        if(head -> link == NULL)
        {
            return true;

        } else
        {
            return false;
        }
    }

    int Top()
    {
        if(IsEmpty())
        {
            return -1; //-1 code means that the stack is empty

        } else
        {
            return head -> link -> data;
        }
    }

    node* CreateNode(int data)
    {
        node *newNode = (node*)malloc(sizeof(node));
        newNode -> data = data;
        newNode -> link = NULL;
        return newNode;
    }

    void Push(int data)
    {
        node* tempNode = CreateNode(data);
        tempNode -> link = head -> link;
        head -> link = tempNode;
    }

    int Pop()
    {
        if(IsEmpty())
        {
            return -1; //-1 code means that the stack is empty

        } else
        {
            node* tempNode = head -> link;
            int tempData = tempNode -> data;
            head -> link = head -> link -> link;
            free(tempNode);
            return tempData;
        }
    }
};

Stack stack;    //Declare stack as a global variable

class BinaryTree
{
    public: 

    struct node
    {
        int data;
        node *leftLink;
        node *rightLink;
    };

    node *root = NULL;

    node *CreateNode(int data)
    {
        node *newNode = (node*)malloc(sizeof(node));
        newNode -> data = data;
        newNode -> leftLink = NULL;
        newNode -> rightLink = NULL;
        return newNode;
    }    

    node *Insert(node *root, int data)
    {
        if(root == NULL)
        {
            root = CreateNode(data);

        } else if(root -> data >= data)
        {
            root -> leftLink = Insert(root -> leftLink, data);

        } else
        {
            root -> rightLink = Insert(root -> rightLink, data);
        }

        return root;
    }

    void PreOrderTraversal(node* root)
    {
        if(root == NULL)
        {
            return;
        }

        stack.Push(root -> data);
        PreOrderTraversal(root -> leftLink);
        PreOrderTraversal(root -> rightLink);       
    }
};

int main()
{
    int a[20] = {39, 48, 24, 11, 66, 51, 55, 44, 33, 22, 12, 35, 41, 23, 22, 10, 99, 21, 50, 40};

    BinaryTree binaryTree;

    cout << "Proses Insert data ...\n";
    for(int i = 0; i < 20; i++)
    {
        binaryTree.root = binaryTree.Insert(binaryTree.root, a[i]);
    }

    cout << "Proses Pre-Order traversal ...\n";
    binaryTree.PreOrderTraversal(binaryTree.root);

    cout << "Proses pop dari stack ...\n";
    for(int i = 0; i < 20; i++)
    {
        cout << "Data: " << stack.Pop() << "\n";
    }
}