//
//  Trees.h
//  MyCodes
//
//  Created by Devanshu Rajpoot on 24/04/23.
//

#ifndef Trees_h
#define Trees_h

using namespace std;

class Node {
    
    int data;
    Node * left;
    Node * right;
    
    void Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right  = NULL;
    }
}



#endif /* Trees_h */
