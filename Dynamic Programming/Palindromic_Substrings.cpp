#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.length();
        int ans = 0;
        vector<vector<bool>> isPal(n,vector<bool>(n,false));
        for(int i = 0;i < n;i++)
        {
            isPal[i][i] = true;
            ans++;
        }
        for(int len = 2;len <= n;len++)
        {
            for(int i = 0;i < n - len + 1;i++)
            {
                int j = i + len - 1;
                int left = s[i];
                int right = s[j];
                bool prev = isPal[i + 1][j - 1];
                if(len == 2)
                {
                    isPal[i][j] = left == right;
                }
                else
                {
                    isPal[i][j] = prev&&(left == right);
                }
                if(isPal[i][j])
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};