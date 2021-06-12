#include <iostream>
using namespace std;

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
            cout << "Alamat: " << root << " Nilai Simpul: " << data << "\n";

        } else if(root -> data >= data)
        {
            root -> leftLink = Insert(root -> leftLink, data);

        } else
        {
            root -> rightLink = Insert(root -> rightLink, data);
        }

        return root;
    }
};

int main()
{
    int a[20] = {39, 48, 24, 11, 66, 51, 55, 44, 33, 22, 12, 35, 41, 23, 22, 10, 99, 21, 50, 40};

    BinaryTree binaryTree;
    
    for(int i = 0; i < 20; i++)
    {
        binaryTree.root = binaryTree.Insert(binaryTree.root, a[i]);
    }
}