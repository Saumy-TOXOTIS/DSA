#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Recursion with Memoisation
    int recursion(int n,vector<int>& dp)
    {
        if(n <= 1)
        {
            return n;
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }
        int ans = 1e9;
        for(int x = 1;x <= n;x++)
        {
            ans = min(ans,1 + max(x - 1,recursion(n - x,dp)));
        }
        return dp[n] = ans;
    }
public:
    int twoEggDrop(int n)
    {
        vector<int> dp(n + 1,-1);
        dp[0] = 0;
        dp[1] = 1;

        // Direct Memoisation to Tabulation
        // for(int i = 2;i <= n;i++)
        // {
        //     int ans = 1e9;
        //     for(int x = 1;x <= i;x++)
        //     {
        //         ans = min(ans,1 + max(x - 1,dp[i - x]));
        //     }
        //     dp[i] = ans;
        // }
        // return dp[n];

        // Tabulation with Binary Search
        for(int i = 2;i <= n;i++)
        {
            int ans = 1e9;
            int left = 1;
            int right = i;
            while(left <= right)
            {
                int mid = left + (right - left)/2;
                int breakCost = mid - 1;
                int surviveCost = dp[i - mid];
                int curWorst = 1 + max(breakCost,surviveCost);
                ans = min(ans,curWorst);
                if(breakCost > surviveCost)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};