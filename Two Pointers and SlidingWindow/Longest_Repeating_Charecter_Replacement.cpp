#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s,int k)
    {
        int n = s.length();
        unordered_map<char,int> freq;
        int left = 0;
        int right = 0;
        int curFreq = 0;
        int maxLen = 0;
        while(right < n)
        {
            freq[s[right]]++;
            curFreq = max(curFreq,freq[s[right]]);
            while(right - left + 1 - curFreq > k)
            {
                freq[s[left]]--;
                left++;
            }
            maxLen = max(maxLen,right - left + 1);
            right++;
        }
        return maxLen;
    }
};