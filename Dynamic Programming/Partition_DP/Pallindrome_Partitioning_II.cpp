#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCut(string s)
    {
        int n = s.length();
        if(n <= 1)
        {
            return 0;
        }
        vector<vector<bool>> isPallindrome(n,vector<bool>(n,false));
        for(int i = 0;i < n;i++)
        {
            isPallindrome[i][i] = true;
        }
        for(int len = 2;len <= n;len++)
        {
            for(int i = 0;i < n - len + 1;i++)
            {
                int j = i + len - 1;
                if(len == 2)
                {
                    isPallindrome[i][j] = s[i] == s[j];
                }
                else
                {
                    isPallindrome[i][j] = isPallindrome[i + 1][j - 1]&&s[i] == s[j];
                }
            }
        }
        vector<int> dp(n + 1,0);
        for(int i = n - 1;i >= 0;i--)
        {
            int ans = 1e9;
            for(int k = i;k < n;k++)
            {
                if(isPallindrome[i][k])
                {
                    ans = min(ans,1 + dp[k + 1]);
                }
            }
            dp[i] = ans;
        }
        return (dp[0] - 1);
    }
};