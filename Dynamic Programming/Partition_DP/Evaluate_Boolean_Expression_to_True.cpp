#include <bits/stdc++.h>
using namespace std;

// Find number of ways in which a boolean expression will evaluate to true

const int mod = 1e9 + 7;

class Solution
{
private:
    int f(string expression,int i,int j,int boolVal,vector<vector<vector<int>>>& dp)
    {
        if(i > j)
        {
            return 0;
        }
        if(i == j)
        {
            if(boolVal)
            {
                return expression[i] == 'T';
            }
            else
            {
                return expression[i] == 'F';
            }
        }
        if(dp[i][j][boolVal] != -1)
        {
            return dp[i][j][boolVal];
        }
        int ways = 0;
        for(int k = i + 1;k <= j - 1;k += 2)
        {
            int lT = f(expression,i,k - 1,1,dp);
            int lF = f(expression,i,k - 1,0,dp);
            int rT = f(expression,k + 1,j,1,dp);
            int rF = f(expression,k + 1,j,0,dp);
            if(expression[k] == '&')
            {
                if(boolVal)
                {
                    ways = (ways + (lT * rT) % mod) % mod;
                }
                else
                {
                    ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
                }
            }
            else if(expression[k] == '|')
            {
                if(boolVal)
                {
                    ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
                }
                else
                {
                    ways = (ways + (lF * rF) % mod) % mod;
                }
            }
            else if(expression[k] == '^')
            {
                if(boolVal)
                {
                    ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
                }
                else
                {
                    ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
                }
            }
        }
        return dp[i][j][boolVal] = ways;
    }
public:
    int evalBoolean(string expression)
    {
        int n = expression.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return f(expression,0,n - 1,1,dp);
    }
};