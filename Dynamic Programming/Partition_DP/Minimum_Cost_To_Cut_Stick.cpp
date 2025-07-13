#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int f(vector<int>& cuts,int i,int j)
    {
        if(i > j)
        {
            return 0;
        }
        int ans = 1e9;
        for(int k = i;k <= j;k++)
        {
            int cost = cuts[j + 1] - cuts[i - 1] + f(cuts,i,k - 1) + f(cuts,k + 1,j);
            ans = min(ans,cost);
        }
        return ans;
    }
public:
    int minCost(int n,vector<int>& cuts)
    {
        int sz = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(n + 1,vector<int>(n + 1,0));
        for(int i = sz;i >= 1;i++)
        {
            for(int j = i;j <= sz;j++)
            {
                int ans = 1e9;
                for(int k = i;k <= j;k++)
                {
                    ans = min(ans,cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][sz];
    }
};