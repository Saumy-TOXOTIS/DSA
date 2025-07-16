#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Recursion with Memoisation
    int recursion(int k,int n,vector<vector<int>>& dp)
    {
        if(n <= 1 || k == 1)
        {
            return n;
        }
        if(dp[n][k] != -1)
        {
            return dp[n][k];
        }
        int ans = 1e9;
        for(int x = 1;x <= n;x++)
        {
            ans = min(ans,1 + max(recursion(k - 1,x - 1,dp),recursion(k,n - x,dp)));
        }
        return dp[n][k] = ans;
    }
public:
    int superEggDrop(int k,int n)
    {
        // n -> number of floors
        // k -> number of eggs
        vector<vector<int>> dp(n + 1,vector<int>(k + 1,0));
        for(int i = 0;i <= k;i++)
        {
            dp[0][i] = 0;
            dp[1][i] = 1;
        }
        for(int i = 0;i <= n;i++)
        {
            dp[i][1] = i;
        }

        // Direct Tabulation from Memoisation
        // for(int i = 2;i <= n;i++)
        // {
        //     for(int j = 2;j <= k;j++)
        //     {
        //         int ans = 1e9;
        //         for(int x = 1;x <= i;x++)
        //         {
        //             ans = min(ans,1 + max(dp[x - 1][j - 1],dp[i - x][j]));
        //         }
        //         dp[i][j] = ans;
        //     }
        // }

        // DP with Binary Search
        for(int i = 2;i <= n;i++)
        {
            for(int j = 2;j <= k;j++)
            {
                int ans = 1e9;
                int left = 1;
                int right = i;
                while(left <= right)
                {
                    int mid = left + (right - left)/2;
                    int breakCost = dp[mid - 1][j - 1];
                    int surviveCost = dp[i - mid][j];
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
                dp[i][j] = ans;
            }
        }

        return dp[n][k];
    }
};