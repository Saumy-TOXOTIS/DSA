#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int recursion(vector<int>& nums,int idx,int currentSum,vector<vector<int>>& dp)
    {
        if(idx == 0)
        {
            if((currentSum)%3 == 0)
            {
                return currentSum;
            }
            else
            {
                return 0;
            }
        }
        if(dp[idx][currentSum%3] != -1)
        {
            return dp[idx][currentSum%3];
        }
        int not_pick = recursion(nums,idx - 1,currentSum,dp);
        int pick = recursion(nums,idx - 1,currentSum + nums[idx - 1],dp);
        return dp[idx][currentSum%3] = max(pick,not_pick);
    }
public:
    int maxSumDivThree(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1,vector<int>(3,-1e9));
        dp[0][0] = 0;
        for(int idx = 1;idx <= n;idx++)
        {
            for(int currentSum = 0;currentSum < 3;currentSum++)
            {
                int not_pick = dp[idx - 1][currentSum];
                int pick = dp[idx - 1][(currentSum + nums[idx - 1])%3] + nums[idx - 1];
                dp[idx][currentSum] = max(pick,not_pick);
            }
        }
        return dp[n][0];
    }
};