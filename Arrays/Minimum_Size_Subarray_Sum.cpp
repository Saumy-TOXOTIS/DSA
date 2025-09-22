#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target,vector<int>& nums)
{
    int n = nums.size();
    int minLength = INT_MAX;
    int left = 0;
    int right = 0;
    int currentSum = 0;
    while(right < n)
    {
        currentSum += nums[right];
        while(currentSum >= target)
        {
            minLength = min(minLength,right - left + 1);
            currentSum -= nums[left];
            left++;
        }
    }
    return minLength == INT_MAX ? 0 : minLength;
}