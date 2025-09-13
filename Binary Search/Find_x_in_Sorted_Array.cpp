#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int left = 0;
        int right = int(nums.size());
        while(left < right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] >= target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        if(left < nums.size() && nums[left] == target)
        {
            return left;
        }
        else
        {
            return -1;
        }
    }
};