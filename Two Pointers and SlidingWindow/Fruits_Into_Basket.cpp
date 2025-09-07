#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalFruits(vector<int>& fruits)
    {
        int n = fruits.size();
        int left = 0;
        int right = 0;
        unordered_map<int,int> freq;
        int curAmount = 0;
        int maxAmount = 0;
        while(right < n)
        {
            freq[fruits[right]]++;
            curAmount++;
            while(freq.size() > 2)
            {
                freq[fruits[left]]--;
                if(freq[fruits[left]] == 0)
                {
                    freq.erase(fruits[left]);
                }
                curAmount--;
                left++;
            }
            maxAmount = max(maxAmount,curAmount);
            right++;
        }
        return maxAmount;
    }
};