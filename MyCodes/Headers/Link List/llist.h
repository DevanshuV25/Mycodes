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

void inserthead(node * &head, int d)
{
    if(head == NULL)
    {
        node * temp = new node(d);
        temp->next = NULL;
        head = temp;
        return;
    }
    //create new node
    node * temp = new node(d);
    temp->next=head;
    head=temp;
}

// Printing the list

void printlist(node * &head)
{
    // temprary head
    node * temp= head;
    
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

// Length of link list

int lenlist(node * head)
{
    node * temp = head;
    int cnt=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

// Inserting at TAIL;

void inserttail(node * &tail,int d)
{
    // create new node
    node * temp = new node(d);
    tail->next = temp;
    tail = temp;
}

//  Insert at middle position

void insertpos(node* &head,node* &tail,int d,int pos)
{
    if(head == NULL)
    {
        node * temp = new node(d);
        temp->next = temp;
        head = temp;
        tail = temp;
    }
    if(pos == 1) // at position 1
    {
        inserthead(head,d);
        return;
    }

    node * npos = head; //temporary head
    
    if(pos == 2) // at postion 2
    {
        // create node
        node * temp = new node(d);
        temp->next = head->next;
        head->next = temp;
        return;
    }
    
    //this number 2 in loop decide the position of node in the list
    while(pos!=2)
    {
        npos = npos->next;
        pos--;
    }
    if(npos->next== NULL) //at last position
    {
        inserttail(tail,d);
        return;
    }
    else
    {
        // create node
        node * temp = new node(d);
        temp->next = npos->next;
        npos->next = temp;
    }
    
}

// Deletion at postion
void deletepos(node* &head,node* &tail,int pos)
{
    //create a temp head
    node * htemp = head;
 
    //position is 1
    if(pos == 1)
    {
        head = head->next;
        htemp->next = NULL;
        delete htemp;
        return;
    }
    // when position >1
    while(pos--!=2)
    {
        htemp = htemp->next;
    }
    node * pnode = htemp->next; // node which want to delete
    htemp->next = pnode->next;
    if(pnode->next == NULL) // for last position
        tail = htemp;
    pnode->next = NULL;
    delete pnode;
    
}

// Deletion by value

void deleteval(node* &head,node* &tail,int d)
{
    // create a temp head
    node* htemp = head;
    node* lnode = head;
    
    if(htemp->data == d) // for 1st position
    {
        head = head->next;
        htemp->next = NULL;
        delete htemp;
        return;
    }
    while(htemp->data != d) // for >1 position
    {
        lnode=htemp;
        htemp = htemp->next;
    }
    lnode->next = htemp->next;
    if(htemp->next == NULL) // for last postion
        tail = lnode;
    htemp->next = NULL;
    delete htemp;
}

// Create a whole list by tail

node* endlist(int size)
{
    if(size < 1)
    {
        cout<<"invalid list size";
        return NULL;
    }
    int value;
    cout<<"enter the values : ";
    cin>>value;  // values by user;
    node * node1 = new node(value); // first node
    node * head = node1;
    node * tail = node1;
    
    while((size-1)!=0)
    {
        cin>>value;
        node * nodex = new node(value);
        tail->next = nodex;
        tail = nodex;
        size--;
    }
    return head;
    
}

// Create a whole list by head

node* toplist(int size)
{
    if(size < 1)
    {
        cout<<"invalid list size";
        return NULL;
    }
    int value;
    cout<<"enter the values : ";
    cin>>value;  // values by user;
    
    node * node1 = new node(value); // first node
    node * head = node1;
    
    while((size-1)!=0)
    {
        cin>>value;
        node * nodex = new node(value);
        nodex->next = head;
        head = nodex;
        size--;
    }
    return head;
}

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

void dinserthead(dnode * &head,dnode * &tail, int d)
{
    if(head == NULL)
    {
        dnode * temp = new dnode(d);
        head = temp;
        tail = temp;
    }
    else
    {
        //create new node
        dnode * temp = new dnode(d);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    
}

// Printing the list in Doubly LL

void printdlist(dnode * &head)
{
    // temprary head
    dnode * temp= head;
    
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

// Inserting at TAIL in Doubly LL

void dinserttail(dnode * &head,dnode * &tail,int d)
{
    if(tail == NULL)
    {
        dnode * temp = new dnode(d);
        head = temp;
        tail = temp;
    }
    else
    {
        // create new node
        dnode * temp = new dnode(d);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

//  Insert at middle position in Doubly LL

void dinsertpos(dnode* &head,dnode* &tail,int d,int pos)
{
    if(pos == 1) // at position 1
    {
        dinserthead(head,tail,d);
        return;
    }

    dnode * npos = head; //temporary head
    
    if(pos == 2) // at postion 2
    {
        // create node
        dnode * temp = new dnode(d);
        temp->next = head->next;
        temp->prev = head;
        head->next = temp;
        return;
    }
    
    //this number 2 in loop decide the position of node in the list
    while(pos!=2)
    {
        npos = npos->next;
        pos--;
    }
    if(npos->next== NULL) //at last position
    {
        dinserttail(head,tail,d);
        return;
    }
    else
    {
        // create node
        dnode * temp = new dnode(d);
        
        // npos is previous node pointer
        // temp is current inserted node
        
        temp->next = npos->next;
        temp->prev = npos;
        npos->next = temp;
        temp->next->prev =temp;
        
    }
    
}

// Deletion at postion in Doubly LL

void ddeletepos(dnode* &head,dnode* &tail,int pos)
{
    //create a temp head
    dnode * htemp = head;

    //position is 1
    if(pos == 1)
    {
        head = head->next;
        head->prev = NULL;
        htemp->next = NULL;
        htemp->prev = NULL;
        delete htemp;
        return;
    }
    // when position >1
    while(pos--!=2)
    {
        htemp = htemp->next;
    }
    dnode * pnode = htemp->next; // node which want to delete
    
    if(pnode->next == NULL ) // for last position
    {
        tail = htemp;
        htemp->next = NULL;
        pnode->next = NULL;
        pnode->prev = NULL;
        delete pnode;
    }
    else
    {
        htemp->next = pnode->next;
        pnode->next->prev = htemp;
        pnode->next = NULL;
        pnode->prev = NULL;
        delete pnode;
    }

}

// Deletion by value in Doubly LL

void ddeleteval(dnode* &head,dnode* &tail,int d)
{
    // create a temp head
    dnode* htemp = head;
    dnode* lnode = head;

    if(htemp->data == d) // for 1st position
    {
        head->next->prev = NULL;
        head = head->next;
        htemp->next = NULL;
        htemp->prev = NULL;
        delete htemp;
        return;
    }
    while(htemp->data != d) // for >1 position
    {
        lnode=htemp;
        htemp = htemp->next;
    }
    
    if(htemp->next == NULL) // for last postion
    {
        tail = lnode;
        lnode->next = NULL;
        htemp->next = NULL;
        htemp->prev = NULL;
        delete htemp;
    }
    else
    {
        lnode->next = htemp->next;
        htemp->next->prev = lnode;
        htemp->next = NULL;
        htemp->prev = NULL;
        delete htemp;
    }
    
}

// CIRCULAR LINK LIST FUNCTIONS

// insert after element in circular link list

void cinsertpos(node * &tail,int d,int element)
{
    //empty list
    if(tail == NULL)
    {
        node * temp = new node(d);
        temp->next = temp;
        tail = temp;
    }
    else
    {
        // for at tail position
        node * epr = tail;
        node * temp =new node(d);
        
        while(epr->data != element)
        {
            epr = epr->next;
            if(epr == tail)
            {
                cout<<"element not found"<<endl;
                return;
            }
        }
        temp->next = epr->next;
        epr->next = temp;
        
    }
    
}

// printing circular link list

void printclist(node * &tail)
{
    // temprary head
    node * temp= tail->next;
    int cnt=0;
    while(temp!=tail)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
        if(temp==tail)
            cout<<temp->data;
        cnt++;
    }
    if(cnt == 0)
    {
        cout<<temp->data<<" ";
    }
    cout<<endl;
}

// deletion node in circular link list

void cdeleteval(node * &tail,int element)
{
    //empty list
    if(tail == NULL)
    {
        return;
    }
    else
    {
        // for at tail position
        node * epr = tail;
        
        while(epr->next->data != element)
        {
            epr = epr->next;
            if(epr->next == tail->next)
                return;
        }
        node * del = epr->next;
        if(del->data == tail->data)
        {
            tail = del->next;
        }
        epr->next = del->next;
        del->next = NULL;
        delete del;
    }
    
}

// insert after element in circular doubly link list

void cdinsertpos(dnode * &tail,int d,int element)
{
    //empty list
    if(tail == NULL)
    {
        dnode * temp = new dnode(d);
        temp->next = temp;
        tail = temp;
    }
    else
    {
        // for at tail position
        dnode * temp = tail;
        dnode * inode = new dnode(d);
        
        while(temp->data != element)
        {
            temp = temp->next;
            if(temp == tail)
            {
                cout<<"element not found"<<endl;
                return;
            }
        }
        inode->next = temp->next;
        temp->next->prev = inode;
        inode->prev = temp;
        temp->next = inode;
    }
}

// printing circular doubly link list

void printcdlist(dnode * &tail)
{
    // temprary head
    dnode * temp = tail->next;
    int cnt=0;
    while(temp!=tail)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
        if(temp==tail)
            cout<<temp->data;
        cnt++;
    }
    if(cnt == 0)
    {
        cout<<temp->data<<" ";
    }
    cout<<endl;
}

// deletion node in circular doubly link list

void cddeleteval(dnode * &tail,int element)
{
    //empty list
    if(tail == NULL)
    {
        return;
    }
    else
    {
        // for at tail position
        dnode * epr = tail;
        
        while(epr->data != element)
        {
            epr = epr->next;
            if(epr->next == tail->next)
                return;
        }
        if(epr->data == tail->data)
        {
            tail = epr->next;
        }
        epr->next->prev = epr->prev;
        epr->prev->next = epr->next;
        epr->next = NULL;
        epr->prev = NULL;
        delete epr;
    }
    
}


#endif /* llist_h */
