//
//  llques.h
//  MyCodes
//
//  Created by Devanshu Rajpoot on 21/03/23.
//
// Leetcode
// Read fron GFG (7)
// 206. Reverse Link List
// 92.  Reverse Link List II
// 876. Middle of the Linked List
// 25.  Reverse Nodes in k-Group
// 141. Linked List Cycle
// // CStudio startnode of cycle
// // CStudio removeloop from list
// 21.  Merge Two Sorted Lists
// 203. Remove Linked List Elements
// 2095.Delete the Middle Node of a Linked List
// 19.  Remove Nth Node From End of List
// 83.  Remove Duplicates from Sorted List
// 82.  Remove Duplicates from Sorted List II
// // GFG Remove Duplicates from unsorted List
// // CStudio Sort linked list of 0s 1s 2s
// 234. Palindrome Linked List
// 2.   Add Two Numbers
// 445. Add Two Numbers II
// // GFG Clone a linked list with next and random pointer
// (LBSheet) Move the last element to Front in a Linked List
// // GFG Add 1 to a number represented as linked list
// 160. Intersection of Two Linked Lists
// // GFG Intersection of sorted lists (common elements in both list)
// // GFG Split a Circular Linked List into two halves
// 725. Split Linked List in Parts
// // GFG Reverse a Doubly Linked List
// 61. Rotate List
// 1721. Swapping Nodes in a Linked List
// // GFG Multiply two linked lists
// // GFG Segregate even and odd nodes in a Link List
// 1290. Convert Binary Number in a Linked List to Integer
// 2487. Remove Nodes From Linked
// // GFG Merge Sort for Linked List
// 1669. Merge In Between Linked Lists
// // GFG Flattening a Linked List
// // GFG Merge K sorted linked lists

#ifndef llques_h
#define llques_h

using namespace std;

// leetcode 206. Reverse link list

void reversell(node * &head, node * curr, node * prev);

// leetcode 92. Reverse link list II

void reversell2(node * &head,int left,int right);

// leetcode 876. Middle of the Linked List

node* middleNode(node * &head);

// leetcode 25. Reverse Nodes in k-Group

void reversekgroup(node * &head,int k);

// leetcode 141. Linked List Cycle  (detect loop)
// Code studio Detect and remove loop from link list
//https://rb.gy/enqc

bool detectloop(node *head);
 
    //using this function for above code
    node * startnode(node * &head);

    //using this function for above code
    void removeloop(node * &head);

// leetcode 21. Merge Two Sorted Lists

node* mergeTwoLists(node* list1, node* list2);

// leetcode 203. Remove Linked List Elements

node * removeElements(node* head, int val);

// leetcode 2095. Delete the Middle Node of a Linked List

node* deleteMiddle(node* head);

// leetcode 19. Remove Nth Node From End of List

node* removeNthFromEnd(node* head, int n);

// leetcode 83. Remove Duplicates from Sorted List

node* deleteDuplicates(node* head);

// leetcode 82. Remove Duplicates from Sorted Lis

node* deleteDuplicates2(node* head);

// GFG Remove Duplicates from unsorted List

node * removeDuplicates( node *head);

// Code Studio Sort linked list of 0s 1s 2s

node* sortList(node *head);

// leetcode 234. Palindrome Linked List

bool isPalindrome(node* head);

// leetcode 2. Add Two Numbers

node* addTwoNumbers(node* l1, node* l2);

// leetcode 445. Add Two Numbers II

node* addTwoNumbersII(node* l1, node* l2);

// Geekforgeeks Clone a linked list with next and random pointer

node *copyList(node *head);

// (LBSheet) Move the last element to Front in a Linked List

node *movetofront(node *head);

// GFG Add 1 to a number represented as linked list

node* addOne(node *head);

// leetcode 160. Intersection of Two Linked Lists

node *getIntersectionNode(node *headA, node *headB);

// GFG Intersection of sorted lists (common elements in both list)

node* findIntersection(node* head1, node* head2);

// GFG Split a Circular Linked List into two halves

void splitList(node *head, node **head1_ref, node **head2_ref);

// leetcode 725. Split Linked List in Parts

vector<node*> splitListToParts(node* head, int k);

// GFG Reverse a Doubly Linked List

dnode* reverseDLL(dnode * head);

// leetcode 61. Rotate List

node* rotateRight(node* head, int k);

// leetcode 1721. Swapping Nodes in a Linked List

node* swapNodes(node* head, int k);

// GFG Multiply two linked lists

long long  multiplyTwoLists (node* l1, node* l2);

// GFG Segregate even and odd nodes in a Link List

node* divide(int N, node *head);

// leetcode 1290. Convert Binary in a Linked List to decimal

int getDecimalValue(node* head);

// leetcode 2487. Remove Nodes From Linked
// GFG Delete nodes having greater value on right

node* removeNodes(node* head);

// GFG Merge Sort for Linked List

node* mergeLists(node* list1, node* list2);
node* mergeSort(node* head);

// leetcode 1669. Merge In Between Linked Lists

node* mergeInBetween(node* list1, int a, int b, node* list2);

// GFG Flattening a Linked List

node* mergeflatten(node* list1, node* list2);
node *flatten(node *root);

// GFG Merge K sorted linked lists

node * mergeKLists(node *arr[], int K);
#endif /* llques_h */
