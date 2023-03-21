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
/*
void reversell2(node * &head,int left,int right)
{
    if(left == 1) // for first list
    {
        node * thead = head;
        int count=1;
        while(count++ != right)
        {
            thead = thead->next;
        }
        if(thead->next == NULL)
        {
            reversell(head);
        }
        else
        {
            node * temp = thead->next;
            thead->next = NULL;
            reversell(head);
            thead = head;
            while(thead->next != NULL)
            {
                thead = thead->next;
            }
            thead->next = temp;
        }
        return;
    }
    
    // for middle list
    
    node * thead = head;
    node * lthead = NULL;
    int count=1;
    while(count++ != right)
    {
        if(count == left)
            lthead = thead;
        thead = thead->next;
        
    }
    
    if(thead->next == NULL)  // for last list
    {
        reversell(lthead->next);
        return;
    }
    
    node * temp = thead->next;
    thead->next = NULL;
    reversell(lthead->next);
    node * ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}
*/
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

#endif /* llques_h */
