//
//  general.h
//  MyCodes
//
//  Created by Devanshu Rajpoot on 21/03/23.
//

#ifndef general_h
#define general_h

using namespace std;

void swap(int *x,int *y)
{
    *x=*x+*y;
    *y=*x-*y;
    *x=*x-*y;
}

void printarray(int a[],int size)
{
    for(int i=0;i<size;i++)
        cout<<a[i]<<" ";
}


#endif /* general_h */
