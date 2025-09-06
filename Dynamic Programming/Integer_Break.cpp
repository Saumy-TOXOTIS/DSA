#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int recursion(int n, vector<int>& dp)
    {
        if(n == 1)
        {
            return 1;
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }
        int maxProduct = 0;
        for(int i = 1;i < n;i++)
        {
            maxProduct = max(maxProduct, max(i*(n - i),i*recursion(n - i,dp)));
        }
        return dp[n] = maxProduct;
    }
public:
    int integerBreak(int n)
    {
        vector<int> dp(n + 1,0);
        dp[1] = 1;
        for(int i = 2;i <= n;i++)
        {
            int maxProduct = 0;
            for(int j = 1;j < i;j++)
            {
                maxProduct = max(maxProduct, max(j*(i - j),j*dp[i - j]));
            }
            dp[i] = maxProduct;
        }
        return dp[n];
    }
};