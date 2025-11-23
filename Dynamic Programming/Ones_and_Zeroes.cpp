#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxForm(vector<string>& strs,int m,int n)
    {
        int sz = strs.size();
        vector<vector<int>> dp(m + 1,vector<int>(n + 1,0));
        for(int index = 1;index <= sz;index++)
        {
            int curr0 = 0;
            int curr1 = 0;
            for(const char& c : strs[index - 1])
            {
                if(c == '1')
                {
                    curr1++;
                }
                else
                {
                    curr0++;
                }
            }
            for(int M = m;M >= curr0;M--)
            {
                for(int N = n;N >= curr1;N--)
                {
                    dp[M][N] = max(dp[M][N],1 + dp[M - curr0][N - curr1]);
                }
            }
        }
        return dp[m][n];
    }
};