#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        int totalSubsets = 1<<n;
        for(int i = 0;i < totalSubsets;i++)
        {
            vector<int> curSubset;
            for(int j = 0;j < n;j++)
            {
                if((i>>j)&1)
                {
                    curSubset.push_back(nums[j]);
                }
            }
            ans.push_back(curSubset);
        }
        return ans;
    }
};