#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int numSubarrayWithSumLessThanEqual(vector<int>& nums,int goal)
    {
        if(goal < 0)
        {
            return 0;
        }
        int n = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        int count = 0;
        while(right < n)
        {
            sum += nums[right]&1;
            while(sum > goal)
            {
                sum -= nums[left]&1;
                left++;
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums,int goal)
    {
        int n = nums.size();
        int k = numSubarrayWithSumLessThanEqual(nums,goal);
        int k_1 = numSubarrayWithSumLessThanEqual(nums,goal - 1);
        return (k - k_1);
    }
};