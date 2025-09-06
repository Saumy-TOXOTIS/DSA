#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int recursion(int n, vector<int> &dp)
    {
        if(n == 1)
        {
            return 0;
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }
        if(n % 2 == 0)
        {
            return dp[n] = 1 + recursion(n/2, dp);
        }
        else
        {
            return dp[n] = 1 + min(recursion(n + 1, dp), recursion(n - 1, dp));
        }
    }
    unordered_map<long long,int> dp;  // sparse DP
    int solve(long long x)
    {
        if(x == 1)
        {
            return 0;
        }
        if(auto it = dp.find(x); it != dp.end())
        {
            return it->second;
        }
        int ans;
        if((x & 1LL) == 0)
        {
            ans = 1 + solve(x >> 1);
        }
        else
        {
            ans = 1 + min(solve(x - 1), solve(x + 1));
        }
        return dp[x] = ans;
    }
public:
    int integerReplacement(int n)
    {
        dp.clear();
        return solve(n);
        //greedy
        long long x = n;
        int steps = 0;
        while (x != 1)
        {
            if ((x & 1LL) == 0)
            {
                x >>= 1;
            }
            else
            {
                if(x == 3 || (x & 3LL) == 1)
                {
                    x--;
                }
                else
                {
                    x++;
                }
            }
            steps++;
        }
        return steps;
    }
};