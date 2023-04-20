//
//  general.cpp
//  MyCodes
//
//  Created by Devanshu Rajpoot on 20/04/23.
//

#include <stdio.h>
#include <iostream>
#include <math.h>
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

int Bintodec(int n)
{
        int dec = 0,num = 0,i = 0;
        while(n != 0){
            num = n%10;
            dec = dec + num*pow(2,i);
            i++;
            n = n/10;
        }
        return dec;
}
