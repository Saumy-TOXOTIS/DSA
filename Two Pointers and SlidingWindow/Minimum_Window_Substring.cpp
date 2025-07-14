#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s,string t)
    {
        int n = s.length();
        int m = t.length();
        if(m > n)
        {
            return "";
        }
        unordered_map<char,int> freq;
        for(int i = 0;i < m;i++)
        {
            freq[t[i]]++;
        }
        int required = m;
        int l = 0;
        int minLen = 1e9;
        int startIndex = -1;
        for(int r = 0;r < n;r++)
        {
            char curCharRight = s[r];
            if(freq[curCharRight] > 0)
            {
                required--;
            }
            freq[curCharRight]--;
            while(required == 0)
            {
                int curLen = r - l + 1;
                if(curLen < minLen)
                {
                    minLen = curLen;
                    startIndex = l;
                }
                char curCharLeft = s[l];
                freq[curCharLeft]++;
                if(freq[curCharLeft] > 0)
                {
                    required++;
                }
                l++;
            }
            if(startIndex == -1)
            {
                return "";
            }
            else
            {
                return s.substr(startIndex,minLen);
            }
        }
    }
};