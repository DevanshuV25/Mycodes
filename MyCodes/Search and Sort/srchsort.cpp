//
//  srchsort.cpp
//  MyCodes
//
//  Created by Devanshu Rajpoot on 20/04/23.
//

#include <stdio.h>
#include <iostream>
#include <math.h>
#include "general.h"
using namespace std;

// Linear search

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

// Merge Sort
//merge function
void merge(int arr[], int p, int q, int r)
{

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int start,int end)
{
    if(start >= end)
        return ;
    int mid=(start + end)/2;
    
    //divide
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);
    
    //merge
    merge(arr, start, mid, end);
    
}


