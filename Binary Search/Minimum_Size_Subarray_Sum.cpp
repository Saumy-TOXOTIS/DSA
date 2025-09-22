#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target,vector<int>& nums)
{
    int n = nums.size();
    int low = 1;
    int high = n;
    int ans = 0;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        int sum = 0;
        for(int i = 0;i < mid;i++)
        {
            sum += nums[i];
        }
        bool flag = false;
        if(sum >= target)
        {
            flag = true;
        }
        for(int i = mid;i < n;i++)
        {
            sum += nums[i];
            sum -= nums[i - mid];
            if(sum >= target)
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}