#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxCoins(vector<int>& nums)
    {
        int sz = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(sz + 2,vector<int>(sz + 2,0));
        for(int i = sz + 1;i >= 1;i--)
        {
            for(int j = i;j <= sz;j++)
            {
                int ans = -1e9;
                for(int k = i;k <= j;k++)
                {
                    ans = max(ans,nums[i - 1]*nums[k]*nums[j + 1] + dp[i][k - 1] + dp[k + 1][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][sz];
    }
};