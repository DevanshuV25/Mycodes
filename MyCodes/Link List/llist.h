//
//  llist.h
//  MyCodes
//
//  Created by Devanshu Rajpoot on 21/03/23.
//
//         Singly Link List
//  (node) creation of node
//  (inserthead) Insertion at head
//  (printlist) Printing the list
//  (lenlist) Lenght of link list
//  (inserttail) Insertion at tail
//  (insertpos) Insertion at position
//  (deletepos) deletion at position
//  (deleteval) deletion by value
//  (endlist) Create a whole list by tail
//  (toplist) Create a whole list by head
//          Doubly Link List
//  (dnode) creation of node in Doubly LL
//  (dinserthead) Insertion at head in Doubly LL
//  (printdlist) Printing the list in Doubly LL
//  (dinserttail) Insertion at tail in Doubly LL
//  (dinsertpos) Insertion at position in Doubly LL
//  (ddeletepos) deletion at position in Doubly LL
//  (ddeleteval) deletion by value in Doubly LL
//          Circular Link List (Singly & Doubly)
//  (cinsertpos) insert after element in circular link list
//  (printclist) printing circular link list
//  (cdeleteval) deletion node in circular link list
//  (cdinsertpos)insert after element in circular doubly link list
//  (printcdlist) printing circular doubly link list
//  (cddeleteval) deletion node in circular doubly link list
//
//


#ifndef llist_h
#define llist_h

using namespace std;

//creating node

class node
{
public:
    int data;
    node * next;
    
    //new node function //Constructor
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
    
    ~node() // destructor
    {
        if(this->next != NULL)
            delete next;
        this->next = NULL;
    }
};

//  Insertion at HEAD

void inserthead(node * &head, int d);

// Printing the list

void printlist(node * &head);

// Length of link list

int lenlist(node * head);

// Inserting at TAIL;

void inserttail(node * &tail,int d);

//  Insert at middle position

void insertpos(node* &head,node* &tail,int d,int pos);

// Deletion at postion
void deletepos(node* &head,node* &tail,int pos);

// Deletion by value

void deleteval(node* &head,node* &tail,int d);

// Create a whole list by tail

node* endlist(int size);

// Create a whole list by head

node* toplist(int size);

// DOUBLY LINK LIST FUNCTIONS

// Creation of doubly node

class dnode
{
public:
    int data;
    dnode * prev;
    dnode * next;
    
    //new node function //Constructor
    dnode(int data)
    {
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
    
    ~dnode() // destructor
    {
        if(this->prev != NULL && this->next != NULL)
        {
            delete prev;
            delete next;
        }
        this->prev = NULL;
        this->next = NULL;
    }
};

// Insertion at HEAD in Doubly LL

void dinserthead(dnode * &head,dnode * &tail, int d);

// Printing the list in Doubly LL

void printdlist(dnode * &head);

// Inserting at TAIL in Doubly LL

void dinserttail(dnode * &head,dnode * &tail,int d);

//  Insert at middle position in Doubly LL

void dinsertpos(dnode* &head,dnode* &tail,int d,int pos);

// Deletion at postion in Doubly LL

void ddeletepos(dnode* &head,dnode* &tail,int pos);

// Deletion by value in Doubly LL

void ddeleteval(dnode* &head,dnode* &tail,int d);

// CIRCULAR LINK LIST FUNCTIONS

// insert after element in circular link list

void cinsertpos(node * &tail,int d,int element);

// printing circular link list

void printclist(node * &tail);

// deletion node in circular link list

void cdeleteval(node * &tail,int element);

// insert after element in circular doubly link list

void cdinsertpos(dnode * &tail,int d,int element);

// printing circular doubly link list

void printcdlist(dnode * &tail);

// deletion node in circular doubly link list

void cddeleteval(dnode * &tail,int element);


#endif /* llist_h */
