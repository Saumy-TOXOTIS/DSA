#include <bits/stdc++.h>
using namespace std;

int countRotation(vector<int>& nums)
{
    int low = 0;
    int high = nums.size() - 1;
    int min_till = INT_MAX;
    int ans = 0;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(nums[mid] < nums[low])
        {
            if(min_till > nums[mid])
            {
                min_till = nums[mid];
                ans = mid;
            }
            high = mid - 1;
        }
        else
        {
            if(min_till > nums[low])
            {
                min_till = nums[low];
                ans = low;
            }
            low = mid + 1;
        }
    }
    return ans;
}