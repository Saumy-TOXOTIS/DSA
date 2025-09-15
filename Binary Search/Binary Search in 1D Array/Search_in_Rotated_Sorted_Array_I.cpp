#include <bits/stdc++.h>
using namespace std;

int custom_BS(vector<int>& nums, int low, int high, int target)
{
    int ans = -1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        if(nums[mid] == target)
        {
            ans = mid;
            break;
        }
        else if(nums[low] <= nums[mid])
        {
            // mid is in left sorted part
            if(target >- nums[low] && target < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            // mid is in right sorted part
            if(target < nums[low] && target > nums[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return ans;
}