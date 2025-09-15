#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right)
        {
            int mid = (left + right)/2;
            if(nums[mid] == target)
            {
                left = mid;
                break;
            }
            if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        if(nums[left] == target)
        {
            return left;
        }
        else
        {
            if(nums[left] > target)
            {
                return left;
            }
            else
            {
                return left + 1;
            }
        }
    }
};