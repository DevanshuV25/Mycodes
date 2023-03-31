//
//  llques.h
//  MyCodes
//
//  Created by Devanshu Rajpoot on 21/03/23.
//
// Leetcode
// 206. Reverse Link List
// 92.  Reverse Link List II
// 876. Middle of the Linked List
// 25. Reverse Nodes in k-Group
// 141. Linked List Cycle
// // CStudio startnode of cycle
// // CStudio removeloop from list
// 203. Remove Linked List Elements
// 2095.Delete the Middle Node of a Linked List
// 19.  Remove Nth Node From End of List
// 83.  Remove Duplicates from Sorted List
// // CStudio Sort linked list of 0s 1s 2s

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

// leetcode 141. Linked List Cycle  (detect loop)
// Code studio Detect and remove loop from link list
//https://www.codingninjas.com/codestudio/problems/interview-shuriken-42-detect-and-remove-loop_241049?leftPanelTab=1&campaign=YouTube_codestudio_lovebabbar28thjan&utm_source=youtube&utm_medium=affiliate&utm_campaign=YouTube_codestudio_lovebabbar28thjan

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
    {/*
        node * head = NULL;
        node * temp = NULL;

        if(list1 == NULL && list2 == NULL)
        {
            return head;
        }
        else if(list1 != NULL || list2 != NULL || list1->data <= list2->data )
        {
            head = list1;
        
            if (list1->next != NULL && list1->next->data > list2->data)
            {
                temp = list1->next;
                list1->next = list2;
                list2 = list2->next;
                list1 = list1->next;
                list1->next = mergeTwoLists(temp,list2);
            }
            else
            {
                temp = NULL;
                list1->next = list2;
                
            }
            
        }
    else
        return head;*/
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

#endif /* llques_h */
