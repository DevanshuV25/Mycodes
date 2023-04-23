//
//  array ques.hpp
//  MyCodes
//
//  Created by Devanshu Rajpoot on 22/04/23.
//
// Leetcode
// 1929. Concatenation of Array (getConcatenation)
// 215. Kth Largest Element in an Array (findKthLarges)
// GFG Sort an array of 0s, 1s and 2s (sort012)
// 88. Merge Sorted Array (mergearrays)
//
// hello


#ifndef array_ques_hpp
#define array_ques_hpp

#include <stdio.h>
#include <vector>

using namespace std;

vector<int> getConcatenation(vector<int>& nums);

int findKthLargest(vector<int>& nums, int k);

void sort012(int a[], int n);

void mergearrays(vector<int>& nums1, int m, vector<int>& nums2, int n);


#endif /* array_ques_hpp */
