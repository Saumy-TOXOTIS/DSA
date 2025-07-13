#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int left = 0;
        int right = -1;
        unordered_map<char,int> freq;
        int maxLen = -1;
        while(right < n)
        {
            right++;
            freq[s[right]]++;
            while(freq[s[right]] > 1)
            {
                freq[s[left]]--;
                left++;
            }
            if(right == n)
            {
                break;
            }
            maxLen = max(maxLen,right - left + 1);
        }
        return maxLen;
    }
};