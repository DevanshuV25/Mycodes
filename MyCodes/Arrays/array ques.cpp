//
//  array ques.cpp
//  MyCodes
//
//  Created by Devanshu Rajpoot on 22/04/23.
//

#include "array ques.hpp"
#include <vector>
#include "srchsort.h"

using namespace std;

vector<int> getConcatenation(vector<int>& nums)
{
        vector<int> ans;
        ans = nums;
        for(auto i : nums) ans.push_back(i);
        return ans;
    }

int findKthLargest(vector<int>& nums, int k)
{
    int sz = nums.size();
    int arr[sz];
    for(int i = 0;i<sz;i++)
    {
        arr[i]=nums[i];
    }
    mergesort(arr,0,sz-1);
    int ans = arr[sz-k];
    return ans;
}

void sort012(int a[], int n)
{
    // code here
    int z=0,o=0,t=0;
    for(int i=0; i<n;i++)
    {
        if(a[i] == 0)
            z++;
        if(a[i] == 1)
            o++;
        if(a[i] == 2)
            t++;
    }
    
    for(int i=0;i<n;i++)
    {
        if(z-->0)
            a[i]=0;
        else if(o-->0)
            a[i]=1;
        else if(t-->0)
            a[i]=2;
    }
}

void mergearrays(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int l = m+n;
    int i=0;
    int j=0;
    
    vector<int> vec;
    while(l--)
    {
        if(i < m && j < n){
        if(nums1[i]<=nums2[j])
        {
            vec.push_back(nums1[i]);
            i++;
        }
        else
        {
            vec.push_back(nums2[j]);
            j++;
        }
    }
        if(j == n && i < m)
        {
            vec.push_back(nums1[i]);
            i++;
        }
        if(i == m && j < n)
        {
            vec.push_back(nums2[j]);
            j++;
        }
    }
    nums1 = vec;
    
}
