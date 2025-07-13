#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> s;
        for(int i = n - 1;i >= 0;i--)
        {
            while(!s.empty() && s.top() <= nums[i])
            {
                s.pop();
            }
            s.push(nums[i]);
        }
        for(int i = n - 1;i >= 0;i--)
        {
            while(!s.empty() && s.top() <= nums[i])
            {
                s.pop();
            }
            if(!s.empty())
            {
                ans[i] = s.top();
            }
            s.push(nums[i]);
        }
        return ans;
    }
};