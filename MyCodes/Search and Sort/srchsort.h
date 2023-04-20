//
//  srchsort.h
//  MyCodes
//
//  Created by Devanshu Rajpoot on 21/03/23.
//
//  Linear search (linsearch)
//  Binay search (binsearch)
//  Slection sort  (selsort)
//  Bubble sort (blbsort)
//  Bubble sort Recursivly (Rblbsort)
//  insertion sort (inssort)
//  Merge sort (mergesort)
//  Quick Sort (quicksort)

#ifndef srchsort_h
#define srchsort_h

using namespace std;

bool linsearch(int a[],int size,int key);

//  Binay search

bool binsearch(int a[],int size,int key);

//  Slection sort

void selsort(int a[],int size);

//  Bubble sort

void blbsort(int ar[],int size);

// Bubble sort Recursivly

void Rblbsort(int ar[],int size);

//  insertion sort

void inssort(int arr[],int size);

//Quick Sort
//Partition function
void quicksort(int arr[], int lb,int ub);
int partition(int arr[],int lb,int ub);

// Merge Sort
//merge function
void merge(int arr[], int p, int q, int r);
void mergesort(int arr[],int start,int end);



#endif /* srchsort_h */
