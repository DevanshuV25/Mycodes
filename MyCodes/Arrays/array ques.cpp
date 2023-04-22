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
