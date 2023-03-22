//
//  llques.h
//  MyCodes
//
//  Created by Devanshu Rajpoot on 21/03/23.
//
// Leetcode
// 206. Reverse Link List
// 92. Reverse Linbk List II
// 876. Middle of the Linked List

#ifndef llques_h
#define llques_h

#include "llist.h"

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

#endif /* llques_h */
