#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSumAfterPartitioning(vector<int>& arr,int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1,0);
        for(int i = n;i >= 0;i--)
        {
            int ans = -1e9;
            int max_element = -1e9;
            int len = 0;
            for(int j = i;j < min(i + k,n);j++)
            {
                len++;
                max_element = max(max_element,arr[j]);
                ans = max(ans,max_element*len + dp[j + 1]);
            }
            dp[i] = max(dp[i],ans);
        }
        return dp[0];
    }
};