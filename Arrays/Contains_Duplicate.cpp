#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_map<int,int> freq;
        for(auto item : nums)
        {
            freq[item]++;
            if(freq[item] >= 2)
            {
                return true;
            }
        }
        return false;
    }
};