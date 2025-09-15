#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums)
{
    int low = 0;
    int high = nums.size() - 1;
    while(low < high)
    {
        int mid = low + (high - low)/2;
        if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
        {
            return nums[mid];
        }
        else if(nums[mid] == nums[mid - 1])
        {
            if((mid - 1 - low) % 2 == 0)\
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 2;
            }
        }
        else if(nums[mid] == nums[mid + 1])
        {
            if((high - mid + 1) % 2 == 0)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 2;
            }
        }
    }
    return nums[low];
}