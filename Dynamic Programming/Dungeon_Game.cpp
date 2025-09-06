#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int recursion(int i, int j, vector<vector<int>>& dungeon, vector<vector<int>>& dp)
    {
        if(i == dungeon.size() - 1 && j == dungeon[0].size() - 1)
        {
            return max(1, 1 - dungeon[i][j]);
        }
        if(i >= dungeon.size() || j >= dungeon[0].size())
        {
            return INT_MAX;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int down = recursion(i + 1, j, dungeon, dp);
        int right = recursion(i, j + 1, dungeon, dp);
        int minHP = min(down, right) - dungeon[i][j];
        return dp[i][j] = max(1, minHP);
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[n - 1][m - 1] = max(1, 1 - dungeon[n - 1][m - 1]);
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = m - 1; j >= 0; j--)
            {
                if(i == n - 1 && j == m - 1)
                {
                    continue;
                }
                int down = (i + 1 < n) ? dp[i + 1][j] : INT_MAX;
                int right = (j + 1 < m) ? dp[i][j + 1] : INT_MAX;
                int minHP = min(down, right) - dungeon[i][j];
                dp[i][j] = max(1, minHP);
            }
        }
        return dp[0][0];
    }
};