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
        newNode -> leftLink = NULL;
        newNode -> rightLink = NULL;

        return newNode;
    }

   node* Insert(node* root, int data)
    {
        node* tempRoot = (node*)malloc(sizeof(node));
        tempRoot = root;
    
        if(tempRoot == NULL)
        {
            return CreateNewNode(data);

        } else if(tempRoot -> data >= data)
        {
            tempRoot -> leftLink = Insert(tempRoot -> leftLink, data);

        } else
        {
            tempRoot -> rightLink = Insert(tempRoot -> rightLink, data);
        }
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
        cout << "Menu\n1. Tambah data ke tree\n2. Cari data\n3. Hapus data dari tree - deletion by Merging\n4. Hapus data dari tree - deletion by Copying\n5. Pre-order traversal\n6. Post-order traversal\n7. In-oder traversal\n0. Keluar\n\nPilihan Anda : ";
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

    } while(userAnswerI != 0);
}