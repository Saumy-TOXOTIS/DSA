#include <bits/stdc++.h>
using namespace std;

int splitArray(vector<int>& nums,int k)
{
    int n = nums.size();
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(),nums.end(),0);
    int ans = high;
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        int sum = 0;
        int count = 1;
        for(int i = 0;i < n;i++)
        {
            sum += nums[i];
            if(sum > mid)
            {
                count++;
                sum = nums[i];
            }
        }
        if(count <= k)
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