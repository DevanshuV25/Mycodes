//
//  srchsort.h
//  MyCodes
//
//  Created by Devanshu Rajpoot on 21/03/23.
//
//  Linear search
//  Binay search
//  Slection sort
//  Bubble sort
//  Bubble sort Recursivly
//  insertion sort

#ifndef srchsort_h
#define srchsort_h
#include "general.h"
using namespace std;



bool linsearch(int a[],int size,int key)
{
    for(int i=0;i<size;i++)
    {
        if(a[i]==key)
            return true;
    }
    return false;
    
}

//  Binay search

bool binsearch(int a[],int size,int key)
{
    int start=0;
    int end=size-1;
    int mid;
    
    while(start<=end) // be sure about this condition.
    {
        mid=(start/2)+(end/2);
        if(a[mid]==key)
            return true;
        
        else if(a[mid]>key)
            end=mid-1;

        else
            start=mid+1;
    }
    return false;
}

//  Slection sort

void selsort(int a[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(a[j]<a[i])
            {
                swap(&a[i],&a[j]);
            }
        }
    }
}

//  Bubble sort

void blbsort(int ar[],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(ar[j]>ar[j+1])
                swap(&ar[j],&ar[j+1]);
        }
    }
}

// Bubble sort Recursivly

void Rblbsort(int ar[],int size)
{
    if(size == 1)
        return;
    
    int count=0;
    
    for(int j=0;j<size-1;j++)
    {
        if(ar[j]>ar[j+1])
        {
            swap(&ar[j],&ar[j+1]);
            count++;
        }
    }
    if (count == 0)
        return;
    
    Rblbsort(ar,size-1);
    
}

//  insertion sort

void inssort(int arr[],int size)
{
    for(int i=1;i<size;i++)
    {
       for(int j=i-1;j>=0;j--)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
            else
                break;
        }
    }
}

#endif /* srchsort_h */
