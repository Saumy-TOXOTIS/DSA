#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> s;
        for(char c : num)
        {
            if(c == '0' && s.empty())
            {
                continue; // Skip leading zeros
            }
            while(k > 0 && !s.empty() && s.top() > c)
            {
                s.pop();
                k--;
            }
            s.push(c);
        }
        while(k > 0 && !s.empty())
        {
            s.pop();
            k--;
        }
        string ans = "";
        while(!s.empty())
        {
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans.empty() ? "0" : ans;
    }
};