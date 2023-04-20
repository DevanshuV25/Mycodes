//
//  linklist.cpp
//  MyCodes
//
//  Created by Devanshu Rajpoot on 20/04/23.
//

#include <stdio.h>
#include <iostream>
#include <math.h>
#include "llist.h"
#include <map>
#include <vector>

using namespace std;

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

//                      QUESTIONS

// leetcode 206. Reverse link list

void reversell(node * &head, node * curr, node * prev)
{
    // first function call should be reversell(head,head,NULL)
    
    // base case
    if(curr == NULL)
    {
        head = prev;
        return;
    }
    
    node * frwd = curr->next;
    reversell(head,frwd,curr);
    curr->next = prev;
    
/*
 void reversell(node * &head )
{
    node * prev = NULL;
    node * curr = head;
    node * frwd = NULL;
    
    if(head == NULL || head->next == NULL)
    {
        return;
    }
    while(curr != NULL)

    {
        frwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = frwd;
    }
    head = prev;
    
    // my approach of 3 pointers.
    node * curh = head;
    node * nex = head;
    node * frd = head;
    
    while(nex->next != NULL)
    {
        nex = nex->next;
    }
    
    head = nex;
    while(nex != curh)
    {
        while(frd->next != nex)
        {
            frd = frd->next;
        }
        
        if(frd->next == nex)
        {
            nex->next = frd;
            nex = nex->next;
            frd = curh;
        }
    }
    nex->next = NULL;
   */
}

// leetcode 92. Reverse link list II

void reversell2(node * &head,int left,int right)
{
    int l=left;
   
    if(left == 1 && right == 1)
    {
        return;
    }
    node * blist = head;
    node * alist = head;
    while(right != 1)
    {
        if(left > 2)
            blist = blist->next;
        alist = alist->next;
        right--;
        left--;
    }
    
    node * temp = alist;
    alist = alist->next;
    temp->next = NULL;

    if(l == 1)
        reversell(blist,blist,NULL);
    else
        reversell(blist->next,blist->next,NULL);

    if(l == 1)
    {
        head = blist;
    }
    while(blist->next != NULL)
    {
        blist = blist->next;
    }
    blist->next = alist;
    return;
}

// leetcode 876. Middle of the Linked List

node* middleNode(node * &head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    if(head->next->next == NULL)
    {
        return head->next;
    }
    node * slow = head;
    node * fast = head->next;
    
    while(fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if(fast != NULL)
            fast = fast->next;
    }
    return slow;
    
//    int nd = (lenlist(head)/2)+1;
//    node * temp = head;
//    while(nd-- != 1)
//    {
//        temp = temp->next;
//    }
//    return temp->data;
}

// leetcode 25. Reverse Nodes in k-Group

void reversekgroup(node * &head,int k)
{
    node * grpend = head;
    node * nlist = NULL;
    int tk = k;
    
    // base case
    if(head == NULL)
    {
        return;
    }
    // base case 2
    if(lenlist(head) < k)
    {
        return;
    }
       
    // actual case
    while(tk != 1)
    {
        grpend = grpend->next;
        tk--;
    }
    nlist = grpend->next;
    grpend->next = NULL;
    reversell(head,head,NULL);
    reversekgroup(nlist,k); // recursion
    
    while(grpend->next != NULL)
    {
        grpend = grpend->next;
    }
    grpend->next = nlist;

}

// leetcode 141. Linked List Cycle  (detect loop)
// Code studio Detect and remove loop from link list
//https://rb.gy/enqc

bool detectloop(node *head)
{
        if(head == NULL)
        {
            return false;
        }
        node * slow = head;
        node * fast = head;

        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow)
                return true;
            
        }
        return false;
}
 
    //using this function for above code
    node * startnode(node * &head)
    {
        
        if(detectloop(head))
        {
            node * slow = head;
            node * fast = head;
            
            while(fast != NULL && fast->next != NULL)
            {
                fast = fast->next->next;
                slow = slow->next;
                
                if(fast == slow)
                    break;
            }
            // using floyde cycle detection
            slow = head;
            while (slow != fast )
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
        else
        {
            return head;
        }
    }

    //using this function for above code
    void removeloop(node * &head)
    {
        if(head == NULL)
        {
            return;
        }
        //using startnode approach
        node * temp = startnode(head);
        while(temp->next != startnode(head))
        {
            temp = temp->next;
        }
        temp->next = NULL;
        
        
    //  check and shift temp apprach works fine but show TLE
    //    if(head == NULL)
    //    {
    //        return;
    //    }
    //    if(slow == fast)
    //        {
    //            while(temp != NULL)
    //            {
    //                while(check != temp)
    //                {
    //                    if(temp->next == check)
    //                    {
    //                        temp->next = NULL;
    //                        return head;
    //                    }
    //                    else
    //                    {
    //                        check = check->next;
    //                    }
    //                }
    //                temp = temp->next;
    //                check = head;
    //            }
    //        }
    //
    //        return head;
    }

// leetcode 21. Merge Two Sorted Lists

node* mergeTwoLists(node* list1, node* list2)
{
    if(list1 == NULL && list2 == NULL)
    {
        return NULL;
    }
    if(list1 == NULL && list2 != NULL)
    {
        return list2;
    }

    if(list2 == NULL && list1 != NULL)
    {
        return list1;
    }
    
    node * temp = list2;
    node * curr = list1->next;
    node * prev = list1;

    while(temp != NULL)
    {
        if(temp->data < list1->data)
        {
            list2 = list2->next;
            temp->next = list1;
            list1 = temp;
            temp = list2;
            prev = list1;
            curr = list1->next;
        }
        
        if(curr == NULL && temp != NULL)
        {
            list2 = list2->next;
            prev->next = temp;
            temp->next = NULL;
            curr = temp;
            temp = list2;
        }

         if(temp!=NULL && prev!=NULL && curr!=NULL && temp->data >= prev->data && temp->data < curr->data)
         {
            list2 = list2->next;
            prev->next = temp;
            temp->next = curr;
            prev = temp;
            temp = list2;
        }
        else
        {
             if(curr != NULL)
             {
                prev = prev->next;
                curr = curr->next;
            }
        }
    }

    return list1;
}

// leetcode 203. Remove Linked List Elements

node * removeElements(node* head, int val)
{
    node * htemp = head;
    node * lnode = head;
    if(head == NULL)
    {
        return head;
    }
    if( head->data == val) // for 1st position
    {
        head = head->next;
        return removeElements(head,val);
    }
    
    while(htemp != NULL && htemp->data != val)
    {
        lnode=htemp;
        htemp = htemp->next;
    }
    if(htemp != NULL)
    {
        lnode->next = htemp->next;
        htemp = htemp->next;
        lnode->next = removeElements(htemp,val);
    }
    
    return head;
}

// leetcode 2095. Delete the Middle Node of a Linked List

node* deleteMiddle(node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return NULL;
    }
    if(head->next->next == NULL)
    {
        head->next = NULL;
        return head;
    }

    node * slow = head;
    node * fast = head->next;
    node * s = NULL;

    while(fast != NULL)
    {
        s = slow;
        slow = slow->next;
        fast = fast->next;
        if(fast != NULL)
            fast = fast->next;
    }
    s->next = slow->next;
    return head;
}

// leetcode 19. Remove Nth Node From End of List

node* removeNthFromEnd(node* head, int n)
{
    node * slow = head;
    node * fast = head;
    
    if(head->next == NULL && n==1)
    {
        return NULL;
    }
    
    int x = n;
    while(x != 0 )
    {
        if(fast != NULL)
            fast = fast->next;
        x--;
    }
    while(fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    
    if(slow == head)
    {
        head = head->next;
    }
    else
    {
        node * temp = head;
        while(temp->next != slow)
        {
            temp = temp->next;
        }
        temp->next  = temp->next->next;
    }
    
    return head;
}

// leetcode 83. Remove Duplicates from Sorted List

node* deleteDuplicates(node* head)
{
    node * prev = head;
    node * temp = head;
    while(prev != NULL)
    {
        if(temp == NULL || prev->data != temp->data )
        {
            prev->next = temp;
            prev = temp;
        }
        if(temp != NULL)
        temp = temp->next;
    }
    return head;
}

// leetcode 82. Remove Duplicates from Sorted Lis

node* deleteDuplicates2(node* head)
{
    node * curr = head;
    map<int,int> m;
    while(curr != NULL)
    {
        m[curr->data]++;
        curr = curr->next;
    }
    node * dummy = new node(0);
    node * temp = dummy;
    curr = head;
    while(curr != NULL)
    {
        if(m[curr->data] == 1)
        {
            dummy->next = curr;
            dummy = dummy->next;
            curr = curr->next;
            dummy->next = NULL;
        }
        else
            curr = curr->next;
    }
    return temp->next;
}

// GFG Remove Duplicates from unsorted List

node * removeDuplicates( node *head)
{
    // your code goes here
    node * curr = head;
    node * prev = NULL;
    map<int,int> m;
    m[curr->data]=1;
    prev = curr;
    curr = curr->next;
    while (curr != NULL)
    {
      if (m[curr->data])
           prev->next = curr->next;
       else
       {
           m[curr->data] = 1;
           prev = curr;
       }
           
       curr = prev->next;
    }
    return head;
}

// Code Studio Sort linked list of 0s 1s 2s

node* sortList(node *head)
{
    // Write your code here.
    node * nhead = head;
    node * zero = NULL;
    node * zo = NULL;
    node * one = NULL;
    node * oe = NULL;
    node * two = NULL;
    node * to = NULL;
    while(nhead != NULL )
    {
        if(nhead->data == 0)
        {
            if(zero == NULL)
            {
                zero = nhead;
                zo = zero;
            }
            else
            {
                zo->next = nhead;
                zo = zo->next;
            }
            nhead = nhead->next;
            continue;
        }
        if(nhead->data == 1)
        {
            if(one == NULL)
            {
                one = nhead;
                oe = one;
            }
            else
            {
                oe->next = nhead;
                oe = oe->next;
            }
            nhead = nhead->next;
            continue;
        }
        if(nhead->data == 2)
        {
            if(two == NULL)
            {
                two = nhead;
                to = two;
            }
            else
            {
                to->next = nhead;
                to = to->next;
            }
            nhead = nhead->next;
            continue;
        }
    }
    if (zero != NULL) {
      nhead = zero;
    }
    else if(one != NULL)
    {
        nhead = one;
    }
    else
    {
        nhead = two;
    }
    if(zo != NULL){
        zo->next = one;
        if(one == NULL){
            zo->next = two;
        }
    }
    if (oe != NULL) {
      oe->next = two;
    }
    if (to != NULL) {
      to->next = NULL;
    }

    return nhead;
        
}

// leetcode 234. Palindrome Linked List

bool isPalindrome(node* head)
{
    if(head->next == NULL)
    {
        return true;
    }
    node * midnode;
    midnode = middleNode(head);
    reversell(midnode->next,midnode->next,NULL);
    node * temp1 = head;
    node * temp2 = midnode->next;
    while(temp2 != NULL)
    {
        if(temp1 != NULL && temp2 != NULL)
        {
            if(temp1->data != temp2->data){
                return false;
            }
        temp1 = temp1->next;
        temp2 = temp2->next;
        }
    }
    return true;
}

// leetcode 2. Add Two Numbers

node* addTwoNumbers(node* l1, node* l2)
{
    node * t1 = l1;
    node * t2 = l2;
    int num = 0, rem = 0, carry = 0;
    node *ans = new node(0);
    node *head = ans;
    while(t1 != NULL || t2 != NULL || carry != 0 )
    {
        int val1 = 0,val2 = 0;
        if(t1 != NULL)
        {
            val1 = t1->data;
        }
        if(t2 != NULL)
        {
            val2 = t2->data;
        }
        num = val1 + val2 + carry;
        rem = num%10;
        ans->next = new node(rem);
        ans = ans->next;
        carry = num/10;
        if(t1 != NULL)
            t1 = t1->next;
        if(t2 != NULL)
            t2 = t2->next;
    }
    head = head->next;
    
    return head;
}

// leetcode 445. Add Two Numbers II

node* addTwoNumbersII(node* l1, node* l2)
{
    reversell(l1,l1,NULL);
    reversell(l2,l2,NULL);
    node * t1 = l1;
    node * t2 = l2;
    int num = 0, rem = 0, carry = 0;
    node *ans = new node(0);
    node *head = ans;
    while(t1 != NULL || t2 != NULL || carry != 0 )
    {
        int val1 = 0,val2 = 0;
        if(t1 != NULL)
        {
            val1 = t1->data;
        }
        if(t2 != NULL)
        {
            val2 = t2->data;
        }
        num = val1 + val2 + carry;
        rem = num%10;
        ans->next = new node(rem);
        ans = ans->next;
        carry = num/10;
        if(t1 != NULL)
            t1 = t1->next;
        if(t2 != NULL)
            t2 = t2->next;
    }
    head = head->next;
    reversell(l1,l1,NULL);
    reversell(l2,l2,NULL);
    reversell(head,head,NULL);
    return head;
}

// Geekforgeeks Clone a linked list with next and random pointer

node *copyList(node *head)
{
    //Write your code here
    node * temp = head;
    node * newtemp = new node(0);
    node * newhead = newtemp;
    
    // make singly clone list
    while(temp != NULL)
    {
        node * nde = new node(temp->data);
        newtemp->next = nde;
        newtemp = newtemp->next;
        temp = temp->next;
    }
    
    // mapping the orginal list with clone list , org node then clone node....
    newhead = newhead->next;
    temp = head;//org
    newtemp = newhead;//new
    node * org;
    node * clone;
    while(temp != NULL && newtemp != NULL)
    {
        org = temp->next;
        temp->next = newtemp;
        clone = newtemp->next;
        newtemp->next = org;
        temp = org;
        newtemp = clone;
        
    }
    
    // copying the random pointers from orginal list
    
    /* run only when we have this typte of node having random pointers
     temp = head;
     while(temp != NULL)
     {
        if(temp->next != NULL && temp->arb != NULL)
            temp->next->arb = temp->arb->next;
        temp = temp->next->next;
     }/*/
    
    //unmap the orginal and clone list for seperation
    temp = head;
    newtemp = newhead;
    while(temp != NULL && newtemp != NULL)
    {
        temp->next = newtemp->next;
        if(newtemp->next != NULL)
            newtemp->next = newtemp->next->next;
        temp = temp->next;
        newtemp = newtemp->next;
        
    }
    return newhead;
}

// (LBSheet) Move the last element to Front in a Linked List

node *movetofront(node *head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    node * seclast = nullptr;
    node * last = head;
    while(last->next != NULL)
    {
        seclast = last;
        last = last->next;
    }
    seclast->next = NULL;
    last->next = head;
    head = last;
    return head;
}

// GFG Add 1 to a number represented as linked list

node* addOne(node *head)
{
    // Your Code here
    // return head of list after adding one
    reversell(head,head,NULL);
    node * t1 = head;
    node * t2 = new node(1);
    int num = 0, rem = 0, carry = 0;
    node *ans = new node(0);
    node *newhead = ans;
    while(t1 != NULL || t2 != NULL || carry != 0 )
    {
        int val1 = 0,val2 = 0;
        if(t1 != NULL)
        {
            val1 = t1->data;
        }
        if(t2 != NULL)
        {
            val2 = t2->data;
        }
        num = val1 + val2 + carry;
        rem = num%10;
        ans->next = new node(rem);
        ans = ans->next;
        carry = num/10;
        if(t1 != NULL)
            t1 = t1->next;
        if(t2 != NULL)
            t2 = t2->next;
    }
    newhead = newhead->next;
    reversell(head,head,NULL);
    reversell(newhead,newhead,NULL);
    return newhead;
}

// leetcode 160. Intersection of Two Linked Lists

node *getIntersectionNode(node *headA, node *headB)
{
    node * temp1 = headA;
    node * temp2 = headB;
    while(temp1 != temp2)
    {
        if(temp1 == NULL)
            temp1 = headB;
        else
            temp1 = temp1->next;
        
        if(temp2 == NULL)
            temp2 = headA;
        else
            temp2 = temp2->next;
    }
    return temp1;
}

// GFG Intersection of sorted lists (common elements in both list)

node* findIntersection(node* head1, node* head2)
{
    // Your Code Here
    node * temp1 = head1;
    node * temp2 = head2;
    node * dummy = new node(0);
    node * ans = dummy;
    
    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->data == temp2->data)
        {
            dummy->next = new node(temp1->data);
            dummy = dummy->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if(temp1->data < temp2->data)
        {
            temp1 = temp1->next;
        }
        else if(temp1->data > temp2->data)
        {
            temp2 = temp2->next;
        }
    }
    return ans->next;
    
}

// GFG Split a Circular Linked List into two halves

void splitList(node *head, node **head1_ref, node **head2_ref)
{
    // your code goes here
    
    node * slow = head;
    node * fast = slow->next->next;
    while(fast != head && fast != head->next)
    {
        if(fast != head && fast != head->next)
        fast = fast->next->next;
        slow = slow->next;
    }
    *head1_ref = head;
    *head2_ref = slow->next;
    node * temp = slow->next;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = *head2_ref;
    slow->next = *head1_ref;
    
}

// leetcode 725. Split Linked List in Parts

vector<node*> splitListToParts(node* head, int k)
{
        vector<node*> ans;
        node * temp = head;
        int l = lenlist(head);
        if(l>k && l%k == 0)
        {
            int g = l/k;
            while(temp != NULL)
            {
                if(g == 0 || temp == head){
                    ans.push_back(temp);
                    g = l/k;}
                g--;
                node* last = temp;
                temp = temp->next;
                if(g == 0)
                last->next = NULL;
            }
        }
        else if(l>k && l%k != 0)
        {
            int rem = l%k,g,nl = 0;

            if(rem > 1)
            {
                nl = l+rem;
                g = (nl/k);
            }else{
                g = (l/k)+ 1;
            }
            while(temp != NULL)
            {
                if(temp == head)
                    ans.push_back(temp);
                if(g == 0){
                    ans.push_back(temp);
                    if(rem != 0 && --rem != 0){
                        g = nl/k;
                }
                    else
                        g = l/k;
                }
                g--;
                node* last = temp;
                temp = temp->next;
                if(g == 0)
                    last->next = NULL;
            }
        }
        else if(l <= k)
        {
            int cnt = k;
            while(temp != NULL)
            {
                cnt--;
                ans.push_back(temp);
                node* last = temp;
                temp = temp->next;
                last->next = NULL;
            }
            if(temp == NULL && cnt > 0)
                {
                    while(cnt-- != 0 )
                    {
                        ans.push_back(temp);
                    }
                }
        }
        return ans;
    }

// GFG Reverse a Doubly Linked List

dnode* reverseDLL(dnode * head)
{
    //Your code here
    dnode * thead = head;
    dnode * temp = thead;
    while(temp != NULL)
    {
        temp = thead->next;
        thead->next = thead->prev;
        thead->prev = temp;
        if(temp != NULL)
            thead = thead->prev;
    }
    return thead;
}

// leetcode 61. Rotate List

node* rotateRight(node* head, int k)
{
    if(k == 0 || head == NULL)
        return head;
    node * temp = head;
    int t ,count = 1;
    while(temp->next != NULL )
    {
        temp = temp->next;
        count++;
    }
    t = k%count;
    while(t--)
    {
        temp = head;
        while(temp->next->next != NULL )
        {
            temp = temp->next;
        }
        node * nod = temp->next;
        if(nod != NULL)
        {temp->next = nod->next;
        nod->next = head;
        head = nod;}
    }
    
    return head;
}

// leetcode 1721. Swapping Nodes in a Linked List

node* swapNodes(node* head, int k)
{
    node *n1 = NULL , *n2 = NULL;
    for (auto p = head; p != NULL; p = p->next)
    {
        if(k <= 0)
            n2 = n2->next;
        if(n2!=NULL)
            cout<<n2->data<<endl;
        if (--k == 0) {
            n1 = p;
            n2 = head;
        }
    }
    int temp = n1->data;
    n1->data = n2->data;
    n2->data= temp;
    return head;
}

// GFG Multiply two linked lists

long long  multiplyTwoLists (node* l1, node* l2)
{
  //Your code here
  node * temp1 = l1;
  node * temp2 = l2;
  long long num1 = 0, num2 = 0;
   long long int mod=pow(10,9)+7;
  while(temp1 != NULL || temp2 != NULL)
  {
      if(temp1 != NULL){
        num1 = (num1*10+temp1->data)%mod;
        temp1 = temp1->next;
      }
      if(temp2 != NULL){
        num2 = (num2*10+temp2->data)%mod;
        temp2 = temp2->next;
      }
  }
  
  return (num1*num2)%mod;
  
}

// GFG Segregate even and odd nodes in a Link List

node* divide(int N, node *head)
{
    // code here
    node * even = new node(0);
    node * n1 = even;
    node * odd = new node(0);
    node * n2 = odd;
    node * temp = head;
        
    while(temp != NULL)
    {
        if(temp->data %2 == 0)
        {
            n1->next = temp;
            n1 = n1->next;
        }
        else
        {
            n2->next = temp;
            n2 = n2->next;
        }
        temp = temp->next;
    }
    n1->next = odd->next;
    n2->next = NULL;
    head = even->next;
    delete even;
    delete odd;
    
    return head;
}

// leetcode 1290. Convert Binary in a Linked List to decimal

int getDecimalValue(node* head)
{
    int k=0;
    while(head)
    {
        k=k*2+head->data;
        head=head->next;
    }
    return k;
}

// leetcode 2487. Remove Nodes From Linked
// GFG Delete nodes having greater value on right

node* removeNodes(node* head)
{
    if(head->next == NULL || head == NULL)
        return head;
        
    node * temp = head->next;
    node * prev = head;
    node * large = prev;
    while(temp != NULL)
    {
        if(temp->data > large->data)
            large = temp;
        temp = temp->next;
    }
    head = large;
    temp = head->next;
    while(temp != NULL)
    {
        if( temp->data <= prev->data)
        {
            temp = temp->next;
            prev = prev->next;
        }
        else
            break;
    }
    
    if(temp == NULL)
        return head;
    
    temp = head;
    prev = head;

    while(temp != NULL)
    {
        if(temp->next != NULL && temp->next->data > temp->data )
        {
            if(temp == head)
            {
                head = temp->next;
                prev = head;
                temp = head;
            }
            else
            {
                prev->next = temp->next;
                temp = temp->next;
            }
        }
        else
        {
            temp = temp->next;
            if(prev->next != temp)
            {
                prev = prev->next;
            }
        }
    }
        
    head = removeNodes(head);
    
    return head;
}

// GFG Merge Sort for Linked List

node* mergeLists(node* list1, node* list2)
{
    if(list1 == NULL && list2 == NULL)
    {
        return NULL;
    }
    if(list1 == NULL && list2 != NULL)
    {
        return list2;
    }

    if(list2 == NULL && list1 != NULL)
    {
        return list1;
    }
    
    node * l1 = list1;
    node * l2 = list2;
    node * dummy = new node(-1);
    node * dp = dummy;
    
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->data <= l2->data)
        {
            dp->next = l1;
            dp = dp->next;
            l1 = l1->next;
        }
        else
        {
            dp->next = l2;
            dp = dp->next;
            l2 = l2->next;
        }
    }
    
    while(l1 != NULL)
    {
        dp->next = l1;
        dp = dp->next;
        l1 = l1->next;
    }
    
    while(l2 != NULL)
    {
        dp->next = l2;
        dp = dp->next;
        l2 = l2->next;
    }
    
    dummy = dummy->next;
    return dummy;
}
node* mergeSort(node* head)
{
    // your code here
    
    if(head == NULL || head->next == NULL)
        return head;
        
    node * mid = middleNode(head);
    node * l1 = head;
    node * l2 = mid->next;
    mid->next = NULL;
        
    l1 = mergeSort(l1);
    l2 = mergeSort(l2);
    
    head = mergeLists(l1,l2);
    
    return head;
}

// leetcode 1669. Merge In Between Linked Lists

node* mergeInBetween(node* list1, int a, int b, node* list2)
{

    node * temp1 = list1;
    node * Ftemp = temp1;
    node * temp2 = list2;
    int cnt = 0;
        
    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
        
    while(cnt < b+1)
    {
        if(cnt == a-1)
        {
            temp1 = Ftemp;
        }
            Ftemp = Ftemp->next;
            cnt++;
    }
    temp1->next = list2;
    temp2->next = Ftemp;
    
    return list1;
}

// GFG Flattening a Linked List

node* mergeflatten(node* list1, node* list2)
{
//    if(list1 == NULL && list2 == NULL)
//    {
//        return NULL;
//    }
//    if(list1 == NULL && list2 != NULL)
//    {
//        return list2;
//    }
//
//    if(list2 == NULL && list1 != NULL)
//    {
//        return list1;
//    }
//
//    node * l1 = list1;
//    node * l2 = list2;
//    node * dummy = new node(-1);
//    node * dp = dummy;
//
//    while(l1 != NULL && l2 != NULL)
//    {
//        if(l1->data <= l2->data)
//        {
//            dp->bottom = l1;
//            dp = dp->bottom;
//            l1 = l1->bottom;
//        }
//        else
//        {
//            dp->bottom = l2;
//            dp = dp->bottom;
//            l2 = l2->bottom;
//        }
//    }
//
//    while(l1 != NULL)
//    {
//        dp->bottom = l1;
//        dp = dp->bottom;
//        l1 = l1->bottom;
//    }
//
//    while(l2 != NULL)
//    {
//        dp->bottom = l2;
//        dp = dp->bottom;
//        l2 = l2->bottom;
//    }
//
//    dummy = dummy->bottom;
//    return dummy;
    return list1; // this only for no error remove it
}
node *flatten(node *root)
{
   // Your code here
   
   if(root == NULL || root->next == NULL)
    return root;
    
   node * L1 = root;
   node * L2 = root->next;
   
   root = mergeflatten(L1,L2);
   root->next = L2->next;
   root = flatten(root);
   
   return root;
   
}

