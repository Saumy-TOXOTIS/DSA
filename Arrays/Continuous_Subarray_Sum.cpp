
#include <bits/stdc++.h>    
using namespace std;

class Solution
{
public:
    bool checkSubarraySum(vector<int>& nums,int k)
    {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = -1;
        int prefixSum = 0;
        for(int i = 0;i < n;i++)
        {
            prefixSum += nums[i];
            if(k != 0)
            {
                prefixSum = prefixSum%k;
            }
            if(mp.find(prefixSum) != mp.end())
            {
                if(i - mp[prefixSum] > 1)
                {
                    return true;
                }
            }
            else
            {
                mp[prefixSum] = i;
            }
        }
        return false;
    }
};