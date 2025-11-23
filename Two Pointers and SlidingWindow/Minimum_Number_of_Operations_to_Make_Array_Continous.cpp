#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums)
    {
        int n = nums.size();
        if(n <= 1)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int m = nums.size();
        int min_ops = n;
        int right = 0;
        for(int left = 0;left < m;left++)
        {
            long long minVal = nums[left];
            long long maxVal = minVal + n - 1;
            while(right < m && nums[right] <= maxVal)
            {
                right++;
            }
            int cost = n - (right - left);
            min_ops = min(min_ops,cost);
        }
        return min_ops;
    }
};