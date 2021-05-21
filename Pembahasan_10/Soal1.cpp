#include <iostream>
using namespace std;

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

    node* CreateNewNode(int data)
    {
        node* newNode = (node*)malloc(sizeof(node));
        newNode -> data = data;
        newNode -> leftLink = newNode -> rightLink = NULL;

        return newNode;
    }

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

};

int main()
{
    Tree theTree;
    theTree.root = NULL;

    int dataContainer;
    int userAnswerI;
    
    do
    {
        cout << "Menu\n1. Tambah data ke tree\n2. Cari data\n3. Hapus data dari tree - deletion by Merging\n4. Hapus data dari tree - deletion by Copying\n5. Pre-order traversal\n6. Post-order traversal\n7. In-oder traversal\n8. Level-order traversal\n0. Keluar\n\nPilihan Anda : ";
        cin >> userAnswerI;

        if(userAnswerI == 1)
        {
            int counter = 1;
            cout << "\nInput data, untuk mengakhiri dengan 0\n";

            do
            {   
                cout << "Input data ke-" << counter << " : ";
                cin >> dataContainer;

                counter++;

            } while (dataContainer != 0);
            
            theTree.root = theTree.Insert(theTree.root, dataContainer);
        }

    } while(userAnswerI > 0 && userAnswerI <= 8);
}