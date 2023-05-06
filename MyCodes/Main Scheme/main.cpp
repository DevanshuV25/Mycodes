//
//  main.cpp
//  MyCodes
//
//  Created by Devanshu Rajpoot on 21/03/23.
//
#include <iostream>
#include "llist.h"
#include "llques.h"
#include "general.h"
#include "srchsort.h"
#include "Trees.h"

using namespace std;

int main()
{
    Node * root = NULL;
    
    root = createtree();
    cout<<endl;
    printinorder(root);
    cout<<endl;
    printpreorder(root);
    cout<<endl;
    printpostorder(root);
    
}

//1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
