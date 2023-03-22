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

    inserthead(head,4);
    inserthead(head,3);
    inserthead(head,2);
    inserthead(head,1);
    
    printlist(head);
    
    reversekgroup(head,3);
    printlist(head);
    
    
    
    //cout<<"middle "<<middleNode(head)->data<<endl;
    cout<<"head "<<head->data<<endl;
}
