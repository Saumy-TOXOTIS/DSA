#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans(n);
        map<int,int> mapping;
        stack<int> s;
        s.push(-1);
        for(int i = m - 1;i >= 0;i--)
        {
            while(s.top() != -1 && s.top() < nums2[i])
            {
                s.pop();
            }
            mapping[nums2[i]] = s.top();
            s.push(nums2[i]);
        }
        for(int i = 0;i < n;i++)
        {
            ans[i] = mapping[nums1[i]];
        }
        return ans;
    }
};