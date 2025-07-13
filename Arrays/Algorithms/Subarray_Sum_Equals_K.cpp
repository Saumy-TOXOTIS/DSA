#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int>& nums, int k)
    {
        map<int,int> prefix;
        int sum = 0;
        prefix[sum] = 1;
        int ans = 0;
        for(int i = 0;i < nums.size();i++)
        {
            sum += nums[i];
            if(prefix.count(sum - k))
            {
                ans += prefix[sum - k];
            }
            prefix[sum]++;
        }
        return ans;
    }
};