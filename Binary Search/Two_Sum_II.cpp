#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums,int target)
{
    int n = nums.size();
    int idx1, idx2;
    for(int i = 0;i < n;i++)
    {
        int newTarget = target - nums[i];
        int low = i + 1;
        int high = n - 1;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(nums[mid] == newTarget)
            {
                idx1 = i + 1;
                idx2 = mid + 1;
                return {idx1,idx2};
            }
            else if(nums[mid] < newTarget)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return {};
}