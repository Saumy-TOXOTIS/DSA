#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int binarySearch_F(vector<int>& nums,int low,int high,int target)
    {
        int ans = -1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target)
            {
                ans = mid;
                high = mid - 1;
            }
            else if(nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
    int binarySearch_L(vector<int>& nums,int low,int high,int target)
    {
        int ans = -1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] == target)
            {
                ans = mid;
                low = mid + 1;
            }
            else if(nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int n = nums.size();
        int first = binarySearch_F(nums,0,n - 1,target);
        int last = binarySearch_L(nums,0,n - 1,target);
        return {first,last};
    }
};