//
//  Trees.h
//  MyCodes
//
//  Created by Devanshu Rajpoot on 24/04/23.
//
// Creating a Binary Tree (createtree)
// Printing a Binary Tree (printtree)
// Level order traversal (levelprint)
// Reverse Level order traversal (Reverselevelprint)
// Printing Inorder Traversal (printinorder)
// Printing Preorder Traversal (printpreorder)
// Printing Postorder Traversal (printpostorder)
// Count Leaves in Binary Tree (countLeaves)



#ifndef Trees_h
#define Trees_h

using namespace std;

class Node
{
    public :
        int data;
        Node * left;
        Node * right;
        
        Node(int d)
        {
            this->data = d;
            this->left = NULL;
            this->right  = NULL;
        }
};

Node * createtree();

void printtree(Node * root);

void levelprint(Node * root);

void Reverselevelprint(Node * root);

void printinorder(Node * root);

void printpreorder(Node * root);

void printpostorder(Node * root);

int countLeaves(Node* root);

#endif /* Trees_h */
