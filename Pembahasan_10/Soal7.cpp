#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

//This class is declared as a Binary Search Tree. But, in this file i will call it a Tree only.
class Tree
{
    struct node
    {
        int data;
        node* leftLink = NULL;
        node* rightLink = NULL;
    };

    public:

    node* root = (node*)malloc(sizeof(node));

    //Used to create a new node and return it's address.
    node* CreateNewNode(int data)
    {
        node* newNode = (node*)malloc(sizeof(node));
        newNode -> data = data;
        newNode -> leftLink = newNode -> rightLink = NULL;

        return newNode;
    }

    /*
        This Insert function is used to insert a new node into the tree by obtaining the root address of the tree.

        Take two arguments, the root address of the tree and the data that want to be inserted.

        Use the recursive method because this function assumes that every node can act as a root. So we can decide whether the new data will be inserted on the left or right side of the tree.
    */
    node* Insert(node* root, int data)
    {    
        if(root == NULL)
        {
            return CreateNewNode(data);

        } else if(root -> data >= data)
        {
            root -> leftLink = Insert(root -> leftLink, data);

        } else
        {
            root -> rightLink = Insert(root -> rightLink, data);
        }

        return root;
    }

    /*
        This function is used to print a tree in a pre-order manner bypassing the root of the tree.
        Pre-order means we traverse the tree in the below order:
        1. Visit(print) the node.
        2. Go to the left subtree.
        3. Go to the right subtree.

        This function takes one argument which is the root of a tree.

        This function uses recursive by assuming that each of the nodes will do the pre-order thing.
    */
    void PreOrderTraversal(node* root)
    {
        if(root != NULL)
        {
            cout << root -> data << " ";
            PreOrderTraversal(root -> leftLink);
            PreOrderTraversal(root -> rightLink);
        } 
    }

    /*
        This function is used to print a tree in an in-order manner by passing the root of the tree.
        In-order means we traverse the tree in the below order:
        1. Go to the left subtree.
        2. Visit(print) the node.
        3. Go to the right subtree.
        
        This function takes one argument which is the root of a tree

        This function uses recursive by assuming that each of the nodes will do the in-order thing.
    */
    void InOrderTraversal(node* root)
    {
        if(root != NULL)
        {
            InOrderTraversal(root -> leftLink);
            cout << root -> data << " ";
            InOrderTraversal(root -> rightLink);
        } 
    }

    /*
        This function is used to print a tree in a post-order manner by passing the root of the tree.
        Post-order means we traverse the tree in the below order:
        1. Go to the left subtree.
        2. Go to the right subtree.
        3. Visit(print) the node.

        This function takes one argument which is the root of a tree.

        This function uses recursive by assuming that each of the nodes will do the post-order thing.
    */
    void PostOrderTraversal(node* root)
    {
        if(root != NULL)
        {
            PostOrderTraversal(root -> leftLink);
            PostOrderTraversal(root -> rightLink);
            cout << root -> data << " ";
        } 
    }

    /*
        Function to find the height of the tree (the tree that its address passed to this function).

        Return -1 if NULl, so the leaf node will have 0 height.
    */
    int GetHeight(node* root)
    {
        int leftHeight;
        int rightHeight;

        if(root != NULL)
        {
            return max(GetHeight(root -> leftLink), GetHeight(root -> rightLink)) + 1;
             
        } else
        {
            return -1;
        }
    }

    //Print a tree based on their level 
    void PrintByLevel(node* root, int level)
    {
        if(root != NULL)
        {
            if(level == 0)
            {
                cout << root -> data << " ";
                return;
            }

            PrintByLevel(root -> leftLink, level - 1);
            PrintByLevel(root -> rightLink, level - 1);
        }
    }

    /*
        This function is used to print a tree in a level-order manner by passing the root of the tree.

        Level-order means we traverse the tree based on the level.

        This function takes one argument which is the root of a tree.
    */
    void LevelOrderTraversal(node* root)
    {
        int heightOfTree = GetHeight(root);

        for(int i = 0; i <= heightOfTree; i++)
        {   
            PrintByLevel(root, i);
        }
    }

    /* 
        Function to search data in a tree by getting the address of the tree and data want to be searched.

        This function take two element as the argument which is the address of the tree and the data want to be searched.
    */
    node* SearchData(node* root, int data)
    {
        while(root != NULL)
        {
            if(root -> data == data)
            {
                cout << "Data " << data << " ditemukan pada alamat " << root << "\n\n";
                return root;

            } else if(root -> data > data)
            {
                cout << "Data " << root -> data << " pergi ke kiri\n";
                root = root -> leftLink;

            } else
            {
                cout << "Data " << root -> data << " pergi ke kanan\n";
                root = root -> rightLink;
            }
        }
        
        return root;
    }

    /*
        Function to delete data from the tree (the tree that its address passed to this function).

        This function has two parameters which are the root of the tree and data that want to be deleted.
    */
    void DeleteNode(node* root, int data)
    {
        node* tempNode = root;
        node* nodeChanger = NULL;   //nodeChanger used to store the new address for the parent node link part.

        if(root != NULL)
        {
            //Update the root part, so now it contains the address of the node that wants to be deleted.
            root = SearchData(root, data);

            //First case: leaf node.
            if(root -> leftLink == NULL && root -> rightLink == NULL)
            {
                free(root);

            } else if(root -> leftLink == NULL) //Second case: node with one child at right.
            {
                nodeChanger = root -> rightLink;

            } else if(root -> rightLink == NULL)//Second case: node with one child at left.
            {
                nodeChanger = root -> leftLink;
            }

            /*                
                This part is used to find the parent node of the node that will be deleted.

                After the parent is already found, we update the linked part whether on the left or the right side with the nodeChanger.

                nodeChanger used as its modifier for example it can be an address of the new child or NULL to state that the parent has been lost the child node.
            */
            while(tempNode != NULL)
            {
                if(tempNode -> leftLink == root)
                {
                    tempNode -> leftLink = nodeChanger;
                    break;

                } else if(tempNode -> rightLink == root)
                {
                    tempNode -> rightLink = nodeChanger;
                    break;

                } else if(tempNode -> data > data)
                {
                    tempNode = tempNode -> leftLink;

                } else
                {
                    tempNode = tempNode -> rightLink;
                }
            }
        }

        cout << "Data pada alamat " << root << " telah dihapus!\n\n"; 
    }
};

int main()
{
    Tree theTree;
    theTree.root = NULL;

    int dataContainer;
    int userAnswerI;
    int number[13] = {50, 25, 75, 10, 35, 60, 85, 30, 28, 33, 65, 63, 68};

    for(int i = 0; i < 13; i++)
    {
        theTree.root = theTree.Insert(theTree.root, number[i]);
    } 

    do
    {
        cout << "Menu\n1. Tambah data ke tree\n2. Cari data\n3. Hapus data dari tree - deletion by Merging\n4. Hapus data dari tree - deletion by Copying\n5. Pre-order traversal\n6. Post-order traversal\n7. In-oder traversal\n8. Level-order traversal\n0. Keluar\n\nPilihan Anda : ";
        cin >> userAnswerI;  
        
        if(userAnswerI == 2)
        {
            int dataContainer;

            cout << "Data yang dicari: ";
            cin >> dataContainer;

            theTree.SearchData(theTree.root, dataContainer);
    
        }else if(userAnswerI == 3 || userAnswerI == 4)
        {
            int dataContainer;

            cout << "Masukan data yang ingin dihapus: ";
            cin >> dataContainer;

            theTree.DeleteNode(theTree.root, dataContainer);

        } else if(userAnswerI == 5)
        {
            theTree.PreOrderTraversal(theTree.root);
            cout << "\n\n";
            
        } else if(userAnswerI == 6)
        {
            theTree.PostOrderTraversal(theTree.root);
            cout << "\n\n";

        } else if(userAnswerI == 7)
        {
            theTree.InOrderTraversal(theTree.root);
            cout << "\n\n";

        } else if(userAnswerI == 8)
        {
            theTree.LevelOrderTraversal(theTree.root);
            cout << "\n\n";

        }

    } while(userAnswerI > 0 && userAnswerI <= 8);   
}