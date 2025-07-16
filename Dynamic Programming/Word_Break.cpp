#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool recursion(int idx,string s,unordered_set<string>& dict,vector<int>& dp)
    {
        if(idx == s.length())
        {
            return true;
        }
        if(dp[idx] != -1)
        {
            return dp[idx];
        }
        string pref = "";
        for(int i = idx;i < s.length();i++)
        {
            pref += s[i];
            if(dict.count(pref) && recursion(i + 1,s,dict,dp))
            {
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
public:
    bool wordBreak(string s,vector<string>& wordDict)
    {
        int n = s.length();
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<bool> dp(n + 1,0);
        dp[n] = 1;
        for(int i = n - 1;i >= 0;i--)
        {
            string pref = "";
            for(int j = i;j < n;j++)
            {
                pref += s[j];
                if(dp[j + 1] && dict.count(pref))
                {
                    dp[i] = 1;
                }
            }
        }
        return dp[0];
    }
};