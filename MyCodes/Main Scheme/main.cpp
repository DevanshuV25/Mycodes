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

using namespace std;

int main()
{
    node * list1 = NULL;
    node * list2 = NULL;

    inserthead(list1,5);
    inserthead(list1,4);
    inserthead(list1,3);
    inserthead(list1,2);
    inserthead(list1,1);

    inserthead(list2,0);
    inserthead(list2,3);
    inserthead(list2,1);

    printlist(list1);
    printlist(list2);

    cout<<Bintodec(110101)<<endl;

    int arr[7] = {3,6,4,7,1,2,8};
    
    mergesort(arr, 0, 6);
    
    printarray(arr, 7);
}
