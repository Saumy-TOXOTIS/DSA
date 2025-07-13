#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e18 + 7;

class Solution
{
private:
    vector<int> findNSE(vector<int>& arr)
    {
        int n = arr.size();
        stack<int> s;
        vector<int> ans(n,n);
        for(int i = n - 1;i >= 0;i--)
        {
            while(!s.empty() && arr[s.top()] > arr[i])
            {
                s.pop();
            }
            if(!s.empty())
            {
                ans[i] = s.top();
            }
            s.push(i);
        }
        return ans;
    }
    vector<int> findPSEE(vector<int>& arr)
    {
        int n = arr.size();
        stack<int> s;
        vector<int> ans(n,-1);
        for(int i = 0;i < n;i++)
        {
            while(!s.empty() && arr[s.top()] >= arr[i])
            {
                s.pop();
            }
            if(!s.empty())
            {
                ans[i] = s.top();
            }
            s.push(i);
        }
        return ans;
    }
    vector<int> findNGE(vector<int>& arr)
    {
        int n = arr.size();
        stack<int> s;
        vector<int> ans(n,n);
        for(int i = n - 1;i >= 0;i--)
        {
            while(!s.empty() && arr[s.top()] < arr[i])
            {
                s.pop();
            }
            if(!s.empty())
            {
                ans[i] = s.top();
            }
            s.push(i);
        }
        return ans;
    }
    vector<int> findPGEE(vector<int>& arr)
    {
        int n = arr.size();
        stack<int> s;
        vector<int> ans(n,-1);
        for(int i = 0;i < n;i++)
        {
            while(!s.empty() && arr[s.top()] <= arr[i])
            {
                s.pop();
            }
            if(!s.empty())
            {
                ans[i] = s.top();
            }
            s.push(i);
        }
        return ans;
    }

public:
    long long subArrayRanges(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> nse_arr = findNSE(nums);
        vector<int> nge_arr = findNGE(nums);
        vector<int> psee_arr = findPSEE(nums);
        vector<int> pgee_arr = findPGEE(nums);
        long long sumMin = 0;
        long long sumMax = 0;
        for(int i = 0; i < n; i++)
        {
            long long left_count = i - psee_arr[i];
            long long right_count = nse_arr[i] - i;
            sumMin = (sumMin + (left_count*right_count*1LL*nums[i])%MOD)%MOD;
        }

        for(int i = 0; i < n; i++)
        {
            long long left_count = i - pgee_arr[i];
            long long right_count = nge_arr[i] - i;
            sumMax = (sumMax + (left_count*right_count*1LL*nums[i])%MOD)%MOD;
        }

        return (sumMax - sumMin + MOD) % MOD;
    }
};