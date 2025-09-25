#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool find132pattern(vector<int>& nums)
    {
        int n = nums.size();
        if(n < 3)
        {
            return false;
        }
        vector<int> pref(n);
        pref[0] = nums[0];
        for(int i = 1;i < n;i++)
        {
            pref[i] = min(pref[i - 1],nums[i]);
        }
        stack<int> st;
        for(int j = n - 1;j >= 0;j--)
        {
            if(nums[j] == pref[j])
            {
                continue;
            }
            while((!st.empty()) && (st.top() <= pref[j]))
            {
                st.pop();
            }
            if((!st.empty()) && (st.top() < nums[j]))
            {
                return true;
            }
            st.push(nums[j]);
        }
        return false;
    }
};