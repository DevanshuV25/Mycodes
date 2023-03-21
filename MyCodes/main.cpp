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
    node * head;
    head=endlist(4);
    printlist(head);
//    reversell(head,head,NULL);
//    printlist(head);
    
    cout<<"middle "<<middleNode(head)->data<<endl;
    cout<<"head "<<head->data<<endl;
}
