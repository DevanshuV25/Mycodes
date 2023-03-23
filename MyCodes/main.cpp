//
//  main.cpp
//  MyCodes
//
//  Created by Devanshu Rajpoot on 21/03/23.
//

#include <iostream>
#include "general.h"
#include "srchsort.h"
#include "llques.h"

int main()
{
    node * head = NULL;
    // inserthead(head,7);
    
    // inserthead(head,6);
    
    //    inserthead(head,8);
    //
    //    inserthead(head,7);
    //
    //    inserthead(head,6);
    //
    inserthead(head,5);
    node * tail = head;
    inserthead(head,4);
    inserthead(head,3);
    inserthead(head,2);
    inserthead(head,1);
    printlist(head);
    node * temp = head;
    temp = temp->next;
    tail->next = temp;
    
    // cirlcular list check
    
    cout<<"Loop "<<detectloop(head)<<endl;
    cout<<"startnode "<< startnode(head)->data<<endl;
    removeloop(head);
    
    cout<<"after removeLoop "<<detectloop(head)<<endl;
    
    //cout<<"middle "<<middleNode(head)->data<<endl;
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    //printlist(head);
}
